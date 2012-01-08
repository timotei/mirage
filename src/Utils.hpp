#ifndef MIRAGE_UTILS_HPP__
#define MIRAGE_UTILS_HPP__

#include "glm.h"
#include <iostream>
#include <boost/foreach.hpp>

inline float toRadians(float degrees){
	return float(degrees / 180 * M_PI);
}

#define foreach BOOST_FOREACH

// A macro to disallow the copy constructor and operator= functions
// This should be used in the private: declarations for a class
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
	TypeName(const TypeName&);               \
	void operator=(const TypeName&)

inline float clampDegree( float val ) {
	while( val >= 360 ) val -= 360;
	while( val <= -360 ) val += 360;

	return val;
}

inline void printMatrix4f( float matrix[] ) {
	for( int i = 0; i < 16; ++ i) {
		std::cout << matrix[i] << "|";
	}

	std::cout << "\n";
}

inline void printVector4f( float vector[] ) {
	for( int i = 0; i < 4; ++ i) {
		std::cout << vector[ i ] << "|";
	}
	std::cout << "\n";
}

inline void printVector3f( float vector[] ) {
	for( int i = 0; i < 3; ++ i) {
		std::cout << vector[ i ] << "|";
	}
	std::cout << "\n";
}
#endif // MIRAGE_UTILS_HPP__
