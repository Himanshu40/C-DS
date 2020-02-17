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

    while(n != NULL)
    {
        printf(" %d ", n->data);
        n = n->next;
    }

    printf("\n");
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

    return 0;
}