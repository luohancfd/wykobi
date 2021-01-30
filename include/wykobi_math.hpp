/*
(***********************************************************************)
(*                                                                     *)
(* Wykobi Computational Geometry Library                               *)
(* Release Version 0.0.5                                               *)
(* http://www.wykobi.com                                               *)
(* Copyright (c) 2005-2019 Arash Partow, All Rights Reserved.          *)
(*                                                                     *)
(* The Wykobi computational geometry library and its components are    *)
(* supplied under the terms of the open source MIT License.            *)
(* The contents of the Wykobi computational geometry library and its   *)
(* components may not be copied or disclosed except in accordance with *)
(* the terms of the MIT License.                                       *)
(*                                                                     *)
(* URL: https://opensource.org/licenses/MIT                            *)
(*                                                                     *)
(***********************************************************************)
*/


#ifndef INCLUDE_WYKOBI_MATH
#define INCLUDE_WYKOBI_MATH


#include <cmath>
#include <limits>
#include <algorithm>


namespace wykobi
{
   #define WYKOBI_DOUBLE_PRECISION

   #ifdef WYKOBI_SINGLE_PRECISION
    typedef float Float;
   #endif

   #ifdef WYKOBI_DOUBLE_PRECISION
    typedef double Float;
   #endif

   #ifdef WYKOBI_EXTENDED_PRECISION
    typedef long double Float;
   #endif

   /*************[ Epsilon constants ]*************/
   static const Float Epsilon_Medium    = std::numeric_limits<double>::epsilon() ;
   static const Float Epsilon_Low       = std::numeric_limits<float>::epsilon() ;
   static const Float Epsilon           = std::numeric_limits<Float>::epsilon() ;
   static const Float Infinity          = std::numeric_limits<Float>::infinity();

   /********[ Random resolution constants ]********/
   static const std::size_t RANDOM_RESOLUTION_INT = 1000000000;
   static const double      RANDOM_RESOLUTION_FLT = RANDOM_RESOLUTION_INT * 1.0;

   /********[                             ]********/
   static const Float PI        = Float(std::asin(double(0.0)));
   static const Float PI2       = PI * Float(2);
   static const Float PIDiv180  = PI / Float(180.0);
   static const Float _180DivPI = Float(1.0) / PIDiv180;


   template <typename T> inline T sqr(const T& val);
   template <typename T> inline T sqrt(const T& val);
   template <typename T> inline T abs(const T& value);
   template <typename T> inline T max(const T& value1, const T& value2);
   template <typename T> inline T min(const T& value1, const T& value2);
   template <typename T> inline T max(const T& value1, const T& value2, const T& value3);
   template <typename T> inline T min(const T& value1, const T& value2, const T& value3);
   template <typename T> inline T infinity();

   template <typename T> inline T sin(const T& value);
   template <typename T> inline T cos(const T& value);
   template <typename T> inline T tan(const T& value);
   template <typename T> inline T asin(const T& value);
   template <typename T> inline T acos(const T& value);
   template <typename T> inline T atan(const T& value);
   template <typename T> inline T approx_sin(T angle);
   template <typename T> inline T approx_cos(T angle);
   template <typename T> inline T approx_tan(T angle);

   template <typename T> inline T clamp(const T& value, const T& low, const T& high);

   template <typename T>
   inline T sqr(const T& val)
   {
      return val * val;
   }

   template <typename T>
   inline T sqrt(const T& val)
   {
      return std::sqrt(val);
   }

   template <typename T>
   inline T abs(const T& value)
   {
      return std::abs(value);
   }

   template <typename T>
   inline T max(const T& value1, const T& value2)
   {
      return std::max<T>(value1,value2);
   }

   template <typename T>
   inline T min(const T& value1, const T& value2)
   {
      return std::min<T>(value1,value2);
   }

   template <typename T>
   inline T max(const T& value1, const T& value2, const T& value3)
   {
      return max(value1,max(value2,value3));
   }

   template <typename T>
   inline T min(const T& value1, const T& value2, const T& value3)
   {
      return min(value1,min(value2,value3));
   }

   template <typename T>
   inline T infinity()
   {
      return std::numeric_limits<T>::infinity();
   }

   template <typename T>
   inline T is_inifinity(T x)
   {
      return x == std::numeric_limits<T>::infinity();
   }

   template <typename T>
   inline T sin(const T& value)
   {
      return std::sin(value);
   }

   template <typename T>
   inline T cos(const T& value)
   {
      return std::cos(value);
   }

   template <typename T>
   inline T tan(const T& value)
   {
      return std::tan(value);
   }

   template <typename T>
   inline T asin(const T& value)
   {
      return std::asin(value);
   }

   template <typename T>
   inline T acos(const T& value)
   {
      return std::acos(value);
   }

   template <typename T>
   inline T atan(const T& value)
   {
      return std::atan(value);
   }

   template <typename T>
   inline T approx_sin(T angle)
   {
      T final_sign = T(1.0);

           if ((angle <= T(180.0)) && (angle >     90.0)) { angle = T(180.0) - angle;    final_sign = T( 1.0); }
      else if ((angle <= T(270.0)) && (angle > T(180.0))) { angle = angle    - T(180.0); final_sign = T(-1.0); }
      else if ((angle <= T(360.0)) && (angle > T(270.0))) { angle = T(360.0) - angle;    final_sign = T(-1.0); }

      angle *=  T(PI / 180.0);
      T asqr = angle * angle;
      T result = T(-2.39e-08);
      result *= asqr;
      result += T(2.7526e-06);
      result *= asqr;
      result -= T(1.98409e-04);
      result *= asqr;
      result += T(8.3333315e-03);
      result *= asqr;
      result -= T(1.666666664e-01);
      result *= asqr;
      result += T(1.0);
      result *= angle;

      return result * final_sign;
   }

   template <typename T>
   inline T approx_cos(T angle)
   {
      T final_sign = T(1.0);

           if ((angle <= T(180.0)) && (angle >     90.0)) { angle = T(180.0) - angle;    final_sign = T(-1.0); }
      else if ((angle <= T(270.0)) && (angle > T(180.0))) { angle = angle    - T(180.0); final_sign = T(-1.0); }
      else if ((angle <= T(360.0)) && (angle > T(270.0))) { angle = T(360.0) - angle;    final_sign = T( 1.0); }

      angle *=  T(PI / 180.0);
      T asqr = angle * angle;
      T result = T(-2.605e-07);
      result *= asqr;
      result += T(2.47609e-05);
      result *= asqr;
      result -= T(1.3888397e-03);
      result *= asqr;
      result += T(4.16666418e-02);
      result *= asqr;
      result -= T(4.999999963e-01);
      result *= asqr;
      result += T(1.0);

      return result * final_sign;
   }

   template <typename T>
   inline T approx_tan(T angle)
   {
      T final_sign = T(1.0);

           if ((angle <= T(180.0)) && (angle >     90.0)) { angle = T(180.0) - angle;    final_sign = T(-1.0); }
      else if ((angle <= T(270.0)) && (angle > T(180.0))) { angle = angle    - T(180.0); final_sign = T( 1.0); }
      else if ((angle <= T(360.0)) && (angle > T(270.0))) { angle = T(360.0) - angle;    final_sign = T(-1.0); }

      angle *=  T(PI / 180.0);
      T asqr = angle * angle;
      T result = T(9.5168091e-03);
      result *= asqr;
      result += T(2.900525e-03);
      result *= asqr;
      result += T(2.45650893e-02);
      result *= asqr;
      result += T(5.33740603e-02);
      result *= asqr;
      result += T(1.333923995e-01);
      result *= asqr;
      result += T(3.333314036e-01);
      result *= asqr;
      result += T(1.0);
      result *= angle;

      return result * final_sign;
   }

   template <typename T>
   inline T clamp(const T& value, const T& low_end, const T& high_end)
   {
      if (value < low_end ) return low_end;
      if (value > high_end) return high_end;

      return value;
   }

} // namespace wykobi

#endif
