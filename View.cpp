#include "View.h"

View::View()
{
   std::clog << "CONSTR : View" << std::endl;

// X. MVC BUILT:
   //ctr = new Controller();

   // MVC completion by setting Observer pattern up.
   //ctr->addObs(this);
}

View::~View()
{
   //delete ctr;

   std::clog << "DESTR : View" << std::endl;
}

// Observer method implementation
void
View::update()
{
   std::clog << "View::update invoquée - NON CODEE !!!" << std::endl;
   // TO BE DONE !
}
