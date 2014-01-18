#include "Game_Manager.h"

Game_Manager::Game_Manager()
{
   std::clog << "CONSTR : Game_Manager" << std::endl;

   echiquier = new Echiquier();
}

Game_Manager::~Game_Manager()
{
   std::clog << "DESTR : Game_Manager" << std::endl;

   delete echiquier;
}

// OBSERVER PASSING THROUGH:
void
Game_Manager::addObs(Observer* obs)
{
   std::clog << "Game_Manager::addObs invoquée" << std::endl;
   echiquier->addObserver(obs);
}

// EVENT LOOP:
void
Game_Manager::event_loop()
{
   std::clog << "Game_Manager::event_loop() lancée !" << std::endl;
   SDL_Event event;
   bool running = true;
   while(running)
   {
      SDL_WaitEvent(&event);
      if (event.type == SDL_QUIT)
         running = false;
   }

}
