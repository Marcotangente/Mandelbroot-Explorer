#ifndef __ADVANCED_COMPLEX__
#define __ADVANCED_COMPLEX__

#include "complex.h"

/**
 * \brief Returns the number of iterations before the Mandelbrot sequence diverges for a given complex number.
 * 
 * \param c The given complex
 * 
 * \return The number of iteration if the seq. diverges. 0 otherwise.
 */
int mandelbrot_iteration(ComplexNbr c);

#endif