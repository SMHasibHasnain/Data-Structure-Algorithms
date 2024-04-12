#include <stdio.h>
#include<stdlib.h>

typedef struct node node;
struct node {
    int data;
    node *next;
};

node *head = NULL, *temp = NULL;

void create(int value) {
    if(head==NULL) {
        head = (node*) malloc (sizeof(node));
        head->data = value;
        head->next = NULL;
        temp = head;
    } else {
        node* create_node = (node*) malloc (sizeof(node));
        create_node->data = value;
        create_node->next = NULL;
        temp->next = create_node;
        temp = create_node;
    }
}

void print() {
    node *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void delete_pos(int pos) {
    if(pos <= 1) {
        printf("\nSomething went wrong\n");
        exit(0);
    }
    node* temp = head;
    node* ptemp = NULL;
    for(int i=0; i<pos-1; i++) {
        if(temp == NULL) {
            printf("\nDeletion not possible. Pos exceeds limit.\n");
            exit(0);
        }
        ptemp = temp;
        temp = temp->next;
    }
    ptemp->next = temp->next;
    free(temp);
}

int main() {
    create(5);
    create(6);
    create(7);
    create(8);
    create(10);
    
    printf("The list is: ");
    print();
    
    delete_pos(3);
    printf("\n\nAfter deleting third data: ");
    print();
    
    return 0;
}
