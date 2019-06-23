///*knodesreverse*/
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#include<malloc.h>
//#include<conio.h>
//struct node{
//	int num;
//	struct node *next;
//};
//struct node * createNode(int num) {
//	struct node *newNode = (struct node *)malloc(sizeof(struct node));
//	newNode->num = num;
//	newNode->next = NULL;
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
//struct node *reverse(int k, struct node *head){
//	struct node *temp = head;
//	
//	struct node *curr = head;
//	struct node *prev = NULL, *next = NULL;
//	int c = 1;
//	while (curr != NULL && c<=k){
//		next = curr->next;
//		curr->next = prev;
//		prev = curr;
//		curr = next;
//
//		c++;
//	}
//	head = prev;
//	return head;
//}
//
//int main(){
//	int n;
//	printf("enter number of nodes:");
//	scanf("%d", &n);
//	int num;
//	printf("enter the number to create a list");
//	scanf("%d", &num);
//	struct node *head = createList(num);
//	int k;
//	printf("enter no of nodes to reverse");
//	scanf("%d", &k);
//	struct node *temp = head;
//	struct node *res1 = NULL,*temp1=NULL;
//	struct node *res=NULL;
//	while (temp != NULL){
//		int c = 1;
//		while (c < k&&temp->next!=NULL){
//			temp = temp->next;
//			c++;
//		}
//		
//		if (c==k){
//			temp1 = temp->next;
//			res = reverse(k, head);
//			head = temp1;
//			temp = head;
//			if (res1 == NULL)
//				res1 = res;
//			else{
//				struct node *ptr = res1;
//				while (ptr->next != NULL)
//					ptr = ptr->next;
//				ptr->next = res;
//			}
//		}
//		if (c!=k){
//			struct node *ptr = res1;
//			while (ptr->next != NULL)
//				ptr = ptr->next;
//			ptr->next = head;
//			temp = NULL;
//		}
//	}
//	struct node *ptr1 = res1;
//	while (ptr1 != NULL){
//		printf("%d->", ptr1->num);
//		ptr1 = ptr1->next;
//	}
//	_getch();
//}