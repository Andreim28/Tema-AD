///\file topSortInternal.c
///\brief Docs project no. 7 - Doxygen
///
/// Developed by Marcu Andrei Cristian - 05.06.18
//-----------------------------topSortInternal.c-------------------------------
#include "functions.h"

int internal_degree(int Matrix[noVertexMAX][noVertexMAX],int vertex){
    ///\fn internal_degree
    ///\param Matrix[noVertexMAX][noVertexMAX] - the adjacency matrix of the graph
    ///\param vertex - we compute the internal degree of vertex
    ///\brief internal_degree function
    ///
    /// We compute the internal degree of a vertex
    ///\var it1 iterator1
    int it1;
    ///\var sum sum=internal degree
    int sum=0;
    for(it1=0;it1<noVertex;it1++){
        ///Sum=internal degree
        sum=sum+Matrix[it1][vertex];
    }
    return sum;
}
void topSort_internal(int Matrix[noVertexMAX][noVertexMAX]){
    ///\fn topSort_internal
    ///\param Matrix[noVertexMAX][noVertexMAX] - the adjacency matrix of the graph
    ///\brief topSort_internal function
    ///
    /// This function computes the topological sort by printing the element with internal degree 0 everytime
    ///\var it1 iterator1
    int it1;
    ///\var it2 iterator2
    int it2;
    ///\var visited[noVertexMAX] Vector that stores the visited vertices
    int visited[noVertexMAX];
    ///\var count It has the initial value equal to noVertex and we use it as a break point
    int count=0;
    ///We initialize visited with 0
    for(it1=0;it1<noVertex;it1++)
        visited[it1]=0;
    while(count<noVertex){
        for(it1=0;it1<noVertex;it1++)
            if(internal_degree(Matrix,it1)==0&&visited[it1]==0){
                ///If the internal_degree of the vertex is 0 and it wasn't visited we print the node
                printf("%d ",(it1));
                visited[it1]=1;
                ///We cut all it's external edges
                for(it2=0;it2<noVertex;it2++)
                    Matrix[it1][it2]=0;
                count++;
            }
    }
}
