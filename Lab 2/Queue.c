// write a program to simulate the working of the queue of integers using an array. Provide the following operations: Insert, delete, display. The program should print appropriate message for overflow and underflow condition.

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue();
void dequeue();
void display();

int main() {
    int choice;
    while(1) {
        printf("\nEnter 1: to enqueue \nEnter 2: to dequeue \nEnter 3: to diaplay \nEnter 4: to exit\n");
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

void enqueue() {
    int num;
    if(rear == SIZE-1) {
        printf("overflow");
    } else {
        if(front == -1) {
            front = 0;
        }
        printf("Enter the number:");
        scanf("%d", &num);
        rear++;
        queue[rear] = num;
        printf("insertion successful");
    }
}

void dequeue() {
    if(front == -1 || front > rear) {
        printf("underflow \n");
    } else {
        printf("dequeued element is: %d \n", queue[front]);
        front++;
        if(front > rear) {
            front = -1;
            rear = -1;
        }
    }
}

void display() {
    if(front == -1 || front > rear) {
        printf("queue is empty");
    } else {
        for(int i= front; i <= rear; i++) {
            printf("Element of queue: %d ", queue[i]);
        }
    }
}



