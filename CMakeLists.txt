project(DbDatabaseTree)

set(HEADERS
    mymodel.h
)

set(SOURCES
    main.cpp
    mymodel.cpp
)

add_executable(databasetree ${HEADERS} ${SOURCES})

target_link_libraries(databasetree Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Sql)
