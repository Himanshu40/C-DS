/*
 * PROGRAM   : To create and display matrix in a single linked list
 * FILE      : matrix.c
 * CREATED BY: Himanshu Sekhar Nayak
 * DATED     : /02/2020
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int          data;
    int          row;
    int          column;
    struct node *next;
}node;

int  rowSize    = 0;
int  columnSize = 0;

void create_node(node **head, int newRow, int newColumn, int new_data)
{
    node *new_node = (node *)malloc(sizeof(node));
    node *last     = (*head);

    new_node->data = new_data;
    new_node->row = newRow;
    new_node->column = newColumn;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}


void display_node(node *n, int RowSize, int ColumnSize)
{
    int i, j;

    printf("+++++++++++++++++++++++++++++\n");
    printf("+List of elements in a mtrix+\n");
    printf("+++++++++++++++++++++++++++++\n");

    for (i = 0; i < RowSize; ++i) {
        for ( j = 0; j < ColumnSize; ++j) {
            printf("%d ", n->data);
            n = n->next;
        }
        printf("\n");
    }

    printf("\n");
}


int main()
{
    node *first = NULL;
    char choice = 'Y';
    int  data;
    int  i, j;
    
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("+To create and display matrix in a single linked list+\n");
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

    printf("\nEnter number of rows: ");
    scanf("%d", &rowSize);
    printf("\nEnter number of columns: ");
    scanf("%d", &columnSize);

    printf("\nEnter the elements in the matrix: ");
    for (i = 0; i < rowSize; ++i)
        for (j = 0; j < columnSize; ++j) {
            scanf("%d", &data);
            create_node(&first, i, j, data);
        }

    display_node(first, rowSize, columnSize);

    return 0;
}
