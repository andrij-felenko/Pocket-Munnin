import qbs
import "../../../qbs/plugin.qbs" as PluginTemplate

PluginTemplate {
    moduleName: "CurrencyHandler"
    version: "1.0.2"

    Depends { name: "lib_quickAF" }

    files: filesList.concat([ "**/*.qml", "metadata.json" ])
}
