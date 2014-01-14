#include "View.h"

View::View()
{
   std::clog << "CONSTR : View" << std::endl;

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
