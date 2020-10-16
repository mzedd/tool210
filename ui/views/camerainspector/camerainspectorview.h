#ifndef CAMERAINSPECTORVIEW_H
#define CAMERAINSPECTORVIEW_H

#include <QWidget>

namespace Ui {
class CameraInspectorView;
}

class CameraInspectorView : public QWidget
{
    Q_OBJECT

public:
    explicit CameraInspectorView(QWidget *parent = nullptr);
    ~CameraInspectorView();

private:
    Ui::CameraInspectorView *ui;
};

#endif // CAMERAINSPECTORVIEW_H
