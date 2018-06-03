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

int CheckAcyclic(int Matrix[noVertexMAX][noVertexMAX]);
void randGraph(int Matrix[noVertexMAX][noVertexMAX]);
int internal_degree(int Matrix[noVertexMAX][noVertexMAX], int vertex);
void topSort_internal(int Matrix[noVertexMAX][noVertexMAX]);
void print_Matrix_file(int Matrix[noVertexMAX][noVertexMAX]);
void dfs(int it);

int main(){
    randGraph(Matrix);

    int it1;
    int it2;
    int MethodSelector=0;

    FILE *randMatrix;
    randMatrix = fopen("randMatrix.txt","r");

    print_Matrix_file(Matrix);
    printf("Pentru a folosi prima metoda(Metoda gradului intern) introduceti 1\n");
    printf("Pentru a folosi metoda a 2-a(Metoda folosind DFS) introduceti 2\n");
    printf("Pentru a folosi ambele metode introduceti 3\n");
    printf("Metoda:");
    scanf("%d",&MethodSelector);
    while(MethodSelector!=1&&MethodSelector!=2&&MethodSelector!=3){
        printf("Numarul introdus este gresit, introduceti 1/2/3 pentru a alege metoda dorita\n");
        printf("Metoda:");
        scanf("%d",&MethodSelector);
    }
    if(MethodSelector == 1){
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
int internal_degree(int Matrix[noVertexMAX][noVertexMAX],int vertex){
    int it1;
    int sum = 0;
    for(it1 = 0; it1 < noVertex ; it1++){
        sum = sum + Matrix[it1][vertex];
    }
    return sum;
}
void topSort_internal(int Matrix[noVertexMAX][noVertexMAX]){
    int it1;
    int it2;
    int visited[noVertexMAX];
    int count = 0;

    printf("The topological sort using the internal degree method is:");
    for(it1 = 0; it1 < noVertex ; it1++)
        visited[it1] = 0;
    while(count < noVertex){
        for(it1 = 0 ; it1 < noVertex; it1++)
            if(internal_degree(Matrix,it1) == 0 && visited[it1] == 0){
                printf("%d ",(it1));
                visited[it1] = 1;
                for(it2 = 0 ; it2 < noVertex ; it2++)
                    Matrix[it1][it2] = 0;
                count++;
            }
    }
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
