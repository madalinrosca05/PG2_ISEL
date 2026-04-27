#include <stdio.h>
#include "book.h"
#include "processFile.h"
#include "errors.h"


int main(int argc, char *argv[]) {
  if (argc != 2) {
      fatal_error("Uso: ./prog24 <ficheiro_de_dados>\n");
  }
  // Inicializa a coleção e processa o ficheiro de dados
  Collection col = { .count = 0 };
  if (processFile(argv[1], collAddBook, &col) < 0) {
      fatal_error("Erro ao processar ficheiro.\n");
  }
  
  char command;
  while (printf("> "), scanf(" %c", &command) == 1) {
    switch (command)
    {
    case 'q':
      break;

    case 'l':
      listBooks(&col);
      break;
      
    case 'i':
      collSortRefIsbn(&col);
      break;

    default:
          printf("Comando desconhecido: %c\n", command);
      break;
    }
  }
}