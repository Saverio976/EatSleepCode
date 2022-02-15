/*
** EPITECH PROJECT, 2022
** ESP
** File description:
** create window
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my_dico.h"
#include "my_puts.h"
#include "esp.h"

static char set_csfml_sprite(window_t *window)
{
    window->bg_texture = sfTexture_createFromFile(BACKGROUND_PATH, NULL);
    if (window->bg_texture == NULL) {
        my_printf("[EatSleepCode][error] can't load %s\n", BACKGROUND_PATH);
        return (0);
    }
    window->bg_sprite = sfSprite_create();
    if (window->bg_sprite == NULL) {
        my_printf("[EatSleeĈode][error] sfSprite_create error");
        return (0);
    }
    sfSprite_setTexture(window->bg_sprite, window->bg_texture, sfTrue);
    return (1);
}

static char set_csfml_text(window_t *window)
{
    window->font = sfFont_createFromFile(FONT_PATH);
    if (window->font == NULL) {
        my_printf("[EatSleepCode][error] can't load %s\n", FONT_PATH);
        return (0);
    }
    window->text = sfText_create();
    if (window->text == NULL) {
        my_printf("[EatSleeĈode][error] sfText_create error");
        return (0);
    }
    sfText_setFont(window->text, window->font);
    return (1);
}

static char set_csfml(window_t *window, int width, int heigth, char const *str)
{
    sfVideoMode mode = {width, heigth, 32};

    window->win = sfRenderWindow_create(mode, str, sfClose | sfResize, NULL);
    if (window->win == NULL) {
        my_printf("[EatSleepCode][error] sfRenderWindow_create error");
        return (0);
    }
    if (set_csfml_text(window) == 0) {
        return (0);
    }
    if (set_csfml_sprite(window) == 0) {
        return (0);
    }
    return (1);
}

static char set_file_edit(window_t *window, char const *str)
{
    file_edit_t *file = NULL;

    my_printf("ici\n");
    file = getfile(str);
    if (file == NULL) {
        my_printf("[EatSleepCode][error] getfile error");
        return (0);
    }
    window->curr_file = file;
    return (1);
}

window_t *create_window(dico_t *args, int width, int heigth)
{
    char const *file_path = NULL;
    window_t *window = NULL;

    my_printf("oooo\n");
    if (args == NULL) {
        my_printf("so bad\n");
    }
    file_path = (args == NULL) ? NULL : dico_t_get_value(args, "file");
    if (file_path == NULL) {
        return (NULL);
    }
    my_printf("kkkkk\n");
    window = malloc(sizeof(window_t));
    if (window == NULL) {
        return (NULL);
    }
    my_printf("kklllll\n");
    if (set_csfml(window, width, heigth, file_path) == 0) {
        return (NULL);
    }
    my_printf("mmmmmm\n");
    if (set_file_edit(window, file_path) == 0) {
        return (NULL);
    }
    my_printf("qqqqqq\n");
    return (window);
}
