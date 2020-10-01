#ifndef SCENEEDITORVIEW_H
#define SCENEEDITORVIEW_H

#include <QWidget>
#include <QComboBox>
#include <QDataWidgetMapper>
#include <QLineEdit>
#include "filepathwidget.h"
#include "models/scenelistmodel.h"

class SceneEditorView : public QWidget
{
    Q_OBJECT
public:
    explicit SceneEditorView(QWidget *parent = nullptr);
    void setModel(SceneListModel *model);

private:
    QDataWidgetMapper *dataMapper;
    QComboBox *sceneSelector;
    QLineEdit *sceneNameLineEdit;
    QLineEdit *sceneShaderFilepath;
    FilepathWidget *filepathWidget;

    SceneListModel *model;
};

#endif // SCENEEDITORVIEW_H
