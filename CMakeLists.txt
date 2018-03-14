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
        front-end/expressions/ExprAccessor.cpp
        front-end/expressions/ExprValue.cpp
        front-end/expressions/ExprAffectation.cpp
        front-end/expressions/ExprMultiplicative.cpp
        front-end/declaration/DeclarationOfTab.cpp
        front-end/declaration/DeclarationOfVar.cpp
        front-end/function/BlockFunction.cpp
        front-end/expressions/ExprMultiplicative.cpp
        front-end/symbole-table/SymboleTable.cpp
        front-end/symbole-table/Symbole.cpp
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
target_link_libraries(MapleCompiler antlr4-runtime)