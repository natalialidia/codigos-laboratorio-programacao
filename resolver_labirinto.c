#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contar_linhas(){
	
	int linhas =0;
	
	FILE *arq;
	arq = fopen("lab.txt","r");
	
	char c;
	while(!feof(arq)){
		c = fgetc(arq);
		if(c == '\n'){
			linhas++;
		}
	}	
	fclose(arq);
	
	return linhas;

}


int contar_colunas(){
	
	int colunas = 0;
	
	FILE *arq;
	arq = fopen("lab.txt","r");
	
	char c;
	while(!feof(arq) && c != '\n'){
		c = fgetc(arq);
		if(c == '+' || c=='-' || c == '|'){
			colunas++;
		}
	}	
	fclose(arq);
	
	return colunas;

}

void imprimir(char ** matriz, int linhas, int colunas){
	
	int i,j;
	for(i=0;i<linhas;i++){
		
		for(j=0;j<colunas;j++){
			printf("%c", matriz[i][j]);
		}
		
		printf("\n");
	}
	
}

char ** alocacao(char ** matriz, int linhas, int colunas){
	
	matriz = (char**) malloc(linhas* sizeof(char*));
	
	int i,j;
	
	for(i=0;i<linhas;i++){
	
		matriz[i] = (char*) malloc(colunas*sizeof(char));
	
	}
	
	return matriz;
}

void preencher_matriz(char ** matriz, int linhas, int colunas){
		
	int i,j;
	for(i=0;i<linhas;i++){
		
		for(j=0;j<colunas;j++){
		
			matriz[i][j] = ' ';
		
		}
	}
	
	FILE *arq;
	arq = fopen("lab.txt","r");
	i = 0, j = 0;
	char c;
	while(!feof(arq)){
		c = fgetc(arq);
		if(c != '\n' && i<linhas && j<colunas){
			matriz[i][j] = c;
			j++;
		}else{
			i++;
			j=0;
		}
	}
	
	fclose(arq);
	
}

int resolver(char ** matriz, int linhas, int colunas, int pos_x, int pos_y){
	
	int i = pos_x;
	int j = pos_y;
	
	int res = 0;
	
	matriz[i][j] = '#';
	
	if(i == linhas-2 && j == colunas-1){
		res = 1;
	}else{
		if(matriz[i+1][j] == ' ' && !res){
			res = resolver(matriz,linhas,colunas,pos_x+1,pos_y);
		}
		
		if(matriz[i][j+1] == ' ' && !res){
			res = resolver(matriz,linhas,colunas,pos_x,pos_y+1);
		}
		
		if(matriz[i-1][j] == ' ' && !res){
			res = resolver(matriz,linhas,colunas,pos_x-1,pos_y);
		}
		
		if(matriz[i][j-1] == ' ' && !res){
			res = resolver(matriz,linhas,colunas,pos_x,pos_y-1);
		}
		
		if(!res && matriz[i+1][j] !=  ' ' && matriz[i][j+1] != ' ' && matriz[i-1][j] != ' ' && matriz[i][j-1] != ' '){
			matriz[i][j] = '/';
		}
	}

	return res;
	
}


int main(){
	
	char ** matriz = NULL;
	
	int linhas = contar_linhas();
	int colunas = contar_colunas();
	
	matriz = alocacao(matriz, linhas, colunas);
	
	preencher_matriz(matriz,linhas, colunas);
	
	printf("Labirinto carregado:\n");
	imprimir(matriz, linhas, colunas);
	
	resolver(matriz, linhas, colunas, 1,0);

	printf("\nSolucao:\n");
	imprimir(matriz, linhas, colunas);
	
	return 0;
	
}

