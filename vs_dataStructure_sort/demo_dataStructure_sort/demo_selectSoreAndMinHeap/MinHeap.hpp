#include"List.hpp"
template<typename T>
struct MinHeap : List<T> {

	MinHeap(){}
	void adjustDown(int i = 0) {
		//位置i元素向下沉,直到其左右结点均比起大或者不存在
		while (i < List<T>::length) {
			int lchild = i * 2 + 1;
			int rchild = i * 2 + 2;
			int j = i;//默认不下降
			if (lchild >= List<T>::length)break;//存在左孩子继续
			if (List<T>::elem[lchild] < List<T>::elem[j])
				j = lchild;//如果左孩子比当前结点小,暂定为左孩子
			if (rchild < List<T>::length&&List<T>::elem[rchild] < List<T>::elem[j])
				j = rchild;//如果右孩子最小,定为右孩子
			if (i == j)break;//若果不能下降,停止调整
			swap(List<T>::elem[i], List<T>::elem[j]);
			i = j;//下沉到位置j

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