#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
  struct node *prev;
};

struct node *head = NULL, *tail = NULL,*temp;
struct node *temp2;

int create() {
  int data;
  struct node *newnode = (struct node*)malloc(sizeof(struct node));
  newnode->data = data;
  newnode->next = NULL;
  newnode->prev = NULL;
  return newnode;
}

void insert_at_front() {
  struct node *newnode;
  newnode = (struct node*)malloc(sizeof(struct node));
  printf("Enter data\n");
  scanf("%d",&newnode->data);
  if (head == NULL) {
    head = tail = newnode;
    head->next = tail->next = NULL;
    head->prev = tail->prev = NULL;
  } else {
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
    head->prev = tail;
    tail->next = head;
  }
}

void insert_at_rear() {
 struct node *newnode;
  newnode = (struct node*)malloc(sizeof(struct node));
  printf("Enter data\n");
  scanf("%d",&newnode->data);
  if (head == NULL) {
    head = tail = newnode;
    head->next = tail->next = NULL;
    head->prev = tail->prev = NULL;
  } else {
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
    tail->next = head;
    head->prev = tail;
  }
}

void insert_at_position() {
  int i,pos;
  printf("Enter the position\n");
  scanf("%d",&pos);
  struct node *newnode;
  newnode = (struct node*)malloc(sizeof(struct node));
  printf("Enter data\n");
  scanf("%d",&newnode->data);
  struct node *temp = head;
  if (pos == 1) {
    insert_at_front();
    return;
  }
  for (i = 0; i < pos - 2; i++) {
    temp = temp->next;
  }
  if (temp == tail) {
    insert_at_rear();
    return;
  }
  newnode->next = temp->next;
  temp->next->prev = newnode;
  temp->next = newnode;
  newnode->prev = temp;
}

void display() {
  struct node *temp = head;
  printf("The list is: ");
  while (temp->next != head) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("%d\n", temp->data);
}

void delete_at_front() {
  if (head == NULL) {
    printf("The list is empty\n");
    return;
  }
  if (head == tail) {
    free(head);
    head = tail = NULL;
    return;
  }
  head = head->next;
  free(head->prev);
  head->prev = tail;
  tail->next = head;
}

void delete_at_rear() {
  if (head == NULL) {
    printf("The list is empty\n");
    return;
}
struct Node *temp = tail;
tail = tail->prev;
tail->next = head;
head->prev = tail;
free(temp);
printf("Node deleted from rear\n");
}

void delete_at_position() {
  int pos;
  printf("Enter the position\n");
  scanf("%d",&pos);
if (head == NULL) {
printf("List is empty\n");
return;
}
temp = head;
for (int i = 1; i < pos - 1; i++) {
temp = temp->next;
}
temp2 = temp->next;
temp->next = temp2->next;
temp2->next->prev = temp;
free(temp2);
printf("Node deleted at position %d\n", pos);
}

int main(){
  int ch;
  for(;;)
  {
    printf("\n 1:Create 2:Insertfront 3:Insertrear 4:Insertmid\n");
    printf("\n 5:Display 6:Deletefront 7:Deleterear 8:Deletemid 9:Exit\n");
    printf("Enter the choice:\n");
    scanf("%d",&ch);

    switch(ch)
    {
      case 1:create();
      break;
      case 2:insert_at_front();
      break;
      case 3:insert_at_rear();
      break;
      case 4:insert_at_position();
      break;
      case 5:display();
      break;
      case 6:delete_at_front();
      break;
      case 7:delete_at_rear();
      break;
      case 8:delete_at_position();
      break;
      case 9:exit(0);
      
    }
  }
}