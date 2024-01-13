/*Write a c program for Doubly circular linked.
Use head and tail pointers.
Newnode, next, data are other pointers .
Use any other pointers if required.
It should only have the following functions.

1.delete at rear
2.delete at position*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
int data;
struct Node *next;
struct Node *prev;
};

struct Node *head, *tail;

struct Node *create_node(int data) {
struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
newnode->data = data;
newnode->next = NULL;
newnode->prev = NULL;
return newnode;
}

void insert_at_rear(int data) {
struct Node *newnode = create_node(data);
if (head == NULL) {
head = newnode;
tail = newnode;
newnode->next = head;
newnode->prev = tail;
} else {
tail->next = newnode;
newnode->prev = tail;
tail = newnode;
tail->next = head;
head->prev = tail;
}
}

void delete_at_rear() {
if (head == NULL) {
printf("List is empty\n");
return;
}
struct Node *temp = tail;
tail = tail->prev;
tail->next = head;
head->prev = tail;
free(temp);
printf("Node deleted from rear\n");
}

void delete_at_position(int pos) {
if (head == NULL) {
printf("List is empty\n");
return;
}
struct Node *temp = head;
for (int i = 1; i < pos - 1; i++) {
temp = temp->next;
}
struct Node *temp2 = temp->next;
temp->next = temp2->next;
temp2->next->prev = temp;
free(temp2);
printf("Node deleted at position %d\n", pos);
}

void display() {
struct Node *temp = head;
printf("Doubly Circular Linked List: ");
do {
printf("%d ", temp->data);
temp = temp->next;
} while (temp != head);
printf("\n");
}

int main() {
insert_at_rear(1);
insert_at_rear(2);
insert_at_rear(3);
insert_at_rear(4);
insert_at_rear(5);
display();
delete_at_rear();
display();
delete_at_position(2);
display();
return 0;
}