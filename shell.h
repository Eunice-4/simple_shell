#ifndef SHELL_H
#define SHELL_H

void display_prompt(void);
void run_command(char *user_input);
int my_strcmp(const char *strA, const char *strB);
int custom_atoi(const char *str);
void cd(char *path);

#endif
