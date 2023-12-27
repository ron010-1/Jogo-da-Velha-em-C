

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

const short int ORDEM = 6;
const short int JOGADAS = 9;

//Fun��o para auxiliar na cria��o da estrutura do jogo
int eh_impar(int numero){
	if(numero%2 == 1){
		return 1;
	}
	return 0;
}

//Criando a estrutura do jogo, com a linhas verticais e horizontais (i = linha, j = coluna, isso em todo o c�digo)
void criar_jogo(char matriz[ORDEM][ORDEM]){
	int i, j, aux = 1;
	//Linhas verticais
	for (i=0; i<ORDEM; i++){
		for(j=0; j<ORDEM; j++){
			
	//Inv�s de deixar os indices para jogar (1, 3, 5), resolvi deixar 1, 2 e 3, para uma melhor experiencia do usuario (todavia, gera mais codigo)
			
			matriz[i][j] = ' ';
			char caractere = aux+'0';
			if (i == 0 && eh_impar(j)){
				matriz[i][j] = caractere;
				aux++;
			}
			else{
				if(eh_impar(i) && !eh_impar(j) && i !=0 && j != 0 ){
					matriz[i][j] = '|';
				}	
			}
		}
	}
	//Linhas horizontais
	aux = 1;
	for(i=1; i<ORDEM; i++){
		for(j=0; j<ORDEM; j++){
			char caractere = aux+'0';
			if (j == 0 && eh_impar(i)){
				matriz[i][j] = caractere;
				aux++;
			}
			if(!eh_impar(i) && j != 0){
				matriz[i][j] = '-';
			}
		}
	}
}

//Procedimento respons�vel por printar o jogo
void imprimir_jogo(char matriz[ORDEM][ORDEM]){
	int i, j;
	for (i=0; i<ORDEM; i++){
		for(j=0; j<ORDEM; j++){
			printf ("%c  ", matriz[i][j]);
		}
		printf ("\n");
	}
}

//Auxiliar verificador de linhas horizontais
int linhas_colunas_check(char matriz[ORDEM][ORDEM], char simbolo, int coluna){
	
	int i, j, contador = 0;
	
	for (i = 1; i<ORDEM; i+=2){
		for (j = 1; j<ORDEM; j+=2){
			if (coluna == 1){
				if(matriz[j][i] == simbolo){
				contador++;
				}
			}
			else{
				if(matriz[i][j] == simbolo){
				contador++;
				}	
			}
		}
		if(contador == 3){
			return 1;
		}
		contador = 0;
	}
}

//Verificando a cada jogada se alguem vence (lado X ou O)
int checar (char matriz[ORDEM][ORDEM], char simbolo){
	int i, j, contador = 0, coluna;
	
	if (linhas_colunas_check(matriz, simbolo, coluna = 0) == 1){
		return 1;
	}
	
	if (linhas_colunas_check(matriz, simbolo, coluna = 1) == 1){
		return 1;
	}
	
	//Verificando a diagonal principal: 
	for (i = 1; i<ORDEM; i+=2){
		if(matriz[i][i] == simbolo){
			contador++;
		}
	}
	if(contador == 3){
		return 1;
	}
	contador = 0;
	
	//Verificando a diagonal inversa a principal
	j = 1;
	for (i = 5; i>=0; i-=2){
		if(matriz[i][j] == simbolo){
			contador++;
		}
		j+=2;
	}
	if(contador == 3){
		return 1;
	}
	contador = 0;
	
	return 0;
}

//Ajustando indice de jogadas (nesse caso, o 1 n�o � alterado, o 2 altera para 3, e o 3 para 5, (esses s�o os verdadeiros indices da tabela)) 
int ajuste(int eixo){
	if(eixo != 1){
		return eixo = eixo == 2 ? 3 : 5;
	}
}

//Fun��o respons�vel por adicionar X ou O no jogo
void jogada(char matriz[ORDEM][ORDEM], int eixo_x, int eixo_y, char simbolo){
	//Ajustando indices para jogar
	eixo_y = ajuste(eixo_y);
	eixo_x = ajuste(eixo_x);
	if (matriz[eixo_x][eixo_y] == ' '){
		matriz[eixo_x][eixo_y] = simbolo;
	}
	else{
		printf ("\nLOCAL JA PREENCHIDO, PERDEU A VEZ\n\n");
	}
}

//Jogada do computador
void jogada_computador(char matriz[ORDEM][ORDEM], char simbolo){
	int jogada_comp = 0;
	//Gerando numeros aleatorios e posteriormente jogando
	srand( (unsigned)time(NULL) );
	int eixo_y = 1 + ( rand() % 3 );
	int eixo_x = 1 + ( rand() % 3 );
	eixo_y = ajuste(eixo_y);
	eixo_x = ajuste(eixo_x);
	
	//O computador jogar� apenas quando encontrar um espa�o livre na matriz (e dentro dos blocos permitidos)
	while (jogada_comp == 0){
		if (matriz[eixo_x][eixo_y] == ' '){
			matriz[eixo_x][eixo_y] = simbolo;
			jogada_comp = 1;
		}
		else{
			eixo_y = 1 + ( rand() % 3 );
			eixo_x = 1 + ( rand() % 3 );
			eixo_y = ajuste(eixo_y);
			eixo_x = ajuste(eixo_x);
		}
	}
}


void main(){
	//Mudando idioma nativo para portugues
	setlocale(LC_ALL, "portuguese");
	
	//Variaveis
	char velha[ORDEM][ORDEM], simbolo = 'O';
	int numero_jogadas = 0, x, y, jogador = 1, opcao = 1;
	
	//Criando e depois imprimindo o jogo da velha para orientar os jogadores
	criar_jogo(velha);
	imprimir_jogo(velha);
	
	printf ("\t\t\t\t================== JOGO DA VELHA ==================\n\n\n");
	printf ("INSTRU��ES: Para jogar, voce deve informar dois numeros, primeiro, o da linha (valores a esqueda do jogo da velha)\n");
	printf ("e depois deve informar a coluna (valores acima do jogo da velha), BOA JOGATINA!\n\n");
	while (opcao == 1 || opcao == 2 && opcao != 3){
		printf ("MENU:\n\nDois jogadores (Digite 1):\nVersus computador (Digite 2):\nEncerrar (Digite 3): \n");
		scanf ("%d", &opcao);
		if (opcao == 1){
			
			numero_jogadas = 0;
			criar_jogo(velha);
			for (numero_jogadas; numero_jogadas<JOGADAS; numero_jogadas++){
				
				//Solicitando as coordenadas
				printf ("\n\nVez do jogador %d\n", jogador);
				scanf ("%d%d", &x, &y);
				//Chegando qual jogador ser� o pr�ximo, bem como o s�mbulo (X ou O)
				jogador = jogador == 1 ? 2 : 1;	
				simbolo = simbolo == 'X' ? 'O' : 'X'; 
				jogada(velha, x, y, simbolo);
				//Checando se exite vencedo
				if (!checar(velha, simbolo)){
					imprimir_jogo(velha);
				}
				else{
					imprimir_jogo(velha);
					printf ("\n%c VENCEU\n\n", simbolo);
					numero_jogadas = JOGADAS;
				}
				//Em caso de empate o programa encerra
				if (numero_jogadas == 8){
					printf ("\n\nVELHA\n");
					numero_jogadas = 9;
				}
			}
		}
		
		if (opcao == 2){
			
			criar_jogo(velha);
			numero_jogadas = 0;
			simbolo = 'X';
			for (numero_jogadas; numero_jogadas<JOGADAS; numero_jogadas++){
				
				//Solicitando as coordenadas para o usu�rio
				if (jogador == 1){
					printf ("\n\nVez do jogador %d\n", jogador);
					scanf ("%d%d", &x, &y);
					jogada(velha, x, y, simbolo);
				}
				else{
				//Computador jogando
					printf("\nVez do computador \n");
					jogada_computador(velha, simbolo);
				}
				//Verificando se exite algum vencendor
				if (!checar(velha, simbolo)){
					imprimir_jogo(velha);
				}
				else{
					imprimir_jogo(velha);
					printf ("\n%c VENCEU\n\n", simbolo);
					numero_jogadas = JOGADAS;
				}
				//Verificando se o jogo deu empate
				if (numero_jogadas == 8){
					printf ("\n\nVELHA\n");
					numero_jogadas = JOGADAS;
				}
				//Checando qual jogador ser� o pr�ximo, bem como o s�mbulo (X ou O)
				jogador = jogador == 1 ? 2 : 1;
				simbolo = simbolo == 'X' ? 'O' : 'X';
			}
		}
	}
	printf ("\n\nOBRIGADO POR JOGAR !");
	getch();
}
