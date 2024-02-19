#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "StrList.h"
#ifndef _STRLIST_C
#define _STRLIST_C
#define FALSE 0
#define TRUE 1
struct _Node
{
    char *data;
    struct _Node *next;
    struct _Node *previous;
};
typedef struct _Node Node;

struct _StrList
{
    struct _Node* head;
    size_t size;
};



StrList* StrList_alloc()
{
    StrList* sList = (StrList*)malloc(sizeof(StrList));
    sList->size = 0;
    Node* p = (Node*)calloc(1 ,sizeof(Node));
    sList->head = p;
    sList->head->next = NULL;
    sList->head->previous = NULL;
    return sList;
}

void StrList_free(StrList* StrList)
{
    Node * temp = &StrList->head;
    size_t size= StrList_size(StrList);
    for (size_t i = 0; i < size; i++)
    {
        Node* next = temp->next;
        free(temp);
        temp = next->next;
    }
}
size_t StrList_size(const StrList* StrList)
{
    // size_t size = 0;
    // Node * temp = &StrList->head;
    // while (temp)
    // {
    //     temp = temp->next;
    //     size++;
    // }
    return StrList->size;
}
void StrList_insertAt(StrList* StrList,const char* data,int index)
{
    printf("Got to the insertAt\n");
    Node* temp = &StrList->head;
    int i = 0;
    while(i < index)
    {
        temp = temp->next;
        i++;
    }
    char* str = (char*)malloc(sizeof(char) * strlen(data));
    strcpy(str, data);
    Node* current = (Node*)malloc(sizeof(Node));
    current->data = str;
    current->next = temp;
    printf("the problem is in 74\n");
    current->previous = temp->previous;
    printf("the problem is in 76\n");
    temp->previous = current;
    printf("the problem is in 78\n");
    StrList->size= StrList->size+1;
}
void StrList_insertLast(StrList* StrList,const char* data)
{
    StrList_insertAt(StrList, data, StrList_size(StrList));
}
char* StrList_firstData(const StrList* StrList)
{
    char* output = StrList->head->data;
    return output;
}
void StrList_printAt(const StrList* Strlist,int index)
{
        const Node* temp = Strlist->head;
        size_t i = 0;
        while (i < index)
        {
            temp = temp->next;
            i++;
        }
        printf("%s",temp->data);
}
void StrList_print(const StrList* StrList)
{
    size_t size = 0;
    while (size < StrList_size(StrList))
    {
        StrList_printAt(StrList, size);
        size++;
    }
}
int StrList_printLen(const StrList* Strlist)
{
    size_t size = 0;
    Node* temp = Strlist->head;
    while (temp)
    {
        size += strlen(temp->data);
        temp = temp->next;
    }
    return size;
}
int StrList_count(StrList* StrList, const char* data)
{
    Node* temp = StrList->head;
    int counter = 0;
    while(temp)
    {
        if (strcmp(temp->data,data))
        {
            counter++;
        }
        temp = temp->next;
    }
    return counter;
}
void StrList_removeAt(StrList* StrList, int index)
{
    Node* temp = StrList->head;
    int i = 0;
    while(i < index)
    {
        temp = temp->next;
        i++;
    }
    temp->next->previous = temp->previous;
    temp->previous->next = temp->next;
    StrList->size=StrList->size-1;
    free(temp);
}

void StrList_remove(StrList* StrList, const char* data)
{
    Node* temp = StrList->head;
    int index = 0;
    while(temp)
    {
        if (strcmp(temp->data,data))
        {
            StrList_removeAt(StrList, index);
        }
        temp = temp->next;
        index++;
    }
}

int StrList_isEqual(const StrList* StrList1, const StrList* StrList2)
{
    if(StrList_size(StrList1) != StrList_size(StrList2))
    {
        return FALSE;
    }
    Node* t1 = StrList1->head;
    Node* t2 = StrList2->head;
    while(t1 && t2)
    {
        if(strcmp(t1->data,t2->data) != 0)
        {
            return FALSE;
        }
        t1 = t1->next;
        t2 = t2->next;
    }
    return TRUE;
}
Node* Node_alloc()
{
    Node* output = (Node*)malloc(sizeof(Node));
    return output;
}
StrList* StrList_clone(const StrList* list)
{
    StrList* output = StrList_alloc();
    Node* list_node = list->head;
    for (size_t i = 0; i < StrList_size(list); i++)
    {
        char* data=NULL;
        strcpy(data,list_node->data);
        StrList_insertLast(output, data);
        list_node = list_node->next;
    }
    return output;
}
void copy_Node(Node* dst, Node* src)
{
    strcpy(dst->data,src->data);
    dst->next = src->next;
    dst->previous = src->previous;
}
void StrList_reverse( StrList* StrList)
{
    Node* temp = StrList->head;
    Node* p;
    size_t i = 0;
    while(i < StrList_size(StrList))
    {
        temp = temp->next;
        i++;
    }
    i = 0 ;
    Node* head = (Node*)malloc(sizeof(Node));
    copy_Node(head,temp);
    StrList->head = head;
    while(i < StrList_size(StrList))
    {
        p = temp->previous;
        temp->previous = temp->next;
        temp->next = p;
        temp = temp->previous;
    }
}

#endif
    