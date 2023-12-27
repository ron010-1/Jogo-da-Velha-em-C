#include <stdio.h>
#include <locale.h>//Idioma pt-BR

const int ORDEM = 6;
const int MAX_JOGADAS = 6;

int numEhImpar(int a){
    if(a % 2 != 0)return 1;//True
    return 0;//False
}
//SEÇÃO DE CRIAÇÃO DO TABULEIRO E IMPRESSÃO DO TABULEIRO NA TELA DO USUÁRIO.
void adicionarCoordenadas(char tabuleiro[ORDEM][ORDEM]){
    int i, j, varCoordenadasX=1, varCoordenadasY=1;
    for(i=0; i<ORDEM;i++){
        for(j=0;j<ORDEM;j++){
            tabuleiro[i][j] = ' ';
            if(i == 0 && numEhImpar(j)){
                tabuleiro[i][j] = varCoordenadasX + '0';
                varCoordenadasX++;
            }else{
                if(numEhImpar(i) && j == 0){
                tabuleiro[i][j] = varCoordenadasY + '0';
                varCoordenadasY++;
            }
            }
        }
    }
}
void adicionaLinhasVerticais(char tabuleiro[ORDEM][ORDEM]){
    int i, j, varCoordenadasX=1, varCoordenadasY=1;
    for(i=0; i<ORDEM;i++){
        for(j=0;j<ORDEM;j++){
            if(numEhImpar(i) && j != 0 && !numEhImpar(j)){
                    tabuleiro[i][j] = '|';
                }
        }     
    }
}
void adicionaLinhasHorizontais(char tabuleiro[ORDEM][ORDEM]){
    int i, j, varCoordenadasX=1, varCoordenadasY=1;
    for(i=0; i<ORDEM;i++){
        for(j=0;j<ORDEM;j++){
            if(i != 0 && !numEhImpar(i) && j != 0 && numEhImpar(j)){
                tabuleiro[i][j] = '-';
            }
        }
    }
}
void imprimirTabuleiro(char tabuleiro[ORDEM][ORDEM]){
    int i, j;
    for(i=0; i<ORDEM;i++){
        for(j=0;j<ORDEM;j++){
            if(tabuleiro[i][j] == " "){
                printf("  ");//Imprimindo espaços do tabuleiro
            }else{
                printf("%c ", tabuleiro[i][j]);
            }
        }printf("\n");
    }
    printf("O tabuleiro foi impresso.");
}
void criarTabuleiro(char tabuleiro[ORDEM][ORDEM]){
    adicionarCoordenadas(tabuleiro);
    adicionaLinhasVerticais(tabuleiro);
    adicionaLinhasHorizontais(tabuleiro);
    imprimirTabuleiro(tabuleiro);
}
//SEÇÃO AJUSTES
int verificarCaractere(char a, char *b){//Verificação de Caractere e Adicionando o valor do char do J2.
    if (a == 'X'){
        *b = 'O';//Alterando o valor de 'J2' já que o seu valor foi passado como referência de memória.
        return 1;//True
    }else if(a == 'O'){
        *b = 'X';//Alterando o valor de 'J2' já que o seu valor foi passado como referência de memória.
        return 1;//True
    }
    return 0;//False
}
//Ajustando as coordenadas para ficar de acordo com as posições da matriz.
int ajustesCoordenadas(int x){//O 1 não altera, o 2 vira 3 e o 3 vira 5.
    if(x == 1) return 1;
    if(x == 2) return 3;
    if(x == 3) return 5;
}
//SEÇÃO ALGORITMOS DO JOGO.
//Contabilizar jogada e armazenar na matriz.
void jogada(char tabuleiro[ORDEM][ORDEM], int x, int y, char simbolo){
    int i, j;
    x = ajustesCoordenadas(x);
    y = ajustesCoordenadas(y);
    for(i=0; i<ORDEM; i++){
        for(j=0; j<ORDEM; j++){
            if(i == x && j == y){
                tabuleiro[i][j] = simbolo;
            }
        }
    }
}
int verificarLinhas(char tabuleiro[ORDEM][ORDEM], char simbolo){
    int i, j=1, contador=0;
    for(i=1; i<ORDEM; i+=2){
        for(j=1; j<ORDEM;j+=2)
        if(tabuleiro[i][j] == simbolo){
            contador++;
        }
        if(contador == 3){
        return 1;//True
        }
        contador=0;
    }
    return 0;//False
}
int verificarColunas(char tabuleiro[ORDEM][ORDEM], char simbolo){
    int i, j, contador=0;
    for(j=1; j<ORDEM; j+=2){
        for(i=1; i<ORDEM;i+=2)
        if(tabuleiro[i][j] == simbolo){
            contador++;
        }
        if(contador == 3){
        return 1;//True
        }
        contador=0;
    }
    return 0;//False
}
int verificarGanhador(char tabuleiro[ORDEM][ORDEM], char simbolo){
    int x = verificarLinhas(tabuleiro, simbolo);
    if(x == 1){
        return 1;
    }
    int y = verificarColunas(tabuleiro, simbolo);
    if(y == 1){
        return 1;
    }
    return 0;
}
//SEÇÃO PROGRAMA PRINCIPAL
int main() {
    setlocale(LC_ALL, "Portuguese");//Alterando o idioma pra pt-BR
    //Variáveis
    int i, x, y;
    char J1, J2;

    //Criando o tabuleiro
    char tabuleiro[7][5];
    criarTabuleiro(tabuleiro);

    //Apresentação do Jogo e Instruções
    printf("\n                      JOGO DA VELHA                                 \n");
    printf("INSTRUÇÕES: Para jogar você deve digitar as coordenadas da posição em que deseja por o seu caractere(LINHA e COLUNA).\n\n Atenção no turno de cada jogador e na posição em que deseja jogar.\n");

    //Início do Jogo
    printf("O J1 deseja ser X ou O?\n");
    scanf("%c", &J1);
    int x = verificarCaractere(J1, &J2);//Passando o caractere do J2 como referência para ser inserido na função.
    if(x == 0){//Se a função retornar False então o caractere é inválido.
        printf("O caractere inserido não é válido.\n");
        printf("Insira um novo caractere para o J1: ");
        scanf("%c ", &J1); verificarCaractere(J1, &J2);
    }

    //Laço de repetições com o máximo de jogadas: 9.
    for(i=0; i<MAX_JOGADAS; i++){//Enquanto i for maior que 0 é true, i=0 é false.
        printf("J1 digite as coordenadas que deseja: \n");
        scanf("%d%d", &x, &y);
        jogada(tabuleiro, x, y, J1);

        printf("J2 digite as coordenadas que deseja: \n");
        scanf("%d%d", &x, &y);
        jogada(tabuleiro, x, y, J2);

        //Verificando se há algum ganhador
        //CHAMAR FUNCAO E VERIFICAR SE É TRUE OR FALSE.
    }
    

    return 0;
}
