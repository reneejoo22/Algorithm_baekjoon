#include <stdio.h>

int main()
{
    int n, f=0;
    int v[999];
    scanf("%d", &n);
    for(int i=0; i < n; i++)
    {
        scanf("%d", v+i);
        f += (i&1)?-v[i]:v[i];
    }
    f/=2;
    printf("%d\n", f);
    for(int i=0; i < n-1; i++)
    {
        f = v[i]-f;
        printf("%d\n", f);
    }
    return 0;
}