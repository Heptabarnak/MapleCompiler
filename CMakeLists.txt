cmake_minimum_required(VERSION 3.9)
project(MapleCompiler)

LIST( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake )

# compiler must be 11 or 14
SET (CMAKE_CXX_STANDARD 14)


SET(FRONT_END_FOLDER ${PROJECT_SOURCE_DIR}/front-end)
SET(BACK_END_FOLDER ${PROJECT_SOURCE_DIR}/back-end)
SET(LIBS_FOLDER ${PROJECT_SOURCE_DIR}/libs)


#--------------------
#   ANTLR4 RUNTIME
#--------------------

# Set variable pointing to the antlr tool that supports C++
set(ANTLR4CPP_JAR_LOCATION ${LIBS_FOLDER}/antlr/antlr-4.7.1-complete.jar)
# Add external build for antlrcpp
include( ExternalAntlr4Cpp )
# Add antrl4cpp artifacts to project environment
include_directories( ${ANTLR4CPP_INCLUDE_DIRS} )
link_directories( ${ANTLR4CPP_LIBS} )

message(STATUS "Found antlr4cpp libs: ${ANTLR4CPP_LIBS} and includes: ${ANTLR4CPP_INCLUDE_DIRS} ")

#--------------------
#   MAPLE PARSER
#--------------------

include_directories(${FRONT_END_FOLDER})

set(ANTLR4_GENERATED_GRAMMAR_FILES
        ${FRONT_END_FOLDER}/maple-parser/MapleGrammarLexer.cpp
        ${FRONT_END_FOLDER}/maple-parser/MapleGrammarParser.cpp
        ${FRONT_END_FOLDER}/maple-parser/MapleGrammarVisitor.cpp)


#----------------
#   EXECUTABLE
#----------------

# add generated grammar to demo binary target
add_executable(MapleCompiler
        main.cpp
        ${ANTLR4_GENERATED_GRAMMAR_FILES}
        )
add_dependencies(MapleCompiler antlr4cpp)
target_link_libraries(MapleCompiler antlr4-runtime.a)