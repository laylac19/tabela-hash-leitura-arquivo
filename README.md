# tabela-hash-leitura-arquivo
Algoritmo que gere e manipule uma Tabela Hash com matricula e nome (Aluno) com base em um arquivo.

# [Relatorio](https://github.com/laylac19/tabela-hash-leitura-arquivo/blob/main/Relat%C3%B3rio%20Tabela%20Hash%20Com%20Leitura%20De%20Arquivo.pdf) sobre o algoritimo
O código implementa uma tabela hash para armazenar informações de alunos, incluindo matrícula e nome, usando encadeamento separado para lidar com colisões. Nesse método, cada posição na tabela hash mantém uma lista encadeada de elementos que mapeiam para aquela posição.

A estrutura TDados para representar um elemento (aluno) na tabela hash, contendo informações como matrícula, nome e um ponteiro para o próximo elemento na lista encadeada. A implementação permite inserir, buscar, excluir e listar elementos na tabela hash, além de salvar e carregar esses elementos de um arquivo.

Para a leitura do arquvio os dados devem estar dispostos assim:
```
    2020202020(matricula)
    abcdefg(nome)
```




