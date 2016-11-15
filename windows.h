#ifndef DEF_WINDOWS

#define DEF_WINDOWS



#include <QCoreApplication>
#include <QWidget>
#include <QPushButton>
#include <QTimer>




class windows : public QWidget
{
    Q_OBJECT

    public:
    windows();
    windows(int dt);

    public slots:
    void run();
    void afficher();

    private:
    QPushButton *m_bouton;
    QTimer *timer;
    bool a;
    int step;
    static const int default_step=40;
};



#endif
