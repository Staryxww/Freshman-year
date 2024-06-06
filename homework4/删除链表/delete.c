#include<stdio.h>
#include<stdlib.h>
// 定义链表节点结构体
struct list_item{
    int intput;
    struct list_item* pNext;
};

int count;
// 创建链表的函数
struct list_item* Create()
{
    struct list_item*head=NULL;
    struct list_item*pEnd,*pNew;
    count = 0;
    pEnd = pNew =(struct list_item*)malloc(sizeof(struct list_item));
    printf("enter a number\n");
    scanf("%d",&pNew->intput);
    while(pNew->intput!=0){
        count++;
        if(count==1){
            pNew->pNext=head;
            pEnd=pNew;
            head=pNew;
        }
        else{
            pNew->pNext=NULL;
            pEnd->pNext=pNew;
            pEnd=pNew;
        }
        pNew=(struct list_item*)malloc(sizeof(struct list_item));
        scanf("%d",&pNew->intput);
    }
    free(pNew);
    return head;
};
// 打印链表的函数
void Print(struct list_item* head){
    struct list_item *pTemp;
    int ilndex=1;
    pTemp=head;
    while (pTemp!=NULL)
    {
        printf("the %dth number is %d\n",ilndex,pTemp->intput);
        pTemp=pTemp->pNext;
        ilndex++;
    }
}
// 在链表头部插入新节点的函数
struct list_item* Insert(struct list_item* head){
    struct list_item *pNew;
    printf("insert the first number\n");
    pNew=(struct list_item*)malloc(sizeof(struct list_item));
    scanf("%d",&pNew->intput);
    pNew->pNext=head;
    head=pNew;
    count++;
    return head;
}
// 删除指定位置节点的函数

void erase_list(struct list_item *head,int ilndex){
    int i;
    struct list_item* pTemp;
    struct list_item* pPre;
    pTemp=head;
    pPre=pTemp;
    printf("delete NO%d number\n",ilndex);
    for(i=1;i<ilndex;i++){
        pPre=pTemp;
        pTemp=pTemp->pNext;
    }
    pPre->pNext=pTemp->pNext;
    free(pTemp);
    count--;
}

int main(){
    struct list_item* head;
    head=Create();
    head=Insert(head);
    Print(head);
    int x;
    int judge=1;
    while(judge==1){
    printf("delete which number\n");
    scanf("%d",&x);
    erase_list(head,x);
    Print(head);
    printf("enter 1 to continue deleting,enter 0 to exit\n");
    scanf("%d",&judge);
    }
    return 0;
}

