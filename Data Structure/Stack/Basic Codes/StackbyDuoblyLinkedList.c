/*
We will implement stack using DOUBLY LinkedList.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
struct node{
    int data;
    node* next;
    node* previous;
};

//top is basically linkedlist's tail. 
node* top = NULL;
node* head = NULL;

//count variable helps to calculate element number without using extra loop.
int count = 0;

void push(int value) {
    if(head == NULL) {
        head = (node*) malloc (sizeof(node)); 
        head->data = value;
        head->next = NULL;
        head->previous = NULL;
        top = head;
        count++;
    }else {
        node* new = (node*) malloc (sizeof(node));
        new->data = value;
        new->next = NULL;
        new->previous = top;
        top->next = new;
        top = new; 
        count++;
    }
    printf("%d has been pushed.\n", value);
}

void pop() {
    if(head==NULL){
        printf("\nUnderflow.\n");
        return;
    }
    node* temp = top;
    top = top->previous;
    top->next = NULL;
    printf("\n%d has been popped.\n", temp->data);
    free(temp);
    count--;
}

void display() {
    if(head == NULL) {
        printf("\nStack is empty!\n");
        return;
    }
    node* temp = head;
    printf("\nStackList: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void peek() {
    if(head == NULL) {
        printf("\nStack is empty!\n");
        return;
    }
    printf("\nPeek number is: %d.\n", top->data);
}

void stackSize() {
    if(head == NULL) {
        printf("\nStack is empty!\n");
        return;
    }
    printf("\nTotal element on stack: %d\n.", count);
}

int main() {

    int choice, data;

    while(1) {
        printf("\n");
        printf("     <= MENU =>\n\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Data Count\n");
        printf("0. Exit\n");
        printf("\nEnter a choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:  
                printf("\nEnter a value to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2: 
                pop();
                break;
            case 3:
                peek();
                break;
            case 4: 
                display();
                break;    
            case 5:
                stackSize();
                break;   
            default: 
                printf("\nIncorrect Input. Try again.\n");    
            break;
            case 0: 
                exit(0);    
        }
    }

    return 0;
}
