//
// Created by agecspnt on 2021/9/19.
//

#ifndef SQLIST_MAIN_H
#define SQLIST_MAIN_H

#endif //SQLIST_MAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <malloc/malloc.h>
#include <ctime>

#define LIST_INIT_SIZE 100 //储存空间的初始分配量，以数据元素为单位
#define LISTINCREMENT 10 //储存空间的分配增量，以数据元素为单位
#define OK 1 //储存空间的初始分配量，以数据元素为单位
#define ERROR 0 //储存空间的分配增量，以数据元素为单位
#define OVERFLOW -2
typedef int Status;
//typedef int ElemType;
#define ElemType int

typedef struct{
    ElemType *elem; //储存空间基址
    int length;  //当前长度
    int listsize;  //当前分配的储存容量
}SqList;

Status InitList_Sq(SqList &L);
Status CreateList(SqList &L);
Status Show_Sq(SqList &L);
Status Insert_Sq(SqList &L, int pos, ElemType e);
Status Pop_Sq(SqList &L,int pos,ElemType &e);