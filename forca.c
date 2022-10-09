#include "forca.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Variáveis globais
char palavraSecreta[20];
char chutes[26];
int chutesDados = 0;

void abertura()
{
    printf("*******************************\n");
    printf("*        JOGO DE FORCA        *\n");
    printf("*******************************\n");
}

void chuta()
{
    char chute;
    scanf(" %c", &chute);

    chutes[chutesDados] = chute;
    chutesDados++;
}

int jaChutou(char letra)
{
    int achou = 0;
    for (int j = 0; j < chutesDados; j++)
    {
        if (chutes[j] == letra)
        {
            achou = '1';
            break;
        }
    }

    return achou;
}

void desenhaForca()
{
    for (int i = 0; i < strlen(palavraSecreta); i++)
    {
        int achou = jaChutou(palavraSecreta[i]);

        if (achou)
        {
            printf("%c", palavraSecreta[i]);
        }
        else
        {
            printf("_ ");
        }
    }
}

void escolhePalavra()
{
    FILE* f;
    f = fopen("palavras.txt", "r");
    if(f == 0){
        printf("Error: Error opening palavras file");
        exit(1);
    }

    int qtddepalavras;
    fscanf(f, "%d", &qtddepalavras);

    srand(time(0));
    int randomico = rand() % qtddepalavras;

    for(int i = 0; i<= randomico; i++){
        fscanf(f, "%s", &palavraSecreta);
    }
    fclose(f);
}

int enforcou(){
    int erros = 0;
    for(int i = 0; i < chutesDados; i++){
        int existe = 0;
        for(int j = 0; j < strlen(palavraSecreta); j++){
            if(chutes[i] == palavraSecreta[j]){
                existe = 1;
                break;
            }
        }

        if(!existe) erros++;
    }
    return erros >= 5;
}

int acertou() {
    for(int i = 0; i < strlen(palavraSecreta); i++){
        if(!jaChutou(palavraSecreta[i])){
            return 0;
        }
    }
    return 1;
}