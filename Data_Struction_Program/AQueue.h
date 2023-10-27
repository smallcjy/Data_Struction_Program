#ifndef AQUEUE_HXX
#define AQUEUE_HXX


#include<iostream>
using namespace std;

//线性实现AQUEUE

template <typename T>class AQueue {
	
private:
	int maxSize;
	int front;
	int rear;
	T* listArray;
	int currSize;

public:
	AQueue(int maxSizeVal) {
		maxSize = maxSizeVal;
		listArray = new T[maxSize];
		currSize = 0;
		front = 0;
		rear = 0;
	}

	void enqueue(T t) {
		if (rear == maxSize - 1) {
			cout << "the AQueue is full." << endl;
		}
		else if (currSize == 0) {
			listArray[rear] = t;
		}
		else {
			listArray[++rear] = t;
			
		}
		currSize++;
	}

	T dequeue() {
		if (currSize == 0) {
			cout << "the queue is empty" << endl;
		}
		else{
			T temp = listArray[front];
			for (int i = front; i < rear; i++) {
				listArray[i] = listArray[i + 1];
			}
			rear--;
			currSize--;
			return temp;
		}
	}

	const T& frontValue() {
		if (currSize == 0) {
			cout << "the queue is empty" << endl;
		}
		else {
			return listArray[front];
		}
	}

	int length() {
		return currSize;
	}

	~AQueue() {}
	void clear() {
		front = 0;
		rear = 0;
		currSize = 0;
		delete[]listArray;
	}

};


#endif // !AQUEUE_HXX
