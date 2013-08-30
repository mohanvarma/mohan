#include<stdio.h>
#define VERTEX 10
int distance[VERTEX] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
int count = 0;
int G[VERTEX][VERTEX] = {
    			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
void dfs(int v)
{
    int S[100] = {0};
    int top;
    top = 0;
    S[top] = v;
    distance[v] = 0;
    printf("Order of traversal:\n");
    while(top>-1)
    {
	int i,j;
	//Pop
	int vertex = S[top--];
	printf("[%d]\n", vertex+1);
	for(i=0; i<VERTEX; i++)
	{
	    for(j=0; j<VERTEX; j++)
	    {
		if(G[i][j] && i==vertex && (distance[j]==-1))
		{
		    //Push
		    S[++top] = j;
		    count++;
		    distance[j] = count;
		}
	    }
	}
    }
}

int main()
{
    /* BFS for the following graph
     *        1
     *      / | \
     *     2  6  7
     *    / \   / \
     *   3   5 8   9
     *  /       \10
     * 4 
     *
     */
    G[0][1] = 1;
    G[1][2] = 1;
    G[2][3] = 1;
    G[1][4] = 1;
    G[0][5] = 1;
    G[0][6] = 1;
    G[6][7] = 1;
    G[7][8] = 1;
    G[7][9] = 1;

    //Undirected
    G[1][0] = 1;
    G[2][1] = 1;
    G[3][2] = 1;
    G[4][1] = 1;
    G[5][0] = 1;
    G[6][0] = 1;
    G[7][6] = 1;
    G[8][7] = 1;
    G[9][7] = 1;

    //dfs on vertex v is dfs(v-1)
    dfs(0);

    return 0;
}

