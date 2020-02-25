/*
 * PROGRAM   : To display prime numbers present in a single linked list
 * FILE      : prime.c
 * CREATED BY: Himanshu Sekhar Nayak
 * DATED     : 
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int          data;
    struct node *next;
}node;


void create_node(node **head, int new_data)
{
    node *new_node = (node *)malloc(sizeof(node));
    node *last     = *head;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}


void display_node(node *n)
{
    printf("++++++++++++++++++\n");
    printf("+List of elements+\n");
    printf("++++++++++++++++++\n");

    while (n != NULL) {
        printf(" %d ", n->data);
        n = n->next;
    }

    printf("\n");
}


void prime(node *head)
{
    int i, found = 0, count = 0;

    while (head != NULL) {
        if (head->data == 1) {
            head = head->next;
            continue;
        }

        for (i = 2; i <= ((head->data)/2); ++i)
            if (head->data % i == 0) {
                found = 1;
                break;
            }
        
        if (!found) {
            printf("%d ", head->data);
            ++count;
        }

        head  = head->next;
        found = 0;
    }

    if (!count)
        printf("\nNo prime numbers is present in a single linked list");
}


int main()
{
    node *first = NULL;
    char choice = 'Y';
    int  data;
    
    printf("++++++++++++++++++++++++++++++++++++++++++\n");
    printf("+To create and display single linked list+\n");
    printf("++++++++++++++++++++++++++++++++++++++++++\n");

    while (choice == 'Y' || choice == 'y') {
        printf("Enter the element: ");
        scanf("%d", &data);
        create_node(&first, data);
        printf("Do you want to add more elements(Y/N)?\n");
        fgetc(stdin);
        scanf("%c", &choice);
        printf("\n");
    }

    display_node(first);

    printf("++++++++++++++++++++++++++++++++++++++++++\n");
    printf("+ Prime Numbers in a single linked list  +\n");
    printf("++++++++++++++++++++++++++++++++++++++++++\n");

    prime(first);
    printf("\n");

    return 0;
}
