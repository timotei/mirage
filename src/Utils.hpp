/*
   Copyright (C) 2011-2012 by Timotei Dolean <timotei21@gmail.com>

   Part of the Mirage Project https://github.com/timotei/mirage

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY.

   See the COPYING file for more details.
*/
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
