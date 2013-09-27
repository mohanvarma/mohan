/*
procedure bfs(G; s)
Input: Graph G = (V; E), directed or undirected; vertex s in V
Output: For all vertices u reachable from s, dist(u) is set
to the distance from s to u.
for all u in V :
	dist(u) = -1

dist(s) = 0
Q = [s] (queue containing just s)
while Q is not empty:
	u = dequeue(Q)
	for all edges (u; v) in E:
		if dist(v) = -1:
		enqueue(Q; v)
		dist(v) = dist(u) + 1

*/

#include<stdio.h>
#define VERTEX 6
int distance[VERTEX] = {-1, -1, -1, -1, -1, -1};
int count = 0;
int G[VERTEX][VERTEX] = {
    			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0}};
void bfs(int v)
{
    int Q[100] = {0};
    int head, tail;
    head = 0;
    tail = 1;
    Q[head] = v;
    distance[v] = 0;
    printf("Order of traversal:\n");
    while(head<tail)
    {
	int i,j;
	//Pop
	int vertex = Q[head++];
	printf("[%d] distance %d\n", vertex+1, distance[vertex]);
	for(i=0; i<VERTEX; i++)
	{
	    for(j=0; j<VERTEX; j++)
	    {
		if(G[i][j] && i==vertex && (distance[j]==-1))
		{
		    //Push
		    Q[tail++] = j;
		    count++;
		    distance[j] = distance[vertex]+1;
		}
	    }
	}
    }
}

int main()
{
    /* BFS for the following graph
     * 6==1==2
     * | /|  |
     * 5  4==3
     */
    G[0][1] = 1;
    G[1][2] = 1;
    G[2][3] = 1;
    G[0][3] = 1;
    G[0][5] = 1;
    G[0][4] = 1;
    G[4][5] = 1;

    //Undirected
    G[1][0] = 1;
    G[2][1] = 1;
    G[3][2] = 1;
    G[3][0] = 1;
    G[5][0] = 1;
    G[4][0] = 1;
    G[5][4] = 1;

    //bfs on vertex v is bfs(v-1)
    bfs(1);

    return 0;
}

