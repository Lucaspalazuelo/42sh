/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** none
*/

#ifndef _MY_H
    #define _MY_H

    #include <unistd.h>
    #include <string.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <stddef.h>
    #include <dirent.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <pwd.h>
    #include <time.h>
    #include <stdbool.h>
    #include <linux/limits.h>
    #include <signal.h>
    #include <sys/wait.h>
    #include "criterion/criterion.h"

    #define RED "\x1b[31m"
    #define GREEN "\x1b[32m"
    #define YELLOW "\x1b[33m"
    #define BLUE "\x1b[34m"
    #define MAGENTA "\x1b[35m"
    #define CYAN "\x1b[36m"
    #define BOLD "\033[1m"
    #define RESET "\x1b[0m"
    #define STOP 999
    #define ERROR 84
    #define SUCCESS 0
    #define ON 0
    #define OFF 1
    #define FAIL 1
    #define OPEN_FAIL -1
    #define SEGFAULT 139
    #define ABORT 136
    #define FLOAT 134

typedef struct s_env {
    char *name;
    char *path;
    struct s_env *next;
}t_env;

typedef struct s_node {
    char *name;
    char *path;
    struct s_node *next;
}t_node;

typedef struct s_array {
    char **array;
    struct s_array *next;
}t_array;

typedef struct s_alias {
    char *name;
    char *cmd;
    struct s_alias *next;
}t_alias;

typedef struct var_quotation_mark {
    int i;
    int j;
    int start;
    int end;
}t_var_quotation_mark;

typedef struct redirection {
    int i;
    char **cmd;
    char *redirection;
    int direction;
}t_redir;

typedef struct s_all {
    int i;
    int j;
    int stop;
    int end;
    int the_return;
    char *read_file;
    t_env *s_node;
    t_node *node;
    t_array *s_array;
    t_alias *s_alias;
}all_t;

// project //
char *special_variables_replace(char *str, char *to_replace, char *with);

int is_built_in(char **array);
int exec_built(all_t *s_all, char **array, char **envp);
int choose_command(all_t *s_all, char **array, char **envp);
void execute_cmd(all_t *s_all, char **cmd, char *name, char **envp);
int get_abs_path(char **envp, char **cmd, char *name);
void check_env(all_t *s_all, char **envp);
void inverse_list(all_t *s_all);
char *my_getenv(char **env, const char *to_find);
void fill_list(all_t *s_all, char *name, char *path);
int exec_unsetenv(all_t *s_all, char **array);
int exec_setenv(all_t *s_all, char **array);
void exec_built_scd(all_t *s_all, char **array);
int add_env_check(char **array);
int exec_env(all_t *s_all);
char *my_getenv_in_list(all_t *s_all, char *to_find);
void changing_pwd(all_t *s_all, char *oldpwd);
void cd_env_path_dollar(all_t *s_all, char *name, char *cwd);
void cd_env_path(all_t *s_all, char *path, char *cwd);
int exec_cd(all_t *s_all, char **path, char **envp);
int the_end(all_t *s_all, char *buffer);
void delete_node(all_t *s_all, t_node *nodetodelete);
void delete_env(all_t *s_all, t_env *nodetodelete);
int check_is_file(char *array);
char **my_split(char *buffer, all_t *s_all);
char *rmv_quotation_mark(char *concat, int start, int end);
t_array *init_array(void);
t_alias *init_alias(void);
void put_array_in_linked_list(all_t *s_all, char **array);
void print_tab(char **array);
void free_linked_list_array(all_t *s_all, t_array *nodetodelete);
int fill_alias_node(all_t *s_all, char **array);
int is_alias(all_t *s_all, char **array);
void rmvcharac(char *str, char garbage);
void display_special_prompt(all_t *s_all);
char *check_quotation_mark(char *concat);
char *check_separator_char(char *str);
int start_mysh(all_t *s_all, char **array, char **envp);
void many_initialisation(all_t *s_all, char **envp);
int start(all_t *s_all, char **array, char **envp);
void free_start(all_t *s_all);
int is_redirection(char **array);
int redirection(all_t *s_all, char **array, char **envp);
void exec_redirection(all_t *s_all, char **cmd, char **envp, char *redirection);
int the_pipe(all_t *s_all, char **array);
int my_fork(char **my_tab, char *str, char **envp);
void check_oldpwd(all_t *s_all);
void double_redirection(all_t *s_all, char **cmd, char **envp, char
*redirection);
void inverse_redir(char **array);
int is_exit(all_t *s_all, char **array);
void double_sep_start(all_t *s_all, char **array);
int exec_repeat(all_t *s_all, char **array, char **envp);
int exec_where(all_t *s_all, char **array, char **envp);
int exec_which(all_t *s_all, char **array, char **envp);
char **start_with_alias(all_t *s_all, char **array, int count);
int globbings(char **array);
void do_globbings(char **array, int nb);
int search_globbings(char **array);
int is_globbing(char c);

// end project //

// util //
int my_putstr(char const *str);
void my_printf(char *str, ...);
int my_put_nbr(int nb);
int my_strlen(char const *str);
char *my_strdup(char *src);
char *my_strcpy(char *dest, char *src);
int my_strcmp_real(char *s_1, char *s_2);
char *my_revstr(char *str);
char **my_sp_str_to_word_array(char *str, char *charach);
void my_free_tab(char **tab);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strcat(char *dest, char const *src);
int my_atoi(char const *str);
int my_isnum(char const *str);
int check_upper(char *str);
int is_alpha_num(char charach);
char *my_strdupcat(char *dest, char const *src);
int my_char_is_alpha(char str);
int my_str_is_alpha(char const *str);
char **my_tab_cpy(char **old);
int my_getnbr(char *str);
void my_print_tab(char **tab);
int my_count_tab(char **array);
// end util //

#endif
