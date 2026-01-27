#include <stdio.h>
#include <string.h>

void add_path(char *path);


int main(int argc, char *argv[])
{
    
    // Para aceitar: wstaion add path "caminho"
    // argc deve ser 4
    if(argc == 1)
    {
        printf("Comando não reconhecido, use wstation help para verificar comandos.\n");
        return 1;
    }

    if(argc == 4 && strcmp(argv[1], "add") == 0 && strcmp(argv[2], "path") == 0)
    {
        add_path(argv[3]);
    } 
    else if (argc < 4 && strcmp(argv[1], "add") == 0) 
    {
        printf("Erro: Faltou o caminho.\n");
    }
    else 
    {
        printf("Comando não reconhecido, use wstation help para verificar comandos.\n");
    }

    return 0;
}

void add_path(char *path)
{
    if (path == NULL || strlen(path) == 0)
    {
        printf("Erro: caminho inválido.\n");
        return;
    }

    FILE *arquivo = fopen("path.txt", "a");
    if (arquivo == NULL)
    {
        printf("Erro fatal: Não foi possível abrir ou criar 'path.txt'.\n");
        return;
    }

    fprintf(arquivo, "%s\n", path);
    fclose(arquivo);

    printf("Caminho adicionado: %s\n", path);
}
