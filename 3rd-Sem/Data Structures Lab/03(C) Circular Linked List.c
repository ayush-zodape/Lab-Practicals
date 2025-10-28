#include <stdio.h>
#include <stdlib.h>
// Structure of a node
struct Node {
int data;
struct Node* next;
};
struct Node* head = NULL; // Global head pointer
// Function to insert element at the end
void insertElement(int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
if (head == NULL) { // First node
head = newNode;
newNode->next = head; // Circular link
} else {
struct Node* temp = head;
while (temp->next != head) { // Traverse till last node
temp = temp->next;
}
temp->next = newNode;
newNode->next = head; // Point back to head
}
}
// Function to delete node by position
void deleteNode(int pos) {
if (head == NULL) {
printf("List is empty\n");
return;
}
struct Node* temp = head;
// Case 1: Delete first node
if (pos == 1) {
if (head->next == head) { // Only one node
free(head);
head = NULL;
return;
}
struct Node* last = head;
while (last->next != head) { // Find last node
last = last->next;
}
last->next = head->next;
head = head->next;
free(temp);
return;
}
// Case 2: Delete at other position
struct Node* prev = NULL;
for (int i = 1; i < pos && temp->next != head; i++) {
prev = temp;
temp = temp->next;
}
if (temp == head) { // Position out of range
printf("Position out of range!\n");
return;
}
prev->next = temp->next;
free(temp);
}
// Function to display the list
void display() {
if (head == NULL) {
printf("List is empty\n");
return;
}
struct Node* temp = head;
printf("Circular Singly Linked List: ");
do {
printf("%d -> ", temp->data);
temp = temp->next;
} while (temp != head);
printf("(head)\n");
}
// Main function
int main() {
int choice, value, pos;
while (1) {
printf("\n--- Circular Singly Linked List Menu ---\n");
printf("1. Insert Element\n");
printf("2. Delete Node (by position)\n");
printf("3. Display List\n");
printf("4. Exit\n");
printf("Enter choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter value: ");
scanf("%d", &value);
insertElement(value);
break;
case 2:
printf("Enter position to delete: ");
scanf("%d", &pos);
deleteNode(pos);
break;
case 3:
display();
break;
case 4:
exit(0);
default:
printf("Invalid choice!\n");
}
}
return 0;
}
