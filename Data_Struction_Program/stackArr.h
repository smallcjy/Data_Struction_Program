 #define _CRT_SECURE_NO_WARNINGS 1
#ifndef STACK_ARR_HXX
#define STACK_ARR_HXX

#include<iostream>
using namespace std;

template<typename T>class stackArr {
public:
	//默认大小20
	stackArr() {
		arr = new T[20];
		count = 0;
		if (!arr) {
			cout << "arr malloc false!" << endl;
		}
		
	}

	//销毁
	~stackArr() {
		if (arr) {
			delete[] arr;
			arr = NULL;
		}
		cout << "xiaohui success!" << endl;
	}

	//添加t到栈中
	void push(T t) {
		arr[count++] = t;
	
	};

	//返回栈顶元素值
	T peek() {
		return arr[count - 1];
	};

	//删除栈底元素并返回
	T pop() {
		int ret = arr[count - 1];
		count--;
		return ret;
	};

	int size() {
		return count;
	};
	int isEmpty() {
		
	};
private:
	T* arr;
	int count;
};





#endif // !STACK_ARR_HXX
