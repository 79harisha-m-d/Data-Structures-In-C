#include <stdio.h>
#include <stdlib.h> // Include the necessary library for the exit function

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert(int item, int priority) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1 && rear == -1) {
        front++;
        rear++;
        queue[rear] = item;
        return;
    }
    else {
        int i, j;
        for (i = front; i <= rear; i++) {
            if (priority > queue[i]) {
                for (j = rear + 1; j > i; j--) {
                    queue[j] = queue[j - 1];
                }
                queue[i] = item;
                rear++;
                return;
            }
        }
        queue[++rear] = item;
    }
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return 0;
    }
    else {
        int item = queue[front++];
        printf("The deleted element is %d\n", item);
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Empty\n");
        return;
    }
    else {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int ch;
    while (1) {
        printf("1: insert\n2: delete\n3: display\n4: exit\n");
        printf("enter the choice\n");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("enter the data and the priority\n");
            int item, priority;
            scanf("%d%d", &item, &priority);
            insert(item, priority);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    }
}
