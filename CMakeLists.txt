cmake_minimum_required(VERSION 3.26)
project(assessment_cplus_23_24_gunwunbun)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)
include_directories(src/game)
include_directories(src/persistence)
include_directories(src/ui)

file(GLOB_RECURSE SOURCES src/*.cc src/*.h planetexpress.db)
add_executable(assessment_cplus_23_24_gunwunbun ${SOURCES}
        src/game/game_state.h
        src/game/enums/sub_game_state.h
        src/persistence/data_handler.h
        src/game/data_models/encounter_model.h
        src/game/data_models/consequence_type.h
        src/game/data_models/consequence.h
        src/game/encounters/encounter_generator.h)

configure_file(planetexpress.db ${CMAKE_BINARY_DIR}/planetexpress.db COPYONLY)

find_package(SQLite3 REQUIRED)
target_link_libraries(${PROJECT_NAME} SQLite::SQLite3)