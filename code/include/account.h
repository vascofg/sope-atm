/**
	Authors: - André Freitas p.andrefreitas@gmail.com
	 	 	 - Vasco Gonçalves vascofg@gmail.com
	Copyright: 2012, Faculdade de Engenharia da Universidade do Porto
 */
#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <stdbool.h>
/** A struct for holding the information of a Bank Account.
 */

typedef short unsigned pin_t; /* the pin type */
typedef int unsigned accountnr_t; /* the account number type */

struct Account {
	accountnr_t number; /* The number that starts from 0 (not the NIB standard) */
	char *user; /* the name of the user of the Account */
	pin_t pin; /* the 4 digits pin */
	double balance; /* the money balance */
};

/** Does a deposit of money from an account
 * @param *a the pointer for the account struct
 * @param ammount the money to deposit
 */
void account_deposit(struct Account *a, double amount);

/** Withdraw money from an account
 * @param *a the pointer for the account struct
 * @param ammount the money to deposit
 * @return 0 if success
 */
bool account_withdraw(struct Account *a, double amount);

/** Get the balance from an account
 * @param *a the pointer for the account struct
 * @return a double
 */
double account_getBalance(struct Account *a);

/** Get the char pointer of the account information.
 * Can be useful to write in the files.
 * @param *a the pointer for the account struct
 * @return a char pointer
 */
char * account_toString(struct Account *a);

#endif /* ACCOUNT_H_ */
