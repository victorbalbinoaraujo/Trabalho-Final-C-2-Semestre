#define T 100 // TAMANHO MÁXIMO DO VETOR

typedef struct Produto *pproduto; // Vetor de Ponteiro
pproduto vProdutos[T]; //Vetor do Ponteiro


void inicializar(); //Null para as posições do ponteiro.

//Solicitar a leitura de dados do teclado para armazenar em uma região da memória
void ler(int p);

//Imprimir os dados de um produto cujo código seja informado
void imprimir(int codigoInf);

//Imprimir todos os dados cadastrados
void ImprimirTodos();
