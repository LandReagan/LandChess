/*

This class implements View in the Model-View-Controller pattern
As per definition, it should inherit from Observer class in Observer pattern

*/

#ifndef VIEW_H_INCLUDED
#define VIEW_H_INCLUDED

#include <iostream>

#include "Observer.h"
#include "Controller.h"

class View : public Observer
{
   public:
   // CONSTRUCTORS & DESTRUCTOR:
      View();
      virtual ~View();

   // OBSERVER:
      void update();

   protected:
      Controller* ctr;

};

#endif // VIEW_H_INCLUDED
