#include "TextManager.h"

TextManager::TextManager(QGraphicsItem *parent)
{
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));
}

void TextManager::hideText()
{
    hide();
}

void TextManager::showText(QString text)
{
    setPlainText(text);
    show();
}
