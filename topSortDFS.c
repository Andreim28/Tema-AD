#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define noVertexMAX 100
#define noVertex 10

int Matrix[noVertexMAX][noVertexMAX];
int sorted[noVertexMAX];
int visited[noVertexMAX];
int noEl_sorted=0;

void dfs(int it) {
    int it1;
    visited[it] = 1;
    for (it1 = 0; it1 < noVertex; it1++) {
        if (Matrix[it][it1] == 1 && visited[it1] == 0) {
            dfs(it1);
        }
    }
    sorted[noEl_sorted++] = it;
}

int main(){
    int it1;
    int it2;

    FILE *randMatrix;
    randMatrix = fopen("randMatrix.txt","r");

    for (it1 = 0; it1 < noVertex; it1++) {
        for (it2 = 0; it2 < noVertex; it2++) {
            fscanf(randMatrix,"%d ",&Matrix[it2][it1]);
        }
    }
    for (it1 = 0; it1 < noVertex; it1++) {
        if (visited[it1] == 0) {
            dfs(it1);
        }
    }
    for (it1 = 0; it1 < noVertex; it1++) {
        printf("%d ",sorted[it1]);
    }
    fclose(randMatrix);
    return 0;
}

