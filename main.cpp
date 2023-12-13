#include "parser.h"

#include <QApplication>
#include <sample.h>
#include <interface.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Parser parser;
    Sample sample(parser.graph);
    Interface interface(&sample);
    interface.show();
    getchar();
    return app.exec();

}
