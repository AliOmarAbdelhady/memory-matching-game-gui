#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>
#include <QGridLayout>
#include <vector>
#include "CardWidget.h"
#include "MemoryGame.h"

class GameBoard : public QWidget {
    Q_OBJECT

public:
    GameBoard(int rows, int cols, QWidget *parent = nullptr);
    void updateBoard();
    void resetBoard();

private:
    int rows;
    int cols;
    QGridLayout *layout;
    std::vector<std::vector<CardWidget*>> cardWidgets;
    MemoryGame *memoryGame;

    void initializeBoard();
};

#endif // GAMEBOARD_H