#ifndef _VECTOR_MANAGER_H
#define _VECTOR_MANAGER_H

#include "my_complex.h"
#include <vector>


template <typename TYPE_Re, typename TYPE_Im> 
void vect_factory(vector<my_complex<TYPE_Re, TYPE_Im> > &obj, int count) {
	for (int i = 0; i < count; i++) {
		obj.push_back(my_complex<TYPE_Re, TYPE_Im>(((TYPE_Re)rand()) / (30633 + i), ((TYPE_Im)rand()) / (30873 + i)));
	}
}

template <typename TYPE_Re, typename TYPE_Im>
vector<my_complex<TYPE_Re, TYPE_Im> > vect_sum(vector<my_complex<TYPE_Re, TYPE_Im> > &obj1, vector<my_complex<TYPE_Re, TYPE_Im> > &obj2) {
	vector<my_complex<TYPE_Re, TYPE_Im> > temp; 

	if (obj1.size() < obj2.size()) {
		while (obj1.size() != obj2.size()) {
			obj1.push_back(my_complex<TYPE_Re, TYPE_Im>(0, 0));
		}
	}

	if (obj1.size() > obj2.size()) {
		while (obj1.size() != obj2.size()) {
			obj2.push_back(my_complex<TYPE_Re, TYPE_Im>(0, 0));
		}
	}

	for (int i = 0; i < obj1.size() ; i++) {
		temp.push_back(obj1[i] + obj2[i]);
	} 

	return temp;
}

template <typename TYPE_Re, typename TYPE_Im>
void vect_show(const vector<my_complex<TYPE_Re, TYPE_Im> > &obj) {
	if (!obj.size()) {
		cout << "Vector is empty!\n";
	}

	for (int i = 0; i < obj.size(); i++) {
		cout << obj[i] << " ";
	}

	cout << endl;
}

#endif