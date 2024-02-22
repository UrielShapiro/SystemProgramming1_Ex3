#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "StrList.h"

char* inputString()
{
    char* str = (char*)malloc(sizeof(char));
    *str = '\0';          
    char c=getchar();
    while (c !=' '&& c != '\n')
    {
        size_t size = strlen(str);
        str = (char*)realloc(str, size+ 2 * sizeof(char));
        str[size]=c;
        str[size+1]='\0';
        c = getchar();
    }
    return str;
}


StrList* scanList(StrList* list)
{
    int num_of_elements;
    scanf("%d", &num_of_elements);
    getchar();               //to clear the buffer from the space after entering the number of elements.
    while(num_of_elements > 0)
    {
        char* str = inputString();
        num_of_elements--;
        StrList_insertLast(list, str);
    }
    return list;
}
void insertAt(StrList* list)
{
    int index;
    scanf("%d", &index);
    size_t size = StrList_size(list);
    if(index > size+1)
    {
        printf("error! can't insert to this index because it's out of range\n");
        return;
    }
    char* str = inputString();
    StrList_insertAt(list, str, index);
}

int main() {
    int choice;
    StrList* list = StrList_alloc();
    scanf("%d", &choice);
    while (choice!=0)
    {
       switch (choice) {
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
            printf("%ld\n", StrList_size(list));
            break;
        case 5:
            int index_5;
            scanf("%d", &index_5);
            if(index_5 > StrList_size(list))
            {
                printf("error! can't print at this index because it's out of range\n");
                break;
            }
            StrList_printAt(list, index_5);
            break;
        case 6:
            printf("%d\n", StrList_printLen(list));
            break; 
        case 7:
            printf("Enter a string\n");
            char* str_7 = inputString();
            printf("The amount of times the string appears in the list is: %d\n", StrList_count(list, str_7));
            break;
        case 8:
            printf("Enter a string: \n");
            const char* str_8 = inputString();
            StrList_remove(list, str_8);
            StrList_print(list);
            break;
        case 9:
            int index_9;
            scanf("%d", &index_9);
            // if(index_9 <= StrList_size(list))
            // {
                StrList_removeAt(list, index_9);
            // }
            break;
        case 10:
            StrList_reverse(list);
            break;
        case 11:
            StrList_free(list);
            StrList_print(list);
            printf("The list is free\n");
            break;
        case 12:
            StrList_sort(list);
            StrList_print(list);
            break;
        case 13:
            if(StrList_isSorted(list)) {
                printf("true\n");
            }
            else {
                printf("false\n");
            }
            break;

        }
        scanf("%d", &choice);
    }
     return 0;

}