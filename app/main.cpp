#include <AFquick/AfGuiApplication>
#include <TrinnGui>
#include <QtGui/QIcon>

int main(int argc, char** argv)
{
    AFquick::GuiApplication app(argc, argv);
    app.setOrganizationName("Afide");
    app.setWindowIcon(QIcon(":/icon/af_base/af_logo.svg"));
    // TODO add company information

    app.setAFaccountFlag(true);
    app.addPlugin(TrinnPluginPtr::create());
    app.show();

    return app.exec();
}
