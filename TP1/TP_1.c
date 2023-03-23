#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#define LARGEUR 800
#define HAUTEUR 600

int main()
{
    // == Declarations variables
    // Display
    ALLEGRO_DISPLAY *display = NULL;
    // Color
    ALLEGRO_COLOR random_color = {0};
    // Events
    ALLEGRO_EVENT_QUEUE *queue = NULL;
    ALLEGRO_EVENT event = {0};
    // Loop control
    int isEnd = 0;
    // Coordinates
    float x1, x2, x3;
    float y1, y2, y3;

    // == Initialisations
    // Allegro
    assert(al_init());
    // Keyboard
    assert(al_install_keyboard());
    // Primitives
    assert(al_init_primitives_addon());
    // Random numbers seed
    srand(time(0));

    // == Creation
    // Display
    // Initial flags for displays
    al_set_new_display_flags(ALLEGRO_RESIZABLE);
    // Use only one buffer
    al_set_new_display_option(ALLEGRO_SINGLE_BUFFER, 1, ALLEGRO_REQUIRE);
    display = al_create_display(LARGEUR, HAUTEUR);
    assert(display != NULL);
    // Set title
    al_set_window_title(display, "TP 1");

    // Events
    queue = al_create_event_queue();
    assert(queue != NULL);
    // - Register events from display
    al_register_event_source(queue, al_get_display_event_source(display));
    // - Register events from keyboard
    al_register_event_source(queue, al_get_keyboard_event_source());

    // Show display
    al_flip_display();

    // Event loop
    while (!isEnd)
    {
        // Wait for event
        al_wait_for_event(queue, &event);

        // What kind of event ?
        switch (event.type)
        {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                isEnd = 1;
                break;
            case ALLEGRO_EVENT_KEY_DOWN:
                // some random coordinates
                x1 = rand() % 800;
                x2 = rand() % 800;
                x3 = rand() % 800;
                y1 = rand() % 600;
                y2 = rand() % 600;
                y3 = rand() % 600;
                // some random color
                random_color = al_map_rgb(rand() % 255, rand() % 255, rand() % 255);

                switch (event.keyboard.keycode)
                {
                    case ALLEGRO_KEY_T:
                        al_draw_filled_triangle(x1, y1, x2, y2, x3, y3, random_color);
                        al_flip_display();
                        break;
                    case ALLEGRO_KEY_C:
                        al_draw_filled_circle(x1, y1, rand() % 100, random_color);
                        al_flip_display();
                        break;
                    case ALLEGRO_KEY_ESCAPE:
                        isEnd = 1;
                        break;
                    default:
                        printf("You pressed key %s , nothing to do\n", al_keycode_to_name(event.keyboard.keycode));
                        break;
                }
                break;
            default:
                break;
        }
    }

    // == Free memory
    // Destroy display
    al_destroy_display(display);
    // Destroy queue
    al_destroy_event_queue(queue);

    return 0;
}