#ifndef LQUEUE_HXX

#define LQUEUE_HXX

#include<iostream>
using namespace std;

template <typename T>class LinkNode {
public:
	T t;
	LinkNode* next;
public:
	LinkNode() {};						//先无参构造才能有参构造
	LinkNode(T data) {
		this->t = data;
		this->next=NULL;
	}

};

template <typename T>class LQueue {
private:
	int size;
	LinkNode<T>* phead;
	LinkNode<T>* ptail;

public:
	LQueue() {
		size = 0;
		LinkNode<T>* ptail=new LinkNode<int>();
		LinkNode<T>* phead = new LinkNode<int>();
		phead = NULL;
		ptail = NULL;

	}

	void enqueue(T t) {
		LinkNode<T>* newNode = new LinkNode<T>(t);			//参数在函数声明处声明变量类型后就不要重新声明，哪怕一样也不行
		if (phead == NULL) {
			phead = newNode;
		}
		else {
			ptail->next = newNode;
		}
		ptail = newNode;
		size++;
	}

	T dequeue() {
		if (size == 0) {
			cout << "This is empty queue.";
		}
		else {
			LinkNode<int>* temp = new LinkNode<T>();
			temp = phead;
			phead = phead->next;
			T val = temp->t;
			delete temp;
			size--;
			return val;
		}
	}

	void deleteQueue() {
		LinkNode<int>* cur = new LinkNode<T>();
		cur = phead;
		while (cur) {
			LinkNode<int>* next = cur->next;
			free(cur);
			cur = next;
			size--;
			
		}
		cur = NULL;
		phead = NULL;
		ptail = NULL;
	}

	int length() {
		return size;
	}

}; 



#endif // !LQueue_HXX