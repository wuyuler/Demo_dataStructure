//HuffmanNode.hpp
struct HuffmanNode {
	char data;//字符
	int weight;//权重
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
		//TODO:判断当前结点是否为叶子结点
		if (lchild == 0 && rchild == 0)
			return true;
		return false;
	}
};
