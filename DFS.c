// You might want some more includes here
#include "MUCSGraph.h"
#include "DFS.h"
#include <stdio.h>
#include <limits.h>

// Helper function that recursively visits during DFS
void DFS_VISIT(Vertex * V, int countV, Edge * E, int countE, int u, int * time)
{
    (*time)++;
    V[u].d = *time;
    V[u].color = GRAY;

    Adjacency * Adj = V[u].list;
    while (Adj)
    {
        Vertex * v = &(V[Adj->pEdge->to - 1]);

        if (1)  
        {
            if (u == Adj->pEdge->to - 1)
            {
                v = &(V[Adj->pEdge->from - 1]);  
            }
        }

        if (v->color == WHITE)
        {
            v->predecessor = V[u].number;  
            DFS_VISIT(V, countV, E, countE, v->number - 1, time);  
        }

        Adj = Adj->next;  
    }

    (*time)++;
    V[u].f = *time;
    V[u].color = BLACK;  

    printf("%d", V[u].number);
    printf("(%d) ", V[u].f);
}
/* Performs depth fisrt search, prints the number and time of each vertice, and marks them as black. */
void PrintDFS(Vertex * V, int countV, Edge * E, int countE)
{
    printf("DFS:\n");

    for (int i = 0; i < countV; i++)
    {
        V[i].color = WHITE;  
        V[i].d = 0;   
        V[i].predecessor = 0; 
    }

    int time = 0;  
 
    for (int i = 0; i < countV; i++)
    {
        if (V[i].color == WHITE)
        {
            DFS_VISIT(V, countV, E, countE, i, &time);  
        }
    }

    printf("\n");  
}