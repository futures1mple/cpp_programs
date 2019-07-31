#include <stdio.h>
#include <stdlib.h>
void piramid (int *a,int n) {
	int i,r,l,tmp,pmt,b;
	for(i=(n-2)/2;i>=0;i--) {
		b=i;
		while (b<n) {
			l=2*b+1;
			r=l+1;
			if(l>=n) break;
			if(r<n && a[r]>a[l]) l=r;
			if(a[l]>a[b]) {
				tmp=a[l];
				a[l]=a[b];
				a[b]=tmp;
				b=l;
			}
			else break;
		}
	}
	while(n>1) {
		tmp=a[0];
		a[0]=a[n-1];
		a[n-1]=tmp;
		n--;
		b=0;
		while(b<n) {
			l=2*b+1;
			r=l+1;
			if(l>=n) break;
			if(r<n && a[r]>a[l]) l=r;
			if(a[l]>a[b]) {
				pmt=a[b];
				a[b]=a[l];
				a[l]=pmt;
				b=l;
			}
			else break;
		}
	}
}




int main() {
	
	int *a,n,i;
	scanf("%d", &n);
	a=(int*)malloc(n*sizeof(int));
	for(i=0; i<n; i++)
	{
		a[i]=rand()%20;
	}
	for(i=0; i<n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n\n");
	piramid(a,n);
	for(i=0; i<n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n\n");
	return 0;
}



















