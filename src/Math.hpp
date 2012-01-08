#ifndef MIRAGE_MATH_HPP__
#define MIRAGE_MATH_HPP__

#include "nvManipulators.h"

//////////////////////////////////////////////////////////////////////////////////////////
//																						//
//	Name:  nv::vec4f PlaneEq(nv::vec4f p0, nv::vec4f p1, nv::vec4f p2)					//
//																						//
//	Description: Finds the A, B, C and D coefficients for the equation AX+BY+CZ+D=0		//
//				 of a plane determined by three points p0, p1 and p2					//
//																						//
//	Inputs:	nv::vec4f p0, p1 and p2 -> three arrays containing the X, Y, Z				//
//											  and W coordinates of points that belong	//
//											  to the plane								//
//																						//
//	Returns: nv::vec4f  -> array containing the A, B, C and D coefficients for			//
//								 the equation AX+BY+CZ+D=0 of the plane					//
//																						//
//////////////////////////////////////////////////////////////////////////////////////////
nv::vec4f getPlaneEquation(const nv::vec4f& p0, const nv::vec4f& p1, const nv::vec4f& p2);

//////////////////////////////////////////////////////////////////////////////////////////////////////
//																									//
//	Name: nv::matrix4f ComputeShadowMatrix(nv::vec4f plane, nv::vec4f lightPos)						//
//																									//
//	Description: Computes the matrix used to project the shadow on a plane							//
//																									//
//	Input: nv::vec4f plane -> array containing the A, B, C and D coefficients for the equation		//
//							   of the plane on which the shadow will be cast						//
//		   nv::vec4f lightPos -> array containing the X, Y, Z and W coordinates of the light		//
//								  source															//
//																									//
//	Returns: nv::matrix4f shadowMat -> array containing the column-major matrix used to project		//
//									  the shadow on the given plane									//
//																									//
//////////////////////////////////////////////////////////////////////////////////////////////////////
nv::matrix4f getShadowMatrix(nv::vec4f plane, nv::vec4f lightPos);

#endif // MIRAGE_MATH_HPP__
