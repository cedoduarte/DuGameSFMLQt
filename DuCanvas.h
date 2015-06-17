#ifndef DUCANVAS_H
#define DUCANVAS_H

#include "QSFMLCanvas.h"

class DuCanvas : public QSFMLCanvas
{
public:
    DuCanvas(QWidget *parent, const QPoint &position, const QSize &size);
protected:
    void OnInit() override;
    void OnUpdate() override;
private:
    sf::Clock mClock;
    sf::Texture mImage;
    sf::Sprite mSprite;
};

#endif // DUCANVAS_H
