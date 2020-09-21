#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>

#include "models/demomodel.h"
#include "timelinecontroller.h"
#include "clipscreencontroller.h"
#include "clipinspectorcontroller.h"
#include "demofileaccessinterface.h"

class Q_DECL_EXPORT MainController : public QObject
{
    Q_OBJECT
public:
    explicit MainController(QObject *parent = nullptr);
    TimelineController *timelineController() const;
    ClipScreenController *clipsScreenController() const;
    ClipInspectorController *clipInspectorController() const;
    void setModel(DemoModel *model);
    void setDemoFileAccessor(DemoFileAccessInterface *demoFileAccessor);

private:
    TimelineController *timelineController_;
    ClipScreenController *clipScreenController_;
    ClipInspectorController *clipInspectorController_;
    DemoModel *model;

    DemoFileAccessInterface *demoFileAccessor;

public Q_SLOTS:
    void handleLoadDemo(QString filename);

private Q_SLOTS:
    void handleClipSelected(int id);
    void handlePlayPauseClicked();
    void handleTimeChanged(float time);
    void handleAddClip();
    void handleClipToRenderChanged(int id);

    void handleFrameFinishedAt(float time);
};

#endif // MAINCONTROLLER_H
