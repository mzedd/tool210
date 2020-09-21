#include "demomodel.h"

DemoModel::DemoModel(QObject *parent) :
    QAbstractItemModel(parent),
    demo_(nullptr)
{

}

DemoModel::~DemoModel()
{
    delete demo_;
}

Demo *DemoModel::demo() const
{
    return demo_;
}

void DemoModel::setDemo(Demo *demo)
{
    this->demo_ = demo;
}

void DemoModel::addClip()
{
    demo_->addClip();
    emit clipAdded(demo_->clipList().size()-1);
}

void DemoModel::addScene()
{
    demo_->addScene();
    emit sceneAdded();
}

void DemoModel::checkClipToBeRenderdChangedAt(float time)
{
    emit clipToRenderChanged(demo_->clipIdAt(time));
}

QModelIndex DemoModel::index(int /*row*/, int /*column*/, const QModelIndex &/*parent*/) const
{
    return QModelIndex();
}

QModelIndex DemoModel::parent(const QModelIndex &/*child*/) const
{
    return QModelIndex();
}

int DemoModel::rowCount(const QModelIndex &/*parent*/) const
{
    return 0;
}

int DemoModel::columnCount(const QModelIndex &/*parent*/) const
{
    return 0;
}

QVariant DemoModel::data(const QModelIndex &/*index*/, int /*role*/) const
{
    return QVariant();
}
