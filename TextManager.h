#ifndef TEXTMANAGER_H
#define TEXTMANAGER_H
#include <QGraphicsTextItem>
#include <QString>
#include <QFont>

class TextManager : public QGraphicsTextItem
{
public:
    TextManager();
    void hideText();
    void showText(QString text);
private:

};

#endif // TEXTMANAGER_H
