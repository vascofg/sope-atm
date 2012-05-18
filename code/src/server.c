#include "account.h"
#include "server.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#define MAX_STRING 100
void server_create(struct Server *s, char *accountsFileName,
		char *requestFIFOname) {
	s->accountsFileName = malloc(sizeof(char) * MAX_STRING);
	s->requestsFIFOname = malloc(sizeof(char) * MAX_STRING);
	strcpy(s->accountsFileName, accountsFileName);
	strcpy(s->requestsFIFOname, requestFIFOname);
	mkfifo(s->requestsFIFOname, 0660);

}

/*void server_loadAccounts(struct Server *s) {

}
void server_run(struct Server *s) {

}
void server_saveAccounts(struct Server *s) {

}*/

int server_createAccount(struct Server *s, accountnr_t nr, char *usr, char *pin,
		double initialBalance) {
	struct Account *a = NULL;
	return account_createAutoIncrement(a, usr, pin, initialBalance);
}

int server_deleteAccount(struct Server *s, accountnr_t nr) {
	struct Account *a = server_getAccountbyID(s, nr);
	if (a != NULL)
	{
		a = NULL;
		return 0;
	}
	return 1;
}

double server_getAccountBalance(struct Server *s, accountnr_t nr) {
	struct Account *a = server_getAccountbyID(s, nr);
	if (a != NULL)
	{
		account_getBalance(a);
		return 0;
	}
	return 1;
}

int server_depositAccount(struct Server *s, accountnr_t nr, double amount) {
	struct Account *a = server_getAccountbyID(s, nr);
	if (a != NULL)
	{
		account_deposit(a, amount);
		return 0;
	}
	return 1;
}

/*int server_authAccount(struct Server *s, accountnr_t nr, char *pinGiven) {

}*/

int server_transfer(struct Server *s, accountnr_t source,
		accountnr_t destination, double amount) {
	struct Account *srcacc = server_getAccountbyID(s, source);
	struct Account *destacc = server_getAccountbyID(s, destination);
	if (srcacc != NULL && destacc != NULL
			&& account_getBalance(srcacc) >= amount) {
		account_withdraw(srcacc, amount);
		account_deposit(destacc, amount);
		return 0;
	}
	return 1;

}
int server_witdhdraw(struct Server *s, accountnr_t nr, double amount) {
	struct Account *a = server_getAccountbyID(s, nr);
	if (a != NULL && account_getBalance(a) >= amount) {
		account_withdraw(a, amount);
		return 0;
	}
	return 1;
}

struct Account* server_getAccountbyID(struct Server *s, accountnr_t nr) {
	int i;
	for (i = 0; i < lastAccountNumber; i++)
		if (s->accounts[i] != NULL)
			if (s->accounts[i]->number == nr)
				return s->accounts[i];
	return NULL;
}

int main() {
	struct Account a1;
	if (!account_createAutoIncrement(&a1, "Jojo Carlos", "1234", 11)) {
		printf("Account creation error");
	}
	return 0;
}
