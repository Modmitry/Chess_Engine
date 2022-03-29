#include "figure.h"

/////////////////////////////////////////////////
//------------- BASE CLASS ----------------------
 figure::figure(int x,int y,bool color,int moves_quantity): m_xCoord(x),m_yCoord(y), m_color(color), number_of_moves(moves_quantity)
 {
 };
//------------------------------------------------------
 void figure::getPosition(int& x,int&y) const
 {
    x=m_xCoord;
    y=m_yCoord;
 }
//------------------------------------------------------
 void figure::setPosition(int x,int y,bool testMove)
 {
     if (x>0&&x<9&&y>0&&y<9)
     {
        m_xCoord=x;
        m_yCoord=y;
        if (!testMove)
          number_of_moves++;
     }
 }
//------------------------------------------------------
void figure::setFigures(std::vector<figure*>* const figures)
{
    if (figures)
        m_figures=figures;
}
//------------------------------------------------------
// to determine the figure in position xC,yC
bool figure::determineFigureinPos(int x, int y,std::vector<std::pair<int,int>>& moves) const
{
    if (!isOnBoard(x,y))
         return false;

    if (!m_figures)
        return false;

    int xTemp,yTemp;

    for (const auto& fig:*m_figures)
    {
        fig->getPosition(xTemp,yTemp);

        if (xTemp==x&&yTemp==y)
        {
            if (fig->getColor()!=m_color)
            {
               moves.push_back(std::make_pair(x,y));
            }

           return false;
        }
    }

    moves.push_back(std::make_pair(x,y));
    return true;
};
//------------------------------------------------------
void figure::get_straight_moves(int xC, int yC,std::vector<std::pair<int,int>>& moves) const
{
    if (!m_figures)
        return;

    int x{0},y{0};

    // 1) up
    x=xC; y=yC;
    while (true)
    {
        y++;
        if (!determineFigureinPos(x,y,moves))
            break;
    }

    // 2) down
    x=xC; y=yC;
    while (true)
    {
        y--;
        if (!determineFigureinPos(x,y,moves))
            break;
    }

    // 3) right
    x=xC; y=yC;
    while (true)
    {
        x++;
        if (!determineFigureinPos(x,y,moves))
            break;
    }

    // 4) left
    x=xC; y=yC;
    while (true)
    {
        x--;
        if (!determineFigureinPos(x,y,moves))
            break;
    }

};
//------------------------------------------------------
void figure::get_diagonal_moves(int xC, int yC,std::vector<std::pair<int,int>>& moves) const
{
    if (!m_figures)
        return;

    int x{0},y{0};

    // 1) right + up
    x=xC; y=yC;
    while (true)
    {
        x++; y++;
        if (!determineFigureinPos(x,y,moves))
            break;
    }

    // 2) left + down
    x=xC; y=yC;
    while (true)
    {
        x--; y--;
        if (!determineFigureinPos(x,y,moves))
            break;
    }

    // 3) right + down
    x=xC; y=yC;
    while (true)
    {
        x++; y--;
        if (!determineFigureinPos(x,y, moves))
            break;
    }

    // 4) left + up
    x=xC; y=yC;
    while (true)
    {
        x--; y++;
        if (!determineFigureinPos(x,y, moves))
            break;
    }

};
//------------------------------------------------------


///////////////////////////////////////////////
//------------------  CASTLE   ----------------
void castle::getMoves(std::vector<std::pair<int,int>>& moves) const
{
    moves.clear();

    int xC,yC;
    this->getPosition(xC,yC);

    get_straight_moves(xC,yC,moves);
}
//---------------------------------------------------------
void castle::getImage(QString& img) const
{
    getColor()? img="D:/Chess/figures/W_castle.png": img="D:/Chess/figures/B_castle.png";
}
///////////////////////////////////////////////

//------------------  KNIGHT   ----------------
void knight::getMoves(std::vector<std::pair<int,int>>& moves) const
{
    // 8 possible moves !!!

   moves.clear();

   // position
   int x,y;
   this->getPosition(x,y);

    //1
    determineFigureinPos(x+1,y+2,moves);
    //2
    determineFigureinPos(x-1,y+2,moves);
    //3
    determineFigureinPos(x+1,y-2,moves);
    //4
    determineFigureinPos(x-1,y-2,moves);
    //5
    determineFigureinPos(x+2,y-1,moves);
    //6
    determineFigureinPos(x+2,y+1,moves);
    //7
    determineFigureinPos(x-2,y-1,moves);
    //8
    determineFigureinPos(x-2,y+1,moves);
}
//---------------------------------------------------------
void knight::getImage(QString& img) const
{
    getColor()? img="D:/Chess/figures/W_knight.png": img="D:/Chess/figures/B_knight.png";
}
//---------------------------------------------------------

///////////////////////////////////////////////
//------------------  BISHOP   ----------------
void bishop::getMoves(std::vector<std::pair<int,int>>& moves) const
{
     moves.clear();

    int xC,yC;
    this->getPosition(xC,yC);

    get_diagonal_moves(xC,yC,moves);
}
//---------------------------------------------------------
void bishop::getImage(QString& img) const
{
    getColor()? img="D:/Chess/figures/W_bishop.png": img="D:/Chess/figures/B_bishop.png";
}
//---------------------------------------------------------

///////////////////////////////////////////////
//------------------  PAWN   ----------------
void pawn::getMoves(std::vector<std::pair<int,int>>& moves) const
{
    //4 possible moves

    const std::vector<figure*>* allFigures=this->getFigures();

    if (!allFigures)
        return;

    moves.clear();

    // position
    int x,y;
    this->getPosition(x,y);

    int xTemp=x;
    int yTemp=y;

    // lambda move forward
    auto moveForward=[&]()->bool
    {
        if (!isOnBoard(xTemp,yTemp))
            return false;

        int xFig,yFig;
        for (const auto& fig:*allFigures)
        {
           fig->getPosition(xFig,yFig);

           if (xTemp==xFig&&yTemp==yFig)
              return false;
         }

         return true;
    };

    // lambda kill
    auto killPawn=[&]()->bool
    {
        if (!isOnBoard(xTemp,yTemp))
            return false;

        int xFig,yFig;
        for (const auto& fig:*allFigures)
        {
           fig->getPosition(xFig,yFig);

           if (xTemp==xFig&&yTemp==yFig && this->getColor()!=fig->getColor())
              return true;
         }
         return false;
    };


    //1
    if (this->getColor())
        yTemp++;
    else
        yTemp--;


    if (moveForward())
        moves.push_back(std::make_pair(xTemp,yTemp));

    //2 long move
    if (moves.size()>0&& getNumber_of_moves()==0)
    {
        if (this->getColor())
            yTemp++;
        else
            yTemp--;

        if (moveForward())
            moves.push_back(std::make_pair(xTemp,yTemp));
    }

    //3   right kill
    xTemp=x+1;

    if (this->getColor())
        yTemp=y+1;
    else
        yTemp=y-1;

    if (killPawn())
        moves.push_back(std::make_pair(xTemp,yTemp));


    //4   left kill
    xTemp=x-1;

    if (this->getColor())
        yTemp=y+1;
    else
        yTemp=y-1;

    if (killPawn())
        moves.push_back(std::make_pair(xTemp,yTemp));


}
//---------------------------------------------------------
void pawn::getImage(QString& img) const
{
    getColor()? img="D:/Chess/figures/W_pawn.png": img="D:/Chess/figures/B_pawn.png";
}
//---------------------------------------------------------

///////////////////////////////////////////////
//------------------  KING   ----------------
void king::getMoves(std::vector<std::pair<int,int>>& moves) const
{
    // 8 possible moves !!!
   moves.clear();

   // position
   int x,y;
   this->getPosition(x,y);

   //1
   determineFigureinPos(x+1,y+1,moves);
   //2
   determineFigureinPos(x+1,y,moves);
   //3
   determineFigureinPos(x+1,y-1,moves);
   //4
   determineFigureinPos(x-1,y+1,moves);
   //5
   determineFigureinPos(x-1,y,moves);
   //6
   determineFigureinPos(x-1,y-1,moves);
   //7
   determineFigureinPos(x,y+1,moves);
   //8
   determineFigureinPos(x,y-1,moves);

   // castling
   if (getNumber_of_moves()==0)
        castling(moves);



}
//---------------------------------------------------------
void king::getImage(QString& img) const
{
    getColor()? img="D:/Chess/figures/W_king.png": img="D:/Chess/figures/B_king.png";
}
//---------------------------------------------------------
void king::setPosition(int x,int y,bool testMove)
{
   if ( this->getNumber_of_moves()==0)
   {
        //color
        bool color=this->getColor();

        for (const auto& fig: *getFigures())
        {
           if (fig->isKindOf()==figureType::mCastle && fig->getColor()==color && fig->getNumber_of_moves()==0)
           {
               int xTemp,yTemp;
               fig->getPosition(xTemp,yTemp);

               if (x+1==xTemp&&y==yTemp)
                    fig->setPosition(x-1,yTemp);
               else if (x-2==xTemp&&y==yTemp)
                    fig->setPosition(x+1,yTemp);
           }
       }
   }

    figure::setPosition(x,y,testMove);
};
//---------------------------------------------------------
 void king::castling(std::vector<std::pair<int,int>>& moves) const
 {

     // current pos
     int x,y;
     this->getPosition(x,y);

     //color
     bool color=this->getColor();

     // temp moves
     std::vector<std::pair<int,int>> temp_moves;


    // to the short side (right)
    if (determineFigureinPos(x+1,y,temp_moves))
    {
        if (determineFigureinPos(x+2,y,temp_moves))
        {
             // the way between king and castle is clear
             for (const auto& fig: *getFigures())
             {
                if (fig->isKindOf()==figureType::mCastle && fig->getColor()==color && fig->getNumber_of_moves()==0)
                {

                    int xTemp,yTemp;
                    fig->getPosition(xTemp,yTemp);


                     if (xTemp==x+3 && yTemp==y) // found the castle in a right position
                         moves.push_back(std::make_pair(xTemp-1,yTemp));
                }
             }
         }
    }




    // to the long side (left)
    if (determineFigureinPos(x-1,y,temp_moves))
    {
        if (determineFigureinPos(x-2,y,temp_moves))
        {

            if (determineFigureinPos(x-3,y,temp_moves))
            {
                 // the way between king and castle is clear
                 for (const auto& fig: *getFigures())
                 {
                    if (fig->isKindOf()==figureType::mCastle && fig->getColor()==color && fig->getNumber_of_moves()==0)
                    {

                        int xTemp,yTemp;
                        fig->getPosition(xTemp,yTemp);


                         if (xTemp==x-4 && yTemp==y) // found the castle in a right position
                             moves.push_back(std::make_pair(xTemp+2,yTemp));
                    }
                 }
             }
         }
    }
 }
 //---------------------------------------------------------


///////////////////////////////////////////////
//------------------  QUEEN   ----------------
void queen::getMoves(std::vector<std::pair<int,int>>& moves) const
{
    moves.clear();

    int xC,yC;
    this->getPosition(xC,yC);

    get_straight_moves(xC,yC,moves);
    get_diagonal_moves(xC,yC,moves);
}
//---------------------------------------------------------
void queen::getImage(QString& img) const
{
    getColor()? img="D:/Chess/figures/W_queen.png": img="D:/Chess/figures/B_queen.png";
}
//---------------------------------------------------------




















