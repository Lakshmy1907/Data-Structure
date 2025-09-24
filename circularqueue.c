#include <stdio.h>
#define MAX 100
int queue[MAX];
int front = -1, rear = -1;
int max_size;
void enqueue(int value) {
if ((rear + 1) % max_size == front) {
printf("Queue is Full!\n");
} 
else if (front == -1) {
front = rear = 0;
queue[rear] = value;
printf("Enqueued: %d\n", value);
} 
else {
rear = (rear + 1) % max_size;
queue[rear] = value;
printf("Enqueued: %d\n", value);
}
}
void dequeue() {
if (front == -1) {
printf("Queue is Empty!\n");
} 
else {
int value = queue[front];
printf("Dequeued: %d\n", value);
if (front == rear) {
// Queue becomes empty
front = rear = -1;
} 
else {
front = (front + 1) % max_size;
}
}
}
void display() {
if (front == -1) {
printf("Queue is empty!\n");
return;
}
printf("Queue elements: ");
int i = front;
while (1) {
printf("%d ", queue[i]);
if (i == rear)
break;
i = (i + 1) % max_size;
}
printf("\n");
}
int main() {
int value;
int choice;
printf("Enter the maximum size of the Queue (1-100): ");
scanf("%d", &max_size);
if (max_size < 1 || max_size > MAX) {
printf("Invalid size! Must be between 1 and 100.\n");
return 0;
}
while (1) {
printf("\n\tQueue Menu\n");
printf("1. Enqueue\n2. Dequeue\n3. Display\n4. 
Exit\n");
printf("Enter your choice (1-4): ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter value to enqueue: ");
scanf("%d", &value);
enqueue(value);
display();
break;
case 2:
dequeue();
display();
break;
case 3:
display();
break;
case 4:
printf("Exiting program.\n");
return 0;
default:
printf("Invalid choice!\n");
}
}
return 0;
}
