#include "functions.h"

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

