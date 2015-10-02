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
    device_type type;\
    char des[10];
    
struct riu_s {
    ICS_NODE_COMMON_FIELDS;
    char conn_str[30];
    char ports_status[100];
    char sqa_ip[30];
    double frequence;
    char location[50];

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
