#ifndef __COMPLEX_PLANE__
#define __COMPLEX_PLANE__

#include "complex.h"

typedef struct complex_plane_t ComplexPlane;

ComplexPlane *new_complex_plane(void);

void free_complex_plane(ComplexPlane *plane);

#endif
