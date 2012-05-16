#include "account.h"
#include <stdio.h>
#include <stdlib.h>
int main(){
	struct Account a1;
	if(!account_create(&a1,1,"João Carlos","1234",11)){
		printf("Account creation error");
	}
	printf("%s\n", account_toString(&a1));

	return 0;
}
