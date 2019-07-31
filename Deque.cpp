#include <iostream>
#include <cstdlib>
using namespace std;

class Deque {
	private:
	int size,maxsize,l,r;
	int *a;
	public:
	Deque(int s) {
		maxsize=s;
		r=0;
		l=s-1;
		size=0;
		a=new int[s];
	}
	friend ostream &operator << (ostream &stream , Deque y);
	friend int operator + (int z, Deque &y);
	void add_l (int x) {
		if(size==maxsize) return;
		a[l]=x;
		l=(maxsize+l-1)%maxsize;
		size++;
	}
	void add_r (int x) {
		if(size==maxsize) return;
		a[r]=x;
		r=(r+1)%maxsize;
		size++;
	}
	void show () {
		int i,k;
		if(size == 0) cout << "Pustoy deq" << endl;
		for(i=(l+1)%maxsize,k=0;k<size;i=(i+1)%maxsize,k++) {
			cout << a[i] << " " ;
		}
		cout << endl;
	}
	void del_l () {
		if(size > 0) {
			l=(l+1)%maxsize;
			a[l]=0;
			size--;
		}
		else return;
	}
	void del_r () {
		if(size > 0) {
			r=(maxsize + r - 1)%maxsize;
			a[r]=0;
			size--;
		}
		else return;
	}
	Deque &operator=(Deque &y) {
		delete a;
		a = new int [y.maxsize];
		maxsize = y.maxsize;
		size = y.size;
		l = y.l;
		r = y.r;
		for(int i=(l+1)%maxsize,k=0;k<size ;k++, i=(i+1)%maxsize) {
			a[i]=y.a[i];
			
		} 
		//cout << y.l << endl << y.r << endl;
		return *this;
	}
	Deque operator+(Deque &y) {
		int min;
		Deque *nd;
		nd = new Deque(maxsize + y.maxsize);
		if(size <= y.size) min = size;
		else min = y.size;
		for(int i=0;i<min;i++) {
			nd->add_r(a[i]);
			nd->add_r(y.a[i]);
		}
		if (min == size) {
			for(int i=min;i<y.size;i++) nd->add_r(y.a[i]);
		}
		else for(int i=min;i<size;i++) nd->add_r(a[i]);
		
		return *nd;
	}
				// Deuqe + number
	Deque operator + (int z) {
		Deque na(maxsize);
		na.size = size;
		na.l=l;
		na.r=r;
		for (int i=(l+1)%maxsize,k=0;k<size;k++,i=(i+1)%maxsize) {
			na.a[i] = a[i] + z;
		}
		return na;
	}

};
	ostream &operator << (ostream &stream , Deque y) {
		int i,k;
		if(y.size == 0) cout << "Pustoy deq" << endl;
		for(i=(y.l+1)%y.maxsize,k=0;k<y.size;i=(i+1)%y.maxsize,k++) {
			cout << y.a[i] << " " ;
		}
		cout << endl;
		return stream;
	}
				//number + Deque
	int operator + (int z, Deque &y) {
		int sum=z;
		for (int i=(y.l+1)%y.maxsize,k=0;k<y.size;k++,i=(i+1)%y.maxsize) {
			if(k%2==0) sum += y.a[i];
			else sum -= y.a[i];
		}
		return sum;
	}

int main () {
	Deque a(10);
	int i;
	/*for(int i=0;i<5;i++) {
		a.add_l(rand()%30);
		a.add_r(rand()%30);
	}*/
	for(i=1;i<8;i++) {
		a.add_r(i);
	}
	Deque b(4);
	for(i=8;i<12;i++) {
		b.add_r(i);
	}
	Deque c=a+b;
	//c.show();
	b=c;
	//b.show();
	Deque d=a+4;
	cout << "       a+4" << endl;
	cout << "a  =" << a ;
	cout << "a+4=" << d << endl;
	//cout << b << endl;
	int k;
	
	k = 4 + a;
	cout << "       4+a" << endl;
	cout << "a  =" << a ;
	cout << "4+a=" << k << endl;
	return 0;
 }
