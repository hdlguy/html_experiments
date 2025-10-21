
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int initialized = 0;
static int fake_status = 42;

int instrument_init(void) {
    srand(time(NULL));
    initialized = 1;
    printf("[libinstrument] initialized\n");
    return 0;
}

int instrument_set_mode(int mode) {
    if (!initialized) return -1;
    printf("[libinstrument] mode set to %d\n", mode);
    fake_status = mode * 10 + (rand() % 10);
    return 0;
}

int instrument_read_status(int *status) {
    if (!initialized) return -1;
    *status = fake_status;
    printf("[libinstrument] status read: %d\n", *status);
    return 0;
}

