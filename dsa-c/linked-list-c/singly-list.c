#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

Node* head = NULL;

// display
void displayList(){
    if(head == NULL){
        printf("List empty \n");
        return;
    }
    Node* current = head;
    printf("[ ");
    while(current != NULL){
        printf("%d ",current->data);
        current = current->next;
    }
    printf(" ]\n");
}

// insertion
void insertBegin(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertEnd(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
        return;
    }
    Node* current = head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newNode;
}

void insertAfterNode(Node* p,int value){
    if(p == NULL) return;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = p->next;
    p->next = newNode;
}

void deleteBegin(){
    if(head == NULL) return;
    Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteEnd(){
    if(head == NULL) return;
    if(head->next == NULL){
        free(head);
        head = NULL;
        return;
    }
    Node* current = head;
    while(current->next->next != NULL){
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

void deleteNodeByValue(int value){
    if(head == NULL) return;
    if(head->data == value){
        deleteBegin();
        return;
    }
    
    Node* current = head;
    while(current->next != NULL && current->next->data != value){
        current = current->next;
    }
    if(current->next == NULL){
        printf("No data \n");
        return;
    }
    Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
}

 int main(){
    displayList();
    insertBegin(10);
    insertBegin(20);
    displayList();
    insertEnd(30);
    insertEnd(40);
    displayList();
    deleteBegin();
    deleteEnd();
    displayList();
    insertAfterNode(head,15);
    displayList();
    deleteNodeByValue(10);
    displayList();
    return 0;
}
