#ifndef INTELLIGENCE_H
#define INTELLIGENCE_H

#include "figure.h"


class Intelligence
{
public:
    Intelligence();




    static figure* tempErasing(std::vector<figure*>& figures, int xC, int yC)
    {
        figure* tempFig{nullptr};

        //
        for (auto it = figures.begin(); it != figures.end(); it++)
        {
            int xTemp,yTemp;
            it.operator*()->getPosition(xTemp,yTemp);

            if (xTemp==xC&&yTemp==yC)
            {
                switch (it.operator*()->isKindOf())
                {
                case (figure::figureType::mBishop):
                    tempFig=new bishop(xTemp,yTemp,it.operator*()->getColor(),it.operator*()->getNumber_of_moves());
                    break;
                case (figure::figureType::mCastle):
                    tempFig=new castle(xTemp,yTemp,it.operator*()->getColor(),it.operator*()->getNumber_of_moves());
                    break;
                case (figure::figureType::mKing):
                    tempFig=new king(xTemp,yTemp,it.operator*()->getColor(),it.operator*()->getNumber_of_moves());
                    break;
                case (figure::figureType::mKnight):
                    tempFig=new knight(xTemp,yTemp,it.operator*()->getColor(),it.operator*()->getNumber_of_moves());
                    break;
                case (figure::figureType::mPawn):
                    tempFig=new pawn(xTemp,yTemp,it.operator*()->getColor(),it.operator*()->getNumber_of_moves());
                    break;
                case (figure::figureType::mQueen):
                    tempFig=new queen(xTemp,yTemp,it.operator*()->getColor(),it.operator*()->getNumber_of_moves());
                    break;
                };

                delete *it;
                figures.erase(it);
                break;
            }
        }
        //
        return tempFig;
    }










    static void computer_engine(std::vector<figure*>& figures, bool current_move)
    {
        if (current_move)
            return;

        for (const auto& fig:figures)
        {


        }




    };


    // determine can figure currentFig move in cage{xC,yC}
    static bool kings_safety(figure*& currentFig,std::vector<figure*>& figures, int xC, int yC)
    {
         // save current position
         int xCurrent,yCurrent;
         currentFig->getPosition(xCurrent,yCurrent);

        // suppose we can go here
        // last parameter is true, because it is a testing move and it is not necessary to increase  number_of_moves


       figure* newFig=tempErasing(figures,xC,yC);

       currentFig->setPosition(xC,yC,true);


        //  now determine king s position
        int xKing,yKing;
        for (const auto& fig:figures)
        {
            if (!fig)
                continue;

            if (fig->isKindOf()==figure::figureType::mKing && fig->getColor()==currentFig->getColor())
            {
                fig->getPosition(xKing,yKing);
                break;
            }
        }

        //  now determine king s safety
        for (const auto& fig:figures)
        {
            if (!fig)
                continue;

            if (fig->getColor()==currentFig->getColor())
                continue;

            /*int xT,yT;
            fig->getPosition(xT,yT);
            if (xT==xC&&yT==yC)
                continue;*/

            std::vector<std::pair<int,int>> tempMoves;
            fig->getMoves(tempMoves);


            for (const auto& move:tempMoves)
            {
               if (move.first==xKing && move.second==yKing)
               {
                    currentFig->setPosition(xCurrent,yCurrent,true);

                    if (newFig)
                    {
                        figures.push_back(newFig);
                        newFig->setFigures(&figures);
                    }

                    return false;
               }
            }
        }

        currentFig->setPosition(xCurrent,yCurrent,true);

        if (newFig)
        {
            figures.push_back(newFig);
            newFig->setFigures(&figures);
        }

        return true;
    }










};

#endif // INTELLIGENCE_H
