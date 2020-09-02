#ifndef CLIPINSPECTORCONTROLLER_H
#define CLIPINSPECTORCONTROLLER_H

#include <QObject>
#include "clipinspectormodel.h"

class Q_DECL_EXPORT ClipInspectorController : public QObject
{
    Q_OBJECT
public:
    explicit ClipInspectorController(QObject *parent = nullptr);
    void setModel(ClipInspectorModel *model);
    void setSelectedClip(Clip *clip);

private:
    ClipInspectorModel *model;

signals:

};

#endif // CLIPINSPECTORCONTROLLER_H
