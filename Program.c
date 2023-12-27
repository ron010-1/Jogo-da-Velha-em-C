#include <stdio.h>
#include <locale.h>//Idioma pt-BR

const int ORDEM = 6;
const int MAX_JOGADAS = 9;

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
//SEÇÃO ALGORITMOS DE VERIFICAÇÃO DE RESULTADO VENCEDOR.=
int main() {
    setlocale(LC_ALL, "Portuguese");//Alterando o idioma pra pt-BR
    char tabuleiro[7][5];
    criarTabuleiro(tabuleiro);
    
    return 0;
}
