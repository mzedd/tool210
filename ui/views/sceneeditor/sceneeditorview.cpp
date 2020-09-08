#include "sceneeditorview.h"

SceneEditorView::SceneEditorView(QWidget *parent) :
    QWidget(parent),
    model(nullptr)
{
    sceneSelector = new QComboBox(this);
}

void SceneEditorView::setModel(SceneListModel *model)
{
    this->model = model;
    sceneSelector->setModel(model);
}
