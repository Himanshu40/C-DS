/*
 * PROGRAM   : To update a specific key element in a  single linked list
 * FILE      : update.c
 * CREATED BY: Himanshu Sekhar Nayak
 * DATED     : /02/2020
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
    node *last     = (*head);

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


int update(node *head, int oldData, int newData)
{
    int found = 0;

    while (head != NULL) {
        if (head->data == oldData) {
            head->data = newData;
            found = 1;
        }
        head = head->next;
    }

    return found;
}


int main()
{
    node *first = NULL;
    char choice = 'Y';
    int  data;
    int  oldData;
    int  newData;
    
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

    START:
    printf("\nWhich element you want to update?\n");
    scanf("%d", &oldData);
    printf("\nEnter the new number: ");
    scanf("%d", &newData);

    if (update(first, oldData, newData)) {
        printf("\n---New element in linked list---\n");
        display_node(first);
    }
    else {
        printf("\nSearched element didn't exist in linked list");
        printf("\nRetry?(Y/N): ");
        fgetc(stdin);
        scanf("%c", &choice);
        if (choice == 'Y' || choice == 'y')
            goto START;
    }

    return 0;
}
