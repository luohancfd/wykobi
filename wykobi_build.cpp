/*
(***********************************************************************)
(*                                                                     *)
(* Wykobi Computational Geometry Library                               *)
(* Release Version 0.0.5                                               *)
(* http://www.wykobi.com                                               *)
(* Copyright (c) 2005-2019 Arash Partow, All Rights Reserved.          *)
(*                                                                     *)
(* The Wykobi computational geometry library and its components are    *)
(* supplied under the terms of the General Wykobi License agreement.   *)
(* The contents of the Wykobi computational geometry library and its   *)
(* components may not be copied or disclosed except in accordance with *)
(* the terms of that agreement.                                        *)
(*                                                                     *)
(* URL: https://opensource.org/licenses/MIT                            *)
(*                                                                     *)
(***********************************************************************)
*/

// #include "Eigen/src/Core/Matrix.h"
#include "wykobi.hpp"
#include <iostream>
#include "Eigen/Core"
#include <iomanip>
using namespace wykobi;
int main(void) {

  point2d<double> p2;
  point3d<double> p3;

  std::cout << "Test: inline int intersection_point(const ray<T,2>& ray, const segment<T,2>& segment, point2d<T>& point, bool robust)" <<std::endl;
  std::cout << intersection_point(ray2d(0,0,0,-1), segment2d(-2,0,2,0), p2) << std::endl;
  std::cout << p2 << std::endl;
  std::cout << intersection_point(ray2d(0,0.1,2, -0.1), segment2d(-2,0,2,0), p2) << std::endl;
  std::cout << p2 << std::endl;
  std::cout << intersection_point(ray2d(0,-1, 0,1), segment2d(-2,0,2,0), p2) << std::endl;
  std::cout << p2 << std::endl;
  std::cout << intersection_point(ray2d(2,0, 0,1), segment2d(-2,0,2,0), p2) << std::endl;
  std::cout << p2 << std::endl;
  std::cout << intersection_point(ray2d(2,0, 1,0), segment2d(-2,0,2,0), p2) << std::endl;
  std::cout << p2 << std::endl;
  std::cout << intersection_point(ray2d(2,0, -1,0), segment2d(-2,0,2,0), p2) << std::endl;
  std::cout << p2 << std::endl;
  std::cout << intersection_point(ray2d(-2,0, -1,0), segment2d(-2,0,2,0), p2) << std::endl;
  std::cout << p2 << std::endl;
  std::cout << intersection_point(ray2d(0,0, -1,0), segment2d(-2,0,2,0), p2) << std::endl;
  std::cout << p2 << std::endl;
  std::cout << intersection_point(ray2d(-3,0, -1,0), segment2d(-2,0,2,0), p2) << std::endl;
  std::cout << p2 << std::endl;

  std::cout << "Test: inline int intersection_point(const ray<T,3>& ray, const triangle<T,3>& triangle, point3d<T>& point, bool robust)" <<std::endl;
  triangle3d tr(-1,-1,0, 1,-1,0, 0,2,0);
  std::cout << intersection_point(ray3d(0,0,-1,0,0,1), tr, p3) <<std::endl;
  std::cout << p3 <<std::endl;
  std::cout << intersection_point(ray3d(0,0, 0,0,0,1), tr, p3) <<std::endl;
  std::cout << p3 <<std::endl;
  std::cout << intersection_point(ray3d(0,0, 1,0,0,-1), tr, p3) <<std::endl;
  std::cout << p3 <<std::endl;
  std::cout << intersection_point(ray3d(0,0, 1,-1,-1,-1), tr, p3) <<std::endl;
  std::cout << p3 <<std::endl;
  std::cout << intersection_point(ray3d(0,0, -0.1,-1,-1,-2), tr, p3) <<std::endl;
  std::cout << p3 <<std::endl;

}
