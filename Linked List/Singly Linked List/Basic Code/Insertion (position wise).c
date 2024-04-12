#include <stdio.h>
#include<stdlib.h>

typedef struct node node;
struct node {
    int data;
    node *next;
};

node *head = NULL;

void print() {
    node *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void insert_last(int value) {
    node *add = (node*) malloc (sizeof(node));
    add->data = value;
    add->next = NULL;
    if(head == NULL) {
        head = add;
    } else {
        node *temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = add;
    }
}

void insert_beg(int value) {
    node* add = (node*) malloc (sizeof(node));
    add->data = value;
    add->next = head;
    head = add;
}

void insert_mid_pos(int pos, int value) {
    node *add = (node*) malloc (sizeof(node));
    add->data = value;
    node *temp = head;
    node* ptemp = NULL;
    for(int i = 0; i < pos-1; i++) {
        if (temp == NULL) {
            printf("Position exceeds the length of the list!\n");
            exit(0);
        }    
        ptemp = temp;
        temp = temp->next;
    }
    if(ptemp==NULL) {
        printf("Something is Wrong!\n");
        exit(0);
    }
    add->next = temp;
    ptemp->next = add;
}

int main() {
    head = (node*) malloc (sizeof(node));
    head->data = 50;
    head->next = (node*) malloc (sizeof(node));
    head->next->data = 60;
    head->next->next = NULL;
    
    insert_last(70);
    insert_beg(40);
    insert_mid_pos(4, 99);
    print();
    
    return 0;
}
