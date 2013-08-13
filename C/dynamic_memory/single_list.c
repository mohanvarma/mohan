#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
int data ;
struct node* next;
};

/* 
(a) Write the function void display(struct node* head) that displays all the elements of the list.
(b) Write the function struct node* addback(struct node* head,int data) that adds an element to the
end of the list. The function should return the new head node to the list.
(c) Write the function struct node* ?nd(struct node* head,int data) that returns a pointer to the
element in the list having the given data. The function should return NULL if the item does
not exist.
(d) Write the function struct node* delnode(struct node* head,struct node* pelement) that deletes the
element pointed to by pelement (obtained using ?nd). The function should return the up­
dated head node. Make sure you consider the case when pelement points to the head node.
(e) Write the function void freelist(struct node* head) that deletes allthe element ofthe list. Make
sure you do not use any pointer after it is freed.
(f) Write test code to illustrate the working of each of the above functions
 *
 */
void display(struct node* head);
struct node* addback(struct node* head,int data);
struct node* find(struct node* head,int data);
struct node* delnode(struct node* head,struct node* pelement);
void freelist(struct node* head);
void test_func();

struct node* reversed(struct node* head)
{
	struct node* tmp = NULL;
	struct node* reversed = NULL;
	while(head)
	{
	tmp = head;
	head = head->next;
	tmp->next = reversed;
	reversed = tmp;
	}
	return reversed;
}
void display(struct node* head)
{
	if(!head)
		return;
	struct node* temp = head;
	while(temp!=NULL)
	{
		printf(" %d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

struct node* addback(struct node* head,int data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	if(!head)
	{
		head = temp;
	}
	else
	{	/*
		while(node_type!=NULL)
		{
			node_type = node_type->next;
		}
		node_type = temp;
		*/
		struct node* node_type = head;
		while(node_type->next!=NULL)
		{
			node_type = node_type->next;
		}
		node_type->next = temp;
	}
	return head;
}

struct node* find(struct node* head,int data)
{
	if(!head)
		return NULL;

	struct node* temp = head;
	while(temp!=NULL)
	{
		if(temp->data == data)
			return temp;
		temp = temp->next;
	}
	return NULL;
}

struct node* delnode(struct node* head,struct node* pelement)
{
	if(!head)
		return head;
	//int data = pelement->data;
	//struct node* temp = find(head, data);
	if(pelement == head)
	{
		struct node* node_type = head;
		head = head->next;
		free(node_type);
		return head;
	}
	else
	{
		struct node* node_type = NULL;
		/*struct node* node_type = pelement;
		pelement = pelement->next;
		free(node_type);
		return head;*/
		node_type = head;
		while(node_type && node_type->next && node_type->next!=pelement)
		{
			node_type = node_type->next;
		}
		struct node* temp = node_type->next;
		node_type->next = node_type->next->next;
		free(temp);
		return head;
	}
}


void freelist(struct node* head)
{
	struct node* temp = head;
	if(!temp)
		return;

	while(head!=NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}



int main()
{
	struct node* head = NULL;
	//struct node* head = malloc(sizeof(struct node));
	//head->next = NULL;
	display(head);
	head = addback(head, 10);
	head = addback(head, 20);
	struct node* findNode = head;
	head = addback(head, 30);
	display(head);
	struct node* temp = find(head, 20);
	display(temp);
	head = delnode(head, findNode);
	display(head);
	head = addback(head, 40);
	display(head);
	temp = find(head, 30);
	display(temp);
	head = delnode(head, temp);
	display(head);
	head = addback(head, 100);
	display(head);
	struct node* rev = reversed(head);
	display(rev);
	return 0;
}
