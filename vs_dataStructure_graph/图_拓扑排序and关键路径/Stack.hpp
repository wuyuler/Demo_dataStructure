template<typename T>
struct Stack {
	T* items;
	int capacity;
	int top;
	Stack(int c = 10) {
		top = 0;
		capacity = c;
		items = new T[capacity];//申请空间

	}
	~Stack() {
		delete[] items;

	}

	void output() {
		//打印输出
		for (int i = 0;i < top;i++)
			cout << items[i];

	};

	void push(T e) {
		//元素入栈,先入元素再改指针
		if (top < capacity) {
			items[top] = e;
			top++;
		}
		else {
			cout << "栈已满";
		}


	}

	T peek() {
		//取栈顶元素
		return items[top - 1];
	}

	T pop() {
		//栈顶元素出栈
		if (top > 0) {
			top--;

			return items[top];
		}
		else {
			cout << "栈已空";
			return NULL;

		}


	}





};