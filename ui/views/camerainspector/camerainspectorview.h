#ifndef CAMERAINSPECTORVIEW_H
#define CAMERAINSPECTORVIEW_H

#include <QWidget>
#include "camerainspectorviewmodel.h"
#include "views/view.h"
#include "interactors/camerainspectorinputboundary.h"

namespace Ui {
class CameraInspectorView;
}

class CameraInspectorView : public QWidget, public View
{
    Q_OBJECT

public:
    explicit CameraInspectorView(QWidget *parent = nullptr);
    ~CameraInspectorView();

    void update();
    void setViewModel(CameraInspectorViewModel *viewModel);
    void setInputBoundary(CameraInspectorInputBoundary *inputBoundary);

private:
    Tool210::Entities::Point fromQVector3D(QVector3D vector);

    Ui::CameraInspectorView *ui;
    CameraInspectorViewModel* viewModel;
    CameraInspectorInputBoundary *inputBoundary;

public slots:
    void editingFinished();
};

#endif // CAMERAINSPECTORVIEW_H
