//Created by Nabin Jaiswal

#include <stdio.h>

struct Stack{
   int arr[5]; //creating static array
    int tos;
};
//Push and Pull Functions Declaration
void push(struct Stack *, int);
int pop(struct Stack *);

int main(){
    int x,i;
    struct Stack s;
    s.tos = -1;

//    Loop for adding elements to the Stack
    for(i=1;i<=6;i++){
        printf("\nEnter a number: ");
        scanf("%d",&x);
        push(&s,x);
    }

//    Loop to remove the elements from the Stack
    for(i=1;i<=6;i++){
        x = pop(&s);
        printf("\n Popped Element = %d",x);
    }
}

void push(struct Stack *p,int x){
    if(p->tos==4){
        printf("\nStack Overflow");
        return;
    }
    p->tos = p->tos + 1;
    p->arr[p->tos] = x;
    printf("\n%d is pushed to the Stack",x);
}
int pop(struct Stack *p){
    int x;
    if(p->tos==-1){
        printf("\nStack Underflow");
        return -1;
    }
    x = p->arr[p->tos];
    p->tos = p->tos-1;
    return (x);
}


