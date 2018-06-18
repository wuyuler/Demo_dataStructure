//HuffmanNode.hpp
struct HuffmanNode {
	char data;//�ַ�
	int weight;//Ȩ��
	char *code;
	int lchild, rchild;
	int parent;

	HuffmanNode() {
		lchild = rchild = parent = 0;
		code = NULL;

	}
	~HuffmanNode() {
		if (code)
			delete[]code;
	}
	void output() {
		printf("%d\t%d\t%d\t%d\t", weight, lchild, rchild, parent);

		if (code)printf("%c\t%s", data, code);
		cout << endl;
	}
	bool isLeaf() {
		//TODO:�жϵ�ǰ����Ƿ�ΪҶ�ӽ��
		if (lchild == 0 && rchild == 0)
			return true;
		return false;
	}
};
