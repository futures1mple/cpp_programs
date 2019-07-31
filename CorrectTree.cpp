#include <iostream>

using namespace std;

class treeitem {
    
    private:
    int value;
    treeitem *l,*r,*f;
    treeitem(int x=0) {
        value=x;
        l=NULL;
        r=NULL;
        f=NULL;
    }
    ~treeitem()
    {
		value=0;
		l=NULL;
		r=NULL;
		f=NULL;
	}
    friend class tree;
};
class tree {
    private:
    treeitem *root;
    public:
    tree () {
        root=new treeitem();
        root= NULL;
    }
    
    void add(int x) {
        treeitem *w,*an;
        int z;
        if(root == NULL) {
            root = new treeitem(x);
            return;
        }
        for(w=root;w!=NULL; ) {
            if( x == w->value) {
                cout << "Odinakoviy Element" << endl;
                return;
            }
            else if(x > w->value) {
                an=w;
                w=w->r;
                z=2;
            }
            else if(x < w->value) {
                an=w;
                w=w->l;
                z=1;
            }
        }
        w=new treeitem(x);
        w->f=an;
        if(z==1) {
            an->l=w;
        }
        if(z==2) {
            an->r=w;
        }
    }
    
    void show () {
		if(root == NULL) return;
        showr(root);
        cout << endl;
    }
    void showr (treeitem *node) {
        cout << node->value << " ";
        if(node->l != NULL) {
            cout << node->value << "L"; 
            showr(node->l);
        }
        if(node->r != NULL) {
            cout << node->value << "R";
            showr(node->r);
        }
    }
    treeitem *search (int x) {
        treeitem *w;
        w=root;
        while(w != NULL && w->value != x) {
            if(x > w->value) w=w->r;
            else w=w->l;
        }
        if(w == NULL) {
            //cout << "Net takoqo elementa" << endl;
            return NULL;
        }
        return w;
    }
	treeitem* f1(treeitem *root,treeitem *t) {
		treeitem *w;
		w = t->l;
			while(w->r != NULL) {
				w = w->r;
			} 
			if(w->l) w->l->f=w->f;
			if(!w->f){root=w->l; delete t; return NULL;}
			else {
				if(w->f->l == w) w->f->l=w->l;
				else if (w->f->r == w) w->f->r=w->l;
			}
			return w;
	}
	treeitem * f2(treeitem *root,treeitem *t) {
		treeitem *w;
		w = t->r;
			while(w->l != NULL) {
				w=w->l;
			}
			if(w->r) w->r->f = w->f;
			if(!w->f) {root=w->r; delete t; return NULL;}
			else {
				if(w->f->l == w) w->f->l=w->r;
				else if (w->f->r == w) w->f->r=w->r;
			}
			return w;
	}
	void del(int x) {
		treeitem *t, *w;
		t=search(x);
		if (t==NULL) {
			cout << "Net elementa" << endl; 
			return;
		}
		if(t->l == NULL && t->r == NULL) {
			if(t->f != NULL) {
				if(t->f->l == t){t->f->l = NULL;}
				if(t->f->r == t) t->f->r = NULL;
			}
			if(t==root) {
				delete t;
				root = NULL;
			}
			t=NULL;
			delete t;
			show();
			return;
		}
		else if(t->l == NULL || t->r == NULL) {
			if(t->l==NULL) w=f2(root,t);
			else w=f1(root,t);
		}
		else if(t->l != NULL && t->r != NULL) {w=f1(root,t);}
		    w->f = t->f;
			if(t!=root)
			{if(t->f->l == t) t->f->l = w;
			else t->f->r = w;}
			else root = w;
			w->l = t->l;
			w->r = t->r;
			t=NULL;
			delete t;
	}
};


int main () {
    tree a;
    //a.add(1);
    cout << "*** Do pervoqo udaleniya ***\n" << endl; 
    a.show();
    //a.del(1);
    a.add(8);
    a.show();
    a.add(6);
    a.show();
    a.add(7);
    a.show();
    a.add(4);
    a.show();
    a.add(3);
    a.show();
    a.add(5);
    a.show();
    a.add(2);
    a.show();
    cout<<endl<<endl;
    a.del(8);
    a.show();
   // a.show();
  //  cout << "\n\n*** Posle udaleniya i dobovleniya elementov ***\n" << endl;
   // a.show();
   // a.del(4);
  //  cout << "\n\n*** Posle vtoroqo udaleniya ***\n" << endl;
   // a.show();
   // a.del(2);
 //   cout << "\n\n*** Posle tret'eqo udaleniya ***\n" << endl;
   // a.show();
    /*a.add(10);
    a.del(10);
    a.add(19);
    a.add(16);
    a.add(14);
    a.add(18);
    a.add(15);
    a.add(17);
    a.show();
    a.del(10);
    a.show();*/
    return 0;
}
