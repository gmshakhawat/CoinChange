#include<stdio.h>

int count( int S[], int m, int n )
{
    int i, j, x, y;
    int table[n+1][m];

    for (i=0; i<m; i++)
    {
        table[0][i] = 1;
    }

    for (i = 1; i < n+1; i++)
    {
        for (j = 0; j < m; j++)
        {
            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0;

            y = (j >= 1)? table[i][j-1]: 0;
            table[i][j] = x + y;

        }
        printf("[%d ]",table[0][i]);
    }
    return table[n][m-1];
}

int main()
{
    int ag;

    int size = 0, i;
    int *v = NULL;
    int val;
    printf("Enter available coin list :");
    while(scanf("%d", &val) == 1 && val != -1)
    {
        v = realloc(v, (size+1) * sizeof(int));
        v[size++] = val;
    }

    int n ;
    ag:
    printf("Enter Changing Amount : ");
    scanf("%d",&n);
    printf(" %d ", count(v, size, n));
    goto ag;
    return 0;
}
