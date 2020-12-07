#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <stdio.h>
// DION ANDREAS SOLANG
// 07211940000039


struct Node{
	struct Node* next;
	int data;
}; 
typedef struct Node Node;
Node* listHead = NULL;

Node* createNode(int data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;
	return newnode;
}
void addNode(Node* newNode)
{
	if(listHead!=NULL)
		newNode->next = listHead;
	listHead = newNode;
	return;
}
void print_head_first()
{
	Node* tmpnode = listHead;
	while(tmpnode!=NULL)
	{
		printf("%d ",tmpnode->data);
		tmpnode=tmpnode->next;
	}
}
void reverse()
{
	Node* tmpnode = listHead;
	Node* tmpnode2=NULL;
	Node* tmpnode3;
	while(tmpnode!=NULL)
	{
		tmpnode3 = tmpnode->next;
		tmpnode->next=tmpnode2;
		tmpnode2=tmpnode;
		tmpnode = tmpnode3;
	}
	listHead = tmpnode2;
}
void print_head_last()
{	
	reverse();
	print_head_first();
	reverse();
}

int nodeSum()
{
	int sum=0;
	Node* tmp=listHead;
	while(tmp!=NULL)
	{
		sum+=tmp->data;
		tmp=tmp->next;
	}
	return sum;
}

int printMin()
{
	int smallest =0;
	smallest = (~smallest)>>1; // smallest=INT_MAX
	Node* tmpnode = listHead;
	while(tmpnode!=NULL)
	{
		smallest = (smallest<tmpnode->data)?smallest:tmpnode->data;
		tmpnode = tmpnode->next;
	}
	return smallest;	
}


void deleteMax()
{
	if(listHead == NULL)
		return;
	Node *tmpnode,*tmpnode2,*maxnode,*before_maxnode;
	tmpnode = tmpnode2  = maxnode = listHead;
	before_maxnode = NULL;
	while(tmpnode!=NULL)
	{
		if(tmpnode->data > maxnode->data)
		{
			maxnode = tmpnode;
			before_maxnode = tmpnode2;
		}
		tmpnode2 = tmpnode;
		tmpnode = tmpnode->next;
	}
	if(before_maxnode==NULL)
	{
		listHead = maxnode->next;
		free(maxnode);
		return;
	}
	before_maxnode->next = maxnode->next;
	free(maxnode);
}


int main()
{
	int N[] = {5,2,2,0,2,3};
	for(int i=0;i<6;i++)
		addNode(createNode(N[i]));

	print_head_first();
	printf("\n");
	print_head_last();
	printf("\n");
	printMin();
	printf("\n");
	deleteMax();
	print_head_first();
	
	return 0;
}
