#include "../include/complex.h"
#include <stdlib.h>
#include <math.h>

// STRUCT

struct complex_t{
   double a;
   double b;
};

// FUNCTION DEFINITION

ComplexNbr *new_complex(double a, double b){
   ComplexNbr *c = malloc(sizeof(ComplexNbr));
   if(!c)
      return NULL;
   c->a = a;
   c->b = b;
   return c;
}

ComplexNbr *empty_complex(void){
   return new_complex(0,0);
}

double real(ComplexNbr *z){
   if(!z)
      return NAN;
   return z->a;
}

double img(ComplexNbr *z){
   if(!z)
      return NAN;
   return z->b;
}

ErrorCode add_complex(ComplexNbr *res, ComplexNbr *z1, ComplexNbr *z2){
   if(!(res && z1 && z2))
      return ERR_NULL_PTR;
   res->a = real(z1) + real(z2);
   res->b = img(z1) + img(z2);
   return SUCCESS;
}

ErrorCode sub_complex(ComplexNbr *res, ComplexNbr *z1, ComplexNbr *z2){
   if(!(res && z1 && z2))
      return ERR_NULL_PTR;
   res->a = real(z1) - real(z2);
   res->b = img(z1) - img(z2);
   return SUCCESS;
}

ErrorCode mul_complex(ComplexNbr *res, ComplexNbr *z1, ComplexNbr *z2){
   if(!(res && z1 && z2))
      return ERR_NULL_PTR;
   res->a = real(z1) * real(z2) - img(z1) * img(z2);
   res->b = real(z1) * img(z2) + img(z1) * real(z2);
   return SUCCESS;
}