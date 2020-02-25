/*
 * PROGRAM   : To store and display digits of a number in a single linked list
 * FILE      : digits.c
 * CREATED BY: Himanshu Sekhar Nayak
 * DATED     : 
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


typedef struct node
{
    int          data;
    struct node *next;
}node;


void createNode(node **head, int new_data)
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
    printf("+ List of digits +\n");
    printf("++++++++++++++++++\n");

    while (n != NULL) {
        printf(" %d ", n->data);
        n = n->next;
    }

    printf("\n");
}


int digits(int *num, int size)
{
    int digit;

    digit  = (*num) / (int)pow(10, (size - 1));
    (*num) = (*num) % (int)pow(10, (size - 1));

    return digit;
}


int main()
{
    node *first = NULL;
    int num, temp, newData, count = 0;

    printf("---------------------------------------------\n");
    printf("-STORE THE DIGITS OF A NUMBER IN LINKED LIST-\n");
    printf("---------------------------------------------\n");
    printf("\nEnter the number: ");
    scanf("%d", &num);

    printf("\nThe number is %d\n", num);

    temp = num;

    while (temp) {
        temp /= 10;
        ++count;
    }

    temp = num;

    while (count) {
        newData = digits(&temp, count);
        createNode(&first, newData);
        --count;
    }

    display_node(first);

    return 0;
}
