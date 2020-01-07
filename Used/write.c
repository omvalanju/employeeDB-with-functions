#include <stdio.h>
#include <stdlib.h>
#include "fh_struct.h"
#include "functions.h"

/*int count()
{
    int count_number;

    FILE* count;

    count = fopen("count.txt","r");

    fscanf(count,"%d",&count_number);

    //printf("%d",count_number);

    return count_number;

    fclose(count);
}*/

int main()
{
    int count_number;
    count_number = count();
    FILE *pointer;    

    pointer = fopen("data.txt","a");

    printf("Enter Name:");
    scanf("%s",e[count_number].name);

    printf("Enter Number:");
    scanf("%d",&e[count_number].number);

    printf("Enter Salary:");
    scanf("%d",&e[count_number].salary);

    //name = fopen("name.txt","a");
    //fprintf(name,"%s\n",e.name);
    //fclose(name);

    fwrite(&e[count_number],sizeof(struct employee),1,pointer);
    fclose(pointer);
    count_number = count_number + 1;    

    FILE* count_write;
    count_write = fopen("count.txt","w");
    fprintf(count_write,"%d",count_number);
    fclose(count_write);
   
}
