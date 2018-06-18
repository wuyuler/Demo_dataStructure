static char screen[40][80]; //屏幕打印专用缓冲区
							//用'#'表示叶子结点后的空

struct BinTree {
	char data;
	BinTree *lchild, *rchild;
	BinTree(char d) {
		data = d;
		lchild = NULL;
		rchild = NULL;
	}
	~BinTree() {

		//递归析构,原理是delete时会调用类的析构函数
		if (lchild) delete lchild;
		if (rchild) delete rchild;
	}

	//输入含有叶子结点空指针标记的方式创建的二叉树
	static BinTree * create(const char* str, int &index) {
		//实现先序遍历字符串创建二叉树
		char ch = str[index++];
		if (ch == '#')return NULL;
		BinTree *node = new BinTree(ch);
		node->lchild = create(str, index);
		node->rchild = create(str, index);
		return node;

		

	}
	//递归求树的深度
	int deep() {
		int ldeep = (lchild == NULL) ? 0 : lchild->deep();
		int rdeep = (rchild == NULL) ? 0 : rchild->deep();
		return 1 + (ldeep > rdeep ? ldeep : rdeep);
	
	}

	//利用中序遍历在screen缓冲区中绘制二叉树图形

	int draw(int startx, int y, BinTree *parent) {
		int endx = startx; //endx表示当前子树最右端的x坐标
		//y+2表示元素值之间间隔一行
		if (lchild) endx =lchild-> draw(startx, y + 2, this) + 1;//如果有左子树,得到左子树最右边的x坐标加一
		int centerx = endx;		//根节点等于左子树最右边的x坐标加一
		screen[y][endx] = data;
		
		if (rchild) endx = rchild->draw(endx+1, y + 2, this) + 1;//如果有右子树,右子树的startx等于根节点x+1
		
		//打印到父节点的连接线
		if (parent) {
			if (parent->lchild == this) {
				for (int i = centerx;i <= endx;i++) 
					screen[y - 1][i] = '-';
				screen[y - 1][centerx] = '/';
				

			}
			else {
				for (int i = startx;i <= centerx;i++)
					screen[y - 1][i] = '-';
				screen[y - 1][centerx] = '\\'; //加转义符号才能用\

			}

		}
		return endx;


	}

	void output() {
		memset(screen, ' ', sizeof(screen));
		draw(0, 0, NULL);
		int height = deep() * 2;
		for (int i = 0;i < height;i++) {
			screen[i][40] = '\0';
			printf("%s\n", screen[i]);

		}




	}

	//实现先序遍历
	void preOrder() {
		cout << data;
		if (lchild) {
			lchild->preOrder();
		}
		else cout << '#';
		if (rchild) {
			rchild->preOrder();
		}
		else cout << '#';

	}

	//实现后序遍历
	void postOrder() {
		if (lchild) {
			lchild->postOrder();
		}
		else cout << '#';
		if (rchild) {
			rchild->postOrder();
		}
		else cout << '#';
		cout << data;
	}
	//由先序和中序重构二叉树
	static BinTree* rebuildByPreIn(const char *PreOrder, const char *InOrder, int len) {
		if (len == 0)return NULL;
		//先序串第一个即为根节点
		char r = PreOrder[0];
		BinTree *R = new BinTree(r);
		int pos = 0;
		//找到中序串中根节点的位置
		while (pos < len) {
			if (InOrder[pos] == r)break;
			pos++;
		}
		R->lchild = rebuildByPreIn(PreOrder + 1, InOrder, pos);
		R->rchild = rebuildByPreIn(PreOrder + pos+1, InOrder + pos+1, len - pos-1);

		return R;

	}

	//中序遍历二叉排序树,得到升序排列的第k个结点
	int output(int k) {
		int lcount = 0;
		if (lchild) {
			lcount = lchild->output(k);
			if (lcount < 0)return -1; //说明左子树已经完成输出,递归结束

		}
		if (lcount == k) {
			printf("%c\n", data); //左子树总共lcount个,第k个节点是从0开始的,所以在此时输出根节点
			return -1;
		}
		int rcount = 0;
		if (rchild) {
			rcount = rchild->output(k - lcount - 1);//右子树的第k-lcount-1小的结点,才是总的第k小的节点
			if (rcount < 0)return -1;

		}
		return lcount + rcount + 1;




	}


};