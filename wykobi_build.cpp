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

#include "wykobi.hpp"
#include <iostream>

using namespace wykobi;
int main(void) {
  point3d<double> p1(0.0, 0.0, 1.0), p2(1, 0, 1.0), p3(0, 1, 1.0);
  point3d<double> p4(0, 0, -1), p5(0,0,2);

  plane<double, 3> pl = make_plane(p1, p2,p3);

  std::cout << lay_distance(p4, pl) << std::endl;
  std::cout << lay_distance(p5, pl) << std::endl;
  std::cout << lay_distance(p1, pl) << std::endl;

  return 0;
}
