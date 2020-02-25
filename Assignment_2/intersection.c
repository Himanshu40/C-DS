/*
 * PROGRAM   : To find intersection of two single linked list
 * FILE      : intersection.c
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


int search(node *thirdHead, int newData)
{
    int found = 0;

    if (thirdHead == NULL)
        return 0;

    while (thirdHead != NULL) {
        if (thirdHead->data == newData) {
            found = 1;
            break;
        }
        thirdHead = thirdHead->next;
    }
    
    return found;
}


void intersection(node **first, node **second, node **third)
{
    node *firstLast  = (*first);
    node *secondLast = (*second);

    while (firstLast != NULL) {
        while (secondLast != NULL) {
            if ((firstLast->data) == (secondLast->data)) {
                if (!search(*third, secondLast->data)) { 
                    node *newNode = (node *)malloc(sizeof(node));

                    newNode->data = secondLast->data;
                    newNode->next = NULL;

                    if (*third == NULL) {
                        *third = newNode;
                        secondLast = secondLast->next;
                        continue;
                    }

                    node *thirdLast = (*third);

                    while (thirdLast->next != NULL)
                        thirdLast = thirdLast->next;

                    thirdLast->next = newNode;
                }
            }
            secondLast = secondLast->next;
        }
        secondLast = (*second);
        firstLast = firstLast->next;
    }
}


int main()
{
    node *first  = NULL;
    node *second = NULL;
    node *third  = NULL;
    char choice = 'Y';
    int  data;

    printf("++++++++++++++++++++++++++++++++++++++++++\n");
    printf("+   To create first single linked list   +\n");
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
    choice = 'Y';

    printf("++++++++++++++++++++++++++++++++++++++++++\n");
    printf("+   To create second single linked list  +\n");
    printf("++++++++++++++++++++++++++++++++++++++++++\n");

    while (choice == 'Y' || choice == 'y') {
        printf("Enter the element: ");
        scanf("%d", &data);
        create_node(&second, data);
        printf("Do you want to add more elements(Y/N)?\n");
        fgetc(stdin);
        scanf("%c", &choice);
        printf("\n");
    }

    display_node(second);

    intersection(&first, &second, &third);

    if (third == NULL) {
        printf("Intersection didn't take place between two single linked list\n");
        return 0;
    }

    printf("++++++++++++++++++++++++++++++++++++++++++\n");
    printf("+ Intersection of two single linked list +\n");
    printf("++++++++++++++++++++++++++++++++++++++++++\n");

    display_node(third);

    return 0;
}
