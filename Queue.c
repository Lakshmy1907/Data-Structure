#include <stdio.h>
#include <stdlib.h>

#define MAX 3
int rear = -1;
int front = -1;

void enQueue(int q[], int item) {
    if (rear == MAX - 1) {
        printf("The queue is full\n");
        return;
    }
    rear++;
    q[rear] = item;
    if (front == -1) {
        front = 0;
    }
}

void deQueue(int q[]) {
    if (front == -1 || front > rear) {
        printf("The queue is empty\n");
        return;
    }
    printf("The element deleted is %d\n", q[front]);
    front++;
}

void display(int q[]) {
    printf("\n");
    if (rear == -1 || front > rear) {
        printf("queue is Empty\n");
    } else {
        printf("The queue is : ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", q[i]);
        }
        printf("\n");
    }
}

int main() {
    int queue[MAX], n;
    while (1) {
        printf("Enter the operation required\n");
        printf("=====================================\n");
        printf("1. enqueue\n2. dequeue\n3. Display\n4. exit\n");
        printf("=====================================\n");
        fflush(stdin);
        scanf("%d", &n);
        switch (n) {
            case 1: {
                printf("Enter the item to push : ");
                int item;
                scanf("%d", &item);
                enQueue(queue, item);
                display(queue);
                break;
            }
            case 2:
                deQueue(queue);
                display(queue);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                printf("\n=======Program terminated=======\n");
                exit(0);
            default:
                printf("Invalid selection\n");
        }
    }
    return 0;
}