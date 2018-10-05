# DbDatabaseTree
DbDatabaseTree git module for use in DbSoftware (https://github.com/0xFEEDC0DE64/DbSoftware)

# Building from source
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
