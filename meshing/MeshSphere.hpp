#ifndef ___MESHSPHERE___
#define ___MESHSPHERE___

#include "Mesh.hpp"

void convertSpherical(float r, float t, float p, std::vector<float> & v) { // v is the cartesian coordinates conversion of the spherical coordinates (r, t, p)
  r = abs(r);
  v.push_back(r * sin(t) * cos(p));
  v.push_back(r * sin(t) * sin(p));
  v.push_back(r * cos(t));
}



#endif /* ___MESHSPHERE___ */
