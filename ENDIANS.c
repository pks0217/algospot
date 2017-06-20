#include <stdio.h>

unsigned int convert(unsigned int x);

int main () {
    int ncase;
    int i;
    unsigned int n;

    scanf("%d", &ncase);

    for(i=0 ; i<ncase ; i++) {
        scanf("%u", &n);
        printf("%u\n", convert(n));

    }

    return 0;
}

unsigned int convert(unsigned int x) {
    unsigned char c[4];
    unsigned int ret;

    c[0] = ( x >> 0  ) & 0xFF;
    c[1] = ( x >> 8  ) & 0xFF;
    c[2] = ( x >> 16 ) & 0xFF;
    c[3] = ( x >> 24 ) & 0xFF;

    ret = (c[0] << 24) | (c[1] << 16) | (c[2] << 8) | (c[3] << 0);

    return ret;
}
