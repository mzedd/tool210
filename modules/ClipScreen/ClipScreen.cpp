#include "ClipScreen.h"
#include "ui_ClipScreen.h"

ClipScreen::ClipScreen(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::ClipScreen)
{
    ui->setupUi(this);
}

ClipScreen::~ClipScreen()
{
    delete ui;
}
