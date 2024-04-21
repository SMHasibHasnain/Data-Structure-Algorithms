#include <stdio.h>

int top = -1;
int size = 10;
int array[10];

void push(int value) {
    if(top + 1 < size)  {
        top++;
        array[top] = value;
        printf("%d has been pushed.\n", value);
    } else {
        printf("Overflow!");
    }
}

void pop() {
    if(top >= 0)  {
        printf("%d has been deleted.\n",  array[top]);
        top--;
    } else {
        printf("Underflow");
    }
}

void display() {
    printf("The stack is: ");
    for(int i=0; i<=top; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void peek() {
    printf("The peek value is: %d", array[top]);
}

void stackSize() {
    printf("Item number of this stack is: %d\n", top+1);
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
                printf("Enter a value: ");
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
                printf("Incorrect Input. Try again.\n");    
            case 0: 
                exit(0);    
        }
    }
    
    return 0;
}
