# DbDatabaseTree
A simple test to load tree items from database (on expanding).

![Screenshot of database and QTreeView](https://raw.githubusercontent.com/0xFEEDC0DE64/DbDatabaseTree/master/screenshot.png)

# Building from source
This project can only be built as part of the project structure [DbSoftware](https://github.com/0xFEEDC0DE64/DbSoftware)

```Shell
git clone https://github.com/0xFEEDC0DE64/DbSoftware.git
cd DbSoftware
git submodule update --init --recursive DbDatabaseTree
cd ..
mkdir build_DbSoftware
cd build_DbSoftware
qmake CONFIG+=ccache ../DbSoftware
make -j$(nproc) sub-DbDatabaseTree
make sub-DbDatabaseTree-install_subtargets
./bin/databasetree
```
