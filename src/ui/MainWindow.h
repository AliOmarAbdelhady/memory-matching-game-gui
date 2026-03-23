#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include "GameBoard.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void setupUI();
    void connectSignals();

    GameBoard *gameBoard;
    QPushButton *restartButton;

private slots:
    void onRestartButtonClicked();
};

#endif // MAINWINDOW_H