#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *arquivo;
    //Validação de comandos
    if( argc < 2)
    {
        printf("Comando não reconhecido, use wstaion help para verificar comandos.\n");
    }

    if(strcmp(argv[1], "wstaion") == 0)
    {
        return 0;
    }

    else if(argc >= 3  && strcmp(argv[1], "add") == 0
            && strcmp(argv[2], "path") == 0)
    {
        arquivo = fopen("path.txt", "a");
        fprintf(arquivo, "teste\n");
    }

    else
    {
        printf("Comando não reconhecido, use wstaion help para verificar comandos.\n");
    }

    return 0;
}




