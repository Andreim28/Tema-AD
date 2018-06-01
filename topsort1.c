#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define noVertexMAX 100
#define noVertex 5

int Matrix[noVertexMAX][noVertexMAX];

void topSort1(int Matrix[noVertexMAX][noVertexMAX]){
    int it1;
    int it2;
    int it3;
    int sum[noVertexMAX];
    int visited[noVertexMAX];
    int count=0;

    for(it1=0;it1<noVertex;it1++){
        sum[it1]=0;
        visited[it1]=0;
    }

    for(it1=0;it1<noVertex;it1++)
        for(it2=0;it2<noVertex;it2++)
            sum[it1]=sum[it1]+Matrix[it2][it1];

    printf("\nThe topological order using method 1 is:");

    while(count<noVertex){
        for(it3=0;it3<noVertex;it3++){
            if((sum[it3]==0) && (visited[it3]==0)){
                printf("%d ",(it3));
                visited[it3]=1;
            }

            for(it1=0;it1<noVertex;it1++){
                if(Matrix[it1][it3]==1)
                    sum[it3]--;
            }
        }
        count++;
    }
}
int main()
{
    int it1;
    int it2;

    FILE *randMatrix;
    randMatrix = fopen("randMatrix.txt","r");

    for(it1=0;it1<noVertex;it1++){
        for(it2=0;it2<noVertex;it2++)
            fscanf(randMatrix,"%d",&Matrix[it1][it2]);
    }
    topSort1(Matrix);
    fclose(randMatrix);
}
