#include "functions.h"

int internal_degree(int Matrix[noVertexMAX][noVertexMAX],int vertex)
{
    int it1;
    int sum=0;
    for(it1=0;it1<noVertex;it1++){
        sum=sum+Matrix[it1][vertex];
    }
    return sum;
}
void topSort_internal(int Matrix[noVertexMAX][noVertexMAX])
{
    int it1;
    int it2;
    int visited[noVertexMAX];
    int count=0;

    for(it1=0;it1<noVertex;it1++)
        visited[it1]=0;
    while(count<noVertex)
    {
        for(it1=0;it1<noVertex;it1++)
            if(internal_degree(Matrix,it1)==0&&visited[it1]==0)
        {
             printf("%d ",(it1));
             visited[it1]=1;
             for(it2=0;it2<noVertex;it2++)
                Matrix[it1][it2]=0;
             count++;
        }
    }
}
