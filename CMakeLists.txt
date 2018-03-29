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

set(ANTLR4_GENERATED_GRAMMAR_FILES
        front-end/src/maple-parser/MapleGrammarLexer.cpp
        front-end/src/maple-parser/MapleGrammarParser.cpp
        front-end/src/maple-parser/MapleGrammarVisitor.cpp
        )

#-----------
#   UTILS
#-----------

set(UTILS_SRC_FILES
        utils/str2int.h
        utils/mapContext2Vector.h
        utils/typeHelper.cpp
        utils/printDebugInfo.cpp
        utils/parseConfig.h
        )

#---------------
#   FRONT-END
#---------------

include_directories(${FRONT_END_FOLDER}/src)

set(AST_SRC_FILES
        front-end/src/declaration/Declaration.h
        front-end/src/expression/Expr.h
        front-end/src/expression/operation/binary/ExprBinaryOperation.h
        front-end/src/expression/operation/ExprOperation.h
        front-end/src/expression/unary/ExprUnary.h

        front-end/src/accessor/FunctionAccessor.cpp
        front-end/src/accessor/LeftValueTab.cpp
        front-end/src/accessor/LeftValueVar.cpp
        front-end/src/accessor/LeftValueAccessor.cpp
        front-end/src/array/TabAccessor.cpp
        front-end/src/array/TabDeclaration.cpp
        front-end/src/axiom/Start.cpp
        front-end/src/control-structure/Block.cpp
        front-end/src/control-structure/IfStatement.cpp
        front-end/src/control-structure/ReturnStatement.cpp
        front-end/src/control-structure/Statement.cpp
        front-end/src/control-structure/WhileStatement.cpp
        front-end/src/expression/ExprAccessor.cpp
        front-end/src/expression/ExprAffectation.cpp
        front-end/src/expression/ExprIncrement.cpp
        front-end/src/expression/ExprParenthesis.cpp
        front-end/src/expression/ExprValue.cpp
        front-end/src/expression/operation/binary/ExprBinaryAndOperation.cpp
        front-end/src/expression/operation/binary/ExprBinaryOrOperation.cpp
        front-end/src/expression/operation/binary/ExprBinaryShiftOperation.cpp
        front-end/src/expression/operation/binary/ExprBinaryXorOperation.cpp
        front-end/src/expression/operation/ExprAdditiveOperation.cpp
        front-end/src/expression/operation/ExprAndOperation.cpp
        front-end/src/expression/operation/ExprEqualityComparisonOperation.cpp
        front-end/src/expression/operation/ExprMultiplicativeOperation.cpp
        front-end/src/expression/operation/ExprOrOperation.cpp
        front-end/src/expression/operation/ExprRelationalComparisonOperation.cpp
        front-end/src/expression/unary/ExprPrefixUnary.cpp
        front-end/src/expression/Value.cpp
        front-end/src/function/AccessorFunction.cpp
        front-end/src/function/BlockFunction.cpp
        front-end/src/function/FunctionDefinition.cpp
        front-end/src/function/FunctionParam.cpp
        front-end/src/symbol-table/Symbol.cpp
        front-end/src/symbol-table/SymbolTable.cpp
        front-end/src/variable/VarAccessor.cpp
        front-end/src/variable/VarDeclaration.cpp
        front-end/src/visitor/StartVisitor.cpp
        front-end/src/visitor/VisitorAccessor.cpp
        front-end/src/visitor/VisitorDeclaration.cpp
        front-end/src/visitor/VisitorExpr.cpp
        front-end/src/visitor/VisitorFunction.cpp
        front-end/src/visitor/VisitorInstruction.cpp
        front-end/src/visitor/VisitorOp.cpp
        front-end/src/expression/Expr.cpp)

#---------------
#   BACK-END
#---------------

include_directories(${BACK_END_FOLDER}/src)

set(BACK_SRC_FILES
        back-end/src/ir/IRInstr.cpp
        back-end/src/ir/BasicBlock.cpp
        back-end/src/ir/BuildIR.h
        back-end/src/ir/CFG.cpp
        back-end/src/ir/instructions/RMemInstr.cpp
        back-end/src/ir/instructions/WMemInstr.cpp
        back-end/src/ir/instructions/CallInstr.cpp
        back-end/src/ir/instructions/LoadConstInstr.cpp
        back-end/src/tree-walk/MapleTreeWalk.cpp
        back-end/src/targets/X86_64.cpp
        back-end/src/targets/BaseTarget.cpp
        back-end/src/ir/instructions/OpInstr.cpp
        back-end/src/ir/instructions/UnaryOpInstr.cpp
        )

#----------
#   CLI
#----------
include_directories(cli)

set(CLI_SRC_FILES
        cli/Runner.cpp
        cli/Config.h
        )


#----------------
#   EXECUTABLE
#----------------

# add generated grammar to demo binary target
add_executable(MapleCompiler
        main.cpp
        ${UTILS_SRC_FILES}
        ${ANTLR4_GENERATED_GRAMMAR_FILES}
        ${AST_SRC_FILES}
        ${BACK_SRC_FILES}
        ${CLI_SRC_FILES}
        )
target_link_libraries(MapleCompiler antlr4-runtime)
