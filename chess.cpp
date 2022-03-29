#include "chess.h"

CHESS::CHESS(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CHESS)
{
    ui->setupUi(this);
}

CHESS::~CHESS()
{
    delete ui;
}

//---------------------------------------------------
void CHESS::on_StartGameBtn_clicked()
{
    startGame(true);
}
//---------------------------------------------------
void CHESS::on_StartGameBtn_2_clicked()
{
     startGame(false);
}
//---------------------------------------------------
void CHESS::reverse()
{
    ui->a1->setGeometry(QRect(760, 10, 90, 90));
    ui->a2->setGeometry(QRect(760, 100, 90, 90));
    ui->a3->setGeometry(QRect(760, 190, 90, 90));
    ui->a4->setGeometry(QRect(760, 280, 90, 90));
    ui->a5->setGeometry(QRect(760, 370, 90, 90));
    ui->a6->setGeometry(QRect(760, 460, 90, 90));
    ui->a7->setGeometry(QRect(760, 550, 90, 90));
    ui->a8->setGeometry(QRect(760, 640, 90, 90));

    ui->b1->setGeometry(QRect(670, 10, 90, 90));
    ui->b2->setGeometry(QRect(670, 100, 90, 90));
    ui->b3->setGeometry(QRect(670, 190, 90, 90));
    ui->b4->setGeometry(QRect(670, 280, 90, 90));
    ui->b5->setGeometry(QRect(670, 370, 90, 90));
    ui->b6->setGeometry(QRect(670, 460, 90, 90));
    ui->b7->setGeometry(QRect(670, 550, 90, 90));
    ui->b8->setGeometry(QRect(670, 640, 90, 90));

    ui->c1->setGeometry(QRect(580, 10, 90, 90));
    ui->c2->setGeometry(QRect(580, 100, 90, 90));
    ui->c3->setGeometry(QRect(580, 190, 90, 90));
    ui->c4->setGeometry(QRect(580, 280, 90, 90));
    ui->c5->setGeometry(QRect(580, 370, 90, 90));
    ui->c6->setGeometry(QRect(580, 460, 90, 90));
    ui->c7->setGeometry(QRect(580, 550, 90, 90));
    ui->c8->setGeometry(QRect(580, 640, 90, 90));

    ui->d1->setGeometry(QRect(490, 10, 90, 90));
    ui->d2->setGeometry(QRect(490, 100, 90, 90));
    ui->d3->setGeometry(QRect(490, 190, 90, 90));
    ui->d4->setGeometry(QRect(490, 280, 90, 90));
    ui->d5->setGeometry(QRect(490, 370, 90, 90));
    ui->d6->setGeometry(QRect(490, 460, 90, 90));
    ui->d7->setGeometry(QRect(490, 550, 90, 90));
    ui->d8->setGeometry(QRect(490, 640, 90, 90));

    ui->e8->setGeometry(QRect(400, 640, 90, 90));
    ui->e7->setGeometry(QRect(400, 550, 90, 90));
    ui->e6->setGeometry(QRect(400, 460, 90, 90));
    ui->e5->setGeometry(QRect(400, 370, 90, 90));
    ui->e4->setGeometry(QRect(400, 280, 90, 90));
    ui->e3->setGeometry(QRect(400, 190, 90, 90));
    ui->e2->setGeometry(QRect(400, 100, 90, 90));
    ui->e1->setGeometry(QRect(400, 10, 90, 90));

    ui->f8->setGeometry(QRect(310, 640, 90, 90));
    ui->f7->setGeometry(QRect(310, 550, 90, 90));
    ui->f6->setGeometry(QRect(310, 460, 90, 90));
    ui->f5->setGeometry(QRect(310, 370, 90, 90));
    ui->f4->setGeometry(QRect(310, 280, 90, 90));
    ui->f3->setGeometry(QRect(310, 190, 90, 90));
    ui->f2->setGeometry(QRect(310, 100, 90, 90));
    ui->f1->setGeometry(QRect(310, 10, 90, 90));

    ui->g8->setGeometry(QRect(220, 640, 90, 90));
    ui->g7->setGeometry(QRect(220, 550, 90, 90));
    ui->g6->setGeometry(QRect(220, 460, 90, 90));
    ui->g5->setGeometry(QRect(220, 370, 90, 90));
    ui->g4->setGeometry(QRect(220, 280, 90, 90));
    ui->g3->setGeometry(QRect(220, 190, 90, 90));
    ui->g2->setGeometry(QRect(220, 100, 90, 90));
    ui->g1->setGeometry(QRect(220, 10, 90, 90));

    ui->h8->setGeometry(QRect(130, 640, 90, 90));
    ui->h7->setGeometry(QRect(130, 550, 90, 90));
    ui->h6->setGeometry(QRect(130, 460, 90, 90));
    ui->h5->setGeometry(QRect(130, 370, 90, 90));
    ui->h4->setGeometry(QRect(130, 280, 90, 90));
    ui->h3->setGeometry(QRect(130, 190, 90, 90));
    ui->h2->setGeometry(QRect(130, 100, 90, 90));
    ui->h1->setGeometry(QRect(130, 10, 90, 90));

    ui->label1->setText("8");
    ui->label2->setText("7");
    ui->label3->setText("6");
    ui->label4->setText("5");
    ui->label5->setText("4");
    ui->label6->setText("3");
    ui->label7->setText("2");
    ui->label8->setText("1");

    ui->labelA->setText("H");
    ui->labelB->setText("G");
    ui->labelC->setText("F");
    ui->labelD->setText("E");
    ui->labelE->setText("D");
    ui->labelF->setText("C");
    ui->labelG->setText("B");
    ui->labelH->setText("A");
}
//---------------------------------------------------
void CHESS::startGame(bool userColor)
{
    if (!userColor)
        reverse();

    // pawns
    for (int i=1;i<9;i++)
    {
        pawn* white_pawn=new pawn(i,2,true);
        figures.push_back(white_pawn);

        pawn* black_pawn=new pawn(i,7,false);
        figures.push_back(black_pawn);
    }

    // castles
    castle* white_castle1=new castle(1,1,true);
    figures.push_back(white_castle1);
    castle* white_castle2=new castle(8,1,true);
    figures.push_back(white_castle2);

    castle* black_castle1=new castle(1,8,false);
    figures.push_back(black_castle1);
    castle* black_castle2=new castle(8,8,false);
    figures.push_back(black_castle2);

    //knights
    knight* white_knight1=new knight(2,1,true);
    figures.push_back(white_knight1);
    knight* white_knight2=new knight(7,1,true);
    figures.push_back(white_knight2);

    knight* black_knight1=new knight(2,8,false);
    figures.push_back(black_knight1);
    knight* black_knight2=new knight(7,8,false);
    figures.push_back(black_knight2);

    // bishops
    bishop* white_bishop1=new bishop(3,1,true);
    figures.push_back(white_bishop1);
    bishop* white_bishop2=new bishop(6,1,true);
    figures.push_back(white_bishop2);

    bishop*black_bishop1=new bishop(3,8,false);
    figures.push_back(black_bishop1);
    bishop* black_bishop2=new bishop(6,8,false);
    figures.push_back(black_bishop2);

    //kings
    king* white_king=new king(5,1,true);
    figures.push_back(white_king);
    king* black_king=new king(5,8,false);
    figures.push_back(black_king);

    //queens
    queen* white_queen=new queen(4,1,true);
    figures.push_back(white_queen);
    queen* black_queen=new queen(4,8,false);
    figures.push_back(black_queen);


    for (auto& fig:figures)
        fig->setFigures(&figures);

    // initial arrangement
    Intelligence::computer_engine(figures,userColor);
    updateCHESS();
}
//---------------------------------------------------


//------------------------------
void CHESS::on_a1_clicked()
{ 
   on_cell_clicked(1,1,ui->a1);
}
//------------------------------
void CHESS::on_b1_clicked()
{
   on_cell_clicked(2,1,ui->b1);
}
//------------------------------
void CHESS::on_c1_clicked()
{
    on_cell_clicked(3,1,ui->c1);
}
//------------------------------
void CHESS::on_d1_clicked()
{
    on_cell_clicked(4,1,ui->d1);
}
//------------------------------
void CHESS::on_e1_clicked()
{
    on_cell_clicked(5,1,ui->e1);
}
//------------------------------
void CHESS::on_f1_clicked()
{
    on_cell_clicked(6,1,ui->f1);
}
//------------------------------
void CHESS::on_g1_clicked()
{
    on_cell_clicked(7,1,ui->g1);
}
//------------------------------
void CHESS::on_h1_clicked()
{
   on_cell_clicked(8,1,ui->h1);
}
//------------------------------
void CHESS::on_a2_clicked()
{
  on_cell_clicked(1,2,ui->a2);
}
//------------------------------
void CHESS::on_b2_clicked()
{
    on_cell_clicked(2,2,ui->b2);
}
//------------------------------
void CHESS::on_c2_clicked()
{
     on_cell_clicked(3,2,ui->c2);
}
//------------------------------
void CHESS::on_d2_clicked()
{
     on_cell_clicked(4,2,ui->d2);
}
//------------------------------
void CHESS::on_e2_clicked()
{
     on_cell_clicked(5,2,ui->e2);
}
//------------------------------
void CHESS::on_f2_clicked()
{
     on_cell_clicked(6,2,ui->f2);
}
//------------------------------
void CHESS::on_g2_clicked()
{
     on_cell_clicked(7,2,ui->g2);
}
//------------------------------
void CHESS::on_h2_clicked()
{
     on_cell_clicked(8,2,ui->h2);
}
//------------------------------
void CHESS::on_a3_clicked()
{
    on_cell_clicked(1,3,ui->a3);
}
//------------------------------
void CHESS::on_b3_clicked()
{
    on_cell_clicked(2,3,ui->b3);
}
//------------------------------
void CHESS::on_c3_clicked()
{
    on_cell_clicked(3,3,ui->c3);
}
//------------------------------
void CHESS::on_d3_clicked()
{
    on_cell_clicked(4,3,ui->d3);
}
//------------------------------
void CHESS::on_e3_clicked()
{
    on_cell_clicked(5,3,ui->e3);
}
//------------------------------
void CHESS::on_f3_clicked()
{
    on_cell_clicked(6,3,ui->f3);
}
//------------------------------
void CHESS::on_g3_clicked()
{
    on_cell_clicked(7,3,ui->g3);
}
//------------------------------
void CHESS::on_h3_clicked()
{
    on_cell_clicked(8,3,ui->h3);
}
//------------------------------
void CHESS::on_a4_clicked()
{
    on_cell_clicked(1,4,ui->a4);
}
//------------------------------
void CHESS::on_b4_clicked()
{
    on_cell_clicked(2,4,ui->b4);
}
//------------------------------
void CHESS::on_c4_clicked()
{
    on_cell_clicked(3,4,ui->c4);
}
//------------------------------
void CHESS::on_d4_clicked()
{
    on_cell_clicked(4,4,ui->d4);
}
//------------------------------
void CHESS::on_e4_clicked()
{
    on_cell_clicked(5,4,ui->e4);
}
//------------------------------
void CHESS::on_f4_clicked()
{
    on_cell_clicked(6,4,ui->f4);
}
//------------------------------
void CHESS::on_g4_clicked()
{
    on_cell_clicked(7,4,ui->g4);
}
//------------------------------
void CHESS::on_h4_clicked()
{
    on_cell_clicked(8,4,ui->h4);
}
//------------------------------
void CHESS::on_a5_clicked()
{
    on_cell_clicked(1,5,ui->a5);
}
//------------------------------
void CHESS::on_b5_clicked()
{
    on_cell_clicked(2,5,ui->b5);
}
//------------------------------
void CHESS::on_c5_clicked()
{
    on_cell_clicked(3,5,ui->c5);
}
//------------------------------
void CHESS::on_d5_clicked()
{
    on_cell_clicked(4,5,ui->d5);
}
//------------------------------
void CHESS::on_e5_clicked()
{
    on_cell_clicked(5,5,ui->e5);
}
//------------------------------
void CHESS::on_f5_clicked()
{
    on_cell_clicked(6,5,ui->f5);
}
//------------------------------
void CHESS::on_g5_clicked()
{
    on_cell_clicked(7,5,ui->g5);
}
//------------------------------
void CHESS::on_h5_clicked()
{
    on_cell_clicked(8,5,ui->h5);
}
//------------------------------
void CHESS::on_a6_clicked()
{
    on_cell_clicked(1,6,ui->a6);
}
//------------------------------
void CHESS::on_b6_clicked()
{
    on_cell_clicked(2,6,ui->b6);
}
//------------------------------
void CHESS::on_c6_clicked()
{
    on_cell_clicked(3,6,ui->c6);
}
//------------------------------
void CHESS::on_d6_clicked()
{
    on_cell_clicked(4,6,ui->d6);
}
//------------------------------
void CHESS::on_e6_clicked()
{
    on_cell_clicked(5,6,ui->e6);
}
//------------------------------
void CHESS::on_f6_clicked()
{
    on_cell_clicked(6,6,ui->f6);
}
//------------------------------
void CHESS::on_g6_clicked()
{
    on_cell_clicked(7,6,ui->g6);
}
//------------------------------
void CHESS::on_h6_clicked()
{
    on_cell_clicked(8,6,ui->h6);
}
//------------------------------
void CHESS::on_a7_clicked()
{
    on_cell_clicked(1,7,ui->a7);
}
//------------------------------
void CHESS::on_b7_clicked()
{
    on_cell_clicked(2,7,ui->b7);
}
//------------------------------
void CHESS::on_c7_clicked()
{
    on_cell_clicked(3,7,ui->c7);
}
//------------------------------
void CHESS::on_d7_clicked()
{
    on_cell_clicked(4,7,ui->d7);
}
//------------------------------
void CHESS::on_e7_clicked()
{
    on_cell_clicked(5,7,ui->e7);
}
//------------------------------
void CHESS::on_f7_clicked()
{
    on_cell_clicked(6,7,ui->f7);
}
//------------------------------
void CHESS::on_g7_clicked()
{
    on_cell_clicked(7,7,ui->g7);
}
//------------------------------
void CHESS::on_h7_clicked()
{
    on_cell_clicked(8,7,ui->h7);
}
//------------------------------
void CHESS::on_a8_clicked()
{
    on_cell_clicked(1,8,ui->a8);
}
//------------------------------
void CHESS::on_b8_clicked()
{
    on_cell_clicked(2,8,ui->b8);
}
//------------------------------
void CHESS::on_c8_clicked()
{
    on_cell_clicked(3,8,ui->c8);
}
//------------------------------
void CHESS::on_d8_clicked()
{
    on_cell_clicked(4,8,ui->d8);
}
//------------------------------
void CHESS::on_e8_clicked()
{
    on_cell_clicked(5,8,ui->e8);
}
//------------------------------
void CHESS::on_f8_clicked()
{
    on_cell_clicked(6,8,ui->f8);
}
//------------------------------
void CHESS::on_g8_clicked()
{
    on_cell_clicked(7,8,ui->g8);
}
//------------------------------
void CHESS::on_h8_clicked()
{
    on_cell_clicked(8,8,ui->h8);
}
//---------------------------------------------------------------------
void CHESS::on_cell_clicked(int x,int y,QPushButton*& cage)
{
    if (!enableMoves)
        return;

    if (!cage)
        return;

    cagesResetColor();

    //////////////////////
    if (currentMove==moveStage::not_move)
    {
        figure* fig=getFigureInCage(x,y);

         if (fig)
         {
             std::vector<std::pair<int,int>> figure_moves;
             fig->getMoves(figure_moves);

             for (const auto& move:figure_moves)
             {
                 if (Intelligence::kings_safety(fig,figures,move.first,move.second))
                 {
                     current_possible_moves.push_back(std::pair(move.first,move.second));
                     setCageMoveColor(move.first,move.second);
                 }
             }

             if (!current_possible_moves.empty())
             {            
                // for next stage
                move_figure=fig;
                currentMove=moveStage::show_moves;
            }
        }
    }
    //////////////////////
    else  if (currentMove==moveStage::show_moves)
    {
        bool find_move{false};

        for (const auto& possible_move:current_possible_moves)
        {
            if (x==possible_move.first&&y==possible_move.second)
            {
                find_move=true;
                break;
            }
        }

        current_possible_moves.clear();
        currentMove=moveStage::not_move;

        if (find_move)
        {
            if (move_figure)
            {
                cagesResetColor();
                deleteFigureInCage(x,y);  // if found
                move_figure->setPosition(x,y);

                if (!pawnTransformation())
                {
                    Intelligence::computer_engine(figures,false);
                    updateCHESS();
                    return;
                }
            }
        }
        else
            on_cell_clicked(x,y,cage);
    }
    /*else  if (currentMove==moveStage::select_move)
    {
    }
    else  if (currentMove==moveStage::opponents_move)
    {
    }*/
    //////////////////////

    // make cage yellow  because user clicked it
    cage->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 115);"));

    return;
}
//---------------------------------------------------------------------
//---------------------------------------------------------------------
void CHESS::on_figTransform1_clicked()
{
    on_figTransform_clicked(figure::figureType::mQueen);
}
//---------------------------------------------------------------------
void CHESS::on_figTransform2_clicked()
{
    on_figTransform_clicked(figure::figureType::mCastle);
}
//---------------------------------------------------------------------
void CHESS::on_figTransform3_clicked()
{
    on_figTransform_clicked(figure::figureType::mBishop);
}
//---------------------------------------------------------------------
void CHESS::on_figTransform4_clicked()
{
    on_figTransform_clicked(figure::figureType::mKnight);
}
//---------------------------------------------------------------------
void CHESS::on_figTransform_clicked(const figure::figureType& figureType)
{
    if (!move_figure)
        return;

    if (move_figure->isKindOf()!=figure::figureType::mPawn)
        return;

    // current color
    bool color=move_figure->getColor();

    // current pos
    int x,y;
    move_figure->getPosition(x,y);

    if ((color&& y==8)/*white*/||(!color && y==1) /*black*/)
    {
        deleteFigureInCage(x,y);

        figure* new_fig{nullptr};

        switch (figureType)
        {
        case (figure::figureType::mQueen):
            new_fig=new queen(x,y,color);
            break;
        case (figure::figureType::mCastle):
            new_fig=new castle(x,y,color);
            break;
        case (figure::figureType::mBishop):
            new_fig=new bishop(x,y,color);
            break;
        case (figure::figureType::mKnight):
            new_fig=new knight(x,y,color);
            break;
        case (figure::figureType::mKing):
            break;
        case (figure::figureType::mPawn):
            break;
        default:
            break;
        }

        if (new_fig)
        {
            figures.push_back(new_fig);
            new_fig->setFigures(&figures);

            QIcon icon("");
            ui->figTransform1->setIcon(icon);
            ui->figTransform2->setIcon(icon);
            ui->figTransform3->setIcon(icon);
            ui->figTransform4->setIcon(icon);

            enableMoves=true;
        }

        Intelligence::computer_engine(figures,false);
        updateCHESS();
    }
}
//---------------------------------------------------------------------
//---------------------------------------------------------------------
void CHESS::setCageMoveColor(int x, int y)
{
    QPushButton* cage=getCage(x,y);
    if (cage)
        cage->setStyleSheet(QString::fromUtf8("background-color: rgb(5, 255, 254);"));
}
//------------------------------------------------------------------------------
QPushButton* CHESS::getCage(int x, int y)
{
    if (x==1)
    {
        switch(y)
        {
        case 1: return(ui->a1);
            break;
        case 2:  return(ui->a2);
            break;
        case 3:  return(ui->a3);
            break;
        case 4:   return(ui->a4);
            break;
        case 5:   return(ui->a5);
            break;
        case 6: return(ui->a6);
            break;
        case 7:  return(ui->a7);
            break;
        case 8:   return(ui->a8);
            break;
        default: return nullptr;
            break;
        }
    }
    else  if (x==2)
    {
        switch(y)
        {
        case 1: return(ui->b1);
            break;
        case 2:  return(ui->b2);
            break;
        case 3:  return(ui->b3);
            break;
        case 4:   return(ui->b4);
            break;
        case 5:   return(ui->b5);
            break;
        case 6: return(ui->b6);
            break;
        case 7:  return(ui->b7);
            break;
        case 8:   return(ui->b8);
            break;
        default: return nullptr;
            break;
        }
    }
    else  if (x==3)
    {
        switch(y)
        {
        case 1: return(ui->c1);
            break;
        case 2:  return(ui->c2);
            break;
        case 3:  return(ui->c3);
            break;
        case 4:   return(ui->c4);
            break;
        case 5:   return(ui->c5);
            break;
        case 6: return(ui->c6);
            break;
        case 7:  return(ui->c7);
            break;
        case 8:   return(ui->c8);
            break;
        default: return nullptr;
            break;
        }
    }
    else  if (x==4)
    {
        switch(y)
        {
        case 1: return(ui->d1);
            break;
        case 2:  return(ui->d2);
            break;
        case 3:  return(ui->d3);
            break;
        case 4:   return(ui->d4);
            break;
        case 5:   return(ui->d5);
            break;
        case 6: return(ui->d6);
            break;
        case 7:  return(ui->d7);
            break;
        case 8:   return(ui->d8);
            break;
        default: return nullptr;
            break;
        }
    }
    else  if (x==5)
    {
        switch(y)
        {
        case 1: return(ui->e1);
            break;
        case 2:  return(ui->e2);
            break;
        case 3:  return(ui->e3);
            break;
        case 4:   return(ui->e4);
            break;
        case 5:   return(ui->e5);
            break;
        case 6: return(ui->e6);
            break;
        case 7:  return(ui->e7);
            break;
        case 8:   return(ui->e8);
            break;
        default: return nullptr;
            break;
        }
    }
    else  if (x==6)
    {
        switch(y)
        {
        case 1: return(ui->f1);
            break;
        case 2:  return(ui->f2);
            break;
        case 3:  return(ui->f3);
            break;
        case 4:   return(ui->f4);
            break;
        case 5:   return(ui->f5);
            break;
        case 6: return(ui->f6);
            break;
        case 7:  return(ui->f7);
            break;
        case 8:   return(ui->f8);
            break;
        default: return nullptr;
            break;
        }
    }
    else  if (x==7)
    {
        switch(y)
        {
        case 1: return(ui->g1);
            break;
        case 2:  return(ui->g2);
            break;
        case 3:  return(ui->g3);
            break;
        case 4:   return(ui->g4);
            break;
        case 5:   return(ui->g5);
            break;
        case 6: return(ui->g6);
            break;
        case 7:  return(ui->g7);
            break;
        case 8:   return(ui->g8);
            break;
        default: return nullptr;
            break;
        }
    }
    else  if (x==8)
    {
        switch(y)
        {
        case 1: return(ui->h1);
            break;
        case 2:  return(ui->h2);
            break;
        case 3:  return(ui->h3);
            break;
        case 4:   return(ui->h4);
            break;
        case 5:   return(ui->h5);
            break;
        case 6: return(ui->h6);
            break;
        case 7:  return(ui->h7);
            break;
        case 8:   return(ui->h8);
            break;
        default: return nullptr;
            break;
        }
    }
    return nullptr;
}
//-----------------------------------------------------------------
bool CHESS::loadFigureImg(const figure* const figure)
{
    if (!figure)
        return false;

    // get position
    int x{0};
    int y{0};
    figure->getPosition(x,y);

    // get button(cage)
    QPushButton* cage=getCage(x,y);

    if (!cage)
        return false;


    // get img
    QString img;
    figure->getImage(img);
    QIcon icon(img);

    // icon size
    QSize size(iconFigure,iconFigure);

    cage->setIcon(icon);
    cage->setIconSize(size);

    return true;
};
//---------------------------------------------------------------
figure* CHESS::getFigureInCage(int pos_x, int pos_y)
{
    for (const auto& fig:figures)
    {
        if (!fig)
            continue;

        int x,y;
        fig->getPosition(x,y);

        if (x==pos_x && y==pos_y)
            return fig;
    }
    return nullptr;
}
//----------------------------------------------------------------
void CHESS::deleteFigureInCage(int pos_x, int pos_y)
{
    for (auto it = figures.begin(); it != figures.end(); it++)
    {
        int xTemp,yTemp;
        it.operator*()->getPosition(xTemp,yTemp);

        if (xTemp==pos_x&&yTemp==pos_y)
        {
            delete *it;
            figures.erase(it);
            break;
        }
    }
}
//----------------------------------------------------------------
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//----------------------------------------------------------------
void  CHESS::updateCHESS()
{
    clearIcons();

    for (const auto& fig:figures)
        loadFigureImg(fig);
}
//--------------------------------------------------------------------------
void CHESS::cagesResetColor()
{
ui->a1->setStyleSheet(QString::fromUtf8("background-color: rgb(90, 170, 5);"));
ui->a2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
ui->a3->setStyleSheet(QString::fromUtf8("background-color: rgb(90, 170, 5);"));
ui->a4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
ui->a5->setStyleSheet(QString::fromUtf8("background-color: rgb(90, 170, 5);"));
ui->a6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
ui->a7->setStyleSheet(QString::fromUtf8("background-color: rgb(90, 170, 5);"));
ui->a8->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

ui->b1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
ui->b2->setStyleSheet(QString::fromUtf8("background-color: rgb(90, 170, 5);"));
ui->b3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
ui->b4->setStyleSheet(QString::fromUtf8("background-color: rgb(90, 170, 5);"));
ui->b5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
ui->b6->setStyleSheet(QString::fromUtf8("background-color: rgb(90, 170, 5);"));
ui->b7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
ui->b8->setStyleSheet(QString::fromUtf8("background-color: rgb(90, 170, 5);"));

ui->c1->setStyleSheet(QString::fromUtf8("background-color: rgb(90, 170, 5);"));
ui->c2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
ui->c3->setStyleSheet(QString::fromUtf8("background-color: rgb(90, 170, 5);"));
ui->c4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
ui->c5->setStyleSheet(QString::fromUtf8("background-color: rgb(90, 170, 5);"));
ui->c6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
ui->c7->setStyleSheet(QString::fromUtf8("background-color: rgb(90, 170, 5);"));
ui->c8->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

ui->d1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
ui->d2->setStyleSheet(QString::fromUtf8("background-color: rgb(90, 170, 5);"));
ui->d3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
ui->d4->setStyleSheet(QString::fromUtf8("background-color: rgb(90, 170, 5);"));
ui->d5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
ui->d6->setStyleSheet(QString::fromUtf8("background-color: rgb(90, 170, 5);"));
ui->d7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
ui->d8->setStyleSheet(QString::fromUtf8("background-color: rgb(90, 170, 5);"));

ui->e1->setStyleSheet(QString::fromUtf8("background-color: rgb(90, 170, 5);"));
ui->e2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
ui->e3->setStyleSheet(QString::fromUtf8("background-color: rgb(90, 170, 5);"));
ui->e4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
ui->e5->setStyleSheet(QString::fromUtf8("background-color: rgb(90, 170, 5);"));
ui->e6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
ui->e7->setStyleSheet(QString::fromUtf8("background-color: rgb(90, 170, 5);"));
ui->e8->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

ui->f1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
ui->f2->setStyleSheet(QString::fromUtf8("background-color: rgb(90, 170, 5);"));
ui->f3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
ui->f4->setStyleSheet(QString::fromUtf8("background-color: rgb(90, 170, 5);"));
ui->f5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
ui->f6->setStyleSheet(QString::fromUtf8("background-color: rgb(90, 170, 5);"));
ui->f7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
ui->f8->setStyleSheet(QString::fromUtf8("background-color: rgb(90, 170, 5);"));

ui->g1->setStyleSheet(QString::fromUtf8("background-color: rgb(90, 170, 5);"));
ui->g2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
ui->g3->setStyleSheet(QString::fromUtf8("background-color: rgb(90, 170, 5);"));
ui->g4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
ui->g5->setStyleSheet(QString::fromUtf8("background-color: rgb(90, 170, 5);"));
ui->g6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
ui->g7->setStyleSheet(QString::fromUtf8("background-color: rgb(90, 170, 5);"));
ui->g8->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

ui->h1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
ui->h2->setStyleSheet(QString::fromUtf8("background-color: rgb(90, 170, 5);"));
ui->h3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
ui->h4->setStyleSheet(QString::fromUtf8("background-color: rgb(90, 170, 5);"));
ui->h5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
ui->h6->setStyleSheet(QString::fromUtf8("background-color: rgb(90, 170, 5);"));
ui->h7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
ui->h8->setStyleSheet(QString::fromUtf8("background-color: rgb(90, 170, 5);"));
}
//--------------------------------------------------------------------------
void CHESS::clearIcons()
{
    QIcon icon("");
    ui->a1->setIcon(icon);
    ui->a2->setIcon(icon);
    ui->a3->setIcon(icon);
    ui->a4->setIcon(icon);
    ui->a5->setIcon(icon);
    ui->a6->setIcon(icon);
    ui->a7->setIcon(icon);
    ui->a8->setIcon(icon);

    ui->b1->setIcon(icon);
    ui->b2->setIcon(icon);
    ui->b3->setIcon(icon);
    ui->b4->setIcon(icon);
    ui->b5->setIcon(icon);
    ui->b6->setIcon(icon);
    ui->b7->setIcon(icon);
    ui->b8->setIcon(icon);

    ui->c1->setIcon(icon);
    ui->c2->setIcon(icon);
    ui->c3->setIcon(icon);
    ui->c4->setIcon(icon);
    ui->c5->setIcon(icon);
    ui->c6->setIcon(icon);
    ui->c7->setIcon(icon);
    ui->c8->setIcon(icon);

    ui->d1->setIcon(icon);
    ui->d2->setIcon(icon);
    ui->d3->setIcon(icon);
    ui->d4->setIcon(icon);
    ui->d5->setIcon(icon);
    ui->d6->setIcon(icon);
    ui->d7->setIcon(icon);
    ui->d8->setIcon(icon);

    ui->e1->setIcon(icon);
    ui->e2->setIcon(icon);
    ui->e3->setIcon(icon);
    ui->e4->setIcon(icon);
    ui->e5->setIcon(icon);
    ui->e6->setIcon(icon);
    ui->e7->setIcon(icon);
    ui->e8->setIcon(icon);

    ui->f1->setIcon(icon);
    ui->f2->setIcon(icon);
    ui->f3->setIcon(icon);
    ui->f4->setIcon(icon);
    ui->f5->setIcon(icon);
    ui->f6->setIcon(icon);
    ui->f7->setIcon(icon);
    ui->f8->setIcon(icon);

    ui->g1->setIcon(icon);
    ui->g2->setIcon(icon);
    ui->g3->setIcon(icon);
    ui->g4->setIcon(icon);
    ui->g5->setIcon(icon);
    ui->g6->setIcon(icon);
    ui->g7->setIcon(icon);
    ui->g8->setIcon(icon);

    ui->h1->setIcon(icon);
    ui->h2->setIcon(icon);
    ui->h3->setIcon(icon);
    ui->h4->setIcon(icon);
    ui->h5->setIcon(icon);
    ui->h6->setIcon(icon);
    ui->h7->setIcon(icon);
    ui->h8->setIcon(icon);
}
//-------------------------------------

//-------------------------------------
bool CHESS::pawnTransformation()
{
    if (move_figure->isKindOf()!=figure::figureType::mPawn)
        return false;

    // current color
    bool color=move_figure->getColor();

    // current pos
    int x,y;
    move_figure->getPosition(x,y);

    // icon size
    QSize size(iconFigure,iconFigure);


    if (color&& y==8) //white
    {

      ui->figTransform1->setIcon(QIcon("D:/Chess/figures/W_queen.png"));
      ui->figTransform1->setIconSize(size);

      ui->figTransform2->setIcon(QIcon("D:/Chess/figures/W_castle.png"));
      ui->figTransform2->setIconSize(size);

      ui->figTransform3->setIcon(QIcon("D:/Chess/figures/W_bishop.png"));
      ui->figTransform3->setIconSize(size);

      ui->figTransform4->setIcon(QIcon("D:/Chess/figures/W_knight.png"));
      ui->figTransform4->setIconSize(size);

      enableMoves=false;

      return true;
    }
    else if (!color && y==1) //black
    {
        ui->figTransform1->setIcon(QIcon("D:/Chess/figures/B_queen.png"));
        ui->figTransform1->setIconSize(size);

        ui->figTransform2->setIcon(QIcon("D:/Chess/figures/B_castle.png"));
        ui->figTransform2->setIconSize(size);

        ui->figTransform3->setIcon(QIcon("D:/Chess/figures/B_bishop.png"));
        ui->figTransform3->setIconSize(size);

        ui->figTransform4->setIcon(QIcon("D:/Chess/figures/B_knight.png"));
        ui->figTransform4->setIconSize(size);

        enableMoves=false;

        return true;
    }

    return false;
};
//------------------------------------------------------





















