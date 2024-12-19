#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

template <typename T>
class BSTree {
private:
int nelem;
BSNode<T>* root;
BSNode<T>* search(BSNode<T>* n, T e) const;
BSNode<T>* insert(BSNode<T>* n, T e);
BSNode<T>* remove(BSNode<T>* n, T e);
T max(BSNode<T>* n) const;
public:
BSTree() : nelem(0), root(nullptr) {}
~BSTree() { delete_cascade(root);}
T search(T e) const;
void insert(T e);
void remove(T e);
int size() const;
T operator[](T e) const {return search(e);}
friend std::ostream& operator<<(std::ostream &out, const BSTree<T> &bst) {
bst.print_inorder(out, bst.root);
return out;
}
void print_inorder(std::ostream &out, BSNode<T>* n) const {
if (n != nullptr) {
print_inorder(out, n->left);
out << n->elem << " ";
print_inorder(out, n->right);
	}
}

void delete_cascade(BSNode<T>* n) {
if (n != nullptr) {
delete_cascade(n->left);
delete_cascade(n->right);
delete n;
	}
}

};

#endif
