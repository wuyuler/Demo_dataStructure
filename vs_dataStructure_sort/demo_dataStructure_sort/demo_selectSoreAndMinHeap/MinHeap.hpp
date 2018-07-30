#include"List.hpp"
template<typename T>
struct MinHeap : List<T> {

	MinHeap(){}
	void adjustDown(int i = 0) {
		//λ��iԪ�����³�,ֱ�������ҽ����������߲�����
		while (i < List<T>::length) {
			int lchild = i * 2 + 1;
			int rchild = i * 2 + 2;
			int j = i;//Ĭ�ϲ��½�
			if (lchild >= List<T>::length)break;//�������Ӽ���
			if (List<T>::elem[lchild] < List<T>::elem[j])
				j = lchild;//������ӱȵ�ǰ���С,�ݶ�Ϊ����
			if (rchild < List<T>::length&&List<T>::elem[rchild] < List<T>::elem[j])
				j = rchild;//����Һ�����С,��Ϊ�Һ���
			if (i == j)break;//���������½�,ֹͣ����
			swap(List<T>::elem[i], List<T>::elem[j]);
			i = j;//�³���λ��j

		}
	}
	void enqueue(T e) {
		List<T>::append(e);
		for (int i = List<T>::length / 2 - 1; i >= 0; i--) {
			adjustDown(i);
		}
	}

	T dequque() {
		if (List<T>::length != 0) {
			T temp = List<T>::elem[0];
			List<T>::elem[0] = List<T>::elem[--List<T>::length];
			adjustDown(0);
			return temp;
		}
		return NULL;

	}

	void sort(T*array, int left, int right) {
		for (int i = left; i < right; i++) {
			enqueue(array[i]);
		}
		int i = 0;
		
		while (List<T>::length != 0) {
			array[i++] = dequque();
		}
		
	}
};