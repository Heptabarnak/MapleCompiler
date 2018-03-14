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

include_directories(${FRONT_END_FOLDER}/src)

set(ANTLR4_GENERATED_GRAMMAR_FILES
        front-end/src/maple-parser/MapleGrammarLexer.cpp
        front-end/src/maple-parser/MapleGrammarParser.cpp
        front-end/src/maple-parser/MapleGrammarVisitor.cpp
        front-end/src/maple-parser/MapleGrammarBaseVisitor.cpp)

#---------------
#   FRONT-END
#---------------

set(AST_SRC_FILES
        front-end/src/accessor/FunctionAccessor.cpp
        front-end/src/accessor/LeftValueAccessor.cpp
        front-end/src/accessor/LeftValueTab.cpp
        front-end/src/accessor/LeftValueVar.cpp
        front-end/src/array/TabAccessor.cpp
        front-end/src/array/TabDeclaration.cpp
        front-end/src/axiome/ProgramDeclaration.cpp
        front-end/src/axiome/ProgramFunction.cpp
        front-end/src/axiome/Start.cpp
        front-end/src/control-structure/ElseStatement.cpp
        front-end/src/control-structure/IfStatementInstruction.cpp
        front-end/src/control-structure/Statement.cpp
        front-end/src/control-structure/StatementInstruction.cpp
        front-end/src/declaration/DeclarationOfTab.cpp
        front-end/src/declaration/DeclarationOfVar.cpp
        front-end/src/expressions/ExprAccessor.cpp
        front-end/src/expressions/ExprAffectation.cpp
        front-end/src/expressions/ExprMultiplicative.cpp
        front-end/src/expressions/ExprParenthesis.cpp
        front-end/src/expressions/ExprValue.cpp
        front-end/src/expressions/Operation/Binary/ExprBinaryAndOperation.cpp
        front-end/src/expressions/Operation/Binary/ExprBinaryOrOperation.cpp
        front-end/src/expressions/Operation/Binary/ExprBinaryShiftOperation.cpp
        front-end/src/expressions/Operation/Binary/ExprBinaryXorOperation.cpp
        front-end/src/expressions/Operation/ExprAdditiveOperation.cpp
        front-end/src/expressions/Operation/ExprAndOperation.cpp
        front-end/src/expressions/Operation/ExprEqualityComparaisonOperation.cpp
        front-end/src/expressions/Operation/ExprMultiplicativeOperation.cpp
        front-end/src/expressions/Operation/ExprOrOperation.cpp
        front-end/src/expressions/Operation/ExprRelationalComparaisonOperation.cpp
        front-end/src/expressions/unary/ExprPostfixUnary.cpp
        front-end/src/expressions/unary/ExprPrefixUnary.cpp
        front-end/src/expressions/Value.cpp
        front-end/src/function/AccessorFunction.cpp
        front-end/src/function/BlockFunction.cpp
        front-end/src/function/FunctionDefinition.cpp
        front-end/src/function/FunctionParam.cpp
        front-end/src/StartVisitor.cpp
        front-end/src/symbol-table/Symbol.cpp
        front-end/src/symbol-table/SymbolTable.cpp
        front-end/src/variable/VarAccessor.cpp
        front-end/src/variable/VarDeclaration.cpp
        )
#-----------
#   UTILS
#-----------

set(UTILS_SRC_FILES utils/str2int.h)

#----------------
#   EXECUTABLE
#----------------

# add generated grammar to demo binary target
add_executable(MapleCompiler
        main.cpp
        ${UTILS_SRC_FILES}
        ${ANTLR4_GENERATED_GRAMMAR_FILES}
        ${AST_SRC_FILES}
        )
target_link_libraries(MapleCompiler antlr4-runtime)