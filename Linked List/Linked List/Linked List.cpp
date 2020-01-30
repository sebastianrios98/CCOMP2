#include <iostream>
using namespace std;

struct asc {
	bool operator()(int a, int b) {
		return a <= b;
	}
};

struct desc {
	bool operator()(int a, int b) {
		return a >= b;
	}
};

template <class T>
struct node {
	T value;
	node* next;
	node() {}
	node(T v, node<T>* n = nullptr) {
		value = v; next = n;
	}
};

template <class T, class Q>
struct linkedlist {
	Q sort;
	node<T>* head = nullptr;
	bool find(T v, node <T>*& ptr) {
		ptr = nullptr;
		for (node<T>* p = head; p&& sort(p->value, v); ptr = p, p = p->next) {
			if (p->value == v) {
				return true;
			}
		}
		return false;
	}
	void add(T v) {
		node<T>* ptr = nullptr;
		if (!find(v, ptr)) {
			if (!ptr) {
				head = new node<T>(v, head);
			}
			else {
				ptr->next = new node<T>(v, ptr->next);
			}
		}
	}
	void print() {
		for (node<T>* i = head; i; i = i->next) {
			cout << i->value << "->";
		}
		cout << endl;
	}
	void del(T v) {
		node <T>* ptr = nullptr;
	}
};



int main() {
	cout << "Hello, world!" << endl;
}