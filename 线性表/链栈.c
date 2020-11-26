#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>  
typedef int Elem;
typedef struct node{
    Elem data;
    struct node *next;
}Node;
//初始化
void InitList(Node *l){
    l = (Node*)malloc(sizeof(Node));
    l->next = NULL;
    l->data = -1;
}
//入栈
int Push(Node* l,Elem x){
    Node* temp;
    temp = (Node*)malloc(sizeof(Node));
    if(temp == NULL){
        printf("申请空间失败");
        return false;
    }
    temp->data = x;
    temp->next = l->next;
    l->next = temp;
    return true;
}
//出栈
int Pop(Node *l,Elem *x){
    Node *temp;
    temp = l->next;
    if(temp == NULL){
        printf("空栈无法删除");
        return false;
    }
    l->next = temp->next;
    *x = temp->data;
    free(temp);
    return true;

}
