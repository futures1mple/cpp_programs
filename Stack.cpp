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
	void show() {
		for (int i=0; i<size; i++) {
			if(i == l) cout << "<" << a[i] << ">";
			cout << a[i] << " ";
		}
		cout << endl;
	}
	void del() {
		if (l <= 0) return ;
		l--;
		a[l]=0;
	}
	Stack sum (Stack b) {
		int min;
		Stack t(l+b.l);
		if (l <= b.l) min = l;
		else min = b.l;
		for( int i=0; i<min; i++) {
			t.add(a[i]);
			t.add(b.a[i]);
		}
		if(min == l) {
			for(int i=min; i<b.l; i++) t.add(b.a[i]);
		}
		else for( int i=min; i<l; i++) t.add(a[i]);
		return t;
	}
};
int main() {
	int add;
	Stack a(10);
	Stack b(15);
	for (int i=0; i<10; i++) {
		add=a.add(i);
	}
	a.show();
	a.del();
	a.del();
	a.del();
	a.show();
	Stack d(5);
	for (int i=1; i<6; i++) {
		add=d.add(i);
	}
	Stack e(9);
	for (int i=6; i<15; i++) {
		add=e.add(i);
		cout << add << endl;
	}
	Stack c=d.sum(e);
	c.show();
	return 0;
}

