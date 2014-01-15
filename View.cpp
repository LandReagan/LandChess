#include "View.h"

View::View()
{
   std::clog << "CONSTR : View" << std::endl;

// 1. SDL INITIALISATION:
   if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
   {
      std::cerr << "Erreur d'initialisation de la SDL ! Sortie du programme..." << std::endl;
      exit(-1);
   }
   else
      std::clog << "SDL initialisée !" << std::endl;

// 2. MVC BUILT:
   ctr = new Controller();

   // MVC completion by setting Observer pattern up.
   ctr->addObs(this);
}

View::~View()
{
   std::clog << "DESTR : View" << std::endl;

   delete ctr;
}

// Observer method implementation
void
View::update()
{
   std::clog << "View::update invoquée - NON CODEE !!!" << std::endl;
   // TO BE DONE !
}
