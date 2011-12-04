#ifndef MIRAGE_UTILS_HPP__
#define MIRAGE_UTILS_HPP__

#include "glm.h"

inline float toRadians(float degrees){
	return float(degrees / 180 * M_PI);
}

// A macro to disallow the copy constructor and operator= functions
// This should be used in the private: declarations for a class
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
	TypeName(const TypeName&);               \
	void operator=(const TypeName&)

#endif // MIRAGE_UTILS_HPP__
