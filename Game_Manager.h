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

   // OBSERVER PASSING THROUGH:
      void addObs(Observer*);
      Snapshot* pass_snapshot() const {return echiquier->get_snapshot();}

   private:
   // Model:
      Echiquier* echiquier;

   // Event local management:
      void click_UP(int x, int y);
      void click_DOWN(int x, int y);
};

#endif // GAME_MANAGER_H_INCLUDED
