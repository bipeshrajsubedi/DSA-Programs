#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

Node* top = NULL;

void display(){
    if(top == NULL){
        printf("Nothing to display \n");
        return;
    }
    Node* current = top;
    while(current != NULL){
        printf("%d\n",current->data);
        current = current->next;
    }
}

void push(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("Push: %d \n",value);
}

void pop(){
    if(top == NULL){
        printf("List empty \n");
        return;
    }
    Node* temp = top;
    printf("Pop: %d \n",temp->data);
    top = top->next;
    free(temp);
}

void peek(){
    if(top == NULL) return;
    int val = top->data;
    printf("Peek: %d\n",val);
}

int main(){
    display();
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    peek();
    return 0;
}