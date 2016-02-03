#include "TextManager.h"

TextManager::TextManager()
{
    setDefaultTextColor(Qt::white);
    setFont(QFont("ArcadeClassic",16));
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
