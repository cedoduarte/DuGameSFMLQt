#include "QSFMLCanvas.h"
#include <QTimer>

QSFMLCanvas::QSFMLCanvas(QWidget *parent, const QPoint &position,
                         const QSize &size, unsigned frameTime)
    : QWidget(parent)
{
    mInitialized = false;
    mTimer = new QTimer(this);

    // setup some states to allow direct rendering into the widget
    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);

    // set strong focus to enable keyboard events to be received
    setFocusPolicy(Qt::StrongFocus);

    // setup the widget geometry
    move(position);
    resize(size);

    // setup the timer
    mTimer->setInterval(frameTime);
}

QSFMLCanvas::~QSFMLCanvas()
{
}

QPaintEngine *QSFMLCanvas::paintEngine() const
{
    return nullptr;
}

void QSFMLCanvas::showEvent(QShowEvent *)
{
    if (!mInitialized) {
        // create the SFML window with the widget handle
        RenderWindow::create(reinterpret_cast<sf::WindowHandle>(winId()));

        // let the derived class do its specific stuff
        OnInit();

        // setup the timer to trigger a refresh at specified framerate
        auto slot1 = static_cast<void (QSFMLCanvas::*)(void)>
                    (&QSFMLCanvas::repaint);
        connect(mTimer, &QTimer::timeout, this, slot1);

        mTimer->start();
        mInitialized = true;
    }
}

void QSFMLCanvas::paintEvent(QPaintEvent *)
{
    // let the derived class do its specific stuff
    OnUpdate();

    // display on screen
    RenderWindow::display();
}

