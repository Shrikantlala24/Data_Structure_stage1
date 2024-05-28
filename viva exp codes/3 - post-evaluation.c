#include <stdio.h>
#include <stdbool.h>
#include<math.h>

#define MAX_STACK_SIZE 100

// Define the stack
int stack[MAX_STACK_SIZE];
int top = -1;

// Function to push an element onto the stack
void push(int value) {
    if (top < MAX_STACK_SIZE - 1) {
        stack[++top] = value;
    } else {
        printf("Stack overflow!\n");
    }
}

// Function to pop an element from the stack
int pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack underflow!\n");
        return -1; // Return an error value
    }
}

// Function to evaluate a postfix expression
int evaluatePostfix(char postfix[]) {
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        if (isdigit(ch)) {
            // Operand: Push onto the stack
            push(ch - '0'); // Convert char to int
        } else {
            // Operator: Pop two operands and perform the operation
            int operand2 = pop();
            int operand1 = pop();
            switch (ch) {
                case '+':
                    push(operand1 + operand2);
                    break;
                case '-':
                    push(operand1 - operand2);
                    break;
                case '*':
                    push(operand1 * operand2);
                    break;
                case '/':
                    push(operand1 / operand2);
                    break;
                case '^':
                    push(pow(operand1,operand2));
                    break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    return -1; // Return an error value
            }
        }
    }
    return pop(); // Result of the expression
}

int main() {
    char postfix[100];
    printf("Enter the postfic expression: ");
    gets(postfix);
    int result = evaluatePostfix(postfix);
    if (result != -1) {
        printf("Result: %d\n", result);
    }
    return 0;
}
