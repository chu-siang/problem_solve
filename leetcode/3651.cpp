const int M=1e4+1, NN=6400;
const int INF=1e9+7;

// Using an array version for linked list to replace x_pos[M]
static int xList[M], nxt[NN];

static unsigned dp[2][NN]; 
static unsigned suffixMin[M]; 

class Solution {
public:
    static inline int idx(int i, int j, int c) { return i*c+j; }

    static int minCost(vector<vector<int>>& grid, int k) {
        const int r=grid.size(), c=grid[0].size(), N=r*c;

        if (xList[0]!=-1) // fill all with -1 at 1st times
            memset(xList, -1, sizeof(xList));

        int xMax=0;
        // Group indices by values of grid
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                const int x=grid[i][j], p=idx(i, j, c);
                nxt[p]=xList[x];// insert node at 1st place
                xList[x]=p;
                if (x>xMax) xMax=x;
            }
        }

        //Initialize DP for 0th row
        fill(dp[0], dp[0]+N, INF);

        dp[0][0]=0;
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                int pos=idx(i, j, c);
                if (i>0) 
                    dp[0][pos]=min(dp[0][pos], dp[0][pos-c]+grid[i][j]);
                if (j>0) 
                    dp[0][pos]=min(dp[0][pos], dp[0][pos-1]+grid[i][j]);
            }
        }

        // DP with t Teleports
        for (int t=1; t<= k;t++) {
            // &1 trick used here
            const bool curr=t&1, prev=(t-1)&1;

            // Compute suffixMin[x] 
            unsigned currMin=INF;
            for (int x=xMax; x>=0; x--) {
                // trasverse the linked list 
                for (int e=xList[x]; e!=-1; e=nxt[e]) {
                    currMin=min(currMin, dp[prev][e]);
                }
                suffixMin[x]=currMin;// teleport
            }

            // Update cells for current teleport 
            for (int i=0; i<r; i++) {
                for (int j = 0; j < c; j++) {
                    const int pos=idx(i, j, c);
                    const int x=grid[i][j];

                    // best result with fewer teleports or by teleport
                    unsigned best=min(dp[prev][pos], suffixMin[x]);

                    // step from up or Left
                    if (i>0) best=min(best, dp[curr][pos-c]+x);
                    if (j>0) best=min(best, dp[curr][pos-1]+x);

                    dp[curr][pos]=best;
                }
            }
        }
        // Reset for the next test case
        memset(xList, -1, sizeof(int)*(xMax+1));
        return dp[k&1][N-1];
    }
};
"
3651. Minimum Cost Path with Teleportations
Hard
Topics
premium lock icon
Companies
Hint
You are given a m x n 2D integer array grid and an integer k. You start at the top-left cell (0, 0) and your goal is to reach the bottom‐right cell (m - 1, n - 1).

There are two types of moves available:

Normal move: You can move right or down from your current cell (i, j), i.e. you can move to (i, j + 1) (right) or (i + 1, j) (down). The cost is the value of the destination cell.

Teleportation: You can teleport from any cell (i, j), to any cell (x, y) such that grid[x][y] <= grid[i][j]; the cost of this move is 0. You may teleport at most k times.

Return the minimum total cost to reach cell (m - 1, n - 1) from (0, 0).

 

Example 1:

Input: grid = [[1,3,3],[2,5,4],[4,3,5]], k = 2

Output: 7

Explanation:

Initially we are at (0, 0) and cost is 0.

Current Position	Move	New Position	Total Cost
(0, 0)	Move Down	(1, 0)	0 + 2 = 2
(1, 0)	Move Right	(1, 1)	2 + 5 = 7
(1, 1)	Teleport to (2, 2)	(2, 2)	7 + 0 = 7
The minimum cost to reach bottom-right cell is 7.

Example 2:

Input: grid = [[1,2],[2,3],[3,4]], k = 1

Output: 9

Explanation:

Initially we are at (0, 0) and cost is 0.

Current Position	Move	New Position	Total Cost
(0, 0)	Move Down	(1, 0)	0 + 2 = 2
(1, 0)	Move Right	(1, 1)	2 + 3 = 5
(1, 1)	Move Down	(2, 1)	5 + 4 = 9
The minimum cost to reach bottom-right cell is 9.

 

Constraints:

2 <= m, n <= 80
m == grid.length
n == grid[i].length
0 <= grid[i][j] <= 104
0 <= k <= 10

"