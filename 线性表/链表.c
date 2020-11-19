#include<stdio.h>
#include <stdlib.h>
//单链表的结构定义
typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;

typedef struct Node *Linklist;
 
 //头插法创建单链表
 Node * head_Create(){
    int i,value,len;
    //srand(time(0));
	Node *head=(Node *)malloc(sizeof(Node));
	Node *p,*q;
	head->next=NULL;
	p=head;
	printf("输入单链表初始的长度：\n");
	scanf("%d",&len);
	for (i=0;i<len;i++) {
         p = (Node*)malloc(sizeof(Node));
         p->data = rand()%100;
         p->next = head->next;
         head->next = p;
	}
	return head;
 }

 //初始化链表

void InitList(Node *L)
{   // 初始化单链表 L
    L = (Node*)malloc(sizeof(Node));
    L->next = NULL;
 }

//尾插法建立链表
Node* tail_create(){
    int n,i;
    printf("请输入单链表初始的长度：\n");
    scanf("%d",&n);
    Node *head,*p,*r;
    srand(time(0));
    head = (Node*)malloc(sizeof(Node));
    r = head;
    for(i = 0;i<n;i++){
        p = (Node*)malloc(sizeof(Node));
        p->data = rand()%100+1;
        r->next = p;
        r = p;
    }
    r->next = NULL;
    return head;
}

//有参数的构造
Node* Create(Node *head){
    int i,len;
    srand(time(0));
    head = (Node *)malloc(sizeof(Node));
	Node *p,*q;
	head->next=NULL;
	p=head;
	printf("输入单链表初始的长度：\n");
	scanf("%d",&len);
	for (i=0;i<len;i++) {
         p = (Node*)malloc(sizeof(Node));
         p->data = rand()%100+1;
         p->next = head->next;
         head->next = p;
	}
    return head;
 }

//遍历单链表并且输出
void ShowLinkList(Node *head)
{
	Node *p=head->next;
	while (p!=NULL) {
		printf("%d ",p->data);
		p=p->next;        
	}	
	printf("\n");
}

//查找指定位置的元素
int FindIndex(Node* l,int n){
    int i = 0;
    Node *p = l->next;
	if (p!=NULL) {
		for (i=1;i<n;i++) {
			p=p->next;
		}
    }
    else
        printf("错误，p不存在。");
    return p->data;
}

//查找定位元素的位置
int FindValue(Node *l,int value){
    Node *p,*r;
    int count = 0;
    p = l;
    while (p != NULL && p->data != value)
    {
        p = p->next;
        count++;
    }
    return count;
}

//任意位置插入元素
void insert(Node* l,int index,int num){
    int j = 1;
    Node *p,*r;
    p = l;
    while(p && j<index){
        p = p->next;
        ++j;
    }
    if( !p || j>index){
        printf("插入的位置错误");
        return;
    }
    r = (Node*)malloc(sizeof(Node));
    r->data = num;
    r->next = p->next;
    p->next = r; 
}

//删除指定位置的元素
int Delete(Node *l,int index){
    int x;
    int j = 1;
    Node *p,*r;
    p = l;
    while(p->next && j<index){
        p = p->next;
        ++j;
    }
    if(!(p->next) || j>index){
        printf("删除位置错误。");
        return;
    }
    r = p->next;
    p->next = r->next;
    x = r->data;
    free(r);
    return x;
}

//删除指定值的元素
void DeleteValue(Node *l,int value){
    Node *p,*r;
    p = l;
    while(p != NULL && p->data != value){
        p = p->next;
    }
    r = p->next;
    p->next = r->next;
    free(r);
}

//求单链表的长度
int Length(Node *l){
    Node *node;
    int count = 0;
    node = l->next;
    while(node != NULL){
        count++;
        node = node->next;
    }
    printf("单链表的长度是：%d\n",count);
    return count;
}

//单链表的排序

void Sort(Node *l)
{
	Node *p = NULL;//i
	Node *q = NULL;//j
	Node *r = NULL;
	Node tmp;
 
	for (p = l->next; p; p = p->next)
	{
		for (q = p->next; q; q = q->next)
		{
			if (p->data > q->data)
			{
				tmp = *p;
				*p = *q;
				*q = tmp;

				r = p->next;
				p->next = q->next;
				q->next = r;
                //转换节点的同时也要改变节点的next的位置
			}
		}
	}
}

//链表的逆序
void Reverse(Node *l){
    Node *list,*p,*q,*r;
    p = l->next;
    list = (Node*)malloc(sizeof(Node));
    list->next = NULL;
    r = list;
    while(p != NULL){
        r = (Node*)malloc(sizeof(Node));
        r->data = p->data;
        r->next = list->next;
        list->next = r;
        p = p->next;
    } 
    ShowLinkList(list);
}

//链表的合并

void merge(Node *a,Node *b,Node *c){
    Linklist r,s,p,q;
    b = (Node*)malloc(sizeof(Node));
    c = (Node*)malloc(sizeof(Node));
    if(!(b) || !(c))
        exit(0);
    b->next = b;
    c->next = c;

    if(!(a))
        return 0;

    p = b;
    q = c;
    r = a->next;

    while(r!=(a)){
        s = r;
        r = r->next;
        if(s->data%2 == 0){
            s->next = p->next;
            p->next = s;
            p = p->next;
        }
        else{
            s->next = q->next;
            q->next = s;
            q = q->next;
        }
    }
    return ;
}
int main(){
    Node *list,*c;
    Node *a,*b;
     a = tail_create();
     b = tail_create();
    //list = Create(list);
    //list = tail_create();
    InitList(c);
    //list = head_Create();
    //ShowLinkList(list);
    //printf("%d\n",Find(list,3));
    //insert(list,4,69);
    //Delete(list,3);
    //printf("%d\n",Delete(list,3));
    //printf("%d\n",FindValue(list,34));
    //Sort(list);
    //Length(list);
    Merge(a,b,c);
    ShowLinkList(c);
    //ShowLinkList(list);
    //Reverse(list);
}
