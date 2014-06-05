#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED

#include <iostream>
#include <vector>

#include "Event_Manager.h"
#include "SDL2/SDL.h"
#include "View.h"
#include "Game_Manager.h"
#include "Graph_Struct.h"
#include "default_display_constants.h"
#include "Snapshot.h"

class GUI : public View, public Event_Manager
{
   public:
      GUI();
      virtual ~GUI();

    // Observer overload:
    void update();

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
