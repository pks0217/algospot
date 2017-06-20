#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define NEXT_BUF_SIZE 1000

struct _Node;

typedef struct _Next {
    struct _Node * node;
    int distance;
} Next;

typedef struct _Node {
    int value;
    int weight;
    int visited;
    int cntNext;
    int cntNextMax;
    Next * next;
} Node;


int addRoad(Node ** const head, const int src_value, const int dst_value, const int distance) {

    Node * src = *(head + src_value);
    Node * dst = *(head + dst_value);

    if ((++src->cntNext) >= (src->cntNextMax * NEXT_BUF_SIZE)) {
        src->next = (Next*)realloc(src->next, sizeof(Next) * (++src->cntNextMax) * NEXT_BUF_SIZE);
    }

    if(src->next == NULL) {
        src->cntNextMax = 0;
        return -1;
    }

    if ((++dst->cntNext) >= (dst->cntNextMax * NEXT_BUF_SIZE)) {
        dst->next = (Next*)realloc(dst->next, sizeof(Next) * (++dst->cntNextMax) * NEXT_BUF_SIZE);
    }

    if(dst->next == NULL) {
        dst->cntNextMax = 0;
        return -1;
    }

    src->next[src->cntNext-1].node = dst;
    src->next[src->cntNext-1].distance = distance;
    dst->next[dst->cntNext-1].node = src;
    dst->next[dst->cntNext-1].distance = distance;

    return 0;
}

void removeAll(Node ** head, const int cnt) {
    int i;

    if(head == NULL || cnt <= 0) 
        return;

    for(i = 0 ; i < cnt ; i++) {
        if((*(head+i))->cntNextMax > 0) {
            free((*(head+i))->next);
        }
        free(*(head+i));
    }
    free(head);
}

Node * calcClosest(Node ** const head, const int idx, const int max) {
    int i=0, x=0, y, z;
    Node * node = *head;
    Node * tmp;

    int cnt = max-idx;

    for(i=1 ; i<cnt ; i++) {
        if(node->weight > (*(head+i))->weight) {
            node = *(head + i);
            x = i;
        }
    }

    node->visited = 1;

    if(node->value == max-1) 
        return node;

    for (i = 0 ; i < node->cntNext ; i++) {
        if(node->next[i].node->visited == 0) {
            y = node->weight + node->next[i].distance;
            z = node->next[i].node->weight;
            node->next[i].node->weight = (y<z)?y:z;
        }
    }

    tmp = *(head+cnt-1);
    *(head+cnt-1) = *(head+x);
    *(head+x) = tmp;

    return NULL;

}

int main() {
    int ncase,nloop;
    int ncity, nroad;
    int x, y, z, src, dst;
    Node ** head;
    Node * node;
    int err = 0;

    scanf("%d", &ncase);

    for(nloop=0 ; nloop<ncase ; nloop++) {
        scanf("%d %d", &ncity, &nroad);

        head = (Node**)malloc(sizeof(Node*)*ncity);

        if(head == NULL) {
            err = 1;
            break;
        }

        for(x=0 ; x<ncity && !err ; x++) {
            node = (Node*)malloc(sizeof(Node));

            if(node==NULL) {
                err = 1;
                break;
            }

            node->value = x;
            node->visited = 0;
            node->weight = INT_MAX;
            node->cntNext = 0;
            node->cntNextMax = 1;
            node->next = (Next*)malloc(sizeof(Next) * node->cntNextMax * NEXT_BUF_SIZE);
            if(node->next == NULL) {
                node->cntNextMax = 0;
                err = 1;
                break;
            }

            *(head+x) = node;
        }

        if (!err) 
            (*head)->weight = 0;

        for(x=0 ; x<nroad && !err ; x++) {
            scanf("%d %d %d", &src, &dst, &z);
            if(addRoad(head, src, dst, z) < 0) {
                err = 1;
                break;
            }
        }

        node = NULL;
        for(y=0 ; y<ncity && !err ; y++) {
            if((node = calcClosest(head, y, ncity)) != NULL) {
                break;
            }
        }

        if(node != NULL) {
            printf("%d\n", node->weight);
        }

        removeAll(head, ncity);
    }

    return 0;
}
