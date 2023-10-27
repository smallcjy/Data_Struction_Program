#pragma once
#ifndef AVLTREE_HXX
#define AVLTREE_HXX
#define IMBALANCE 1
#include<iostream>
template<typename T>class AvlNote {
private:
	int key;
	int heigth;
	AvlNote* firstchild;
	AvlNote* rightchild;
public:
	AvlNote() {};
	AvlNote(int keyword, AvlNote* left, AvlNote* rigth, int heigth = 0) {
		this->key = keyword;
		this->firstchild = left;
		this->rightchild = rigth;
		this->heigth = heigth;
	}

	int max(int a, int b) {
		if (a >= b) return a;
		return b;
	}

	int heigth(AvlNote* t) {
		if (t == NULL) {
			return -1;
		}
		else {
			return t->heigth;
		}
	}

	void rightRotation(AvlNote* &k2) {
		AvlNote* k1 = k2->firstchild;
		k2->firstchild = k1->rightchild;
		k1->rightchild = k2;
		k2->heigth = max(heigth(k2->firstchild), heigth(k2->rightchild)) + 1;
		k1->heigth = max(height(k1->firstchild), k2->heigth) + 1;
		k2 = k1;
		return;
	}
	void leftRotation(AvlNote* &k2) {
		AvlNote* k1 = k2->rightchild;
		k2->rightchild = k1->firstchild;
		k1->firstchild = k2;
		k2->heigth = max(heigth(k2->firstchild), heigth(k2->rightchild)) + 1;
		k1->heigth = max(height(k1->rightchild), k2->heigth) + 1;
		k2 = k1;
		return;
	}
	void balance(AvlNote* &t) {
		if (t == NULL) return;
		//L
		if (heigth(t->firstchild) - heigth(t->rightchild) > IMBALANCE) {
			//LL
			if (heigth(t->firstchild) >= height(t->rightchild)) {
				rightRotation(t);
			}
			else {
				//LR
				leftRotation(t->firstchild);
				rightRotation(t);
			}
		}
		else {
			//RR
			if (heigth(t->firstchild) <= height(t->rightchild)) {
				leftRotation(t);
			}
			else {
				//RL
				rightRotation(t->rightchild);
				leftRotation(t);
			}
		}
		t->heigth = max(height(t->firstchild), heigth(t->rightchild) + 1;

	}

	bool find(const int& key, AvlNote* t) {
		if (t == NULL) {
			return false;
		}
		else if (key < t->key) {
			return find(key, t->firstchild);
		}
		else if (key > t->key) {
			return find(key, t->rightchild);
		}
		else {
			return true;		//match
		}
	}

	AvlNote* findmin(AvlNote* t) {
		if (t == NULL) {
			return nullptr;
		}
		if (t->firstchild == NULL) {
			return t;
		}
		else {
			return findmin(t->firstchild);
		}
	}

	void insert(int key, AvlNote* &t) {
		if (t == NULL) {
			t = new AvlNote<T>(key, NULL, NUll, 0);
		}
		else if (key < this->key) {
			insert(key, t->firstchild);
		}
		else if (key > this->key) {
			insert(key, t->rightchild);
		}
		balance(t);
	}

	void remove(int key, AvlNote*& t) {
		if (t == NULL)return;
		if (key < t->key) {
			remove(key, t->firstchild);
		}
		else if (key > t->key) {
			remove(key, t->rightchild);			//now we find the item we want to remove
		}
		else if (t->firstchild != NULL && t->rightchild != NULL) {			//two child
			t->key = findmin(t->rightchild)->KeyWord;
			remove(t->key, t->rightchild);
		}
		else {														//one child or none child
			AvlNote* OldNote = t;
			t = (t->firstchild != NULL) ? t->firstchild : t->rightchild;		//衔接上一层节点中的左右child指针指向下下层
			delete OldNote;				//上一层的孩子已经替换，所以此时可以删除t节点。
		}
	}
};




#endif // !AVLTREE_HXX

