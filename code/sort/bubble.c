#include<stdio.h>

#define N (1010)

int n,a[N];

void swap(int *a, int *b) {
    int t=*a;
    *a=*b;
    *b=t;
}
int main() {
    scanf("%d",&n);
    int i,j;
    for(i=1; i<=n; i++) {
        scanf("%d",&a[i]);
    }
    for(i=1; i<=n; i++) {
        for(j=1; j<i; j++) {
            if(a[j]>a[i]) swap(&a[i],&a[j]);
        }
    }
    for(i=1; i<=n; i++) {
        printf("%d ",a[i]);
    }
    puts("");
    return 0;
}


