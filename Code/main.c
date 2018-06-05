///\file main.c
///\brief Docs project no. 7 - Doxygen
///
/// Developed by Marcu Andrei Cristian - 05.06.18
//-----------------------------main.c-------------------------------
#include "functions.h"///> topSort_internal(), dfs()
///\var Matrix[noVertexMAX][noVertexMAX] is the adjacency matrix of the graph
int Matrix[noVertexMAX][noVertexMAX];
///\var sorted[noVertexMAX] is the vector which stores the sorted topological values after DFS
int sorted[noVertexMAX];
///\var visited[noVertexMAX] is a vector that verifies if a vertex was visited before
int visited[noVertexMAX];

int main(){
    ///\fn int main()
    ///\brief Int main
    ///
    /// In main() we call almost all the functions declared before randGraph(), topSort_internal(), dfs(), print_Matrix_file()
    ///\fn randGraph generates a random graph
    randGraph(Matrix);
    ///\var it1 iterator1
    int it1;
    ///\var it2 iterator2
    int it2;
    ///\var MethodSelector Used to choose the method
    int MethodSelector=0;

    FILE *randMatrix;
    randMatrix = fopen("randMatrix.txt","r");
    print_Matrix_file(Matrix);
    printf("To use the first method(internal degree method) type 1\n");
    printf("To use the second method(dfs topological sort) type 2\n");
    printf("To use both methods type 3\n");
    printf("Method:");
    scanf("%d",&MethodSelector);
    ///If you choose MethodSelector=0 -> Method 1
    ///If you choose MethodSelector=1 -> Method 2
    ///If you choose MethodSelector=2 -> Method 1&2
    while(MethodSelector!=1&&MethodSelector!=2&&MethodSelector!=3){
        printf("The number is wrong, please type 1/2/3 to select your method\n");
        printf("Method:");
        scanf("%d",&MethodSelector);
    }
    ///We use method 1
    if(MethodSelector == 1){
        printf("The topological sort using Internal degree method is:");
        ///We read the Matrix by line to use the Internal topological sort
        for(it1 = 0; it1 < noVertex ; it1++){
            for(it2 = 0 ; it2 < noVertex ; it2++)
                fscanf(randMatrix , "%d" , &Matrix[it1][it2]);
        }
        ///Here we call the function topSort_internal()
        topSort_internal(Matrix);
    }
    /// We use method 2
    if(MethodSelector == 2){
        printf("The topological sort using DFS method is:");
        ///We declare visited with 0
        for(it1 = 0; it1 < noVertex ; it1++)
            visited[it1] = 0;
        ///We read the Matrix by column to use DFS topological sort
        for(it1 = 0; it1 < noVertex ; it1++){
            for(it2 = 0; it2 < noVertex ; it2++)
                fscanf(randMatrix , "%d" , &Matrix[it2][it1]);
        }
        ///We call dfs function for each unvisited node
        for (it1 = 0; it1 < noVertex; it1++) {
            if (visited[it1] == 0) {
                ///Here we call the function dfs()
                dfs(it1);
            }
        }
        ///We print the sorted vector which contains the topological sort
        for (it1 = 0; it1 < noVertex; it1++) {
            printf("%d ",sorted[it1]);
        }
    }
    ///We use both methods
    if(MethodSelector == 3){
        ///We read the matrix by line for internal degree topological sort
        printf("The topological sort using Internal degree method is:");
        for(it1 = 0; it1 < noVertex ; it1++){
            for(it2 = 0; it2 < noVertex ; it2++)
                fscanf(randMatrix,"%d",&Matrix[it1][it2]);
        }
        ///We call the internal topological sort function
        topSort_internal(Matrix);
        ///We close the file
        fclose(randMatrix);
        ///We open the file to read the matrix again
        FILE *randMatrix;
        randMatrix = fopen("randMatrix.txt","r"); // Deschidem din nou fisierul pentru a citi matricea pe coloana

        printf("\nThe topological sort using DFS method is:");
        ///We declare visited with 0
        for(it1 = 0; it1 < noVertex ; it1++)
            visited[it1] = 0;
        ///We read the matrix by column
        for(it1 = 0; it1 < noVertex; it1++){
            for(it2 = 0; it2 < noVertex; it2++)
                fscanf(randMatrix,"%d",&Matrix[it2][it1]);
        }
        ///We call dfs function for each unvisited vertex
        for (it1 = 0; it1 < noVertex; it1++) {
            if (visited[it1] == 0) {
                ///We call dfs function
                dfs(it1);
            }
        }
        ///We print the vector which contains the topological order
        for (it1 = 0; it1 < noVertex; it1++) {
            printf("%d ",sorted[it1]);
        }
    }
    ///We close the file
    fclose(randMatrix);
    return 0;
}
int CheckAcyclic(int Matrix[noVertexMAX][noVertexMAX]){
    ///\fn int CheckAcyclic(int Matrix[noVertexMAX][noVertexMAX])
    ///\param Matrix[noVertexMAX][noVertexMAX] - the adjacency matrix of the graph
    ///\brief CheckAcyclic function
    ///
    ///The function CheckAcyclic checks if the generated Matrix has a cycle, return 1 if it is acyclic and 0 otherwise
    ///\var it1 iterator1
    int it1;
    ///\var it2 iterator2
    int it2;
    ///\var count It has the initial value equal to noVertex and we use it as a break point
    int count = noVertex;
    ///\var internal Variable that stores the internal degree of a vertex
    int internal;
    ///\var aux[noVertexMAX][noVertexMAX] A matrix equal to the adjacency Matrix
    int aux[noVertexMAX][noVertexMAX];
    ///\var visited[noVertexMAX] Vector that stores the visited vertices
    int visited[noVertexMAX];
    ///\var check A boolean variable used to check if the graph is acyclic
    bool check;
    ///Here we create a copy of Matrix in aux
    for(it1 = 0; it1 < noVertex; it1++){
        for(it2 = 0; it2 < noVertex; it2++){
            aux[it1][it2] = Matrix[it1][it2];
        }
    }
    ///We initialize visited with 0
    for(it1 = 0; it1 < noVertex; it1++)
        visited[it1] = 0;
    while(count != 0){
        ///Check is 0 everytime we repeat the while loop
        check = 0;
        for(it1 = 0; it1 < noVertex; it1++){
            ///Internal is 0 everytime we repeat the for loop
            internal = 0;
            ///We check if we visited that vertex before
            if(visited[it1] == 0){
                ///If the vertex is unvisited we calculate it's internal degree
                for(it2 = 0; it2 < noVertex; it2++){
                   internal = internal + aux[it2][it1];
                }
                ///If internal is still 0 then the graph is acyclic
                if(internal == 0){
                    ///Check becomes 1(acyclic graph)
                    check = 1;
                    ///The current vertex is visited
                    visited[it1] = 1;
                    ///Count=count -1 because we finished the first vertex(we don't want a infinite loop).In the end count will be 0
                    count--;
                    ///We make the external degree of the vertex 0
                    for(it2 = 0; it2 < noVertex; it2++)
                        aux[it1][it2] = 0;
                }
            }

        }
        ///Graph is cyclic
        if(check == 0)
            return 0;
    }
    ///Graph is acyclic
    return 1;

}
void randGraph(int Matrix[noVertexMAX][noVertexMAX]){
    ///\fn void randGraph(int Matrix[noVertexMAX][noVertexMAX])
    ///\param Matrix[noVertexMAX][noVertexMAX] - the adjacency matrix of the graph
    ///\brief randGraph function
    ///
    ///The function randGraph generates a random directed acyclic graph
    ///\var it1 iterator1
    int it1;
    ///\var it2 iterator2
    int it2;
    ///\fn srand() is used to generate random everytime
    srand(time(0));
    ///We open the file
    FILE *randMatrix;
    randMatrix = fopen("randMatrix.txt","w");
    //fprintf(randMatrix,"%d \n",noVertex);
    ///We traverse the matrix
    for(it1 = 0; it1 < noVertex; it1++){
        for(it2 = 0; it2 < noVertex; it2++){
            ///We check if we are on the main diagonal
            if(it1 == it2){
                continue;
            }
            if(Matrix[it2][it1] == 0){
                ///We generate a random value 0/1
                Matrix[it1][it2] = rand() % 2;
            }
            ///We check if the graph is acyclic, if it is not acyclic we make the element 0
            if(CheckAcyclic(Matrix) == 0){
                Matrix[it1][it2] = 0;
            }
        }
    }
    ///We print the matrix
    for(it1 = 0; it1 < noVertex; it1++){
        for(it2 = 0; it2 < noVertex; it2++){
            fprintf(randMatrix , "%d " , Matrix[it1][it2]);
        }
        fprintf(randMatrix , "\n");
    }
    ///We print the number of vertices
    fprintf(randMatrix , "Number of vertices:%d" , noVertex);
    fclose(randMatrix);
}
void print_Matrix_file(int Matrix[noVertexMAX][noVertexMAX]){
    ///\fn void print_Matrix_file(int Matrix[noVertexMAX][noVertexMAX])
    ///\param Matrix[noVertexMAX][noVertexMAX] - the adjacency matrix of the graph
    ///\brief print_Matrix_file
    ///
    ///The function prints the adjacency matrix
    ///\var it1 iterator1
    int it1;
    ///\var it2 iterator2
    int it2;
    FILE *randMatrix;
    randMatrix = fopen("randMatrix.txt","r");

    printf("The adjacency matrix of the random directed acyclic graph is:\n");
    ///We print the matrix
    for(it1 = 0 ; it1 < noVertex ; it1++){
        for(it2 = 0 ; it2 < noVertex ; it2++)
            printf("%d " , Matrix[it1][it2]);
        printf("\n");
    }
    fclose(randMatrix);
}
