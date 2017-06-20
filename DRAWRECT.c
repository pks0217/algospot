#include <stdio.h>
#include <string.h>

int main() {
    int ncase, i, j;
    int x, y, sx, sy, px, py, tx, ty;

    scanf("%d", &ncase);

    for(i=0 ; i<ncase ; i++) {
        sx = px = tx = 0;
        sy = py = ty = 0;
        for(j=0 ; j<3 ; j++) {
            scanf("%d %d", &x, &y);
            sx += x;
            sy += y;
            if(j==0) {
                px = x;
                py = y;
            } else {
                if(px != x && tx == 0)
                    tx = 2*(x+px);
                if(py != y && ty == 0)
                    ty = 2*(y+py);
            }
        }

        printf("%d %d\n", tx-sx, ty-sy);
    }

    return 0;
}
