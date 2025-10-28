#include <stdio.h>
#include <stdlib.h>
// Define structure for a stack node
struct Node {
int data;
struct Node* next;
};
// Initialize stack as empty
struct Node* top = NULL;
// Function to push an element onto the stack
void push(int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
if (newNode == NULL) {
printf("Stack Overflow! Unable to allocate memory.\n");
return;
}
newNode->data = value;
newNode->next = top; // Link new node to previous top
top = newNode; // Make new node the top
printf("%d pushed to stack.\n", value);
}
// Function to pop an element from the stack
void pop() {
if (top == NULL) {
printf("Stack Underflow! No elements to pop.\n");
return;
}
struct Node* temp = top;
printf("%d popped from stack.\n", top->data);
top = top->next;
free(temp);
}
// Function to peek at the top element
void peek() {
if (top == NULL) {
printf("Stack is empty! Nothing to peek.\n");
} else {
printf("Top element is: %d\n", top->data);
}
}
// Function to display elements of the stack
void display() {
if (top == NULL) {
printf("Stack is empty.\n");
return;
}
struct Node* temp = top;
printf("Stack elements (top to bottom): ");
while (temp != NULL) {
printf("%d -> ", temp->data);
temp = temp->next;
}
printf("NULL\n");
}
// Main function to perform stack operations
int main() {
int choice, value;
while (1) {
printf("\n--- Stack using Linked List ---\n");
printf("1. Push\n");
printf("2. Pop\n");
printf("3. Peek\n");
printf("4. Display\n");
printf("5. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter value to push: ");
scanf("%d", &value);
push(value);
break;
case 2:
pop();
break;
case 3:
peek();
break;
case 4:
display();
break;
case 5:
printf("Exiting...\n");
exit(0);
default:
printf("Invalid choice! Please try again.\n");
}
}
return 0;
}
