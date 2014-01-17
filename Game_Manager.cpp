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
