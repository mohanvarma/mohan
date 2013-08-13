/* Remove later*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//strlen
//malloc
//free

void addRecord(const char*, int, int, int, int, int);
void clear(void);
void arrange(int, int, int,  int, int);



struct record
{
	char* student_name;
	int student_marks1;
	int student_marks2;
	int student_marks3;
	int student_marks4;
	int student_marks5;
	struct record* next;
};

typedef struct record student;

student* custom_sort(student* head, int inputKey, int outputOrder);

int compare_nodes(student* head, student* right, int inputKey, int outputOrder);

/* Remove later*/
void print_rec(void);
void print_local(student* node);

void print_output(student* temp, int outputKey);

student* head = 0;

void addRecord(const char *pName, int ms1, int ms2, int ms3, int ms4, int ms5)
{
	student* temp = (student*) malloc(sizeof(student));
	//Malloc error
	if(!temp)
		return;

	temp->student_name = (char*) malloc(strlen(pName)+1);
	strcpy(temp->student_name, pName);
	temp->student_marks1 = ms1;
	temp->student_marks2 = ms2;
	temp->student_marks3 = ms3;
	temp->student_marks4 = ms4;
	temp->student_marks5 = ms5;
	temp->next = 0;
	//First node
	if(!head)
	{
		head = temp;
	}
	else
	{
		//Go till the last node and append the node
		student* s_type = head;
		while(s_type->next)
		{
			s_type = s_type->next;
		}
		s_type->next = temp;
	}
}

void clear(void)
{
	student* s_type = head;
	if(!head)
		return;

	while(s_type)
	{
		student* temp = s_type;
		s_type = s_type->next;
		if(temp->student_name)
			free(temp->student_name);
		free(temp);
	}
	head = 0;
}

/* Remove later*/
void print_rec(void)
{
	student* s_type = head;
	while(s_type)
	{
		printf("\n");
		printf("%s ", s_type->student_name);
		printf("%d ", s_type->student_marks1);
		printf("%d ", s_type->student_marks2);
		printf("%d ", s_type->student_marks3);
		printf("%d ", s_type->student_marks4);
		printf("%d ", s_type->student_marks5);
		s_type = s_type->next;
	}
}

/* Remove later*/
void print_local(student* node)
{
	student* s_type = node;
	while(s_type)
	{
		printf("\n");
		printf("%s ", s_type->student_name);
		printf("%d ", s_type->student_marks1);
		printf("%d ", s_type->student_marks2);
		printf("%d ", s_type->student_marks3);
		printf("%d ", s_type->student_marks4);
		printf("%d ", s_type->student_marks5);
		s_type = s_type->next;
	}
}

void print_output(student* temp, int outputKey)
{
	if(outputKey == 0)
	{
		printf("\n%s", temp->student_name);
		return;
	}
	else if(outputKey == 1)
	{
		printf("\n%d", temp->student_marks1);
		return;
	}
	else if(outputKey == 2)
	{
		printf("\n%d", temp->student_marks2);
		return;
	}
	else if(outputKey == 3)
	{
		printf("\n%d", temp->student_marks3);
		return;
	}
	else if(outputKey == 4)
	{
		printf("\n%d", temp->student_marks4);
		return;
	}
	else if(outputKey == 5)
	{
		printf("\n%d", temp->student_marks5);
		return;
	}
	return;
}

int compare_nodes(student* head, student* right, int inputKey, int outputOrder)
{
	if(outputOrder == 0)
	{
		if(inputKey == 1)
			return (head->student_marks1 - right->student_marks1);
		else if(inputKey == 2)
			return (head->student_marks2 - right->student_marks2);
		else if(inputKey == 3)
			return (head->student_marks3 - right->student_marks3);
		else if(inputKey == 4)
			return (head->student_marks4 - right->student_marks4);
		else if(inputKey == 5)
			return (head->student_marks5 - right->student_marks5);
	}
	else
	{
		if(inputKey == 1)
			return (right->student_marks1 - head->student_marks1);
		else if(inputKey == 2)
			return (right->student_marks2 - head->student_marks2);
		else if(inputKey == 3)
			return (right->student_marks3 - head->student_marks3);
		else if(inputKey == 4)
			return (right->student_marks4 - head->student_marks4);
		else if(inputKey == 5)
			return (right->student_marks5 - head->student_marks5);
	}
}

student* custom_sort(student* head, int inputKey, int outputOrder)
{
	student* s_type = head;
	if(!s_type)
		return head;

	//only 1 element, nothing to sort
	if(!(s_type->next))
		return head;

	student* left = head;
	student* right = head;
	student *result = 0;
    student *next   = 0;
    student *tail   = 0;
	while(right->next && right->next->next)
	{
		left = left->next;
		right = right->next->next;
	}

	right = left->next;
	left->next = 0;
	//printf("\nPrinting after splitting in the middle\n");
	//printf("\nLeft\n");
	//print_local(head);
	//printf("\nRight\n");
	//print_local(right);
	//head contains the left half & right contains the right half to be merged
	head = custom_sort(head, inputKey, outputOrder);
	right = custom_sort(right, inputKey, outputOrder);

    while (head || right)
    {
        if (!right) {
            next = head;
            head = head->next;
        } else if (!head) {
            next = right;
            right = right->next;
        } else if (compare_nodes(head, right, inputKey, outputOrder) > 0) {
            next = head;
            head = head->next;
        } else {
            next = right;
            right = right->next;
        }
        if (!result) {
            result=next;
        } else {
            tail->next=next;
        }
        tail = next;
    }
    return result;
}

void arrange(int inputKey, int n, int nPlusm,  int outputOrder, int outputKey)
{
	student* sorted = custom_sort(head, inputKey, outputOrder);
	printf("\nAfterSorting\n");
	print_local(sorted);
	printf("\nStripping the list\n");
	int count = 1;
	student* temp;
	for(temp=sorted; temp!=NULL && count<=nPlusm; temp=temp->next, count++)
	{
		if(count>=n)
			print_output(temp, outputKey);
	}
}


int main()
{
	//(“TheGod”, 120, 134, 657, 78, 99), (“cave”, 12, 567, 45, 7, 90), (“Barrack”, 32, 34, 784, 567, 890), (“Yespapa”, 890, 678, 790, 12, 990), (“ocean”, 990, 678, 67, 45, 890)
	addRecord("TheGod", 120, 134, 657, 78, 99);
	addRecord("cave", 12, 567, 45, 7, 90);
	addRecord("Barrack", 32, 34, 784, 567, 890);
	addRecord("Yespapa", 890, 678, 790, 12, 990);
	//addRecord("Yespapa", 890, 678, 790, 12, 990);
	addRecord("ocean", 990, 678, 67, 45, 890);
	print_rec();
	arrange(1, 1, 4, 1, 0);
	clear();
	return 0;
}
