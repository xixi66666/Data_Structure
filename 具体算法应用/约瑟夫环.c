#include <stdio.h>
#include <stdlib.h>

typedef struct node{
   int date;
   struct node *next;
}node,*cmd;     //创建链表

cmd create();   //创建函数
void print(cmd L);  //输出函数
int a,b;        //一共a个数，报b则出链

int main()
{
   cmd L;
   scanf("%d %d",&a,&b);
   L=create();
   print(L);
   return 0;
}

cmd create()   // 创建含有 1 2 3....a个数的链表
{
   int i;
   cmd L,p,s;
   L=(cmd)malloc(sizeof(node));
   p=L;
   p->date=1;
   for(i=2;i<=a;i++){   
   s=(cmd)malloc(sizeof(node));
   s->date=i;
   p->next=s;
   p=s;
 }
    p->next=L;    //循环链表
    return L;
}

void print(cmd L)
{
   int i=0,j,r[1000];   //数组存放出列数字
   cmd q,p;      //删除链结点所需
   p=L;           
   while(i<a){  
      for(j=1;j<(b-1);j++){   //将目标停在要报b
        p=p->next;}              
      q=p->next;         //做删除结点
      r[i]=q->date;      //出链的结点date保存到
      p->next=q->next;     
      free(q);
      p=p->next;
      i++;
 }
 for(j=0;j<=a-1;j++)
  printf("%d ",r[j]);
}
