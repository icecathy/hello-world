// *****************************************************************************
// not my code !!!
// *****************************************************************************
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <algorithm>
 
using namespace std;
const int N = 60010;
 
int a[N];
 
//插入排序
void InsertSort(int a[], int l, int r)
{
    for(int i = l + 1; i <= r; i++)
    {
        if(a[i - 1] > a[i])
        {
            int t = a[i];
            int j = i;
            while(j > l && a[j - 1] > t)
            {
                a[j] = a[j - 1];
                j--;
            }
            a[j] = t;
        }
    }
}
 
//寻找中位数的中位数
int FindMid(int a[], int l, int r)
{
    if(l == r) return l;
    int i = 0;
    int n = 0;
    for(i = l; i < r - 5; i += 5)
    {
        InsertSort(a, i, i + 4);
        n = i - l;
        swap(a[l + n / 5], a[i + 2]);
    }
 
    //处理剩余元素
    int num = r - i + 1;
    if(num > 0)
    {
        InsertSort(a, i, i + num - 1);
        n = i - l;
        swap(a[l + n / 5], a[i + num / 2]);
    }
    n /= 5;
    if(n == l) return l;
    return FindMid(a, l, l + n);
}
 
//进行划分过程
int Partion(int a[], int l, int r, int p)
{
    swap(a[p], a[l]);
    int i = l;
    int j = r;
    int pivot = a[l];
    while(i < j)
    {
        while(a[j] >= pivot && i < j)
            j--;
        a[i] = a[j];
        while(a[i] <= pivot && i < j)
            i++;
        a[j] = a[i];
    }
    a[i] = pivot;
    return i;
}
 
int BFPRT(int a[], int l, int r, int k)
{
    int p = FindMid(a, l, r);    //寻找中位数的中位数
    int i = Partion(a, l, r, p);
    //int i=l;
    //return -1;
 
    int m = i - l + 1;
    if(m == k) return a[i];
    if(m > k)  return BFPRT(a, l, i - 1, k);
    return BFPRT(a, i + 1, r, k - m);
}
 
void solve()
{
    int n, k;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &k);
    BFPRT(a,0,n-1,k);
//    printf("The %d th number is : %d\n", k, BFPRT(a, 0, n - 1, k));
//    for(int i = 0; i < n; i++)
//        printf("%d ", a[i]);
//    puts("");
}
int main() {
    int T;
    scanf("%d",&T);
    while(T>0) {
        solve();
        --T;
    }
    return 0;
}

/**
10
72 6 57 88 60 42 83 73 48 85
5
*/
