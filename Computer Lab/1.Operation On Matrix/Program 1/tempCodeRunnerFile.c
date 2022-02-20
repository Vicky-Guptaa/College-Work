#include <stdio.h>

int main()
{
    system("clrs");
    int n, m;
    scanf("%d%d", &n, &m);
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int p, q;
    scanf("%d%d", &p, &q);
    int brr[p][q];
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            scanf("%d", &brr[i][j]);
        }
    }

    
    return 0;
}