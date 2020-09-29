#ifndef CLIPINSPECTORVIEW_H
#define CLIPINSPECTORVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QDataWidgetMapper>
#include <QTableView>

class ClipListModel;
class SceneListModel;

class ClipInspectorView : public QWidget
{
    Q_OBJECT
public:
    explicit ClipInspectorView(QWidget *parent = nullptr);
    void setClipListModel(ClipListModel *clipListModel);
    void setSceneListModel(SceneListModel *sceneListModel);

    QSize sizeHint() const;

    QDataWidgetMapper *dataMapper;
    QTableView *tableView;

private:
    QLineEdit *clipNameLineEdit;
    QLineEdit *clipDurationLineEdit;
    QComboBox *sceneComboBox;

};

#endif // CLIPINSPECTORVIEW_H
