#include"BinTree.hpp"

struct AVLTree {
	BinTree*root;
	AVLTree() { root = NULL; }
	BinTree*search(char key) {
		BinTree*f = root;
		BinTree*p = f;
		while (p) {
			//����key,����ҵ�pָ��key���ڵĽ��,����ָ��key���ڵ���һ��
			if (p->data == key)return p;
			if (key < p->data) {
				f = p;
				p = p->lchild;
			}
			else { f = p;p = p->rchild; }
		}
		return f;
	}

	void insert(char key) {
		//�������������,���key���ھͲ��ظ�����
		BinTree* p=search(key);
		BinTree *f = new BinTree(key);
		if (p == NULL) {
			root = f;
		}
		else if (key == p->data)return;
		else if (key < p->data) {
			p->lchild = f;
			f->parent = p;
		}
		else {
			p->rchild = f;
			f->parent = p;
		}

		updateHeightAbove(f);
		balance(f);
	}
	void updateHeight(BinTree*x) {
		//����x���ĸ߶�
		int lheight = (x->lchild == NULL) ? 0 : x->lchild->height;
		int rheight = (x->rchild == NULL) ? 0 : x->rchild->height;
		x->height = (lheight > rheight) ? lheight + 1 : rheight + 1;
		
	}
	void updateHeightAbove(BinTree*x) {
		//����x������ϵĸ߶�
		while (x) {
			updateHeight(x);
			x = x->parent;
		}

	}

	void connect34(BinTree*a, BinTree*b, BinTree*c, BinTree*T0, BinTree*T1, BinTree*T2, BinTree*T3) {
		//ʵ��3+4�ع�
		b->lchild = a;
		b->rchild = c;
		a->lchild = T0;
		a->rchild = T1;
		c->lchild = T2;
		c->rchild = T3;
		a->parent = b;
		c->parent = b;
		if (T0 != NULL) {
			T0->parent = a;

		}
		if (T1 != NULL) {
			T1->parent = a;

		}
		if (T2 != NULL) {
			T2->parent = c;

		}
		if (T3 != NULL) {
			T3->parent = c;

		}
		updateHeightAbove(a);
		updateHeightAbove(c);
		//if (b->parent == NULL)root = b;
		
	}

	void replaceParent(BinTree*p, BinTree*q) {
		//��p�ĸ��ڵ��滻Ϊq�ĸ��ڵ�
		if (p!=NULL&&q != NULL) {
			if (q->parent != NULL) {
				p->parent = q->parent;
				if (p->data < p->parent->data)
					p->parent->lchild = p;
				else p->parent->rchild = p;
			}
			else {
				p->parent = NULL;
				root = p;

			}
			
		}
	}

	int gapOfHeight(BinTree*a, BinTree*b) {
		if (a != NULL && b != NULL) {
			return a->height - b->height;
		}
		else if(a == NULL && b != NULL) {
			return -(b->height);
		}
		else if (a != NULL && b == NULL)return a->height;
		else return 0;

	}
	void balance(BinTree *x) {
		BinTree*g = x;
		BinTree*p, *v;
		while (g) {
			//�ж�p�Ƿ�ƽ��,�����ƽ��,�����������,����ô����connect34

			if (gapOfHeight(g->lchild,g->rchild)>=2) {
				p = g->lchild;
				if (gapOfHeight(p->lchild,p->rchild)>0) {
					v = p->lchild;
					replaceParent(p, g);

					connect34(v, p, g, v->lchild, v->rchild, p->rchild, g->rchild);
				}
				else {
					v = p->rchild;
					replaceParent(v, g);
					connect34(p, v, g, p->lchild, v->lchild, v->rchild, g->lchild);
					
				}
			}
			else if (gapOfHeight(g->rchild,g->lchild)>=2) {
				p = g->rchild;
				if (gapOfHeight(p->lchild, p->rchild)>0) {
					v = p->lchild;
					replaceParent(v, g);
					connect34(g, v, p, g->lchild,v->lchild,v->rchild,p->rchild);
				
				}
				else {
					v = p->rchild;
					replaceParent(p, g);
					connect34(g,p,v,g->lchild,p->lchild,v->lchild,v->rchild);
					
				}
			}

			g = g->parent;
			

		}
	}
	void output() {
		if (root)root->output();
		else cout << "Empty BST." << endl;
	}

};