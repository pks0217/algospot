#include <stdio.h>
#include <float.h>
#include <math.h>

int main() {
    int ncase;
    int size;
    float fMx[100][3];

    int i, j, x, y, saveX, saveFlag;
    float dist, distMin, saveMin=0.0;

    scanf("%d", &ncase);

    for (i=0 ; i<ncase ; i++) {
        saveMin = 0.0f;
        scanf("%d", &size);
        for (j=0 ; j<size ; j++) {
            scanf("%f %f", &fMx[j][1], &fMx[j][2]);
            fMx[j][0] = j; 
        }

        for(j=0 ; j<size ; j++) {
            distMin = FLT_MAX;
            saveFlag = 0;
            for(x=0 ; x<size ; x++) {
                if(fMx[x][0] != 0.0f) {
                    for(y = 0 ; y<size ; y++) {
                        if(fMx[y][0] == 0.0f) {
                            dist = sqrt(pow(fMx[x][1]-fMx[y][1], 2) + pow(fMx[x][2]-fMx[y][2], 2));
                            if (distMin > dist) {
                                distMin = dist; 
                                saveFlag = 1;
                                saveX = x; 
                            }
                        }
                    }
               }
            }
            if (saveFlag == 1) {
                fMx[saveX][0] = 0.0f;
                if (saveMin < distMin) {
                 saveMin = distMin;
                }
            }
        }
        printf("%.2f\n", saveMin);
    }
    return 0;
}
