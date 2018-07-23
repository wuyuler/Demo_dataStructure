#include"BinTree.hpp"

struct AVLTree {
	BinTree*root;
	AVLTree() { root = NULL; }
	BinTree*search(char key) {
		BinTree*f = root;
		BinTree*p = f;
		while (p) {
			//查找key,如果找到p指向key所在的结点,否则指向key所在的上一层
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
		//插入二叉排序树,如果key存在就不重复插入
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
		//更新x结点的高度
		int lheight = (x->lchild == NULL) ? 0 : x->lchild->height;
		int rheight = (x->rchild == NULL) ? 0 : x->rchild->height;
		x->height = (lheight > rheight) ? lheight + 1 : rheight + 1;
		
	}
	void updateHeightAbove(BinTree*x) {
		//更新x结点以上的高度
		while (x) {
			updateHeight(x);
			x = x->parent;
		}

	}

	void connect34(BinTree*a, BinTree*b, BinTree*c, BinTree*T0, BinTree*T1, BinTree*T2, BinTree*T3) {
		//实现3+4重构
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
		//将p的父节点替换为q的父节点
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
			//判断p是否平衡,如果不平衡,属于哪种情况,该怎么调用connect34

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