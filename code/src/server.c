#include "account.h"
#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#define MAX_STRING 100
void server_create(struct Server *s, char *accountsFileName,
		char *requestFIFOname){
	s->accountsFileName= malloc(sizeof(char)*MAX_STRING);
	s->requestsFIFOname= malloc(sizeof(char)*MAX_STRING);
	strcpy(s->accountsFileName,accountsFileName);
	strcpy(s->requestsFIFOname,requestFIFOname);
	mkfifo(s->requestsFIFOname,0660);

}
int main(){
	struct Account a1;
	if(!account_createAutoIncrement(&a1,"Jojo Carlos","1234",11)){
		printf("Account creation error");
	}
	return 0;
}
