#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "fh_struct.h"

int main()
{
   int op;
    
    
   enum op{Add=1, Remove=2, Update=3, Exit=5, Read=4};
    

   for (;;)
   {
       printf("Select Operation:\n1.Add\n2.Remove\n3.Update\n4.Display Data\n5.Exit\nEnter Operation number:");

       scanf("%d",&op);
       printf("**************************\n");

       if (op>5)
       {
           printf("Invalid Operation");
           continue;
       }
       else
           switch(op)
           {
               case Add:
                   add();
                   read();
                   break;

               case Remove:
                   rmv();
                   read();
                   break;

               case Update:
                   modify();
                   read();
                   break;

               case Read:
                   read();
                   break;
                 
               case Exit:
                   exit(0);
            }

}
}

