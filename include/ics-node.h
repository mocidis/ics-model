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
    char desc[250];\
    char ip_addr[50];
    
struct riu_s {
    ICS_NODE_COMMON_FIELDS;
    char location[50];

    int is_tx;
    int is_sq;

    double frequence;
    int port;
    double volume;

    char multicast_ip [16];
    int stream_port;

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
