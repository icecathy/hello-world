#include <iostream>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <algorithm>
 
using namespace std;
const int N = 10000005;
 
int a[N];
 
void solve()
{
    int n, k;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &k);
    
    int l,r,m,ans=-1;
    l=r=a[0];
    for(int i=1; i<n; i++) {
        l=min(l,a[i]);
        r=max(r,a[i]);
    }
    while(l<r) {
        m=(l+r)/2;
        int t=0;
        for(int i=0; i<n; i++) {
            if(a[i]<=m) ++t;
        }
        if(t<k) {
            l=m+1;
        }
        else {
            r=m;
        }
    }
//
//    printf("The %d th number is : %d\n", k, ans);
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
