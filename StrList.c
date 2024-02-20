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
};
typedef struct _Node Node;

struct _StrList
{
    struct _Node* head;
    size_t size;
};
typedef struct _StrList StrList;

Node* createNode(char* data, Node* next)
{
    Node* node=(Node*)malloc (sizeof(Node));
    node->data = data;
    node->next = next;
    return node;
}
StrList* StrList_alloc()
{
    StrList* sList = (StrList*)malloc(sizeof(StrList));
    sList->size = 0;
    sList->head = NULL;
    return sList;
}

void StrList_free(StrList* StrList)
{
    Node * temp = StrList->head;
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
    return StrList->size;
}
void StrList_insertAt(StrList* StrList,const char* data,int index)
{
    Node* temp;
    Node* node;
    char* str = (char*)malloc(sizeof(char) * strlen(data));
    strcpy(str, data);
    if(StrList->size == 0 || index == 0)
    {
        node = createNode(str, StrList->head);
        StrList->head=node;
    }
    else
    {
        temp = StrList->head;
        size_t i = 0;
        while(i < index-1)
        {
            temp = temp->next;
            i++;
        }
        if (index == StrList->size)
        {
            node= createNode(str,NULL);
        }
        else
        {
            node = createNode(str,temp->next);
        }
        temp->next=node;
    }
    StrList->size = StrList->size+1;
}

void StrList_insertLast(StrList* StrList,const char* data)
{
       StrList_insertAt(StrList, data, StrList->size);
}
char* StrList_firstData(const StrList* StrList)
{
    char* output = StrList->head->data;
    return output;
}
void StrList_printAt(const StrList* Strlist,int index)
{
        Node* temp = Strlist->head;
        for(size_t i=0; i<index;i++)
        {
            temp = temp->next;
        }
        printf("%s \n",temp->data);
}
void StrList_print(const StrList* StrList)
{
    Node* temp = StrList->head;
    for (size_t size = 0; size<StrList->size;size++)
    {
        printf("%s ",temp->data);
        temp = temp->next;
    }
    printf("\n");
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
    for(size_t i=0;i < StrList_size(StrList);i++)
    {
        if (!strcmp(temp->data,data))   //strcmp returns 0 if the strings are equal.
        {
            counter++;
        }
        temp = temp->next;
    }
    return counter;
}
void StrList_removeAt(StrList* StrList, int index)
{
    // Node* temp = StrList->head;
    // int i = 0;
    // while(i < index)
    // {
    //     temp = temp->next;
    //     i++;
    // }
    // StrList->size=StrList->size-1;
    // free(temp);
}

void StrList_remove(StrList* StrList, const char* data)
{
    if (StrList->size == 0)
    {
        printf("The list is empty\n");
        return;
    }
    Node* p1=StrList->head;
    Node* p2=p1->next;
    while (p2 != NULL)
    {
        if(!strcmp(StrList->head->data, data))
        {
            p1 = p2;
            free(StrList->head);
            StrList->head = p1;
            p2=p1->next;
            StrList->size--;
        }
        else if(!strcmp(p2->data,data))
        {
            Node* removed=p2;
            p2=p2->next;
            free(removed);
            p1->next=p2;
            StrList->size--;
        }
        else
        {
            p2 = p2->next;
            p1 = p1->next;
        }
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
}
void StrList_reverse( StrList* StrList)
{
    // Node* temp = StrList->head;
    // Node* p;
    // size_t i = 0;
    // while(i < StrList_size(StrList))
    // {
    //     temp = temp->next;
    //     i++;
    // }
    // i = 0 ;
    // Node* head = (Node*)malloc(sizeof(Node));
    // copy_Node(head,temp);
    // StrList->head = head;
    // while(i < StrList_size(StrList))
    // {
    //     temp->next = p;
    // }
}

#endif
    