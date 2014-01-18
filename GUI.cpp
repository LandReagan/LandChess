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

// 4. GRILLE CREATION:
   for (int i = 0; i < 8; ++i)
   {
      for (int j = 0; j < 8; ++j)
      {
         Graph_Struct* gs = new Graph_Struct(i, j);
         grille.push_back(gs);
      }
   }

   SDL_RenderClear(ren);

   SDL_Surface* background_surface = SDL_CreateRGBSurface(0, screen_width, screen_height, 32, 0, 0, 0, 0);
   SDL_FillRect(background_surface, NULL, SDL_MapRGB(background_surface->format, 215, 113, 22));

   for (size_t i = 0; i < grille.size(); ++i)
   {
      SDL_FillRect(background_surface, grille[i]->rect, SDL_MapRGB(background_surface->format, 0, 0, 0));
      SDL_FillRect(background_surface, grille[i]->inner_rect, SDL_MapRGB(background_surface->format, 230, 230, 230));
   }

   SDL_Texture* background_texture = SDL_CreateTextureFromSurface(ren, background_surface);
   SDL_RenderCopy(ren, background_texture, nullptr, nullptr);

   SDL_RenderPresent(ren);

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

   game_manager->event_loop();

   std::clog << "Fin d'exécution !" << std::endl;
}
