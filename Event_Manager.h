#ifndef EVENT_MANAGER_H_INCLUDED
#define EVENT_MANAGER_H_INCLUDED

#include <iostream>

#include "SDL2/SDL.h"

class Event_Manager
{
   public:
      Event_Manager();
      //virtual ~Event_Manager();

   protected:
      // Event loop:
      void event_loop();

   private:


   // Event processing:
      void mouse_DOWN(int x, int y);
      void mouse_UP(int x, int y);
};

#endif // EVENT_MANAGER_H_INCLUDED
