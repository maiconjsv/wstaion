#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "platform.h"

/* ====== PROTÓTIPOS ====== */
void add_path(const char *path);
void rm_path(const char *path);
void run_for_each_path(void);

/* ====== MAIN ====== */
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Comando não reconhecido. Use: wstaion help\n");
        return 1;
    }

    if (argc == 4 && strcmp(argv[1], "add") == 0 && strcmp(argv[2], "path") == 0)
    {
        add_path(argv[3]);
    }
    else if (argc == 4 && strcmp(argv[1], "rm") == 0 && strcmp(argv[2], "path") == 0)
    {
        rm_path(argv[3]);
    }
    else if (argc == 2 && strcmp(argv[1], "workstart") == 0)
    {
        run_for_each_path();
    }
    else
    {
        printf("Comando não reconhecido. Use: wstaion help\n");
    }

    return 0;
}

/* ====== ADD PATH ====== */
void add_path(const char *path)
{
    if (!path || strlen(path) == 0)
    {
        printf("Erro: caminho inválido.\n");
        return;
    }

    ensure_config_dir();

    char filepath[1024];
    get_path_file(filepath, sizeof(filepath));

    FILE *f = fopen(filepath, "a");
    if (!f)
    {
        perror("Erro ao abrir arquivo");
        return;
    }

    fprintf(f, "%s\n", path);
    fclose(f);

    printf("Caminho adicionado: %s\n", path);
}

/* ====== REMOVE PATH ====== */
void rm_path(const char *path)
{
    char filepath[1024];
    get_path_file(filepath, sizeof(filepath));

    FILE *orig = fopen(filepath, "r");
    if (!orig)
    {
        printf("Arquivo de paths não encontrado.\n");
        return;
    }

    char tmp[1100];
    snprintf(tmp, sizeof(tmp), "%s.tmp", filepath);

    FILE *temp = fopen(tmp, "w");
    if (!temp)
    {
        fclose(orig);
        return;
    }

    char line[1024];
    int removed = 0;

    while (fgets(line, sizeof(line), orig))
    {
        line[strcspn(line, "\n")] = 0;

        if (strcmp(line, path) != 0)
            fprintf(temp, "%s\n", line);
        else
            removed = 1;
    }

    fclose(orig);
    fclose(temp);

    remove(filepath);
    rename(tmp, filepath);

    if (removed)
        printf("Caminho removido: %s\n", path);
    else
        printf("Caminho não encontrado.\n");
}

/* ====== WORKSTART ====== */
void run_for_each_path(void)
{
    char filepath[1024];
    get_path_file(filepath, sizeof(filepath));

    FILE *f = fopen(filepath, "r");
    if (!f)
    {
        printf("Arquivo de paths não encontrado.\n");
        return;
    }

    char cmd[1024];

    while (fgets(cmd, sizeof(cmd), f))
    {
        cmd[strcspn(cmd, "\n")] = 0;
        if (strlen(cmd) == 0)
            continue;

        printf("Iniciando: %s\n", cmd);
        run_command(cmd);
        sleep_ms(4000);
    }

    fclose(f);

    printf(
        "----------------------------------------\n"
        "          Bom trabalho!!\n"
        "----------------------------------------\n");
}
