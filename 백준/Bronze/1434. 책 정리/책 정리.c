#include <stdio.h>
 
 
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a=0, b=0;
    int x;
    while (n--)
    {
        scanf("%d", &x);
        a += x;
    }
    while (m--)
    {
        scanf("%d", &x);
        b += x;
    }
    printf("%d", a - b);
}