#include "vFileSelector.h"
#include "vFileSelectorPlugin.h"

#include <QtPlugin>

vFileSelectorPlugin::vFileSelectorPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void vFileSelectorPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool vFileSelectorPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *vFileSelectorPlugin::createWidget(QWidget *parent)
{
    return new vFileSelector(parent);
}

QString vFileSelectorPlugin::name() const
{
    return QLatin1String("vFileSelector");
}

QString vFileSelectorPlugin::group() const
{
    return QLatin1String("vrfEducation Widgets");
}

QIcon vFileSelectorPlugin::icon() const
{
    return QIcon();
}

QString vFileSelectorPlugin::toolTip() const
{
    return QLatin1String("This widget is used to select a file in your computer");
}

QString vFileSelectorPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool vFileSelectorPlugin::isContainer() const
{
    return false;
}

QString vFileSelectorPlugin::domXml() const
{
    return QLatin1String("<widget class=\"vFileSelector\" name=\"fileSelector\">\n</widget>\n");
}

QString vFileSelectorPlugin::includeFile() const
{
    return QLatin1String("vFileSelector.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(vFileSelectorPlugin, vFileSelectorPlugin)
#endif // QT_VERSION < 0x050000
