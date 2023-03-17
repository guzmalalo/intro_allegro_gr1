#include <stdio.h>
#include <assert.h>
#include <allegro5/allegro5.h>


int main() {

    // Declaration
    ALLEGRO_DISPLAY * display = NULL;
    ALLEGRO_COLOR vert = {0};

    // Initialisation d'allegro
    assert(al_init());

    // Creation -> allocation
    display = al_create_display(800, 600);
    // Couleur
    vert = al_map_rgb(0,255,0);

    // Changer le titre
    al_set_window_title(display, "Hello world");

    // Changer la couleur
    al_clear_to_color(vert);

    // First display
    al_flip_display();

    // Pause
    al_rest(5);

    return 0;
}