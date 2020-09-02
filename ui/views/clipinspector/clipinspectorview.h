#ifndef CLIPINSPECTORVIEW_H
#define CLIPINSPECTORVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>

class ClipInspectorView : public QWidget
{
    Q_OBJECT
public:
    explicit ClipInspectorView(QWidget *parent = nullptr);

private:
    QLabel *clipNameLabel;
    QComboBox *sceneComboBox;
};

#endif // CLIPINSPECTORVIEW_H
