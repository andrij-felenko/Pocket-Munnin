import qbs

Project {
    name: "pocket_munnin"

    SubProject { filePath: "plug_currencyHandler/plug_currencyHandler.qbs" }
    SubProject { filePath: "plug_todoList/plug_todoList.qbs" }
    SubProject { filePath: "plug_trinn/plug_trinn.qbs" }

    references: [
        "app_pocketMunnin/application.qbs"
    ]
}
