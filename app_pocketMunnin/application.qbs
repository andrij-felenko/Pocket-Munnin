import qbs 
import "../../../qbs/app.qbs" as App

App {
    projectName: "pocket_munnin"

    cpp.includePaths: "../../**"

    Depends { name: "lib_baseAF" }
    Depends { name: "lib_quickAF" }
    Depends { name: "Trinn" }
}
