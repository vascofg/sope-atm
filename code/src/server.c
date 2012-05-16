#include "account.h"
#include <stdio.h>
#include <stdlib.h>
int main(){
	struct Account a1;
	if(!account_createAutoIncrement(&a1,"Jojo Carlos","1234",11)){
		printf("Account creation error");
	}


	printf("%s\n", account_toString(&a1));


	struct Account a2;
		if(!account_createAutoIncrement(&a2,"Maria","asba",0)){
			printf("Account creation error");
		}

	printf("%s\n", account_toString(&a2));

	account_resetLastAccountNumber();

	struct Account a3;
	if(!account_createAutoIncrement(&a3,"Joso Carlos","1234",10000000)){
		printf("Account creation error");
	}

	printf("%s\n", account_toString(&a3));
	return 0;
}
