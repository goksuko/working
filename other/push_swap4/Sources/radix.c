#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Stack structure
typedef struct {
    Node* top;
} Stack;

// Function to initialize a stack
void initializeStack(Stack* stack) {
    stack->top = NULL;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == NULL) {
        fprintf(stderr, "Stack underflow.\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

// Function to check if a stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Function to find the maximum element in the array
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform radix sort using two stacks
void radixSort(int arr[], int n) {
    int max = findMax(arr, n);
    Stack stack[2];

    // Initialize two stacks
    initializeStack(&stack[0]);
    initializeStack(&stack[1]);

    // Perform radix sort
    for (int bitPosition = 0; max >> bitPosition > 0; ++bitPosition) {
        // Distribute elements to the appropriate stack
        for (int i = 0; i < n; ++i) {
            int bit = (arr[i] >> bitPosition) & 1;
            push(&stack[bit], arr[i]);
        }

        // Gather elements back to the original array
        int index = 0;
        for (int j = 0; j < 2; ++j) {
            while (!isEmpty(&stack[j])) {
                arr[index++] = pop(&stack[j]);
            }
        }
    }
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    radixSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
