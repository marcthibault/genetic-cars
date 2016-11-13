#include "windows.h"

windows::windows() : QWidget()
{
    setFixedSize(100, 50);

    m_bouton = new QPushButton("Run !", this);
    m_bouton->setFont(QFont("Comic Sans MS", 14));
    m_bouton->move(0, 0);


    QObject::connect(m_bouton, SIGNAL(clicked()), this, SLOT(run()));
}

void windows::run()
{


    setFixedSize(1000, 600);

}
