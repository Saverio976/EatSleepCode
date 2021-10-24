/*
** EPITECH PROJECT, 2021
** EatSleepCode
** File description:
** update the ctx.text_file with a char
*/

#include <SFML/Graphics.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "struct_context.h"
#include "eatsleepcode.h"
#include "my.h"

void save_text_modif(context_t *ctx)
{
    reset_file_from(ctx->path, ctx->swap);
}

void save_swap_modif(context_t *ctx)
{
    int fd = open(ctx->swap, O_WRONLY | O_TRUNC);

    if (fd < 0)
        write_file_error(ctx->swap, ": Error when saving modified data");
    for (int i = 0; ctx->text_file[i] != NULL; i++)
        write(fd, ctx->text_file[i], my_strlen(ctx->text_file[i]));
    close(fd);
}

void add_new_line_at(context_t *ctx)
{
    int len = my_strlen(ctx->text_file[ctx->cursor_y]) - 1;
    char *new1 = malloc(sizeof(char) * (ctx->cursor_x + 2));
    char *new2 = malloc(sizeof(char) * (len - ctx->cursor_x + 2));
    char **new_text_file;
    int j;

    my_init_nstr(new1, '\0', ctx->cursor_x + 2);
    my_strncpy(new1, ctx->text_file[ctx->cursor_y], ctx->cursor_x);
    new1[ctx->cursor_x] = '\n';
    my_init_nstr(new2, '\0', len + 1);
    my_strcpy(new2, ctx->text_file[ctx->cursor_y] + ctx->cursor_x);
    new_text_file = malloc(sizeof(char *) * (my_arraylen(ctx->text_file) + 2));
    for (int i = 0; i < ctx->cursor_y; i++)
        new_text_file[i] = ctx->text_file[i];
    new_text_file[ctx->cursor_y] = new1;
    new_text_file[ctx->cursor_y + 1] = new2;
    for (j = ctx->cursor_y + 2; ctx->text_file[j - 1]; j++)
        new_text_file[j] = ctx->text_file[j - 1];
    new_text_file[j] = NULL;
    free(ctx->text_file[ctx->cursor_y]);
    free(ctx->text_file);
    ctx->text_file = new_text_file;
}

static void remove_line_at(context_t *ctx, int len_last_line)
{
    int i;
    int len = my_strlen(ctx->text_file[ctx->cursor_y]) + len_last_line;
    char *new;
    char **new_text_file;

    new_text_file = malloc(sizeof(char *) * (my_arraylen(ctx->text_file) + 1));
    new = malloc(sizeof(char) * (len + 2));
    my_init_nstr(new, '\0', len + 2);
    my_strncat(new, ctx->text_file[ctx->cursor_y - 1], len_last_line - 2);
    my_strcat(new, ctx->text_file[ctx->cursor_y]);
    free(ctx->text_file[ctx->cursor_y - 1]);
    free(ctx->text_file[ctx->cursor_y]);
    for (i = 0; i < (ctx->cursor_y - 1); i++)
        new_text_file[i] = ctx->text_file[i];
    new_text_file[i] = new;
    for (i = i + 2; ctx->text_file[i] != NULL; i++)
        new_text_file[i - 1] = ctx->text_file[i];
    new_text_file[i - 1] = NULL;
    free(ctx->text_file);
    ctx->text_file = new_text_file;
}

void remove_text_at(context_t *ctx)
{
    int len = my_strlen(ctx->text_file[ctx->cursor_y]);
    char *new;
    int i;

    if (ctx->cursor_x == 0) {
        remove_line_at(ctx, len);
        (ctx->cursor_y)--;
    } else {
        new = malloc(sizeof(char) * len);
        for (i = 0; i < ctx->cursor_x - 1; i++)
            new[i] = ctx->text_file[ctx->cursor_y][i];
        for (i = i + 1; ctx->text_file[ctx->cursor_y][i]; i++)
            new[i - 1] = ctx->text_file[ctx->cursor_y][i];
        new[i - 1] = '\0';
        free(ctx->text_file[ctx->cursor_y]);
        ctx->text_file[ctx->cursor_y] = new;
    }
}

void update_text_unicode(context_t *ctx, sfUint32 u)
{
    int len = my_strlen(ctx->text_file[ctx->cursor_y]) + 2;
    char *new = malloc(sizeof(char) * len);
    int i;
    char c;

    if (u > 127)
        return;
    c = (char) u;
    for (i = 0; i < ctx->cursor_x; i++)
        new[i] = ctx->text_file[ctx->cursor_y][i];
    new[i] = c;
    for (i = i + 1; ctx->text_file[ctx->cursor_y][i]; i++)
        new[i] = ctx->text_file[ctx->cursor_y][i - 1];
    new[i] = '\0';
    free(ctx->text_file[ctx->cursor_y]);
    ctx->text_file[ctx->cursor_y] = new;
}
