#include "parser.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    TParser parser;
//    TSample sample(&parser);
//    TInterface interface(&sample);
//    interface.show();
    return app.exec();
}
