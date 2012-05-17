/**
 Authors: - André Freitas p.andrefreitas@gmail.com
 - Vasco Gonçalves vascofg@gmail.com
 Copyright: 2012, Faculdade de Engenharia da Universidade do Porto
 */
#ifndef SERVER_H_
#define SERVER_H_
#include "account.h"
/** A struct for defining a server that handles multibanco accounts requests.
 */
struct Server {
	char *accountsFileName; /* The name where the accounts data is saved */
	char *requestsFIFOname; /* The name of the requests fifo */
	struct Account **accounts; /* The list of accounts */
};

void server_create(struct Server *s, char *accountsFileName,
		char *requestFIFOname);
void server_loadAccounts(struct Server *s);
void server_run(struct Server *s);
void server_saveAccounts(struct Server *s);
int server_createAccount(struct Server *s, accountnr_t nr, char *usr, char *pin,
		double initialBalance);
int server_deleteAccount(struct Server *s, accountnr_t nr);
double server_getAccountBalance(struct Server *s, accountnr_t nr);
int server_depositAccount(struct Server *s, double amount);
int server_authAccount(struct Server *s, accountnr_t nr, char *pinGiven);
int server_transfer(struct Server *s, accountnr_t source,
		accountnr_t destination, double amount);
int server_witdhdraw(struct Server *s, accountnr_t nr, double amount);

#endif /* SERVER_C_ */
