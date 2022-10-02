



// C++ program to merge two sorted linked lists 

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node
{
	public:
	int data;
	Node* next;
};


void MoveNode(Node** destRef, Node** sourceRef);

/* Takes two lists sorted in increasing
order, and splices their nodes together
to make one big sorted list which
is returned. */
Node* SortedMerge(Node* a, Node* b)
{
	
	Node dummy;
	Node* tail = &dummy;
	dummy.next = NULL;
	while (1)
	{
		if (a == NULL)
		{
			tail->next = b;
			break;
		}
		else if (b == NULL)
		{
			tail->next = a;
			break;
		}
		if (a->data <= b->data)
			MoveNode(&(tail->next), &a);
		else
			MoveNode(&(tail->next), &b);

		tail = tail->next;
	}
	return(dummy.next);
}


/* MoveNode() function takes the
node from the front of the source,
and move it to the front of the dest.
It is an error to call this with the
source list empty.*/

void MoveNode(Node** destRef, Node** sourceRef)
{
	
	Node* newNode = *sourceRef;
	assert(newNode != NULL);

	*sourceRef = newNode->next;

	newNode->next = *destRef;

	*destRef = newNode;
}


/* Function to insert a node at
the beginning of the linked list */
void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

/* Function to print nodes in a given linked list */
void printList(Node *node)
{
	while (node!=NULL)
	{
		cout<<node->data<<" ";
		node = node->next;
	}
}


int main()
{
	Node* res = NULL;
	Node* a = NULL;
	Node* b = NULL;


	push(&a, 15);
	push(&a, 10);
	push(&a, 5);

	push(&b, 20);
	push(&b, 3);
	push(&b, 2);

	/* Remove duplicates from linked list */
	res = SortedMerge(a, b);

	cout << "Merged Linked List is: \n";
	printList(res);

	return 0;
}


