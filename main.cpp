#include "parser.h"

#include <QApplication>
#include <sample.h>
#include <interface.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Parser parser;
    if(!parser.error) {
        Sample sample(parser.graph);
        Interface interface(&sample);
        interface.show();
    }else{
        Interface interface(parser.error);
        interface.show();
    }

    return app.exec();
}
