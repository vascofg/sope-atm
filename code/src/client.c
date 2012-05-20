#include <stdio.h>

int show_menu()
{
	int opt;
	printf("CLIENTE DE MULTIBANCO\n-----------------------\n1 - Levantar dinheiro\n2 - Depositar dinheiro\n3 - Transferência\n4 - Consultar Saldo\n5 - Sair\n");
	scanf("%d", &opt);
	switch(opt)
	{
	case 5:
		return 0;
	}
	return 1;
}

//TODO SEPARATE TO A DIFFERENT APPLICATION
/*int main()
{
	do {
	} while (show_menu());
	return 0;
}
*/
