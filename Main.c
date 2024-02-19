#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "StrList.h"

char* inputString()
{
    char* str = (char*)malloc(sizeof(char));
    *str = '\0';
    char c;
    while ((c=getchar())!=' ')
    {
        size_t size = strlen(str);
        str = (char*)realloc(str, size+2);
        str[size]=c;
        str[size+1]='\0';
    }
    return str;
}


StrList* scanList(StrList* list)
{
    int num_of_elements;
    scanf("%d", &num_of_elements);
    printf("Allocating a new StrList\n");
    // StrList* list = StrList_alloc();
    printf("Write your string\n");
    char c;
    while(num_of_elements > 0)
    {
        char* str = (char*)malloc(sizeof(char));
        *str = '\0';
        while ((c=getchar())!=' ')
        {
            size_t size = strlen(str);
            str = (char*)realloc(str, size+2);
            str[size]=c;
            str[size+1]='\0';
        }
        num_of_elements--;
        StrList_insertLast(list, str);
    }
    return list;
}
void insertAt(StrList* list)
{
    printf("Enter an index\n");
    int index = scanf("%d", &index);
    printf("Enter a string %d\n", index);
    char* str=NULL;
    scanf("%s", str);
    StrList_insertAt(list, str, index);
}

int main() {
    printf("please enter a number: \n");
    int choice;
    scanf("%d", &choice);
    printf("A number was entered! \n");
    StrList* list = StrList_alloc();

    switch (choice) {
    case 0:
            break;
    case 1:
        scanList(list);
        break;
    case 2:
        insertAt(list);
        break;
    case 3:
        StrList_print(list);
        break;
    case 4:
        printf("%ld", StrList_size(list));
        break;
    case 5:
        printf("Enter an index\n");
        int index_5 = scanf("%d", &index_5);
        StrList_printAt(list, index_5);
        break;
    case 6:
        printf("The amount of chars in the string is: %d", StrList_printLen(list));
        break;
    case 7:
        printf("Enter a string\n");
        char* str_7 = NULL;
        scanf("%s", str_7);
        printf("The amount of times the string appears in the list is: %d", StrList_count(list, str_7));
        break;
    case 8:
        printf("Enter a string\n");
        char* str_8 = NULL;
        scanf("%s", str_8);
        StrList_remove(list, str_8);
        break;
    case 9:
        printf("Enter an index\n");
        int index_9;
        scanf("%d", &index_9);
        StrList_removeAt(list, index_9);
        break;
    case 10:
        StrList_reverse(list);
        break;
    case 11:
        StrList_free(list);
        break;
    // case 12:
    //     if (!StrList_isSorted(list)) {
    //         StrList_sort(list);
    //     }
    //     break;
    // case 13:
    //     if(StrList_isSorted(list)) {
    //         printf("The list is sorted\n");
    //     }
        // else {
        //     printf("The list is not sorted\n");
        // }
        // break;
    }

    return 0;
}

