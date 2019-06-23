#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<malloc.h>
struct node{
	int num;
	struct node *next;
};
struct node * createNode(int num) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = NULL;
	return newNode;
}

struct node * createList(int num) {
	struct node *head = createNode(num % 10);
	num /= 10;
	while (num) {
		struct node *newNode = createNode(num % 10);
		newNode->next = head;
		head = newNode;
		num /= 10;
	}
	return head;
}
int loopdetection(struct node *head){
	struct node *slow = head;
	struct node *fast = head;
	struct node *meet = NULL;
	struct node *temp = head;
	while (fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast){
			meet = fast;
			return 1;
		}
	}
	return 0;
}
int main(){
	int num;
	printf("enter the num to create list");
	scanf("%d", &num);
	struct node *head = createList(num);
	struct node *temp = head, *temp1 = head;
	while (temp->next != NULL){
		temp = temp->next;
	}
	//temp->next = temp1->next->next;
	int x = loopdetection(head);
	if (x == 1)
	printf("there is a loop");
	else
	printf("there is no loop");
	
	_getch();
}