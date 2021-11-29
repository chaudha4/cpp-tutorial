#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// rm ./a.out; gcc 006-linked-list.c; ./a.out

// forward declaration
typedef struct node_struct node;


typedef struct node_struct
{
    int data;
    node* next;
} node;

node* root = NULL;
node* last = NULL;

node* add(int ii) {
    node* n = (node*) malloc(sizeof(node));
    n->data = ii;
    n->next = NULL;    

    if (root == NULL)
    {
        last = n;
        root = n;
    } else {
        last->next = n;
        last = n;
    }
    return n;
}

void pnode() {
    printf("\n");
    if (root == NULL) {
        printf("Empty Linked List\n");
        return;
    }

    node* n = root;
    while (n)
    {
        printf("%i\t", n->data);
        n = n->next;
    }
    printf("\n");
}

// driver
void main() {
    printf("Started\n");
    add(10);
    add(12);
    add(9);
    pnode();

}