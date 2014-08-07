#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};

typedef struct node* Node;

Node create_node(int data)
{
    Node new_node = (Node)malloc(sizeof(struct node));
    if(!new_node)
        return NULL;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node create_head(int data)
{
    Node head = create_node(data);
    return head;
}

void add_node(Node head, Node n)
{
    Node tmp = head;
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = n;
}

void free_list(Node head)
{
    Node tmp = NULL;
    while(head)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void del_node(Node n)
{
    Node tmp = n;
    if(tmp->next)
    {
        tmp->data = tmp->next->data;
        tmp->next = tmp->next->next;
    }
    free(tmp->next);
}

void print_list(Node head)
{
    while(head)
    {
        printf("%d->",head->data);
        head = head->next;
    }
    printf("\b \b");
    printf("\b \b");
    printf("\n");
}

Node reverse(Node head)
{
    Node tmp = NULL;
    Node reversed = NULL;
   
    while(head)
    {
        tmp = head;
        head = head->next;
        tmp->next = reversed;
        reversed = tmp;
    }
    return reversed;
}

Node reverse_recursive(Node curr, Node prev)
{
    if(!curr->next)
    {
	curr->next = prev;
	return curr;
    }

    Node new_head = reverse_recursive(curr->next, curr);
    curr->next = prev;
    return new_head;
}

/*
list_node* rev_list_rec(list_node* head, list_node* prev)
{
  // Base case
  if(head == NULL || head->next == NULL)
  {
    head->next = prev;
    return head;
  }

  list_node* new_head = rev_list_rec(head->next, head);
  head->next = prev;
  return new_head;
}
 */
int main()
{
    Node head = create_head(1);
    print_list(head);

    Node added = create_node(2);
    add_node(head, added);
    added = create_node(3);
    add_node(head, added);
    added = create_node(4);
    add_node(head, added);
    added = create_node(5);
    add_node(head, added);
    print_list(head);
    Node rev = reverse(head);
    print_list(rev);
    rev = reverse_recursive(rev, NULL);
    print_list(rev);
    free_list(rev);
    return 0;
}
