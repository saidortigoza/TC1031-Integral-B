//
//  File: hash.h
//  Date: 28/11/2021
//  Author: Said Ortigoza
//  Description: Implementación de la clase Hash
//
//  Copyrigth (c) 2021 by Tecnologico de Monterrey.
//  All Rights Reserved. May be reproduced for any non-commercial
//  purpose
//

#ifndef HASH_H_
#define HASH_H_

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <class Key, class Value>
class Hash {
private:
	unsigned int (*func) (const Key);
	unsigned int size;
	unsigned int count;

	Key *keys;
	Key initialValue;
	Value *values;

	long indexOf(const Key) const;

public:
	Hash(unsigned int, Key, unsigned int (*f) (const Key));
	~Hash();
  
	bool put(Key, Value);
  Value get(const Key);

  bool full() const;
	bool contains(const Key) const;
	string toString() const;
};

template <class Key, class Value>
Hash<Key, Value>::Hash(unsigned int sze, Key init, unsigned int (*f) (const Key)){
	size = sze;
	keys = new Key[size];
	if (keys == 0) {
		cout<<"Sin espacio en memoria."<<endl;
	}
	initialValue = init;
	for (unsigned int i = 0; i < size; i++) {
		keys[i] = init;
	}
	values = new Value[size];
	if (values == 0) {
		cout<<"Sin espacio en memoria."<<endl;
	}
	for (int i = 0; i  < sze; i++){
        values[i] = 0;
    }
	func = f;
	count = 0;
}

template <class Key, class Value>
Hash<Key, Value>::~Hash() {
	delete [] keys;
	keys = 0;
	delete [] values;
	values = 0;
	size = 0;
	func = 0;
	count = 0;
}

template <class Key, class Value>
long Hash<Key, Value>::indexOf(const Key k) const {
	unsigned int i, start;
	start = i = func(k) % size;
	for(int j = 0; j<size; j++){
		if(keys[i] == k){
			return i;
		}
		i = (start + j * j) % size;
	}
	return -1;
}

template <class Key, class Value>
bool Hash<Key, Value>::put(Key k, Value v) {
	unsigned i, start;
	long pos;
	pos = indexOf(k);
	if(pos != -1){
		values[pos] = v;
		return true;
	}
	start = i = func(k) % size;
	for(int j = 0; j<size; j++){
		if (keys[i] == initialValue){
			keys[i] = k;
			values[i] = v;
			return true;
		}
		i = (start + j * j) % size;
	}
	return false;
}

template <class Key, class Value>
Value Hash<Key, Value>::get(const Key k) {
	unsigned int i, start;
	long pos;
	pos = indexOf(k);
	if (pos != -1) {
		return values[pos];
	}
	else{
    cout<<"La llave ingresada es incorrecta."<<endl;
  }
}

template <class Key, class Value>
bool Hash<Key, Value>::full() const {
	return (count > size);
}

template <class Key, class Value>
bool Hash<Key, Value>::contains(const Key k) const {
	long pos;
	pos = indexOf(k);
	return (pos != -1);
}

template <class Key, class Value>
string Hash<Key, Value>::toString() const {
	stringstream aux;
	for (int i = 0; i < size; i++){
			if (keys[i] != initialValue){
				aux << "(" << i << " ";
			  aux << keys[i] << " : " << values[i] << ") ";
			}
	}
	return aux.str();
}

#endif