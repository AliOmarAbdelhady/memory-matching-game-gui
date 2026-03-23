#include "GameBoard.h"
#include "CardWidget.h"
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>

GameBoard::GameBoard(QWidget *parent) : QWidget(parent) {
    layout = new QVBoxLayout(this);
    gridLayout = new QGridLayout();
    layout->addLayout(gridLayout);
    
    statusLabel = new QLabel("Welcome to the Memory Matching Game!", this);
    layout->addWidget(statusLabel);
}

void GameBoard::initializeBoard(int rows, int cols) {
    clearBoard();
    cardWidgets.clear();
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            CardWidget *card = new CardWidget(this);
            cardWidgets.push_back(card);
            gridLayout->addWidget(card, i, j);
            connect(card, &CardWidget::cardFlipped, this, &GameBoard::onCardFlipped);
        }
    }
}

void GameBoard::clearBoard() {
    QLayoutItem *item;
    while ((item = gridLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
}

void GameBoard::onCardFlipped(CardWidget *card) {
    // Handle card flip logic and update the game state
    // This will involve communicating with the MemoryGame instance
    // and updating the UI accordingly.
}

void GameBoard::updateStatus(const QString &message) {
    statusLabel->setText(message);
}