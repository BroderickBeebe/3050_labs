// You might want some more includes here
#include "MUCSGraph.h"
#include "Queue.h"
#include "BFS.h"
#include <stdio.h>
#include <limits.h>

// Helper function to initialize vertex properties
void initializeVertices(Vertex * V, int countV, int start) 
{
    for (int i = 0; i < countV; i++) {
        if (V[i].number == start) 
        {
            V[i].color = GRAY;
            V[i].d = 0;
            V[i].predecessor = 0;
        } 
        else 
        {
            V[i].color = WHITE;
            V[i].d = INT_MAX;
            V[i].predecessor = 0;
        }
    }
}

// Helper function to process the adjacency list and enqueue the neighbors
void processAdjacencyList(Vertex *V, Vertex *u, Queue *Q) 
{
    Adjacency *Adj = V[u->number - 1].list;
    while (Adj) 
    {
        Vertex *v = &(V[Adj->pEdge->to - 1]);


        if (v->number == u->number) 
        {
            v = &(V[Adj->pEdge->from - 1]);
        }

        if (v->color == WHITE) 
        {
            v->color = GRAY;
            v->d = u->d + 1;
            v->predecessor = u->number;
            enQueue(Q, v);
        }
        Adj = Adj->next;
    }
}
/*main function to print BFS, performs BFS, prints each vertice and the distance between each vertex and the initial vertex, then
sets the color of all printed vertices to black
*/
void PrintBFS(Vertex * V, int countV, Edge * E, int countE, int s) {
    printf("\nBFS:\n");


    initializeVertices(V, countV, s);


    Queue *Q = createQueue();
    enQueue(Q, &(V[s - 1]));

    while (!isEmpty(Q)) {
        Vertex *u = (Vertex *)deQueue(Q);
        printf("%d(%d) ", u->number,u->d);
        processAdjacencyList(V, u, Q);
        u->color = BLACK;
    }

    destroyQueue(Q);
    printf("\n");
}

