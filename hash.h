#ifndef ARQUIVOHASH_H
#define ARQUIVOHASH_H

// Definindo um tipo de dado para armazenar strings de até 100 caracteres
typedef char string[100];

// Definindo a estrutura para armazenar os dados do aluno
typedef struct tipoDados {
    long long matricula; // Número de matrícula
    string nome; // Nome do aluno
    struct tipoDados *prox; // Ponteiro para o próximo aluno na lista
} TDados;

// Declaração das funções do sistema de gerenciamento de alunos usando tabela hash

// Função para inicializar a tabela hash com NULL
void inicializarTabela(TDados **hash, int tam);

// Função para calcular o tamanho da tabela hash com base em um tamanho inicial
int calcularTam(int tam);

// Função para calcular o tamanho da tabela a partir dos dados de um arquivo
int calcularTamanhoTabela();

// Função para inserir um dado na lista da tabela hash
void inserirDadoLista(TDados **hash, long long matricula, string nomeAluno, int tam);

// Função para inserir um elemento na tabela hash
void insereElemento(TDados **hash, int tam, long long matricula, string nomeAluno);

// Função para adicionar um novo aluno à tabela hash
void adicionarNovoAluno(TDados **hash, int tam);

// Função para ler dados de um arquivo e preencher a tabela hash
void leituraArq(TDados **hash, int tam);

// Função para calcular o módulo da matrícula em relação ao tamanho da tabela
int calcularMod(long long matricula, int tam);

// Função para buscar se uma matrícula está presente na lista da tabela hash
int buscaLista(TDados **hash, long long matricula, int tam);

// Função para buscar e exibir os detalhes de um aluno na tabela hash
void busca(TDados **hash, long long matricula, int tam);

// Função para percorrer a lista da tabela hash e salvar os dados em um arquivo
void percorreLista(TDados **hash, int pos, FILE *aluno);

// Função para salvar os dados da tabela hash em um arquivo
void salvarArqHash(TDados **hash, int tam);

// Função para obter a matrícula inserida pelo usuário
long long obterMatricula();

// Função para excluir um elemento da tabela hash
void excluirElemento(TDados **hash, long long matricula, int tam);

// Função para imprimir os elementos de uma lista da tabela hash
void imprimirElementosLista(TDados *lista);

// Função para exibir a lista completa da tabela hash
void exibirLista(TDados **hash, int tam);

// Função para liberar a memória alocada para a tabela hash
void liberarMemoria(TDados **hash, int tam);

// Função para executar a ação escolhida no menu
void executarAcaoMenu(TDados **hash, int num, int tam);

// Função para exibir o menu principal e realizar operações na tabela hash
void exibirMenu(TDados **hash, int tam);

#endif

