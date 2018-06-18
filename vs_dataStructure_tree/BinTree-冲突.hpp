static char screen[40][80]; //��Ļ��ӡר�û�����
							//��'#'��ʾҶ�ӽ���Ŀ�

struct BinTree {
	char data;
	BinTree *lchild, *rchild;
	BinTree(char d) {
		data = d;
		lchild = NULL;
		rchild = NULL;
	}
	~BinTree() {

		//�ݹ�����,ԭ����deleteʱ����������������
		if (lchild) delete lchild;
		if (rchild) delete rchild;
	}

	//���뺬��Ҷ�ӽ���ָ���ǵķ�ʽ�����Ķ�����
	static BinTree * create(const char* str, int &index) {
		//ʵ����������ַ�������������
		char ch = str[index++];
		if (ch == '#')return NULL;
		BinTree *node = new BinTree(ch);
		node->lchild = create(str, index);
		node->rchild = create(str, index);
		return node;

		

	}
	//�ݹ����������
	int deep() {
		int ldeep = (lchild == NULL) ? 0 : lchild->deep();
		int rdeep = (rchild == NULL) ? 0 : rchild->deep();
		return 1 + (ldeep > rdeep ? ldeep : rdeep);
	
	}

	//�������������screen�������л��ƶ�����ͼ��

	int draw(int startx, int y, BinTree *parent) {
		int endx = startx; //endx��ʾ��ǰ�������Ҷ˵�x����
		//y+2��ʾԪ��ֵ֮����һ��
		if (lchild) endx =lchild-> draw(startx, y + 2, this) + 1;//�����������,�õ����������ұߵ�x�����һ
		int centerx = endx;		//���ڵ�������������ұߵ�x�����һ
		screen[y][endx] = data;
		
		if (rchild) endx = rchild->draw(endx+1, y + 2, this) + 1;//�����������,��������startx���ڸ��ڵ�x+1
		
		//��ӡ�����ڵ��������
		if (parent) {
			if (parent->lchild == this) {
				for (int i = centerx;i <= endx;i++) 
					screen[y - 1][i] = '-';
				screen[y - 1][centerx] = '/';
				

			}
			else {
				for (int i = startx;i <= centerx;i++)
					screen[y - 1][i] = '-';
				screen[y - 1][centerx] = '\\'; //��ת����Ų�����\

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

	//ʵ���������
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

	//ʵ�ֺ������
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
	//������������ع�������
	static BinTree* rebuildByPreIn(const char *PreOrder, const char *InOrder, int len) {
		if (len == 0)return NULL;
		//���򴮵�һ����Ϊ���ڵ�
		char r = PreOrder[0];
		BinTree *R = new BinTree(r);
		int pos = 0;
		//�ҵ������и��ڵ��λ��
		while (pos < len) {
			if (InOrder[pos] == r)break;
			pos++;
		}
		R->lchild = rebuildByPreIn(PreOrder + 1, InOrder, pos);
		R->rchild = rebuildByPreIn(PreOrder + pos+1, InOrder + pos+1, len - pos-1);

		return R;

	}

	//�����������������,�õ��������еĵ�k�����
	int output(int k) {
		int lcount = 0;
		if (lchild) {
			lcount = lchild->output(k);
			if (lcount < 0)return -1; //˵���������Ѿ�������,�ݹ����

		}
		if (lcount == k) {
			printf("%c\n", data); //�������ܹ�lcount��,��k���ڵ��Ǵ�0��ʼ��,�����ڴ�ʱ������ڵ�
			return -1;
		}
		int rcount = 0;
		if (rchild) {
			rcount = rchild->output(k - lcount - 1);//�������ĵ�k-lcount-1С�Ľ��,�����ܵĵ�kС�Ľڵ�
			if (rcount < 0)return -1;

		}
		return lcount + rcount + 1;




	}


};