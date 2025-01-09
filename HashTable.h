#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "../PRA_2324_P1/ListLinked.h" 

template <typename V>
class HashTable: public Dict<V> {

    private:
        int n;
	int max;
	ListLinked<TableEntry<V>>* table;
        
	int h(std::string key ) const {
	    int suma=0;
	    for(int i=0;i<key.length();i++){
	        suma += int(key.at(i));
	    
	    }
	    return suma%max;
	}
    public:
        HashTable(int size){
	    max = size;
	    table = new ListLinked<TableEntry<V>>[max];
	    n = 0;
	   
	}
	~HashTable(){
	
	   delete[] table;
	
	}
	int capacity(){
	    return max;
	}
        friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th){
	    for (int i = 0; i < th.max; i++) {
            out << "Bucket " << i << ": " << th.table[i] << std::endl;
            }
	    return out;
	
	}
        V operator[](std::string key) const {
	    int i = h(key);	
	    
	    for(int j=0;j<table[i].size();j++){
	        if (table[i][j].key == key){
	       
	            return table[i][j].value;
	     }
	    }
	    throw std::runtime_error("key no encontrada");
	
	
	}
        void insert(std::string key, V value) override{
	    int j;	
	    int i = h(key);
	    
	       if  (j = table[i].search(key) != -1){
	       
	           throw std::runtime_error("key ya existente");
	    }
	    table[i].append(TableEntry<V>(key,value));
	    n++;    
	    
	    
	    
	
	}
	V search(std::string key) const override{

	    return  (*this)[key];
	
	}
	V remove(std::string key) override{
	    int i = h(key);	
	    
	    for(int j=0;j<table[i].size();j++){
	        if (table[i][j].key == key){
	       
	            V val = table[i][j].value;
		    table[i].remove(j);
		    return val;
	     }
	    }
	    throw std::runtime_error("key no encontrada");
	
	
	  
	
	
	}
	int entries() const override {
	
	    return n;
	
	
	
	}
           
};

#endif
