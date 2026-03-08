#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#ifndef VERSION
#define VERSION "dev"
#endif
#ifdef _WIN32
#include <windows.h>
#include <direct.h>
#else
#include <unistd.h>
#include <sys/stat.h>
#endif

void add_path(char *path);
void rm_path(const char *path);
void run_for_each_path(void);
void ensure_config_dir(void);
void get_path_file(char *buffer, size_t size);
void show_version();
void show_help();
void list_paths();

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Command not recognized, use wstation help to verify commands.\n");
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
        printf("Error: The path was missing.\n");
    }
    else if (argc == 2 && strcmp(argv[1], "workstart") == 0)
    {
        run_for_each_path();
    }
    else if (argc == 2 && (strcmp(argv[1], "-v" ) == 0 
            || strcmp(argv[1], "--version")== 0))
    {
        show_version();
        return 0;
    }
    else if(argc == 2 && strcmp(argv[1], "help") == 0)
    {
        show_help();
        return 0;
    }
    else if(argc == 2 && (strcmp(argv[1], "list") == 0))
    {
        list_paths();
    }

    else
    {
        printf("Command not recognized, use wstation help to verify commands.\n");
    }

    return 0;
}

/* ===================== FUNCTIONS ===================== */

void ensure_config_dir(void)
{
    #ifdef _WIN32
        const char *home = getenv("USERPROFILE");
    #else
        const char *home = getenv("HOME");
    #endif

        if (!home)
        {
            fprintf(stderr, "Error: HOME variable not defined.\n");
            exit(1);
        }

        char dir[1024];
        snprintf(dir, sizeof(dir), "%s/.config/wstaion", home);

    #ifdef _WIN32
        if (_mkdir(dir) == -1 && errno != EEXIST)
    #else
        if (mkdir(dir, 0755) == -1 && errno != EEXIST)
    #endif
        {
            perror("Error creating configuration directory.");
            exit(1);
        }
}

void show_version()
{
    printf("wstaion %s\n", VERSION);
    printf("https://github.com/maiconjsv/wstaion\n");
}

void show_help()
{
    printf(
            "wstaion - workspace launcher\n"
            "\n"
            "Usage:\n"
            "  wstaion <command> [arguments]\n"
            "\n"
            "Commands:\n"
            "  \033[32madd path <path>\033[0m        Add a command or path to the startup list\n"
            "  \033[32mrm path <path>\033[0m         Remove a saved path\n"
            "  \033[32mworkstart\033[0m              Run all saved paths\n"
            "  \033[32mhelp\033[0m                   Show this help message\n"
            "  \033[32m-v, --version\033[0m          Show program version\n"
            "\n"
            "Examples:\n"
            "  wstaion add path \"code ~/Projects/api\"\n"
            "  wstaion add path \"firefox\"\n"
            "  wstaion rm path \"firefox\"\n"
            "  wstaion workstart\n"
            "\n"
            "Config file:\n"
            "\033[1;36m~/.config/wstaion/path.txt\033[0m\n"
            "\n"
            "Project repository:\n"
            "  https://github.com/maiconjsv/wstaion\n"
        );
}

void get_path_file(char *buffer, size_t size)
{
    #ifdef _WIN32
        const char *home = getenv("USERPROFILE");
    #else
        const char *home = getenv("HOME");
    #endif
        if (!home)
        {
            fprintf(stderr, "Error: HOME variable not defined.\n");
            exit(1);
        }

        snprintf(buffer, size,
                "%s/.config/wstaion/path.txt",
                home);
}

/* ===================== ADD PATH ===================== */

void add_path(char *path)
{
    if (!path || strlen(path) == 0)
    {
        printf("Error: Invalid path.\n");
        return;
    }

    ensure_config_dir();

    char filepath[1024];
    get_path_file(filepath, sizeof(filepath));

    FILE *arquivo = fopen(filepath, "a");
    if (!arquivo)
    {
        perror("Error to open paths file");
        return;
    }

    fprintf(arquivo, "%s\n", path);
    fclose(arquivo);

    printf("Path added: %s\n", path);
}

/* ===================== REMOVE PATH ===================== */

void rm_path(const char *path)
{
    char filepath[1024];
    get_path_file(filepath, sizeof(filepath));

    FILE *orig = fopen(filepath, "r");
    if (!orig)
    {
        printf("Error: path.txt file not found.\n");
        return;
    }

    char tmpfile[2024];
    snprintf(tmpfile, sizeof(tmpfile), "%s.tmp", filepath);

    FILE *temp = fopen(tmpfile, "w");
    if (!temp)
    {
        perror("Error to create temp file");
        fclose(orig);
        return;
    }

    char linha[1024];
    int removido = 0;

    while (fgets(linha, sizeof(linha), orig))
    {
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

    remove(filepath);
    rename(tmpfile, filepath);

    if (removido)
        printf("Path deleted: %s\n", path);
    else
        printf("Path not found.\n");
}

/* ===================== WORKSTART ===================== */

void run_for_each_path(void)
{
    char filepath[1024];
    get_path_file(filepath, sizeof(filepath));

    FILE *arquivo = fopen(filepath, "r");
    if (!arquivo)
    {
        printf("Error: path.txt not founded.\n");
        return;
    }

    char path[1024];

    while (fgets(path, sizeof(path), arquivo))
    {
        path[strcspn(path, "\n")] = '\0';

        if (strlen(path) == 0)
            continue;

        printf("Starting: %s\n", path);

        char cmd[1200];

#ifdef _WIN32
        snprintf(cmd, sizeof(cmd), "start \"\" %s", path);
#else
        snprintf(cmd, sizeof(cmd), "%s &", path);
#endif

if(system(cmd) == -1)
{
    perror("Erro ao executar comando");
}

#ifdef _WIN32
        Sleep(5000);
#else
        sleep(5);
#endif
    }

    fclose(arquivo);

    printf(
        "--------------------------------------------------------\n"
        "                All systems running.\n"
        "                Coffee required.\n"
        "                Good luck, developer.\n"
        "--------------------------------------------------------\n");
}

void list_paths()
{
    char filepath[1024];
    get_path_file(filepath, sizeof(filepath));

    FILE *arquivo = fopen(filepath, "r");
    if (!arquivo)
    {
        printf("No paths configured.\n");
        return;
    }

    char linha[1024];
    int i = 1;

    while (fgets(linha, sizeof(linha), arquivo))
    {
        linha[strcspn(linha, "\n")] = '\0';
        printf("%d - %s\n", i++, linha);
    }

    fclose(arquivo);
}