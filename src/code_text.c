/*
** Saverio976, 2021
** EatSleepCode
** File description:
** master read and write on text
*/

#include <SFML/Graphics.h>
#include <stddef.h>
#include <stdlib.h>
#include "constant.h"
#include "struct_context.h"
#include "eatsleepcode.h"
#include "my.h"

void render_text_color(context_t *ctx, char *txt, sfVector2f *position,
                                sfColor color)
{
    sfText_setString(ctx->text, sanitize_string(txt));
    sfText_setFont(ctx->text, ctx->font);
    sfText_setCharacterSize(ctx->text, 18);
    sfText_setPosition(ctx->text, *position);
    sfText_setFillColor(ctx->text, color);
    sfRenderWindow_drawText(ctx->window, ctx->text, NULL);
}

static void set_auto_color(context_t *ctx, char *line, sfVector2f *position)
{
    int is_keyword = 0;
    int is_type = 0;
    int is_prepro = 0;
    char tab[2] = {0};

    for (int i = 0; i < my_strlen(line); i++) {
        is_keyword = check_if_keyword(line + i);
        is_type = check_if_type(line + i);
        is_prepro = check_if_preprocess(line + i);
        if (is_prepro != 0)
            i += higth_preproces(line + i, is_prepro, ctx, position);
        else if (is_keyword != 0)
            i += higth_keyword(line + i, is_keyword, ctx, position);
        else if (is_type != 0)
            i += higth_type(line + i, is_type, ctx, position);
        else {
            tab[0] = line[i];
            position->x += (sfText_getGlobalBounds(ctx->text)).width;
            render_text_color(ctx, tab, position, DFL_COLOR);
        }
    }
}

static void put_text_on(context_t *ctx)
{
    sfVector2f position = {START_TXT_X, START_TXT_Y};
    int len_max;

    len_max = my_arraylen(ctx->text_file);
    for (int i = ctx->scroll_y; i < len_max; i++) {
        //position.y += SPACE_BETWEEN_LINE;
        set_auto_color(ctx, ctx->text_file[i], &position);
        position.x = START_TXT_X;
        position.y += (sfText_getGlobalBounds(ctx->text)).height + LINE_PADING;
    }
}

static void put_cursor(context_t *ctx)
{
    sfVector2f position = {START_TXT_X, START_TXT_Y};
    char tab[2] = {0};

    for (int i = 0; i < ctx->cursor_y; i++) {
        sfText_setString(ctx->text, ctx->text_file[i]);
        position.y += (sfText_getGlobalBounds(ctx->text)).height;
    }
    for (int i = 0; i < ctx->cursor_x; i++) {
        tab[0] = ctx->text_file[ctx->cursor_y][i];
        sfText_setString(ctx->text, tab);
        position.x += (sfText_getGlobalBounds(ctx->text)).width;
    }
    render_text_color(ctx, CURSOR_CHAR, &position, CURSOR_COLOR);
}

void render_code(context_t *ctx)
{
    put_text_on(ctx);
    put_cursor(ctx);
}
