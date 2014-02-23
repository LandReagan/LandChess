#ifndef GRAPH_STRUCT_H_INCLUDED
#define GRAPH_STRUCT_H_INCLUDED

#include <iostream>
#include <vector>

#include "SDL2/SDL.h"

#include "default_display_constants.h"

/*

Graph_Struct describes display canevas of game screen, 64 rects with x from 0
to 7 and y as well. Default size is described by default constants:

*/

class Graph_Struct
{
   public:
      Graph_Struct(int, int);
      virtual ~Graph_Struct();

      SDL_Rect* rect;
      SDL_Rect* inner_rect;
      int x;
      int y;
};

#endif // GRAPH_STRUCT_H_INCLUDED


