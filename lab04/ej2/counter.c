#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "counter.h"

struct _counter {
    unsigned int count;
};

/*---------------Constructors---------------*/

counter counter_init(void) {
    counter new_counter;
    new_counter = malloc(sizeof(counter));
    new_counter->count = INITIAL_VALUE;
    return new_counter;
}

void counter_inc(counter c) {
    c->count = c->count + 1u;
}


/*---------------Functions---------------*/

bool counter_is_init(counter c) {
    bool status = false;
    
    if (c->count == INITIAL_VALUE){
        status = true;
    }
    return status;
}

void counter_dec(counter c) {
    assert(!counter_is_init(c));
    c->count = c->count -1;
}

counter counter_copy(counter c) {
    counter copy;
    copy = counter_init();
    copy->count = c->count;
    return copy;
}

void counter_destroy(counter c) {
    free(c);
    c = NULL;
}
