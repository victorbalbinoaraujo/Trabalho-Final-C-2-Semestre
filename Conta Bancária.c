#include <stdio.h>
#include <stdlib.h>

int n_cadastros = 0;

struct Cliente 
{
    char nome[256];
    int cpf;
};

struct Conta
{
    int numero_da_conta;
    struct Cliente cliente;
    float saldo;
};

struct Conta lista[100];
int num_conta = 0;

void cadastro();
void menu(struct Conta conta);
void operacoes(struct Conta conta);
void saldo(struct Conta conta);
void saque(struct Conta *conta, float valor);
void deposito(struct Conta *conta, float valor);
void cadastrados(struct Conta conta);

int main()
{
    printf("\nBem vindo ao Banco! Vamos comecar seu cadastro!\n");
    cadastro();
}

void cadastro()
{
    system("pause");
    system("cls");

    struct Conta conta;

    n_cadastros += 1;
    conta.numero_da_conta = n_cadastros; 
    conta.saldo = 0.0;

    printf("Informe seu nome: ");
    scanf("%s", &conta.cliente.nome);
    printf("Informe seu CPF: ");
    scanf("%d", &conta.cliente.cpf);

    for (int i = 0; i < 100; i++)
    {
        if(conta.cliente.cpf == lista[i].cliente.cpf)
        {
            printf("CPF ja cadastrado! Cadastre com o SEU CPF!\n");
            cadastro();
        }
    }
    
    lista[n_cadastros] = conta;
    menu(conta);
}

void menu(struct Conta conta)
{
    char cc;
    system("cls");
    printf("Deseja fazer uma operacao? [S ou s para sim/N ou n para nao] ");
    printf("Caso nao deseja fazer uma operacao o programa se encerra\n");
    scanf(" %c", &cc);

    if(cc == 'S' || cc == 's')
    {
        operacoes(conta);
    }
    else if(cc == 'N' || cc == 'n')
    {
        exit(0);
    }
    else
    {
        printf("Entrada invalida!");
        menu(conta);
    }
}

void operacoes(struct Conta conta)
{
    system("cls");
    int opcao = 0;
    float valor = 0;

    printf("Que operacao deseja realizar? \n");
    printf("1 - Saldo\n");
    printf("2 - Saque\n");
    printf("3 - Deposito\n");
    printf("4 - Cadastrar nova conta\n");
    printf("5 - Ver contas cadastradas\n");
    scanf("%d", &opcao);
        
    switch(opcao)
    {
        case 1:
            printf("\nOpcao escolhida: Saldo\n");
            printf("Digite o numero da conta: ");
            scanf("%d", &num_conta);
            for(int i = 0; i < 100; i++)
            {
                if(num_conta == lista[i].numero_da_conta)
                {
                    conta = lista[i];
                    saldo(conta);
                }
            }
            break;

        case 2:
            printf("\nOpcao escolhida: Saque\n");
            printf("Digite o numero da conta: ");
            scanf("%d", &num_conta);
            for(int i = 0; i < 100; i++)
            {
                if(num_conta == lista[i].numero_da_conta)
                {
                    conta = lista[i];
                    printf("Digite o valor: ");
                    scanf("%f", &valor);
                    saque(&conta, valor);
                }
            }
            break;

        case 3:
            printf("\nOpcao escolhida: Deposito\n");
            printf("Digite o numero da conta: ");
            scanf("%d", &num_conta);
            for(int i = 0; i < 100; i++)
            {
                if(num_conta == lista[i].numero_da_conta)
                {
                    conta = lista[i];
                    printf("Digite o valor: ");
                    scanf("%f", &valor);
                    deposito(&conta, valor);
                }
            }
            break;
            
        case 4:
            printf("\nOpcao escolhida: Cadastrar nova conta\n");
            cadastro();
            break;

        case 5:
            printf("\nOpcao escolhida: Ver contas cadastradas\n");
            cadastrados(conta);
            break;
            
        default:
            printf("\nOpcao invalida!\nOpcoes validas sao: 1, 2, 3, 4 e 5");
            operacoes(conta);
            break;
    }
}
   
void saldo(struct Conta conta)
{
    
    printf("Seu saldo: R$%.2f\n", conta.saldo);
    system("pause");
    menu(conta);
}

void saque(struct Conta *conta, float valor)
{
    system("cls");
    
    if(conta->saldo >= valor)
    {
        conta->saldo -= valor;
        lista[num_conta].saldo -= valor;
        printf("Saque realizado com sucesso!\n");
        system("pause");
        menu(*conta);
    }
    else
    {
        printf("Saldo insuficiente!\n");
        system("pause");
        menu(*conta);
    }
}

void deposito(struct Conta *conta, float valor)
{
    system("cls");

    if(valor >= 0)
    {
        conta->saldo += valor;
        lista[num_conta].saldo += valor;
        printf("Deposito realizado com sucesso!\n");
        system("pause");
        menu(*conta);
    }
    else
    {
        printf("Valor invalido!\n");
        system("pause");
        menu(*conta);
    }
}

void cadastrados(struct Conta conta)
{
    system("pause");
    system("cls");
    for(int i = 0; i < 100; i++)
    {
        if(lista[i].numero_da_conta != 0)
        {
            printf("Numero da conta: %d\n", lista[i].numero_da_conta);
            printf("Nome: %s\n", lista[i].cliente.nome);
            printf("CPF: %d\n", lista[i].cliente.cpf);
            printf("Saldo: R$%.2f\n\n", lista[i].saldo);
        }
    }
    system("pause");
    menu(conta);
}