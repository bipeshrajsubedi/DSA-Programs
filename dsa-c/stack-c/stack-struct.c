#include<stdio.h>
#define MAX 5

struct Stack{
    int stack[MAX];
    int top;
};

void initialize(struct Stack* s){
    s->top = -1;
}

void push(struct Stack* s,int value){
    if(s->top == MAX-1){ printf("Overflow \n");}
    else{
        s->top++;
        s->stack[s->top] = value;
    }
}

void pop(struct Stack* s){
    if(s->top == -1){printf("underflow \n");}
    else{
        printf("Popped: %d \n",s->stack[s->top]);
        s->top--;
    }
}

void peek(struct Stack* s){
  if(s->top == -1){printf("Stack empty");}
  else{
    printf("Peek: %d \n",s->stack[s->top]);
  }
}

void display(struct Stack* s){
    if(s->top == -1){printf("Stack empty \n");}
    else{
        for(int i=s->top; i>=0; i--){
            printf("%d \n",s->stack[i]);
        }
    }
}

int main(){
    struct Stack s;
    initialize(&s);
    push(&s,2), push(&s,4), push(&s, 7);
    peek(&s);
    display(&s);
    pop(&s);
    display(&s);
    pop(&s);
    display(&s);
    peek(&s);
    return 0;
}