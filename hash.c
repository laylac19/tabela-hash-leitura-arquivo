#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash.h"

// Fun��o para inicializar a tabela hash com valores nulos
void inicializarTabela(TDados **hash, int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        hash[i] = NULL;
    }
}

// Fun��o para calcular o tamanho da tabela hash a partir de um tamanho base
int calcularTam(int tam) {
    float metade = (float)(tam / 2) * 1.5; // Calcula 1.5 vezes o tamanho base
    return metade;
}

// Fun��o para calcular o tamanho da tabela a partir de um arquivo de alunos
int calcularTamanhoTabela() {
    int i = 0, size = 0;
    char vetor[100], parag = '\n';
    FILE *aluno;
    aluno = fopen("lista_matricula_alunos_2023.txt", "r");
    // Verifica se o arquivo foi aberto com sucesso
    if (!aluno)
        printf("\nErro na abertura do arquivo 'lista_matricula_alunos_2023.txt'");
    else {
        // L� o arquivo linha por linha
        while (fgets(vetor, sizeof(vetor), aluno)) {
            if (strlen(vetor) > 1) {
                size++; // Conta as linhas n�o vazias (representando alunos)
            }
        }
        size++; // Incrementa para incluir a �ltima linha vazia
        fclose(aluno);
    }
    size = calcularTam(size); // Calcula o tamanho final da tabela
    return size;
}

// Fun��o para inserir um dado na lista da tabela hash
void inserirDadoLista(TDados **hash, long long matricula, string nomeAluno, int tam) {
    int pos = calcularMod(matricula, tam); // Calcula a posi��o na tabela hash
    TDados **lista = &hash[pos];

    if (*lista == NULL) {
        *lista = (TDados *)malloc(sizeof(TDados)); // Aloca mem�ria para o novo elemento
        if (*lista == NULL) {
            printf("\nErro na alocacao da memoria!");
            return;
        }
        strcpy((*lista)->nome, nomeAluno);
        (*lista)->matricula = matricula;
        (*lista)->prox = NULL;
    } else {
        TDados *armazena = hash[pos];
        while ((*lista)->prox != NULL)
            *lista = (*lista)->prox;
        (*lista)->prox = (TDados *)malloc(sizeof(TDados)); // Aloca mem�ria para o novo elemento
        if ((*lista)->prox == NULL) {
            printf("\nErro na alocacao da memoria!");
            return;
        }
        *lista = (*lista)->prox;
        strcpy((*lista)->nome, nomeAluno);
        (*lista)->matricula = matricula;
        (*lista)->prox = NULL;
        hash[pos] = armazena;
    }
}

// Fun��o principal que insere um novo elemento na tabela hash
void insereElemento(TDados **hash, int tam, long long matricula, string nomeAluno) {
    int posicao = calcularMod(matricula, tam);
    if (hash[posicao] != NULL) {
        if (buscaLista(hash, matricula, tam)) {
            printf("\nMatricula ja cadastrada: %lld - %s\n", matricula, nomeAluno);
            return;
        }
    }
    inserirDadoLista(hash, matricula, nomeAluno, tam);
}

// Fun��o para adicionar um novo aluno na tabela hash
void adicionarNovoAluno(TDados **hash, int tam) {
    string nomeAluno;
    long long matricula;
    getchar(); // Limpa o buffer do teclado
    printf("\nInsira o nome: ");
    fgets(nomeAluno, sizeof(nomeAluno), stdin); // L� o nome do aluno
    printf("\nInsira a matricula: ");
    scanf("%lld", &matricula); // L� a matr�cula do aluno
    insereElemento(hash, tam, matricula, nomeAluno);
}

// Fun��o para ler os dados de um arquivo e inserir na tabela hash
void leituraArq(TDados **hash, int tam) {
    long long matricula;
    string nomeAluno;
    FILE *aluno;
    
    printf("Abrindo arquivo para leitura...\n");
    
    aluno = fopen("lista_matricula_alunos_2023.txt", "r"); // Abre o arquivo para leitura
    if (!aluno) {
        printf("\nErro na abertura do arquivo 'lista_matricula_alunos_2023.txt'");
    } else {
        printf("Lendo dados do arquivo...\n");
        
        while (!feof(aluno)) { // Enquanto n�o for o fim do arquivo
            if (fscanf(aluno, "%lld", &matricula)) { // L� a matr�cula
                fgetc(aluno); // Consumir o caractere '\n' ap�s a leitura da matr�cula
                fgets(nomeAluno, sizeof(nomeAluno), aluno); // L� o nome do aluno
                if (nomeAluno[strlen(nomeAluno) - 1] == '\n') {
                    nomeAluno[strlen(nomeAluno) - 1] = '\0'; // Remove o caractere '\n' do final
                }
                insereElemento(hash, tam, matricula, nomeAluno); // Insere na tabela hash
            }
        }        
        fclose(aluno); // Fecha o arquivo
        printf("\n\nLeitura conclu�da. Dados inseridos na tabela hash.\n");
    }
}

// Fun��o para calcular o m�dulo da matr�cula em rela��o ao tamanho da tabela
int calcularMod(long long matricula, int tam) {
    int mod = matricula % tam; // Calcula o resto da divis�o da matr�cula pelo tamanho
    return mod;
}

// Fun��o para buscar se uma matr�cula est� presente na lista da tabela hash
int buscaLista(TDados **hash, long long matricula, int tam) {
    int posi = calcularMod(matricula, tam); // Calcula a posi��o na tabela
    TDados *lista = hash[posi];
    while (lista != NULL) {
        if (matricula == lista->matricula)
            return 1; // Encontrou a matr�cula na lista
        lista = lista->prox;
    }
    return 0; // Matr�cula n�o encontrada na lista
}

// Fun��o para buscar e exibir os detalhes de um aluno na tabela hash
void busca(TDados **hash, long long matricula, int tam) {
    int posi = calcularMod(matricula, tam);
    int exibe = 0;
    TDados *lista = hash[posi];
    while (lista != NULL) {
        if (matricula == lista->matricula) {
            printf("\n - Hash[%d]: %lld - %s \n", posi,lista->matricula, lista->nome);
            exibe = 1;
        }
        lista = lista->prox;
    }
    if (!exibe)
        printf("\n\tMatricula nao existe");
}

// Fun��o para percorrer a lista da tabela hash e salvar os dados em um arquivo
void percorreLista(TDados **hash, int pos, FILE *aluno){
    TDados *lista = hash[pos];
    while (lista != NULL) {
        fprintf(aluno, "%lld\n%s\n", lista->matricula, lista->nome); // Adicionar uma quebra de linha ap�s o nome
        lista = lista->prox;
    }
}

// Fun��o para salvar os dados da tabela hash em um arquivo
void salvarArqHash(TDados **hash, int tam) {
    FILE *aluno;
    int i;
    aluno = fopen("lista_matricula_alunos_2023.txt", "w"); // Abre o arquivo para escrita
    if (!aluno) {
        printf("\nErro na abertura do arquivo 'lista_matricula_alunos_2023.txt'");
    } else {
        for (i = 0; i < tam; i++) {
            TDados *lista = hash[i];
            while (lista != NULL) {
                fprintf(aluno, "%lld\n%s\n", lista->matricula, lista->nome); // Escreve matr�cula e nome
                lista = lista->prox;
            }
        }
        fclose(aluno); // Fecha o arquivo
        printf("\nBase de dados salva com sucesso!\n");
    }
}

// Fun��o para obter a matr�cula inserida pelo usu�rio
long long obterMatricula() {
    long long matricula;
    printf("Informe a matricula: ");
    scanf("%lld", &matricula);
    return matricula;
}

// Fun��o para excluir um elemento da tabela hash
void excluirElemento(TDados **hash, long long matricula, int tam) {
    int pos = calcularMod(matricula, tam);
    if (!buscaLista(hash, matricula, tam)) {
        printf("\nItem nao encontrado\n");
        return;
    }
    TDados **lista = &hash[pos];
    TDados *anterior = *lista;
    TDados *proximo = (*lista)->prox;
    TDados *guarda = hash[pos];
    while (*lista != NULL) {
        if ((*lista)->matricula == matricula) {
            if (*lista == anterior) {
                if ((*lista)->prox == NULL) {
                    free(*lista); // Libera mem�ria do elemento atual
                    hash[pos] = NULL; // Atualiza a posi��o na tabela
                } else {
                    (*lista)->prox = proximo->prox;
                    strcpy((*lista)->nome, proximo->nome);
                    (*lista)->matricula = proximo->matricula;
                    hash[pos] = guarda;
                }
            } else {
                anterior->prox = proximo;
                free(*lista); // Libera mem�ria do elemento atual
                hash[pos] = guarda;
            }
            return;
        }
        anterior = *lista;
        *lista = (*lista)->prox;
        proximo = (*lista)->prox;
    }
    hash[pos] = guarda;
    free(anterior);
    free(proximo);
    free(guarda);
}

// Fun��o para imprimir os elementos de uma lista da tabela hash
void imprimirElementosLista(TDados *lista) {
    if (lista == NULL) {
        printf(""); // Lista vazia
    } else {
        while (lista != NULL) {
            printf("%lld - %s", lista->matricula, lista->nome); // Imprime matr�cula e nome
            if (lista->prox != NULL) {
                printf(" |*| "); // Nova linha para o pr�ximo elemento
            }
            lista = lista->prox;
        }
    }
}

// Fun��o para exibir a lista completa da tabela hash
void exibirLista(TDados **hash, int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        printf("Hash[%d]: ", i); // Mostra a posi��o na tabela
        imprimirElementosLista(hash[i]); // Chama a fun��o para imprimir a lista da posi��o
        printf("\n");
    }
}

// Fun��o para liberar a mem�ria alocada para a tabela hash
void liberarMemoria(TDados **hash, int tam) {
    int i;
    
    printf("\nSaindo...\n");
    
    for (i = 0; i < tam; i++) {
        TDados *lista = hash[i];
        while (lista != NULL) {
            TDados *temp = lista;
            lista = lista->prox; // Move para o pr�ximo elemento
            free(temp); // Libera mem�ria do elemento atual
        }
    }
}

// Fun��o para executar a a��o escolhida no menu
void executarAcaoMenu(TDados **hash, int num, int tam) {
    long long info;
    switch (num) {
        case 0:
            liberarMemoria(hash, tam);
            break;
        case 1:
            adicionarNovoAluno(hash, tam);
            break;
        case 2:
            info = obterMatricula();
            excluirElemento(hash, info, tam);
            break;
        case 3:
            info = obterMatricula();
            busca(hash, info, tam);
            break;
        case 4:
            exibirLista(hash, tam);
            break;
        case 5:
            salvarArqHash(hash, tam);
            break;
        default:
            printf("Nao existe essa opcao!");
            break;
    }
}

// Fun��o para exibir o menu principal e realizar opera��es na tabela hash
void exibirMenu(TDados **hash, int tam) {
    int op;
    leituraArq(hash, tam);
    do {
        printf("\n\n---------- MENU --------------\n\n");
        printf("\t0. Sair\n");
        printf("\t1. Inserir novo aluno\n");
        printf("\t2. Remover aluno\n");
        printf("\t3. Buscar aluno\n");
        printf("\t4. Imprimir a base de dados\n");
        printf("\t5. Salvar base de dados\n");
        printf("Escolha a opcao: ");
        scanf("%d", &op);
        executarAcaoMenu(hash, op, tam);
    } while (op != 0);
}

