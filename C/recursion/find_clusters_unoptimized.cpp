//For c
// #pragma GCC optimize (1)
#include<stdio.h>
#include<time.h>
// For cpp, as g++ is not accepting C style
/*
int main(int argc, char** argv) __attribute__((optimize("-O1")));
void explore_white(int i, int j) __attribute__((optimize("-O1")));
int Find_and_explore_white(int Map[501][501]) __attribute__((optimize("-O1")));
void explore_black(int i, int j) __attribute__((optimize("-O1")));
int Find_and_explore_black(int Map[501][501]) __attribute__((optimize("-O1")));
*/

int Map[501][501];
int N;
int Answer;

void explore_white(int i, int j)
{
	//Boundary check;
	if(i<1 || i>N)
		return;

	if(j<1 || j>N)
		return;

	//If hit black, return
	if(Map[i][j] == 1)
		return;

	//If already explored, return
	if(Map[i][j] > 1)
		return;

	Map[i][j] = Answer;
	
	explore_white(i-1, j);
	explore_white(i+1, j);
	explore_white(i, j-1);
	explore_white(i, j+1);

}

int Find_and_explore_white(int Map[501][501])
{
	int i,j;

	for(i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			//First white cell
			if(!Map[i][j])
			{
				goto label;			
			}
		}
	}

	//No white cell found
	return -1;

label:
	Map[i][j] = ++Answer;
	//Explore all directions
	explore_white(i-1, j);
	explore_white(i+1, j);
	explore_white(i, j-1);
	explore_white(i, j+1);
	return 0;
}

void explore_black(int i, int j)
{
	//Boundary check;
	if(i<1 || i>N)
		return;

	if(j<1 || j>N)
		return;

	//If hit white, return
	if(!Map[i][j])
		return;

	//If already explored, return
	if(Map[i][j] > 1)
		return;

	Map[i][j] = Answer;
	
	explore_black(i-1, j);
	explore_black(i+1, j);
	explore_black(i, j-1);
	explore_black(i, j+1);

}

int Find_and_explore_black(int Map[501][501])
{
	int i,j;

	for(i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			//First black cell
			if(Map[i][j] == 1)
			{
				goto label;			
			}
		}
	}

	//No black cell found
	return -1;

label:
	Map[i][j] = ++Answer;
	//Explore all directions
	explore_black(i-1, j);
	explore_black(i+1, j);
	explore_black(i, j-1);
	explore_black(i, j+1);
	return 0;
}

int main(int argc, char** argv)
{
	clock_t start = clock();
	int test_case;
	freopen("input_clusters.txt", "r", stdin);

	setbuf(stdout, NULL);
	
	/*
	  Your program should handle 20 test cases given.
	 */

	for(test_case = 1; test_case <= 20; ++test_case)
	{
		int i, j;

		/*
		   Read each test case from standard input.
		   A cell information of i-th row and j-th column is stored in Map[i][j].
		   (ex. If a number in the second row and the third column is one, one is stored in Map[2][3].)
		 */
		scanf("%d", &N);
		for(i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				scanf("%d", &Map[i][j]);
			}
		}

		//Cluster count
		//Finally reduce the count by 1
		Answer = 1;

		while(1)
		{
		if ((Find_and_explore_black(Map) == -1) && (Find_and_explore_white(Map) == -1 ))
			break;
		}


		// Print the answer to standard output(screen).
		printf("#%d %d\n", test_case, Answer-1);
	clock_t end = clock();
	printf("Took %f secs\n", 1.0*(end-start)/CLOCKS_PER_SEC);
	}

	return 0;//Your program should return 0 on normal termination.
}
