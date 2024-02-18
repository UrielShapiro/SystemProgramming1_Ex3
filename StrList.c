#include <stdio.h>
#include "StrList.h"

struct StrList
{
    struct Node *head;
    size_t size;
}StrList;
struct Node
{
    char *data;
    struct Node *next;
    struct Node *previous;
}Node;

typedef struct Node Node;
typedef struct StrList StrList;

StrList* StrList_alloc()
{
    StrList *sList = (StrList*)malloc(sizeof(Node));
    sList->head = NULL;
    sList->size = 0;
    sList->head->next = NULL;
    sList->head->previous = NULL;
    return sList;
}

void StrList_free(StrList* StrList)
{
    Node* temp = &StrList->head;
    for (size_t i = 0; i < StrList_size; i++)
    {
        Node* next = &temp->next;
        free(&temp);
        temp = &next->next;
    }
}
size_t StrList_size(const StrList* StrList)
{
    size_t size = 0;
    Node* temp = StrList->head;
    while (temp)
    {
        temp = temp->next;
        size++;
    }
    return size;
}
void StrList_insertLast(StrList* StrList,const char* data)
{
    StrList_insertAt(StrList, data, StrList_size - 1);
}
void StrList_insertAt(StrList* StrList,const char* data,int index)
{
    Node* temp = StrList->head;
    int i = 0;
    while(i < index)
    {
        temp = &temp->next;
        i++;
    }
    temp->next->data = data;
    
}



    