#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
    int ncase;
    long a, b, x, y;
    char s[256];
    char s1[256];
    char s2[256];
    char c[128], d[128];

    fgets(s, 256, stdin);
    ncase = atoi(s);

    for(x=0 ; x<ncase ; x++) {
        fgets(s, 256, stdin);
        y = 0; a = 0; b=0;
        memset(c, 0, sizeof(c));
        memset(d, 0, sizeof(d));
        memset(s1, 0, sizeof(s1));
        memset(s2, 0, sizeof(s2));

        while(isalpha(s[y]) || (0<=(s[y]-'0') && (s[y]-'0')<=9)) {
            c[s[y]-'0'] += 1;
            s1[a] = s[y];
            a++;
            y++;
        }
        y++;
        while(isalpha(s[y]) || (0<=(s[y]-'0') && (s[y]-'0')<=9)) {
            d[s[y]-'0'] += 1;
            s2[b] = s[y];
            b++;
            y++;
        }

        if(!strcmp(s1, s2)) {
            y=-1;
        } else {
            for(a=0 ; a<128 ; a++) {
                if(c[a] != d[a]) {
                    y=-1;
                    break;
                }
            }
        }

        if(y>=0) puts("Yes");
        else puts("No.");
    }

    return 0;
}
