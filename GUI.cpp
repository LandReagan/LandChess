#include "GUI.h"

GUI::GUI()
{
   std::clog << "CONSTR : GUI" << std::endl;

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

   game_manager = new Game_Manager();

   game_manager->addObs(this);
}

GUI::~GUI()
{
   std::clog << "DESTR : GUI" << std::endl;

   delete game_manager;

   SDL_DestroyWindow(win);
   SDL_DestroyRenderer(ren);
   SDL_Quit();
}

void
GUI::exec()
{
   std::clog << "Exécution !" << std::endl;



   std::clog << "Fin d'exécution !" << std::endl;
}