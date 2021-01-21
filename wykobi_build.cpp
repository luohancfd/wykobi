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

using namespace wykobi;
int main(void) {
  point3d<double> p1(0.0, 0.0, 1.0), p2(1, 0, 1.0), p3(0, 1, 1.0);
  point3d<double> p4(0, 0, -1), p5(0,0,2);

  plane<double, 3> pl = make_plane(p1, p2,p3);

  std::cout << lay_distance(p4, pl) << std::endl;
  std::cout << lay_distance(p5, pl) << std::endl;
  std::cout << lay_distance(p1, pl) << std::endl;

  ray<double, 3> r1(0.0,0.0, 0,1,1,2);
  std::cout << "Origin " << r1.origin << std::endl;
  std::cout << "Direction " << r1.direction << std::endl;

  point3d<double> po(0,0,0);
  vector3d<double> pdir(1,1,2);
  ray<double, 3> r2(po, pdir);
  std::cout << "Origin " << r2.origin << std::endl;
  std::cout << "Direction " << r2.direction << std::endl;

  Eigen::Vector3d epo(0,0,0);
  Eigen::Vector3d epdir(1,1,2);
  ray<double, 3> r3(epo, epdir);
  std::cout << "Origin " << r3.origin << std::endl;
  std::cout << "Direction " << r3.direction << std::endl;


  return 0;
}
