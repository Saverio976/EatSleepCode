/*
** EPITECH PROJECT, 2021
** EatSleepCode
** File description:
** All non static file functions
*/

#ifndef EATSLEEPCODE_H_
    #define EATSLEEPCODE_H_

    #include <SFML/Graphics.h>
    #include "struct_context.h"

// src/code_text.c
void render_text_color(context_t *, char *, sfVector2f *, sfColor);
void render_code(context_t *);

// src/eat_sleep_code.c
int eat_sleep_code(int, char **);

// src/eat_sleep_code_interface.c
sfRenderWindow *create_window(unsigned int, unsigned int, char const *);
sfSprite *create_background(char const *, sfTexture **);
context_t *create_context(unsigned int, unsigned int, char const *, 
                            char const *);
int eat_sleep_code_interface(char const *, char const *);

// src/file_copy_to.c
int copy_file_to(char const *, char const *);
int reset_file_from(char const *, char const *);

// src/free_pointer.c
void free_pointer_bg(sfTexture *, sfSprite *);
void free_pointer_ctx(context_t *);

// src/master_sfevents.c
void master_event_window(context_t *, sfEvent *);

// src/read_text.c
char **read_text(char const *);

// src/syntax_color.c
int higth_keyword(char *, int, context_t *, sfVector2f *);
int higth_type(char *, int, context_t *, sfVector2f *);
int higth_preproces(char *, int, context_t *, sfVector2f *);

// src/utils.c
char *sanitize_string(char *);
int check_if_keyword(char *);
int check_if_type(char *);
int check_if_preprocess(char *);
int write_file_error(char const *, char *);

// src/update_text.c
void update_text_unicode(context_t *, sfUint32);
void save_swap_modif(context_t *);
void save_text_modif(context_t *);
void remove_text_at(context_t *);

#endif
