#ifndef __COMPLEX_PLANE__
#define __COMPLEX_PLANE__

#include "complex.h"

typedef struct complex_plane_t ComplexPlane;

/**
 * \brief Creates a complex plane.
 * 
 * \param width The width of the plane in pixels.
 * \param height The height of the plane in pixels.
 * 
 * \return The ComplexPlane *. (NULL if error).
 */
ComplexPlane *new_complex_plane(int width, int height);

/**
 * \brief Destroys the complex plane and free the memory.
 * 
 * \param plane The plane to free.
 */
void free_complex_plane(ComplexPlane *plane);

/**
 * \brief Updates the complex matrix in the plane
 * 
 * \param plane The complex plane to update.
 * 
 * \return An ErrorCode.
 */
ErrorCode update_matrix(ComplexPlane *plane);

#endif
