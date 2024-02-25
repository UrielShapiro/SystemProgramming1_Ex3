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

Node* createNode(const char* data, Node* next)      //Allocates memory for a new node with the given data.
{
    Node* node=(Node*)malloc(sizeof(Node));
    node->data = (char*) malloc(strlen(data) + sizeof(char)); //Allocates memory for the data of the new node. +1 for the \0.
    strcpy(node->data,data);
    node->next = next;
    return node;
}
StrList* StrList_alloc()
{
    StrList* sList = (StrList*)malloc(sizeof(StrList));  //Allocates memory for a new StrList.
    sList->size = 0;                                    //Initializes the size of the list to 0.
    sList->head = NULL;
    return sList;
}

size_t StrList_size(const StrList* StrList)
{
    return StrList->size;
}
void StrList_insertAt(StrList* StrList,const char* data,int index)
{
    Node* temp;             //A temporary node to traverse the list.
    Node* node;             //Initializing the new node to be inserted.
    if(StrList->size == 0 || index == 0) //If the list is empty or the index is 0, the new node will be the head of the list.
    {
        node = createNode(data, StrList->head);
        StrList->head = node;           //Setting the head of the list to be the new node.
    }
    else
    {
        temp = StrList->head;
        size_t i = 0;
        while(i < index-1)  //Traversing the list to the node before the index.
        {
            temp = temp->next;
            i++;
        }
        if (index == StrList->size)
        {
            node= createNode(data,NULL); //If the index is the last node, the new node will be the last node, therefore its "next" will be NULL.
        }
        else
        {
            node = createNode(data,temp->next); //If the index is not the last node, the new node will be inserted between the node before the index and the node at the index.
        }
        temp->next=node;    //Setting the "next" of the node before the index to be the new node.
    }
    StrList->size = StrList->size+1;    //Increasing the size of the list by 1.
}

void StrList_insertLast(StrList* StrList,const char* data)
{
       StrList_insertAt(StrList, data, StrList->size);  //Inserting the new node at the last index of the list using the InsertAt function.
}
char* StrList_firstData(const StrList* StrList)
{
    return StrList->head->data;
}
void StrList_printAt(const StrList* Strlist,int index)
{
    Node* temp = Strlist->head;
    for(size_t i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    printf("%s\n",temp->data);
}
void StrList_print(const StrList* StrList)
{
    if(StrList->size == 0)
    {
        printf("\n");   //As required by the tests
        return;         //Nothing else to print.
    }
    Node* temp = StrList->head;
    for (size_t size = 0; size<StrList->size - 1;size++)
    {
        printf("%s ",temp->data);
        temp = temp->next;
    }
    printf("%s",temp->data);
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
    if (StrList->size == 0 || index >= StrList->size)
    {
        return;
    }
    Node* p1 = StrList->head;
    Node* p2 = p1->next;
    if (index == 0)
    {
        free(p1->data);
        free(p1);
        StrList->head = p2;
        StrList->size--;
        return;
    }
    size_t i = 0;
    while (i < index - 1)
    {
        p1 = p2;
        p2 = p2->next;
        i++;
    }
    p1->next = p2->next;    //To keep the list connected after removing the node.
    free(p2->data);
    free(p2);
    StrList->size--;
}
void StrList_free(StrList* StrList)
{
    while(StrList->size > 0)    //Will run as long as the list is not empty.
    {
        StrList_removeAt(StrList, 0);   //remove the head of the list, StrList_size times. eventually the list will be empty.
    }
    free(StrList);  //Free the list itself.
}
void StrList_remove(StrList* StrList, const char* data)
{
    if (StrList->size == 0)
    {
        return;
    }
    Node* p1=StrList->head;
    Node* p2=p1->next;
    while (p2 != NULL)
    {
        if(!strcmp(StrList->head->data, data))
        {
            p1 = p2;
            free(StrList->head->data);
            free(StrList->head);
            StrList->head = p1;
            p2=p1->next;
            StrList->size--;
        }
        else if(!strcmp(p2->data,data))
        {
            Node* removed=p2;
            p2=p2->next;
            free(removed->data);
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
        return FALSE;   //If the sizes of the lists are not equal, the lists cant be equal.
    }
    Node* t1 = StrList1->head;
    Node* t2 = StrList2->head;
    while(t1 && t2)
    {
        if(strcmp(t1->data,t2->data) != 0)  //If the data of the nodes is not equal, the lists are not equal.
        {
            return FALSE;
        }
        t1 = t1->next;
        t2 = t2->next;
    }
    return TRUE;    //If the function did not return FALSE until now, the lists are equal.
}
StrList* StrList_clone(const StrList* list)
{
    StrList* output = StrList_alloc();  //Allocating memory for the new list.
    Node* new_list_node = list->head;       //A pointer to the head of the list. So we can traverse the list.
    for (size_t i = 0; i < StrList_size(list); i++)
    {
        char* data= (char*)malloc(strlen(new_list_node->data)+1); //Allocating memory for the new node's data.
        strcpy(data,new_list_node->data);
        StrList_insertLast(output, data);
        free(data);
        new_list_node = new_list_node->next;
    }
    return output;
}

void StrList_reverse( StrList* StrList)
{
    if(StrList_size(StrList) == 0 || StrList_size(StrList) == 1)    //If the list is empty or has only one node, there is no need to reverse it.
    {
        return;
    }
    Node* current = StrList->head;
    Node* previous = NULL;  //Pointer to the previous node.
    Node* next = NULL;      //Pointer to the next node.
    while (current != NULL) //Traversing the list and reversing the "next" of each node.
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    StrList->head = previous;   //Setting the head of the list to be the last node.
}

void SwapNodes(Node* a, Node* b)    //Swaps the data of two nodes.
{
    char* temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void StrList_sort( StrList* StrList)
{
    Node* current = StrList->head;
    //Bubble sort
    for (size_t i = 0; i < StrList_size(StrList)-1; i++)
    {
        for (size_t j = 0; j < StrList_size(StrList)-i-1; j++)
        {
            if(strcmp(current->data,current->next->data) > 0)
            {
                SwapNodes(current, current->next);
            }
            current = current->next;
        }
        current = StrList->head;
    }
}

int StrList_isSorted(StrList* StrList)
{
    Node* current = StrList->head;
    for (size_t i = 0; i < StrList_size(StrList)-1; i++)
    {
        if(strcmp(current->data,current->next->data) > 0)
        {
            return FALSE;
        }
        current = current->next;
    }
    return TRUE;
}

#endif