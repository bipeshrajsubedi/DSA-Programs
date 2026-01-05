#include<stdio.h>
#define MAX 5

struct Queue {
    int items[MAX];
    int front;
    int rear;
};
typedef struct Queue Queue;

void initQueue(Queue* q){
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue* q){
    return q->front == -1 || q->front > q->rear;

}

int isFull(Queue* q){
    return q->rear == MAX -1;
}

void enqueue(Queue* q, int value){
    if(isFull(q)){printf("Queue is full \n");}
    else{
        if(isEmpty(q)){ q->front = 0;}
        q->rear++;
        q->items[q->rear]=value;
    }
}
void dequeue(Queue* q){
    if(isEmpty(q)){printf("Queue is empty \n");}
    else{
        int val = q->items[q->front];
        q->front++;
        if(q->front > q->rear){q->front = q->rear = -1;}
        printf("Dequeued: %d \n", val);
    }
}

void display(Queue* q){
   if(isEmpty(q)){printf("Queue is empty \n");}
   else{
   printf("queue elemets \n");
   for(int i=q->front; i<=q->rear; i++){
     printf("%d \n",q->items[i]);
   }
   }
}

int main(){
    Queue my_q;
    initQueue(&my_q);
    enqueue(&my_q,2),enqueue(&my_q,5),enqueue(&my_q,7),enqueue(&my_q,9),enqueue(&my_q,10);
    display(&my_q);
    enqueue(&my_q,13);
    dequeue(&my_q);
    display(&my_q);
    enqueue(&my_q,14);
    return 0;
}