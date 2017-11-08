#ifndef _MY_COMPLEX_H
#define _MY_COMPLEX_H

#include <iostream>
#include <cstdlib>

using namespace std;

template <typename TYPE_Re, typename TYPE_Im> class my_complex {
public:
	my_complex() {
		real = 0;
		imag = 0;
	}

	my_complex(TYPE_Re preal, TYPE_Im pimag) {
		real = preal;
		imag = pimag;
	}

	my_complex(const my_complex &obj) {
		real = obj.real;
		imag = obj.imag;
	}

	void sum(const my_complex &obj2) {
		real += obj2.real;
		imag += obj2.imag;
	}

	void sub(const my_complex &obj2) {
		real -= obj2.real;
		imag -= obj2.imag;
	}

	void mul(const my_complex &obj2) {
		real *= obj2.real;
		imag *= obj2.imag;
	}

	void show() {
		if (!real && !imag) {
			cout << 0;
			return;
		}

		if (real){
			cout << real;
		}

		if (imag) {
			if (imag > 0) {
				cout << "+";
			}
			else {
				cout << "-";
			}

			cout << (imag > 0 ? imag : -imag) << 'j';
		}
	}

	my_complex operator=(const my_complex &obj2) {
		real = obj2.real;
		imag = obj2.imag;
		return *this;
	}

	my_complex operator+(const my_complex &obj2) const {
		my_complex temp;
		temp = *this;
		temp.real += obj2.real;
		temp.imag += obj2.imag;
		return temp;
	}

	my_complex operator-(const my_complex &obj2) const {
		my_complex temp;
		temp = *this;
		temp.real -= obj2.real;
		temp.imag -= obj2.imag;
		return temp;
	}

	my_complex operator*(const my_complex &obj2) const {
		my_complex temp;
		temp.real = real*obj2.real - imag*obj2.imag;
		temp.imag = real*obj2.imag + imag*obj2.real;
		return temp;
	}

	my_complex operator/(const my_complex &obj2) const {
		my_complex temp;

		if(!(pow(obj2.real, 2) + pow(obj2.imag, 2))) {
			cerr << "Error:devide by zero!\n";
			throw 1;
		}

		temp.real = (real * obj2.real + imag * (-obj2.imag)) / pow(obj2.real, 2) + pow(obj2.imag, 2);
		temp.imag = (real * (-obj2.imag) + imag * obj2.real) / pow(obj2.real, 2) + pow(obj2.imag, 2);
		return temp;
	}

	friend ostream &operator<<(ostream &stream, const my_complex &obj) {
		if (!obj.real && !obj.imag) {
			stream << 0;
			return stream;
		}

		if (obj.real){
			stream << obj.real;
		}

		if (obj.imag) {
			if (obj.imag > 0) {
				stream << "+";
			}
			else {
				stream << "-";
			}

			stream << (obj.imag > 0 ? obj.imag : -obj.imag) << 'j';
		}

		return stream;
	}
private:
	TYPE_Re real;
	TYPE_Im imag;
};

template <typename TYPE_Re, typename TYPE_Im> class my_complex <TYPE_Re* , TYPE_Im*>;
template <typename TYPE_Re, typename TYPE_Im> class my_complex <TYPE_Re*, TYPE_Im>;
template <typename TYPE_Re, typename TYPE_Im> class my_complex <TYPE_Re, TYPE_Im*>;
template <typename TYPE_Re, typename TYPE_Im> class my_complex <TYPE_Re&, TYPE_Im&>;
template <typename TYPE_Re, typename TYPE_Im> class my_complex <TYPE_Re&, TYPE_Im>;
template <typename TYPE_Re, typename TYPE_Im> class my_complex <TYPE_Re, TYPE_Im&>;

#endif
