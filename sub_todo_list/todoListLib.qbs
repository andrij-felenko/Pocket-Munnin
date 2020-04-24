import qbs
import "../../../../templateQbs/templateLibS.qbs" as LibStaticT

LibStaticT {
    libraryName: "TodoList"
    version: "1.0.2"

    Depends { name: "quickAFlib" }

    files: filesList.concat([ "**/*.qml", "metadata.json" ])
}
