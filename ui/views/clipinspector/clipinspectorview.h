#ifndef CLIPINSPECTORVIEW_H
#define CLIPINSPECTORVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QDataWidgetMapper>

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

private:
    QLineEdit *clipNameLineEdit;
    QLineEdit *clipDurationLineEdit;
    QComboBox *sceneComboBox;

};

#endif // CLIPINSPECTORVIEW_H
