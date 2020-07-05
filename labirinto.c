#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_num(int min, int max, int tipo){
	
	int value;
	
	if(tipo){
		
		value = ((rand()%(max-min-1)+min)/2)*2+1; 
	}else{
			
		value = (((2+rand()%(max-min-1)+min))/2)*2;
	}

	return value;

}

char ** alocacao(char ** matriz, int linhas, int colunas){
	
	matriz = (char**) malloc(linhas* sizeof(char*));
	
	int i,j;
	
	for(i=0;i<linhas;i++){
	
		matriz[i] = (char*) malloc(colunas*sizeof(char));
	
	}
	
	return matriz;
}


void parede_vertical(char ** matriz, int min, int max, int coluna){
	
	int buraco = rand_num(min, max,1);
		
	int i;
	for(i = min; i<=max ;i++){
		if(i != buraco){
			matriz[i][coluna] = i%2 == 0 ? '+' : '|' ;
		}
	}
}


void parede_horizontal(char ** matriz, int min, int max, int linha){
	
	int buraco = rand_num(min , max,1);
	
	int i;
	for(i = min; i<=max ;i++){
		if(i != buraco){
			matriz[linha][i] = i%2 == 0 ? '+' : '-' ;
		}
	}
	
	
}

void constroi_paredes(char ** matriz,int linha, int coluna, int max_linha, int max_coluna, int orientacao){
	
	if(orientacao){
		
		if(max_linha - linha >= 2){
			
			int parede_ver = rand_num(coluna, max_coluna,0);
			
			parede_vertical(matriz, linha, max_linha, parede_ver);
			
			constroi_paredes(matriz, linha, parede_ver+1, max_linha, max_coluna, !orientacao);
			constroi_paredes(matriz, linha, coluna, max_linha, parede_ver-1, !orientacao);
		}
		
		
	}else{
		
		if(max_coluna - coluna >= 2){
			
			int parede_hor = rand_num(linha, max_linha,0);
			
			parede_horizontal(matriz, coluna, max_coluna, parede_hor);
			
			constroi_paredes(matriz, parede_hor+1, coluna, max_linha, max_coluna, !orientacao);
			constroi_paredes(matriz, linha, coluna, parede_hor-1, max_coluna, !orientacao);
		}
		
	}
	
}

void gera_labirinto(char ** matriz, int linhas, int colunas){
	
	int i,j;
	for(i=0;i<linhas;i++){
		
		for(j=0;j<colunas;j++){
		
			matriz[i][j] = ' ';
		
		}
	}
	
	for(i = 0; i < colunas; i++){
		
        matriz[0][i] = i%2 == 0 ? '+' : '-';
		
		matriz[linhas-1][i] = i%2 == 0 ? '+' : '-';
	}

    for(i = 0; i < linhas-1; i++){
        
		matriz[i][0] = i%2 == 0 ? '+' : '|';
    	
        matriz[i][colunas-1] = i%2 == 0 ? '+' : '|';
	}
	
	matriz[1][0] = ' ';
	matriz[linhas-2][colunas-1] = ' ';
	
	constroi_paredes(matriz, 1, 1, linhas-2, colunas-2, 1);
	
}


void imprimir(char ** matriz, int linhas, int colunas){
	
	int i,j;
	for(i=0;i<linhas;i++){
		
		for(j=0;j<colunas;j++){
			printf("%c", matriz[i][j]);
		
		}
		
		puts("\b");
	}
	
}

void salvar(char **matriz, int linhas, int colunas){
	FILE *arquivo;
	arquivo = fopen("lab.txt", "w");
	if (arquivo == NULL){
        perror("Erro: ");
        getchar();
        exit(1);    
    }
    int i, j;
    for (i = 0; i < linhas ; i++) {
    	for (j = 0; j < colunas; j++){
    		fprintf(arquivo, "%c", matriz[i][j]);
		}
        fprintf(arquivo, "\n");    
    }
	fclose(arquivo);
}


int main(){
	srand(time(NULL));
	
	int linhas = 0,colunas = 0;
	while(linhas < 10 || colunas < 10){
		printf("Digite a quantidade de linhas e colunas:\n");
		scanf("%d %d",&linhas,&colunas);
		if(linhas < 10 || colunas < 10){
			puts("O labirinto deve ter ao menos 10 linhas e 10 colunas\n");
		}
	}
		
	linhas = linhas*2 + 1;
	colunas  = colunas*2 + 1;
		
	char ** matriz = NULL;
	
	matriz = alocacao(matriz, linhas, colunas);

	gera_labirinto(matriz, linhas, colunas);	
	
	imprimir(matriz, linhas, colunas);
	
	salvar(matriz, linhas, colunas);
	
	return 0;
}
