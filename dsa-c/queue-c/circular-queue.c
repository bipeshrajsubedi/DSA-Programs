#include<stdio.h>
#define MAX 5

struct CQueue{
    int items[MAX];
    int front;
    int rear;
};
typedef struct CQueue CQueue;

void initQueue(CQueue* c){
   c->front = c->rear = -1;
}

int isEmpty(CQueue* c){
    return c->front == -1;
}
int isFull(CQueue* c){
    return (c->rear+1)%MAX == c->front;
}
void enqueue(CQueue* c, int value){
    if(isFull(c)){printf("Queue is full \n");}
    else{
        if(isEmpty(c)){c->front = c->rear = 0;}
        else{
            c->rear = (c->rear+1)%MAX;
        }
        c->items[c->rear] = value;
    }
}

void dequeue(CQueue* c){
    if(isEmpty(c)){printf("Queue underflow \n");}
    else{
        int data = c->items[c->front];
        if(c->front == c->rear){c->front = c->rear = -1;}
        else{
            c->front = (c->front + 1)%MAX;
        }
        printf("Dequeued: %d \n", data);
    }
}

void display(CQueue* c){
    printf("Display queue \n");
    int i = c->front;
    while(1){
        printf("%d \n",c->items[i]);
        if(i == c->rear){break;}
        i =(i+1)%MAX;
    }
}

int main(){
    CQueue c;
    initQueue(&c);
    enqueue(&c,2), enqueue(&c,7), enqueue(&c,3),enqueue(&c,6), enqueue(&c,10);
    display(&c);
    enqueue(&c,13);
    dequeue(&c);
    display(&c);
    enqueue(&c,13);
    display(&c);

    return 0;
}
