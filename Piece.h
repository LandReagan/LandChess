#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED

enum NATURE {ROI, DAME, FOU, CAVALIER, TOUR, PION};
enum COLOR {WHITE, BLACK};

class Piece
{
   public:
      Piece(NATURE n, COLOR c) : nature(n), color(c) {}

   private:
      NATURE nature;
      COLOR color;
};

#endif // PIECE_H_INCLUDED
