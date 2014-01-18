#include "Graph_Struct.h"

Graph_Struct::Graph_Struct(int m_x, int m_y) : x(m_x), y(m_y)
{
   rect = new SDL_Rect();
   rect->h = case_width;
   rect->w = case_width;
   rect->x = left_margin + x * case_width;
   rect->y = top_margin + y * case_width;

   inner_rect = new SDL_Rect();
   inner_rect->h = case_width - 2 * case_border_thickness;
   inner_rect->w = case_width - 2 * case_border_thickness;
   inner_rect->x = left_margin + x * case_width + case_border_thickness;
   inner_rect->y = top_margin + y * case_width + case_border_thickness;
}

Graph_Struct::~Graph_Struct()
{
   delete rect;
}
