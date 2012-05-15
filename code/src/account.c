#include "account.h"

void account_deposit(struct Account *a, double amount) {
	a->balance += amount;
}
bool account_withdraw(struct Account *a, double amount) {
	if (a->balance < amount)
		return false;
	return true;
}
double account_getBalance(struct Account *a){
	return a->number;
}
