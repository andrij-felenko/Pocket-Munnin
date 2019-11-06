#include "old/dataHandler.h"

using namespace Trinn;
DataHandler* DataHandler::m_dataHandler = nullptr;

DataHandler::DataHandler(QObject *parent) : QObject(parent)
{
    //
}

const DataHandler *DataHandler::dataHandler()
{
    DataHandler::init();
    return m_dataHandler;
}

void DataHandler::init()
{
    if (m_dataHandler)
        return;

    m_dataHandler = new DataHandler;
}
