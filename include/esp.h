/*
** EPITECH PROJECT, 2021
** EatSleepCode
** File description:
** project header
*/

#ifndef ESP_H_
    #define ESP_H_

    #include <SFML/Graphics.h>
    #include "my_list.h"
    #include "my_dico.h"

static const int OFFSET_CODE_X = 10;
static const int OFFSET_CODE_Y = 10;

static const char BACKGROUND_PATH[] = "./assets/images/black_bg.png";
static const char FONT_PATH[] = "./assets/fonts/menlo.ttf";

// ----------------------------------------------------------------------------

typedef struct file_edit_t file_edit_t;
typedef struct window_t window_t;

struct file_edit_t {
    char filename[255];
    char *pathfile;
    int nb_lines;
    int charactr_size;
    list_t *list_line;
    list_t *curr_line;
    list_t *line_top;
    list_t *line_bot;
    int y;
    int global_x;
    int global_y;
};

struct window_t {
    sfRenderWindow *win;
    sfTexture *bg_texture;
    sfSprite *bg_sprite;
    sfFont *font;
    sfText *text;
    file_edit_t *curr_file;
};

// ---------------------------------------------------------------------------

dico_t *argparse(int ac, char **av);

file_edit_t *getfile(char const *pathfile);

int handle_event(sfRenderWindow *window, file_edit_t *file);

int file_edit_t_display(file_edit_t *file, sfRenderWindow *win, sfText *text);

void file_edit_t_destroy(file_edit_t *file);

void destroy_window(window_t *window);

window_t *create_window(dico_t *args, int width, int heigth);

int window_loop(window_t *window, __attribute__((unused)) dico_t *args);

#endif
