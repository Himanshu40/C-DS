/*
 * PROGRAM   : To create and display sorted single linked list that contains strings
 * FILE      : stringSort.c
 * CREATED BY: Himanshu Sekhar Nayak
 * DATED     : /02/2020
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    char        word[10];
    struct Node *next;
}Node;

void createSortedList(Node **head, char *newWord)
{
    Node *curr    = (*head);
    Node *newNode = (Node *)malloc(sizeof(Node));

    strcpy(newNode->word, newWord);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    if (strcasecmp(newNode->word, curr->word) < 0) {
        newNode->next = curr;
        *head = newNode;
        return;
    }

    while ((curr->next != NULL) && (strcasecmp(newNode->word, curr->next->word) > 0))
        curr = curr->next;

    newNode->next = curr->next;
    curr->next    = newNode; 
}

void display(Node *head)
{
    printf("+++++++++++++++++++++++++++\n");
    printf("+List of ascending strings+\n");
    printf("+++++++++++++++++++++++++++\n");

    while (head) {
        printf("%s ", head->word);
        head = head->next;
    }

    printf("\n");
}

int main()
{
    Node *first  = NULL;
    char  choice = 'Y';
    char  word[10];

    printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("+To create and display sorted single linked list+\n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");

    while (choice == 'Y' || choice == 'y') {
        printf("Enter the string: ");
        scanf("%s", word);
        fgetc(stdin);
        createSortedList(&first, word);
        printf("Do you want to add more strings(Y/N)?\n");
        scanf("%c", &choice);
        fgetc(stdin);
        printf("\n");
    }

    display(first);
}
