#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node
{
    int data;
    struct _node *next;
}node;

node *head, *tail;

void init_list(void)
{
    head = (node*)malloc(sizeof(node));
    tail = (node*)malloc(sizeof(node));
    head->next = tail;
    tail->next = tail;
}

node *ordered_insert(int k) 
{
    node *temp = head -> next;
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = k;
    
    while (1)
    {
        if (temp->data < k && temp->next->data >= k)
        {
            newNode->next = temp->next;
            temp->next = newNode;        
            break;
        }

        temp = temp -> next;
    }
}

node *print_list(node* t) 
{
    node *temp = head -> next;

    while (1)
    {
        if (temp == tail)
        {    
            break;
        }
        print("%d ", temp->data);

        temp = temp -> next;
    }
}

void delete_node(int k)
{
    node *pre = head;
    while (1)
    {
        if (pre->next->data == k)
        {
            node *temp = pre->next;
            pre->next = temp->next;
            free(temp);
            break;
        }

        pre = pre -> next;
    }
}

void main()
{
    node *t;

    init_list();
    ordered_insert(10);
    ordered_insert(5);
    ordered_insert(8);
    ordered_insert(3);
    ordered_insert(1);
    ordered_insert(7);

    printf("\nInitial Linked list is ");
    print_list(head->next);

    delete_node(8);
    print_list(head->next);

    return 0;
}