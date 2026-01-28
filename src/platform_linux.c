#include "platform.h"
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

void ensure_config_dir(void)
{
    const char *home = getenv("HOME");
    if (!home)
    {
        fprintf(stderr, "Erro: HOME não definido.\n");
        exit(1);
    }

    char dir[1024];
    snprintf(dir, sizeof(dir), "%s/.config/wstaion", home);

    if (mkdir(dir, 0755) == -1 && errno != EEXIST)
    {
        perror("Erro ao criar diretório");
        exit(1);
    }
}

void get_path_file(char *buffer, size_t size)
{
    const char *home = getenv("HOME");
    snprintf(buffer, size, "%s/.config/wstaion/path.txt", home);
}

void run_command(const char *cmd)
{
    pid_t pid = fork();

    if (pid == 0)
    {
        execl("/bin/sh", "sh", "-c", cmd, NULL);
        _exit(1);
    }
}

void sleep_ms(int ms)
{
    usleep(ms * 1000);
}
