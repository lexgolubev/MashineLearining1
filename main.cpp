#include "mainwindow.h"
#include <QApplication>
#include <QtCore>
#include <QVector>
#include <QPointF>
#define BIG_NUMBER 9999999

int main(int argc, char *argv[])
{
    auto getRand = []()->double {
        return static_cast<double>(((double)(qrand() % BIG_NUMBER)) / BIG_NUMBER);
    };

    auto generateDots = [&getRand](int size, const QPointF &center, double r) -> QVector<QPointF> {
        QVector<QPointF> points;
        for(int i = 0; i < size; ++i) {
            double x1 = center.x() + getRand()*r;
            double x2 = center.y() + getRand()*r;
            points.append(QPoint(x1, x2));
        }
        return points;

    };


    auto countWeightsAndT = [](const QVector<QPointF> &poistsA, const QVector<QPointF> &pointB, double &w1, double &w2)->double {
        QVector<QPointF> points;
        for (int i = 0; i < points1.size(); i++) {
            points << points1[i] << points2[i];
        }
        auto alf = static_cast<double>(0.01);
    //learning
        int curEpoch = 0;
        bool goodEpoch = false;
        while(!goodEpoch) {
            goodEpoch = true;
            for(int curPoint = 0; curPoint < points.size(); ++curPoint) {
                auto S = points.at(curPoint).x()*w1 + points.at(curPoint).y()*w2 - T;
                auto y = (S<=0) ? 0 : 1;
                int e;
                if (curPoint % 2 == 0) {
                    e = 0;
                } else {
                    e = 1;
                }
                int K = y - e;
                w1 = w1 - alf * points.at(curPoint).x() * (K);
                w2 = w2 - alf * points.at(curPoint).y() * (K);
                T = T + alf * (K);
                if (K != 0) {
                    goodEpoch = false;
                }
            }
            curEpoch++;
        }

    };



//1) initiaization
    qsrand(QTime::currentTime().second());
    double w1 = getRand();
    double w2 = getRand();
    double T = getRand();

    auto points1 = generateDots(20, QPointF(10, 10), 4);
    auto points2 = generateDots(20, QPointF(20, 20), 5);
    auto points3 = generateDots(20, QPointf(30, 30), 5);
    QVector<QPointF> points;
    for (int i = 0; i < points1.size(); i++) {
        points << points1[i] << points2[i];
    }
    auto alf = static_cast<double>(0.01);
//learning
    int curEpoch = 0;
    bool goodEpoch = false;
    while(!goodEpoch) {
        goodEpoch = true;
        for(int curPoint = 0; curPoint < points.size(); ++curPoint) {
            auto S = points.at(curPoint).x()*w1 + points.at(curPoint).y()*w2 - T;
            auto y = (S<=0) ? 0 : 1;
            int e;
            if (curPoint % 2 == 0) {
                e = 0;
            } else {
                e = 1;
            }
            int K = y - e;
            w1 = w1 - alf * points.at(curPoint).x() * (K);
            w2 = w2 - alf * points.at(curPoint).y() * (K);
            T = T + alf * (K);
            if (K != 0) {
                goodEpoch = false;
            }
        }
        curEpoch++;
    }

    double a = T/w2;
    double b = -w1/w2;

    printf("w1: %lf \n w2: %lf \n T: %lf \n", w1, w2, T);
    printf("a: %lf \n b: %lf \n", a, b);
    printf("Current epoch: %d\n", curEpoch);
}
