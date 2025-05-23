#include "raylib.h"
#include "raymath.h"
#include "../include/display.h"
#include "../include/complex_plane.h"
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

   int screenWidth = GetMonitorWidth(0);
   int screenHeight = GetMonitorHeight(0);

   ComplexPlane *plane = new_complex_plane(screenWidth, screenHeight);
   if(!plane){
      CloseWindow();
      return 1;
   }

   SetTargetFPS(60);
   SetWindowState(FLAG_WINDOW_RESIZABLE);
   RenderTexture2D fractalTexture = LoadRenderTexture(screenWidth, screenHeight);
   render_mandelbrot_texture(plane, fractalTexture, MAX_ITERATION_DEFAULT);

   while (!WindowShouldClose())      // run the loop untill the user presses ESCAPE or presses the Close button on the window
   {
      // drawing
      BeginDrawing();
      ClearBackground(RAYWHITE);     // Setup the back buffer for drawing (clear color and depth buffers)

      display_texture_view(fractalTexture);

      // end the frame and get ready for the next one  (display frame, poll input, etc...)
      EndDrawing();
   }

   UnloadRenderTexture(fractalTexture);
   // destroy the window and cleanup the OpenGL context
   CloseWindow();
   free_complex_plane(plane);
   return 0;
}
