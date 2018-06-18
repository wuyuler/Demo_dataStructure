#include "HuffmanNode.hpp"
#include<string.h>
//Huffman��
struct HuffmanTree
{
	int n;//��������
	HuffmanNode* nodes;
	char table[128];//ASCII������
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
		//ͨ�������

		//����Ҫ�����Ҷ�ӽڵ�
		for (int i = 1;i <= n;i++) {
			nodes[i].data = charset[i - 1];
			nodes[i].weight = weight[i - 1];
			nodes[i].lchild = 0;
			nodes[i].rchild = 0;

		}


		//ͨ�����������С�������ڵ�õ���
		for (int i = n;i < 2 * n - 1;i++) {
			int c = 0, a = 0, b = 0;
			for (int j = 1;j <= i;j++) {//��ȡ����ֵ
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
			for (int j = 1;j <= i;j++) {//�õ�Ȩ����С�����������

				if (nodes[j].parent == 0 && j != b && nodes[j].weight < nodes[a].weight)a = j;
				if (nodes[a].weight < nodes[b].weight) {//ʼ�ձ���a��Ȩ��>b��Ȩ��
					c = a;
					a = b;
					b = c;
				}
			}
			//����Ȩ����С���޸����Ľ��,�õ�һ���µ��޸��ڵ�
			nodes[i + 1].weight = nodes[a].weight + nodes[b].weight;
			nodes[i + 1].lchild = b;
			nodes[i + 1].rchild = a;
			nodes[a].parent = i + 1;
			nodes[b].parent = i + 1;
		}


		//ͨ����������ɱ����
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
			//memcpy(node.code,code,sizeof(char)*len);//code���ݵ�ָ��,�ڱ���һ��3�����,�����ڱ�һ��2����ͻ����,����ÿ��ȷ�����볤��
			//�����Ǹ��ƽ�����
			strcpy(node.code, code);

			return;
		}
		else    return;

	}


	void output() {
		cout << "���\t" << "Ȩ��\t" << "��ڵ�\t" << "�ҽڵ�\t" << "���ڵ�\t" << "�ַ�\t" << "����\t" << endl;
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