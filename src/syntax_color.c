/*
** Saverio976, 2021
** EatSleepCode
** File description:
** syntax function
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my.h"
#include "constant.h"
#include "struct_context.h"
void render_text_color(context_t *, char *, sfVector2f *, sfColor);

static char *cut_text(char *cursor, int len)
{
    char *cut = malloc(sizeof(char) * (len + 1));

    my_strncpy(cut, cursor, len);
    cut[len] = '\0';
    return (cut);
}

int higth_keyword(char *cursor, int len, context_t *ctx, sfVector2f *position)
{
    char *cut = cut_text(cursor, len);

    position->x += (sfText_getGlobalBounds(ctx->text)).width;
    render_text_color(ctx, cut, position, KYW_COLOR);
    free(cut);
    return (len - 1);
}

int higth_type(char *cursor, int len, context_t *ctx, sfVector2f *position)
{
    char *cut = cut_text(cursor, len);

    position->x += (sfText_getGlobalBounds(ctx->text)).width;
    render_text_color(ctx, cut, position, TYP_COLOR);
    free(cut);
    return (len - 1);
}

int higth_preproces(char *cursor, int len, context_t *ctx, 
                    sfVector2f *position)
{
    char *cut = cut_text(cursor, len);

    position->x += (sfText_getGlobalBounds(ctx->text)).width;
    render_text_color(ctx, cut, position, PRO_COLOR);
    free(cut);
    return (len - 1);
}
