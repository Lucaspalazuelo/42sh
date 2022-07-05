/*
** EPITECH PROJECT, 2022
** builtin_cd.c
** File description:
** Created by louis on 21/01/2022.
*/

#include "my.h"

int cd_env_path_dollar_scd(char *path, int lock, char *name)
{
    if (path == NULL) {
        my_printf("%s: Undefined variable.\n", &name[1]);
        return 1;
    }
    if (lock == 1) {
        my_printf("%s: No match.\n", path);
        free(path);
        return 1;
    }
    if (path[0] == '-') {
        my_printf("Usage: cd [-plvn][-|<dir>].\n");
        free(path);
        return 1;
    }
    return 0;
}

void cd_env_path_dollar(all_t *s_all, char *name, char *cwd)
{
    struct stat buf;
    int lock = 0;
    if (check_upper(&name[1]) == 1)
        return my_printf("%s: Undefined variable.\n", &name[1]);
    if (my_strcmp_real(&name[1], "LS_COLORS") == 0)
        lock = 1;
    char *path = my_getenv_in_list(s_all, &name[1]);
    if (cd_env_path_dollar_scd(path, lock, name) == 1)
        return;
    stat(path, &buf);
    if (S_ISDIR(buf.st_mode) != 1) {
        my_printf("%s: No such file or directory.\n", path);
        free(path);
        return;
    }
    if (chdir(path) == 0)
        changing_pwd(s_all, cwd);
    free(path);
}

void cd_env_path(all_t *s_all, char *path, char *cwd)
{
    struct stat s;

    stat(path, &s);
    if (chdir(path) == 0)
        changing_pwd(s_all, cwd);
    else if (S_ISREG(s.st_mode) == 1) {
        my_printf("%s: Not a directory.\n", path);
        s_all->the_return = 1;
    } else {
        my_printf("%s: No such file or directory.\n", path);
        s_all->the_return = 1;
    }
}

int exec_cd_dash(all_t *s_all, char **path, char *cwd)
{
    if (my_strcmp_real(path[1], "-") == 0 && path[1][1] == '\0'
    && path[2] == NULL) {
        char *new = my_getenv_in_list(s_all, "OLDPWD");
        chdir(new);
        free(new);
        changing_pwd(s_all, cwd);
        return 1;
    }
    if (path[1][0] == '-') {
        my_printf("Usage: cd [-plvn][-|<dir>].\n");
        return 1;
    }
    return 0;
}

int exec_cd(all_t *s_all, char **path, char **envp)
{
    char cwd[PATH_MAX];
    getcwd(cwd, sizeof(cwd));
    if (path[1] == NULL || my_strcmp_real(path[1], "~") == 0
    || my_strcmp_real(path[1], "home") == 0
    || my_strcmp_real(path[1], "HOME") == 0
    || my_strcmp_real(path[1], "$home") == 0) {
        chdir(&my_getenv(envp, "HOME")[1]);
        changing_pwd(s_all, cwd);
        return 0;
    }
    if (exec_cd_dash(s_all, path, cwd) == 1)
        return 0;
    if (path[1][0] == '$')
        cd_env_path_dollar(s_all, path[1], cwd);
    else
        cd_env_path(s_all, path[1], cwd);
    return 1;
}
