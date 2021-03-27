#include "Treap.h"
#include <time.h>
#include <string>
#include <iostream>

bool sideLine;
std::string s;
void Treap::viewTree(leave *t, int level, bool side)
{
	if (t)
	{
		if (sideLine)
		{
			//std::cout << s << (char)186 << (char)16 << t->key << ";" << t->prior << "\n";
			std::cout << s << "|" << ">" << t->key << ";" << t->prior << "\n";
			s += " ";
			sideLine = false;
		}
		else
			//std::cout << s << (char)16 << t->key << ";" << t->prior << "\n";
			std::cout << s << ">" << t->key << ";" << t->prior << "\n";
		if (!side)
		{
			s.erase(s.length() - 2, 2);
			s += "  ";
		}
		s += " ";
		if (t->left != nullptr)
			s += "|";
		else
			sideLine = true;

		Treap::viewTree(t->right, level + 1, 1);
		Treap::viewTree(t->left, level + 1, 0);
		if (s.length() >= 2)
			s.erase(s.length() - 2, 2);
	}
}
void Treap::deleteTree(leave* t)
{
	if (t)
	{
		if (t->right)
			if (t->right->left == nullptr&&t->right->right == nullptr)
			{
				delete t->right;
				t->right = nullptr;
			}
		if (t->left)
			if (t->left->left == nullptr&&t->left->right == nullptr)
			{
				delete t->left;
				t->left = nullptr;
			}
		deleteTree(t->right);
		deleteTree(t->left);
		delete t;
	}
}
void Treap::split(leave* t, int key, leave* &l, leave* &r)
{
	if (!t)
		l = r = NULL;
	else if (key < t->key)
		split(t->left, key, l, t->left), r = t;
	else
		split(t->right, key, t->right, r), l = t;
}
void Treap::merge(leave* &t, leave* l, leave* r)
{
	if (!l || !r)
		t = l ? l : r;
	else if (l->prior > r->prior)
		Treap::merge(l->right, l->right, r), t = l;
	else
		Treap::merge(r->left, l, r->left), t = r;
}
void Treap::erase(leave* &t, int key)
{
	if (t->key == key)
		Treap::merge(t, t->left, t->right);
	else
		Treap::erase(key < t->key ? t->left : t->right, key);
}
void Treap::insert(leave* &t, leave* it)
{
	if (!t)
		t = it;
	else if (it->prior > t->prior)
		Treap::split(t, it->key, it->left, it->right), t = it;
	else
		Treap::insert(it->key < t->key ? t->left : t->right, it);
}
bool Treap::findKey(leave* t, int x)
{
	if (t)
	{
		if (x < t->key)
			Treap::findKey(t->left, x);
		else if (x > t->key)
			Treap::findKey(t->right, x);
		else if (t->key == x)
			return true;
	}
	else
		return false;
}
bool Treap::findPrior(leave* t, int y)
{
	if (t)
		if (t->prior == y)
			return true;
		else
			return (Treap::findPrior(t->right, y) || Treap::findPrior(t->left, y));
	else
		return false;
}
Treap Treap::build(int *x, int n)
{
	Treap t;
	int p;
	for (int i = 0; i < n; i++)
		if (!t.findKey(x[i]) && !t.findPrior(p = rand()))
			t.insert(x[i], p);
	return t;
}
void Treap::intersection(leave* a, leave* b)
{
	if (a)
	{
		if (Treap::findKey(b, a->key))
			std::cout << a->key << " ";
		Treap::intersection(a->right, b);
		Treap::intersection(a->left, b);
	}
}
Treap::Treap()
{
	root = nullptr;
	Rand = false;
}
void Treap::viewTree()
{
	s.clear();
	sideLine = false;
	Treap::viewTree(root, 0, 1);
}
void Treap::deleteTree()
{
	Treap::deleteTree(root);
	root = nullptr;
}
void Treap::split(Treap t, int key, Treap &l, Treap &r)
{
	Treap::split(t.root, key, l.root, r.root);
}
void Treap::merge(Treap &t, Treap l, Treap r)
{
	Treap::merge(t.root, l.root, r.root);
}
void Treap::erase(int key)
{
	if (findKey(root, key))
		Treap::erase(root, key);
	else
		std::cout << "Key " << key << " not found\n";
}
void Treap::insert(int x, int y)
{
	if (!Treap::findKey(root, x) && !Treap::findPrior(root, y))
	{
		leave* a = new leave(x, y);
		Treap::insert(root, a);
	}
	else
		std::cout << "Element " << x << ";" << y << " already exists\n";
}
void Treap::insert(int x)
{
	if (Rand)
	{
		srand(time(0));
		Rand = false;
	}
	int y = rand();
	if (!Treap::findKey(root, x))
	{
		while (Treap::findPrior(root, y))
			y = rand();
		leave* a = new leave(x, y);
		Treap::insert(root, a);
	}
}
bool Treap::findKey(int x)
{
	return Treap::findKey(root, x);
}
bool Treap::findPrior(int y)
{
	return Treap::findPrior(root, y);
}
void Treap::build(Treap &t, int* x, int n)
{
	if (Rand)
	{
		srand(time(0));
		Rand = false;
	}
	Treap::merge(t, t, build(x, n));
}
void Treap::intersection(Treap b)
{
	Treap::intersection(root, b.root);
	std::cout << '\n';
}
void Treap::randseed(int t)
{
	srand(t);
	Rand = false;
}