# Lecture 2

## Pseudocode for the Push() function
* Check for **Stack Overflow** condtion
* If the Stack is full, then print the message "Stack Overflow" and return
* If Stack is not full, then increment **tos** by 1
* Place the element in the Stack at the index pointed by tos

**Stack Overflow** is the condition which occurs when we try to push/add elements to the Stack beyond its size limit.

**Note:** For Push() function return type is **void**.

## Pseudocode for the Pop() function
* Check for **Stack Underflow** condition
* If the Stack is empty, then print the message "Stack Underflow" and return
* If Stack is not empty, then delete the element pointed by **tos** from the Stack
* Decrement **tos** by 1
* return the deleted element

**Stack Underflow** is the condition that occurs when we try to pop elements from a Stack but the Stack is already element and cannot execute the pop() function.

**Note:** Return type of pop() function may be int,float or char

### C Program to illustrate the Push() and Pop() function


```c
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



```
