grammar MapleGrammar;

// axiom
start : program+ ;
program : functionDefinition | functionDeclaration | declaration ;

// Terminaux
MACRO : '#' .+? [\n\r] -> skip ;
WS : [ \t\n\r]+ -> skip ;
SC :  ';' ;
TYPE : 'char'| ('int'('32'|'64')'_t') ;
TYPE_VOID : 'void' ;
CHAR : '\'' '\\'? [\u0000-\u00FF] '\'' ;
INTEGER : [0-9]+ ('e' [0-9]+)?;
ID : [a-zA-Z_]+ [a-zA-Z0-9_]* ;
STRING : '"' ('\\'? [\u0000-\u00FF])+ '"' ;
value : INTEGER | CHAR ;

// Comments
COMMENT : '/*' .*? '*/' -> channel(HIDDEN) ;
LINE_COMMENT : '//' ~'\n'* '\n' -> channel(HIDDEN) ;

// Opérateurs
opIncrement : '++' | '--' ;
opUnaryPrefix : '+' | '-' | '!' | '~';
opMultiplicative : '*' | '/' | '%'  ;
opAdditive : '+' | '-' ;
opBinaryShift : '<<' | '>>' ;
opCompareRelational : '<' | '<=' | '>' | '>=' ;
opCompareEquality : '==' | '!=' ;
opBinaryAnd : '&' ;
opBinaryXor : '^' ;
opBinaryOr : '|' ;
opAnd : '&&' ;
opOr : '||' ;
opAffectation : '=' | '+=' | '-=' | '*=' | '/=' | '%=' | '<<=' | '>>=' | '&=' | '^=' | '|=' ;
opComma : ',' ;

// Expression
expr : accessor                         # exprAccessor
    | value                             # exprValue
    | '(' expr ')'                      # exprParenthesis
    | leftValue opIncrement             # exprIncrementPostfix
    | opIncrement leftValue             # exprIncrementPrefix
    | opUnaryPrefix expr                # exprUnaryPrefix
    | expr opMultiplicative expr        # exprMultiplicative
    | expr opAdditive expr              # exprAdditive
    | expr opBinaryShift expr           # exprBinaryShift
    | expr opCompareRelational expr     # exprCompareRelational
    | expr opCompareEquality expr       # exprCompareEquality
    | expr opBinaryAnd expr             # exprBinaryAnd
    | expr opBinaryXor expr             # exprBinaryXor
    | expr opBinaryOr expr              # exprBinaryOr
    | expr opAnd expr                   # exprAnd
    | expr opOr expr                    # exprOr
    | leftValue opAffectation expr      # exprAffectation
    | expr opComma expr                 # exprComma
    ;

// Déclaration
declarationVar : TYPE (declarationVarDefinition ',')* declarationVarDefinition SC ;
declarationTab : TYPE ID '[' ((expr ']')|(expr? ']' definitionTab)) SC;
declaration : declarationVar
    | declarationTab  ;
declarationVarDefinition : ID assignment? ;

// Affectation
definitionTab : '=' (('{' ((value ',')* value)? '}') | STRING) ;
assignment: '=' expr ;

// Accesseurs
accessorTab : ID '[' expr ']' ;
accessorVar : ID ;
accessorFunction : ID '(' argumentList ')' ;

leftValue : accessorTab
    | accessorVar ;

accessor : leftValue
    | accessorFunction ;

// Structures de contrôle
ifStatement: 'if' '(' expr ')' instruction elseStatement? ;
elseStatement: 'else' instruction ;
whileStatement: 'while' '(' expr ')' instruction ;
forStatement: 'for' '(' init=expr? SC cond=expr? SC post=expr? ')' instruction ;

// Fonctions

functionDeclaration: (TYPE | TYPE_VOID) ID '(' (typeListWithoutName | TYPE_VOID)? ')' SC;
functionDefinition : (TYPE | TYPE_VOID) ID '(' (typeList | TYPE_VOID)? ')' blockFunction ;
returnStatement : 'return' expr SC ;
blockFunction : '{' declaration* instruction* '}' ;
argumentList : ((expr ',')* expr)? ;

typeList : (argumentType ',')*  argumentType ;
typeListWithoutName : ((argumentTypeWithoutName ',')* argumentTypeWithoutName) ;

argumentType: argumentTypeVar | argumentTypeArray ;
argumentTypeVar : TYPE ID ;
argumentTypeArray : TYPE ID '[' expr? ']' ;

argumentTypeWithoutName : argumentTypeVarWithoutName | argumentTypeArrayWithoutName ;
argumentTypeVarWithoutName : TYPE ID? ;
argumentTypeArrayWithoutName : TYPE ID? '['']' ;

// Autres structures
block: '{' instruction* '}' ;
statement : expr SC ;

instruction : statement
    | ifStatement
    | whileStatement
    | forStatement
    | block
    | returnStatement ;
