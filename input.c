#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "resource_control.h"
#include "input.h"

char  *read_name(void){
read_line();
}

char * read_pass(void){
    char* str = NULL;
    char c;
    int leng = 0;
    while((c=getch()) != '\r') {
        if(c == '\b') {
            if(leng != 0) {
                str = realloc(str, --leng);
                printf("\b \b");
            }
        }
        else {
            printf("*");
            str = realloc(str, ++leng);
            str[leng-1] = c;
        }
    }
    str = realloc(str, ++leng);
    str[leng-1] = '\0';
    return str;
}


char * read_line(void){
    char *ln=NULL,g;
    int i=0;
    do{
        g=getchar();
        ln=realloc(ln,i+1);
        *(ln+i)=g;
        i++;
    }
    while(g!='\n');
    *(ln+i-1)='\0';
    return ln;
}
