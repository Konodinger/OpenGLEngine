#ifndef ___UTILSMATHS___
#define ___UTILSMATHS___

#include "utils.hpp"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159274101257324219
#endif

inline vec3 convertSpherical(float r, float t, float p) { // It is the cartesian coordinates conversion of the spherical coordinates (r, t, p)
  r = abs(r);
  return vec3(r * sin(t) * cos(p),
              r * sin(t) * sin(p),
              r * cos(t));
}

#endif /* ___UTILSMATHS___ */
