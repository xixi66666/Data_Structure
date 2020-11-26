#include<stdio.h>
#include<stdlib.h>
#define Maxsize 20
typedef int ElemType;
typedef struct list
{
    int data[Maxsize];
    int top;
}Seqlist;

//初始化栈
void InitStack(Seqlist *l){
    l->top = -1;
}

//进栈
int Push(Seqlist *l,ElemType x){
    if(l->top == Maxsize-1){
        printf("栈已满");
        return;
    }
    l->top++;
    l->data[l->top] = x;
    return;
}

//出栈
int Pop(Seqlist *l,ElemType *x){
    if(l->top == -1){
        printf("空栈无法再出栈");
        return ;
    }
    else{
        *x = l->data[l->top];
        l->top--;
        return;
    }
}

//获取栈顶元素 
int Gettop(Seqlist *l,ElemType *x){
    if(l->top == -1){
        printf("空栈无法再获取");
        return ;
    }
    else{
        *x = l->data[l->top];
        return 1;
    }
}
