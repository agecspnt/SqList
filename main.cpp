#include "main.h"

int main(){
    int e; //用于显示实际被删除的元素
    SqList L;
    InitList_Sq(L);
    CreateList(L);
    Insert_Sq(L,3,999);
    Pop_Sq(L,1,e);
    printf("被删除的元素为：%d\n",e);
    Show_Sq(L);

    return 0;
}