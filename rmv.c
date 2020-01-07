#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "fh_struct.h"
#include <string.h>


int count(void)
{
    int count_number;

    FILE* count;

    count = fopen("count.txt","r");

    fscanf(count,"%d",&count_number);

    //printf("%d",count_number);

    fclose(count);

    return count_number;
}



int main(void)
{
    int count_number;
    int del,x;

    FILE *pointer;
    pointer = fopen("data.txt","w");

    count_number = count();
    printf("Enter Element number to delete:");
    scanf("%d",&del);

    if (del>count_number)
        printf("Entry does not exist");

    else

        for(x=del-1;x<=count_number-1;x++)
        {
            strcpy(e[x].name,e[x+1].name);
            e[x].number=e[x+1].number;
            e[x].salary=e[x+1].salary;
        }
         
         fclose(pointer);

         count_number = count_number - 1;
         
         FILE* count_write;
         count_write = fopen("count.txt","w");
         fprintf(count_write,"%d",count_number);
         fclose(count_write);         
} 

