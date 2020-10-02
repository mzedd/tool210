#include "clipinspectorview.h"
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLabel>

#include "cliplistmodel.h"
#include "scenelistmodel.h"

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

    dataMapper = new QDataWidgetMapper(this);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    connect(clipNameLineEdit, &QLineEdit::editingFinished, dataMapper, &QDataWidgetMapper::submit);
    connect(clipDurationLineEdit, &QLineEdit::editingFinished, dataMapper, &QDataWidgetMapper::submit);
    connect(sceneComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), dataMapper, &QDataWidgetMapper::submit);

    mainLayout->addStretch();
    setLayout(mainLayout);
}

void ClipInspectorView::setClipListModel(ClipListModel *clipListModel)
{
    dataMapper->setModel(clipListModel);

    dataMapper->addMapping(clipNameLineEdit, 0);
    dataMapper->addMapping(clipDurationLineEdit, 1);
    dataMapper->addMapping(sceneComboBox, 2, "currentIndex");
}

void ClipInspectorView::setSceneListModel(SceneListModel *sceneListModel)
{
    sceneComboBox->setModel(sceneListModel);
}

QSize ClipInspectorView::sizeHint() const
{
    return QSize(500, 200);
}
