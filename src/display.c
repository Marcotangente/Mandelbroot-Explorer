#include "../include/display.h"

void draw_mandelbrot(ComplexPlane *plane){
   if(!plane)
      return;

   int windowHeight = GetScreenHeight();
   int windowWidth = GetScreenWidth();
   Vector2 windowPosition = GetWindowPosition();
   for(int windowY = 0; windowY < windowHeight; windowY++){
      int screenY = windowY + windowPosition.y;
      for(int windowX = 0 ; windowX < windowWidth; windowX++){
         int screenX = windowX + windowPosition.x;
         ComplexNbr c = get_complex_at(plane, screenX, screenY);
         if(mandelbrot_iteration(c))
            DrawPixel(windowX, windowY, WHITE);
         else
            DrawPixel(windowX, windowY, BLACK);
      }
   }
}