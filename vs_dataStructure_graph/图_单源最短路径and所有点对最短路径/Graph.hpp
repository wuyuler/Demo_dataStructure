
struct Graph
{
	int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	char vertices[MAX_VERTEX_NUM + 1];
	int vexnum;
	int kind;
	Graph(const char *names, int k = 1) {
		kind = k;
		vexnum = strlen(names);
		strcpy(vertices, names);
		for (int i = 0;i < vexnum;i++) {
			for (int j = 0;j < vexnum;j++) {
				arcs[i][j] = INFINITY;
				if (i == j)arcs[i][j] = 0;

			}
				

		}
	}
		void addArc(int tail, int head, int w = 0) {
			arcs[tail][head] = w;
			if (kind == 0)
				arcs[head][tail] = w;
		}
	


};