#include <stdio.h>
#include <string.h>
#include "StrList.h"

int main() {
    int choice = scanf("%d", &choice);

    switch (choice) {
    case 0:
        break;
    case 1:
        int num_of_elements = scanf("%d", &num_of_elements);
        printf("Allocating a new StrList\n");
        StrList* list = StrList_alloc();
        printf("Write your string\n");
        char* string = scanf("%s", string);
        int i = num_of_elements;
        while (i) {
            char str[] = "";
            while(*string != " ") {
                char str1 = *string;
                strcat(str,str1);
            }
            i--;
            StrList_insertLast(list, string);
        }
        break;
    case 2:
        printf("Enter an index\n");
        int index = scanf("%d", &index);
        printf("Enter a string %d\n", index);
        char* str = scanf("%s", str);
        StrList_insertAt(list, index, str);
        break;
    case 3:
        StrList_print(list);
        break;
    case 4:
        printf(StrList_size(list));
        break;
    case 5:
        printf("Enter an index\n");
        int index = scanf("%d", &index);
        StrList_printAt(list, index);
        break;
    case 6:
        printf("The amount of chars in the string is: %d", StrList_printLen(list));
        break;
    case 7:
        printf("Enter a string\n");
        char* str = scanf("%s", str);
        printf("The amount of times the string appears in the list is: %d", StrList_count(list, str));
        break;
    case 8:
        printf("Enter a string\n");
        char* str = scanf("%s", str);
        StrList_remove(list, str);
        break;
    case 9:
        printf("Enter an index\n");
        int index = scanf("%d", &index);
        StrList_removeAt(list, index);
        break;
    case 10:
        StrList_reverse(list);
        break;
    case 11:
        StrList_free(list);
        break;
    case 12:
        if (!StrList_isSorted(list)) {
            StrList_sort(list);
        }
        break;
    case 13:
        if(StrList_isSorted(list)) {
            printf("The list is sorted\n");
        }
        else {
            printf("The list is not sorted\n");
        }
        break;
    }

    return 0;
}