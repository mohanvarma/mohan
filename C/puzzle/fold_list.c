/*
 * Fold a linked list such that last element is 2nd, last but 1 is 4th etc..
 * Ex: 1->2->3->4->5->6->7->8->9 => 1->9->2->8->3->7->4->6->5
 */

/*
 * Approach: Split it in half, reverse 2nd half, merge both
 */

#include<stdio.h>
#include<stdlib.h>
struct list_node{
    int data;
    struct list_node* next;
};

typedef struct list_node node;

node* global_head = 0;
void create_head(int data);
node* add_node(int data);
node* reverse_list(node* head);
void free_list(node* head);
void print_list(node* head);

void create_head(int data)
{
    global_head = (node*) malloc(sizeof(node));
    global_head->data = data;
    global_head->next = 0;
}

node* add_node(int data)
{
    node* head = global_head;
    while(head->next != 0)
    {
	head = head->next;
    }

    node* temp = (node*) malloc(sizeof(node));
    temp->next = 0;
    temp->data = data;

    head->next = temp;
    return temp;
}

node* reverse_list(node* head)
{
    node* old_head = head;
    node* temp = 0;
    node* reversed = 0;

    while(old_head != NULL)
    {
	temp = old_head;
	old_head = old_head->next;
	temp->next = reversed;
	reversed = temp;
    }

    return reversed;
}

node* reverse_list_recursive_v1(node* head)
{
    node* old_head = head;
	// Trivial reverse
	if(!old_head || !old_head->next)
		return old_head;

	node* rest = old_head->next;
	old_head->next = NULL;

	node* new_head = reverse_list_recursive_v1(rest);
	rest->next = old_head;
	return new_head;
}

node* reverse_list_recursive(node* head, node* rev)
{
    node* old_head = head;
	// Trivial reverse
	if(!old_head->next)
		return old_head;

	node* temp = old_head;
	old_head = old_head->next;
	temp->next = rev;
	node* new_head = reverse_list_recursive(old_head, temp);

	old_head->next = temp;
	return new_head;
}

void free_list(node* head)
{
    node* temp_head = head;

    while(temp_head != NULL)
    {
	node* temp = temp_head;
	temp_head = temp_head->next;
	free(temp);
    }

    global_head = 0;
}

void print_list(node* head)
{
    node* temp_head = head;

    while(temp_head != NULL)
    {
	printf("%d->", temp_head->data);
	temp_head = temp_head->next;
    }

    printf("\b \b");
    printf("\b \b");
    printf("\n");
}

node* fold_list(node* head)
{
    if(!head)
	return NULL;

    node* left = head;
    node* right = head;
    node* new_head = NULL;

    node* tail = NULL;
    node* next = NULL;
    while(right->next && right->next->next)
    {
	left = left->next;
	right = right->next->next;
    }

    right = left->next;
    left->next = NULL;
    
    left = head;
    right = reverse_list(right);

    printf("Left list:");
    print_list(left);
    printf("Right list:");
    print_list(right);

    // Merge both lists taking 1 element at a time
    while(left || right)
    {
	if(left)
	{
	    next = left;
	    left = left->next;
	    next->next = 0;
	}
	if(!new_head)
	{
	    new_head = next;
	    tail = next;
	}
	else
	{
	    // Append the next node after tail
	    // Update tail
	    tail->next = next;
	    tail = next; 
	}

	if(right)
	{
	    // Append the next node after tail
	    // Update tail
	    next = right;
	    tail->next = next;
	    right = right->next;
	    next->next = 0;
	    tail = next;
	}
    }

    return new_head;

}

node* reverse_list_groups(node* head, int k)
{
    node* tmp = NULL;
    node* curr = head;
    node* reversed = NULL;
    int count = 0;
    // Reverse initial k nodes
    while(curr && count<k)
    {
	tmp = curr;
	curr = curr->next;
	tmp->next = reversed;
	reversed = tmp;
	count++;
    }
    // If not enough(k) elements, return the list reversed so far
    if(!curr)
	return reversed;

    // Reverse remaining list using recursion
    node* temp_reversed = reverse_list_groups(curr, k);
    //head is still pointing to the first(now, last) node of the list
    //link it with next reversed group of k nodes
    head->next = temp_reversed;
    return reversed;
}

int main()
{
    int i = 1;
    create_head(i);
    print_list(global_head);

    for(i = 2; i <= 9; i++)
    {
	// Can optimize from O(n) to O(1) by saving tail as last
	// added node
	add_node(i);
    }

    // Debug
    print_list(global_head);

    // Split it in half
    node* left = global_head;
    node* right = global_head;

    while(right->next && right->next->next)
    {
	left = left->next;
	right = right->next->next;
    }
    
    right = left->next;
    left->next = 0;
    left = global_head;

    // Debug
    print_list(left);
    print_list(right);

    right = reverse_list(right);

    print_list(right);

    node* new_head = 0;
    node* next = 0;
    node* tail = 0;

    while(left || right)
    {
	if(left)
	{
	    next = left;
	    left = left->next;
	    next->next = 0;

	    if(!new_head)
	    {
		new_head = next;
	    }
	    else
	    {
		if(tail)
		    tail->next = next;
		tail = next;
	    }
	}
	
	if(right)
	{
	    next = right;
	    right = right->next;
	    next->next = 0;

	    if(tail)
	    {
	    	tail->next = next;
		tail = next;
	    }
	    else
	    {
		new_head->next = next;
		tail = next;
	    }
	}
    }

    global_head = new_head;

    print_list(global_head);

    free_list(global_head);
    global_head = 0;

    printf("=================fold functions===================\n");
    i = 1;
    create_head(i);

    for(i = 2; i <= 9; i++)
    {
	// Can optimize from O(n) to O(1) by saving tail as last
	// added node
	add_node(i);
    }

    print_list(global_head);

    node* folded_head = fold_list(global_head);

    print_list(folded_head);
    free_list(folded_head);
    global_head = 0;

    i = 1;
    create_head(i);

    for(i = 2; i <= 9; i++)
    {
	// Can optimize from O(n) to O(1) by saving tail as last
	// added node
	add_node(i);
    }

    print_list(global_head);

    node* reverse_head_groups = reverse_list_groups(global_head, 3);

    print_list(reverse_head_groups);
    free_list(reverse_head_groups);
    global_head = 0;


    return 0;
}
