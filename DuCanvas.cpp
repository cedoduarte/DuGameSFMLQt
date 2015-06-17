#include "DuCanvas.h"

DuCanvas::DuCanvas(QWidget *parent, const QPoint &position, const QSize &size)
    : QSFMLCanvas(parent, position, size)
{
}

void DuCanvas::OnInit()
{
    // load the image
    mImage.loadFromFile("/users/cedoduarte/desktop/qt.png");

    // setup the sprite
    mSprite.setTexture(mImage);
    mSprite.setPosition(150, 150);
    mClock.restart();
}

void DuCanvas::OnUpdate()
{
    // clear screen
    RenderWindow::clear(sf::Color(0, 128, 0));
    mSprite.rotate(mClock.getElapsedTime().asSeconds() * 100.0);

    // draw it
    RenderWindow::draw(mSprite);
    mClock.restart();
}
