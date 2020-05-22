/* Name: Rogers Xiang
 * Implementation of Rational number type
 */

#include <stdlib.h>  // for abs
#include "Rational.h"

// helper function
int greatestCommonDivisor(int a, int b);

namespace cse374 {

Rational::Rational() {
  num_ = 0;
  denom_ = 1;
}

Rational::Rational(int n) {
  num_ = n;
  denom_ = 1;
}

// multiplies top and bottom by -1 if denom is negative
// gcd = 1 if both n and d are 0 (to avoid dividing by 0)
Rational::Rational(int n, int d) {
  int gcd = greatestCommonDivisor(abs(n), abs(d));
  if (d < 0) {
    num_ = -n / gcd;
    denom_ = -d / gcd;
  } else {
    num_ = n / gcd;
    denom_ = d / gcd;
  }
}

int Rational::n() const {
  return num_;
}

int Rational::d() const {
  return denom_;
}

Rational Rational::plus(Rational other) const {
  int top = n() * other.d() + other.n() * d();
  int bottom = d() * other.d();
  return Rational(top, bottom);
}

Rational Rational::minus(Rational other) const {
  int top = n() * other.d() - other.n() * d();
  int bottom = d() * other.d();
  return Rational(top, bottom);
}

Rational Rational::times(Rational other) const {
  int top = n() * other.n();
  int bottom = d() * other.d();
  return Rational(top, bottom);
}

Rational Rational::div(Rational other) const {
  int top = n() * other.d();
  int bottom = d() * other.n();
  return Rational(top, bottom);
}

}  // namespace cse374

// uses the Euclidean algorithm
// assumes positive inputs
// returns 1 (instead of 0) if both are 0
// since result will be used for division
int greatestCommonDivisor(int a, int b) {
  if (!b) {
    return (a ? a : 1);
  }
  return greatestCommonDivisor(b, a % b);
}
