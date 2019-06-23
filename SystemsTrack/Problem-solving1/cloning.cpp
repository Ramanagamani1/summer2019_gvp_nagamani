///*cloning of linked list*/
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#include<malloc.h>
//#include<conio.h>
//struct node{
//	int num;
//	struct node *next;
//	struct node *random;
//};
//struct node * createNode(int num) {
//	struct node *newNode = (struct node *)malloc(sizeof(struct node));
//	newNode->num = num;
//	newNode->next = NULL;
//	newNode->random = NULL;
//	return newNode;
//}
//
//struct node * createList(int num) {
//	struct node *head = createNode(num % 10);
//	num /= 10;
//	while (num) {
//		struct node *newNode = createNode(num % 10);
//		newNode->next = head;
//		head = newNode;
//		num /= 10;
//	}
//	return head;
//}
//struct node *clonelist(struct node *head){
//	struct node *res = (struct node*)malloc(sizeof(struct node));
//	struct node *temp = head,*next=NULL;
//	while (temp != NULL){
//		struct node *newNode = (struct node *)malloc(sizeof(struct node));
//		newNode->num = temp->num;
//		newNode->random = NULL;
//		next = temp->next;
//		temp->next = newNode;
//		newNode->next = next;
//		temp = temp->next->next;
//	}
//	struct node *temp1 = head;
//	struct node *temp3 = head;
//	while (temp1!= NULL){
//		if (temp1->random == NULL){
//			temp1 = temp1->next->next;
//			temp3 = temp3->next->next;
//		}
//		else{
//			struct node *ptr = temp1;
//			struct node *temp3 = head;
//			while (ptr->random != temp3)
//				temp3 = temp3->next;
//		        
//		temp1->next->random = temp3->next;
//		temp1 = temp1->next->next;
//		temp3 = temp3->next->next;
//		}
//	}
//	head = head->next;
//	temp = head;
//	while (temp ->next!= NULL){
//		temp->next = temp->next->next;
//		temp = temp->next;
//	}
//	return head;
//	
//}
//int main(){
//	int num;
//	printf("enter the num to create list");
//	scanf("%d", &num);
//	struct node *head = createList(num);
//	struct node *temp = head;
//	temp = temp->next;
//	temp->random = temp->next->next;
//	temp = temp->next;
//	temp->random = head;
//	struct node *res=clonelist(head);
//	struct node *ptr = res;
//	while (ptr != NULL){
//		printf("%d->", ptr->num);
//		ptr = ptr->next;
//	}
//	_getch();
//}