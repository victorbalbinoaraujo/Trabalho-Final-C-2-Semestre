#include <stdio.h>
#include <stdlib.h>
#include "produto.h"

struct Produto{
    double codigo;
    char nome[51];
    double valor;
};

void inicializar(){
    int i;
    for(i = 0; i < T; i++){
        vProdutos[i] = NULL;
    }
}

void ler(int p){
    if(p==T){
        printf("- Estoque dos Fatecanos cheio  \n");
        system("pause");
        return;
    }
    //Alocar dinamicamente um espaço de memoria para o dado e ligar ao ponteiro
    vProdutos[p] = (pproduto) malloc(sizeof (struct Produto));
    fflush(stdin);
    printf("Digite o Codigo do Produto: \n");
    scanf("%lf", &vProdutos[p]->codigo);
    fflush(stdin);
    printf("Digite o Nome do Produto: \n");
    gets(vProdutos[p]->nome);
    fflush(stdin);
    printf("Digite o Valor do Produto: \n");
    scanf("%lf", &vProdutos[p]->valor);
    printf("Produto Cadastrado com Sucesso! \n");
    system("pause");
}

void imprimir(int codigoInf){
    int i;
    for(i = 0; i < T; i++){
        if(vProdutos[i] != NULL){
            if(vProdutos[i]->codigo == codigoInf){
                system("cls");
                printf("            Produto Encontrado \n");
                printf("------------------------------------------------\n");
                printf("%.lf %s   R$%.2lf \n\n", vProdutos[i]->codigo, vProdutos[i]->nome, vProdutos[i]->valor);
                system("pause");
                return;
                }
        }
    }
    system("cls");
    printf("- Produto nao Encontrado\n");
    system("pause");
}

void ImprimirTodos(){
    int i;
    double soma;
    system("cls");
    for(i = 0; i < T; i++){
        if(vProdutos[i] != NULL){
                printf("%.lf\t %s\t\tR$%.2lf \t \n", vProdutos[i]->codigo, vProdutos[i]->nome, vProdutos[i]->valor);
                soma = soma + vProdutos[i]->valor;
            }
    }
    printf("\n");
    printf("Total da Compra: R$%.2f\n\n", soma);
    system("pause");
}

