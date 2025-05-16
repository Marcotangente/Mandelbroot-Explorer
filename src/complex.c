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

void free_complex(ComplexNbr *z){
   if(z)
      free(z);
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

ErrorCode div_complex(ComplexNbr *res, ComplexNbr *z1, ComplexNbr *z2){
   if(!(res && z1 && z2))
      return ERR_NULL_PTR;
   ErrorCode errorCode;

   double z2Mod = modulus(z2);
   ComplexNbr *z2Conj = empty_complex();
   if(!z2Conj)
      return ERR_ALLOCATION_FAIL;
   errorCode = conjugate(z2Conj, z2);
   if(errorCode != SUCCESS)
      return errorCode;
   ComplexNbr *num = empty_complex();
   if(!num)
      return ERR_ALLOCATION_FAIL;
   errorCode = mul_complex(num, z1, z2Conj);
   if(errorCode != SUCCESS)
      return errorCode;

   res->a = real(num)/(z2Mod * z2Mod);
   res->b = img(num)/(z2Mod * z2Mod);

   free_complex(z2Conj);
   free_complex(num);

   return SUCCESS;
}

ErrorCode conjugate(ComplexNbr *res, ComplexNbr *z){
   if(!(res && z))
      return ERR_NULL_PTR;
   res->a = real(z);
   res->b = -1 * img(z);
   return SUCCESS;
}

double modulus(ComplexNbr *z){
   if(!z)
      return NAN;
   return sqrt(real(z) * real(z) + img(z) * img(z));
}