#include "raylib.h"
#include "raymath.h"
#include "../include/complex.h"
#include <stdio.h>
#include "../include/resource_dir.h"   // utility header for SearchAndSetResourceDir

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 800
#define WINDOW_NAME "Mandelbrot Visualizer 🔮"

int main(void){
   // Tell the window to use vsync and work on high DPI displays
   SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
   // Create the window and OpenGL context
   InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
   // loop
   while (!WindowShouldClose())      // run the loop untill the user presses ESCAPE or presses the Close button on the window
   {
      printf("winpos = (%d,%d)\n", (int)GetWindowPosition().x, (int)GetWindowPosition().y);
      // drawing
      BeginDrawing();

      // Setup the back buffer for drawing (clear color and depth buffers)
      ClearBackground(BLACK);

      // draw some text using the default font
      DrawText("Hello Raylib", 200,200,20,WHITE);
      
      // end the frame and get ready for the next one  (display frame, poll input, etc...)
      EndDrawing();
   }

   // cleanup


   // destroy the window and cleanup the OpenGL context
   CloseWindow();
   return 0;
}
