#include "../include/complex_plane.h"
#include <stdlib.h>

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
};

ComplexPlane *new_complex_plane(void){
   ComplexPlane *plane = malloc(sizeof(ComplexPlane));

   return plane;
}