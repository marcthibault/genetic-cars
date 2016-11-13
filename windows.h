#ifndef DEF_WINDOWS

#define DEF_WINDOWS



#include <QCoreApplication>
#include <QWidget>
#include <QPushButton>




class windows : public QWidget
{
    Q_OBJECT

    public:
    windows();

    public slots:
    void run();

    private:
    QPushButton *m_bouton;
};



#endif
