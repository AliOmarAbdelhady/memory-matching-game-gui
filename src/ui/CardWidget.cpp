#include "CardWidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

CardWidget::CardWidget(int cardValue, QWidget *parent)
    : QWidget(parent), value(cardValue), isFlipped(false) {
    button = new QPushButton(" ");
    button->setFixedSize(100, 100);
    connect(button, &QPushButton::clicked, this, &CardWidget::onCardClicked);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(button);
    setLayout(layout);
}

void CardWidget::onCardClicked() {
    if (!isFlipped) {
        emit cardFlipped(value);
        flipCard();
    }
}

void CardWidget::flipCard() {
    isFlipped = true;
    button->setText(QString::number(value));
}

void CardWidget::resetCard() {
    isFlipped = false;
    button->setText(" ");
}