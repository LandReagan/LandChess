#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED

#include <iostream>

#include "SDL2/SDL.h"

#include "View.h"

class GUI : public View
{
   public:
      GUI();
      ~GUI();

   private:
   // SDL:
      SDL_Window* win;
      SDL_Renderer* ren;

};

#endif // GUI_H_INCLUDED
