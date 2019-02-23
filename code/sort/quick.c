#include<stdio.h>

#define N (10000010)

int n,a[N];

void swap(int *a, int *b) {
    int t=*a;
    *a=*b;
    *b=t;
}
void quick_sort(int *a,int l,int r) {
    if(l>=r) return;
    int left=l, right=r, key=a[l];
    while(l<r) {
        while(l<r && key<=a[r]) --r;
        if(key>a[r]) {
            //swap(&a[l],&a[r]);
            a[l]=a[r];
            ++l;
        }
        while(l<r && key>=a[l]) ++l;
        if(key<a[l]) {
            //swap(&a[l],&a[r]);
            a[r]=a[l];
            --r;
        }
    }
    a[l]=key;
    quick_sort(a,left,l-1);
    quick_sort(a,l+1,right);
}
int main() {
    scanf("%d",&n);
    int i,j;
    for(i=1; i<=n; i++) {
        scanf("%d",&a[i]);
    }
    quick_sort(a,1,n);
    for(i=1; i<=n; i++) {
        printf("%d ",a[i]);
    }
    puts("");
    return 0;
}


