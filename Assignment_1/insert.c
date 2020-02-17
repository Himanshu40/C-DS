#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int          data;
    struct node *next;
}node;

int node_size = 0;


int insertStart(node **head, int new_data)
{
    if (*head == NULL) {
        printf("No node is present in Linked List\n");
        return 1;
    }
    node *new_node = (node *)malloc(sizeof(node));

    new_node->data = new_data;
    new_node->next = (*head);

    (*head) = new_node;
    ++node_size;

    return 0;
}


int insertPosn(node **head, int nposn, int new_data)
{
    if (*head == NULL) {
        printf("No node is present in Linked List\n");
        return 1;
    }
    
    if ((nposn < 1) || (nposn > (node_size + 1))) {
        printf("Given position is out of bound from Linked List\n");
        return 1;
    }

    node *new_node = (node *)malloc(sizeof(node));
    node *curr     = (*head);

    while ((nposn - 1) != 1) {
        curr = curr->next;
        --nposn;
    }
    
    new_node->data = new_data;
    new_node->next = curr->next;
    curr->next     = new_node;    

    return 0;
}


void append(node **head, int new_data)
{
    node *new_node = (node *)malloc(sizeof(node));
    node *last     = (*head);

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        ++node_size;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    ++node_size;
}


void display_node(node *n)
{
    printf("\n");
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
    node *first  = NULL;
    char  choice = 'Y';
    int   data;
    int   menuChoice;
    int   posn;
    int   check;
    
    printf("++++++++++++++++++++++++++++++++++++++++++\n");
    printf("+To create and display single linked list+\n");
    printf("++++++++++++++++++++++++++++++++++++++++++\n");

    while (choice == 'Y') {
        printf("\nEnter the element: ");
        scanf("%d", &data);
        append(&first, data);
        printf("Do you want to add more elements(Y/N)?\n");
        fgetc(stdin);
        scanf("%c", &choice);
    }

    display_node(first);

    START:
    printf("\n");
    printf("-----------------MENU---------------\n");
    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("+1. Add a node at the start of node+\n");
    printf("+2. Add a node at specific position+\n");
    printf("+3. Add a node at the end of node  +\n");
    printf("++++++++++++++++++++++++++++++++++++\n");

    printf("Enter a choice: ");
    scanf("%d", &menuChoice);

    switch(menuChoice)
    {
        case 1:  printf("Enter the element: ");
                 scanf("%d", &data);
                 check = insertStart(&first, data);
                 if (check) {
                     printf("Retry?(Y/N)\n");
                     fgetc(stdin);
                     scanf("%c", &choice);
                     if (choice == 'Y')
                        goto START;
                     else
                        return 0;
                 }
                 else
                    display_node(first);
                 break;

        case 2:  printf("Enter the element: ");
                 scanf("%d", &data);
                 printf("Enter the position:");
                 scanf("%d", &posn);
                 check = insertPosn(&first, posn, data);
                 if (check) {
                     printf("Retry?(Y/N)\n");
                     fgetc(stdin);
                     scanf("%c", &choice);
                     if (choice == 'Y')
                        goto START;
                     else
                        return 0;
                 }
                 else
                    display_node(first);
                 break;

        case 3:  printf("Enter the element: ");
                 scanf("%d", &data);
                 append(&first, data);
                 display_node(first);
                 break;

        default: printf("Invalid Choice\n");
                 printf("Retry(Y/N): ");
                 fgetc(stdin);
                 scanf("%c", &choice);
                 if (choice == 'Y')
                    goto START;
                 else
                    return 0;
    }

    printf("Do you want to continue any other operation(Y/N)?\n");
    fgetc(stdin);
    scanf("%c", &choice);
    if (choice == 'Y')
        goto START;
    else
        printf("Operation terminated successfully\n");

    return 0;
}