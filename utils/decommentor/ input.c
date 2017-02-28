// 02_04.c
// This program removes all comments from any C program file
#include <stdio.h>

// This is a bad /* comment
void main (int argc, const char * argv[]) {
	int c = 0, c1 = 0;
	int INSIDE_QUOTE = 0;
	int INSIDE_SINGLELINE_COMMENT = 0;
	int INSIDE_MULTILINE_COMMENT = 0;

	/*This is a multiline comment to be removed /* is also removed
	Look at it*/

	printf("This is a \"comment in literal string : MultiLine- /*This must not be removed*/  SingleLine- // This must not be removed either\n");
}

