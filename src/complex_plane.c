#include "../include/complex_plane.h"
#include <stdlib.h>

#define DEFAULT_SCALE_RE 1.0
#define DEFAULT_SCALE_IM 1.0
#define DEFAULT_ORIGIN_RE 0.0
#define DEFAULT_ORIGIN_IM 0.0

/* IDEAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAS
 * On alloue le plan complexe sur tout l'écran au lieu de la fenetre, ok c'est plus gros mais ça évite de le recalculer entièrement si on déplace la fenêtre et ça c'est cool
 * Pour chopper un complexe il faudra donc non pas les coord sur la fenêtre mais sur l'écran : donc on utilise GetWindowPosition()
 * Aussi apparemment dessiner pixel par pixel c'est pas ouf https://search.brave.com/search?q=raylib+draw+pixel+slow&source=desktop&summary=1&conversation=1bac6319b2d49cb879baa6
 * 
 */



struct complex_plane_t{
   int width;
   int height;
   ComplexNbr *matrix;

   double originRe;
   double originIm;

   double scaleRe;
   double scaleIm;
};

ComplexPlane *new_complex_plane(int width, int height){
   ComplexPlane *plane = malloc(sizeof(ComplexPlane));
   if(!plane)
      return NULL;

   plane->width = width;
   plane->height = height;

   plane->scaleRe = DEFAULT_SCALE_RE;
   plane->scaleIm = DEFAULT_SCALE_IM;
   plane->originRe = DEFAULT_ORIGIN_RE;
   plane->originIm = DEFAULT_ORIGIN_IM;

   plane->matrix = malloc(sizeof(ComplexNbr) * width * height);
   if (!plane->matrix){
      free_complex_plane(plane);
      return NULL;
   }



   return plane;
}

void free_complex_plane(ComplexPlane *plane){
   if(plane){
      free(plane);
   }
}