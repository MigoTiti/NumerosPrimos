#include <stdio.h>
#include <stdlib.h>

void Primo(int x);
void PrimoRef(int x, int *cont);
void Escolha(int op);
void Escolha2(int opt);
int menu(void);
void EncheVetor(int *primo, int c);
void ContaPrimo(int *primo, int x, int *c);

int main(){	
    int op;
	do{
	op=menu();
	Escolha(op);
    }while(op!=4); 
}

int menu(void){
	int op;
	printf("Escoha a operacao desejada:\n\n");
	printf("1-Identificar se o numero e primo; \n");
	printf("2-Identificar se o numero e primo (referencia); \n");
	printf("3-Contar os numeros primos ate um natural qualquer; \n");
	printf("4-Sair. \n\n");
	scanf("%d",&op);
	return op;
}

void Escolha(int op){	
    int x, y, c, opt, cont=0, *primo;
	switch(op){
	case 1:
	    printf("\nDigite um numero natural: "); scanf("%d",&x);
	    Primo(x);
	    printf("\nDeseja fazer outra operacao? (s=1/n=0): "); scanf("%d",&opt);
	    Escolha2(opt);
	    break;
	case 2:
		printf("\nDigite um numero natural: "); scanf("%d",&x);
		if ((x==1) || (x % 2 ==0)){
		system("cls");
		printf("O numero %d nao e primo. \n\n",x);
		}else{
		PrimoRef(x,&cont);
		if (cont >= 2)
	       printf("O numero %d nao e primo. \n\n",x);
	    else
	       printf("O numero %d e primo. \n\n",x);
	    }
	    printf("\nDeseja fazer outra operacao? (s=1/n=0): "); scanf("%d",&opt);
	    Escolha2(opt);
	    break;
	case 3:
		printf("\nDigite um numero natural: "); scanf("%d",&x);
		system("cls");
		primo=(int *) malloc(x * (sizeof(int)));
		EncheVetor(primo,x);
		ContaPrimo(primo,x,&c);
		for (y=0;y<=(c-1);y++)
          printf("%d\n",primo[y]);
        printf("\nNumero de primos: %d\n\n",c);
        free(primo);
	    printf("\n\nDeseja fazer outra operacao? (s=1/n=0): "); scanf("%d",&opt);
	    Escolha2(opt);
		break;
	case 4:
		exit(0);
	default:
		system("cls");
		printf("Comando invalido. \n");
}
}

void Escolha2(int opt){
	system("cls");
    if (opt==0)
     exit(0);
    else
     system("cls");
}

void EncheVetor(int *primo, int c){
	int y, x=1;
	for (y=0;y<=(c-1);y++){
		primo[y]=x;
		x++;
	}
}

void ContaPrimo(int *primo, int x, int *c){
	int y, z=0, a=0, cont=0;
	do{
	x--;
		a++;
		cont = 0;
    	for (y=1;y<=(a/2);y++){
     		if (a % y == 0)
	    	cont++;
        }
		if (cont < 2){
		   if (a>1){
		   	  primo[z]=a;
		   	  z++;
		   }
	    }
    }while(x>0);
    *c=z;
}

void PrimoRef(int x, int *cont){
	system("cls");
	int y, c=0;
	for (y=1;y<=(x/2);y++){
     	if (x % y == 0)
	    c++;
	}
	*cont=c;
}

void Primo(int x){
	int cont=0, y, opt;
	system("cls");
	if ((x % 2 == 0) || (x==1))
		printf("O numero %d nao e primo. \n\n",x);
	else{
    	for (y=1;y<=(x/2);y++){
     		if (x % y == 0)
	    	cont++;
	    }
	    if (cont >= 2)
	       printf("O numero %d nao e primo. \n\n",x);
	    else
	       printf("O numero %d e primo. \n\n",x);
	    
    }
}
