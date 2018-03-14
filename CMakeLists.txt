cmake_minimum_required(VERSION 3.5)
project(MapleCompiler)

# compiler must be 11 or 14
SET(CMAKE_CXX_STANDARD 14)


SET(FRONT_END_FOLDER ${PROJECT_SOURCE_DIR}/front-end)
SET(BACK_END_FOLDER ${PROJECT_SOURCE_DIR}/back-end)
SET(LIBS_FOLDER ${PROJECT_SOURCE_DIR}/libs)


include_directories(utils)


#--------------------
#   ANTLR4 RUNTIME
#--------------------

add_library(antlr4-runtime STATIC IMPORTED) # or STATIC instead of SHARED
set_target_properties(antlr4-runtime PROPERTIES
        IMPORTED_LOCATION "${LIBS_FOLDER}/libantlr4-runtime.a"
        INTERFACE_INCLUDE_DIRECTORIES "${FRONT_END_FOLDER}/include/antlr"
        )

#--------------------
#   MAPLE PARSER
#--------------------

include_directories(${FRONT_END_FOLDER})

set(ANTLR4_GENERATED_GRAMMAR_FILES
        ${FRONT_END_FOLDER}/maple-parser/MapleGrammarLexer.cpp
        ${FRONT_END_FOLDER}/maple-parser/MapleGrammarParser.cpp
        ${FRONT_END_FOLDER}/maple-parser/MapleGrammarVisitor.cpp
        ${FRONT_END_FOLDER}/maple-parser/MapleGrammarBaseVisitor.cpp)

#---------------
#   FRONT-END
#---------------

set(VISITORS_FILES
        front-end/StartVisitor.cpp
        front-end/accessor/Accessor.cpp
        front-end/expressions/ExprValue.cpp
        front-end/expressions/ExprAffectation.cpp
        front-end/expressions/ExprMultiplicative.cpp)


#----------------
#   EXECUTABLE
#----------------

# add generated grammar to demo binary target
add_executable(MapleCompiler
        main.cpp
        utils/str2int.h
        ${ANTLR4_GENERATED_GRAMMAR_FILES}
        ${VISITORS_FILES}
        )
target_link_libraries(MapleCompiler antlr4-runtime)