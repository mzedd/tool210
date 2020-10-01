#include "sceneeditorview.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLabel>

SceneEditorView::SceneEditorView(QWidget *parent) :
    QWidget(parent),
    model(nullptr)
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *selectAndAddLayout = new QHBoxLayout;
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
    addSceneButton = new QPushButton("+");
    selectAndAddLayout->addWidget(sceneSelector);
    selectAndAddLayout->addWidget(addSceneButton);
    mainLayout->addLayout(selectAndAddLayout);

    // scene data form
    sceneNameLineEdit = new QLineEdit;
    filepathWidget = new FilepathWidget();
    sceneDataLayout->addRow(new QLabel("Name:"), sceneNameLineEdit);
    sceneDataLayout->addRow(new QLabel("filepath:"), filepathWidget);
    mainLayout->addLayout(sceneDataLayout);

    mainLayout->addStretch();
    setLayout(mainLayout);

    dataMapper = new QDataWidgetMapper(this);
    connect(sceneSelector, QOverload<int>::of(&QComboBox::currentIndexChanged), dataMapper, &QDataWidgetMapper::setCurrentIndex);
    connect(addSceneButton, &QPushButton::clicked, this, &SceneEditorView::handleAddScene);

    // using manual submit because we use our custom filepath widget
    dataMapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    connect(sceneNameLineEdit, &QLineEdit::editingFinished, dataMapper, &QDataWidgetMapper::submit);
    connect(filepathWidget, &FilepathWidget::filepathChanged, dataMapper, &QDataWidgetMapper::submit);
}

void SceneEditorView::setModel(SceneListModel *model)
{
    this->model = model;
    sceneSelector->setModel(model);
    dataMapper->setModel(model);

    dataMapper->addMapping(sceneNameLineEdit, 0);
    //dataMapper->addMapping(sceneShaderFilepath, 1);
    dataMapper->addMapping(filepathWidget, 1);
}

void SceneEditorView::handleAddScene()
{
    model->insertRow(0);
    sceneSelector->setCurrentIndex(model->rowCount()-1);
    dataMapper->toLast();
}
