#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
	
} ;

enum Boolean
{
  false,
  true
};

struct Node *sourceListRoot = NULL;
struct Node *targetListRoot = NULL ;
struct Node *tempListRoot = NULL ;

void appendElementToSourceList( int value) ;
void printSourceList() ;
void makeSourceListPointToTheSecondNodeOfTempList();
void makeTempListFirstNodeConnectWithTargetListFirstNode();
void makeTargetListPointTempListFirstNode();
struct Node * getLastNode( struct Node *listRoot ) ;
enum Boolean sourceListIsNotEmpty ();
void printTargetList();

enum Boolean sourceListIsNotEmpty () 
{
		if ( sourceListRoot ) {
			return true;
		}
		
		return false;
}

void makeTargetListPointTempListFirstNode()
{
	targetListRoot = tempListRoot;
}

void makeTempListFirstNodeConnectWithTargetListFirstNode()
{
	if( ! tempListRoot ) 
	{
		return;
	}
	
	tempListRoot->next = targetListRoot;
}

void makeSourceListPointToTheSecondNodeOfTempList()
{
	if ( !tempListRoot ) 
	{
		return;
	}
	
	sourceListRoot = tempListRoot->next;
}

void createSourceListWithTestData() 
{
	appendElementToSourceList( 100);
	appendElementToSourceList(200);
	appendElementToSourceList(300);
	appendElementToSourceList(400);
	appendElementToSourceList(500);
}

void printSourceList() 
{
	struct Node *currentNode = sourceListRoot;
	while( currentNode ) 
	{
		printf("ListVal: %d\n", currentNode->data);
		currentNode = currentNode->next;
	}
}

void printTargetList () 
{
	struct Node *currentNode = targetListRoot;
	while( currentNode ) 
	{
		printf("ListVal: %d\n", currentNode->data);
		currentNode = currentNode->next;
	}
}

struct Node * getLastNode( struct Node *listRoot ) 
{
	struct Node *currentNode = listRoot;
	if(  !listRoot ) 
	{
		printf("returning for null list\n");
		return NULL;
	}
	
	while( currentNode->next ) 
	{
		currentNode = currentNode->next;
	}
	
	return currentNode;
}

void appendElementToSourceList( int value) 
{
	 struct Node *newNode = malloc(sizeof(struct Node) );
	 newNode->data = value;
	 newNode->next = NULL;
	 
	struct Node *lastNode = getLastNode(sourceListRoot);
	
	if ( lastNode ) 
	{
		lastNode->next = newNode;
	} 
	else 
	{
		printf("Added New Node\n");
		sourceListRoot = newNode;	
	}
	
}

void makeTempListRootPointToSourceListRoot()
{
	tempListRoot = sourceListRoot;
}

void main (int argc, const char * argv[]) 
{
	
	createSourceListWithTestData();
	printf("Lets see how the source list look like in the beginning\n");
	printSourceList();
	
	while ( sourceListIsNotEmpty() ) 
	{
		// Step 1
		makeTempListRootPointToSourceListRoot( );
		
		// Step 2
		makeSourceListPointToTheSecondNodeOfTempList();
		
		// Step 3
		makeTempListFirstNodeConnectWithTargetListFirstNode();
		
		// Step 4
		makeTargetListPointTempListFirstNode();
	
		// examine the source list again
		// printf("Lets see how the source list look like now\n");
		// printSourceList();
	}

	// examine the source list again
	printf("Lets see how the target list look like now\n");
	printTargetList();
	
}
