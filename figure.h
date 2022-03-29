#ifndef FIGURE_H
#define FIGURE_H

#include <QMainWindow>
//------------- BASE CLASS ----------------------
class figure
{
public:
    figure(){};
    figure(int x,int y,bool color,int moves_quantity=0);
    /*figure(const figure*& fig)
    {

        fig->getPosition(m_xCoord,m_yCoord);
        m_color=fig->getColor();
        number_of_moves=fig->getNumber_of_moves();
        m_figures=fig->getFigures1();

    };*/
    virtual ~figure() {};

    void getPosition(int& x,int&y) const;
    virtual void setPosition(int x,int y,bool testMove=false);

    bool isOnBoard( )const { return (m_xCoord>0&&m_xCoord<9&&m_yCoord>0&&m_yCoord<9);};
    static bool isOnBoard(int x, int y) {return (x>0&&y>0&&x<9&&y<9);};

    std::vector<figure*>* getFigures1() const { return m_figures;};
    const std::vector<figure*>* getFigures() const { return m_figures;};
    void setFigures(std::vector<figure*>* const figures);


    bool getColor() const{return m_color; };
    int getNumber_of_moves() const {return number_of_moves;};

protected:

    // to determine the figure in position xC,yC
    bool determineFigureinPos(int xC, int yC,std::vector<std::pair<int,int>>& moves) const;
    void get_straight_moves(int xC, int yC,std::vector<std::pair<int,int>>& moves) const;
    void get_diagonal_moves(int xC, int yC,std::vector<std::pair<int,int>>& moves) const;

    // members
private:

    int m_xCoord;
    int m_yCoord;
    bool m_color;   // black=false; white=true
    int number_of_moves;

    //vector-pointer to all figures
    std::vector<figure*>* m_figures=nullptr;

public:

    enum class figureType
    {
        mCastle,
        mKnight,
        mBishop,
        mPawn,
        mKing,
        mQueen
    };



public:
    // necessary to override
    virtual void getMoves(std::vector<std::pair<int,int>>& moves)const=0;
    virtual void getImage(QString& img) const = 0;
    virtual figureType isKindOf() const =0;

};

//------------------  CASTLE   ----------------
class castle: public figure
{

 public:
    castle(){};
    castle(int x,int y,bool color,int moves_quantity=0): figure(x,y,color,moves_quantity){};
    ~castle() override {};

    void getMoves(std::vector<std::pair<int,int>>& moves)const  override;
    void getImage(QString& img) const override;
    figureType isKindOf() const override  { return figureType::mCastle;};
};
//------------------  KNIGHT   ----------------
class knight: public figure
{

 public:
    knight(){};
    knight(int x,int y,bool color,int moves_quantity=0): figure(x,y,color,moves_quantity){};
    ~knight() override {};

    void getMoves(std::vector<std::pair<int,int>>& moves)const override;
    void getImage(QString& img) const override;
    figureType isKindOf() const override  { return figureType::mKnight;};
};
//------------------  BISHOP   ----------------
class bishop: public figure
{
 public:

    bishop(){};
    bishop(int x,int y,bool color,int moves_quantity=0): figure(x,y,color,moves_quantity){};
    ~bishop() override {};

    void getMoves(std::vector<std::pair<int,int>>& moves)const override;
    void getImage(QString& img) const override;
    figureType isKindOf() const override  { return figureType::mBishop;};
};
//------------------  PAWN   ----------------
class pawn: public figure
{
 public:

    pawn(){};
    pawn(int x,int y,bool color,int moves_quantity=0): figure(x,y,color,moves_quantity){};
    ~pawn() override {};

    void getMoves(std::vector<std::pair<int,int>>& moves)const override;
    void getImage(QString& img) const override;
    figureType isKindOf() const override  { return figureType::mPawn;};
};
//------------------  KING   ----------------
class king: public figure
{
 public:

    king(){};
    king(int x,int y,bool color,int moves_quantity=0): figure(x,y,color,moves_quantity){};
    ~king() override {};

    void getMoves(std::vector<std::pair<int,int>>& moves)const override;
    void getImage(QString& img) const override;
    figureType isKindOf() const override  { return figureType::mKing;};
    virtual void setPosition(int x,int y,bool testMove=false) override;


private:
    void castling(std::vector<std::pair<int,int>>& moves) const;
};
//------------------  QUEEN   ----------------
class queen: public figure
{
 public:

    queen(){};
    queen(int x,int y,bool color,int moves_quantity=0): figure(x,y,color,moves_quantity){};
    ~queen() override {};

    void getMoves(std::vector<std::pair<int,int>>& moves)const override;
    void getImage(QString& img) const override;
    figureType isKindOf() const override  { return figureType::mQueen;};
};



#endif // FIGURE_H
