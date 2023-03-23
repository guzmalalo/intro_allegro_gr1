#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <assert.h>
#include <stdio.h>

#define LARGEUR 800
#define HAUTEUR 600
#define COULEUR_ALEA al_map_rgb(rand()%256,rand()%256,rand()%256)
#define BLANC al_map_rgb(255,255,255)

typedef struct {
    int x, y, largeur, hauteur;
} Rect;

void dessiner(Rect r) {
    al_clear_to_color(BLANC);
    al_draw_filled_rectangle(r.x, r.y, r.x + r.largeur, r.y + r.hauteur, COULEUR_ALEA);
    al_flip_display();
}

void centrerRectangle(Rect *rectangle, int largeur, int hauteur) {
    rectangle->largeur = largeur;
    rectangle->hauteur = hauteur;
    rectangle->x = LARGEUR / 2 - rectangle->largeur / 2;
    rectangle->y = HAUTEUR / 2 - rectangle->hauteur / 2;
}

int main() {
    bool fini = false;
    Rect rectangle;
    ALLEGRO_DISPLAY *fenetre = NULL;
    ALLEGRO_EVENT_QUEUE *fifo = NULL;
    ALLEGRO_EVENT event;

    assert(al_init());
    assert(al_init_primitives_addon());
    assert(al_install_keyboard());

    centrerRectangle(&rectangle, 80, 60);

    fenetre = al_create_display(LARGEUR, HAUTEUR);
    assert(fenetre != NULL);
    al_set_window_title(fenetre, "ECE");
    //al_set_window_position(fenetre, 0, 0);

    fifo = al_create_event_queue();
    assert(fifo); // fifo != NULL
    al_register_event_source(fifo, al_get_keyboard_event_source());
    al_register_event_source(fifo, al_get_display_event_source(fenetre));

    dessiner(rectangle);

    while (!fini) {
        al_wait_for_event(fifo, &event);
        printf("On vient de piocher un event de type %d.\n", event.type);
        switch (event.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE: { // 42
                fini = true;
                break;
            }
            case ALLEGRO_EVENT_KEY_DOWN: { // 10
                if (event.keyboard.keycode) {

                }
            }
            default: {
                printf("Cet event est ignore.\n");
            }
        }
    }

    al_destroy_display(fenetre);
    al_destroy_event_queue(fifo);

    return 0;
}
