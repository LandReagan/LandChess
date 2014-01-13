/*

This class implements Controller in the Model-View-Controller pattern

*/

#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include <iostream>

#include "Model.h"

class Controller
{
   public:
      Controller();
      ~Controller();

   protected:
      Model* mod;

};

#endif // CONTROLLER_H_INCLUDED
