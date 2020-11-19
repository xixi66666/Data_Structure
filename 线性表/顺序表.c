#include<stdio.h>
#include<stdlib.h>
#define Maxsize 20
typedef int ElemType;

typedef struct list
{
    int data[Maxsize];
    int length;
}Seqlist;

//初始化
void InitSeqlist(Seqlist *l){//这是一个空的线性表，长度为0
    l = (Seqlist*)malloc(sizeof(Seqlist));
    l->length = 0;
}

//创建
void CreatSeqlist(Seqlist *l){
    //l = (Seqlist*)malloc(sizeof(Seqlist));
    srand(time(0));
    int i,x;
    printf("请输入元素的总个数：");
    scanf("%d",&i);
    if(i<0 || i>Maxsize){
        printf("创建的数目错误。");
        return;
    }
    int j;
    for(j = 0;j<i;j++){
        l->data[j] = rand()%100+1;   
    }
    l->length = i;
}

//在头部插入新元素
void Pushfront(Seqlist *l,ElemType x){
    if(l->length == Maxsize){
        printf("元素已满，无法插入\n");
        return;
    }
    int i;
    for(i = l->length;i>0;i--){
        l->data[i] = l->data[i-1];
    }
    l->data[0] = x;
    l->length++;
}

//在尾部插入新元素
void Pushback(Seqlist *l,ElemType x){
    if(l->length == Maxsize){
        printf("元素已满，无法插入\n");
        return;
    }
    l->data[l->length] = x;
    l->length++;
}

//在指定位置插入
void Insert(Seqlist *l,ElemType x, int i){
    if(l->length == Maxsize){
        printf("元素已满，无法插入\n");
        return;
    }
    int k;
    for(k = l->length;k>=i;k--){
        l->data[k] = l->data[k-1];
    }
    l->data[i-1] = x;
    l->length++;
}

//插入元素并且不改变顺序表的相对位置
void InsertX(Seqlist *l,int num){
    int i = 0,n;
    if(l->length == Maxsize){
    printf("元素已满，无法插入\n");
    return;
    }
    for(i = 0;i<l->length;i++){
        if(l->data[i] >= num);
        n = i;
    }
    for(i = l->length-1;i>=n;i--){
        l->data[i+1] = l->data[i];
    }
    n = i;
    l->data[n] = num;
    l->length++;
}

//删除指定位置的元素
int Delete(Seqlist *l,int pos){
    int i;
    if(pos<0||pos>=l->length){
        printf("删除位置不合法");
        return;
    }
     if(pos == 0){//pos == 0
         for(i = 0;i<l->length-1;i++){
             l->data[i] = l->data[i+1];
         }
         l->length--;
         return;
     }
    for(i=pos-1; i<l->length-1; i++)
    {
        l->data[i]=l->data[i+1];
    }
    l->length--;
}

//删除指定值的元素
void DeleteValue(Seqlist *l,int value){
    int i,k;
    for(i = 0;i<l->length;i++){
        while(value == l->data[i]){
             Delete(l,i);
        } 
    }
}

void pop_back(Seqlist *list)//删除最后一个元素
{
    if(list->length==0)
    {
        printf("顺序表为空，无法删除元素");
        return;
    }
    list->length--;//这也太聪明了，直接减少一个元素
}

//查找指定位置的元素
int Getvalue(Seqlist *l,int i){
    return l->data[i-1];
}

//查找指定值的元素
int Getnumber(Seqlist *l,int value){
    int i;
    for(i = 0;i<l->length;i++){
        if(l->data[i] == value);
        return i;
    }
}

//逆序顺序表
void Reverse(Seqlist *l){
    if(l->length <= 0){
        printf("顺序表出错。");
        return;
    }
    int i,t;
    int k = l->length-1;
    for(i = 0;i<k;i++,k--){
        t = l->data[i];
        l->data[i] = l->data[k];
        l->data[k] = t;
    }
}

//排序顺序表
void SortList( Seqlist *l){
    int i,j;
    for(i = 0;i<l->length-1;i++){
        for(j = 0;j<l->length-1-i;j++){
            if(l->data[j] > l->data[j+1]){
                ElemType t = l->data[j];
                l->data[j] = l->data[j+1];
                l->data[j+1] = t;
            }
        }
    }
}

//根据第一个值排序
void SortList_Value(Seqlist *l){
    int flag = l->data[0];
    int temp,i,count = 0;
    for(i = 1;i<l->length;i++){
        if(l->data[i]<flag){
            count++;
            if(count != i){
                temp = l->data[i];
                l->data[i] = l->data[count];
                l->data[count] = temp;
            } 
        }
    }
    temp = l->data[0];
    l->data[0] = l->data[count];
    l->data[count] = temp;
    }


//遍历输出顺序表
void Showlist(Seqlist *list)//顺序表的打印输出
{   
    int i;
    if(list == NULL){
        printf("为空");
        return ;
    }
    for(i=0; i<list->length; i++)
    {
        printf("%d  ",list->data[i]);
    }
}

//删除区间值
void DeleteInterval(Seqlist *l,Seqlist*n, int n1,int n2){
    int i = 0;
    int count = 0;
    for(i;i<l->length;i++){
        if(l->data[i]<n1 || l->data[i]>n2){
            n->data[count] = l->data[i];
            count++;
        }
    }
    n->length = count;
}


//清除顺序表
void clear(Seqlist *l){
    l->length = 0;
}

//静态分配的内存在栈里，每进入一个函数时都会建栈，栈里会存放函数用到的参数、局部变量等信息，函数执行完以后，会出栈销毁栈，
//这个过程就会释放你静态分配的数组内存，这是由系统自动完成的。

//合并两个顺序表
void merge(Seqlist *new,Seqlist *p1,Seqlist *p2){
    new->length = p1->length+p2->length;
    if(new->length<0 || new->length >Maxsize){
        printf("超出合法范围");
        return ;
        }
    int a = 0,b = 0,c = 0;
    for(a = 0;a<p1->length;a++){
        new->data[a] = p1->data[a];
    }
    b = p1->length;
    for(c = 0;c<p2->length;){
        new->data[b] = p2->data[c];
        b++;
        c++;
    }
    Showlist(new);
}

//排序两个顺序表
void SortTwoList(Seqlist *l,Seqlist *p){
    if(l->length+p->length>Maxsize){
        printf("超出合理范围");
        return ;
    }
    int n = l->length;
    l->length = l->length+p->length;
    
    int i = 0;
    for(i = 0;i<p->length;i++){
        l->data[n] = p->data[i];
        n++;
    }
    SortList(l);
}

void main(){
    Seqlist list,list1,a,b;
    int *x;
    //InitSeqlist(&list);
    //InitSeqlist(&list1);
    CreatSeqlist(&list);
    InitSeqlist(&b);
    //Showlist(&list);
    //Pushfront(&list,69);
    //Pushback(&list,69);
    //Insert(&list,11,3);
    //Delete(&list,2);
    //printf("%d",Getvalue(&list,3));
    //Reverse(&list);
    //clear(&list);
    //merge(&a,&list1,&list);  
    // SortList(&list);
    // Showlist(&list);
    //Showlist(&list1);
    //InsertX(&list,69);
    //SortTwoList(&list,&list1);
    //Showlist(&list);
    Showlist(&list);
    //SortList_Value(&list);          2
    //Showlist(&list);                2
    //DeleteInterval(&list,&b,50,80);     1
    //Showlist(&b);                       1
}
