#ifndef QSFMLCANVAS_H
#define QSFMLCANVAS_H

#include <QWidget>
#include <SFML/Graphics.hpp>

class QTimer;

class QSFMLCanvas : public QWidget, public sf::RenderWindow
{
public:
    QSFMLCanvas(QWidget *parent, const QPoint &position, const QSize &size,
                unsigned frameTime = 0);
    virtual ~QSFMLCanvas();
protected:
    QTimer *mTimer;
    bool mInitialized;

    virtual void OnInit() = 0;
    virtual void OnUpdate() = 0;
    QPaintEngine *paintEngine() const override;
    void showEvent(QShowEvent *) override;
    void paintEvent(QPaintEvent *) override;
};

#endif // QSFMLCANVAS_H
