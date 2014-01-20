#ifndef GAME_MANAGER_H_INCLUDED
#define GAME_MANAGER_H_INCLUDED

#include "SDL2/SDL.h"

#include "Controller.h"
#include "Echiquier.h"

class Game_Manager : public Controller
{
   public:
      Game_Manager();
      virtual ~Game_Manager();

   // EVENT LOOP:
      void event_loop();

   // OBSERVER PASSING THROUGH:
      void addObs(Observer*);

   private:
   // Model:
      Echiquier* echiquier;

   // SDL event:
      SDL_Event* event;

   // Event local management:
      void click_on(int x, int y);
};

#endif // GAME_MANAGER_H_INCLUDED
