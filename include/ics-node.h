#ifndef __ICS_NODE_H__
#define __ICS_NODE_H__

#include <time.h>

typedef enum {
    RIU = 0,
    OIU = 1   
} device_type;

extern char *DEVICE_TYPE[];

typedef struct riu_s riu_t;
typedef struct oiu_s oiu_t;

#define ICS_NODE_COMMON_FIELDS \
    char id[10];\
    int is_online;\
    time_t recv_time;\
    device_type type;
    
struct riu_s {
    ICS_NODE_COMMON_FIELDS;
    char conn_str[30];
    int n_ports;
    char sqa_ip[30];

    riu_t *next, *prev;
};

struct oiu_s {
    ICS_NODE_COMMON_FIELDS;

    oiu_t *next, *prev;
};

void rius_init(riu_t **head);
void rius_append(riu_t **head, riu_t *r);
void oius_init(oiu_t **head);
void oius_append(oiu_t **head, oiu_t *o);
#endif
