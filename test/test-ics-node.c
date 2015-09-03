#include <stdio.h>
#include <string.h>
#include "ics-node.h"
#include "utlist.h"
int main() {
    riu_t *head, *node;
    riu_t riu1 = {
        .n_ports = 4,
    };
    riu_t riu2 = {
        .n_ports = 4,
        .is_online = 1,
    };
    riu_t riu3 = {
        .n_ports = 4,
        .is_online = 1,
    };

    strcpy(riu1.id, "riu1");
    strcpy(riu2.id, "riu2");
    strcpy(riu3.id, "riu3");

    strcpy(riu1.conn_str, "conn1");
    strcpy(riu2.conn_str, "conn2");
    strcpy(riu3.conn_str, "conn3");

    strcpy(riu1.sqa_ip, "239.0.0.1");
    strcpy(riu2.sqa_ip, "239.0.0.2");
    strcpy(riu3.sqa_ip, "239.0.0.3");

    rius_init(&head);

    rius_append(&head, &riu1);
    rius_append(&head, &riu2);
    rius_append(&head, &riu3);

    DL_FOREACH(head, node) {
        printf("Node: id=%s, is_online=%d, conn_str=%s, n_ports=%d, sqa_ip=%s\n", node->id, node->is_online, node->conn_str, node->n_ports, node->sqa_ip);
    }
    printf("Hello\n");
    return 0;
}
