#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct slist
{
	int id ;
	struct slist *next ;			
}L;
 
//create a node 
L *create_node(int data)
{
	//Allocate the same amount of space to each node 
	L *p = malloc(sizeof(L));
	if(NULL == p)
	{
		printf("malloc error!\n");
		return NULL ;
	}
	//Clean structure 
	memset(p,0,sizeof(L));
	//Initialize the first node 
	p->id = data ; 
	//Set the node's successor pointer to NULL 
	p->next = NULL ;
}
 
//Tail insertion of linked list 
void tail_insert(L *pH , L *new)
{
	//Get the current position 
	L *p = pH ; 
	//If the next node at the current position is not NUll 
	while(NULL != p->next)
	{
		//Move to the next node 
		p = p->next ;
	}
	//If you jump out of the above loop, you have reached the position of NULL
	//At this time, the newly inserted node is directly assigned to the NULL position. 
	p->next = new ;
}
 
//Head insertion of linked list 
void top_insert(L *pH , L *new)
{
	L *p = pH ;
	new->next = p->next ;
	p->next = new ;
}
 
//Traverse of linked list 
void Print_node(L *pH)
{
	//Get the current position 
	L *p = pH ;
	//Get the position of the first node 
	p = p->next ;
	//If the next node at the current position is not null 
	while(NULL != p->next)
	{
		//(1)Print node value 
		printf("id:%d\n",p->id);
		//(2)Move to next node,if condition is still true，repeat(1)，then(2) 
		p = p->next ;
	}
	//If the next node at the current position is null, print the value
	//means there is only one node 
	printf("id:%d\n",p->id);
}
 
//Delete node in Linked list 
int detele_list_node(L * pH , int data)
{
	//Get the position of the current head node 
	L *p = pH ;
	L *prev = NULL;
	while(NULL != p->next)
	{
		//Holds a pointer to the previous node of the current node 
		prev = p ;
		//Then let the current pointer move forward 
		p = p->next ; 	
		//Determine if the data need to be deleted is found  
		if(p->id == data)
		{
			//Two cases, one is a Middle node, and the other is a tail node
			if(p->next != NULL)  //Middle node 
			{
				prev->next = p->next ;
				free(p);//Free
			}
			else //Tail node 
			{
				prev->next = NULL ; //Let the previous node of the tail node pointer to null 
				free(p); // Free
			}
			return 0  ;
		}
	}
	printf("No found of the node\n");
	return -1 ;
}
 
void trave_list(L * pH)
{
	//save the first node position 
	L *p = pH->next;
	L *pBack;
	int i = 0 ;
	if(p->next == NULL || p == NULL)
		return ;
		
	while(NULL != p->next) //Traverse the linked list 
	{
		//Save next node of the first node 
		pBack = p->next ; 
		//Find the first valid node, which is the next node of the head pointer 
		if(p == pH->next) 
		{
			//Because there is only one node，so it pointer to NULL
			p->next = NULL ; 
		} 
		else
		{
			/*
			new->next = p->next ;
			p->next = new ;
			*/
			p->next = pH->next ; //Tail connection 
		}
		pH->next = p ; //Head connection 
		p = pBack ; //go to the next node
	}
	top_insert(pH,p); //insert the last node 
}

int main(int argc , char **argv) 
{
	//create first node 
	int i ;
	L *header = create_node(0); 
	for(i = 1 ; i < 10 ; i++)
	{
		tail_insert(header,create_node(i));
	}
	Print_node(header);
	detele_list_node(header,5);
	putchar('\n');
	Print_node(header);
	putchar('\n');
	trave_list(header);
	Print_node(header);
	return 0 ;
}
