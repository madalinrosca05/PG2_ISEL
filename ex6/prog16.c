#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
Aplicação conjunta das funcionalidades sobre strings, desenvolvidas nos exercícios anteriores.
Escreva um programa de aplicação prog16.c, produzindo o executável prog16 que filtre linhas de
texto, formadas por campos, com base no conteúdo de um dos campos, comparado com uma string através
da função strcmp_ic.

O programa tem dois argumentos de linha de comando:
• O primeiro é um número, de valor 1 ou superior, para selecionar a posição do campo a comparar;
• O segundo é a string para ser comparada, em cada linha, com o campo selecionado.

A filtragem consiste em apresentar, em standard output, apenas o conteúdo das linhas nas quais o campo
selecionado corresponde à string indicada no argumento de linha de comando; as restantes linhas são
descartadas. Antes de realizar a comparação, a string de argumento e o campo indicado, de cada linha,
devem ser uniformizados pela função separatorUnify. As linhas selecionadas são apresentadas com
o seu conteúdo original, sem modificações causadas pelo processamento dos campos.

O valor numérico do primeiro argumento pode ser obtido, da respetiva string, usando uma função de
biblioteca, por exemplo strtoul. Quanto ao segundo argumento de linha de comando, normalmente
contém apenas uma palavra; no entanto, pode ser inserida uma string que inclua espaços se for delimitada
por aspas.

Propõe-se que o programa leia o texto de standard input com a função fgets da biblioteca normalizada,
assumindo a dimensão máxima de linha com 255 carateres úteis.

Para efeitos de demonstração, deve criar ficheiros, contendo linhas com campos, e utilizá-los através do
redireccionamento de input. Os campos devem permitir diversos cenários de teste, envolvendo:

• Texto diferente da palavra pretendida, para demonstrar que a comparação o distingue;
• A string pretendida com maiúsculas ou minúsculas, para demonstrar que a comparação aceita ambas;
• Carateres de espaçamento em diversos arranjos, para confirmar o efeito da uniformização.

*/
int main(int argc, char *argv[]){ //para compilar, façam ./prog16 1 ""
    //constantes
    static int MAX_LINE_SIZE = 255;


    //receção e processamento das entradas e verificações

    if (argc != 3){
        fatal_error("número de argumentos inválido, use 3 argumentos da seguinte forma: ./prog16 posição_do_campo string_a_procurar < ficheiro.txt");}
    int pos_campo = (int)strtoul(argv[1], NULL, 10);
    if (pos_campo <= 0){fatal_error("posição do campo impossível, insira número maior ou igual a 1");}

    char str_introduzida[MAX_LINE_SIZE];
    strncpy(str_introduzida, argv[2], MAX_LINE_SIZE -1);
    str_introduzida[MAX_LINE_SIZE - 1] = '\0';
    separator_unify(str_introduzida);
    
    char linha[MAX_LINE_SIZE];
    char copia[MAX_LINE_SIZE];


    if (pos_campo <= 0){fatal_error("posição do campo impossível, insira número maior ou igual a 1");}


    //lógica do codigo
    while (fgets(linha, MAX_LINE_SIZE, stdin) != NULL){
        strcpy(copia, linha);

        char *campo = NULL;
        char *atual = strtok(copia, ";\n");
        int count = 1;

        //colocar no campo pedido
        while (atual != NULL) {
            if (count == pos_campo) {
                campo = atual;
                break;
            }
            atual = strtok(NULL, " \n");
            count++;
        }

        //compara a string com a original e printa
        if (campo != NULL) {
            separator_unify(campo);
            if (strcmp_ic(campo, str_introduzida) == 0) {
                printf("%s", linha);
            }
        }
    }
    
    return 0;
}