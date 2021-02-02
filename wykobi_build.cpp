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
  double x, y;
  std::cout << intersect(segment2d(-1, 0, 1, 0), segment2d(-2, 0, -0.9,0), x, y) << std::endl;
  std::cout << x << ", "<< y << std::endl;

}
