#include <iostream> 

using namespace std;

void hashadd (int *a,int n,int x) {
	int k,kol=0;
	k = x%n;
	cout << endl << "x = " << x << endl;
	while(a[k] != 0) {
		k=(k+1)%n;
		kol++;
		if (k == x%n) {
			cout << "Polniy massiv" << endl;
			kol=0;
			return;
		}
	}
	cout << "Kolizii= " << kol << endl;
	a[k]=x;
	for(int i=0; i<n; i++) {
			cout << a[i] << " " ;
	}
	cout << endl;
}


void hashdel (int *a,int n,int x) {
	int j,i,k,kol=0,l,p,q,m;
	k=x%n;
	i=k;
	cout << endl << "x = " << x << endl;
	while (a[i] != x) {
		i = (i+1)%n;
		kol++;
		if(i == x%n) {
			cout << "Net elementa" << endl;
			kol=0;
			return;
		} 
	}
	//cout << "Kolizii poiska = " << kol << endl;
	a[i]=0;
	l=(i+1)%n;
	j=i;
	while (a[l] != 0 && l != j) {
		p=a[l]%n;
		q=i-p;
		m=l-p;
		if(m!=0) {
			if(m<0) m+=n;
			if(q<0) q+=n;
			if(m>q) {
				a[i]=a[l];
				a[l]=0;
				i=l;
			}
		}
		l=(l+1)%n;
		kol++;
	}
	cout << "Kolizii udaleniya+poiska = " << kol << endl;
	for(i=0;i<n;i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}


int main() {
	int *a,n;
	cin >> n;
	a = new int [n];
	for (int i=0;i<n;i++) {
		a[i]=0;
	}
	hashadd(a,n,72);
	hashadd(a,n,69);
	hashadd(a,n,22);
	hashadd(a,n,4);
	hashadd(a,n,59);
	hashadd(a,n,31);
	hashadd(a,n,15);
	hashadd(a,n,39);
	hashadd(a,n,6);
	hashadd(a,n,11);
	cout << "\n*** Udaleniye ***\n";
	hashdel(a,n,11);
	hashdel(a,n,69);
	hashdel(a,n,22);
	cout << "\n\n *** D O N E *** \n" << endl;
}
