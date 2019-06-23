/*sumoflinkedlists*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<conio.h>
#include<math.h>
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
void addnode(struct node **input1, int data)
{
	struct node* newnode = (struct node*) malloc(sizeof(struct node));
	newnode->num = data;
	newnode->next = (*input1);
	(*input1) = newnode;
}

void addcarry(struct node *input1, struct node *input2, int *carry,struct node **result){
	int sum;
	if (input1 != input2){
		addcarry(input1->next,input2,carry,result);
		sum = input1->num + *carry;
		*carry = sum / 10;
		sum = sum % 10;
		addnode(result, sum);
	}
}
struct node *addsamesizelinkedlists(struct node *input1, struct node *input2, int *carry)
{
	if (input1 == NULL)
		return NULL;
	struct node *result = (struct node *)malloc(sizeof(struct node));
	int sum;
	result->next = addsamesizelinkedlists(input1->next, input2->next, carry);
	sum = input1->num + input2->num + *carry;
	*carry = sum / 10;
	sum = sum % 10;

	result->num = sum;
	return result;
}
void sumoflinkedlists(struct node *input1, struct node *input2,struct node **result){
	int len1 = 0, len2 = 0,carry=0;
	struct node *temp = input1;
	struct node *temp1 = input2;
	if (input1 == NULL)
	{
		*result = input2;
		return;
	}
	if (input2 == NULL){
		*result = input1;
		return;
	}
	while (temp != NULL){
		   len1++;
		   temp = temp->next;
	}
	while (temp1 != NULL){
		len2++;
		temp1 = temp1->next;
	}
	struct node *temp2 = input2;
	
	if (len1 == len2){
		*result = addsamesizelinkedlists(input1, input2, &carry);
	}
	else{
		struct node *curr;
		int diff = abs(len1 - len2);
		struct node *ptr;
		if (len1 < len2){
			ptr = input1;
			input1 = input2;
			input2 = ptr;
		}
		for (curr = input1; diff--; curr = curr->next);
		*result = addsamesizelinkedlists(curr, input2, &carry);
		addcarry(input1, curr, &carry, result);
	}
	if (carry)
		addnode(result, carry);
}
int main(){
	int num1,num2;
	printf("enter the number to create a list");
	scanf("%d", &num1);
	struct node *input1 = createList(num1);
	printf("enter the number to create a list");
	scanf("%d", &num2);
	struct node *input2 = createList(num2);
	struct node *sum = NULL;
	sumoflinkedlists(input1, input2,&sum);
	printf("the sum of two linked lists is:");
	while (sum != NULL){
		printf("%d->", sum->num);
		sum = sum->next;
	}
	_getch();
}