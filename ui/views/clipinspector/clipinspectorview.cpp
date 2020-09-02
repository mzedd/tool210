#include "clipinspectorview.h"
#include <QHBoxLayout>
#include <QLabel>

ClipInspectorView::ClipInspectorView(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *clipNameLayout = new QHBoxLayout;
    QHBoxLayout *sceneListLayout = new QHBoxLayout;

    // heading
    mainLayout->addWidget(new QLabel("Clip Inspector"));

    // separator
    QFrame *line = new QFrame;
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    mainLayout->addWidget(line);

    // clip name
    clipNameLineEdit = new QLineEdit;
    clipNameLayout->addWidget(new QLabel("Clip name"));
    clipNameLayout->addWidget(clipNameLineEdit);
    mainLayout->addLayout(clipNameLayout);

    // scene list
    sceneComboBox = new QComboBox;
    sceneListLayout->addWidget(new QLabel("Scene:"));
    sceneListLayout->addWidget(sceneComboBox);
    mainLayout->addLayout(sceneListLayout);

    // stretcher
    mainLayout->addStretch();

    setLayout(mainLayout);
}

void ClipInspectorView::setModel(ClipInspectorModel *model)
{
    this->model = model;

    connect(model, &ClipInspectorModel::selectedClipChanged, this, &ClipInspectorView::selectedClipChanged);
}

void ClipInspectorView::setController(ClipInspectorController *controller)
{
    this->controller = controller;

    connect(clipNameLineEdit, &QLineEdit::textEdited, controller, &ClipInspectorController::selectedClipNameEdited);
}

void ClipInspectorView::selectedClipChanged()
{
    clipNameLineEdit->setText(model->selectedClip()->getName());
    update();
}

void ClipInspectorView::sceneListChanged()
{
    // set combobox text entrieo
    update();
}
