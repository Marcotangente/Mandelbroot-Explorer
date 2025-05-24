#include "raylib.h"
#include "raymath.h"
#include "../include/display.h"
#include "../include/complex_plane.h"
#include <stdio.h>
#include "../include/resource_dir.h"   // utility header for SearchAndSetResourceDir

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 800
#define WINDOW_NAME "Mandelbrot Visualizer"
#define MOVE_COOLDOWN 0.1

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

   int maxIter = MAX_ITERATION_DEFAULT;
   double lastMoveTime = 0.0;

   SetTargetFPS(30);
   SetWindowState(FLAG_WINDOW_RESIZABLE);
   RenderTexture2D fractalTexture = LoadRenderTexture(screenWidth, screenHeight);
   render_mandelbrot_texture(plane, fractalTexture, maxIter);


   while (!WindowShouldClose())      // run the loop untill the user presses ESCAPE or presses the Close button on the window
   {
      double now = GetTime();
      if(now - lastMoveTime >= MOVE_COOLDOWN){
         bool moved = false;
         if(IsKeyDown(KEY_RIGHT)){
            translate_plane(plane, -20, 0);
            moved = true;
         }
         if(IsKeyDown(KEY_LEFT)){
            translate_plane(plane, 20, 0);
            moved = true;
         }
         if(IsKeyDown(KEY_UP)){
            translate_plane(plane, 0, 20);
            moved = true;
         }
         if(IsKeyDown(KEY_DOWN)){
            translate_plane(plane, 0, -20);
            moved = true;
         }
         if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            Vector2 mousePos = GetMousePosition();
            zoom_plane(plane, 2.0, mousePos.x, mousePos.y);
            moved = true;
         }
         if(IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)){
            Vector2 mousePos = GetMousePosition();
            zoom_plane(plane, 0.5, mousePos.x, mousePos.y);
            moved = true;
         }

         if(moved){
            render_mandelbrot_texture(plane, fractalTexture, maxIter);
            lastMoveTime = now;
         }
      }


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
