#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "command_handle.h"
#include "resource_control.h"
#include "input.h"
#include "output.h"
int s_comp_with_space(char *s1,char *s2){

    int i,num_of_spcs=0;
    for(i=0;i<strlen(s2);i++)
        if(*(s1+i)!=*(s2+i))
            return *(s1+i)-*(s2+i);
    for(i=strlen(s2);i<strlen(s1);i++)
            if(*(s1+i)!=32)
                num_of_spcs++;
    if(num_of_spcs==0)
        return 0;

}

int num_in_string(char *d){
    int x=1,n=1,sum=0;
        if(*(d+8)>=48&&*(d+8)<=57)
            for(int i=strlen(d)-1;i>=8;i--){
                 x=n*(*(d+i)-48);
                 sum=sum+x;
                 n=n*10;
                 }
        return sum;
}

/*

int num_in_string_with_spcs(char *d){
    int x=1,n=1,sum=0;
        if(*(d+8)>=48&&*(d+8)<=57)
            for(int i=strlen(d)-1;i>=8;i--){
                if((*(d+i)!=' ')&&(*(d+i-1)!=' ')){
                 x=n*(*(d+i)-48);
                 sum=sum+x;
                 n=n*10;
                }
                 }
        return sum+(*(d+8)-48)*n;
}

int s_comp(char *s1,char *s2){
    do{
        if(!*s1) return *s1-*s2;
      }
    while(*s1++==*s2++);
    return *--s1-*--s2;
}
*/
int s_comp_1(char *s1,char *s2){
    int i=-1;
    do{
        if(!*s1) return *s1-*s2;
        i++;
      }
    while((*s1++==*s2++)&&(i!=strlen(s2)-2));

    return *--s1-*--s2;
}

void command_handle(void){
        out_command(1);
        char *c=read_line();
        if(!(s_comp_with_space(c,"exit")))
            return;
        else
        {
           if(!(s_comp_with_space(c,"help")))
            {
                out_command(2);
                command_handle();
            }
            else
            {
                 if(!(s_comp_with_space(c,"-a user")))
                 {
                    add_user();
                    command_handle();
                 }
                else
                {
                    if(!(s_comp_1(c,"-d user 1"))&&(num_in_string(c)<=size_ret())&&(num_in_string(c)>0))
                    {
                        del_user(num_in_string(c));
                        command_handle();
                    }
                    else
                    {
                        if(!(s_comp_with_space(c,"-p user q")))
                        {
                            out_size();
                            command_handle();
                        }
                        else
                        {
                            if(!(s_comp_1(c,"-p user 1"))&&(num_in_string(c)<=size_ret())&&(num_in_string(c)>0))
                            {
                                out_user(num_in_string(c));
                                command_handle();
                            }
                            else
                            {
                                if(!(s_comp_with_space(c,"-p user all")))
                                {
                                    for(int i=1;i<=size_ret();i++)
                                        out_user(i);
                                    command_handle();
                                }
                                else
                                {
                                    if(!(s_comp_with_space(c,"-p user state")))
                                    {
                                        out_size();
                                        for(int i=1;i<=size_ret();i++)
                                            out_user(i);
                                        command_handle();
                                    }
                                    else {
                                        out_command(3);
                                        command_handle();
                                        }
                                }
                            }
                        }
                   }
                }
            }
      }
}
