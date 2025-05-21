#include "../include/advanced_complex.h"

#define MAX_ITER 200

int mandelbrot_iteration(ComplexNbr c){
   ComplexNbr z = {0.0, 0.0};
   unsigned int iterationCount = 0;
   while(iterationCount < MAX_ITER){
      if(modulus(z) > 2)
         return iterationCount;
      z = add_complex(mul_complex(z, z), c);
      iterationCount++;
   }
   return 0;
}