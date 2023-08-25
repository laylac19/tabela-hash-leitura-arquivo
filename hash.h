#ifndef ARQUIVOHASH_H
#define ARQUIVOHASH_H

// Definindo um tipo de dado para armazenar strings de at� 100 caracteres
typedef char string[100];

// Definindo a estrutura para armazenar os dados do aluno
typedef struct tipoDados {
    long long matricula; // N�mero de matr�cula
    string nome; // Nome do aluno
    struct tipoDados *prox; // Ponteiro para o pr�ximo aluno na lista
} TDados;

// Declara��o das fun��es do sistema de gerenciamento de alunos usando tabela hash

// Fun��o para inicializar a tabela hash com NULL
void inicializarTabela(TDados **hash, int tam);

// Fun��o para calcular o tamanho da tabela hash com base em um tamanho inicial
int calcularTam(int tam);

// Fun��o para calcular o tamanho da tabela a partir dos dados de um arquivo
int calcularTamanhoTabela();

// Fun��o para inserir um dado na lista da tabela hash
void inserirDadoLista(TDados **hash, long long matricula, string nomeAluno, int tam);

// Fun��o para inserir um elemento na tabela hash
void insereElemento(TDados **hash, int tam, long long matricula, string nomeAluno);

// Fun��o para adicionar um novo aluno � tabela hash
void adicionarNovoAluno(TDados **hash, int tam);

// Fun��o para ler dados de um arquivo e preencher a tabela hash
void leituraArq(TDados **hash, int tam);

// Fun��o para calcular o m�dulo da matr�cula em rela��o ao tamanho da tabela
int calcularMod(long long matricula, int tam);

// Fun��o para buscar se uma matr�cula est� presente na lista da tabela hash
int buscaLista(TDados **hash, long long matricula, int tam);

// Fun��o para buscar e exibir os detalhes de um aluno na tabela hash
void busca(TDados **hash, long long matricula, int tam);

// Fun��o para percorrer a lista da tabela hash e salvar os dados em um arquivo
void percorreLista(TDados **hash, int pos, FILE *aluno);

// Fun��o para salvar os dados da tabela hash em um arquivo
void salvarArqHash(TDados **hash, int tam);

// Fun��o para obter a matr�cula inserida pelo usu�rio
long long obterMatricula();

// Fun��o para excluir um elemento da tabela hash
void excluirElemento(TDados **hash, long long matricula, int tam);

// Fun��o para imprimir os elementos de uma lista da tabela hash
void imprimirElementosLista(TDados *lista);

// Fun��o para exibir a lista completa da tabela hash
void exibirLista(TDados **hash, int tam);

// Fun��o para liberar a mem�ria alocada para a tabela hash
void liberarMemoria(TDados **hash, int tam);

// Fun��o para executar a a��o escolhida no menu
void executarAcaoMenu(TDados **hash, int num, int tam);

// Fun��o para exibir o menu principal e realizar opera��es na tabela hash
void exibirMenu(TDados **hash, int tam);

#endif

