#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

void displayList(){
    Node* current = head;
    if(current == NULL){
        printf("Linked List Empty \n");
    }
    else{
    printf("[ ");
    while(current != NULL){
        printf("%d ",current->data);
        current = current->next;
    }
    printf(" ]\n");
    }
}

// Insertion
void insertBegin(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    if(tail == NULL){
        tail  = newNode;
    }
}

void insertEnd(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    if(tail != NULL){
        tail->next = newNode;
        tail = newNode;
    }
    else{
        head = newNode;
    }
    tail = newNode;
}

void insertAfterNode(Node* pre,int value){
    if(pre == NULL){
        printf("Insert at begin \n");
    }
    else{
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = pre->next;
        pre->next = newNode;

        if(pre == tail){
            tail = newNode;
        }
    }

}

// Deletion
void deleteBegin(){
    if(head == NULL){
        printf("Empty list \n");
    }
    else{
        Node* temp = head;
        head = head->next;
        if(head == NULL){
            tail = NULL;
        }
        free(temp);
    }
}
void deleteEnd(){
    if(head == NULL) return;
    if(head == tail){
        free(head);
        head = tail = NULL;
        return;
    }
    Node* current = head;
    while(current != tail){
        current = current->next;
    }
    free(tail);
    tail = current;
    tail->next = NULL;
}

// delete node by value
void deleteNodeByValue(int value){
    if(head == NULL) return;
    if(head->data == value){
        deleteBegin();
        return;
        }
    Node* current = head;
    while(current->next !=NULL && current->next->data != value){
        current = current->next;
    }
    if(current == NULL){
        printf("Data not found. \n");
        return;
    }

    Node* temp = current->next;
    current->next = current->next->next;

    if(temp == tail){
        tail = current;
    }
}


int main(){
    displayList();
    insertBegin(10);
    insertBegin(20);
    displayList();
    insertEnd(30);
    displayList();
    insertAfterNode(head,15);
    printf("%d \n", head->data);
    displayList();
    deleteNodeByValue(15);
    displayList();
    return 0;
}