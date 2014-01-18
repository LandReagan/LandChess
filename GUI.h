#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED

#include <iostream>
#include <vector>

#include "SDL2/SDL.h"

#include "View.h"
#include "Game_Manager.h"
#include "Graph_Struct.h"

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

   // Graphical structure:
      std::vector<Graph_Struct*> grille;
};

#endif // GUI_H_INCLUDED
