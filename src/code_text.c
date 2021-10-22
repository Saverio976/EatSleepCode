/*
** Saverio976, 2021
** EatSleepCode
** File description:
** master read and write on text
*/

#include <SFML/Graphics.h>
#include "constant.h"
#include "struct_context.h"
#include "my.h"
#include <stddef.h>
#include <stdlib.h>
char **read_text(char *);
char *sanitize_string(char *);
int check_if_keyword(char *);
int check_if_type(char *);

static void render_text_color(context_t *ctx, char *txt, sfVector2f *position,
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
    int x_tmp = position->x;
    char *cut;
    char tab[2] = {0};

    for (int i = 0; i < my_strlen(line); i++) {
        is_keyword = check_if_keyword(line + i);
        is_type = check_if_type(line + i);
        if (is_keyword != 0) {
            cut = malloc(sizeof(char) * (is_keyword + 1));
            my_strncpy(cut, line + i, is_keyword);
            cut[is_keyword] = '\0';
            position->x += (sfText_getGlobalBounds(ctx->text)).width;
            render_text_color(ctx, cut, position, KYW_COLOR);
            free(cut);
            i += is_keyword - 1;
        } else if (is_type != 0) {
            cut = malloc(sizeof(char) * (is_type + 1));
            my_strncpy(cut, line + i, is_type);
            cut[is_type] = '\0';
            position->x += (sfText_getGlobalBounds(ctx->text)).width;
            render_text_color(ctx, cut, position, TYP_COLOR);
            free(cut);
            i += is_type - 1;
        } else {
            tab[0] = line[i];
            position->x += (sfText_getGlobalBounds(ctx->text)).width;
            render_text_color(ctx, tab, position, DFL_COLOR);
        }
    }
    position->x = x_tmp;
}

static void update_text(context_t *ctx, char *path)
{
    sfVector2f position = {50, 30};
    char **text_char = read_text(path);
    int len_max = my_arraylen(text_char);

    for (int i = ctx->scroll_y; i < len_max; i++) {
        position.y += 20;
        set_auto_color(ctx, text_char[i], &position);
        free(text_char[i]);
    }
    free(text_char);
}

void render_code(context_t *ctx, char *path)
{
    update_text(ctx, path);
}
