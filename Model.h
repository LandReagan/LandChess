/*

This class implements Model in the Model-View-Controller pattern
As per definition, it should inherit from Observable class in Observer pattern

*/

#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

#include <iostream>

#include "Observable.h"

class Model : public Observable
{
   public:
   // CONSTRUCTORS & DESTRUCTOR
      Model();
      virtual ~Model();

   // OBSERVABLE:
      void addObserver(Observer*);
      void removeObserver(Observer*);
      void notifyObservers();

   protected:

};

#endif // MODEL_H_INCLUDED
