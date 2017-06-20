#include <stdio.h>
#include <string.h>

int main() {
    int ncase, i, x, len;
    char buf[128];

    scanf("%d", &ncase);

    for(i=0 ; i<ncase ; i++) {
        scanf("%s", buf);
        len = strlen(buf);
        x=0;
        while(x<len) {
            printf("%c", buf[x]);
            x+=2;
        }
        x=1;
        while(x<len) {
            printf("%c", buf[x]);
            x+=2;
        }

        printf("\n");
    }

    return 0;
}
