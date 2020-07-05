#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int soma_pares(int n){
	
	n = (n-1)*2;
	
	if(n<=0){
		printf("0  ");
		return 0;
	}
	
	printf("%d  ", n);
	int retorno = soma_pares((n/2)) + n;
	return retorno;
}

int soma_pares_p(int * n){
	
	*n = (*n-1)*2;
	
	if(*n<=0){
		printf("0  ");
		return 0;
	}
	
	int m = (*n)/2;
	
	int retorno = soma_pares_p(&m) + (*n);
	printf("%d  ", *n);
	return retorno;
}

int soma_impares(int * n){
	
	*n = (*n)*2-1;
	
	if(*n==1){
		printf("1  ");
		return 1;
	}
	
	int m = (*n-1)/2;
	
	int retorno = soma_impares(&m) + (*n);
	printf("%d  ", *n);
	return retorno;
}


float somatorio(int n){
	
	if(n<=1){
		return 0.5;
	}
	
	float aux = (float) 1/(n*(n+1));
	
	return somatorio(n-1) + aux;
	
}

void p1(int * p, int *q){
	int aux = *p;
	*p = *q;
	*q = aux;
}

void p2(int ** p, int **q){
	int * aux = *p;
	*p = *q;
	*q = aux;
}

int soma(int * p){
	
	if(*p<=0){
		return 0;
	}
	
	*p = *p-1;
	int m = *p;
	printf("%d ", *p);
	int retorno = *p + soma(&m);
	return retorno;

}

int pares(int *p, int *q){
	int aux;
	if(*p <= *q){
		if(*p%2 != 0){
			*p +=1;
		}
		aux = *p + 2;
		printf("%d ", *p);
		return pares(&aux, q) + *p;
	}else{
		return 0;
	}
	
}

int ver_perfeitos(int n){
	
	if(n<=0){
		return 0;
	}
	
	int i, soma = 0;
	for(i=1;i<n;i++){
		if( n%i == 0){
			soma += i;
		}
	}
	
	if(soma == n){
		return 1;
	}
	
	return 0;
	
}

int perfeitos(int *p, int *q){
	
	if(*p == *q){
		if(ver_perfeitos(*p)){
			printf("%d  ", *p);
			return *p;
		}else{
			return 0;
		}
	}
	
	int next = *p+1;
	if(ver_perfeitos(*p)){
		printf("%d ", *p);
		int retorno = *p + perfeitos(&next, q);
		return retorno;
	}else{
		perfeitos(&next,q);
	}
	
	
}

int ver_primos(int n){
	
	if(n<=1){
		return 0;
	}
	int i, count=0;
	for(i=1;i<=n;i++){
		if(n%i == 0){
			count++;
		}
	}
	
	if(count == 2){
		return 1;
	}
	
	return 0;
	
}

int primos(int *p, int *q){
	
	if(*p == *q){
		if(ver_primos(*p)){
			printf("%d  ", *p);
			return *p;
		}else{
			return 0;
		}
	}
	
	int next = *p+1;
	if(ver_primos(*p)){
		printf("%d  ", *p);
		return *p + primos(&next, q);
	}else{
		primos(&next, q);
	}
	
	
}

void hipotenusa(int n){
	
	int i,j,k;
	for(i=1;i<=n;i++){
		for(j=1;j<i;j++){
			for(k=1;k<i;k++){
				if(pow(i,2) == pow(j,2) + pow(k,2)){
					printf("%d %d %d\n", i, j, k);
				}
			}
		}
	}
	
}

float q14(int * p){
	
	if(*p <= 1){
		return 1;
	}
	
	float aux = (float) 1/(*p);
	
	int q = *p-1;
	
	if(*p%2 == 0){
		return q14(&q) - aux;
		
	}else{
		return q14(&q) + aux;
	}
	
}

float somando(int * p, int * q){
		
	if(*p == *q){
		return 1;
	}else{
		float soma = ((float) (*p)/(*q)) + ((float) (*q)/(*p));
		
		(*p) = (*p)+1;
		(*q) = (*q)-1;
		
		if((*p)>(*q)){
			return soma;
		}else{
			return soma + somando(p,q);
		}
	}
	
}

int sufixo(int x, int y){
	
	int mod, count = 0, divisor, aux = y;
	while(aux>0){
		aux = aux/10;
		count++;
	}
	
	divisor = pow(10,count);
	
	mod = x%divisor;
	
	if(mod==y){
		return 1;
	}
	
	return 0;	
	
}

int segmento(int x, int y){
	
	while(y!=0){
		
		printf("%d  ", x);
		
		if(sufixo(x,y)){
			return 1;
		}else{
			x = x/10;
		}
	}
	
	return 0;
}

float pi(int * p){
	
	if(*p<=1){
		return 4;
	}
	
	float aux = (float) 4/(2*(*p)-1);
		
	int q =(*p)-1;
		
	if(q%2 != 0){
		return pi(&q) - aux;
	}else{	
		return pi(&q) + aux;
	}
}

float q13(int * p, int * q){
	
	if(*p==*q){
		return 1;
	}
	
	float soma = ((float) (*p)/(*q))+ ((float) (*q)/(*p));
	
	*p = *p+1;
	*q = *q-1;
	
	if(*p>*q){
		return soma; 
	}else{
		return soma + q13(p,q);
	}
	
	
}

void palindromo(int x){
	
	int aux = x, y = 0;
	
	while(aux>0){
		y = y*10 + aux%10;
		aux=aux/10;
	}
	
	if(x==y){
		printf("\nPalindromo :%d\n", y);
	}
	
}

int binario(int n){
	
	int aux = 0, count=0;
	
	while(n>0){
		aux += (n%10) * pow(2,count);
		n = n/10;
		count++;
	}
	
	return aux;
	
}

int fibonacci(int n){
	
	if(n==1 || n==0){
		return 1;
	}
	
	return fibonacci(n-1) + fibonacci(n-2);
	
}

int main(){
	
	int a = 4, b=10;
	int * p = &a;
	int * q = &b;
	
	p = &b;

	printf("%d ", *p);
	
	return 0;
}
