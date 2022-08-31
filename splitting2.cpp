#include<stdio.h>
#include<stdlib.h>

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

//splitting list
Nodeptr splitList(Nodeptr head, Nodeptr ptr)
{
	Nodeptr temp, head1, head2;
	if(head == NULL)
	{
		printf("Void splitting");
	}
	else
	{
		temp = head; 
		while(temp != ptr)
			{
				temp = temp->next;
			}
		head2 = temp->next;
		temp->next = NULL;
		head1 = head;
	}	
	return head2;
}

int main()
{
	Nodeptr head, node1, node2, node3, newHead, node4, node5, node6, temp, head1, head2;
	node1 = createNode(node1,16);
	head = node1;                  //creation of head node
	temp = head;
	node2 = createNode(node2,34); //links generation
	temp->next = node2; 	     //jump to next node
	node3 = createNode(node3,69);
	node2->next = node3;
	node4 = createNode(node4, 70);
	node3->next = node4;
	node5 = createNode(node5, 99);
	node4->next = node5;
	node6 = createNode(node6, 100);
	node5->next = node6;
	//printing list
	printList(head);

	//splitting list 
	head1 = head;
	head2 = splitList(head, node1);
	printf("\nList have been splitted successfully!\n");
	printList(head1);
	printf("\n");
	printList(head2);
	return 0;
}
