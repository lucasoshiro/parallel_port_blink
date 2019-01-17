#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>
#include <time.h>

/* Base parallel port address. May be different on different systems*/
#define BASE 0x378

#define set_lpt_val(val) (outb (val, BASE))

const struct timespec delay = {0, 100000000};

typedef enum {D0 = 0x01,
              D1 = 0x02,
              D2 = 0x04,
              D3 = 0x08,
              D4 = 0x10,
              D5 = 0x20,
              D6 = 0x40,
              D7 = 0x80}
    parallell_pins;

int main () {
    if (ioperm (BASE, 3, 1)) fprintf (stderr, "Access denied\n"), exit (1);

    for (;;) {
        /* Blinks two times led 1, two times led 2, two times led 3 */

        set_lpt_val(D0); nanosleep (&delay, NULL);
        set_lpt_val(0);  nanosleep (&delay, NULL);
        set_lpt_val(D0); nanosleep (&delay, NULL);
        set_lpt_val(0);  nanosleep (&delay, NULL);

        set_lpt_val(D1); nanosleep (&delay, NULL);
        set_lpt_val(0);  nanosleep (&delay, NULL);
        set_lpt_val(D1); nanosleep (&delay, NULL);
        set_lpt_val(0);  nanosleep (&delay, NULL);

        set_lpt_val(D2); nanosleep (&delay, NULL);
        set_lpt_val(0);  nanosleep (&delay, NULL);
        set_lpt_val(D2); nanosleep (&delay, NULL);
        set_lpt_val(0);  nanosleep (&delay, NULL);
    }

    return 0;
}
