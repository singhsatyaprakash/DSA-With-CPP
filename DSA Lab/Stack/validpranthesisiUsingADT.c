#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Stack structure
struct Stack {
    int top;
    char items[MAX];
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if stack is empty
bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, char item) {
    if (stack->top == MAX - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->items[++stack->top] = item;
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

// Function to check if the parentheses are balanced
bool isValidParentheses(const char* expr) {
    struct Stack stack;
    initStack(&stack);

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        // Push opening brackets onto the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&stack, ch);
        } 
        // For closing brackets, check for a matching opening bracket
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&stack)) {
                return false; // No matching opening bracket
            }

            char top = pop(&stack);

            // Check if the current closing bracket matches the last opening bracket
            if ((ch == ')' && top != '(') || 
                (ch == '}' && top != '{') || 
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    // At the end, stack should be empty if parentheses are balanced
    return isEmpty(&stack);
}

int main() {
    char expression[MAX];
    printf("Enter an expression with parentheses: ");
    scanf("%s", expression);

    if (isValidParentheses(expression)) {
        printf("The expression has balanced parentheses.\n");
    } else {
        printf("The expression does not have balanced parentheses.\n");
    }

    return 0;
}
