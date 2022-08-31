#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
	q = (Nodeptr)malloc(sizeof(struct node));
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

//deletion at Head
Nodeptr deleteHead(Nodeptr head)
{
	Nodeptr temp;//temporary pointer pointing towards head
	if(head == NULL)
	{
		printf("Void deletion!");
	}
	else{
		temp = head;
		head = head->next;
		free(temp);
	}
	return head;
}

//deletion at Tail
Nodeptr deleteTail(Nodeptr head)
{
	Nodeptr temp, pre;//temporary pointer pointing towards head
	temp = head;   
	while(temp->next != NULL)
	{
		pre = temp;
		temp = temp->next;	
	}  
	pre->next = NULL;
	free(temp);
	return head;
}
//deletion after a node
deleteAfterNode(Nodeptr ptr)
{
	Nodeptr temp;
	if(ptr == NULL){
		printf("Void deletion!");
	}
	else{
		temp = ptr->next;
		ptr->next = temp->next;
		free(temp);
	}
}

//deletion before a node
deleteBeforeNode(Nodeptr head, Nodeptr ptr)
{
	Nodeptr temp, pre;
	if(ptr == NULL){
		printf("Void deletion!");
	}
	else{
		temp = head;
		while(temp->next != ptr)
		{
			pre = temp;
			temp = temp->next;
		}
		pre->next = ptr;
		free(temp);
	}
}

//deletion at particular position:
deleteItem(Nodeptr head, int item)
{
	Nodeptr temp, pre;
	temp = head;
	while(temp->data != item)
	{
		pre = temp;
		temp = temp->next;
	}
	pre->next = temp->next;
	free(temp);
}

//Traversal
traverse(Nodeptr head)
{
	Nodeptr temp; int count=1;
	temp = head;
	while(temp != NULL)
	{
		printf("Node[%d] = [%d]", count, temp->data);
		printf("\n");
		temp = temp->next;
		count++;
	}
	printf("Length of the list is %d", count-1);
}

int main()
{
	Nodeptr head, node1, node2, node3, newHead, node4, node5,temp;
	node1 = createNode(node1,16);
	head = node1;                  //creation of head node
	temp = head;
	node2 = createNode(node2,34); //links generation
	temp->next = node2; 	     //jump to next node
	node3 = createNode(node3,35);
	node2->next = node3;
	node4 = createNode(node4, 50);
	node3->next = node4;
	node5 = createNode(node5, 100);
	node4->next = node5;
	//printing list
	printList(head);
	
//	newHead = deleteHead(head);
//	printf("\n");
//	printf("Head deleted!\n");
//	printList(newHead);           //List with new head
	
//	newHead = deleteTail(head);
//	printf("\n");
//	printf("Tail deleted!\n");
//	printList(newHead); 
//
//	deleteAfterNode(node3);
//	printf("\n");
//	printf("Node Deleted successfully!\n");
//	printList(head);
//
//	deleteBeforeNode(head, node4);
//	printf("\n");
//	printf("Node Deleted Successfully!\n");
//	printList(head);
//
//	printf("\n");
//	traverse(head); //Its can also count the number of elements in the list
	
	deleteItem(head, 35);
	printf("\nItem Deleted Successfully!\n");
	printList(head);
	
	return 0;
}
