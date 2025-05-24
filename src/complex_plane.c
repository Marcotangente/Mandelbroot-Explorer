#include "../include/complex_plane.h"
#include <stdlib.h>

#define DEFAULT_SCALE_RE 0.003
#define DEFAULT_SCALE_IM 0.003
#define DEFAULT_ORIGIN_RE -3
#define DEFAULT_ORIGIN_IM 1.5

// STRUCT

struct complex_plane_t{
   int width; //pixels
   int height; //pixels
   ComplexNbr *matrix;

   ComplexNbr origin;
   double scaleRe;
   double scaleIm;
};

// PROTOTYPE

/**
 * \brief Recomputes the complex number matrix of the plane.
 * 
 * \param plane A pointer to the complex plane to update.
 * 
 * \return An ErrorCode indicating success or the type of failure.
 */
static ErrorCode recalculate_complex_matrix(ComplexPlane *plane);

// FUNCTIONS

ComplexPlane *new_complex_plane(int width, int height){
   ComplexPlane *plane = malloc(sizeof(ComplexPlane));
   if(!plane)
      return NULL;

   plane->width = width;
   plane->height = height;

   plane->scaleRe = DEFAULT_SCALE_RE;
   plane->scaleIm = DEFAULT_SCALE_IM;
   plane->origin = (ComplexNbr){DEFAULT_ORIGIN_RE, DEFAULT_ORIGIN_IM};

   plane->matrix = malloc(sizeof(ComplexNbr) * width * height);
   if (!plane->matrix){
      free_complex_plane(plane);
      return NULL;
   }

   if(recalculate_complex_matrix(plane) != SUCCESS){
      free_complex_plane(plane);
      return NULL;
   }

   return plane;
}

void free_complex_plane(ComplexPlane *plane){
   if(plane){
      free(plane->matrix);
      free(plane);
   }
}

ComplexNbr get_complex_at(ComplexPlane *plane, int x, int y){
   if(!plane)
      return (ComplexNbr){0,0};
   if(!is_in_bounds(plane, x, y))
      return (ComplexNbr){0,0};

   return plane->matrix[y * plane->width + x];
}

bool is_in_bounds(ComplexPlane *plane, int x, int y){
   if(x < 0 || x >= plane->width || y < 0 || y >= plane->height)
      return false;
   return true;
}

ErrorCode zoom_plane(ComplexPlane *plane, double factor, int centerX, int centerY){
   if(!plane)
      return ERR_NULL_PTR;
   if(factor <= 0)
      return ERR_INVALID_ARG;
   if(!is_in_bounds(plane, centerX, centerY))
      return ERR_OUT_OF_BOUNDS;

   ComplexNbr centerComplex = get_complex_at(plane, centerX, centerY);

   plane->scaleRe /= factor;
   plane->scaleIm /= factor;

   plane->origin = (ComplexNbr){centerComplex.re - centerX * plane->scaleRe, centerComplex.im + centerY * plane->scaleIm};

   return recalculate_complex_matrix(plane);
}

ErrorCode translate_plane(ComplexPlane *plane, int offsetX, int offsetY){
   if(!plane)
      return ERR_NULL_PTR;

   ComplexNbr offsetComplex = {offsetX * plane->scaleRe, -offsetY * plane->scaleIm};
   plane->origin = add_complex(plane->origin, offsetComplex);

   return recalculate_complex_matrix(plane);
}

ErrorCode set_plane_origin(ComplexPlane *plane, ComplexNbr origin){
   if(!plane)
      return ERR_NULL_PTR;
   plane->origin = origin;
   return recalculate_complex_matrix(plane);
}

ErrorCode set_plane_scale(ComplexPlane *plane, double scaleRe, double scaleIm){
   if(!plane)
      return ERR_NULL_PTR;
   plane->scaleRe = scaleRe;
   plane->scaleIm = scaleIm;
   return recalculate_complex_matrix(plane);
}

// STATIC FUNCTIONS

static ErrorCode recalculate_complex_matrix(ComplexPlane *plane){
   if(!plane || !plane->matrix)
      return ERR_NULL_PTR;

   for(int i = 0; i < plane->width * plane->height; i++){
      int x = i % plane->width;
      int y = i / plane->width;
      double re = plane->origin.re + x * plane->scaleRe;
      double im = plane->origin.im - y * plane->scaleIm;
      plane->matrix[i] = (ComplexNbr){re, im};
   }

   return SUCCESS;
}