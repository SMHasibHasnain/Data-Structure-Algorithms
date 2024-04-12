#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
struct node{
    int data;
    node *next;
};

void create_node(node *ptr){
    printf("Enter node value: ");
    scanf("%d", &ptr->data);
    printf("Write 1 to add more node, 0 to stop: ");
    int choice;
    scanf("%d", &choice);
    if (choice == 0) {
        ptr->next = NULL;
        return;
    } 
    else {
        ptr->next = (node*) malloc (sizeof(node));
        create_node(ptr->next);
    }
}

void print_node(node *ptr) {
    printf("%d  ", ptr->data);
    if (ptr->next == NULL) {
        return;
    } 
    else {
        print_node(ptr->next);
    }
}

int count_node(node *ptr) {
    if(ptr == NULL) {
        return 0;
    }
    else {
        return (1 + count_node(ptr->next));
    }
}

int main() {
    node *head = (node*) malloc (sizeof(node));
    create_node(head);
    printf("\n");
    print_node(head);
    printf("\n");
    printf("Total node: %d\n", count_node(head));
    return 0;
}  