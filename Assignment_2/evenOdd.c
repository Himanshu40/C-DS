/*
 * PROGRAM   : To store the even & odd nos. in 2nd and 3rd single linked list respectively
 * FILE      : evenOdd.c
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
        printf("%d ", n->data);
        n = n->next;
    }

    printf("\n");
}


void createEven(node **head, node **top)
{
    node *tail = (*head);

    while (tail != NULL) {
        if (tail->data % 2 == 0) {
            node *newNode = (node *)malloc(sizeof(node));
            newNode->data = tail->data;
            newNode->next = NULL;

            if (*top == NULL) {
                *top = newNode;
                tail = tail->next;
                continue;
            }

            node *last = (*top);

            while (last->next != NULL)
                last = last->next;

            last->next = newNode;
        }
        tail = tail->next;
    }
}


void createOdd(node **head, node **top)
{
    node *tail = (*head);

    while (tail != NULL) {
        if (tail->data % 2 != 0) {
            node *newNode = (node *)malloc(sizeof(node));
            newNode->data = tail->data;
            newNode->next = NULL;

            if (*top == NULL) {
                *top = newNode;
                tail = tail->next;
                continue;
            }

            node *last = (*top);

            while (last->next != NULL)
                last = last->next;

            last->next = newNode;
        }
        tail = tail->next;
    }
}


int main()
{
    node *first  = NULL;
    node *second = NULL;
    node *third  = NULL;
    char choice  = 'Y';
    int  data;
    
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("+To store even and odd nos. in 2nd & 3rd single linked list+\n");
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

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

    createEven(&first, &second);
    createOdd(&first, &third);

    printf("\nEven Numbers in 2nd single linked list:-\n");
    display_node(second);

    printf("\nOdd Numbers in 3nd single linked list:-\n");
    display_node(third);

    return 0;
}
