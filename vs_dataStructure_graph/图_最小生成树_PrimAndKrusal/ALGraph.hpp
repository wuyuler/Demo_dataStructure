//�����
struct ArcNode {
	int adjvex; //�ñ�ָ��ڵ�����,��������ɫ����
	ArcNode*nextarc;
	int info;//���Դ�����Ϣ
	ArcNode(int adj, int w) {
		adjvex = adj;info = w;
		nextarc = NULL;

	}

	void output() {
		printf("->(adj=%d,w=%d)", adjvex, info);
	}
};

//������
struct VexNode {
	char data;//�����Դ�����Ϣ
	ArcNode *firstarc;
	VexNode() {
		firstarc = NULL;
	}
	~VexNode() {
		delete firstarc;
	}
	void output() {
		cout << "����" << data;
		ArcNode*p = firstarc;
		while (p) {
			p->output();
			p = p->nextarc;
		}
		cout << endl;
	}
	void addArc(int adj, int w) {
		//������ͷ���Ĳ���
		ArcNode *p = new ArcNode(adj, w);
		p->nextarc = firstarc;
		firstarc = p;
	}
};
struct ALGraph {
	//�ڽ�����ʽ�洢
	VexNode *vertices;
	int vexnum;//���������
	int kind;//ͼ������
	ALGraph(const char* names, int k = 1) {
		kind = k;
		vexnum = strlen(names);
		vertices = new VexNode[vexnum];
		for (int i = 0;i < vexnum;i++) {
			vertices[i].data = names[i];


		}

	}
	~ALGraph()
	{
		delete[] vertices;
	}
	void output() {
		for (int i = 0;i < vexnum;i++) {
			vertices[i].output();

		}

	}

	void addArc(int tail, int head, int w = 0) {
		vertices[tail].addArc(head, w);
		if (kind == 0) {
			vertices[head].addArc(tail, w);
		}
	}
	int getNumOfArc() {
		int numOfArc = 0;
		for (int i = 0;i < vexnum;i++) {
			ArcNode* p = (vertices[i]).firstarc;
			while (p) {
				p = p->nextarc;
				numOfArc++;
			}

		}
		return numOfArc;
	}
};