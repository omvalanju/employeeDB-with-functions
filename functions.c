#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"
#include "fh_struct.h"

int count(void)
{   
    int count_number;

    FILE* count; 
    count = fopen("count.txt","r");
    fscanf(count,"%d",&count_number);     
    fclose(count);
  
    return count_number;
}

int add(void)
{
    int count_number,number_length,str_length,i,salary_length;

    count_number = count();

    FILE *pointer;
    pointer = fopen("data.txt","a");

    printf("Enter Name:");
    scanf("%s",e[count_number].name);
    str_length = strlen(e[count_number].name);
  
    for (i=0;i <= str_length;i++)
    {
        if (isdigit((e[count_number].name)[i]));
        {
            printf("Invalid Name\n");
            exit(1);
        }
    }
    

    printf("Enter Number:");
    scanf("%d",&e[count_number].number);
   // number_length = strlen(e[count_number].number);   
  
    /*for (i=0;i <= number_length;i++)
    {
        if (!isdigit((e[count_number].number)[i]));
        {
            printf("Invalid Number\n");
            exit(1);
        }

    } 
   
    if ((e[count_number].number)[i] > 999999999 || (e[count_number].number)[i] < 900000000);
    {
        printf("Invalid Name\n");
        exit(1);
    }*/

    printf("Enter Salary:");
    scanf("%d",&e[count_number].salary);

    //salary_length = strlen(e[count_number].salary);
  
    /*for (i=0;i <= salary_length;i++)
    {
        if (!isdigit((e[count_number].salary)[i]));
        {
            printf("Invalid Salary\n");
            exit(1);
        }
     
    }*/

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


int rmv(void)
{
    int seek,x,count_number,i;
    FILE *pointer;
    count_number = count();
    pointer = fopen("data.txt","r+");

    printf("Enter Element Number\n");
    scanf("%d",&x);

    seek = (x-1) * 108;

    fseek(pointer,seek,SEEK_SET);
    
    for(i=x-1;i<=count_number;i++)
    {
        strcpy(e[i].name,e[i+1].name);
        e[i].number=e[i+1].number;
        e[i].salary=e[i+1].salary;
        fwrite(&e[i],sizeof(struct employee),1,pointer);
    }
    fclose(pointer);
    count_number = count_number - 1;

    FILE* count_write;
    count_write = fopen("count.txt","w");
    fprintf(count_write,"%d",count_number);
    fclose(count_write);
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

