#include "my_complex.h"
#include "vector_manager.h"

#define VECTOR_SIZE 5

int main(int argc, char *argv[]) {
	vector<my_complex<double, double> > vec1;
	vector<my_complex<double, double> > vec2;
	vect_factory(vec1, VECTOR_SIZE);
	vect_factory(vec2, VECTOR_SIZE);
	vector<my_complex<double, double> > vec3 = vect_sum(vec1, vec2);
	vect_show(vec1);
	vect_show(vec2);
	vect_show(vec3);

	cout << endl;

	vector<my_complex<int, int> > vec4;
	vector<my_complex<int, int> > vec5;
	vect_factory(vec4, VECTOR_SIZE);
	vect_factory(vec5, VECTOR_SIZE);
	vector<my_complex<int, int> > vec6 = vect_sum(vec4, vec5);
	vect_show(vec4);
	vect_show(vec5);
	vect_show(vec6);

	cout << endl;

	vector<my_complex<int, double> > vec7;
	vector<my_complex<int, double> > vec8;
	vect_factory(vec7, VECTOR_SIZE);
	vect_factory(vec8, VECTOR_SIZE);
	vector<my_complex<int, double> > vec9 = vect_sum(vec7, vec8);
	vect_show(vec7);
	vect_show(vec8);
	vect_show(vec9);

	return 0;
}

