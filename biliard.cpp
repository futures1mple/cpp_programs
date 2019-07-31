#include <iostream>

using namespace std;

class Stack {
	private:
	int size, l;
	int *a;
	public:
	Stack (int s) {
		size = s;
		l=0;
		a = new int[size];
	}
	int add(int el) {
		if (l >= size) return -1;
			a[l]=el;
			l++;
		return 0;
	}
	int del() {
		int b;
		if (l <= 0) return 0;
		l--;
		b = a[l];
		a[l]=0;
		return b;
	}
};

void proverka(int * b, int n) {
	int i=1;
	for(i=i;b[i] > b[i-1] && i<=n;i++);
	i++;
	for(i=i;b[i] < b[i-1] && i<=n;i++); 
	if(i < n){ 
		cout << "Ne po poryadku zabiti wari" << endl;
		return;
	}
	cout << "wari zabiti v pravilnom poryadke" << endl;
}

int main () {
	int n,i=0,*b,k,t,j;
	cout << "Skolko warov" << endl;
	cin >> n;
	b = new int[n];
	Stack a(n);
	for(j=n;j>0;j--) {
		cout << "Kakoy war zakatit?" << endl;
		cin >> k;
		a.add(k);
		cout << "Pomownik vitawil?" << endl;
		cin >> t;
		if(t != 0) { 
			k = a.del(); 
			b[i] = k; 
			i++;
		}
	}
	for(k = a.del();k!=0;k = a.del()) {
		b[i] = k;
		i++;
	}
	for(i=0;i<n;i++) {
		cout << b[i] << " ";
	}
	cout << endl;
	proverka(b,n);
	return 0;
}
