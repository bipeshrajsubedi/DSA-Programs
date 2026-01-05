#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

Node* front = NULL;
Node* rear = NULL;

void display(){
    if(front == NULL){
        printf("Nothing to display. \n");
        return;
    }
    Node* current  = front;
    while(current != NULL){
        printf("%d ",current->data);
        current = current->next;
    }
    printf("\n");
}

void enqueue(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    printf("Enqueue: %d \n",value);
    if(front == NULL && rear == NULL){
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

void dequeue(){
    if(front == NULL){
        printf("Queue empty \n");
        return;
    }
    Node* temp = front;
    printf("Dequeue: %d \n",temp->data);
    front = front->next;
    if(front == NULL){
        rear = NULL;
    }
    free(temp);
}

void peek(){
    if(front == NULL) return;
    printf("Front: %d \n",front->data);
}

int main(){
    display();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    peek();
    return 0;
}