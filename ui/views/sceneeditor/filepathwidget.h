#ifndef FILEPATHWIDGET_H
#define FILEPATHWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class FilepathWidget : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(QString filepath READ filepath WRITE setFilepath NOTIFY filepathChanged USER true)

public:
    explicit FilepathWidget(QWidget *parent = nullptr);

    QString filepath() const;
    void setFilepath(const QString &filepath);

private:
    QLabel *filepathLabel;
    QPushButton *openFileDialogButton;

    QString filepath_;

Q_SIGNALS:
    void filepathChanged();

private Q_SLOTS:
    void openFileDialog();
};

#endif // FILEPATHWIDGET_H
