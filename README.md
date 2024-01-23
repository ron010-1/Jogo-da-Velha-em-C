# Jogo da Velha em C
Bem-vindo ao Jogo da Velha em C! Este projeto implementa o clássico jogo da velha para dois jogadores. Este README fornecerá informações sobre como compilar, executar o código, e as regras do jogo.

## Como Compilar e Executar
Certifique-se de ter um compilador C instalado em seu sistema. Se você estiver usando o GCC, você pode compilar o código da seguinte maneira:

```C
gcc jogo_da_velha.c -o jogo_da_velha
```
Isso criará um executável chamado jogo_da_velha. Agora, execute o jogo:
```C
./jogo_da_velha
```

## Como Jogar
O Jogo da Velha é um jogo para dois jogadores, X e O, que alternam turnos marcando espaços em uma grade 3x3. O primeiro jogador a formar uma linha horizontal, vertical ou diagonal com suas marcações ganha.

A grade é numerada da seguinte forma:

1 | 2 | 3
-   -   -
4 | 5 | 6
-   -   -
7 | 8 | 9
Os jogadores fazem suas jogadas inserindo o número correspondente à posição desejada.

## Estrutura do Código
O código está organizado da seguinte forma:

jogo_da_velha.c: O arquivo principal contendo a lógica do jogo e todas as funções necessárias para o seu funcionamento.

## Contribuições
Contribuições são bem-vindas! Se você encontrar problemas ou tiver sugestões de melhoria, abra uma issue neste repositório.

## Licença
Este projeto está licenciado sob a Licença MIT - consulte o arquivo LICENSE para obter detalhes.

Divirta-se jogando Jogo da Velha em C!
