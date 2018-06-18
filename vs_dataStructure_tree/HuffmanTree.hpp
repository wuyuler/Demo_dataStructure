#include "HuffmanNode.hpp"
#include<string.h>
//Huffman树
struct HuffmanTree
{
	int n;//编码数量
	HuffmanNode* nodes;
	char table[128];//ASCII索引表
	HuffmanTree(int n) {
		this->n = n;
		nodes = new HuffmanNode[n * 2 + 2];


	}
	~HuffmanTree() {
		delete[]nodes;
	}
	void create(const char *charset, int weight[]) {
		for (int i = 0;i < n;i++)
			table[charset[i]] = i + 1;
		//通过填表建树

		//填入要编码的叶子节点
		for (int i = 1;i <= n;i++) {
			nodes[i].data = charset[i - 1];
			nodes[i].weight = weight[i - 1];
			nodes[i].lchild = 0;
			nodes[i].rchild = 0;

		}


		//通过不断配对最小的两个节点得到树
		for (int i = n;i < 2 * n - 1;i++) {
			int c = 0, a = 0, b = 0;
			for (int j = 1;j <= i;j++) {//先取两个值
				if (nodes[j].parent == 0 && c < 1) {
					a = j;
					c++;
					continue;
				}
				if (nodes[j].parent == 0) {
					b = j;
					break;
				}

			}

			if (nodes[a].weight < nodes[b].weight) {
				c = a;
				a = b;
				b = c;
			}
			for (int j = 1;j <= i;j++) {//得到权重最小的两个根结点

				if (nodes[j].parent == 0 && j != b && nodes[j].weight < nodes[a].weight)a = j;
				if (nodes[a].weight < nodes[b].weight) {//始终保持a的权重>b的权重
					c = a;
					a = b;
					b = c;
				}
			}
			//两个权重最小的无父结点的结点,得到一个新的无父节点
			nodes[i + 1].weight = nodes[a].weight + nodes[b].weight;
			nodes[i + 1].lchild = b;
			nodes[i + 1].rchild = a;
			nodes[a].parent = i + 1;
			nodes[b].parent = i + 1;
		}


		//通过遍历树完成编码表
		char code[10] = { 0 };
		fillCode(2 * n - 1, code, 0);

	}

	void fillCode(int i, char *code, int len) {
		HuffmanNode &node = nodes[i];


		if (node.lchild) {
			code[len++] = '0';
			fillCode(node.lchild, code, len);
			len--;
		}

		if (node.rchild) {
			code[len++] = '1';
			fillCode(node.rchild, code, len);

		}
		if (node.isLeaf()) {
			node.code = new char[10];

			code[len++] = '\0';
			//memcpy(node.code,code,sizeof(char)*len);//code传递的指针,在编完一个3编码后,返回在编一个2编码就会出错,必须每次确定编码长度
			//别忘记复制结束符
			strcpy(node.code, code);

			return;
		}
		else    return;

	}


	void output() {
		cout << "序号\t" << "权重\t" << "左节点\t" << "右节点\t" << "父节点\t" << "字符\t" << "编码\t" << endl;
		for (int i = 1;i <= 2 * n - 1;i++) {
			cout << i << "\t";
			nodes[i].output();
		}


	}

	void encode(const char*src, char*dst) {
		dst[0] = '\0';
		for (int i = 0;i<strlen(src);i++) {
			dst = strcat(dst, nodes[table[src[i]]].code);


		}



	}

	void decode(char*src, char*dst) {
		int a = 0;

		while (src[0]) {

			for (int i = 1;i <= n;i++) {
				if (strncmp(src, nodes[i].code, strlen(nodes[i].code)) == 0) {
					dst[a] = nodes[i].data;
					a++;
					src = src + strlen(nodes[i].code);
					break;

				}

			}


		}

	}
};