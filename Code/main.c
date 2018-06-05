#include "functions.h"

int Matrix[noVertexMAX][noVertexMAX];
int sorted[noVertexMAX];
int visited[noVertexMAX];

int main(){
    randGraph(Matrix);

    int it1;
    int it2;
    int MethodSelector=0;

    FILE *randMatrix;
    randMatrix = fopen("randMatrix.txt","r");

    print_Matrix_file(Matrix);
    printf("To use the first method(internal degree method) type 1\n");
    printf("To use the second method(dfs topological sort) type 2\n");
    printf("To use both methods type 3\n");
    printf("Method:");
    scanf("%d",&MethodSelector);
    while(MethodSelector!=1&&MethodSelector!=2&&MethodSelector!=3){
        printf("The number is wrong, please type 1/2/3 to select your method\n");
        printf("Method:");
        scanf("%d",&MethodSelector);
    }
    if(MethodSelector == 1){
        printf("The topological sort using Internal degree method is:");
        for(it1 = 0; it1 < noVertex ; it1++){
            for(it2 = 0 ; it2 < noVertex ; it2++)
                fscanf(randMatrix , "%d" , &Matrix[it1][it2]);
        }
        topSort_internal(Matrix);
    }
    if(MethodSelector == 2){
        printf("The topological sort using DFS method is:");
        for(it1 = 0; it1 < noVertex ; it1++)
            visited[it1] = 0;
        for(it1 = 0; it1 < noVertex ; it1++){
            for(it2 = 0; it2 < noVertex ; it2++)
                fscanf(randMatrix , "%d" , &Matrix[it2][it1]);
        }
        for (it1 = 0; it1 < noVertex; it1++) {
            if (visited[it1] == 0) {
                dfs(it1);
            }
        }
        for (it1 = 0; it1 < noVertex; it1++) {
            printf("%d ",sorted[it1]);
        }
    }
    if(MethodSelector == 3){
        printf("The topological sort using Internal degree method is:");
        for(it1 = 0; it1 < noVertex ; it1++){
            for(it2 = 0; it2 < noVertex ; it2++)
                fscanf(randMatrix,"%d",&Matrix[it1][it2]);
        }
        topSort_internal(Matrix);

        fclose(randMatrix);
        FILE *randMatrix;
        randMatrix = fopen("randMatrix.txt","r"); // Deschidem din nou fisierul pentru a citi matricea pe coloana

        printf("\nThe topological sort using DFS method is:");
        for(it1 = 0; it1 < noVertex ; it1++)
            visited[it1] = 0;
        for(it1 = 0; it1 < noVertex; it1++){
            for(it2 = 0; it2 < noVertex; it2++)
                fscanf(randMatrix,"%d",&Matrix[it2][it1]);
        }
        for (it1 = 0; it1 < noVertex; it1++) {
            if (visited[it1] == 0) {
                dfs(it1);
            }
        }
        for (it1 = 0; it1 < noVertex; it1++) {
            printf("%d ",sorted[it1]);
        }
    }
    fclose(randMatrix);
    return 0;
}
int CheckAcyclic(int Matrix[noVertexMAX][noVertexMAX]){
    int it1;
    int it2;
    int count = noVertex;
    int internal;
    int aux[noVertexMAX][noVertexMAX];
    int visited[noVertexMAX];
    bool check;

    for(it1 = 0; it1 < noVertex; it1++){
        for(it2 = 0; it2 < noVertex; it2++){
            aux[it1][it2] = Matrix[it1][it2];
        }
    }
    for(it1 = 0; it1 < noVertex; it1++)
        visited[it1] = 0;
    while(count != 0){
        check = 0;
        for(it1 = 0; it1 < noVertex; it1++){
            internal = 0;
            if(visited[it1] == 0){
                for(it2 = 0; it2 < noVertex; it2++){
                   internal = internal + aux[it2][it1];
                }
                if(internal == 0){
                    check = 1;
                    visited[it1] = 1;
                    count--;
                    for(it2 = 0; it2 < noVertex; it2++)
                        aux[it1][it2] = 0;
                }
            }

        }
        if(check == 0)
            return 0;
    }
    return 1;

}
void randGraph(int Matrix[noVertexMAX][noVertexMAX]){

    int it1;
    int it2;
    srand(time(0));

    FILE *randMatrix;
    randMatrix = fopen("randMatrix.txt","w");
    //fprintf(randMatrix,"%d \n",noVertex);

    for(it1 = 0; it1 < noVertex; it1++){
        for(it2 = 0; it2 < noVertex; it2++){
            if(it1 == it2){
                continue;
            }
            if(Matrix[it2][it1] == 0){
                Matrix[it1][it2] = rand() % 2;
            }
            if(CheckAcyclic(Matrix) == 0){
                Matrix[it1][it2] = 0;
            }
        }
    }
    for(it1 = 0; it1 < noVertex; it1++){
        for(it2 = 0; it2 < noVertex; it2++){
            fprintf(randMatrix , "%d " , Matrix[it1][it2]);
        }
        fprintf(randMatrix , "\n");
    }
    fprintf(randMatrix , "Number of vertices:%d" , noVertex);
    fclose(randMatrix);
}
void print_Matrix_file(int Matrix[noVertexMAX][noVertexMAX]){
    int it1;
    int it2;
    FILE *randMatrix;
    randMatrix = fopen("randMatrix.txt","r");

    printf("The adjacency matrix of the random directed acyclic graph is:\n");
    for(it1 = 0 ; it1 < noVertex ; it1++){
        for(it2=0 ; it2 < noVertex ; it2++)
            printf("%d " , Matrix[it1][it2]);
        printf("\n");
    }
    fclose(randMatrix);
}
