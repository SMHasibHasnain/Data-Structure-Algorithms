#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
struct node {
    int data;
    node *next;
};

node *head = NULL, *thead = NULL;
int count;

void create();
void print();
void insertEnd();
void insertFront();
void insertPos();
void deleteLast();
void deleteFront();
void deletePos();
void countTotal();
void reverse();
void caution();
void exitGate();
void search();
void update();

int main() {
    int i;
    do {
        printf(" ________________MENU_______________\n");
        printf(":         [Choose any option]       :\n");
        printf("-------------------------------------\n\n");
        
        printf("1.   Create List\n");
        printf("2.   Print the Linked List\n");
        printf("3.   Insert new node at the end\n");
        printf("4.   Insert new node at the front\n");
        printf("5.   Insert new node at x'th postion\n");
        printf("6.   Delete the last node\n");
        printf("7.   Delete the front node\n");
        printf("8.   Delete node of x'th postion\n");
        printf("9.   Count total number of node\n");
        printf("10.  Reverse the linked list\n");
        printf("11.  Search an element\n");
        printf("12.  Update an element\n");
        printf("(0)  Exit\n\n");
        
        printf("=> Enter chosen option's number: ");
        scanf("%d", &i);
        printf("\n");
        
        switch(i) {
            case 0:
                exitGate();
            case 1: 
                create();
                break;
            case 2:
                printf("The link list is: \n");
                print();
                printf("\n");
                break;
            case 3:
                insertEnd();
                break;    
            case 4:
                insertFront();
                break;
            case 5:
                insertPos();
                break;
            case 6:
                deleteLast();
                break;
            case 7:
                deleteFront();
                break;
            case 8:
                deletePos();
                break;
            case 9:
                countTotal();
                printf("\nTotal node is: %d", count);
                printf("\n");
                break;
            case 10:
                reverse();
                break;
            case 11:
                search();
                break;
            case 12:
                update();
                break;    
            default:
                printf("Invalid input. Try again\n");    
        }
} while (i != 0);
}

void create() {
    int value;
    do {
        printf("Enter value (type '-1' to finish): ");
        scanf("%d", &value);
        if(value == -1) {
            printf("\nGood job! \nList has been created.\nUse other options to manupulatre this list.\n\n");
            return;
        }
        if(head == NULL) {
            head = (node*) malloc (sizeof(node));
            if(head == NULL) {
                printf("Memory allocation failed.\n\n");
                return;
            }
            head->data = value;
            head->next = NULL;
            thead = head;
        } else {
            node* newNode = (node*) malloc (sizeof(node));
            if(newNode == NULL) {
                printf("Memory allocation failed.\n");
                return;
            }
            newNode->data = value;
            newNode->next = NULL;
            thead->next = newNode;
            thead = newNode;
        }
    } while (1);
}

void print() {
    caution();
    node *ptr = head;
    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void insertEnd() {
    caution();
    node* insertNode = (node*) malloc (sizeof(node));
    if(insertNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
        }
    printf("Enter value: ");
    scanf("%d", &insertNode->data);
    insertNode->next = NULL;
    node* ptr = head;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = insertNode;
    printf("\nData has been inserted.\n\n");
}

void insertFront() {
    caution();
    node* insertNode = (node*) malloc (sizeof(node));
    if(insertNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
        }
    printf("Enter value: ");
    scanf("%d", &insertNode->data);
    insertNode->next = head;
    head = insertNode;
    printf("\nData has been inserted.\n\n");
}

void insertPos() {
    caution();
    int pos;
    printf("Enter inserting position: ");
    scanf("%d", &pos);
    countTotal();
    if(pos > count || pos < 1) {
        printf("The position number isn't correct.\n\n");
        return;
    }
    node* insertNode = (node*) malloc (sizeof(node));
    if(insertNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &insertNode->data);
    node *ptr = head;
    node *temp = NULL;
    for(int i = 0; i < pos - 1; i++) {
        temp = ptr;
        ptr = ptr->next;
    }
    temp->next = insertNode;
    insertNode->next = ptr;
    printf("\nData has been inserted.\n\n");
}

void deleteLast() {
    caution();
    node *ptr = head;
    node *temp = temp;
    while (ptr->next != NULL) {
        temp = ptr;
        ptr = ptr->next;
    }
    temp->next = NULL;
    free(ptr);
    printf("\nData has been deleted.\n\n");
}

void deleteFront() {
    caution();
    node *ptr = head;
    head = head->next;
    free(ptr);
    printf("\nData has been deleted.\n\n");
}


void deletePos() {
    caution();
    int pos;
    printf("Enter the position, you want to delete: ");
    scanf("%d", &pos);
    countTotal();
    if(pos > count || pos < 1) {
        printf("The position number isn't correct.\n\n");
        return;
    }
    node *ptr = head;
    node *temp = NULL;
    for(int i = 0; i < pos - 1; i++) {
        temp = ptr;
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    free(ptr);
    printf("\nData has been deleted.\n\n");
}


void countTotal() {
    caution();
    count = 0;
    node *ptr = head;
    while(ptr != NULL) {
        count++;
        ptr = ptr->next;
    }
}

void reverse() {
    caution();
    node *prev = NULL;
    node *current = head;
    node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    printf("Data has been reversed!\n\n");   
}

void exitGate() {
    printf("Good Luck :)\n\n");
    exit(0);
}

void caution() {
    if(head == NULL) {
        printf("Please create the list first!\n\n");
        create();
    }
}

void search() {
    caution();
    int value;
    int pos = 0;
    printf("Search a value: ");
    scanf("%d", &value);
    node* ptr = head;
    while (ptr != NULL) {
        pos++;
        if(ptr->data == value) {
            printf("Element Found!\n");
            printf("Number of node position of %d is %d\n\n", value, pos);
            return;
        } else {
            ptr = ptr->next;
        }
    }
    printf("%d isn't found on the list.\n\n", value);
}

void update() {
    caution();
    int pos;
    printf("Update value positioned at: ");
    scanf("%d", &pos);
    int value;
    printf("Updated value: ");
    scanf("%d", &value);
    node *ptr = head;
    int i = 0;
    while(i < pos - 1) {
        ptr = ptr->next;
        i++;
    }    
    ptr->data = value;
    printf("Value has been updated!\n\n");
}
