// 02_04.c
// This program removes all comments from any C program file
#include <stdio.h>

#define MAXFILESIZE 102400

const char *gInputStream = NULL;
char *gOutputStream = NULL;

void setInputStream (const char * stream) 
{
	gInputStream = stream;
}

void setOutputStream (char * stream) 
{
	gOutputStream = stream;
}

char getCharFromInputStream() 
{
	return *gInputStream++;
}

char peepNextCharFromInputStream () 
{
	return *gInputStream;
}

void putCharToOutputStream(char c)
{
	*gOutputStream++ = c;
}


void skipUntilMultiLineCommentEnds() 
{
	char c;
	while ( c = getCharFromInputStream() ) 
	{
		if ( c == '*' && peepNextCharFromInputStream() == '/' )
		{
			getCharFromInputStream();
			return;
		}
	}
}

void skipUntilSingleLineCommentEnds () 
{
	char c;
	while ( c = getCharFromInputStream() ) 
	{
		if ( c == '\n')
		{
			putCharToOutputStream(c);
			return;
		}
	}	
}

void removeCommentsFromBuffer(const char * InputBuffer, char * OutputBuffer) 
{
	int INSIDE_LITERAL_STRING = 0;
	char c, lastChar='\0';

	setInputStream(InputBuffer);
	setOutputStream(OutputBuffer);

	while ( c = getCharFromInputStream() ) 
	{
		if ( c == '\"' ) 
		{
			if ( lastChar != '\\' ) 
			{
				INSIDE_LITERAL_STRING = INSIDE_LITERAL_STRING ? 0 : 1;
			}	
			putCharToOutputStream(c);
		} 
		else if ( c == '/' && !INSIDE_LITERAL_STRING && peepNextCharFromInputStream() == '*' ) {
			skipUntilMultiLineCommentEnds();
		}
		else if ( c == '/' && !INSIDE_LITERAL_STRING && peepNextCharFromInputStream() == '/' ) {
			skipUntilSingleLineCommentEnds();
		} else {
			putCharToOutputStream(c);
		}
		lastChar = c;
	}
	putCharToOutputStream(c);
}

void populateInputBufferFromStdIn(char *input) 
{
	int nchar = 0;
	while ( ((*input++ = getchar()) != EOF) &&
				(nchar++ < 	MAXFILESIZE)	);
	*(--input) = '\0';
}

void printOutputBuffertoStdout(char *output) 
{
	printf("%s",output);
}

void main (int argc, const char * argv[]) 
{
	char input[MAXFILESIZE];
	char output[MAXFILESIZE];
	populateInputBufferFromStdIn(input);
	removeCommentsFromBuffer(input,output);
	printOutputBuffertoStdout(output);
}
