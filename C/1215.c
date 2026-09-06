#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct No{
   char palavra[201];
   struct No *prox; 
}No;

No *lista = NULL;

void inserir(No **lista, char palavra[]){
    No* novo = (No *)malloc(sizeof(No));

    strcpy(novo->palavra,palavra);
    novo -> prox = *lista;
    *lista = novo;
}

int existe(No *lista, char palavra[]){
    while(lista != NULL){
        if(strcmp(lista->palavra, palavra) == 0){
            return 1;
        }
        lista = lista->prox;
    }
    return 0;
}


int compara(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

int main(){
    
    No *lista = NULL;
    char linha[200];
    char palavra[201];

    while(fgets(linha,200,stdin) != NULL){
        int idx = 0;

        for(int i = 0; linha[i] != '\0'; i++){
            if(isalpha(linha[i])){
                palavra[idx++] = tolower(linha[i]);
            }else{
                if(idx > 0){
                    palavra[idx] = '\0';
                if(!existe(lista, palavra)){
                    inserir(&lista,palavra);
                    idx = 0;
                       
        }
                }
            }
        }

        if (idx > 0) {
        palavra[idx] = '\0';

        if (!existe(lista, palavra)) {
            inserir(&lista, palavra);
    }

        idx = 0;
}

    }
    
    char vet[5000][201];
    int n = 0;
    
    No *aux = lista;
    while (aux != NULL){
        strcpy(vet[n++], aux->palavra);
        aux = aux->prox;
    }
    qsort(vet, n, sizeof(vet[0]), compara);
    
    for (int i = 0; i < n; i++) {
        printf("%s\n", vet[i]);
    }

    return 0;
}

