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
    int i = 0;
    char newline = '\n';

    if (fd < 0)
        write_file_error(ctx->swap, ": Error when saving modified data");
    while (ctx->text_file[i] != NULL) {
        write(fd, ctx->text_file[i], my_strlen(ctx->text_file[i]));
        write(fd, &newline, 1);
        i++;
    }
    close(fd);
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
    i++;
    for (; i < len; i++)
        new[i] = ctx->text_file[ctx->cursor_y][i - 1];
    new[i] = '\0';
    free(ctx->text_file[ctx->cursor_y]);
    ctx->text_file[ctx->cursor_y] = new;
}
