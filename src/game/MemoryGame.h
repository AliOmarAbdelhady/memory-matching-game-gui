#ifndef MEMORYGAME_H
#define MEMORYGAME_H

#include <vector>
#include <ctime>
#include <algorithm>
#include <random>

class MemoryGame {
private:
    std::vector<std::vector<int>> cardGrid;
    std::vector<std::vector<bool>> revealedCards;
    std::vector<std::vector<bool>> matchedCards;
    int rows;
    int cols;
    int score;
    int attempts;
    int pairsFound;
    int totalPairs;
    time_t startTime;
    bool gameOver;

public:
    MemoryGame(int r, int c);
    void initializeCards();
    void shuffleCards(std::vector<int>& cards);
    bool flipCard(int row, int col);
    bool isValid(int row, int col);
    void playTurn(int row1, int col1, int row2, int col2);
    void displayStats() const;
    bool isGameOver() const;
    int getScore() const;
    int getAttempts() const;
    int getPairsFound() const;
    int getTotalPairs() const;
};

#endif // MEMORYGAME_H