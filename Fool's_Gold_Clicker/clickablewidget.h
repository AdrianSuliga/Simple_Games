#ifndef CLICKABLEWIDGET_H
#define CLICKABLEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QBoxLayout>
#include <QSpacerItem>

class ClickableWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ClickableWidget(QWidget* parent = nullptr, int nr = 0, QString pts = "0.0", QString m = "1.0",
                             QString h = "0", QString pi = "0", QString c = "0", QString dl = "0", QString dy = "0");
    ~ClickableWidget();
signals:
    void clicked();
protected:
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
private slots:
    void setLayoutClickableWidget(int nr, QFont Bohemian);
    void setStyleClickableWidget();
private:
    QLabel *titleLabel, *lineLabel, *pointsLabel, *multiLabel, *hammersLabel, *hammersIcon, *pickaxesLabel, *pickaxesIcon,
        *childrenLabel, *childrenIcon, *drillLabel, *drillIcon, *dynamiteLabel, *dynamiteIcon;
    QSpacerItem *hammersSpacer, *pickaxesSpacer, *childrenSpacer, *drillSpacer, *dynamiteSpacer;
    QHBoxLayout *pointsLayout, *multiLayout, *hammersLayout, *pickaxesLayout, *childrenLayout, *drillsLayout, *dynamiteLayout;
    QVBoxLayout *mainLayout;
    QString points, multi, ham, pick, ch, dr, dm;
};

#endif // CLICKABLEWIDGET_H
