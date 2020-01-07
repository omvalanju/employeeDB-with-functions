#include <stdio.h>
#include <stdlib.h>
#include "fh_struct.h"

int main(){
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

