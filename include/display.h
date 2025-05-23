#ifndef __DISPLAY__
#define __DISPLAY__

#include "complex_plane.h"
#include "advanced_complex.h"
#include "raylib.h"

/**
 * \brief Renders the Mandelbrot set into a given RenderTexture2D.
 *
 * The rendering covers the full screen size, mapping each pixel to a complex number.
 *
 * \param plane Pointer to the ComplexPlane used for coordinate mapping.
 * \param texture RenderTexture2D where the Mandelbrot set will be drawn.
 * \param maxIter The maximum number of iterations used in the Mandelbrot calculation.
 */
void render_mandelbrot_texture(ComplexPlane *plane, RenderTexture2D texture, int maxIteration);

/**
 * \brief Displays a portion of the RenderTexture2D onto the current window.
 *
 * This function maps the part of the texture that corresponds to the current
 * window position and size and draws it onto the screen.
 *
 * \param texture The texture to be displayed in the current window.
 */
void display_texture_view(RenderTexture2D texture);

#endif
