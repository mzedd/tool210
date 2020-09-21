#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>

#include "timelinecontroller.h"
#include "clipscreencontroller.h"
#include "clipinspectorcontroller.h"
#include "Demo.h"
#include "demofileaccessinterface.h"

class Q_DECL_EXPORT MainController : public QObject
{
    Q_OBJECT
public:
    explicit MainController(QObject *parent = nullptr);
    TimelineController *timelineController() const;
    ClipScreenController *clipsScreenController() const;
    ClipInspectorController *clipInspectorController() const;
    void setModel(Demo *demo);
    void setDemoFileAccessor(DemoFileAccessInterface *demoFileAccessor);

private:
    TimelineController *timelineController_;
    ClipScreenController *clipScreenController_;
    ClipInspectorController *clipInspectorController_;
    Demo *demo;

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
