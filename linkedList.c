#include<stdio.h>

#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElemType;
typedef struct LinkList
{
    ElemType data;
    struct Node* next; //由于是顺序执行，所以这里还不能使用简化后的类型名
} Node, LinkList, *LinkListPtr;

/**
 * 创建具有n个结点的单链表
 * 链表的结点是根据需要一个一个动态生成，链接到原有的链表上，可采用尾插法后头插法，这里使用头插法，即插入头结点之后成为第一个结点
 */
LinkListPtr create_head(int n)
{
    /*
        返回类型为指针类型，这里就不能用参数来放返回结果了，
        因为链表的首地址是在创建的时候动态分配的，
        在main函数中调用时&Node的地址值跟创建好之后的地址值是不同的
    */
    LinkListPtr list, node;
    ElemType data;
    int i;

    list = (LinkListPtr)malloc(sizeof(Node)); //生成头结点
    list->next = NULL;
    printf("请输入结点数据值\n");
    for(i = 0; i < n; i++)
    {
        node = (LinkListPtr)malloc(sizeof(Node)); //生成新结点
        scanf("%d", &data);
        node->data = data;
        node->next = list->next;
        list->next = node;
    }
    return list;
}

/**
 * 尾插法创建链表
 */
LinkListPtr create_tail(int n) {
    LinkListPtr list, node, p;
    ElemType data;
    int i;

    list = (LinkListPtr)malloc(sizeof(Node)); //生成头结点
    list->next = NULL;
    p = list;
    printf("请输入结点数据值\n");
    for(i = 0; i < n; i++) { //生成新结点
        node = (LinkListPtr) malloc(sizeof(Node));
        scanf("%d", &data);
        node->data =data;
        //指针移动到最后一个结点
        while(p->next) {
            p = p->next;
        }
        //修改指针，插入新结点
        node->next = NULL;
        p->next = node;
    }
    return list;
}

/**
 * 插入数据到指定位置
 */
Status insertLinkList(LinkListPtr linkListPtr, ElemType e, int pos)
{
    LinkListPtr p = linkListPtr;
    int i = 0;

    while(i < pos-1 && p) { //移动到第pos-1个结点
        p = p->next;
        i++;
    }
    if(!p || i > pos) {
        printf("第%d个元素不存在\n", pos);
        return ERROR;
    }
    //为新结点分配空间，赋值，修改后继指针和第pos-1个结点的后继指针
    LinkListPtr newNode = (LinkListPtr)malloc(sizeof(Node));
    newNode->data = e;
    newNode->next = p->next;
    p->next = newNode;
    return OK;
}

/**
 * 删除第pos个结点
 */
Status deleteByOrder(LinkListPtr list, int pos, ElemType* e) {
    LinkListPtr p = list;
    LinkListPtr q;
    int i = 0;
    while(p && i < pos-1) { //移动到第pos-1个结点
        p = p->next;
        i++;
    }
    if(!p || i > pos) {
        printf("\n第%d个结点不存在", pos);
        return ERROR;
    }
    q = p->next;
    *e = q->data; //返回被删除的元素值
    //修改相关结点的指针域
    p->next = q->next;
    //释放被删除结点的空间
    free(q);
    return OK;
}

/**
 * 清空链表，只保留头结点
 */
Status clearList(LinkListPtr list) {
    LinkListPtr p = list->next; //移动到第一个结点
    LinkListPtr q;
    while(p) {
        printf("%d\t", p->data);
        q = p;
        p = p->next;
        free(q);
    }
    list->next = NULL;
}

/**
 * 遍历链表，输出其中的数据元素
 */
Status printLinkList(LinkListPtr list)
{
    LinkListPtr p;
    p = list->next; //移动到存放真实数据的第一个结点
    while(p) {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}

/**
 * 链表的逆置
 */
Status reserve(LinkListPtr list) {
    LinkListPtr p, q, r;
    p = list;//P指向头结点
    q = p->next; //q指向第一个结点
    while(q->next) {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    q->next = p; //连上最后一个结点
    p = list->next;
    p->next = NULL; //收尾
    list->next = q; //赋头
    return OK;
}

void main()
{
    ElemType e = 100;
    //LinkListPtr list = create_head(10); //头插法生成链表
    LinkListPtr list2 = create_tail(10); //尾插法生成链表
    insertLinkList(list2, e, 4);
    insertLinkList(list2, e, 4);
    insertLinkList(list2, e, 1);
    insertLinkList(list2, e, 18);
    printLinkList(list2);
    deleteByOrder(list2, 1, &e);
    printf("被删除的元素值: %d\n", e);
    deleteByOrder(list2, 4, &e);
    printf("被删除的元素值: %d\n", e);
    deleteByOrder(list2, 4, &e);
    printf("被删除的元素值: %d\n", e);
    printLinkList(list2);
    printf("逆置链表：\n");
    reserve(list2);
    printLinkList(list2);
    printf("清空链表:");
    clearList(list2);
    printLinkList(list2);
}