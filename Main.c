#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "StrList.h"
/*
This function is used to input a string from the user.
It reads the string character by character and stores it in a dynamically allocated array.
It returns a pointer to the array which stores the string.
*/
char* inputString()
{
    char* str = (char*)malloc(sizeof(char));
    *str = '\0';
    char c=getchar();
    while (c !=' '&& c != '\n') //Read the string character by character until a space or a new line is entered.
    
    {
        size_t size = strlen(str);
        str = (char*)realloc(str, size + 2 * sizeof(char)); //Reallocate memory for the string to store the new character.
        str[size]=c;
        str[size+1]='\0';   //Add the null terminator at the end of the string.
        c = getchar();
    }
    return str;
}
/*
This function is used to scan a list of strings from the user for case 1.
*/
StrList* scanList(StrList* list)
{
    int num_of_elements;      //The number of elements to be scanned.
    scanf("%d", &num_of_elements);
    getchar();               //to clear the buffer from the space after entering the number of elements.
    while(num_of_elements > 0)
    {
        char* str = inputString();  //Input a string from the user.
        num_of_elements--;
        StrList_insertLast(list, str);  //Insert the string at the end of the list.
        free(str);  //Free the string after inserting it in the list (because it's already deep copied to the list).
    }
    return list;
}
/*
This function is used to insert a string at a specific index in the list for case 2.
*/
void insertAt(StrList* list)
{
    int index;  //The index at which the string will be inserted.
    scanf("%d", &index);
    getchar();              //To clear the buffer from unintended space.
    size_t size = StrList_size(list);
    if(index > size+1)
    {
        printf("error! can't insert to this index because it's out of range\n");
        return;
    }
    char* str = inputString();          //Input the string to be inserted.
    StrList_insertAt(list, str, index); //Insert the string at the specified index.
    free(str);                          //Free the string after inserting it in the list (because it's already deep copied to the list).
}

int main() {
    int choice;
    StrList* list = StrList_alloc();    //Allocating memory for the list.
    scanf("%d", &choice);
    while (choice != 0)
    {
       switch (choice) {
        case 1:
            if (list == NULL)   //If the list was freed, allocate memory for it again.
            {
                list = StrList_alloc();
            }
            scanList(list);
            break;
        case 2:
            insertAt(list);
            break;
        case 3:
            if(list != NULL)
            {
                StrList_print(list);
            }
            else               //If the list is empty, print a new line (as required by the tests).
            {
                printf("\n");
            }
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
            getchar();      //To clear the buffer from the space after entering the string.
            char* str_7 = inputString();
            printf("%d\n", StrList_count(list, str_7));
            free(str_7);    //Free the string after counting it in the list.
            break;
        case 8:
            const char* str_8 = inputString();  //The string to be removed (const char* because thats the type of the function's parameter).
            StrList_remove(list, str_8);
            free((char*)str_8);     //Free the string after removing it from the list.
            break;
        case 9:
            int index_9;
            scanf("%d", &index_9);
            if(index_9 <= StrList_size(list))   //If the index is out of range, don't remove anything.
            {
                StrList_removeAt(list, index_9);
            }
            break;
        case 10:
            StrList_reverse(list);
            break;
        case 11:
            StrList_free(list);
            list = NULL;    //Set the list pointer to null after freeing it. Will be used to check if the list was freed.
            break;
        case 12:
            StrList_sort(list);
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
        scanf("%d", &choice);   //Scan the next choice.
    }
    if(list != NULL)    //If the list was not freed, free it before the program ends.
    {
        StrList_free(list);
    }
    return 0;
}