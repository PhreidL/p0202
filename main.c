//Lucas Alves de Lima 22216036-8
// Caio Rios Sousa 22117034-3

#include <stdio.h>
#include <stdlib.h>
#define esp 100

int iguais(char v[], char d[]);

void reinTempS();
void copia(char d[], char f[]);
void criaVar();
void criaPre();

void e0();
void e1();
void e2();
void e3();
void e4();
void e5();
void e6();

void sigma1();
void sigma2();
void sigma3();
void sigma4();
void sigma5();
void sigma6();
void sigma7();
void sigma8();
void sigma9();
void sigma10();

int p = 0;
int auxC = -1;
int aux = 0;
int pos_N = 0;
int pos_S = 0;
int pos_C = 0;
int N[esp];
long long int tempN;
char tempC[esp];
char f[esp];
char tempS[esp];
char vars[200][20];
char pre[9][10] = {{'I','F'},{'E','L','S','E'},{'T','H','E','N'},{'P','R','I','N','T'},{'R','E','A','D'},{'O','F'},{'G','O','T','O'},{'E','N','D'},{'L','E','T'}};


int main(int argc, char *argv[]) {
	printf("Entrada das variaveis: \n");
    gets(f);
	e0();
	
	system("pause");
	return 0;
}

void e0(){
	if(f[p] == 0){
		criaVar();
		criaPre();
	}else
		if(f[p] >= '0' && f[p] <= '9' ){
		sigma1();
		p++;
		e1();
		}else
			if(f[p] == 32){
				p++;
				e0();
			}else
				if(f[p] >= 'a' && f[p] <= 'z' || f[p] >='A' && f[p] <= 'Z'){
					sigma4();
					p++;
					e2();	
				}else
					if(f[p] == ':'){
						p++;
						e3();
					}else
		   				 if(f[p] == '%'){
							p++;
							e5();
						}else{
							sigma9();
							p++;
							e6();
						}
			
}

void e1(){
	if(f[p] >= '0' && f[p] <= '9'){
		sigma2();
		p++;
		e1();
	}else{
		sigma3();
		e0();
	}
}

void e2(){
	if(f[p] >= 'a' && f[p] <= 'z' || f[p] >='A' && f[p] <= 'Z' || f[p] >= '0' && f[p] <= '9'){
		sigma5();
		p++;
		e2();
	}else{
		sigma6();
		e0();
	}
}

void e3(){
	if( f[p] == '=' ){
		//p++;
		e4();
	}else{
		sigma7();
		e0();
	}
}

void e4(){
	sigma8();
	p++;
	e0();
}

void e5(){
	if(f[p] != 0){
		p++;
		e5();
	}else{
		p++;
		e0();
	}
}

void e6(){
	sigma10();
	e0();
}

void sigma1(){
	pos_N = 0;
	tempN = f[p] - '0';
}
void sigma2(){
	pos_N++;
	tempN = tempN*10 + f[p] - '0';
}
void sigma3(){
	printf("N(%d)", tempN);
}
void sigma4(){
	pos_S = 0;
	tempS[pos_S] = f[p];
}
void sigma5(){
	pos_S++;
	tempS[pos_S] = f[p];
}
void sigma6(){
	int c=0, achou=0, achouPre=0;
	for(c = 0; (c <= auxC) && (!achou) ; c++){
		if(iguais(vars[c],tempS)){
			achou = 1;
			aux = c;
		}
	}
	c=0;
	for(c = 0; (c < 9) && (!achouPre) ; c++){
		if(iguais(pre[c],tempS)){
			achouPre = 1;
			aux = c;
		}
	}
		
	if(achou){
		printf("V(%d)", aux);
		reinTempS();
	}else
		if(achouPre){
			printf("P(%d)", aux);
    		reinTempS();
		}else{
			auxC++;
			copia(vars[auxC], tempS);
			printf("V(%d)", auxC);
			reinTempS();
		}
}
void sigma7(){
	printf(":");
}
void sigma8(){
	printf(":");
	printf("=");
}
void sigma9(){
	pos_C++;
	tempC[pos_C] = f[p];
}
void sigma10(){
	printf("%c", tempC[pos_C]);
}

void copia(char d[], char f[]){
	int c=0;
    for(c = 0; d[c] = f[c]; c++);
}

int iguais(char v[], char d[]){
	 int i;
	 for(i = 0; v[i]; i++){
	 	if(v[i] != d[i]){
	 		return 0;
		 }
	 }
	 if(v[i] != d[i]){
	 	return 0;
	 }else{
	 	return 1;
	 }
}

void reinTempS(){
	int i =0;
    while(tempS[i] != 0){
        tempS[i] = 0;
        i++;
    }
}

void criaVar(){
	printf("\n- Tabela vars -\n");
	int i;  
	for(i=0; i <= auxC; i++){
		printf("\n%d  -> %s", i, vars[i]);
	}
	printf("\n");
}
void criaPre(){
	printf("\n- Tabela de Palavras Reservadas -\n");
	int i;  
	for(i=0; i < 9; i++){
		printf("\n%d  -> %s", i, pre[i]);
	}
	printf("\n");
}
