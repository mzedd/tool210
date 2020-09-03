#include "clipinspectorview.h"
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLabel>

ClipInspectorView::ClipInspectorView(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QFormLayout *clipDataLayout = new QFormLayout;

    // heading
    mainLayout->addWidget(new QLabel("Clip Inspector"));

    // separator
    QFrame *line = new QFrame;
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    mainLayout->addWidget(line);

    // clip data form
    sceneComboBox = new QComboBox;
    clipNameLineEdit = new QLineEdit;
    clipDurationLineEdit = new QLineEdit("0");
    clipDataLayout->addRow(new QLabel("Name:"), clipNameLineEdit);
    clipDataLayout->addRow(new QLabel("Duration:"), clipDurationLineEdit);
    clipDataLayout->addRow(new QLabel("Scene:"), sceneComboBox);
    mainLayout->addLayout(clipDataLayout);

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
    connect(clipDurationLineEdit, &QLineEdit::textEdited, controller, &ClipInspectorController::selectedClipDurationEdited);
}

void ClipInspectorView::selectedClipChanged()
{
    clipNameLineEdit->setText(model->selectedClip()->getName());
    clipDurationLineEdit->setText(QString::number(model->selectedClip()->getDuration(), 'f', 1));
    update();
}

void ClipInspectorView::sceneListChanged()
{
    // set combobox text entrieo
    update();
}
