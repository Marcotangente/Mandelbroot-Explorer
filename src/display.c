#include "../include/display.h"
#include <stdlib.h>

// PROTOTYPES

/**
 * \brief Maps the number of Mandelbrot iterations to a specific color.
 * 
 * This function is used to assign a color to each pixel based on how many iterations 
 * it took for the corresponding complex number to diverge (or not). Points that did not 
 * diverge within the given max iteration count can be mapped to a distinct color (e.g., black).
 * 
 * \param iter The number of iterations computed for the point.
 * \param maxIter The maximum number of iterations used in the Mandelbrot calculation.
 * 
 * \return A Color representing the "depth" of the point in the Mandelbrot set.
 */
static Color iteration_to_color(int iter, int maxIter);

// FUNCTIONS

void render_mandelbrot_texture(ComplexPlane *plane, RenderTexture2D texture, int maxIteration){
   int screenWidth = GetMonitorWidth(0);
   int screenHeight = GetMonitorHeight(0);

   BeginTextureMode(texture);
   ClearBackground(RAYWHITE);

   for(int y = 0; y < screenHeight; y++){
      for (int x = 0; x < screenWidth; x++){
         ComplexNbr c = get_complex_at(plane, x, y);
         DrawPixel(x, y, iteration_to_color(mandelbrot_iteration(c, maxIteration), maxIteration));
      }
   }
   EndTextureMode();
}

void display_texture_view(RenderTexture2D texture){
   int windowHeight = GetScreenHeight();
   int windowWidth = GetScreenWidth();
   Vector2 windowPosition = GetWindowPosition();

   Rectangle sourceRectangle = {
      .x = windowPosition.x,
      .y = windowPosition.y,
      .width = windowWidth,
      .height = windowHeight
   };

   Rectangle targetRectangle = {
      .x = 0,
      .y = 0,
      .width = windowWidth,
      .height = windowHeight
   };

   DrawTexturePro(texture.texture, sourceRectangle, targetRectangle, (Vector2){0, 0}, 0.0f, WHITE);
}

// STATIC FUNCTIONS

static Color iteration_to_color(int iter, int maxIteration){
   if(!iter)
      return BLACK;

   float t = (float)iter / maxIteration;
   return (Color){
      .r = (unsigned char)(9 * (1 - t) * t * t * t * 255),
      .g = (unsigned char)(15 * (1 - t) * (1 - t) * t * t * 255),
      .b = (unsigned char)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255),
      .a = 255
   };
}