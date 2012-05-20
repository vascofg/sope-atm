#include <stdio.h>

int show_menu()
{
	int opt;
	printf("ADMINISTRADOR DE MULTIBANCO\n--------------------------\n1 - Criar Nova Conta\n2 - Listar Contas\n3 - Eliminar Conta\n4 - Encerrar Servidor\n5 - Sair\n");
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
