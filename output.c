#include <stdio.h>
#include <stdlib.h>
#include "resource_control.h"

void out_command(int n)
{
    if(n==1)
    {
       printf(">");
       return;
    }
    if(n==2)
    {
        printf("print: prints the asked information after flag '-p'\n");
        printf("       -p [struct][info_type]\n       [struct] may be       1)user\n");
        printf("       [info_type] may be    1)all - all struct\n                             2)q - quantity\n                             3)'N' - struct num (integer)\n\n                             4)state\n\n");
        printf("add: adds a new user after the flag '-a'\n     -a user\n");
        printf("del: deletes a user with the number N after the flag '-d'\n     -d user N\n");
    }
    if(n==3)
        printf("Error - wrong command input or user does not exist, type help to know the commands\n");
    if(n==4)
        printf("Name:");
    if(n==5)
        printf("Password:");
    if(n==6)
        printf("\nUser added successfully\n");
    if(n==7)
        printf("\nUser deleted successfully\n");
    if(n==8)
        printf("Error: user does not exist\n");

}

void out_size(void){
    printf("Users current quantity:%d\n",size_ret());
}

void out_user(int n){
         printf("User %d:\n       Name:%s\n       Password:%s\n       id:%d\n",n,person_name(n-1),person_pass(n-1),person_id(n-1));
}
