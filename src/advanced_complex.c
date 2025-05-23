#include "../include/advanced_complex.h"

int mandelbrot_iteration(ComplexNbr c, int maxIteration){
   ComplexNbr z = {0.0, 0.0};
   int iterationCount = 0;
   while(iterationCount < maxIteration){
      if(modulus(z) > 2)
         return iterationCount;
      z = add_complex(mul_complex(z, z), c);
      iterationCount++;
   }
   return maxIteration;
}