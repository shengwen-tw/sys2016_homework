#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _List {
	struct _List *next;
	int val;
} List;

/* Append the linked list and return new element's address  */
List* list_append(List **list, int val)
{
	//Create new element
	List *new_element = (List *)malloc(sizeof(List));

	new_element->val = val;
	new_element->next = NULL;

	List *cur = *list;

	//Empty list
	if(cur == NULL) {
		*list = new_element;
		return new_element;
	}

	//Go to the last item
	while(cur->next != NULL) {
		cur = cur->next;
	}

	//Append
	cur->next = new_element;

	return new_element;
}

/* Traversal  print elements */
int print_list(List *list)
{
	assert(list);

	List *cur = list;

	
	while(cur->next != NULL) {
		printf("%d ", cur->val);
		cur = cur->next;
	}

	printf("%d\n", cur->val);
}

/* List element swap  */
int list_swap(List **head, List *a, List *b)
{
	assert(head);
	assert(a);
	assert(b);
	assert(a != b);

	List new_head;
	new_head.next = *head;

	/* Do traversal */
	List *cur = &new_head;
	
	/* Find the previous element of a */
	List *a_previous, *b_previous;

	while(cur->next != a) {
		cur = cur->next;
		if(cur == NULL) {
			return 1;
		}
	}
	a_previous = cur;

	/* Find the previous element of b */
	while(cur->next != b) {
		cur = cur->next;
		if(cur == NULL) {
			return 1;
		}
	}
	b_previous = cur;
		
	/* Swap */
	a_previous->next = b;
	b_previous->next = a;
	List *tmp = a->next;
	a->next = b->next;
	b->next = tmp;

	*head = new_head.next;
}

int bubble_sort(List **head)
{
	List *wall = NULL;
	List *cur;

	int leave = 0;
	while(!leave) {
		leave = 1;

		cur = *head;

		while(cur->next != wall) {
			leave = 0;

			if(cur->val > cur->next->val) {
				list_swap(head, cur, cur->next);
			} else {
				cur = cur->next;
			}
		}

		wall = cur;
	}
} 

int main(void)
{
	List *list = NULL;

	/* Linked list creation */
	list_append(&list, 8);
	list_append(&list, 9);
	list_append(&list, 1);
	list_append(&list, 4);
	list_append(&list, 2);
	list_append(&list, 5);

	printf("Befor bubble sort:\n");
	print_list(list);

	/* Swap elements */
	bubble_sort(&list);

	printf("After bubble sort:\n");
	print_list(list);

	return 0;
}

