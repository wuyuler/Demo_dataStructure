//弧结点
struct ArcNode {
	int adjvex; //该边指向节点的序号,即书中蓝色方框
	ArcNode*nextarc;
	int info;//弧自带的信息
	ArcNode(int adj, int w) {
		adjvex = adj;info = w;
		nextarc = NULL;

	}

	void output() {
		printf("->(adj=%d,w=%d)", adjvex, info);
	}
};

//顶点结点
struct VexNode {
	char data;//顶点自带的信息
	ArcNode *firstarc;
	VexNode() {
		firstarc = NULL;
	}
	~VexNode() {
		delete firstarc;
	}
	void output() {
		cout << "顶点" << data;
		ArcNode*p = firstarc;
		while (p) {
			p->output();
			p = p->nextarc;
		}
		cout << endl;
	}
	void addArc(int adj, int w) {
		//类似于头结点的插入
		ArcNode *p = new ArcNode(adj, w);
		p->nextarc = firstarc;
		firstarc = p;
	}
};
struct ALGraph {
	//邻接链表方式存储
	VexNode *vertices;
	int vexnum;//顶点的数量
	int kind;//图的种类
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