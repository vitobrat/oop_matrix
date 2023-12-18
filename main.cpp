#include "parser.h"

#include <QApplication>
#include "derivesample.h"
#include "interface.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Parser parser;
    DeriveSample sample(parser.graph);
    Interface interface(&sample);
    interface.show();
    getchar();
    return app.exec();

}
