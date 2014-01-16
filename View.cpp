#include "View.h"

View::View()
{
   std::clog << "CONSTR : View" << std::endl;

// 1. SDL INITIALISATION:
   if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
   {
      std::cerr << "Erreur d'initialisation de la SDL ! " << SDL_GetError()
         << " Sortie du programme..." << std::endl;
      exit(-1);
   }
   else
      std::clog << "SDL initialisée !" << std::endl;

// 2. WINDOW CREATION:
   win = nullptr;
   win = SDL_CreateWindow("LandChess", SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
   if (win == nullptr)
   {
      std::cerr << "Erreur dans la création de la fenêtre : "
         << SDL_GetError() << " - Sortie du programme !" << std::endl;
      exit(-1);
   }
   else
      std::clog << "Fenêtre créée !" << std::endl;

// 3. RENDERER CREATION:
   ren = nullptr;
   ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
   if (ren == nullptr)
   {
      std::cerr << "Erreur dans la création du Renderer : "
         << SDL_GetError() << " - Sortie du programme !" << std::endl;
      exit(-1);
   }
   SDL_SetRenderDrawColor(ren, 96, 195, 73, 255);
   SDL_RenderClear(ren);
   SDL_RenderPresent(ren);

// Window test:
   SDL_Delay(2000);

// X. MVC BUILT:
   ctr = new Controller();

   // MVC completion by setting Observer pattern up.
   ctr->addObs(this);
}

View::~View()
{
   delete ctr;

   SDL_DestroyWindow(win);
   SDL_DestroyRenderer(ren);
   SDL_Quit();

   std::clog << "DESTR : View" << std::endl;
}

// Observer method implementation
void
View::update()
{
   std::clog << "View::update invoquée - NON CODEE !!!" << std::endl;
   // TO BE DONE !
}
