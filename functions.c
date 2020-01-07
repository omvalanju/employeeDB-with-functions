#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "fh_struct.h"

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

int add(void)
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

int modify(void){
    int seek,x;
    FILE *pointer;

    pointer = fopen("data.txt","r+");

    printf("Enter element Number\n");
    scanf("%d",&x);

    seek = (x-1) * 108;

    fseek(pointer,seek,SEEK_SET);

    printf("Enter Name:");
    scanf("%s",e[x].name);

    printf("Enter Number:");
    scanf("%d",&e[x].number);

    printf("Enter Salary:");
    scanf("%d",&e[x].salary);


    fwrite(&e[x],sizeof(struct employee),1,pointer);
    fclose(pointer);
}


int read(void)
{
    int count_number;
    int x;
    count_number = count();
    FILE *pointer;
    pointer = fopen("data.txt","r");

    for(x=0;x<count_number;x++)
    {
        printf("****************************\n");
        fread (&e[x], sizeof(struct employee), 1, pointer);
        printf ("Name %d = %s\nNumber %d = %d\nSalary %d = %d\n",x+1,e[x].name,x+1,e[x].number,x+1,e[x].salary);
    }

}

