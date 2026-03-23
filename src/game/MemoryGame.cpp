#include "MemoryGame.h"
#include <algorithm>
#include <random>
#include <QDebug>

MemoryGame::MemoryGame(int r, int c) : rows(r), cols(c), score(0), attempts(0), pairsFound(0), gameOver(false) {
    if ((rows * cols) % 2 != 0) {
        qDebug() << "Error: Grid must have an even number of cells for pairs.";
        exit(1);
    }

    totalPairs = (rows * cols) / 2;
    cardGrid.resize(rows, std::vector<int>(cols, 0));
    revealedCards.resize(rows, std::vector<bool>(cols, false));
    matchedCards.resize(rows, std::vector<bool>(cols, false));
    initializeCards();
    startTime = time(nullptr);
}

void MemoryGame::initializeCards() {
    std::vector<int> cardValues;
    for (int i = 1; i <= totalPairs; i++) {
        cardValues.push_back(i);
        cardValues.push_back(i);
    }

    shuffleCards(cardValues);
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cardGrid[i][j] = cardValues[index++];
        }
    }
}

void MemoryGame::shuffleCards(std::vector<int>& cards) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
}

bool MemoryGame::flipCard(int row, int col) {
    row--; 
    col--; 

    if (!isValid(row, col) || revealedCards[row][col] || matchedCards[row][col]) {
        return false;
    }

    revealedCards[row][col] = true;
    return true;
}

bool MemoryGame::isValid(int row, int col) {
    return row >= 0 && row < rows && col >= 0 && col < cols;
}

bool MemoryGame::checkMatch(int row1, int col1, int row2, int col2) {
    return cardGrid[row1][col1] == cardGrid[row2][col2];
}

void MemoryGame::updateGameState(int row1, int col1, int row2, int col2) {
    if (checkMatch(row1, col1, row2, col2)) {
        matchedCards[row1][col1] = true;
        matchedCards[row2][col2] = true;
        score += 10;
        pairsFound++;
    } else {
        score = std::max(0, score - 2);
        revealedCards[row1][col1] = false;
        revealedCards[row2][col2] = false;
    }
    attempts++;
    gameOver = (pairsFound == totalPairs);
}

void MemoryGame::resetGame() {
    score = 0;
    attempts = 0;
    pairsFound = 0;
    gameOver = false;
    revealedCards.assign(rows, std::vector<bool>(cols, false));
    matchedCards.assign(rows, std::vector<bool>(cols, false));
    initializeCards();
    startTime = time(nullptr);
}

int MemoryGame::getScore() const {
    return score;
}

int MemoryGame::getAttempts() const {
    return attempts;
}

int MemoryGame::getPairsFound() const {
    return pairsFound;
}

int MemoryGame::getTotalPairs() const {
    return totalPairs;
}

time_t MemoryGame::getElapsedTime() const {
    return difftime(time(nullptr), startTime);
}