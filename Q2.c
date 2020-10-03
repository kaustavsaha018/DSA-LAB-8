#include<stdio.h>
#include<stdlib.h>

struct stack{
	int data;
	struct stack *prev;
};
struct stack *head,*newnode,*temp;
void push(int);
int pop();
void peek();
void display();

int main(){
	
	printf("Enter 1 for push\nEnter 2 for pop\nEnter 3 for peek\nEnter 4 for display\nEnter 5 to exit\n");
	int choice,again=1;
	int n;
	while(again!=0){
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("\nEnter a number to be pushed into the stack: ");
				scanf("%d", &n);
				push(n);
				break;
			case 2:
				printf("\n%d has been poped out from the stack",pop());
				break;
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
			case 5:
				again=0;
				break;
			default:
				printf("\nInvalid Choice!");
				
		}
	}
}

void push(int n){
	newnode=(struct stack *)malloc(sizeof(struct stack));
	if(head==NULL){
		head=newnode;
		temp=newnode;
		temp->data=n;
		temp->prev=NULL;
	}
	else{
		head=newnode;
		head->prev=temp;
		temp=head;
		temp->data=n;
	}
}
int pop(){
	if(head==NULL){
		printf("\nStack is empty!");
		exit(1);
	}
	else{
		temp=head;
		head=head->prev;
		return temp->data;
	}
	
}
void peek(){
	if(head==NULL){
		printf("\nStack is empty!");
		return;
	}
	else{
		printf("\n%d is at the top of the stack",head->data);
	}
	
}
void display(){
	if(head==NULL){
		printf("\nStack is empty!");
		return;	
	}
	else{
		printf("\nThe elements in the stack are:");
		while(head!=NULL){
			printf(" %d", head->data);
			head=head->prev;
		}
		
	}
	
}
