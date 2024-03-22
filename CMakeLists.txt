cmake_minimum_required(VERSION 3.10)
project(intro_allegro C)

set(CMAKE_C_STANDARD 99)

add_executable(HELLO Hello_allegro/main_hello.c)
add_executable(TP0 TP0/TP_0.c)
add_executable(TP1 TP1/TP_1.c)
add_executable(TP2 TP2/groupe1.c)


IF(WIN32)
    target_link_libraries(HELLO -lmingw32 -lallegro-5.0.10-monolith-md-debug)
ELSE()
    INCLUDE_DIRECTORIES(/usr/local/Cellar/allegro/5.2.9.1/include)
    LINK_DIRECTORIES(/usr/local/Cellar/allegro/5.2.9.1/lib)
    file(GLOB LIBRARIES "/usr/local/Cellar/allegro/5.2.9.1/lib/*.dylib")
    message("LIBRARIES = ${LIBRARIES}")
    message("LIBRARIES = ${LIBRARIES}")
    TARGET_LINK_LIBRARIES(HELLO ${LIBRARIES})
    TARGET_LINK_LIBRARIES(TP0 ${LIBRARIES})
    TARGET_LINK_LIBRARIES(TP1 ${LIBRARIES})
    TARGET_LINK_LIBRARIES(TP2 ${LIBRARIES})
ENDIF(WIN32)