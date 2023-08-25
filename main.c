#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "hash.h" // Inclui o arquivo de cabe�alho para as fun��es relacionadas a hash

int main() {
    setlocale(LC_ALL, "Portuguese");
    int tamanhoTabela = calcularTamanhoTabela(); // Calcula o tamanho da tabela hash
    TDados *hash[tamanhoTabela]; // Cria um array de ponteiros para armazenar os baldes da tabela hash
    inicializarTabela(hash, tamanhoTabela); // Inicializa os baldes da tabela hash
    exibirMenu(hash, tamanhoTabela); // Exibe o menu principal para intera��o do usu�rio
    return 0;
}
