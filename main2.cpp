//
// Created by agecspnt on 2021/9/19.
//

#include "main.h"

// 构造一个空的线性表L
Status InitList_Sq(SqList &L){
    L.elem = (ElemType*) malloc(LIST_INIT_SIZE*sizeof (ElemType));  //100*4
    if (!L.elem){   // 储存分配失败
        printf("内存分配失败，初始化失败！\n");
        exit(OVERFLOW);  // 程序异常退出
    }
    L.length = 0;  // 空表的长度初始化为0
    L.listsize = LIST_INIT_SIZE;  //空表的初始存储空间为 LIST_INIT_SIZE
    return OK;
}
Status CreateList(SqList &L){
    int n;
    printf("要输入几个元素：\n");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&L.elem[i]);
        L.length++;
    }
    return OK;
}
Status Show_Sq(SqList &L){
    for(int i=0;i<L.length;i++)
    {
        printf("%d ",L.elem[i]);
    }
    return OK;
}
Status Insert_Sq(SqList &L, int pos, ElemType e){
    if (pos<1 || pos>L.length+1){  //对传入的pos进行判断，看其是否合法
        printf("插入位置有问题");
        return ERROR;
    }
    if (L.length >= L.listsize){
        ElemType *newbase = (ElemType*) realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
        if (!newbase){
            printf("内存空间分配失败!\n");
            exit(OVERFLOW);
        }
        L.elem = newbase;
        L.listsize += LISTINCREMENT;
    }
    ElemType *q = &(L.elem[pos-1]);  //即将要插入元素的地址
    ElemType *p = &(L.elem[L.length-1]);  //p为最后一个元素的地址

    for (; p>=q; --p) {
        *(p+1) = *p;  //逆序将元素右移
    }
    *q = e;
    L.length++;
    return OK;
}
Status Pop_Sq(SqList &L,int pos,ElemType &e){
    if (pos>L.length || pos<1){
        printf("输入的位置有误\n");
        return ERROR;
    }
    ElemType *p = &(L.elem[pos-1]);  //将即将删除的元素的地址赋值给p
    e = *p;
    ElemType *q = L.elem + L.length - 1;  //最后一个元素的位置
    for (++p;p<=q ; ++p) {
        *(p-1) = *p;
    }
    L.length--;
    return OK;
}
