#include <stdio.h>
#include <stdlib.h>
#include "resource_control.h"
#include "input.h"
#include "output.h"

struct user
{
    char *name;
    char *password;
    int id;
};
int size=0;
struct user *person;

char* person_name(int n) {
    return person[n].name;
}

char* person_pass(int n) {
    return person[n].password;
}

int person_id(int n) {
    return person[n].id;
}

int gen_id(int x) {
    return x*1648+1648%x;
}

int quant_users(void) {
    return size;
}

void set_name(int n){
    person[n].name=read_name();
}

void set_pass(int n){
    person[n].password = read_pass();
}

void set_id(int n){
    person[n].id=gen_id(n+1);
}

int size_ret(void){
return size;
}

void add_user() {
        person=realloc(person,sizeof(struct user)*(size+1));
        size++;
        out_command(4);
        set_name(size-1);
        out_command(5);
        set_pass(size-1);
        set_id(size-1);
        out_command(6);
}

void del_user(int n){
    free(person[n-1].name);
    free(person[n-1].password);
    for(int i=n-1;i<size-1;i++)
        person[i]=person[i+1];
        size--;
    person = realloc(person,(size+1)*sizeof(struct user));
    out_command(7);
}
