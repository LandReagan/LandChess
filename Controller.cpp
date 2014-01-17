#include "Controller.h"

Controller::Controller()
{
   std::clog << "CONSTR : Controller" << std::endl;

   //mod = new Model();
}

Controller::~Controller()
{
   std::clog << "DESTR : Controller" << std::endl;

   //delete mod;
}

// Observer pass-through:
void
Controller::addObs(Observer* obs)
{
   std::clog << "Controller::addObs invoquée" << std::endl;
   mod->addObserver(obs);
}
