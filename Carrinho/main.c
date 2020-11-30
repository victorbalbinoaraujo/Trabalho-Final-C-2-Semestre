#include <stdio.h>
#include <stdlib.h>
#include "produto.h"

int main()
{

    int p = 0;
    int codigoInf = 0;
    int opc = 0;

    inicializar();

    do{
        system("cls");
        printf("                                          ---------------------------------------\n");
        printf("                                         |          BOTECO DOS FATECANO'S        |\n");
        printf("                                         |              Menu Principal           |\n");
        printf("                                         |---------------------------------------|\n");
        printf("                                         |1-  Adicionar Produto no Carrinho      |\n");
        printf("                                         |2-  Buscar Produtos                    |\n");
        printf("                                         |3-  Carrinho de Compras                |\n");
        printf("                                         |4-  Quantidade de Produtos Registrados |\n");
        printf("                                         |5-  Sair do Programa                   |\n");
        printf("                                         ---------------------------------------\n\n");
        printf("                                                    Digite a opcao: ");
        scanf("%d", &opc);

        switch(opc){

    case 1:
        system("cls");
        ler(p);
        p++;
        break;

    case 2:
        system("cls");
        fflush(stdin);
        printf("Digite o Codigo do Produto: \n");
        scanf("%d", &codigoInf);
        imprimir(codigoInf);
        break;

    case 3:
        system("cls");
        ImprimirTodos();
        break;

    case 4:
        system("cls");
        printf("Quantidade de Produtos Registrados: %d \n", p);
        system("pause");

    case 5:
        system("cls");
        printf("                                          ----------------------------------------\n");
        printf("                                         |          BOTECO DOS FATECANO'S         |\n");
        printf("                                         |                AGRADECE                |\n");
        printf("                                         |           PROGRAMA FINALIZADO          |\n");
        printf("                                         |                                        |\n");
        printf("                                         |            Desenvolvido por:           |\n");
        printf("                                         |   Amanda Alexandre - Leticia Nobrega   |\n");
        printf("                                         |       Lucas Santos - Pedro Moreno      |\n");
        printf("                                         |    Valeska Milioni - Victor Araujo     |\n");
        printf("                                         |                                        |\n");
        printf("                                         |            FATEC MOGI MIRIM            |\n");
        printf("                                          --------------------------------------- \n");
        break;

    default:
        system("cls");
        printf("ERROR - Opcao inexistente! \n");
        system("pause");
        }
    }while(opc != 5);

    return 0;
}
