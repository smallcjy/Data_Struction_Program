#pragma once
#ifndef BINARYTREE_HXX
#define BINARYTREE_HXX
#include<iostream>
using namespace std;

template<typename T> class BTNote {
public:
	T data;
	int KeyWord;
	BTNote* firstChild;
	BTNote* nextSibling;
public:
	BTNote() {};
	BTNote(int Key,T t) {
		this->data = t;
		this->KeyWord = Key;
		this->firstChild = NULL;
		this->nextSibling = NULL;
		cout << "construct susscee";
	}
	~BTNote() {};
	T element() {
		return this->data;
	}
	BTNote* left() {
		return this->firstChild;
	}
	void setLeft(BTNote* child) {
		this->firstChild = child;
	}
	BTNote* right() {
		return this->nextSibling;
	}
	void setRight(BTNote* child) {
		this->nextSibling = child;
	}

	T visit(const BTNote*& note) {
		if (note == NULL) return;
		return note->data;
	}
	void preorder(BTNote* root) {					//前序遍历
		if (root == NULL) return;
		visit(root);
		preorder(root->left());
		preorder(root->right());
	}
	//x is the item which we want to search, t is the node of the subtree which x is in

	bool find(const int& key, BTNote* t) {
		if (t == NULL) {
			return false;
		}
		else if (key < t->KeyWord) {
			return find(key, t->left());
		}
		else if (key > t->KeyWord) {
			return find(key, t->right());
		}
		else {
			return true;		//match
		}
	}

	BTNote* findmin(BTNote* t) {
		if (t == NULL) {
			return nullptr;
		}
		if (t->left() == NULL) {
			return t;
		}
		else {
			return findmin(t->left());
		}
	}

	BTNote* findmax(BTNote* t) {
		if (t == NULL) {
			return nullptr;
		}
		if (t->right() == NULL) {
			return t;
		}
		else {
			return findmax(t->right());
		}
	}

	void insert(int key, T x, BTNote*& t) {
		if (t == NULL) {
			t = new BTNote<int>(key, x);
		}
		else if (key < t->KeyWord) {
			insert(key, x, t->left());
		}
		else if (key > t->KeyWord) {
			insert(key, x, t->rigth());
		}
		else;				//其他处理方式：开辟一个新的内存空间记录元素重复出现的次数；


	}

	void remove(int key, BTNote*& t) {
		if (t == NULL)return;
		if (key < t->KeyWord) {
			remove(key, t->left());
		}
		else if (key > t->KeyWord) {
			remove(key, t->right());			//now we find the item we want to remove
		}
		else if (t->left() != NULL && t->right() != NULL) {			//two child
			t->KeyWord = findmin(t->right())->KeyWord;
			remove(t->KeyWord, t->right());
		}
		else {														//one child or none child
			BTNote* OldNote = t;
			t = (t->left() != NULL) ? t->left() : t->right();		//衔接上一层节点中的左右child指针指向下下层
			delete OldNote;				//上一层的孩子已经替换，所以此时可以删除t节点。
		}
	}
};





#endif // !BINARYTREE_HXX

