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
    explicit ClickableWidget(QWidget* parent = nullptr, QString path = "", int nr = 0);
    ~ClickableWidget();
signals:
    void clicked();
protected:
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
private slots:
    void setLayoutClickableWidget(int nr, QFont Bohemian);
    void setStyleClickableWidget();
    void loadContentFromFile(QString path);
private:
    QLabel *titleLabel, *lineLabel, *pointsLabel, *multiLabel, *hammersLabel, *hammersIcon, *pickaxesLabel, *pickaxesIcon,
        *childrenLabel, *childrenIcon, *drillLabel, *drillIcon, *dynamiteLabel, *dynamiteIcon;
    QSpacerItem *hammersSpacer, *pickaxesSpacer, *childrenSpacer, *drillSpacer, *dynamiteSpacer;
    QHBoxLayout *pointsLayout, *multiLayout, *hammersLayout, *pickaxesLayout, *childrenLayout, *drillsLayout, *dynamiteLayout;
    QVBoxLayout *mainLayout;
    QString points, multi, ham, pick, ch, dr, dm;
};

#endif // CLICKABLEWIDGET_H
