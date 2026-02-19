#include "shell.h"
#include "config.h"
#include "string.h"

extern void print_string(char* str);
extern char get_char();

void shell_init() {
    print_string("Welcome to (Your OS name)\n");
    print_string("Type help to show all comands\n");
    shell_loop();
}

void shell_loop() {
    char buffer[MAX_BUFFER_SIZE];
    int index = 0;

    while (1) {
        print_string(PROMPT);
        index = 0;

        while (1) {
            char c = get_char();

            if (c == '\n' || c == '\r') {
                buffer[index] = '\0';
                print_string("\n");
                break;
            } 
            else if (c == '\b' && index > 0) {
                index--;
                print_string("\b \b");
            } 
            else if (index < MAX_BUFFER_SIZE - 1) {
                buffer[index++] = c;
                char echo[2] = {c, '\0'};
                print_string(echo);
            }
        }

        if (index > 0) {
            handle_command(buffer);
        }
    }
}

void handle_command(char* input) {
    if (strcmp(input, "help") == 0) {
        cmd_help();
    } else if (strcmp(input, "reboot") == 0) {
        cmd_reboot();
    } else if (strcmp(input, "clear") == 0) {
        cmd_clear();
    } else {
        print_string("ERROR: COMAND DON'T FIND\n");
    }
}


void cmd_help() {
    print_string("Comandos disponiveis:\n");
    print_string("  help   - Show this list\n");
    print_string("  clear  - Clear screen (depende da sua implementacao)\n");
    print_string("  reboot - Restart System\n");
}

void cmd_reboot() {
    print_string("Restarting...");
}

void cmd_clear() {
    print_string("Cleaning screen...\n");
}