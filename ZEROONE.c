#include <stdio.h>
#include <string.h>

int main() {
    char str[1000001] = {'\0',};
    int offset[1000001] = {0,};
    int i, st, sp, ncase;

    scanf("%s", str);

    scanf("%d", &ncase);

    st = 0;
    sp = strlen(str);
    for(i=0 ; i<sp ; i++) {
        offset[i] = st;

        if(*(str+i) != *(str+i+1)) {
            st = i+1;
        }
    }

    for(i=0 ; i<ncase ; i++) {
        scanf("%d %d", &st, &sp);

        if(offset[st] == offset[sp]) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }

    }

    return 0;
}
