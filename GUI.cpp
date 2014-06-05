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
      SDL_WINDOWPOS_CENTERED, screen_width, screen_height, SDL_WINDOW_SHOWN);
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

   game_manager = new Game_Manager();

   game_manager->addObs(this);
}

GUI::~GUI()
{
   std::clog << "DESTR : GUI" << std::endl;

   delete game_manager;

   for (size_t i = 0; i < grille.size(); ++i)
      delete grille[i];

   SDL_DestroyWindow(win);
   SDL_DestroyRenderer(ren);
   SDL_Quit();
}

void
GUI::exec()
{
   std::clog << "Exécution !" << std::endl;

   event_loop(); // method inherited from Event_Manager

   std::clog << "Fin d'exécution !" << std::endl;
}

//
void
GUI::update()
{
        std::clog << "GUI::update" << std::endl;
      // BACKGROUND SURFACE:
    SDL_Surface* background_surface = SDL_CreateRGBSurface(0, screen_width, screen_height, 32, 0, 0, 0, 0);
    SDL_FillRect(background_surface, NULL, SDL_MapRGB(background_surface->format, 215, 113, 22));

    Snapshot* snap = game_manager->pass_snapshot();

    for (size_t i = 0; i < snap->v_snap.size(); ++i)
    {
        std::clog << "i:" << i << " ";
        std::string i_str = snap->v_snap[i];
        int x(0), y(0);
        x = i_str[0] - 'a';
        y = '8' - i_str[1];
        std::clog << i_str << " x=" << x << " y=" << y << std::endl;

        SDL_FillRect(background_surface, grille[x + 8 * y]->rect, SDL_MapRGB(background_surface->format, 0, 0, 0));
        if (i_str[3] == '0')
            SDL_FillRect(background_surface, grille[x + 8 * y]->inner_rect, SDL_MapRGB(background_surface->format, 25, 25, 25));
        else
            SDL_FillRect(background_surface, grille[x + 8 * y]->inner_rect, SDL_MapRGB(background_surface->format, 255, 255, 255));
    }

    /*
    for (size_t i = 0; i < grille.size(); ++i)
   {
      SDL_FillRect(background_surface, grille[i]->rect, SDL_MapRGB(background_surface->format, 0, 0, 0));
      if (i % 2 == 0 && (i / 8) % 2 == 0 || i % 2 == 1 && (i / 8) % 2 == 1)
        SDL_FillRect(background_surface, grille[i]->inner_rect, SDL_MapRGB(background_surface->format, 230, 230, 230));
      else
        SDL_FillRect(background_surface, grille[i]->inner_rect, SDL_MapRGB(background_surface->format, 25, 25, 25));
   }
   */

   SDL_Texture* background_texture = SDL_CreateTextureFromSurface(ren, background_surface);
   SDL_RenderCopy(ren, background_texture, nullptr, nullptr);

   SDL_RenderPresent(ren);
}

// EVENT MANAGER CLASS IMPLEMENTATION:

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
