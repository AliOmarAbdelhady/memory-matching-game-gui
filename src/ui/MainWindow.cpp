#include "MainWindow.h"
#include "GameBoard.h"
#include <QVBoxLayout>
#include <QMenuBar>
#include <QStatusBar>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Memory Matching Game");
    setFixedSize(800, 600);

    QVBoxLayout *layout = new QVBoxLayout;

    // Create the game board
    gameBoard = new GameBoard(this);
    layout->addWidget(gameBoard);

    // Set up the central widget
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // Create menu bar
    QMenuBar *menuBar = new QMenuBar(this);
    QMenu *fileMenu = new QMenu("File", this);
    QAction *exitAction = new QAction("Exit", this);
    connect(exitAction, &QAction::triggered, this, &QMainWindow::close);
    fileMenu->addAction(exitAction);
    menuBar->addMenu(fileMenu);
    setMenuBar(menuBar);

    // Create status bar
    statusBar()->showMessage("Welcome to the Memory Matching Game!");
}

void MainWindow::showGameOverMessage() {
    QMessageBox::information(this, "Game Over", "Congratulations! You've found all the pairs!");
}