///*merge sort using double linked lists*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct node * createNode(int num) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = num;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}
struct node *merge(struct node *head1,struct node *head2){
	
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	if (head1->data < head2->data){
		head1->next = merge(head1->next,head2);
		head1->next->prev = head1;
		head1->prev = NULL;
		return head1;
	}
	else{
		head2->next = merge(head1, head2->next);
		head2->next->prev = head2;
		head2->prev = NULL;
		return head2;
	}
}
struct node *findmiddle(struct node *head){
	struct node *slow = head;
	struct node *fast = head;
	struct node *mid ;
	while (fast ->next&&fast->next->next){
		slow = slow->next;
		fast = fast->next->next;
	}
	mid = slow->next;
	slow->next = NULL;
	return mid;
}
struct node *mergesort(struct node *head){

	if (head == NULL||head->next==NULL){
		return head;
	}
	struct node *mid=findmiddle(head);
	head=mergesort(head);
	mid=mergesort(mid);
	return merge(head, mid);
}


int main(){
	int n;
	int *a = (int *)malloc(100 * sizeof(int));
	struct node *head = NULL;
	printf("enter the no of elements:");
	scanf("%d", &n);
	printf("enter the elements");
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++){
		struct node *newnode = createNode(a[i]);
		if (head == NULL)
			head = newnode;
		else{
			struct node *temp = head;
			struct node *prev = NULL;
			while (temp != NULL){
				prev = temp;
				temp = temp->next;
			}
			prev->next = newnode;
			newnode->prev = prev;
		}
	}

	struct node *res=mergesort(head);
	while (res != NULL){
		printf("%d->", res->data);
		res = res->next;
	}
	_getch();
}
