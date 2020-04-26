#include <AFquick/AfGuiApplication>
#include <TrinnGui>
#include <QIcon>
#include <QDir>

int main(int argc, char** argv)
{
    AFquick::GuiApplication app(argc, argv);
    app.setOrganizationName("Afide");
    app.setWindowIcon(QIcon(":/icon/af_base/af_logo_migo_light.svg"));
    // TODO add company information

    app.setAFaccountFlag(true);
    app.addPlugin(TrinnPluginPtr::create());
    app.show();

    return app.exec();
}
