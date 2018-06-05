
#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define noVertexMAX 100
#define noVertex 10

int CheckAcyclic(int Matrix[noVertexMAX][noVertexMAX]);
void randGraph(int Matrix[noVertexMAX][noVertexMAX]);
int internal_degree(int Matrix[noVertexMAX][noVertexMAX], int vertex);
void topSort_internal(int Matrix[noVertexMAX][noVertexMAX]);
void print_Matrix_file(int Matrix[noVertexMAX][noVertexMAX]);
void dfs(int it);

#endif

