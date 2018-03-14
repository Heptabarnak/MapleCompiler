cmake_minimum_required(VERSION 3.5)
project(MapleCompiler)

LIST(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# compiler must be 11 or 14
SET(CMAKE_CXX_STANDARD 14)


SET(FRONT_END_FOLDER ${PROJECT_SOURCE_DIR}/front-end)
SET(BACK_END_FOLDER ${PROJECT_SOURCE_DIR}/back-end)
SET(LIBS_FOLDER ${PROJECT_SOURCE_DIR}/libs)


include_directories(utils)


#--------------------
#   ANTLR4 RUNTIME
#--------------------

# Set variable pointing to the antlr tool that supports C++
set(ANTLR4CPP_JAR_LOCATION ${LIBS_FOLDER}/antlr/antlr-4.7.1-complete.jar)
# Add external build for antlrcpp
include(ExternalAntlr4Cpp)
# Add antrl4cpp artifacts to project environment
include_directories(${ANTLR4CPP_INCLUDE_DIRS})
link_directories(${ANTLR4CPP_LIBS})

message(STATUS "Found antlr4cpp libs: ${ANTLR4CPP_LIBS} and includes: ${ANTLR4CPP_INCLUDE_DIRS} ")

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
        front-end/expressions/ExprAccessor.cpp
        front-end/expressions/ExprValue.cpp
        front-end/expressions/ExprAffectation.cpp
        front-end/expressions/ExprMultiplicative.cpp
        front-end/symbole-table/SymboleTable.cpp
        front-end/symbole-table/Symbole.cpp)
        front-end/expressions/ExprMultiplicative.cpp
        front-end/expressions/ExprParenthesis.cpp
        front-end/expressions/unary/ExprPrefixUnary.cpp
        front-end/expressions/unary/ExprPostfixUnary.cpp
        front-end/expressions/Operation/ExprEqualityComparaisonOperation.cpp
        front-end/expressions/Operation/ExprRelationalComparaisonOperation.cpp
        front-end/expressions/Operation/ExprAdditiveOperation.cpp
        front-end/expressions/Operation/ExprMultiplicativeOperation.cpp
        front-end/expressions/Operation/ExprAndOperation.cpp
        front-end/expressions/Operation/ExprOrOperation.cpp
        front-end/expressions/Operation/Binary/ExprBinaryAndOperation.cpp
        front-end/expressions/Operation/Binary/ExprBinaryXorOperation.cpp
        front-end/expressions/Operation/Binary/ExprBinaryOrOperation.cpp
        front-end/expressions/Operation/Binary/ExprBinaryShiftOperation.cpp
        front-end/Variable/VarAccessor.cpp
        front-end/Variable/VarDeclaration.cpp
        front-end/Array/TabAccessor.cpp
        front-end/Array/TabDeclaration.cpp
        front-end/Array/Tab.cpp
        front-end/Array/ItemTab.cpp)


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
add_dependencies(MapleCompiler antlr4cpp)
target_link_libraries(MapleCompiler antlr4-runtime.a)