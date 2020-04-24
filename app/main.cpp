#include <QtCore/QDir>
#include <QtGui/QGuiApplication>
#include <QDebug>
#include "id.h"
#include "crypt.h"
#include "guiApplicationAF.h"
#include "trinn.h"

int main(int argc, char** argv)
{
    qputenv("QT_AUTO_SCREEN_SCALE_FACTOR", "1");

    GuiApplicationAF::setApplicationName("Pocket Munnin");
    GuiApplicationAF::setOrganizationName("AF");
    GuiApplicationAF::setOrganizationDomain("andrij.felenko@gmail.com");

    GuiApplicationAF::setAttribute(Qt::AA_EnableHighDpiScaling); // HiDPI scaling
    GuiApplicationAF::setAttribute(Qt::AA_UseHighDpiPixmaps);    // HiDPI pixmaps

    GuiApplicationAF app(argc, argv);
    GuiApplicationAF::addLibraryPath(QDir::current().absolutePath());
    app.registratePlugin(new Trinn::TrinnPlugin(&app));

//    PluginHandler handler;
//    handler.parsePluginDirectory();

//    app.setWindowIcon(QIcon(":/LibDynamic/MunninIcons/pack0/raven_banner.svg"));
    app.setQuitOnLastWindowClosed(false);

    return app.exec();
}

// <div>Icons made by <a href="https://www.flaticon.com/authors/smashicons"
// title="Smashicons">Smashicons</a> from <a href="https://www.flaticon.com/"
// title="Flaticon">www.flaticon.com</a> is licensed by <a href="http://creativecommons.org/licenses/by/3.0/"
// title="Creative Commons BY 3.0" target="_blank">CC 3.0 BY</a></div>
