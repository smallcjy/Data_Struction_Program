#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdio.h>
#include "double_list.h"
using namespace std;

//C++实现双向链表

//构造函数
template <typename T>DLink<T>::DLink() {
	//创建表头，第一个头节点，不储存数据
	phead = new DNode<T>();
	phead->prev = phead->next = phead;	//前指针和后指针都指在第一个节点
	count = 0;

}

template <typename T>DLink<T>::~DLink() {
	//删除所有节点
	DNode<T>* ptmp;
	DNode<T>* pnode = phead->next;
	while (pnode != phead) {
		ptmp = pnode;
		pnode->next = pnode;
		delete ptmp;

	}

	//删除表头
	delete phead;
	phead = NULL;
}


//返回链表大小
template <typename T>int DLink<T>::size() {
	return count;
}

//判断链表是否为空
template <typename T>bool DLink<T>::is_empty() {
	if (count ==0){
		return true;
	}
	else {
		return false;
	}
}

//获取第index位置的节点,返回一个指向该节点的指针
template <typename T>DNode<T>* DLink<T>::getNode(int index) {
	//判断输入参数有效性，提高程序的健壮性
	if (index<0 || index>count) {
		cout << "get node failed1" << endl;
		return NULL;
	}

	//正向查找
	if (index <= count/2) {
		int i = 0;
		DNode<T>* pindex = phead->next;
		while (i++ < index) {
			pindex = pindex->next;

		}
		return pindex;

	}
	//逆向查找
	if (index > count / 2) {
		int j = 0;
		int rindex = count - index - 1;
		DNode<T>* pindex = phead->prev;	//注意表头的前指针指向的元素是最后一个元素
		while (j++ < rindex) {
			pindex = pindex->prev;
								//双向查找使时间复杂度下降
		}
		return pindex;
	}
}

//获取index节点的值
template <typename T>T DLink<T>::get(int index) {
	return getNode(index)->value;
}


//获取第一个节点值
template <typename T>T DLink<T>::get_first() {
	return phead->next->value;
}

//获取最后一个节点的值
template <typename T>T DLink<T>::get_last() {
	return phead->prev->value;
}

//将节点插入到第index位置之前
template <typename T>int DLink<T>::insert(T data, int index) {
	if (count = 0) return insert_first(data);
	DNode<int>* pindex = getNode(index);
	DNode<int>* pnode = new DNode<int>(data, pindex->prev, pindex);
	//new用来callconstructor构造器
	pindex->prev->next = pnode;
	pindex->prev = pnode;
	count++;
	return 0;
}

//将节点插入到第一个节点处
template <typename T>int DLink<T>::insert_first(T data) {
	DNode<T>* pnode = new DNode<T>(data, phead, phead->next);
	phead->next = pnode;
	phead->next->prev = pnode;
	count++;
	return 0;
}

//将节点插入到最后一个位置
template <typename T>int DLink<T>::insert_last(T data) {
	DNode<T>* pnode = new DNode<T>(data, phead->prev, phead);
	phead->prev->next = pnode;
	phead->prev = pnode;
	count++;
	return 0;
}

//删除index位置的节点
template <typename T>int DLink<T>::del(int index) {
	DNode<T>* pindex = getNode(index);
	pindex->prev->next = pindex->next;
	pindex->next->prev = pindex->prev;
	delete pindex;									//delete能释放指针指向的内存
	count--;
	return 0;

}

//删除第一个元素
template <typename T>int DLink<T>::delete_first() {
	del(1);
	count--;
	return 0;
}

//删除最后一个元素
template <typename T>
int DLink<T>::delete_last() {
	del(count - 1);							//注意这里的count是逻辑意义而不是物理意义
}

//test

int main() {
	DLink<int> link;
	link = DLink<int>::DLink();
	link.insert_first(1);
	link.get_first();

	return 0;
}

















































