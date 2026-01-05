#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}Node;

Node* head = NULL;
//Node* tail = NULL;

// display
void displayList(){
    Node* current = head;
    if(current == NULL){
        printf("Empty list \n");
        return;
    }
    printf("[ ");
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf(" ]\n");
}

// Insertion
void insertBegin(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    if(head == NULL){
        head = newNode;
    }
    else{
    head->prev = newNode;
    head =  newNode;
    }
}

void insertEnd(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if(head == NULL){
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    Node* current = head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

void insertAfterNode(Node* pre, int value){
    if(pre == NULL) return;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    newNode->prev = pre;
    newNode->next = pre->next;

    if(pre->next != NULL){
        pre->next->prev = newNode;
    }

    pre->next = newNode;
}

void deleteBegin(){
    if(head == NULL) return;
    if(head->next == NULL){
        free(head);
        head = NULL;
        return;
    }
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
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
    while(current->next != NULL){
        current = current->next;
    }

    current->prev->next = NULL;
    free(current);
}

void deleteNodeByValue(int value){
    if(head == NULL) return;

    if(head->next == NULL && head->data == value){
        free(head);
        head = NULL;
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
    if(temp->next != NULL){
        temp->next->prev = current;
    }
    free(temp);
}

int main(){
    // displayList();
    // insertBegin(10);
    // insertBegin(20);
    // displayList();
    // insertEnd(30);
    // insertEnd(40);
    // displayList();
    // insertAfterNode(head,15);
    // displayList();
    displayList();
    insertBegin(10);
    insertBegin(15);
    insertBegin(20);
    displayList();
    deleteBegin();
    displayList();
    insertEnd(30);
    displayList();
    deleteNodeByValue(10);
    displayList();
    return 0;
}