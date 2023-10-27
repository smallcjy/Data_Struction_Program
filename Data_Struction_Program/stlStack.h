 #define _CRT_SECURE_NO_WARNINGS 1
#ifndef STL_STACK_HXX
#define STL_STACK_HXX
#include<iostream>
using namespace std;

template<typename T>class Link {
public:
	T element;
	Link* next;

public:
	Link(const T& elemval, Link* nextval = NULL) {
		element = elemval;
		next = nextval;
	}
	Link(Link* nextval = NULL) {
		next = nextval;
	}
};



template<typename T>class stlStack {

public:
	stlStack() {
		size = 0;		//costruction
		top = NULL;
		//cout << "construction sucess" << endl;
	};

	void clear() {
		Link<T>* temp = top;
		while (top->next != NULL) {
			top = top->next;
			delete temp;
		}
		size = 0;
		
	}
	
	void push(const T& t) {
		top = new Link<T>(t, top);
		size++;
	}
	const T& topValue() {
		if (top == NULL) {
			cout << "Stack is empty" << endl;
			return 0;
		}
		return top->element;
	}
	const T& pop() {
		if (top == NULL) {
			cout << "Stack is empty" << endl;
			return 0;
		}
		Link<T>* temp = top;
		top = top->next;
		return temp->element;
	}

private:
	
	Link<T>* top;
	int size;
};














#endif // !STL_STACK_HXX
