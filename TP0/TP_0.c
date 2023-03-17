#include <stdio.h>
#include <assert.h>
#include <allegro5/allegro5.h>


int main() {

    // Declaration
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *queue = NULL;
    ALLEGRO_EVENT event = {};
    int fini = 0;

    // Initialisation d'allegro
    assert(al_init());
    // Initialisation clavier
    assert(al_install_keyboard());
    // Initialisation souris
    assert(al_install_mouse());

    // Creation display-> allocation
    display = al_create_display(800, 600);

    // Creation file
    queue = al_create_event_queue();

    // Ajouter les sources
    // display
    al_register_event_source(queue, al_get_display_event_source(display));
    // clavier
    al_register_event_source(queue, al_get_keyboard_event_source());
    // souris
    al_register_event_source(queue, al_get_mouse_event_source());

    // Changer le titre
    al_set_window_title(display, "TP0");

    // First display
    al_flip_display();

    while (!fini) {

        al_wait_for_event(queue, &event);

        switch (event.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                fini = 1;
                break;
            case ALLEGRO_EVENT_KEY_DOWN:
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_ESCAPE:
                        fini = 1;
                        break;
                    default:
                        printf("La touche est %s \n", al_keycode_to_name(event.keyboard.keycode));
                        break;
                }
                break;
            case ALLEGRO_EVENT_MOUSE_AXES:
                printf("x: %d , y: %d \n", event.mouse.x, event.mouse.y);
                break;
            case  ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                al_clear_to_color(al_map_rgb(rand()%255, rand()%255, rand()%255));
                al_flip_display();
                break;
        }

    }

    // Free
    al_destroy_display(display);
    al_destroy_event_queue(queue);

    return 0;
}