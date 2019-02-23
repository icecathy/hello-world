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
    for(i=1; i<n; i++) {
        int min_index = i;
        for(j=i+1; j<=n; j++) {
            //if(a[i]>a[j]) swap(&a[i],&a[j]);
            if(a[min_index]>a[j]) min_index=j;
        }
        if(i!=min_index) swap(&a[i],&a[min_index]);
    }
     for(i=1; i<=n; i++) {
        printf("%d ",a[i]);
    }
    puts("");
    return 0;
}


