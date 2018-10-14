project(DbDatabaseTree)

set(HEADERS
    mymodel.h
)

set(SOURCES
    main.cpp
    mymodel.cpp
)

set(OTHER_FILES
    install.sql
)

add_executable(databasetree ${HEADERS} ${SOURCES} ${OTHER_FILES})

target_link_libraries(databasetree Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Sql)
