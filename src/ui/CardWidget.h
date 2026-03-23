#ifndef CARDWIDGET_H
#define CARDWIDGET_H

#include <QWidget>
#include <QPushButton>

class CardWidget : public QWidget {
    Q_OBJECT

public:
    explicit CardWidget(int cardValue, QWidget *parent = nullptr);
    
    void revealCard();
    void hideCard();
    bool isRevealed() const;
    int getCardValue() const;

signals:
    void cardClicked(int cardValue);

private:
    int cardValue;
    QPushButton *button;
    bool revealed;
};

#endif // CARDWIDGET_H