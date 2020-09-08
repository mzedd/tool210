#ifndef SCENEEDITORVIEW_H
#define SCENEEDITORVIEW_H

#include <QWidget>
#include <QComboBox>
#include "models/scenelistmodel.h"

class SceneEditorView : public QWidget
{
    Q_OBJECT
public:
    explicit SceneEditorView(QWidget *parent = nullptr);
    void setModel(SceneListModel *model);

private:
    QComboBox *sceneSelector;

    SceneListModel *model;
};

#endif // SCENEEDITORVIEW_H
