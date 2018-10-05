# DbDatabaseTree
A simple test to load tree items from database (on expanding).

[![Build Status](https://travis-ci.org/0xFEEDC0DE64/DbDatabaseTree.svg?branch=master)](https://travis-ci.org/0xFEEDC0DE64/DbDatabaseTree) [![Codacy Badge](https://api.codacy.com/project/badge/Grade/ffdd86f49c834a63a54ebd2b9519499e)](https://www.codacy.com/app/0xFEEDC0DE64/DbDatabaseTree?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=0xFEEDC0DE64/DbDatabaseTree&amp;utm_campaign=Badge_Grade)

![Screenshot of database and QTreeView](https://raw.githubusercontent.com/0xFEEDC0DE64/DbDatabaseTree/master/screenshot.png)

## Building from source
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
