#include<stdio.h>

int top=-1;
int stack[10];
void push(int);
int pop();
void insert_sort(int);
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
				insert_sort(n);
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
return 0;
}
void push(int n){
	if(top==10){
		printf("\nStack Overflow!");
		return;
	}
	else{
		top++;
		stack[top]=n;	
	}
}
int pop(){
	if(top==-1){
		printf("\nStack Underflow!");
		return;	
	}	
	else
		top--;
		return stack[top+1];		
}

void insert_sort(int element){
	int x;
	if(top==-1 || stack[top]<element){
		push(element);
		return;
	}
	else{
		x=pop();
		insert_sort(element);
		push(x);
	}
}

void peek(){
	if(top==-1){
		printf("\nStack is empty!");
	}
	else{
		printf("\n%d is at the top of the stack",stack[top]);
	}
	
}

void display(){
	int x;
	if(top==-1){
		return;
	}	
	else{
		x=pop();
		display();
		printf(" %d", x);
		push(x);
	}
}
