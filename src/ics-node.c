#include <string.h>
#include "utlist.h"
#include "ics-node.h"

void rius_init(riu_t **head) {
    *head = NULL;
}

void oius_init(oiu_t **head) {
    *head = NULL;
}

void rius_append(riu_t **head, riu_t *r) {
    DL_APPEND(*head, r);
}

void oius_append(oiu_t **head, oiu_t *o) {
    DL_APPEND(*head, o);
}
