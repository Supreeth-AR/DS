#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node *create_ll(struct node *head)
{
    struct node *new_node, *ptr;
    int num;
    printf("Enter -1 to Exit.. \n");
    printf("Enter the num: \n");
    scanf("%d", &num);

    while (num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        if (head == NULL)
        {
            head = new_node;
            new_node->next = NULL;
        }
        else
        {
            ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = NULL;
        }
        printf("Enter the num: \n");
        scanf("%d", &num);
    }
    return head;
}

struct node *insert_beg(struct node *head)
{
    struct node *new_node;
    int num;
    printf("Enter the num: \n");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    if (head == NULL)
    {
        head = new_node;
        new_node->next = NULL;
    }
    else
    {
        new_node->next = head;
        head = new_node;
    }
    return head;
}

struct node *insert_end(struct node *head)
{
    struct node *ptr, *new_node;
    int num;
    printf("Enter the num: \n");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
    return head;
}

struct node *insert_before(struct node *head)
{
    struct node *new_node, *ptr, *prevptr;
    int num, val;
    printf("Enter the num: \n");
    scanf("%d", &num);
    printf("Enter the value before which number has to be inserted: \n");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = head;
    while (ptr->next != NULL)
    {
        prevptr = ptr;
        ptr = ptr->next;
    }
    prevptr->next = new_node;
    new_node->next = ptr;
    return head;
}

struct node *insert_after(struct node *head)
{
    struct node *new_node, *ptr, *prevptr;
    int num, val;
    printf("Enter the num: \n");
    scanf("%d", &num);
    printf("Enter the value before which number has to be inserted: \n");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = head;
    while (ptr->next != NULL)
    {
        prevptr = ptr;
        ptr = ptr->next;
    }
    prevptr = ptr;
    ptr = ptr->next;
    prevptr->next = new_node;
    new_node->next = ptr;
    return head;
}

struct node *display(struct node *head)
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("Linked List is empty...\n");
    }
    else
    {
        ptr = head;
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
    return head;
}

struct node *delete_beg(struct node *head)
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("Nothing to delete.. \n");
    }
    else
    {
        ptr = head;
        head = ptr->next;
        free(ptr);
    }
    return head;
}

struct node *delete_end(struct node *head)
{
    struct node *ptr, *prevptr;
    ptr = head;
    while (ptr->next != NULL)
    {
        prevptr = ptr;
        ptr = ptr->next;
    }
    prevptr->next = NULL;
    free(ptr);
    return head;
}

struct node *delete_node(struct node *head)
{
    struct node *ptr, *prevptr;
    int val;
    printf("Enter the value that has to be deleted: \n");
    scanf("%d", &val);
    ptr = head;
    if (ptr->data == val)
    {
        head = delete_beg(head);
        return head;
    }
    else
    {
        while (ptr->data != val)
        {
            prevptr = ptr;
            ptr = ptr->next;
        }
        prevptr->next = ptr->next;
        free(ptr);
        return head;
    }
}

int main()
{
    int choice;
    printf("---------menu-------\n");
    printf("1.Create Linked list\n 2.Display\n 3.Insert_beg\n 4.Insert_end\n 5.Insert_before\n 6.Insert_after\n 7.Del_beg\n 8.Del_end\n 9.Del_node\n 10.Exit\n");
    do
    {
        printf("Enter the choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head = create_ll(head);
            printf("Linked List Created\n");
            break;
        case 2:
            head = display(head);
            break;
        case 3:
            head = insert_beg(head);
            break;
        case 4:
            head = insert_end(head);
            break;
        case 5:
            head = insert_before(head);
            break;
        case 6:
            head = insert_after(head);
            break;
        case 7:
            head = delete_beg(head);
            break;
        case 8:
            head = delete_end(head);
            break;
        case 9:
            head = delete_node(head);
            break;
        }
    } while (choice != 10);
}