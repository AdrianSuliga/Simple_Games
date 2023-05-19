#include "choose_range.h"
#include "ui_choose_range.h"
#include "titlescreen.h"

Choose_Range::Choose_Range(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Choose_Range)
{
    ui->setupUi(this);
    setWindowTitle("Guessing Game");
}

Choose_Range::~Choose_Range()
{
    delete ui;
}

void Choose_Range::on_pushButton_clicked()
{
    TitleScreen *tl = new TitleScreen(nullptr);
    setAttribute(Qt::WA_DeleteOnClose);
    tl->show();
    close();
}

