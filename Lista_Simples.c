/*
 * @Autor do exercicio : Márcio Alexandre Freire Sindeaux
 * @Data : 23/10/2018
 * @E-mail : sindeaux1999@hotmail.com
 *
 * PROBLEMA :
 * Pensando em seus consumidores, uma rede de supermecados, Bread de Sal e Trigo, começa a produzir um sistema para seus consumidores
 *
 * O sistema, segundo seu chefe, é para ajudar os clientes a parar de carregar a 'lista de compras' de papel. Dessa forma os lientes se
 * lembrariam do que comprar, e gastariam menos papel para isso.
 *
 * Mas houve um problema... O gerente de requisitos morreu de hipertensão (provavel causa seja a excessiva injestão de pão salgado), e, 
 * para não parar o projeto, ele pede para voce fazer um prototipo em C, que auxilie na hora de costruir o prototipo real. 
 *
 * Futuramente o dono desse repositório vai criar esse programa !
 *
 * RESPOSTA :
 */
#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

typedef struct item{
	char nome[50];
	int qtd;
	int id;
	double preco;
	struct item * prox;
}item;

typedef struct mainList{
	struct item * inicio;
	int qtd;
}mainList;

mainList * alocalista();
item * alocaitem();
void inserirItem(mainList * l);
void retirarItem(mainList * l);
void calcularPrecoLista(mainList * l);
void mostrarLista(mainList * l);

int main (void){
	int opc = -1;
	mainList * l = alocalista();;
	l->inicio == NULL;
	while(opc != 0 ){
		printf("\n\n[1] - Colocar Item na lista de compras\n");
		printf("[2] - Retirar item da lista de compras\n");
		printf("[3] - Calcular preco da lista\n");
		printf("[4] - Mostrar toda a lista\n");
		printf("[0] - Sair\n");
		scanf("%d",&opc);
		switch(opc){
			case 0:
				printf("\n\nSistema desligando \t...");
			break;
			case 1:
				inserirItem(l);
			break;
			case 2:
				retirarItem(l);
			break;
			case 3:
				calcularPrecoLista(l);
			break;
			case 4:
				mostrarLista(l);
			break;
			default :
				printf("\n\nNumero digitado invalido\n\n");
		}
	}
}

mainList * alocalista(){
	mainList * l = (mainList*)malloc(sizeof(mainList));
	l->inicio = NULL;
	l->qtd = 0;
	return(l);
}

item * alocaitem(){
	item * l = (item*)malloc(sizeof(item));
	l->prox = NULL;
	l->qtd = 0;
	return(l);
}
void inserirItem(mainList * l){
	item * aux = alocaitem(); 
	char ent[100];
	printf("\n\nDigite o nome do produto \t :\t");
	fflush(stdin);
	gets(aux->nome);
	printf("Digite o preco do produto : \t");
	scanf("%lf",&aux->preco);
	printf("Digite a quantidade : \t");
	scanf("%d",&aux->qtd);
	aux->id = l->qtd + 1;
	aux->prox = l->inicio;
	l->inicio = aux;
	l->qtd++;
}

void retirarItem(mainList * l){
	int num;
	mostrarLista(l);
	printf("\n\nUSANDO O CAMPO 'ID', DIGITE O ID DO PRODUTO QUE DESEJA EXCLUIR\n\n");
	printf("Numero : \t");
	scanf("%d",&num);
	if((num>l->qtd)||(num<0)){
		printf("\n\nID DIGITADO INVALIDO \n\n");
	}else{
		item * aux = l->inicio;
		if(aux->id == num){
			l->inicio = aux->prox;
			free(aux);
		}else{
			item * antaux = aux;
			aux = aux->prox;
			while(aux != NULL){
				if(aux->id == num){
					antaux->prox = aux->prox;
					free(aux);
					break;
				}
				antaux = aux;
				aux = aux->prox;
			}
		}
	}	
}

void calcularPrecoLista(mainList * l){
	item * aux = l->inicio;
	if(aux == NULL){
		printf("\n\nNão ha itens na lista\n\n");
	}else{
		double valor = 0;
		while(aux != NULL){
			valor = valor + (aux->qtd * aux->preco);
			aux = aux->prox;
		}
		printf("\n\nPRECO TOTAL R$%.2lf\n\n",valor);
	}
}

void mostrarLista(mainList * l){
	item * aux = l->inicio;
	if(aux == NULL){
		printf("\n\nNao exitem itens na lista\n\n");
	}else{
		while(aux != NULL){
			printf("| ID %d|",aux->id);
			printf("%s",aux->nome);
			printf("|Quantidade : %d|\n",aux->qtd);
			aux = aux->prox;
		}
	}
	printf("\n\n");
}