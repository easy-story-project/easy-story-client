#include "storylineview.h"
#include "storylineviewplugin.h"

#include <QtPlugin>

StoryLineViewPlugin::StoryLineViewPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void StoryLineViewPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool StoryLineViewPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *StoryLineViewPlugin::createWidget(QWidget *parent)
{
    return new StoryLineView(parent);
}

QString StoryLineViewPlugin::name() const
{
    return QLatin1String("StoryLineView");
}

QString StoryLineViewPlugin::group() const
{
    return QLatin1String("tangxy");
}

QIcon StoryLineViewPlugin::icon() const
{
    return QIcon();
}

QString StoryLineViewPlugin::toolTip() const
{
    return QLatin1String("storyLine1");
}

QString StoryLineViewPlugin::whatsThis() const
{
    return QLatin1String("故事大纲编辑视图");
}

bool StoryLineViewPlugin::isContainer() const
{
    return true;
}

QString StoryLineViewPlugin::domXml() const
{
    return QLatin1String("<widget class=\"StoryLineView\" name=\"storyLineView\">\n</widget>\n");
}

QString StoryLineViewPlugin::includeFile() const
{
    return QLatin1String("storylineview.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(storylineviewplugin, StoryLineViewPlugin)
#endif // QT_VERSION < 0x050000
