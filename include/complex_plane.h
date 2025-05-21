#ifndef __COMPLEX_PLANE__
#define __COMPLEX_PLANE__

#include "complex.h"
#include <stdbool.h>

typedef struct complex_plane_t ComplexPlane;

/**
 * \brief Creates a new complex plane with given dimensions.
 * 
 * \param width The width of the plane in pixels.
 * \param height The height of the plane in pixels.
 * 
 * \return A pointer to the newly allocated ComplexPlane, or NULL on failure.
 */
ComplexPlane *new_complex_plane(int width, int height);

/**
 * \brief Frees the memory associated with a complex plane.
 * 
 * \param plane The plane to free.
 */
void free_complex_plane(ComplexPlane *plane);

/**
 * \brief Retrieves the complex number at a given (x, y) coordinate in the plane.
 * 
 * \param plane A pointer to the complex plane.
 * \param x The horizontal coordinate.
 * \param y The vertical coordinate.
 * 
 * \return The ComplexNbr at the given coordinate. If out of bounds or NULL plane, the complex (0,0).
 */
ComplexNbr get_complex_at(ComplexPlane *plane, int x, int y);

/**
 * \brief Checks if the given coordinates are in bounds of the plane.
 * 
 * \param plane A pointer to the complex plane.
 * \param x The horizontal coordinate.
 * \param y The vertical coordinate.
 * 
 * \return true if (x, y) is within the bounds of the plane, false otherwise.
 */
bool is_in_bounds(ComplexPlane *plane, int x, int y);

/**
 * \brief Recomputes the complex number matrix of the plane.
 * 
 * \param plane A pointer to the complex plane to update.
 * 
 * \return An ErrorCode indicating success or the type of failure.
 */
ErrorCode recalculate_complex_matrix(ComplexPlane *plane);

/**
 * \brief Applies a zoom transformation to the complex plane.
 * 
 * \param plane A pointer to the complex plane.
 * \param factor The zoom factor. Must be greater than 0. Values < 1 zoom in, values > 1 zoom out.
 * \param centerX The x coordinate of the zoom center (in pixels).
 * \param centerY The y coordinate of the zoom center (in pixels).
 *
 * \return An ErrorCode indicating success or the type of failure.
 */
ErrorCode zoom_plane(ComplexPlane *plane, double factor, int centerX, int centerY);

/**
 * \brief Applies a translation to the complex plane.
 * 
 * \param plane A pointer to the complex plane.
 * \param offsetX The x-axis shift (in pixels).
 * \param offsetY The y-axis shift (in pixels).
 *
 * \return An ErrorCode indicating success or the type of failure.
 */
ErrorCode translate_plane(ComplexPlane *plane, int offsetX, int offsetY);

/**
 * \brief Sets the origin of the given plane.
 * 
 * \param plane A pointer to the complex plane.
 * \param origin The new origin
 * 
 * \return An ErrorCode indicating success or the type of failure.
 */
ErrorCode set_plane_origin(ComplexPlane *plane, ComplexNbr origin);

/**
 * \brief Set the scale of the given plane.
 * 
 * \param plane A pointer to the complex plane.
 * \param scaleRe The scale for the real axis.
 * \param scaleIm The scale for the imaginary axis.
 * 
 * \return An ErrorCode indicating success or the type of failure.
 */
ErrorCode set_plane_scale(ComplexPlane *plane, double scaleRe, double scaleIm);

#endif
