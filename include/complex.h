#ifndef __COMPLEX__
#define __COMPLEX__

#include "utils.h"

// STRUCT

typedef struct complex_t ComplexNbr;

// PROTOTYPES

/**
 * \brief Creates a new complex number.
 * 
 * \param a The real part.
 * \param b The imaginary part.
 * 
 * \return A pointer to ComplexNbr (a,b). (NULL if error).
 */
ComplexNbr *new_complex(double a, double b);

/**
 * \brief Creates an empty complex number to be used to store results.
 * 
 * \return A pointer to the ComplexNbr 0. (NULL if error).
 */
ComplexNbr *empty_complex(void);

/**
 * \brief Gets the real part of a complex number.
 * 
 * \param z The complex number.
 * 
 * \return The real part of z.
 */
double real(ComplexNbr *z);

/**
 * \brief Gets the imaginary part of a complex number.
 * 
 * \param z The complex number.
 * 
 * \return The imaginary part of z.
 */
double img(ComplexNbr *z);

/**
 * \brief Adds two complex numbers.
 * 
 * \param res The address to write the result.
 * \param z1 The first operand.
 * \param z2 The second operand.
 * 
 * \return An ErrorCode. 
 */
ErrorCode add_complex(ComplexNbr *res, ComplexNbr *z1, ComplexNbr *z2);

/**
 * \brief Subtracts two complex numbers.
 * 
 * \param res The address to write the result.
 * \param z1 The first operand.
 * \param z2 The second operand.
 * 
 * \return An ErrorCode. 
 */
ErrorCode sub_complex(ComplexNbr *res, ComplexNbr *z1, ComplexNbr *z2);

/**
 * \brief Multiplies two complex numbers.
 * 
 * \param res The address to write the result.
 * \param z1 The first operand.
 * \param z2 The second operand.
 * 
 * \return An ErrorCode. 
 */
ErrorCode mul_complex(ComplexNbr *res, ComplexNbr *z1, ComplexNbr *z2);

#endif