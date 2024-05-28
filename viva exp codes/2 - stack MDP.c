#include<stdio.h>
#include<stdlib.h>

#define MAX 4
int stack_arr[MAX];
int top = -1;

void push(int n) {
    if (top == MAX - 1){
    printf("Stack overflow\n");
    return; }
    
    top ++;
    stack_arr[top] = n;
}

int pop() {
    if (top == -1)
    {
        printf("stack underflow\n");
        return 0;
    }
    
    int value = stack_arr[top];
    top --;
    return value;

}

void print_stack() {
    printf("the stack is \n");
    for (int i = 0; i <= top; i++) {
    printf(" %d\n",stack_arr[i]);
    }
    
}

int main() {
    int choice,data;
    for (int i = 0; ; i++)
    {
         printf("1. push\n2. pop\n3. print top element\n4. print all elements\n5. quit");
    printf("\n enter your choice: ");
    scanf("%d",&choice);
        
        switch (choice)
        {
        case 1:
            printf("enter the number: ");
            scanf("%d",&data);
            push(data);
            break;
        case 2:
            data = pop();
            printf("the deleted element is %d\n",data);
            break;
        case 3:
            printf("the top element is %d\n",stack_arr[top]);
            break;
        case 4:
            print_stack();
            break;
        case 5:
            printf("Quiting.....\n done");
            exit(1);
        
        default:
            printf("wrong choice\n");
            break;
        }
    }
    
}