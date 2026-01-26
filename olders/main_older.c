#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Verificação básica de quantidade de argumentos
    // Esperado: programa (0) + add (1) + path (2) + "caminho" (3) = 4 argumentos
    if (argc != 4) {
        printf("Erro: Formato invalido.\n");
        printf("Uso: wstation add path \"C:\\caminho\\arquivo.exe\"\n");
        return 1;
    }

    // Validação dos comandos "add" e "path"
    // strcmp retorna 0 quando as strings são iguais
    if (strcmp(argv[1], "add") != 0 || strcmp(argv[2], "path") != 0) {
        printf("Erro: Comando desconhecido. Voce quis dizer 'add path'?\n");
        return 1;
    }

    // caminho recebido do terminal
    char *caminhoRecebido = argv[3];

    // Operação de Arquivo
    FILE *arquivo = fopen("config.txt", "a");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo de registro");
        return 1;
    }

    // Gravando o caminho
    if (fprintf(arquivo, "%s\n", caminhoRecebido) > 0) {
        printf("Sucesso: O caminho \"%s\" foi registrado.\n", caminhoRecebido);
    } else {
        printf("Erro ao gravar no arquivo.\n");
    }

    fclose(arquivo);
    return 0;
}