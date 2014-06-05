#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED

#include <iostream>

enum NATURE {ROI = 0, DAME, FOU, CAVALIER, TOUR, PION};
enum COLOR {BLACK = 0, WHITE};

class Piece
{
   public:
      Piece(NATURE n, COLOR c) : nature(n), color(c)
         {std::clog << "Piece cree nature:" << nature << " color:" << color << std::endl;}

    char get_nature() const {return nature;}
    char get_color() const {return color;}

   private:
      NATURE nature;
      COLOR color;
};

#endif // PIECE_H_INCLUDED
