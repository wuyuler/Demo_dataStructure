#include<string>
template<typename KeyType,typename ValueType>
struct HashMap {
	struct Pair {
		KeyType key;
		ValueType value;
		Pair*next = NULL;
		Pair() { next = NULL; }
		Pair(KeyType k, ValueType v) {
			key = k;
			value = v;
			next = NULL;
		}
	};
	int capacity;
	Pair*headers;
	HashMap(int c = 10) {
		capacity = c;
		headers = new Pair[c];
		memset(headers, NULL, sizeof(Pair)*c);
	}
	~HashMap() { delete[]headers; }

	unsigned int HashCode(string s) {
		//字符串hash函数,Key类型必须实现此函数
		int h = 0;
		for (int i = 0;i < s.size();i++)h = h * 131 + s[i];
		return h;
	}
	Pair*find(KeyType key) {
		int hash = HashCode(key) % capacity;
		Pair*f = &headers[hash];
		Pair*p = f->next;
		while (p) {
			if (p->key == key)return p;
			f = p;
			p = p->next;
		}
		return f;
	}
	void put(KeyType key, ValueType value) {
		//插入或覆盖值为key,内容为value的结点
		Pair*p = find(key);
		if (p->key == key)p->value = value;
		else p->next = new Pair(key, value);
	}

	void remove(KeyType key) {
		int hash = HashCode(key) % capacity;
		Pair*f = &headers[hash];
		Pair*p = f->next;
		while (p) {
			if (p->key == key) {
				f->next = p->next;
				delete p;
				break;
			}
			f = p;
			p = p->next;
		}
		
	}

	void output() {
		for (int i = 0;i < capacity;i++) {
			Pair*p = headers[i].next;
			cout << "hash code" << i << ":";
			while (p) {
				cout << "{" << p->key << ":" << p->value << "}";
				p = p->next;


			}
			cout << endl;

		}



	}




};