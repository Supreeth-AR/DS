// Write a program to simulate the working of stack using an array with the following :
// a) Push b) Pop c) Display
// The program should print appropriate messages for stack overflow, stack underflow.

#include <stdio.h>
#define SIZE 5

void push(int);
void pop();
void display();
int stack[SIZE], top = -1;

void push(int value)
{
    if (top == SIZE - 1)
    {
        printf("\n Overflow/Stack is Full");
    }
    else
    {
        top = top + 1;
        stack[top] = value;
        printf("\n Insertion Successful!!");
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\n Stack is Empty/Underflow");
    }
    else
    {
        printf("\n The Deleted Element is %d", stack[top]);
        top = top - 1;
    }
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("\n Stack is Empty");
    }
    for (i = top; i > 0; i--)
    {
        printf("\n %d", stack[i]);
    }
}

int main()
{
    int value, choice;
    while (1)
    {
        printf("\n\n----------MENU----------");
        printf("\n 1.Push \n 2.Pop \n 3.Display \n 4.Exit \n");
        printf("\n Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n Enter a Value: ");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("\n Wrong Input ------ Try Again ------");
        }
    }
}
