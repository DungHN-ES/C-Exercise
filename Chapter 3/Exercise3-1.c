#include <stdio.h>

int binSearch(int x, int v[], int n);

/* test */
int main()
{
    int x = 6;
    int v[7] = {1, 2, 3, 5, 6, 8, 11};
    printf("%d\n", binSearch(x, v, 7));
    return 0;
}

/* binSearch: find x in v[0] <- v[1] <- ... <- v[n-1]*/
int binSearch(int x, int v[], int n)
{
    int low = 0;
    int high = n-1;
    int mid = (low + high) / 2;
    while (low <= high && v[mid] != x)
    {
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
        mid = (low + high)/2;
    }
    if (v[mid] == x)    return mid;
    else return -1;
}