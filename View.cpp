#include "View.h"

View::View()
{
   std::clog << "CONSTR : View" << std::endl;

   ctr = new Controller();
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
   // TO BE DONE !
}
