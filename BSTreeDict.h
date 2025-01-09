#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"
using namespace std;

template <typename V>
class BSTreeDict : public Dict<V> {
private:
	BSTree<TableEntry<V>>* tree;
	int entryCount;
	
public:
	BSTreeDict() {
	    tree = new BSTree<TableEntry<V>>(); // Crear un ABB vacío
	    entryCount = 0;
	}
	~BSTreeDict() {
	    delete tree; // Liberar la memoria del árbol
	}
	int entries() const override {
	    return entryCount;
	}
	void insert(string key, V value) override {
	    tree->insert(TableEntry(key,value));
	    entryCount++;	
	}
	V remove(string key) override {
	    try{	
		V e;
		auto entry = tree->search(TableEntry(key,e));
		auto value = entry.value; //Obtener valor
		tree->remove(TableEntry(key,e)); // Eliminar el elemento del árbol
		entryCount--;
		return value;
	}
	    catch (runtime_error &e){
		throw runtime_error("Elemento no encontrado");
	}
	}
	V search(string key) const override {
	    V e;
	    auto entry = tree->search(TableEntry(key,e));
            return entry.value;
	}
	V operator[](string key) const {
            return search(key); 
	}
	friend ostream& operator<<(ostream &out, const BSTreeDict<V> &dict) {
	    out << *dict.tree; // Usamos la sobrecarga de << de BSTree para imprimir el árbol
	return out;
	}
};
#endif
