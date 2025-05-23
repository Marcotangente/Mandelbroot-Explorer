#ifndef __ADVANCED_COMPLEX__
#define __ADVANCED_COMPLEX__

#include "complex.h"

/**
 * \brief Returns the number of iterations before the Mandelbrot sequence diverges for a given complex number.
 * 
 * \param c The complex number to test.
 * \param maxIteration The maximum number of iterations to perform before assuming convergence.
 * 
 * \return The number of iterations before divergence, or maxIteration if it does not diverge.
 */
int mandelbrot_iteration(ComplexNbr c, int maxIteration);

#endif
