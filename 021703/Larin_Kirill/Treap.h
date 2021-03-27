#pragma once

class Treap
{
private:
	bool Rand;
	struct leave
	{
		int key, prior;
		leave *left, *right;
		Treap::leave(int k, int p) { key = k; prior = p; left = right = nullptr; }
		Treap::leave() {}
	} *root;
	
	void viewTree(leave*, int, bool);
	void deleteTree(leave*);
	void split(leave*, int, leave*&, leave*&);
	void merge(leave*&, leave*, leave*);
	void erase(leave*&, int);
	void insert(leave*&, leave*);
	bool findKey(leave*, int);
	bool findPrior(leave*, int);
	Treap build(int*, int);
	void intersection(leave*, leave*);
public:
	Treap();
	void viewTree();
	void deleteTree();
	void split(Treap, int, Treap&, Treap&);
	void merge(Treap&, Treap, Treap);
	void erase(int);
	void insert(int, int);
	void insert(int);
	bool findKey(int);
	bool findPrior(int);
	void build(Treap&, int*, int);
	void intersection(Treap);
	void randseed(int);
};