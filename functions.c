#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"
#include "fh_struct.h"


int intcheck(int num)
{
    int i,str_length;
    char buffer[50];
    sprintf(buffer,"%d",num);
    int x = 0;

    str_length = strlen(buffer);

    for (i=0;i<=str_length-1;i++)
    {
        if (isdigit(buffer[i]))
        {
            continue;
        }
        else
        {
            x = 1;
            return x;
        }
    }
    return x;
}


int countdig(long int num)
{
    int count = 0;

    while(num != 0)
    {
        count = count + 1;
        num /= 10;
    }
    //printf("%d",count);
    return count;
}

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
    int str_length,number_length,i,count_number,countd,check;
    count_number = count();
    FILE *pointer;

    pointer = fopen("data.txt","a");

    name:
        printf("Enter Name:");
        scanf("%s",e[count_number].name);
        str_length = strlen(e[count_number].name);
       // printf("%d",str_length);

    for (i=0;i<=str_length;i++)
    {
        if (isdigit(e[count_number].name[i]))
        {
            printf("Invalid Name.Enter again\n");
            goto name;
        }
    }

    number:
        printf("Enter Number:");
        scanf("%li",&e[count_number].number);
    
    countd = countdig(e[count_number].number);
    printf("%d",countd); 
    if (countd = 10)
    {
        printf("valid Number\n");
        goto number;
    }
    
    check = intcheck(e[count_number].number);
    
    if (check != 10)
    {
        printf("Invalid Number\n");
        goto number;
    }
  
    salary:
        printf("Enter Salary:");
        scanf("%d",&e[count_number].salary);

    check = intcheck(e[count_number].salary);
    
    if(check != 0)
    {
        // printf("Not Int");
         printf("Invalid Salary\n");
         goto salary;

    }

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
    scanf("%li",&e[x].number);

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
        printf ("Name %d = %s\nNumber %d = %li\nSalary %d = %d\n",x+1,e[x].name,x+1,e[x].number,x+1,e[x].salary);
    }

}

