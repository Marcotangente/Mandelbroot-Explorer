#ifndef __COMPLEX__
#define __COMPLEX__

#include "utils.h"

// STRUCT

typedef struct complex_t{
   double re;
   double im;
}ComplexNbr;

// PROTOTYPES

/**
 * \brief Adds two complex numbers.
 * 
 * \param z1 The first operand.
 * \param z2 The second operand.
 * 
 * \return ComplexNbr z1 + z2.
 */
ComplexNbr add_complex(ComplexNbr z1, ComplexNbr z2);

/**
 * \brief Subtracts two complex numbers.
 * 
 * \param z1 The first operand.
 * \param z2 The second operand.
 * 
 * \return ComplexNbr z1 - z2.
 */
ComplexNbr sub_complex(ComplexNbr z1, ComplexNbr z2);

/**
 * \brief Multiplies two complex numbers.
 * 
 * \param z1 The first operand.
 * \param z2 The second operand.
 * 
 * \return ComplexNbr z1 * z2.
 */
ComplexNbr mul_complex(ComplexNbr z1, ComplexNbr z2);

/**
 * \brief Divides two complex numbers.
 * 
 * \param z1 The first operand.
 * \param z2 The second operand.
 * 
 * \return ComplexNbr z1 / z2.
 */
ComplexNbr div_complex(ComplexNbr z1, ComplexNbr z2);

/**
 * \brief Conjugates a complex number.
 * 
 * \param z The complex to conjugate.
 * 
 * \return ComplexNbr z*.
 */
ComplexNbr conjugate(ComplexNbr z);

/**
 * \brief Calculates the modulus of a complex number.
 * 
 * \param z The complex.
 * 
 * \return The modulus of z.
 */
double modulus(ComplexNbr z);

#endif