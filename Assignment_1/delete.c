/*
 * PROGRAM   : To create and delete single linked list
 * FILE      : delete.c
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

int nodeSize = 0;

void create_node(node **head, int new_data)
{
    node *new_node = (node *)malloc(sizeof(node));
    node *last     = *head;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        ++nodeSize;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    ++nodeSize;
}


int delNodeStart(node **head)
{
    if ((*head) == NULL) {
        printf("No node is present in the list\n");
        return 1;
    }

    node *temp = (*head);

    (*head) = temp->next;
    free(temp);
    --nodeSize;

    return 0;
}


int delNodePosn(node **head, int sposn)
{
    if ((*head) == NULL) {
        printf("No node is present in the linked list\n");
        return 1;
    }

    if ((sposn < 0) || (sposn > (nodeSize + 1))) {
        printf("Given position is out of bound\n");
        return 1;
    }

    node *curr = (*head);
    node *last;

    while((sposn - 1) != 0) {
        last = curr;
        curr = curr->next;
        --sposn;
    }

    last->next = curr->next;
    free(curr);

    return 0;
}


int delNodeLast(node **head)
{
    if ((*head) == NULL) {
        printf("No node is present in the list\n");
        return 1;
    }

    node *temp = (*head);
    node *last;

    while(temp->next != NULL) {
        last = temp;
        temp = temp->next;
    }

    last->next = NULL;
    free(temp);
    --nodeSize;

    return 0;
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
    int  option;
    int  check;
    int  posn;
    
    printf("++++++++++++++++++++++++++++++++++++++++++\n");
    printf("+To create and display single linked list+\n");
    printf("++++++++++++++++++++++++++++++++++++++++++\n");

    while (choice == 'Y' || choice == 'y') {
        printf("\nEnter the element: ");
        scanf("%d", &data);
        create_node(&first, data);
        printf("Do you want to add more elements(Y/N)?\n");
        fgetc(stdin);
        scanf("%c", &choice);
    }

    display_node(first);

    START:
    printf("\n");
    printf("--------------MENU--------------\n");
    printf("-1. Delete node at Start       -\n");
    printf("-2. Delete node at Last        -\n");
    printf("-3. Delete node at any position-\n");
    printf("--------------------------------\n");

    printf("\nEnter the choice: ");
    scanf("%d", &option);

    switch(option)
    {
        case 1:  check = delNodeStart(&first);
                 if (check) {
                     printf("Retry(Y/N)?\n");
                     fgetc(stdin);
                     scanf("%c", choice);
                     if (choice == 'Y' || choice == 'y')
                         goto START;
                     else
                         goto END;              
                 }
                 else
                    display_node(first);
                 break;

        case 2:  check = delNodeLast(&first);
                 if (check) {
                     printf("Retry(Y/N)?\n");
                     fgetc(stdin);
                     scanf("%c", choice);
                     if (choice == 'Y' || choice == 'y')
                         goto START;
                     else
                         goto END;                     
                 }
                 else
                    display_node(first);
                 break;

        case 3:  printf("Enter the position: ");
                 scanf("%d", &posn);
                 check = delNodePosn(&first, posn);
                 if (check) {
                     printf("Retry(Y/N)?\n");
                     fgetc(stdin);
                     scanf("%c", choice);
                     if (choice == 'Y' || choice == 'y')
                         goto START;
                     else
                         goto END;                    
                 }
                 else
                    display_node(first);
                 break;
        default: printf("Invalid Choice\n");
                 printf("Retry(Y/N): ");
                 fgetc(stdin);
                 scanf("%c", &choice);
                 if (choice == 'Y' || choice == 'y')
                     goto START;
                 else
                     goto END;
    }

    END:
    printf("Do you want to continue any other operation(Y/N)?\n");
    fgetc(stdin);
    scanf("%c", &choice);
    if (choice == 'Y' || choice == 'y')
        goto START;    
    else
        printf("Operation terminated successfully\n");

    return 0;
}