#ifndef SHELL_H
#define SHELL_H

#define PROMPT "OS_Kernel >> "

void shell_init();
void shell_loop();
void handle_command(char* input);

void cmd_help();
void cmd_clear();
void cmd_reboot();

#endif