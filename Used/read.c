#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fh_struct.h"
#include "functions.h"

int main()
{
    int count_number;
    int x;
    count_number = count();
    FILE *pointer;
    pointer = fopen("data.txt","r");

    for(x=0;x<count_number;x++)
    {
        fread (&e[x], sizeof(struct employee), 1, pointer);
        printf ("Name %d = %s   Number %d = %d   Salary %d = %d\n",x+1,e[x].name,x+1,e[x].number,x+1,e[x].salary);
    }
}
