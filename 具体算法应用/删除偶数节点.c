#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist();
struct ListNode *deleteeven( struct ListNode *head );
void printlist( struct ListNode *head )
{
     struct ListNode *p = head;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}
struct ListNode *createlist(){
    struct ListNode *p1,*p2,*head;
    int i = 0,n;
    p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    scanf("%d",&n);
    while(n != -1){
        p1->data = n;
        i = i+1;
        if(i == 1)
        head = p1;
        else
        {
            p2->next = p1;
        }
        p2 = p1;
        p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
        scanf("%d",&n);
		p1->data=n;      
    }
    p2->next = NULL;
    return head;
}
struct ListNode *deleteeven( struct ListNode *L ){
    struct ListNode *f,*s;
    while(L!=NULL&&L->data%2==0)
        L=L->next;//头结点不是偶数
    s=f=L;
    while(f!=NULL&&f->data%2==0){
        f=f->next;
            if(f->next!=NULL){
                f=f->next;
            }
            else
                s->next=NULL;
                return L;
        
        s->next = f;
        s = f;
        f = f->next;
    }
    return L;
}
int main()
{
    struct ListNode *head;

    head = createlist();
    head = deleteeven(head);
    printlist(head);

    return 0;
}
