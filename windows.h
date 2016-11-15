#ifndef DEF_WINDOWS

#define DEF_WINDOWS



#include <QCoreApplication>
#include <QWidget>
#include <QPushButton>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPolygonF>
#include <QPointF>
#include <QApplication>
#include <QLCDNumber>
#include <QTimer>
#include <QGridLayout>
#include <QVector>
#include <QPen>
#include <QBrush>



class windows : public QWidget
{
    Q_OBJECT

    public:
    windows();
    windows(int dt);
    void dessiner(QVector<QPointF> v,QPen pen=QPen(Qt::red),QBrush brush=QBrush(Qt::blue));


    public slots:
    void run();
    void afficher();
    void reset();
    void update();

    private:
    QPushButton *m_bouton;
    QTimer *timer;
    bool a;
    int step;
    static const int default_step=40;
    QGraphicsScene* m_scene;
    QGraphicsView* m_view;
    QPushButton *m_reset;

    // Pour le chrono
    QLCDNumber* m_LCD;
    int m_Timer_value;
    QTimer* m_timer;
    bool validStart;


    int avancement;
};



#endif
