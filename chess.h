#ifndef CHESS_H
#define CHESS_H

#include "intelligence.h"
#include "ui_chess.h"


QT_BEGIN_NAMESPACE
namespace Ui { class CHESS; }
QT_END_NAMESPACE

class CHESS : public QMainWindow
{
    Q_OBJECT

public:
    CHESS(QWidget *parent = nullptr);
    ~CHESS();

private slots:
    void on_StartGameBtn_clicked();
    void on_StartGameBtn_2_clicked();
    void reverse();
    void startGame(bool userColor);

    //
    void on_a1_clicked();
    void on_b1_clicked();
    void on_c1_clicked();
    void on_d1_clicked();
    void on_e1_clicked();
    void on_f1_clicked();
    void on_g1_clicked();
    void on_h1_clicked();
    //
    void on_a2_clicked();
    void on_b2_clicked();
    void on_c2_clicked();
    void on_d2_clicked();
    void on_e2_clicked();
    void on_f2_clicked();
    void on_g2_clicked();
    void on_h2_clicked();
    //
    void on_a3_clicked();
    void on_b3_clicked();
    void on_c3_clicked();
    void on_d3_clicked();
    void on_e3_clicked();
    void on_f3_clicked();
    void on_g3_clicked();
    void on_h3_clicked();
    //
    void on_a4_clicked();
    void on_b4_clicked();
    void on_c4_clicked();
    void on_d4_clicked();
    void on_e4_clicked();
    void on_f4_clicked();
    void on_g4_clicked();
    void on_h4_clicked();
    //
    void on_a5_clicked();
    void on_b5_clicked();
    void on_c5_clicked();
    void on_d5_clicked();
    void on_e5_clicked();
    void on_f5_clicked();
    void on_g5_clicked();
    void on_h5_clicked();
    //
    void on_a6_clicked();
    void on_b6_clicked();
    void on_c6_clicked();
    void on_d6_clicked();
    void on_e6_clicked();
    void on_f6_clicked();
    void on_g6_clicked();
    void on_h6_clicked();
    //
    void on_a7_clicked();
    void on_b7_clicked();
    void on_c7_clicked();
    void on_d7_clicked();
    void on_e7_clicked();
    void on_f7_clicked();
    void on_g7_clicked();
    void on_h7_clicked();
    //
    void on_a8_clicked();
    void on_b8_clicked();
    void on_c8_clicked();
    void on_d8_clicked();
    void on_e8_clicked();
    void on_f8_clicked();
    void on_g8_clicked();
    void on_h8_clicked();

    void on_cell_clicked(int x,int y,QPushButton*& cage);
    //

    void on_figTransform1_clicked();
    void on_figTransform2_clicked();
    void on_figTransform3_clicked();
    void on_figTransform4_clicked();

    void on_figTransform_clicked(const figure::figureType& figureType);


    void setCageMoveColor(int x, int y);
    QPushButton* getCage(int x, int y);
    bool loadFigureImg(const figure* const figure);
    figure* getFigureInCage(int pos_x, int pos_y);
    void deleteFigureInCage(int pos_x, int pos_y);


    void updateCHESS();
    void cagesResetColor();
    void clearIcons();

    bool pawnTransformation();

private:
    Ui::CHESS *ui;



    //**// Move
    enum class moveStage
    {
        opponents_move,
        not_move,
        show_moves,
        select_move
    }currentMove=moveStage::not_move;

    std::vector<std::pair<int,int>> current_possible_moves;

    figure* move_figure=nullptr;
    //**//



    //**//
    static const int iconFigure=70;

    // all figures;
    std::vector<figure*> figures;

    bool enableMoves{true};

};
#endif // CHESS_H
