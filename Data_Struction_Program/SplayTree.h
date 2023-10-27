#pragma once
#ifndef SPLAYTREE_HXX
#define SPLAYTREE_HXX
#include<iostream>
using namespace std;

template<typename T>class Node {
public:
	int key;
	Node<T>* m_parent;
	Node<T>* m_leftchild;
	Node <T>* m_rightchild;
	Node() {};
	Node(int keyword) {
		key = keyword;
		m_parent = NULL;
		m_leftchild = NULL;
		m_rightchild = NULL;
	}
};


template<typename T>class SPTree {
private:
	Node<T>* root=NULL;
public:
	SPTree() {
		root = NULL;
	}

	//得到某树的根节点
	Node<T>* gethead() {
		return this->root;
	}

	void leftRotation(Node<T>* node) {
		if (node == NULL) { return; }
		else {
			Node<T>* temp = node->m_rightchild;
			node->m_rightchild = temp->m_leftchild;
			if (temp->m_leftchild) {
				temp->m_leftchild->m_parent = node;
			}
			temp->m_parent = node->m_parent;
			if (node == node->m_parent->m_leftchild) {
				node->m_parent->m_leftchild = temp;
			}
			else if (node == node->m_rightchild->m_rightchild) {
				node->m_parent->m_rightchild = temp;
			}
			temp->m_leftchild = node;
			node->m_parent = temp;
		}
	}

	void rightRatation(Node<T>* node) {
		if (node == NULL) { return; }
		else {
			Node<T>* temp = node->m_leftchild;
			node->m_parent = temp;
			temp->m_parent = node->m_parent;
			if (temp->m_rightchild) {
				temp->m_rightchild->m_parent = node;
				node->m_leftchild = temp->m_rightchild;
			}
			if (node == node->m_parent->m_leftchild) {
				node->m_parent->m_leftchild = temp;
			}
			else if(node == node->m_parent->m_rightchild) {
				node->m_parent->m_rightchild = temp;
			}
			temp->m_rightchild = node;
			node->m_parent = temp;
		}
	}

	void splay(Node<T>* node) {
		while (node->m_parent) {
				//zig
			if (!node->m_parent->m_parent) {
				if (node == node->m_parent->m_leftchild) {
					rightRatation(node->m_parent);
				}
				else if (node == node->m_parent->m_rightchild) {
					leftRotation(node->m_parent);
				}
			}
			else {
				//zigzig
				if (node == node->m_parent->m_leftchild && node->m_parent == node->m_parent->m_parent->m_leftchild) {
					rightRatation(node->m_parent->m_parent);
					rightRatation(node->m_parent);
				}
				//zigzag
				else if (node == node->m_parent->m_rightchild && node->m_parent == node->m_parent->m_parent->m_leftchild) {
					leftRotation(node->m_parent);
					rightRatation(node->m_parent);
				}
				//zigzig
				else if (node == node->m_parent->m_rightchild && node->m_parent == node->m_parent->m_parent->m_rightchild) {
					leftRotation(node->m_parent);
					leftRotation(node->m_parent);
				}
				//zigzag
				else if (node == node->m_leftchild && node->m_parent == node->m_parent->m_parent->m_rightchild) {
					rightRatation(node->m_parent);
					leftRotation(node->m_parent);
				}
			}
		}
	
	};
	void insert(int key) {
		Node<T>* newnode = new Node<T>(key);
		Node<T>* y = NULL;							//y是x的parent
		Node<T>* x = this->root;
		while (x != NULL) {
			y = x;
			if (newnode->key < x->key) {
				x = x->m_leftchild;
			}
			else if(newnode->key > x->key) {
				x = x->m_rightchild;
			}
		}
		newnode->m_parent = y;
		if (y == NULL) {
			this->root = newnode;
		}
		else if (newnode->key < y->key) {
			newnode->m_parent->m_leftchild = newnode;
		}
		else {
			newnode->m_parent->m_rightchild = newnode;
		}
		splay(newnode);
	}
};


#endif // !SPLAYTREE_HXX

