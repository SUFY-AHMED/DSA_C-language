#include<stdio.h>
#include<stdlib.h>

// we are using ADP (abstract data types)
//structure
struct node{
	struct node* next;
	int data;
};
typedef struct node *Nodeptr;

//using function
Nodeptr createNode(Nodeptr,int item)
{
	Nodeptr q;
	q = (Nodeptr)malloc(sizeof(struct node)); //Dynamic memory allocation 
	q->data = item;	
	q->next = NULL;
	return q;
}

//printList
void printList(Nodeptr head)
{
	Nodeptr ptr;
	ptr = head;
	printf("[ ");
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}
	printf("]");
}

//freeNode
Nodeptr freeNode(Nodeptr head, Nodeptr current)
{
	Nodeptr temp;
	temp = head; 
	if(current==NULL)
	{
		printf("Void deletion");
	}
	else
	{
		while(temp->next!=current)
		{
			temp = temp->next;
		}
		temp->next = current->next;
		free(current);//built in function
	}
	return head;
}

//insertion at head
Nodeptr insertAtHead(Nodeptr head, int item)
{
	Nodeptr ptr; 
	ptr = (Nodeptr)malloc(sizeof(struct node));
	ptr->data = item;
	
	if(head == NULL)
	{
		head = ptr;
	}
	else
	{
		ptr->next = head;
		head = ptr;
	}
	return head;
}

//inserting after a node
Nodeptr insertAfterNode(Nodeptr current, int item)
{
	Nodeptr newNode;
	if(current == NULL)
	{
		printf("void insertion");
	}
	else
	{
		newNode = createNode(newNode, item);
		newNode->next = current->next; //linking
		current->next = newNode;      //breaking from after node
	}	
}

//Inserting before a node
Nodeptr insertBeforeNode(Nodeptr head,Nodeptr current, int item)
{
	Nodeptr newNode, pre, ptr;
	newNode = createNode(newNode, item);
	ptr = head;
	if(head = NULL)
	{
		current = newNode;
		return newNode;
	}
	else
	{
		while(ptr != current)
		{
			pre = ptr;
			ptr = ptr->next;
		}
		pre->next = newNode;
		newNode->next = ptr;
	}
	
}

//insertion at tail
Nodeptr insertLast(Nodeptr head,int item)
{
	Nodeptr newNode, temp;
	temp = head;
	newNode = createNode(newNode, item);
	if(head == NULL)
	{
		newNode = head;	
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->next = NULL;
	}
	return head;
}
int main()
{
	Nodeptr head, node1, node2, node3, newHead, node4, node5, node6, temp;
	node1 = createNode(node1,16);
	head = node1;                  //creation of head node
	temp = head;
	node2 = createNode(node2,34); //links generation
	temp->next = node2; 	     //jump to next node
	node3 = createNode(node3,69);
	node2->next = node3;
	//printing list
	printList(head);
	//inserting at head 
	
//	node5 = insertBeforeNode(head, node2, 45);
//	printf("\n");
//	printf("Inserted before the node!\n");
//	printList(head);
//	
	node4 = insertAfterNode(node2, 20);
	printf("\n");
	printf("Inserted after the node!\n");
	printList(head);
//
	printf("\nLast item upgraded!\n");
	node6 = insertLast(head, 4);
	printList(head);
//	
//	newHead = insertAtHead(head, 9);
//	printf("\n");
//	printf("Head Upgraded!\n");
//	printList(newHead);
	return 0;
}
	
