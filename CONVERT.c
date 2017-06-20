#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {

    double k2p = 2.2046;
    double p2k = 0.4536;
    double l2g = 0.2642;
    double g2l = 3.7854;

    double nd;
    char s[3];
    int ncase, i;

    scanf("%d", &ncase);
    for(i=0 ; i<ncase ; i++) {
        scanf("%lf %s", &nd, s);
        if(!strcmp(s, "kg")) {
            printf("%d %.4lf lb\n", i+1, nd*k2p);
        }
        else if(!strcmp(s, "lb")) {
            printf("%d %.4lf kg\n", i+1, nd*p2k);
        }
        else if(!strcmp(s, "g")) {
            printf("%d %.4lf l\n", i+1, nd*g2l);
        }
        else if(!strcmp(s, "l")) {
            printf("%d %.4lf g\n", i+1, nd*l2g);
        }
    }

    return 0;
}
