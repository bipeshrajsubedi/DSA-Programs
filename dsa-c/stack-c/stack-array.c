#include<stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int value){
    if (top == MAX-1){
        printf("Overflow \n");
    }
    else{
        top++;
        stack[top] = value;
    }
}
void pop(){
    if (top == -1){
        printf("Underflow \n");
    }
    else{
        printf("value popped: %d \n",stack[top]);
        top--;
    }
}
void peek(){
    if (top == -1){
        printf("No element to peek \n");
    }
    else{
        printf("Top element: %d \n",stack[top]);
    }
}
void display(){
    if (top == -1){
        printf("Stack is empty \n");
    }
    else{
        for(int i=top; i>=0; i--){
            printf("%d \n",stack[i]);
        }
    }
}

int main(){
    peek();
    display();
    push(5), push(6), push(7);
    display();
    pop();
    display();
    pop();
    peek();
    return 0;
}
