#include "../include/complex.h"
#include <math.h>

// FUNCTION DEFINITION

ComplexNbr add_complex(ComplexNbr z1, ComplexNbr z2){
   return (ComplexNbr){z1.re + z2.re, z1.im + z2.im};
}

ComplexNbr sub_complex(ComplexNbr z1, ComplexNbr z2){
   return (ComplexNbr){z1.re - z2.re, z1.im - z2.im};
}

ComplexNbr mul_complex(ComplexNbr z1, ComplexNbr z2){
   return (ComplexNbr){z1.re * z2.re - z1.im * z2.im, z1.re * z2.im + z1.im *z2.re};
}

ComplexNbr div_complex(ComplexNbr z1, ComplexNbr z2){
   double z2Mod = modulus(z2);
   ComplexNbr z2Conj = conjugate(z2);
   ComplexNbr num = mul_complex(z1, z2Conj);
   return (ComplexNbr){num.re/(z2Mod * z2Mod), num.im/(z2Mod * z2Mod)};
}

ComplexNbr conjugate(ComplexNbr z){
   return (ComplexNbr){z.re, -z.im};
}

double modulus(ComplexNbr z){
   return sqrt(z.re * z.re + z.im * z.im);
}
