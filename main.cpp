#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QTreeView>

#include "mymodel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "myConnection");
    db.setHostName("localhost");
    db.setUserName("test");
    db.setPassword("test");
    db.setDatabaseName("test");
    if(!db.open())
    {
        qWarning() << db.lastError().text();
        return -1;
    }

    QTreeView view;
    view.setModel(new MyModel(db, &app));
    view.show();

    return app.exec();
}
