#include "filepathwidget.h"
#include <QHBoxLayout>
#include <QFileDialog>
#include <QDebug>

FilepathWidget::FilepathWidget(QWidget *parent) :
    QWidget(parent),
    filepathLabel(new QLabel("Moin", this)),
    openFileDialogButton(new QPushButton("file", this))
{
    int btnHeight = filepathLabel->height();
    openFileDialogButton->setFixedSize(btnHeight, btnHeight);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(filepathLabel);
    layout->addWidget(openFileDialogButton);
    setLayout(layout);

    connect(openFileDialogButton, &QPushButton::clicked, this, &FilepathWidget::openFileDialog);
}

QString FilepathWidget::filepath() const
{
    qDebug() << "is read";
    return filepath_;
}

void FilepathWidget::setFilepath(const QString &filepath)
{
    filepath_ = filepath;
    filepathLabel->setText(filepath_);
}

void FilepathWidget::openFileDialog()
{
    setFilepath(QFileDialog::getOpenFileName(this, tr("Select fragment shader file"), ".", tr("Fragment shader (*.frag)")));
        emit filepathChanged();
}
