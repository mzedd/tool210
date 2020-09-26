#ifndef CLIPINSPECTORVIEW_H
#define CLIPINSPECTORVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QDataWidgetMapper>
#include <QTableView>
#include "models/clipinspectormodel.h"
#include "controllers/clipinspectorcontroller.h"

class ClipInspectorView : public QWidget
{
    Q_OBJECT
public:
    explicit ClipInspectorView(QWidget *parent = nullptr);
    void setModel(ClipInspectorModel *model);
    void setController(ClipInspectorController *controller);

    QSize sizeHint() const;

    QDataWidgetMapper *dataMapper;
    QTableView *tableView;

private:
    QLineEdit *clipNameLineEdit;
    QLineEdit *clipDurationLineEdit;
    QComboBox *sceneComboBox;

    ClipInspectorModel *model;
    ClipInspectorController *controller;
};

#endif // CLIPINSPECTORVIEW_H
