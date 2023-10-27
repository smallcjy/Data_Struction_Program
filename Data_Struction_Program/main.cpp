 #define _CRT_SECURE_NO_WARNINGS 1
//#include"double_list.h"
//#include"stackArr.h"
//#include"stlStack.h"
//#include"AQueue.h"
//#include"LQueue.h"
//#include"BinaryTree.h"
#include"SplayTree.h"
//#include"AVLtree.h"
#include<iostream>
using namespace std;




int main() {
	//test_code

	//DLink<int>* Dlink = new DLink<int>();
	//Dlink->insert_first(100);
	//Dlink->insert_last(50);
	//Dlink->insert(25,1);
	//cout << Dlink->size();
	//
	/*
	//stackArr<int>* stack1 = new stackArr<int>();
	//stack1->push(10);
	//cout << stack1->size() << endl;
	//stack1->pop();
	//cout << stack1->size() << endl;
	//stack1->~stackArr();*/


	//Lstack_test
	//stlStack<int>* LStack = new stlStack<int>();
	//LStack->push(10);
	//cout << LStack->topValue() << endl;

	/*AQueue<int>* Aqueue = new AQueue<int>(20);
	Aqueue->enqueue(0);
	Aqueue->enqueue(1);
	Aqueue->enqueue(2);
	Aqueue->enqueue(3);
	cout << Aqueue->dequeue() << Aqueue->dequeue() << endl;
	cout << Aqueue->frontValue() << endl;
	Aqueue->clear();
	cout << Aqueue->frontValue() << endl;*/

	//LQueue<int>* lqueue = new LQueue<int>();
	//lqueue->enqueue(10);
	//lqueue->enqueue(20);
	//cout << lqueue->length();
	////cout << lqueue->dequeue() << endl;
	//lqueue->deleteQueue();
	//cout << lqueue->length();


	//tree test
	//BinaryTree<int>* byTree = new BinaryTree<int>(5, 10);


	//SplayTree test

	SPTree<int>* tree=new SPTree<int>();
	tree->insert(3);
	tree->insert(2);
	tree->insert(1);
	tree->rightRatation(tree->gethead());


	

	return 0;
}

