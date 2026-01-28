#ifndef PLATFORM_H
#define PLATFORM_H

#include <stddef.h>

void ensure_config_dir(void);
void get_path_file(char *buffer, size_t size);
void run_command(const char *cmd);
void sleep_ms(int ms);

#endif
