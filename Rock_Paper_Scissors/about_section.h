#ifndef ABOUT_SECTION_H
#define ABOUT_SECTION_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QBoxLayout>
#include <QSpacerItem>

namespace Ui {
class About_Section;
}

class About_Section : public QDialog
{
    Q_OBJECT

public:
    explicit About_Section(QWidget *parent = nullptr);
    ~About_Section();

private slots:
    void setLayoutForAboutSection();
    void setStylesForAboutSection();

private:
    Ui::About_Section *ui;
    QLabel *titleLabel, *infoLabel;
    QPushButton *okButton;
    QSpacerItem *leftSpacer, *rightSpacer;

    QHBoxLayout *buttonLayout;
    QVBoxLayout *mainLayout;
};

#endif // ABOUT_SECTION_H
