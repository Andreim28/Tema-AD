///\file topSortDFS.c
///\brief Docs project no. 7 - Doxygen
///
/// Developed by Marcu Andrei Cristian - 05.06.18
//-----------------------------topSortDFS.c-------------------------------
#include "functions.h"

int Matrix[noVertexMAX][noVertexMAX];
///\var Matrix[noVertexMAX][noVertexMAX] is the adjacency matrix of the graph
int sorted[noVertexMAX];
///\var sorted[noVertexMAX] is the vector which stores the sorted topological values after DFS
int visited[noVertexMAX];
///\var visited[noVertexMAX] is a vector that verifies if a vertex was visited before
int noEl_sorted=0;
///\var noEl_sorted variable that counts how many elements were sorted

void dfs(int it) {
    ///\fn dfs
    ///\param it - the vertex we start from
    ///\brief dfs function
    ///
    /// The function DFS traverses the matrix
    ///\var it1 iterator1
    int it1;
    ///The start vertex is initialized with 1
    visited[it] = 1;
    for (it1 = 0; it1 < noVertex; it1++) {
        ///If it's external degree is 1 and the next vertex wasn't visited we make dfs(nextvertex)
        if (Matrix[it][it1] == 1 && visited[it1] == 0){
            dfs(it1);
        }
    }
    ///Here we create the vector which contains the vertices sorted
    sorted[noEl_sorted++] = it;
}

