template<typename T>
struct Stack {
	T* items;
	int capacity;
	int top;
	Stack(int c = 10) {
		top = 0;
		capacity = c;
		items = new T[capacity];//����ռ�

	}
	~Stack() {
		delete[] items;

	}

	void output() {
		//��ӡ���
		for (int i = 0;i < top;i++)
			cout << items[i];

	};

	void push(T e) {
		//Ԫ����ջ,����Ԫ���ٸ�ָ��
		if (top < capacity) {
			items[top] = e;
			top++;
		}
		else {
			cout << "ջ����";
		}


	}

	T peek() {
		//ȡջ��Ԫ��
		return items[top - 1];
	}

	T pop() {
		//ջ��Ԫ�س�ջ
		if (top > 0) {
			top--;

			return items[top];
		}
		else {
			cout << "ջ�ѿ�";
			return NULL;

		}


	}





};