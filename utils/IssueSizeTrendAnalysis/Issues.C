// Analyze issues
#include<stdio.h>
#include<string.h>
struct issuedetails{
	char issueId[20],parentId[20];
	float efforts;
}issuelist[20];

int issuecount;
void getIssueData();
int showVerbose = 0;

void TraceIssueDetails () {
	if ( ! showVerbose ) {
		return;
	}
	
	for(int currentIssueIndex=0;currentIssueIndex < issuecount; currentIssueIndex++ )
	{ 
			printf("%s\t%s\t%f\n\r", issuelist[currentIssueIndex].issueId, 
				issuelist[currentIssueIndex].parentId, 
				issuelist[currentIssueIndex].efforts);
	}
}

void calculateLeafNode()
{
	int leafNodes=0,flag;
	for(int leafIterator = 0;leafIterator < issuecount; leafIterator++ )
	{
		flag=0;
		for(int parentIterator = 0; parentIterator < issuecount; parentIterator++ )
		{
			if(strcmp(issuelist[leafIterator].issueId,issuelist[parentIterator].parentId)==0)
			{
				flag=1;
				break;
			}
		}
		if(flag!=1)
			leafNodes++;
	}
	printf("\nTotal LeafNodes = %d\n",leafNodes);
	
}
int main (int argc , const char *argv[]) {
	
	/*Fetching Data*/

	
		getIssueData();
	calculateLeafNode();
		
	return 0;
}

void getIssueData()
{	
	int currentIssueIndex = 0,issueIterator;

	strcpy(issuelist[currentIssueIndex].issueId,"IONPIVOT-1");	strcpy(issuelist[currentIssueIndex].parentId,"");	issuelist[currentIssueIndex++].efforts = 78;
	strcpy(issuelist[currentIssueIndex].issueId,"IONPIVOT-2");	strcpy(issuelist[currentIssueIndex].parentId,"");	issuelist[currentIssueIndex++].efforts = 0;
	strcpy(issuelist[currentIssueIndex].issueId,"IONPIVOT-3");	strcpy(issuelist[currentIssueIndex].parentId,"IONPIVOT-2");	issuelist[currentIssueIndex++].efforts = 0;
	strcpy(issuelist[currentIssueIndex].issueId,"IONPIVOT-4");	strcpy(issuelist[currentIssueIndex].parentId,"IONPIVOT-3");	issuelist[currentIssueIndex++].efforts = 34;
	strcpy(issuelist[currentIssueIndex].issueId,"IONPIVOT-5");	strcpy(issuelist[currentIssueIndex].parentId,"IONPIVOT-4");	issuelist[currentIssueIndex++].efforts = 45;
	strcpy(issuelist[currentIssueIndex].issueId,"IONPIVOT-6");	strcpy(issuelist[currentIssueIndex].parentId,"");	issuelist[currentIssueIndex++].efforts = 42;
	strcpy(issuelist[currentIssueIndex].issueId,"IONPIVOT-7");	strcpy(issuelist[currentIssueIndex].parentId,"");	issuelist[currentIssueIndex++].efforts = 0;
	strcpy(issuelist[currentIssueIndex].issueId,"IONPIVOT-8");	strcpy(issuelist[currentIssueIndex].parentId,"IONPIVOT-7");	issuelist[currentIssueIndex++].efforts = 90;
	strcpy(issuelist[currentIssueIndex].issueId,"IONPIVOT-9");	strcpy(issuelist[currentIssueIndex].parentId,"IONPIVOT-7");	issuelist[currentIssueIndex++].efforts = 67;
	strcpy(issuelist[currentIssueIndex].issueId,"IONPIVOT-11");	strcpy(issuelist[currentIssueIndex].parentId,"");	issuelist[currentIssueIndex++].efforts = 0;
	strcpy(issuelist[currentIssueIndex].issueId,"IONPIVOT-12");	strcpy(issuelist[currentIssueIndex].parentId,"IONPIVOT-11");	issuelist[currentIssueIndex++].efforts = 34;
	strcpy(issuelist[currentIssueIndex].issueId,"IONPIVOT-13");	strcpy(issuelist[currentIssueIndex].parentId,"IONPIVOT-11");	issuelist[currentIssueIndex++].efforts = 23;
	
	
	issuecount=currentIssueIndex;
	TraceIssueDetails();
}
