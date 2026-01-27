#include <stdio.h>
#include <string.h>

void add_path(char *path);
void rm_path(const char *path);

int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        printf("Comando não reconhecido, use wstation help para verificar comandos.\n");
        return 1;
    }

    if (argc == 4 && strcmp(argv[1], "add") == 0 && strcmp(argv[2], "path") == 0)
    {
        add_path(argv[3]);
    }
    else if (argc == 4 && strcmp(argv[1], "rm") == 0 && strcmp(argv[2], "path") == 0)
    {
        rm_path(argv[3]);
        printf("ok\n");
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

void rm_path(const char *path)
{
    FILE *orig = fopen("path.txt", "r");
    if (orig == NULL)
    {
        printf("Erro: arquivo path.txt não encontrado.\n");
        return;
    }

    FILE *temp = fopen("path.tmp", "w");
    if (temp == NULL)
    {
        printf("Erro: não foi possível criar arquivo temporário.\n");
        fclose(orig);
        return;
    }

    char linha[1024];
    int removido = 0;

    while (fgets(linha, sizeof(linha), orig))
    {
        // remove \n do fgets
        linha[strcspn(linha, "\n")] = '\0';

        if (strcmp(linha, path) != 0)
        {
            fprintf(temp, "%s\n", linha);
        }
        else
        {
            removido = 1;
        }
    }

    fclose(orig);
    fclose(temp);

    remove("path.txt");
    rename("path.tmp", "path.txt");

    if (removido)
        printf("Caminho removido: %s\n", path);
    else
        printf("Caminho não encontrado.\n");
}

