///*knodesreverse*/
#define _crt_secure_no_warnings
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<conio.h>
struct node{
	int num;
	struct node *next;
};
struct node * createnode(int num) {
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->num = num;
	newnode->next = null;
	return newnode;
}

struct node * createlist(int num) {
	struct node *head = createnode(num % 10);
	num /= 10;
	while (num) {
		struct node *newnode = createnode(num % 10);
		newnode->next = head;
		head = newnode;
		num /= 10;
	}
	return head;
}
struct node *reverse(int k, struct node *head){
	struct node *temp = head;
	
	struct node *curr = head;
	struct node *prev = null, *next = null;
	int c = 1;
	while (curr != null && c<=k){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;

		c++;
	}
	head = prev;
	return head;
}

int main(){
	int n;
	printf("enter number of nodes:");
	scanf("%d", &n);
	int num;
	printf("enter the number to create a list");
	scanf("%d", &num);
	struct node *head = createlist(num);
	int k;
	printf("enter no of nodes to reverse");
	scanf("%d", &k);
	struct node *temp = head;
	struct node *res1 = null,*temp1=null;
	struct node *res=null;
	while (temp != null){
		int c = 1;
		while (c < k&&temp->next!=null){
			temp = temp->next;
			c++;
		}
		
		if (c==k){
			temp1 = temp->next;
			res = reverse(k, head);
			head = temp1;
			temp = head;
			if (res1 == null)
				res1 = res;
			else{
				struct node *ptr = res1;
				while (ptr->next != null)
					ptr = ptr->next;
				ptr->next = res;
			}
		}
		if (c!=k){
			struct node *ptr = res1;
			while (ptr->next != null)
				ptr = ptr->next;
			ptr->next = head;
			temp = null;
		}
	}
	struct node *ptr1 = res1;
	while (ptr1 != null){
		printf("%d->", ptr1->num);
		ptr1 = ptr1->next;
	}
	_getch();
}
