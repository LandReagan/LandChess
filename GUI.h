#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED

#include <iostream>

#include "SDL2/SDL.h"

#include "View.h"
#include "Game_Manager.h"

class GUI : public View
{
   public:
      GUI();
      virtual ~GUI();

   // EXECUTION METHOD:
      void exec();

   private:
   // Controller:
      Game_Manager* game_manager;

   // SDL:
      SDL_Window* win;
      SDL_Renderer* ren;

};

#endif // GUI_H_INCLUDED
