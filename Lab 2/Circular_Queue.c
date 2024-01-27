// write a program to simulate the working of a circular queue using an array. Provide the following operations: insert, delete& display. The program should print appropriate message for queue empty and queue overflow conditions.

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void dequeue();
void enqueue();
void display();
int isFull();
int isEmpty();

int main()
{
    int choice;
    while (1)
    {
        printf("\n Enter 1: to enqueue \n Enter 2: to dequeue \n Enter 3: to display \n Enter 4: to exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("invalid number \n");
            break;
        }
    }
}

int isFull()
{
    if ((front == rear + 1) || (front == 0 && rear == SIZE - 1))
    {
        return 1;
    }
    return 0;
}

int isEmpty()
{
    if (front == -1)
    {
        return 1;
    }
    return 0;
}

void enqueue()
{
    int num;
    if (isFull())
    {
        printf("overflow");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        printf("Enter the number: ");
        scanf("%d", &num);
        rear = (rear + 1) % SIZE;
        queue[rear] = num;
    }
}

void dequeue()
{
    if (isEmpty())
    {
        printf("underflow");
    }
    else
    {
        int num = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
        printf("dequeued element %d\n", num);
    }
}

void display()
{
    int i;
    if (isEmpty())
    {
        printf("queue is empty\n");
    }
    else
    {
        for (i = front; i != rear; i = (i + 1) % SIZE)
        {
            printf("Element of queue: %d \n", queue[i]);
        }
        printf("Element of queue: %d \n", queue[i]);
    }
}
