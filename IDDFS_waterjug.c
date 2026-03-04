#include <stdio.h>
#include <string.h>

int visited[5][4];
int goalFound = 0;

int min(int x, int y)
{
    if(x < y) return x;
    return y;
}

void DLS(int a, int b, int depth, int limit)
{
    if(a < 0 || b < 0 || a > 4 || b > 3 || visited[a][b] || goalFound)
        return;

    printf("(%d,%d) depth=%d\n", a, b, depth);

    if(a == 2 || b == 2)
    {
        printf("Goal reached!\n");
        goalFound = 1;
        return;
    }

    if(depth == limit)
        return;

    visited[a][b] = 1;

    int transfer;

    DLS(4,b,depth+1,limit);
    DLS(a,3,depth+1,limit);
    DLS(0,b,depth+1,limit);
    DLS(a,0,depth+1,limit);

    transfer = min(a,3-b);
    DLS(a-transfer,b+transfer,depth+1,limit);

    transfer = min(b,4-a);
    DLS(a+transfer,b-transfer,depth+1,limit);
}

void IDDFS()
{
    for(int limit=0; limit<=10; limit++)
    {
        printf("\nDepth Limit = %d\n", limit);

        memset(visited,0,sizeof(visited));
        goalFound = 0;

        DLS(0,0,0,limit);

        if(goalFound)
            return;
    }
}

int main()
{
    printf("Iterative Deepening DFS\n");

    IDDFS();

    return 0;
}
