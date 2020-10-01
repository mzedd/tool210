#include "sceneeditorview.h"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>

SceneEditorView::SceneEditorView(QWidget *parent) :
    QWidget(parent),
    model(nullptr)
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QFormLayout *sceneDataLayout = new QFormLayout;

    // heading
    mainLayout->addWidget(new QLabel("Scene Inspector"));

    // separator
    QFrame *line = new QFrame;
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    mainLayout->addWidget(line);

    // scene selector
    sceneSelector = new QComboBox;
    mainLayout->addWidget(sceneSelector);

    // scene data form
    sceneNameLineEdit = new QLineEdit;
    sceneShaderFilepath = new QLineEdit("-");
    sceneDataLayout->addRow(new QLabel("Name:"), sceneNameLineEdit);
    sceneDataLayout->addRow(new QLabel("Shader filename:"), sceneShaderFilepath);
    mainLayout->addLayout(sceneDataLayout);

    mainLayout->addStretch();
    setLayout(mainLayout);

    dataMapper = new QDataWidgetMapper(this);
    connect(sceneSelector, QOverload<int>::of(&QComboBox::currentIndexChanged), dataMapper, &QDataWidgetMapper::setCurrentIndex);
}

void SceneEditorView::setModel(SceneListModel *model)
{
    this->model = model;
    sceneSelector->setModel(model);
    dataMapper->setModel(model);

    dataMapper->addMapping(sceneNameLineEdit, 0);
    dataMapper->addMapping(sceneShaderFilepath, 1);

    sceneSelector->setCurrentIndex(0);
    dataMapper->toFirst();
}
