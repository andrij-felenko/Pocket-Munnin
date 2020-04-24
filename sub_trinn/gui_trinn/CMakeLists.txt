cmake_minimum_required(VERSION 3.14)
project(plug_trinn VERSION 0.0.1)

set (trinn_h
    include/trinn.h
    include/trinnEnum.h
    include/login/crypt_Copy.h
    include/login/loginDatas.h
    include/login/me.h
    include/old/dataHandler.h
    include/old/dataModel.h
    include/old/dataStream.h
    include/old/lastCurrency.h
    include/old/listTemplate.h
    include/old/metadata.json
    include/old/moneyAccounting.h
    include/subject/bankCard.h
    include/subject/object.h
    include/subject/subject.h
    include/transaction/baseTransaction.h
    include/transaction/income.h
    include/transaction/magnet.h
    include/transaction/plan.h
    include/transaction/spend.h
    include/transaction/transfer.h
    include/type/base.h
    include/type/category.h
    include/type/project.h
    include/trinnStorage.h
    )

set (trinn_cpp
    src/trinn.cpp
    src/login/crypt_Copy.cpp
    src/login/loginDatas.cpp
    src/login/me.cpp
    src/old/dataHandler.cpp
    src/old/dataModel.cpp
    src/old/dataStream.cpp
    src/old/lastCurrency.cpp
    src/old/moneyAccounting.cpp
    src/subject/bankCard.cpp
    src/subject/object.cpp
    src/subject/subject.cpp
    src/transaction/baseTransaction.cpp
    src/transaction/income.cpp
    src/transaction/magnet.cpp
    src/transaction/plan.cpp
    src/transaction/spend.cpp
    src/transaction/transfer.cpp
    src/type/base.cpp
    src/type/category.cpp
    src/type/project.cpp
    src/trinnStorage.cpp
    )

set (CMAKE_AUTORCC)
find_package(Qt5Core)
find_package(Qt5Qml)
find_package(Qt5Quick)

add_library(plug_trinn SHARED ${trinn_h} ${trinn_cpp})

set_target_properties(plug_trinn PROPERTIES PREFIX "plug_" OUTPUT_NAME "trinn")
target_include_directories(plug_trinn PUBLIC include
    PUBLIC $<TARGET_PROPERTY:lib_quickAF,INTERFACE_INCLUDE_DIRECTORIES>
    PUBLIC $<TARGET_PROPERTY:lib_currencyAF,INTERFACE_INCLUDE_DIRECTORIES>)
target_link_libraries(plug_trinn lib_baseAF lib_quickAF lib_currencyAF Qt5::Core Qt5::Quick Qt5::Qml)
