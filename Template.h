#include <string>
using namespace std;

#ifndef TEMPLATE_H
#define TEMPLATE_H
template < class T > 

T StudentAveragePoint(T studentmath_mark,T studentphysics_mark,T studentprogramming_mark){
	
	T studentAveragePoint = (studentmath_mark+studentphysics_mark+studentprogramming_mark)/3;
	return studentAveragePoint;
}


#endif
