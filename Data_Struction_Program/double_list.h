#include<iostream>
#ifndef DOUBLE_LIST_HXX
#define DOUBLE_LIST_HXX
using namespace std;

// 类模板：参数化类中成员的数据类型，使得在使用中可以任意化数据结构的类型
template <typename T>class DNode {
public:
	T value; //节点储存的数据
	DNode *prev;	//前指针
	DNode *next;	//后指针
public:
	DNode() {};//默认构造节点
	DNode(T v, DNode* prev, DNode* next) {
		this->value = v;
		this->prev = prev;
		this->next = next;
	}							//有参构造节点
};

template <typename T>class DLink {
private:
	int count;			//记录列表长度
	DNode<T>* phead;	//头节点
public:
	DLink() {
		//创建表头，第一个头节点，不储存数据
		phead = new DNode<T>();
		phead->prev = phead->next = phead;	//前指针和后指针都指在第一个节点
		count = 0;
	};
	~DLink() {
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
	};

	int size() { return count; };			//获取大小
	bool is_empty() { return count == 0; };		//判断是否为空列表

	T get(int index) {
		return getNode(index)->value;
	};
	T get_first() {
		return getNode(0)->value;
	};
	T get_last() { 
		return getNode(count - 1)->value;
	};

	int insert(T t, int index) {
		if (count == 0) {
			return insert_first(t);
		}
		DNode<int>* pindex = getNode(index);
		DNode<int>* pnode = new DNode<int>(t, pindex->prev, pindex);
		//new用来callconstructor构造器
		pindex->prev->next = pnode;
		pindex->prev = pnode;
		count++;
		return 0;
	};
	int insert_first(T t) {
		DNode<T>* pnode = new DNode<T>(t, phead, phead->next);
		phead->next->prev = pnode;
		phead->next = pnode;
		count++;
		return 0;
	};
	int insert_last(T t) {
		DNode<T>* pnode = new DNode<T>(t, phead->prev, phead);
		phead->prev->next = pnode;
		phead->prev = pnode;
		count++;
		return 0;
	};

	
	int del(int index) {
		DNode<T>* pindex = getNode(index);
		pindex->prev->next = pindex->next;
		pindex->next->prev = pindex->prev;
		delete pindex;									//delete能释放指针指向的内存
		count--;
		return 0;
	};	//remove
	int delete_first() {
		del(0);
		count--;
		return 0;
	};
	int delete_last() {
		del(count - 1);
	};
private:
	DNode<T>* getNode(int index) {
		//判断输入参数有效性，提高程序的健壮性
		if (index<0 || index>=count) {
			cout << "get node failed1" << endl;
			return NULL;
		}

		//正向查找
		if (index <= count / 2) {
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
	};
};






#endif // !DOUBLE_LIST_HXX



