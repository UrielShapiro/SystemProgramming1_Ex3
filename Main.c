#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StrList.h"

char* inputString()
{
    char* str = (char*)malloc(sizeof(char));
    *str = '\0';
    getchar();
    char c=getchar();
    while (c !=' '&& c != '\n')
    {
        size_t size = strlen(str);
        str = (char*)realloc(str, size+2);
        str[size]=c;
        str[size+1]='\0';
        c = getchar();
    }
    return str;
}


StrList* scanList(StrList* list)
{
    int num_of_elements;
    printf("Enter the number of elements: \n");
    scanf("%d", &num_of_elements);
    printf("Write your string: \n");
    char c=getchar();               //to clear the buffer from the space after entering the number of elements.
    while(num_of_elements > 0)
    {
        char* str = (char*)malloc(sizeof(char));
        *str = '\0';
        c = getchar();
        while(c != ' ' && c !='\n'&& c!= EOF)
        {
                size_t size = strlen(str);
                str = (char*)realloc(str, size+2);
                str[size]=c;
                str[size+1]='\0';
                c = getchar();

        }
        num_of_elements--;
        StrList_insertLast(list, str);
    }
    return list;
}
void insertAt(StrList* list)
{
    printf("Enter an index\n");
    int index;
    scanf("%d", &index);
    size_t size = StrList_size(list);
    if(index > size+1)
    {
        printf("error! can't insert to this index because it's out of range\n");
        return;
    }
    printf("Enter a string\n");
    char* str = inputString();
    StrList_insertAt(list, str, index);
}

int main() {
    printf("please enter a number: \n");
    int choice;
    StrList* list = StrList_alloc();
    printf("Allocated the list\n");
    scanf("%d", &choice);
    while (choice!=0)
    {
       switch (choice) {
        case 1:
            scanList(list);
            printf("case 1 is working\n");
            break;
        case 2:
            insertAt(list);
            printf("case 2 is working\n");
            break;
        case 3:
            StrList_print(list);
            printf("case 3 is working\n");
            break;
        case 4:
            printf("The size of the list is: %ld\n", StrList_size(list));
            printf("case 4 is working\n");
            break;
        case 5:
            printf("Enter an index\n");
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
            printf("The amount of chars in the string is: %d\n", StrList_printLen(list));
            break; 
        case 7:
            printf("Enter a string\n");
            char* str_7 = inputString();
            printf("The amount of times the string appears in the list is: %d\n", StrList_count(list, str_7));
            break;
        case 8:
            printf("Enter a string: \n");
            char* str_8 = inputString();
            StrList_remove(list, str_8);
            break;
        }
        scanf("%d", &choice);
    }

    // case 9:
    //     printf("Enter an index\n");
    //     int index_9;
    //     scanf("%d", &index_9);
    //     StrList_removeAt(list, index_9);
    //     break;
    // case 10:
    //     StrList_reverse(list);
    //     break;
    // case 11:
    //     StrList_free(list);
    //     break;
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
     return 0;

}