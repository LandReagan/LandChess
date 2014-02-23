#include "Event_Manager.h"

Event_Manager::Event_Manager()
{
   std::clog << "CONSTR : Event_Manager" << std::endl;
}

void
Event_Manager::event_loop()
{
   std::clog << "Event_Manager::event_loop() invoquée" << std::endl;
   bool running = true;
   SDL_Event event;
   while(running)
   {
      SDL_WaitEvent(&event);
      if (event.type == SDL_QUIT)
         running = false;
      else if (event.type == SDL_MOUSEBUTTONUP)
      {
         int x = event.motion.x;
         int y = event.motion.y;
      }
   }
}

// PRIVATE METHODS:


