#define T 100 // TAMANHO M�XIMO DO VETOR

typedef struct Produto *pproduto; // Vetor de Ponteiro
pproduto vProdutos[T]; //Vetor do Ponteiro


void inicializar(); //Null para as posi��es do ponteiro.

//Solicitar a leitura de dados do teclado para armazenar em uma regi�o da mem�ria
void ler(int p);

//Imprimir os dados de um produto cujo c�digo seja informado
void imprimir(int codigoInf);

//Imprimir todos os dados cadastrados
void ImprimirTodos();
