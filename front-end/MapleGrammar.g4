grammar MapleGrammar;

// Axiome
start : program+ ;
program : functionDefinition | declaration ;

// Terminaux
MACRO : '#' .+ [\\n] -> skip ;
WS : [ \t\n\r]+ -> skip ;
SC :  ';' ;
TYPE : 'char'| ('int'('32'|'64')'_t') ;
TYPE_VOID : 'void' ;
CHAR : '\'' [\u0000-\u00FF] '\'' ;
INTEGER : [0-9]+ ('e' [0-9]+)?;
ID : [a-zA-Z_]([a-zA-Z0-9_]*) ;
value : INTEGER | CHAR ;

// Opérateurs
op1 : '++' | '--' ;
op2 : '++' | '--' | '+' | '-' | '!' | '~';
op3 : '*' | '/' | '%'  ;
op4 : '+' | '-' ;
op5 : '<<' | '>>' ;
op6 : '<' | '<=' | '>' | '>=' ;
op7 : '==' | '!=' ;
op8 : '&' ;
op9 : '^' ;  
op10 : '|' ;
op11 : '&&' ;
op12 : '||' ;
op13 : '=' | '+=' | '-=' | '*=' | '/=' | '%=' | '<<=' | '>>=' | '&=' | '^=' | '|=' ;

// Expression
expr : accessor
    | value
    | '(' expr ')'
    | expr op1
    | op2 expr
    | expr op3 expr
    | expr op4 expr
    | expr op5 expr
    | expr op6 expr
    | expr op7 expr
    | expr op8 expr
    | expr op9 expr
    | expr op10 expr
    | expr op11 expr
    | expr op12 expr
    | leftValue op13 expr ;

// Déclaration
declarationVar : TYPE ID assignment? SC ;
declarationTab : TYPE '[' expr ']' ID definitionTab? SC ;
declaration : declarationVar
    | declarationTab  ;

// Affectation
definitionTab : '=' '{' ((value ',')* value)? '}' ;
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
if: 'if' '(' expr ')' instruction else? ;
else: 'else' instruction ;
while: 'while' '(' expr ')' instruction ;

// Fonctions
functionDefinition : (TYPE | TYPE_VOID) ID '(' (typeList | TYPE_VOID)? ')' blockFunction ;
returnStatement : 'return' expr SC ;
blockFunction : '{' declaration* instruction* '}' ;
argumentList : ((expr ',')* expr)? ;
typeList : ((TYPE ID ',')* TYPE ID) ;


// Autres structures
block: '{' instruction* '}' ;
statement : expr SC ;

instruction : statement
    | if
    | while
    | block
    | returnStatement ;
