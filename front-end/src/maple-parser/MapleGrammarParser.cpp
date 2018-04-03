
// Generated from F:/Downloads/MapleCompiler/front-end/src/maple-parser\MapleGrammar.g4 by ANTLR 4.7


#include "MapleGrammarVisitor.h"

#include "MapleGrammarParser.h"


using namespace antlrcpp;
using namespace antlr4;

MapleGrammarParser::MapleGrammarParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

MapleGrammarParser::~MapleGrammarParser() {
  delete _interpreter;
}

std::string MapleGrammarParser::getGrammarFileName() const {
  return "MapleGrammar.g4";
}

const std::vector<std::string>& MapleGrammarParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& MapleGrammarParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- StartContext ------------------------------------------------------------------

MapleGrammarParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MapleGrammarParser::ProgramContext *> MapleGrammarParser::StartContext::program() {
  return getRuleContexts<MapleGrammarParser::ProgramContext>();
}

MapleGrammarParser::ProgramContext* MapleGrammarParser::StartContext::program(size_t i) {
  return getRuleContext<MapleGrammarParser::ProgramContext>(i);
}


size_t MapleGrammarParser::StartContext::getRuleIndex() const {
  return MapleGrammarParser::RuleStart;
}

antlrcpp::Any MapleGrammarParser::StartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitStart(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::StartContext* MapleGrammarParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, MapleGrammarParser::RuleStart);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(85); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(84);
      program();
      setState(87); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == MapleGrammarParser::TYPE

    || _la == MapleGrammarParser::TYPE_VOID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

MapleGrammarParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MapleGrammarParser::FunctionDefinitionContext* MapleGrammarParser::ProgramContext::functionDefinition() {
  return getRuleContext<MapleGrammarParser::FunctionDefinitionContext>(0);
}

MapleGrammarParser::FunctionDeclarationContext* MapleGrammarParser::ProgramContext::functionDeclaration() {
  return getRuleContext<MapleGrammarParser::FunctionDeclarationContext>(0);
}

MapleGrammarParser::DeclarationContext* MapleGrammarParser::ProgramContext::declaration() {
  return getRuleContext<MapleGrammarParser::DeclarationContext>(0);
}


size_t MapleGrammarParser::ProgramContext::getRuleIndex() const {
  return MapleGrammarParser::RuleProgram;
}

antlrcpp::Any MapleGrammarParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::ProgramContext* MapleGrammarParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 2, MapleGrammarParser::RuleProgram);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(92);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(89);
      functionDefinition();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(90);
      functionDeclaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(91);
      declaration();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueContext ------------------------------------------------------------------

MapleGrammarParser::ValueContext::ValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MapleGrammarParser::ValueContext::INTEGER() {
  return getToken(MapleGrammarParser::INTEGER, 0);
}

tree::TerminalNode* MapleGrammarParser::ValueContext::CHAR() {
  return getToken(MapleGrammarParser::CHAR, 0);
}


size_t MapleGrammarParser::ValueContext::getRuleIndex() const {
  return MapleGrammarParser::RuleValue;
}

antlrcpp::Any MapleGrammarParser::ValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitValue(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::ValueContext* MapleGrammarParser::value() {
  ValueContext *_localctx = _tracker.createInstance<ValueContext>(_ctx, getState());
  enterRule(_localctx, 4, MapleGrammarParser::RuleValue);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(94);
    _la = _input->LA(1);
    if (!(_la == MapleGrammarParser::CHAR

    || _la == MapleGrammarParser::INTEGER)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OpIncrementContext ------------------------------------------------------------------

MapleGrammarParser::OpIncrementContext::OpIncrementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MapleGrammarParser::OpIncrementContext::getRuleIndex() const {
  return MapleGrammarParser::RuleOpIncrement;
}

antlrcpp::Any MapleGrammarParser::OpIncrementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitOpIncrement(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::OpIncrementContext* MapleGrammarParser::opIncrement() {
  OpIncrementContext *_localctx = _tracker.createInstance<OpIncrementContext>(_ctx, getState());
  enterRule(_localctx, 6, MapleGrammarParser::RuleOpIncrement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(96);
    _la = _input->LA(1);
    if (!(_la == MapleGrammarParser::T__0

    || _la == MapleGrammarParser::T__1)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OpUnaryPrefixContext ------------------------------------------------------------------

MapleGrammarParser::OpUnaryPrefixContext::OpUnaryPrefixContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MapleGrammarParser::OpUnaryPrefixContext::getRuleIndex() const {
  return MapleGrammarParser::RuleOpUnaryPrefix;
}

antlrcpp::Any MapleGrammarParser::OpUnaryPrefixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitOpUnaryPrefix(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::OpUnaryPrefixContext* MapleGrammarParser::opUnaryPrefix() {
  OpUnaryPrefixContext *_localctx = _tracker.createInstance<OpUnaryPrefixContext>(_ctx, getState());
  enterRule(_localctx, 8, MapleGrammarParser::RuleOpUnaryPrefix);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(98);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MapleGrammarParser::T__2)
      | (1ULL << MapleGrammarParser::T__3)
      | (1ULL << MapleGrammarParser::T__4)
      | (1ULL << MapleGrammarParser::T__5))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OpMultiplicativeContext ------------------------------------------------------------------

MapleGrammarParser::OpMultiplicativeContext::OpMultiplicativeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MapleGrammarParser::OpMultiplicativeContext::getRuleIndex() const {
  return MapleGrammarParser::RuleOpMultiplicative;
}

antlrcpp::Any MapleGrammarParser::OpMultiplicativeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitOpMultiplicative(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::OpMultiplicativeContext* MapleGrammarParser::opMultiplicative() {
  OpMultiplicativeContext *_localctx = _tracker.createInstance<OpMultiplicativeContext>(_ctx, getState());
  enterRule(_localctx, 10, MapleGrammarParser::RuleOpMultiplicative);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(100);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MapleGrammarParser::T__6)
      | (1ULL << MapleGrammarParser::T__7)
      | (1ULL << MapleGrammarParser::T__8))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OpAdditiveContext ------------------------------------------------------------------

MapleGrammarParser::OpAdditiveContext::OpAdditiveContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MapleGrammarParser::OpAdditiveContext::getRuleIndex() const {
  return MapleGrammarParser::RuleOpAdditive;
}

antlrcpp::Any MapleGrammarParser::OpAdditiveContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitOpAdditive(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::OpAdditiveContext* MapleGrammarParser::opAdditive() {
  OpAdditiveContext *_localctx = _tracker.createInstance<OpAdditiveContext>(_ctx, getState());
  enterRule(_localctx, 12, MapleGrammarParser::RuleOpAdditive);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(102);
    _la = _input->LA(1);
    if (!(_la == MapleGrammarParser::T__2

    || _la == MapleGrammarParser::T__3)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OpBinaryShiftContext ------------------------------------------------------------------

MapleGrammarParser::OpBinaryShiftContext::OpBinaryShiftContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MapleGrammarParser::OpBinaryShiftContext::getRuleIndex() const {
  return MapleGrammarParser::RuleOpBinaryShift;
}

antlrcpp::Any MapleGrammarParser::OpBinaryShiftContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitOpBinaryShift(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::OpBinaryShiftContext* MapleGrammarParser::opBinaryShift() {
  OpBinaryShiftContext *_localctx = _tracker.createInstance<OpBinaryShiftContext>(_ctx, getState());
  enterRule(_localctx, 14, MapleGrammarParser::RuleOpBinaryShift);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(104);
    _la = _input->LA(1);
    if (!(_la == MapleGrammarParser::T__9

    || _la == MapleGrammarParser::T__10)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OpCompareRelationalContext ------------------------------------------------------------------

MapleGrammarParser::OpCompareRelationalContext::OpCompareRelationalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MapleGrammarParser::OpCompareRelationalContext::getRuleIndex() const {
  return MapleGrammarParser::RuleOpCompareRelational;
}

antlrcpp::Any MapleGrammarParser::OpCompareRelationalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitOpCompareRelational(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::OpCompareRelationalContext* MapleGrammarParser::opCompareRelational() {
  OpCompareRelationalContext *_localctx = _tracker.createInstance<OpCompareRelationalContext>(_ctx, getState());
  enterRule(_localctx, 16, MapleGrammarParser::RuleOpCompareRelational);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(106);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MapleGrammarParser::T__11)
      | (1ULL << MapleGrammarParser::T__12)
      | (1ULL << MapleGrammarParser::T__13)
      | (1ULL << MapleGrammarParser::T__14))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OpCompareEqualityContext ------------------------------------------------------------------

MapleGrammarParser::OpCompareEqualityContext::OpCompareEqualityContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MapleGrammarParser::OpCompareEqualityContext::getRuleIndex() const {
  return MapleGrammarParser::RuleOpCompareEquality;
}

antlrcpp::Any MapleGrammarParser::OpCompareEqualityContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitOpCompareEquality(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::OpCompareEqualityContext* MapleGrammarParser::opCompareEquality() {
  OpCompareEqualityContext *_localctx = _tracker.createInstance<OpCompareEqualityContext>(_ctx, getState());
  enterRule(_localctx, 18, MapleGrammarParser::RuleOpCompareEquality);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(108);
    _la = _input->LA(1);
    if (!(_la == MapleGrammarParser::T__15

    || _la == MapleGrammarParser::T__16)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OpBinaryAndContext ------------------------------------------------------------------

MapleGrammarParser::OpBinaryAndContext::OpBinaryAndContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MapleGrammarParser::OpBinaryAndContext::getRuleIndex() const {
  return MapleGrammarParser::RuleOpBinaryAnd;
}

antlrcpp::Any MapleGrammarParser::OpBinaryAndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitOpBinaryAnd(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::OpBinaryAndContext* MapleGrammarParser::opBinaryAnd() {
  OpBinaryAndContext *_localctx = _tracker.createInstance<OpBinaryAndContext>(_ctx, getState());
  enterRule(_localctx, 20, MapleGrammarParser::RuleOpBinaryAnd);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(110);
    match(MapleGrammarParser::T__17);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OpBinaryXorContext ------------------------------------------------------------------

MapleGrammarParser::OpBinaryXorContext::OpBinaryXorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MapleGrammarParser::OpBinaryXorContext::getRuleIndex() const {
  return MapleGrammarParser::RuleOpBinaryXor;
}

antlrcpp::Any MapleGrammarParser::OpBinaryXorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitOpBinaryXor(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::OpBinaryXorContext* MapleGrammarParser::opBinaryXor() {
  OpBinaryXorContext *_localctx = _tracker.createInstance<OpBinaryXorContext>(_ctx, getState());
  enterRule(_localctx, 22, MapleGrammarParser::RuleOpBinaryXor);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(112);
    match(MapleGrammarParser::T__18);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OpBinaryOrContext ------------------------------------------------------------------

MapleGrammarParser::OpBinaryOrContext::OpBinaryOrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MapleGrammarParser::OpBinaryOrContext::getRuleIndex() const {
  return MapleGrammarParser::RuleOpBinaryOr;
}

antlrcpp::Any MapleGrammarParser::OpBinaryOrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitOpBinaryOr(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::OpBinaryOrContext* MapleGrammarParser::opBinaryOr() {
  OpBinaryOrContext *_localctx = _tracker.createInstance<OpBinaryOrContext>(_ctx, getState());
  enterRule(_localctx, 24, MapleGrammarParser::RuleOpBinaryOr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(114);
    match(MapleGrammarParser::T__19);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OpAndContext ------------------------------------------------------------------

MapleGrammarParser::OpAndContext::OpAndContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MapleGrammarParser::OpAndContext::getRuleIndex() const {
  return MapleGrammarParser::RuleOpAnd;
}

antlrcpp::Any MapleGrammarParser::OpAndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitOpAnd(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::OpAndContext* MapleGrammarParser::opAnd() {
  OpAndContext *_localctx = _tracker.createInstance<OpAndContext>(_ctx, getState());
  enterRule(_localctx, 26, MapleGrammarParser::RuleOpAnd);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(116);
    match(MapleGrammarParser::T__20);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OpOrContext ------------------------------------------------------------------

MapleGrammarParser::OpOrContext::OpOrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MapleGrammarParser::OpOrContext::getRuleIndex() const {
  return MapleGrammarParser::RuleOpOr;
}

antlrcpp::Any MapleGrammarParser::OpOrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitOpOr(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::OpOrContext* MapleGrammarParser::opOr() {
  OpOrContext *_localctx = _tracker.createInstance<OpOrContext>(_ctx, getState());
  enterRule(_localctx, 28, MapleGrammarParser::RuleOpOr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(118);
    match(MapleGrammarParser::T__21);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OpAffectationContext ------------------------------------------------------------------

MapleGrammarParser::OpAffectationContext::OpAffectationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MapleGrammarParser::OpAffectationContext::getRuleIndex() const {
  return MapleGrammarParser::RuleOpAffectation;
}

antlrcpp::Any MapleGrammarParser::OpAffectationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitOpAffectation(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::OpAffectationContext* MapleGrammarParser::opAffectation() {
  OpAffectationContext *_localctx = _tracker.createInstance<OpAffectationContext>(_ctx, getState());
  enterRule(_localctx, 30, MapleGrammarParser::RuleOpAffectation);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(120);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MapleGrammarParser::T__22)
      | (1ULL << MapleGrammarParser::T__23)
      | (1ULL << MapleGrammarParser::T__24)
      | (1ULL << MapleGrammarParser::T__25)
      | (1ULL << MapleGrammarParser::T__26)
      | (1ULL << MapleGrammarParser::T__27)
      | (1ULL << MapleGrammarParser::T__28)
      | (1ULL << MapleGrammarParser::T__29)
      | (1ULL << MapleGrammarParser::T__30)
      | (1ULL << MapleGrammarParser::T__31)
      | (1ULL << MapleGrammarParser::T__32))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OpCommaContext ------------------------------------------------------------------

MapleGrammarParser::OpCommaContext::OpCommaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MapleGrammarParser::OpCommaContext::getRuleIndex() const {
  return MapleGrammarParser::RuleOpComma;
}

antlrcpp::Any MapleGrammarParser::OpCommaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitOpComma(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::OpCommaContext* MapleGrammarParser::opComma() {
  OpCommaContext *_localctx = _tracker.createInstance<OpCommaContext>(_ctx, getState());
  enterRule(_localctx, 32, MapleGrammarParser::RuleOpComma);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(122);
    match(MapleGrammarParser::T__33);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

MapleGrammarParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MapleGrammarParser::ExprContext::getRuleIndex() const {
  return MapleGrammarParser::RuleExpr;
}

void MapleGrammarParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExprAdditiveContext ------------------------------------------------------------------

std::vector<MapleGrammarParser::ExprContext *> MapleGrammarParser::ExprAdditiveContext::expr() {
  return getRuleContexts<MapleGrammarParser::ExprContext>();
}

MapleGrammarParser::ExprContext* MapleGrammarParser::ExprAdditiveContext::expr(size_t i) {
  return getRuleContext<MapleGrammarParser::ExprContext>(i);
}

MapleGrammarParser::OpAdditiveContext* MapleGrammarParser::ExprAdditiveContext::opAdditive() {
  return getRuleContext<MapleGrammarParser::OpAdditiveContext>(0);
}

MapleGrammarParser::ExprAdditiveContext::ExprAdditiveContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MapleGrammarParser::ExprAdditiveContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitExprAdditive(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprValueContext ------------------------------------------------------------------

MapleGrammarParser::ValueContext* MapleGrammarParser::ExprValueContext::value() {
  return getRuleContext<MapleGrammarParser::ValueContext>(0);
}

MapleGrammarParser::ExprValueContext::ExprValueContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MapleGrammarParser::ExprValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitExprValue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprBinaryShiftContext ------------------------------------------------------------------

std::vector<MapleGrammarParser::ExprContext *> MapleGrammarParser::ExprBinaryShiftContext::expr() {
  return getRuleContexts<MapleGrammarParser::ExprContext>();
}

MapleGrammarParser::ExprContext* MapleGrammarParser::ExprBinaryShiftContext::expr(size_t i) {
  return getRuleContext<MapleGrammarParser::ExprContext>(i);
}

MapleGrammarParser::OpBinaryShiftContext* MapleGrammarParser::ExprBinaryShiftContext::opBinaryShift() {
  return getRuleContext<MapleGrammarParser::OpBinaryShiftContext>(0);
}

MapleGrammarParser::ExprBinaryShiftContext::ExprBinaryShiftContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MapleGrammarParser::ExprBinaryShiftContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitExprBinaryShift(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprAffectationContext ------------------------------------------------------------------

MapleGrammarParser::LeftValueContext* MapleGrammarParser::ExprAffectationContext::leftValue() {
  return getRuleContext<MapleGrammarParser::LeftValueContext>(0);
}

MapleGrammarParser::OpAffectationContext* MapleGrammarParser::ExprAffectationContext::opAffectation() {
  return getRuleContext<MapleGrammarParser::OpAffectationContext>(0);
}

MapleGrammarParser::ExprContext* MapleGrammarParser::ExprAffectationContext::expr() {
  return getRuleContext<MapleGrammarParser::ExprContext>(0);
}

MapleGrammarParser::ExprAffectationContext::ExprAffectationContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MapleGrammarParser::ExprAffectationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitExprAffectation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprBinaryXorContext ------------------------------------------------------------------

std::vector<MapleGrammarParser::ExprContext *> MapleGrammarParser::ExprBinaryXorContext::expr() {
  return getRuleContexts<MapleGrammarParser::ExprContext>();
}

MapleGrammarParser::ExprContext* MapleGrammarParser::ExprBinaryXorContext::expr(size_t i) {
  return getRuleContext<MapleGrammarParser::ExprContext>(i);
}

MapleGrammarParser::OpBinaryXorContext* MapleGrammarParser::ExprBinaryXorContext::opBinaryXor() {
  return getRuleContext<MapleGrammarParser::OpBinaryXorContext>(0);
}

MapleGrammarParser::ExprBinaryXorContext::ExprBinaryXorContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MapleGrammarParser::ExprBinaryXorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitExprBinaryXor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprBinaryAndContext ------------------------------------------------------------------

std::vector<MapleGrammarParser::ExprContext *> MapleGrammarParser::ExprBinaryAndContext::expr() {
  return getRuleContexts<MapleGrammarParser::ExprContext>();
}

MapleGrammarParser::ExprContext* MapleGrammarParser::ExprBinaryAndContext::expr(size_t i) {
  return getRuleContext<MapleGrammarParser::ExprContext>(i);
}

MapleGrammarParser::OpBinaryAndContext* MapleGrammarParser::ExprBinaryAndContext::opBinaryAnd() {
  return getRuleContext<MapleGrammarParser::OpBinaryAndContext>(0);
}

MapleGrammarParser::ExprBinaryAndContext::ExprBinaryAndContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MapleGrammarParser::ExprBinaryAndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitExprBinaryAnd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprIncrementPostfixContext ------------------------------------------------------------------

MapleGrammarParser::LeftValueContext* MapleGrammarParser::ExprIncrementPostfixContext::leftValue() {
  return getRuleContext<MapleGrammarParser::LeftValueContext>(0);
}

MapleGrammarParser::OpIncrementContext* MapleGrammarParser::ExprIncrementPostfixContext::opIncrement() {
  return getRuleContext<MapleGrammarParser::OpIncrementContext>(0);
}

MapleGrammarParser::ExprIncrementPostfixContext::ExprIncrementPostfixContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MapleGrammarParser::ExprIncrementPostfixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitExprIncrementPostfix(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprOrContext ------------------------------------------------------------------

std::vector<MapleGrammarParser::ExprContext *> MapleGrammarParser::ExprOrContext::expr() {
  return getRuleContexts<MapleGrammarParser::ExprContext>();
}

MapleGrammarParser::ExprContext* MapleGrammarParser::ExprOrContext::expr(size_t i) {
  return getRuleContext<MapleGrammarParser::ExprContext>(i);
}

MapleGrammarParser::OpOrContext* MapleGrammarParser::ExprOrContext::opOr() {
  return getRuleContext<MapleGrammarParser::OpOrContext>(0);
}

MapleGrammarParser::ExprOrContext::ExprOrContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MapleGrammarParser::ExprOrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitExprOr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprMultiplicativeContext ------------------------------------------------------------------

std::vector<MapleGrammarParser::ExprContext *> MapleGrammarParser::ExprMultiplicativeContext::expr() {
  return getRuleContexts<MapleGrammarParser::ExprContext>();
}

MapleGrammarParser::ExprContext* MapleGrammarParser::ExprMultiplicativeContext::expr(size_t i) {
  return getRuleContext<MapleGrammarParser::ExprContext>(i);
}

MapleGrammarParser::OpMultiplicativeContext* MapleGrammarParser::ExprMultiplicativeContext::opMultiplicative() {
  return getRuleContext<MapleGrammarParser::OpMultiplicativeContext>(0);
}

MapleGrammarParser::ExprMultiplicativeContext::ExprMultiplicativeContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MapleGrammarParser::ExprMultiplicativeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitExprMultiplicative(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprAccessorContext ------------------------------------------------------------------

MapleGrammarParser::AccessorContext* MapleGrammarParser::ExprAccessorContext::accessor() {
  return getRuleContext<MapleGrammarParser::AccessorContext>(0);
}

MapleGrammarParser::ExprAccessorContext::ExprAccessorContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MapleGrammarParser::ExprAccessorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitExprAccessor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprCommaContext ------------------------------------------------------------------

std::vector<MapleGrammarParser::ExprContext *> MapleGrammarParser::ExprCommaContext::expr() {
  return getRuleContexts<MapleGrammarParser::ExprContext>();
}

MapleGrammarParser::ExprContext* MapleGrammarParser::ExprCommaContext::expr(size_t i) {
  return getRuleContext<MapleGrammarParser::ExprContext>(i);
}

MapleGrammarParser::OpCommaContext* MapleGrammarParser::ExprCommaContext::opComma() {
  return getRuleContext<MapleGrammarParser::OpCommaContext>(0);
}

MapleGrammarParser::ExprCommaContext::ExprCommaContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MapleGrammarParser::ExprCommaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitExprComma(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprAndContext ------------------------------------------------------------------

std::vector<MapleGrammarParser::ExprContext *> MapleGrammarParser::ExprAndContext::expr() {
  return getRuleContexts<MapleGrammarParser::ExprContext>();
}

MapleGrammarParser::ExprContext* MapleGrammarParser::ExprAndContext::expr(size_t i) {
  return getRuleContext<MapleGrammarParser::ExprContext>(i);
}

MapleGrammarParser::OpAndContext* MapleGrammarParser::ExprAndContext::opAnd() {
  return getRuleContext<MapleGrammarParser::OpAndContext>(0);
}

MapleGrammarParser::ExprAndContext::ExprAndContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MapleGrammarParser::ExprAndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitExprAnd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprParenthesisContext ------------------------------------------------------------------

MapleGrammarParser::ExprContext* MapleGrammarParser::ExprParenthesisContext::expr() {
  return getRuleContext<MapleGrammarParser::ExprContext>(0);
}

MapleGrammarParser::ExprParenthesisContext::ExprParenthesisContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MapleGrammarParser::ExprParenthesisContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitExprParenthesis(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprBinaryOrContext ------------------------------------------------------------------

std::vector<MapleGrammarParser::ExprContext *> MapleGrammarParser::ExprBinaryOrContext::expr() {
  return getRuleContexts<MapleGrammarParser::ExprContext>();
}

MapleGrammarParser::ExprContext* MapleGrammarParser::ExprBinaryOrContext::expr(size_t i) {
  return getRuleContext<MapleGrammarParser::ExprContext>(i);
}

MapleGrammarParser::OpBinaryOrContext* MapleGrammarParser::ExprBinaryOrContext::opBinaryOr() {
  return getRuleContext<MapleGrammarParser::OpBinaryOrContext>(0);
}

MapleGrammarParser::ExprBinaryOrContext::ExprBinaryOrContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MapleGrammarParser::ExprBinaryOrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitExprBinaryOr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprCompareRelationalContext ------------------------------------------------------------------

std::vector<MapleGrammarParser::ExprContext *> MapleGrammarParser::ExprCompareRelationalContext::expr() {
  return getRuleContexts<MapleGrammarParser::ExprContext>();
}

MapleGrammarParser::ExprContext* MapleGrammarParser::ExprCompareRelationalContext::expr(size_t i) {
  return getRuleContext<MapleGrammarParser::ExprContext>(i);
}

MapleGrammarParser::OpCompareRelationalContext* MapleGrammarParser::ExprCompareRelationalContext::opCompareRelational() {
  return getRuleContext<MapleGrammarParser::OpCompareRelationalContext>(0);
}

MapleGrammarParser::ExprCompareRelationalContext::ExprCompareRelationalContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MapleGrammarParser::ExprCompareRelationalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitExprCompareRelational(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprCompareEqualityContext ------------------------------------------------------------------

std::vector<MapleGrammarParser::ExprContext *> MapleGrammarParser::ExprCompareEqualityContext::expr() {
  return getRuleContexts<MapleGrammarParser::ExprContext>();
}

MapleGrammarParser::ExprContext* MapleGrammarParser::ExprCompareEqualityContext::expr(size_t i) {
  return getRuleContext<MapleGrammarParser::ExprContext>(i);
}

MapleGrammarParser::OpCompareEqualityContext* MapleGrammarParser::ExprCompareEqualityContext::opCompareEquality() {
  return getRuleContext<MapleGrammarParser::OpCompareEqualityContext>(0);
}

MapleGrammarParser::ExprCompareEqualityContext::ExprCompareEqualityContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MapleGrammarParser::ExprCompareEqualityContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitExprCompareEquality(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprIncrementPrefixContext ------------------------------------------------------------------

MapleGrammarParser::OpIncrementContext* MapleGrammarParser::ExprIncrementPrefixContext::opIncrement() {
  return getRuleContext<MapleGrammarParser::OpIncrementContext>(0);
}

MapleGrammarParser::LeftValueContext* MapleGrammarParser::ExprIncrementPrefixContext::leftValue() {
  return getRuleContext<MapleGrammarParser::LeftValueContext>(0);
}

MapleGrammarParser::ExprIncrementPrefixContext::ExprIncrementPrefixContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MapleGrammarParser::ExprIncrementPrefixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitExprIncrementPrefix(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprUnaryPrefixContext ------------------------------------------------------------------

MapleGrammarParser::OpUnaryPrefixContext* MapleGrammarParser::ExprUnaryPrefixContext::opUnaryPrefix() {
  return getRuleContext<MapleGrammarParser::OpUnaryPrefixContext>(0);
}

MapleGrammarParser::ExprContext* MapleGrammarParser::ExprUnaryPrefixContext::expr() {
  return getRuleContext<MapleGrammarParser::ExprContext>(0);
}

MapleGrammarParser::ExprUnaryPrefixContext::ExprUnaryPrefixContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MapleGrammarParser::ExprUnaryPrefixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitExprUnaryPrefix(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::ExprContext* MapleGrammarParser::expr() {
   return expr(0);
}

MapleGrammarParser::ExprContext* MapleGrammarParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MapleGrammarParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  MapleGrammarParser::ExprContext *previousContext = _localctx;
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, MapleGrammarParser::RuleExpr, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(144);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ExprAccessorContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(125);
      accessor();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ExprValueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(126);
      value();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ExprParenthesisContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(127);
      match(MapleGrammarParser::T__34);
      setState(128);
      expr(0);
      setState(129);
      match(MapleGrammarParser::T__35);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ExprIncrementPostfixContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(131);
      leftValue();
      setState(132);
      opIncrement();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ExprIncrementPrefixContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(134);
      opIncrement();
      setState(135);
      leftValue();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ExprUnaryPrefixContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(137);
      opUnaryPrefix();
      setState(138);
      expr(13);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<ExprAffectationContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(140);
      leftValue();
      setState(141);
      opAffectation();
      setState(142);
      expr(2);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(192);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(190);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ExprMultiplicativeContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(146);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(147);
          opMultiplicative();
          setState(148);
          expr(13);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ExprAdditiveContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(150);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(151);
          opAdditive();
          setState(152);
          expr(12);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ExprBinaryShiftContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(154);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(155);
          opBinaryShift();
          setState(156);
          expr(11);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<ExprCompareRelationalContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(158);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(159);
          opCompareRelational();
          setState(160);
          expr(10);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<ExprCompareEqualityContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(162);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(163);
          opCompareEquality();
          setState(164);
          expr(9);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<ExprBinaryAndContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(166);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(167);
          opBinaryAnd();
          setState(168);
          expr(8);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<ExprBinaryXorContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(170);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(171);
          opBinaryXor();
          setState(172);
          expr(7);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<ExprBinaryOrContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(174);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(175);
          opBinaryOr();
          setState(176);
          expr(6);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<ExprAndContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(178);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(179);
          opAnd();
          setState(180);
          expr(5);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<ExprOrContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(182);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(183);
          opOr();
          setState(184);
          expr(4);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<ExprCommaContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(186);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(187);
          opComma();
          setState(188);
          expr(2);
          break;
        }

        } 
      }
      setState(194);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- DeclarationVarContext ------------------------------------------------------------------

MapleGrammarParser::DeclarationVarContext::DeclarationVarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MapleGrammarParser::DeclarationVarContext::TYPE() {
  return getToken(MapleGrammarParser::TYPE, 0);
}

std::vector<MapleGrammarParser::DeclarationVarDefinitionContext *> MapleGrammarParser::DeclarationVarContext::declarationVarDefinition() {
  return getRuleContexts<MapleGrammarParser::DeclarationVarDefinitionContext>();
}

MapleGrammarParser::DeclarationVarDefinitionContext* MapleGrammarParser::DeclarationVarContext::declarationVarDefinition(size_t i) {
  return getRuleContext<MapleGrammarParser::DeclarationVarDefinitionContext>(i);
}

tree::TerminalNode* MapleGrammarParser::DeclarationVarContext::SC() {
  return getToken(MapleGrammarParser::SC, 0);
}


size_t MapleGrammarParser::DeclarationVarContext::getRuleIndex() const {
  return MapleGrammarParser::RuleDeclarationVar;
}

antlrcpp::Any MapleGrammarParser::DeclarationVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitDeclarationVar(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::DeclarationVarContext* MapleGrammarParser::declarationVar() {
  DeclarationVarContext *_localctx = _tracker.createInstance<DeclarationVarContext>(_ctx, getState());
  enterRule(_localctx, 36, MapleGrammarParser::RuleDeclarationVar);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(195);
    match(MapleGrammarParser::TYPE);
    setState(201);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(196);
        declarationVarDefinition();
        setState(197);
        match(MapleGrammarParser::T__33); 
      }
      setState(203);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
    setState(204);
    declarationVarDefinition();
    setState(205);
    match(MapleGrammarParser::SC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationTabContext ------------------------------------------------------------------

MapleGrammarParser::DeclarationTabContext::DeclarationTabContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MapleGrammarParser::DeclarationTabContext::TYPE() {
  return getToken(MapleGrammarParser::TYPE, 0);
}

tree::TerminalNode* MapleGrammarParser::DeclarationTabContext::ID() {
  return getToken(MapleGrammarParser::ID, 0);
}

tree::TerminalNode* MapleGrammarParser::DeclarationTabContext::SC() {
  return getToken(MapleGrammarParser::SC, 0);
}

MapleGrammarParser::ExprContext* MapleGrammarParser::DeclarationTabContext::expr() {
  return getRuleContext<MapleGrammarParser::ExprContext>(0);
}

MapleGrammarParser::DefinitionTabContext* MapleGrammarParser::DeclarationTabContext::definitionTab() {
  return getRuleContext<MapleGrammarParser::DefinitionTabContext>(0);
}


size_t MapleGrammarParser::DeclarationTabContext::getRuleIndex() const {
  return MapleGrammarParser::RuleDeclarationTab;
}

antlrcpp::Any MapleGrammarParser::DeclarationTabContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitDeclarationTab(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::DeclarationTabContext* MapleGrammarParser::declarationTab() {
  DeclarationTabContext *_localctx = _tracker.createInstance<DeclarationTabContext>(_ctx, getState());
  enterRule(_localctx, 38, MapleGrammarParser::RuleDeclarationTab);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(207);
    match(MapleGrammarParser::TYPE);
    setState(208);
    match(MapleGrammarParser::ID);
    setState(209);
    match(MapleGrammarParser::T__36);
    setState(218);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      setState(210);
      expr(0);
      setState(211);
      match(MapleGrammarParser::T__37);
      break;
    }

    case 2: {
      setState(214);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MapleGrammarParser::T__0)
        | (1ULL << MapleGrammarParser::T__1)
        | (1ULL << MapleGrammarParser::T__2)
        | (1ULL << MapleGrammarParser::T__3)
        | (1ULL << MapleGrammarParser::T__4)
        | (1ULL << MapleGrammarParser::T__5)
        | (1ULL << MapleGrammarParser::T__34)
        | (1ULL << MapleGrammarParser::CHAR)
        | (1ULL << MapleGrammarParser::INTEGER)
        | (1ULL << MapleGrammarParser::ID))) != 0)) {
        setState(213);
        expr(0);
      }
      setState(216);
      match(MapleGrammarParser::T__37);
      setState(217);
      definitionTab();
      break;
    }

    }
    setState(220);
    match(MapleGrammarParser::SC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

MapleGrammarParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MapleGrammarParser::DeclarationVarContext* MapleGrammarParser::DeclarationContext::declarationVar() {
  return getRuleContext<MapleGrammarParser::DeclarationVarContext>(0);
}

MapleGrammarParser::DeclarationTabContext* MapleGrammarParser::DeclarationContext::declarationTab() {
  return getRuleContext<MapleGrammarParser::DeclarationTabContext>(0);
}


size_t MapleGrammarParser::DeclarationContext::getRuleIndex() const {
  return MapleGrammarParser::RuleDeclaration;
}

antlrcpp::Any MapleGrammarParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::DeclarationContext* MapleGrammarParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 40, MapleGrammarParser::RuleDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(224);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(222);
      declarationVar();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(223);
      declarationTab();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationVarDefinitionContext ------------------------------------------------------------------

MapleGrammarParser::DeclarationVarDefinitionContext::DeclarationVarDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MapleGrammarParser::DeclarationVarDefinitionContext::ID() {
  return getToken(MapleGrammarParser::ID, 0);
}

MapleGrammarParser::AssignmentContext* MapleGrammarParser::DeclarationVarDefinitionContext::assignment() {
  return getRuleContext<MapleGrammarParser::AssignmentContext>(0);
}


size_t MapleGrammarParser::DeclarationVarDefinitionContext::getRuleIndex() const {
  return MapleGrammarParser::RuleDeclarationVarDefinition;
}

antlrcpp::Any MapleGrammarParser::DeclarationVarDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitDeclarationVarDefinition(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::DeclarationVarDefinitionContext* MapleGrammarParser::declarationVarDefinition() {
  DeclarationVarDefinitionContext *_localctx = _tracker.createInstance<DeclarationVarDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 42, MapleGrammarParser::RuleDeclarationVarDefinition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(226);
    match(MapleGrammarParser::ID);
    setState(228);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MapleGrammarParser::T__22) {
      setState(227);
      assignment();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefinitionTabContext ------------------------------------------------------------------

MapleGrammarParser::DefinitionTabContext::DefinitionTabContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MapleGrammarParser::ValueContext *> MapleGrammarParser::DefinitionTabContext::value() {
  return getRuleContexts<MapleGrammarParser::ValueContext>();
}

MapleGrammarParser::ValueContext* MapleGrammarParser::DefinitionTabContext::value(size_t i) {
  return getRuleContext<MapleGrammarParser::ValueContext>(i);
}


size_t MapleGrammarParser::DefinitionTabContext::getRuleIndex() const {
  return MapleGrammarParser::RuleDefinitionTab;
}

antlrcpp::Any MapleGrammarParser::DefinitionTabContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitDefinitionTab(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::DefinitionTabContext* MapleGrammarParser::definitionTab() {
  DefinitionTabContext *_localctx = _tracker.createInstance<DefinitionTabContext>(_ctx, getState());
  enterRule(_localctx, 44, MapleGrammarParser::RuleDefinitionTab);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(230);
    match(MapleGrammarParser::T__22);
    setState(231);
    match(MapleGrammarParser::T__38);
    setState(241);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MapleGrammarParser::CHAR

    || _la == MapleGrammarParser::INTEGER) {
      setState(237);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(232);
          value();
          setState(233);
          match(MapleGrammarParser::T__33); 
        }
        setState(239);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
      }
      setState(240);
      value();
    }
    setState(243);
    match(MapleGrammarParser::T__39);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

MapleGrammarParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MapleGrammarParser::ExprContext* MapleGrammarParser::AssignmentContext::expr() {
  return getRuleContext<MapleGrammarParser::ExprContext>(0);
}


size_t MapleGrammarParser::AssignmentContext::getRuleIndex() const {
  return MapleGrammarParser::RuleAssignment;
}

antlrcpp::Any MapleGrammarParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::AssignmentContext* MapleGrammarParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 46, MapleGrammarParser::RuleAssignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(245);
    match(MapleGrammarParser::T__22);
    setState(246);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AccessorTabContext ------------------------------------------------------------------

MapleGrammarParser::AccessorTabContext::AccessorTabContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MapleGrammarParser::AccessorTabContext::ID() {
  return getToken(MapleGrammarParser::ID, 0);
}

MapleGrammarParser::ExprContext* MapleGrammarParser::AccessorTabContext::expr() {
  return getRuleContext<MapleGrammarParser::ExprContext>(0);
}


size_t MapleGrammarParser::AccessorTabContext::getRuleIndex() const {
  return MapleGrammarParser::RuleAccessorTab;
}

antlrcpp::Any MapleGrammarParser::AccessorTabContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitAccessorTab(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::AccessorTabContext* MapleGrammarParser::accessorTab() {
  AccessorTabContext *_localctx = _tracker.createInstance<AccessorTabContext>(_ctx, getState());
  enterRule(_localctx, 48, MapleGrammarParser::RuleAccessorTab);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(248);
    match(MapleGrammarParser::ID);
    setState(249);
    match(MapleGrammarParser::T__36);
    setState(250);
    expr(0);
    setState(251);
    match(MapleGrammarParser::T__37);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AccessorVarContext ------------------------------------------------------------------

MapleGrammarParser::AccessorVarContext::AccessorVarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MapleGrammarParser::AccessorVarContext::ID() {
  return getToken(MapleGrammarParser::ID, 0);
}


size_t MapleGrammarParser::AccessorVarContext::getRuleIndex() const {
  return MapleGrammarParser::RuleAccessorVar;
}

antlrcpp::Any MapleGrammarParser::AccessorVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitAccessorVar(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::AccessorVarContext* MapleGrammarParser::accessorVar() {
  AccessorVarContext *_localctx = _tracker.createInstance<AccessorVarContext>(_ctx, getState());
  enterRule(_localctx, 50, MapleGrammarParser::RuleAccessorVar);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(253);
    match(MapleGrammarParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AccessorFunctionContext ------------------------------------------------------------------

MapleGrammarParser::AccessorFunctionContext::AccessorFunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MapleGrammarParser::AccessorFunctionContext::ID() {
  return getToken(MapleGrammarParser::ID, 0);
}

MapleGrammarParser::ArgumentListContext* MapleGrammarParser::AccessorFunctionContext::argumentList() {
  return getRuleContext<MapleGrammarParser::ArgumentListContext>(0);
}


size_t MapleGrammarParser::AccessorFunctionContext::getRuleIndex() const {
  return MapleGrammarParser::RuleAccessorFunction;
}

antlrcpp::Any MapleGrammarParser::AccessorFunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitAccessorFunction(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::AccessorFunctionContext* MapleGrammarParser::accessorFunction() {
  AccessorFunctionContext *_localctx = _tracker.createInstance<AccessorFunctionContext>(_ctx, getState());
  enterRule(_localctx, 52, MapleGrammarParser::RuleAccessorFunction);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(255);
    match(MapleGrammarParser::ID);
    setState(256);
    match(MapleGrammarParser::T__34);
    setState(257);
    argumentList();
    setState(258);
    match(MapleGrammarParser::T__35);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LeftValueContext ------------------------------------------------------------------

MapleGrammarParser::LeftValueContext::LeftValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MapleGrammarParser::AccessorTabContext* MapleGrammarParser::LeftValueContext::accessorTab() {
  return getRuleContext<MapleGrammarParser::AccessorTabContext>(0);
}

MapleGrammarParser::AccessorVarContext* MapleGrammarParser::LeftValueContext::accessorVar() {
  return getRuleContext<MapleGrammarParser::AccessorVarContext>(0);
}


size_t MapleGrammarParser::LeftValueContext::getRuleIndex() const {
  return MapleGrammarParser::RuleLeftValue;
}

antlrcpp::Any MapleGrammarParser::LeftValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitLeftValue(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::LeftValueContext* MapleGrammarParser::leftValue() {
  LeftValueContext *_localctx = _tracker.createInstance<LeftValueContext>(_ctx, getState());
  enterRule(_localctx, 54, MapleGrammarParser::RuleLeftValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(262);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(260);
      accessorTab();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(261);
      accessorVar();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AccessorContext ------------------------------------------------------------------

MapleGrammarParser::AccessorContext::AccessorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MapleGrammarParser::LeftValueContext* MapleGrammarParser::AccessorContext::leftValue() {
  return getRuleContext<MapleGrammarParser::LeftValueContext>(0);
}

MapleGrammarParser::AccessorFunctionContext* MapleGrammarParser::AccessorContext::accessorFunction() {
  return getRuleContext<MapleGrammarParser::AccessorFunctionContext>(0);
}


size_t MapleGrammarParser::AccessorContext::getRuleIndex() const {
  return MapleGrammarParser::RuleAccessor;
}

antlrcpp::Any MapleGrammarParser::AccessorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitAccessor(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::AccessorContext* MapleGrammarParser::accessor() {
  AccessorContext *_localctx = _tracker.createInstance<AccessorContext>(_ctx, getState());
  enterRule(_localctx, 56, MapleGrammarParser::RuleAccessor);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(266);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(264);
      leftValue();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(265);
      accessorFunction();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStatementContext ------------------------------------------------------------------

MapleGrammarParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MapleGrammarParser::ExprContext* MapleGrammarParser::IfStatementContext::expr() {
  return getRuleContext<MapleGrammarParser::ExprContext>(0);
}

MapleGrammarParser::InstructionContext* MapleGrammarParser::IfStatementContext::instruction() {
  return getRuleContext<MapleGrammarParser::InstructionContext>(0);
}

MapleGrammarParser::ElseStatementContext* MapleGrammarParser::IfStatementContext::elseStatement() {
  return getRuleContext<MapleGrammarParser::ElseStatementContext>(0);
}


size_t MapleGrammarParser::IfStatementContext::getRuleIndex() const {
  return MapleGrammarParser::RuleIfStatement;
}

antlrcpp::Any MapleGrammarParser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitIfStatement(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::IfStatementContext* MapleGrammarParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 58, MapleGrammarParser::RuleIfStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(268);
    match(MapleGrammarParser::T__40);
    setState(269);
    match(MapleGrammarParser::T__34);
    setState(270);
    expr(0);
    setState(271);
    match(MapleGrammarParser::T__35);
    setState(272);
    instruction();
    setState(274);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      setState(273);
      elseStatement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElseStatementContext ------------------------------------------------------------------

MapleGrammarParser::ElseStatementContext::ElseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MapleGrammarParser::InstructionContext* MapleGrammarParser::ElseStatementContext::instruction() {
  return getRuleContext<MapleGrammarParser::InstructionContext>(0);
}


size_t MapleGrammarParser::ElseStatementContext::getRuleIndex() const {
  return MapleGrammarParser::RuleElseStatement;
}

antlrcpp::Any MapleGrammarParser::ElseStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitElseStatement(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::ElseStatementContext* MapleGrammarParser::elseStatement() {
  ElseStatementContext *_localctx = _tracker.createInstance<ElseStatementContext>(_ctx, getState());
  enterRule(_localctx, 60, MapleGrammarParser::RuleElseStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(276);
    match(MapleGrammarParser::T__41);
    setState(277);
    instruction();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStatementContext ------------------------------------------------------------------

MapleGrammarParser::WhileStatementContext::WhileStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MapleGrammarParser::ExprContext* MapleGrammarParser::WhileStatementContext::expr() {
  return getRuleContext<MapleGrammarParser::ExprContext>(0);
}

MapleGrammarParser::InstructionContext* MapleGrammarParser::WhileStatementContext::instruction() {
  return getRuleContext<MapleGrammarParser::InstructionContext>(0);
}


size_t MapleGrammarParser::WhileStatementContext::getRuleIndex() const {
  return MapleGrammarParser::RuleWhileStatement;
}

antlrcpp::Any MapleGrammarParser::WhileStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitWhileStatement(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::WhileStatementContext* MapleGrammarParser::whileStatement() {
  WhileStatementContext *_localctx = _tracker.createInstance<WhileStatementContext>(_ctx, getState());
  enterRule(_localctx, 62, MapleGrammarParser::RuleWhileStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(279);
    match(MapleGrammarParser::T__42);
    setState(280);
    match(MapleGrammarParser::T__34);
    setState(281);
    expr(0);
    setState(282);
    match(MapleGrammarParser::T__35);
    setState(283);
    instruction();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclarationContext ------------------------------------------------------------------

MapleGrammarParser::FunctionDeclarationContext::FunctionDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MapleGrammarParser::FunctionDeclarationContext::ID() {
  return getToken(MapleGrammarParser::ID, 0);
}

tree::TerminalNode* MapleGrammarParser::FunctionDeclarationContext::SC() {
  return getToken(MapleGrammarParser::SC, 0);
}

tree::TerminalNode* MapleGrammarParser::FunctionDeclarationContext::TYPE() {
  return getToken(MapleGrammarParser::TYPE, 0);
}

std::vector<tree::TerminalNode *> MapleGrammarParser::FunctionDeclarationContext::TYPE_VOID() {
  return getTokens(MapleGrammarParser::TYPE_VOID);
}

tree::TerminalNode* MapleGrammarParser::FunctionDeclarationContext::TYPE_VOID(size_t i) {
  return getToken(MapleGrammarParser::TYPE_VOID, i);
}

MapleGrammarParser::TypeListWithoutNameContext* MapleGrammarParser::FunctionDeclarationContext::typeListWithoutName() {
  return getRuleContext<MapleGrammarParser::TypeListWithoutNameContext>(0);
}


size_t MapleGrammarParser::FunctionDeclarationContext::getRuleIndex() const {
  return MapleGrammarParser::RuleFunctionDeclaration;
}

antlrcpp::Any MapleGrammarParser::FunctionDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitFunctionDeclaration(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::FunctionDeclarationContext* MapleGrammarParser::functionDeclaration() {
  FunctionDeclarationContext *_localctx = _tracker.createInstance<FunctionDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 64, MapleGrammarParser::RuleFunctionDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(285);
    _la = _input->LA(1);
    if (!(_la == MapleGrammarParser::TYPE

    || _la == MapleGrammarParser::TYPE_VOID)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(286);
    match(MapleGrammarParser::ID);
    setState(287);
    match(MapleGrammarParser::T__34);
    setState(290);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MapleGrammarParser::TYPE: {
        setState(288);
        typeListWithoutName();
        break;
      }

      case MapleGrammarParser::TYPE_VOID: {
        setState(289);
        match(MapleGrammarParser::TYPE_VOID);
        break;
      }

      case MapleGrammarParser::T__35: {
        break;
      }

    default:
      break;
    }
    setState(292);
    match(MapleGrammarParser::T__35);
    setState(293);
    match(MapleGrammarParser::SC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDefinitionContext ------------------------------------------------------------------

MapleGrammarParser::FunctionDefinitionContext::FunctionDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MapleGrammarParser::FunctionDefinitionContext::ID() {
  return getToken(MapleGrammarParser::ID, 0);
}

MapleGrammarParser::BlockFunctionContext* MapleGrammarParser::FunctionDefinitionContext::blockFunction() {
  return getRuleContext<MapleGrammarParser::BlockFunctionContext>(0);
}

tree::TerminalNode* MapleGrammarParser::FunctionDefinitionContext::TYPE() {
  return getToken(MapleGrammarParser::TYPE, 0);
}

std::vector<tree::TerminalNode *> MapleGrammarParser::FunctionDefinitionContext::TYPE_VOID() {
  return getTokens(MapleGrammarParser::TYPE_VOID);
}

tree::TerminalNode* MapleGrammarParser::FunctionDefinitionContext::TYPE_VOID(size_t i) {
  return getToken(MapleGrammarParser::TYPE_VOID, i);
}

MapleGrammarParser::TypeListContext* MapleGrammarParser::FunctionDefinitionContext::typeList() {
  return getRuleContext<MapleGrammarParser::TypeListContext>(0);
}


size_t MapleGrammarParser::FunctionDefinitionContext::getRuleIndex() const {
  return MapleGrammarParser::RuleFunctionDefinition;
}

antlrcpp::Any MapleGrammarParser::FunctionDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitFunctionDefinition(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::FunctionDefinitionContext* MapleGrammarParser::functionDefinition() {
  FunctionDefinitionContext *_localctx = _tracker.createInstance<FunctionDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 66, MapleGrammarParser::RuleFunctionDefinition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(295);
    _la = _input->LA(1);
    if (!(_la == MapleGrammarParser::TYPE

    || _la == MapleGrammarParser::TYPE_VOID)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(296);
    match(MapleGrammarParser::ID);
    setState(297);
    match(MapleGrammarParser::T__34);
    setState(300);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MapleGrammarParser::TYPE: {
        setState(298);
        typeList();
        break;
      }

      case MapleGrammarParser::TYPE_VOID: {
        setState(299);
        match(MapleGrammarParser::TYPE_VOID);
        break;
      }

      case MapleGrammarParser::T__35: {
        break;
      }

    default:
      break;
    }
    setState(302);
    match(MapleGrammarParser::T__35);
    setState(303);
    blockFunction();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

MapleGrammarParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MapleGrammarParser::ExprContext* MapleGrammarParser::ReturnStatementContext::expr() {
  return getRuleContext<MapleGrammarParser::ExprContext>(0);
}

tree::TerminalNode* MapleGrammarParser::ReturnStatementContext::SC() {
  return getToken(MapleGrammarParser::SC, 0);
}


size_t MapleGrammarParser::ReturnStatementContext::getRuleIndex() const {
  return MapleGrammarParser::RuleReturnStatement;
}

antlrcpp::Any MapleGrammarParser::ReturnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitReturnStatement(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::ReturnStatementContext* MapleGrammarParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 68, MapleGrammarParser::RuleReturnStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(305);
    match(MapleGrammarParser::T__43);
    setState(306);
    expr(0);
    setState(307);
    match(MapleGrammarParser::SC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockFunctionContext ------------------------------------------------------------------

MapleGrammarParser::BlockFunctionContext::BlockFunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MapleGrammarParser::DeclarationContext *> MapleGrammarParser::BlockFunctionContext::declaration() {
  return getRuleContexts<MapleGrammarParser::DeclarationContext>();
}

MapleGrammarParser::DeclarationContext* MapleGrammarParser::BlockFunctionContext::declaration(size_t i) {
  return getRuleContext<MapleGrammarParser::DeclarationContext>(i);
}

std::vector<MapleGrammarParser::InstructionContext *> MapleGrammarParser::BlockFunctionContext::instruction() {
  return getRuleContexts<MapleGrammarParser::InstructionContext>();
}

MapleGrammarParser::InstructionContext* MapleGrammarParser::BlockFunctionContext::instruction(size_t i) {
  return getRuleContext<MapleGrammarParser::InstructionContext>(i);
}


size_t MapleGrammarParser::BlockFunctionContext::getRuleIndex() const {
  return MapleGrammarParser::RuleBlockFunction;
}

antlrcpp::Any MapleGrammarParser::BlockFunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitBlockFunction(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::BlockFunctionContext* MapleGrammarParser::blockFunction() {
  BlockFunctionContext *_localctx = _tracker.createInstance<BlockFunctionContext>(_ctx, getState());
  enterRule(_localctx, 70, MapleGrammarParser::RuleBlockFunction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(309);
    match(MapleGrammarParser::T__38);
    setState(313);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MapleGrammarParser::TYPE) {
      setState(310);
      declaration();
      setState(315);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(319);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MapleGrammarParser::T__0)
      | (1ULL << MapleGrammarParser::T__1)
      | (1ULL << MapleGrammarParser::T__2)
      | (1ULL << MapleGrammarParser::T__3)
      | (1ULL << MapleGrammarParser::T__4)
      | (1ULL << MapleGrammarParser::T__5)
      | (1ULL << MapleGrammarParser::T__34)
      | (1ULL << MapleGrammarParser::T__38)
      | (1ULL << MapleGrammarParser::T__40)
      | (1ULL << MapleGrammarParser::T__42)
      | (1ULL << MapleGrammarParser::T__43)
      | (1ULL << MapleGrammarParser::CHAR)
      | (1ULL << MapleGrammarParser::INTEGER)
      | (1ULL << MapleGrammarParser::ID))) != 0)) {
      setState(316);
      instruction();
      setState(321);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(322);
    match(MapleGrammarParser::T__39);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentListContext ------------------------------------------------------------------

MapleGrammarParser::ArgumentListContext::ArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MapleGrammarParser::ExprContext *> MapleGrammarParser::ArgumentListContext::expr() {
  return getRuleContexts<MapleGrammarParser::ExprContext>();
}

MapleGrammarParser::ExprContext* MapleGrammarParser::ArgumentListContext::expr(size_t i) {
  return getRuleContext<MapleGrammarParser::ExprContext>(i);
}


size_t MapleGrammarParser::ArgumentListContext::getRuleIndex() const {
  return MapleGrammarParser::RuleArgumentList;
}

antlrcpp::Any MapleGrammarParser::ArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitArgumentList(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::ArgumentListContext* MapleGrammarParser::argumentList() {
  ArgumentListContext *_localctx = _tracker.createInstance<ArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 72, MapleGrammarParser::RuleArgumentList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(333);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MapleGrammarParser::T__0)
      | (1ULL << MapleGrammarParser::T__1)
      | (1ULL << MapleGrammarParser::T__2)
      | (1ULL << MapleGrammarParser::T__3)
      | (1ULL << MapleGrammarParser::T__4)
      | (1ULL << MapleGrammarParser::T__5)
      | (1ULL << MapleGrammarParser::T__34)
      | (1ULL << MapleGrammarParser::CHAR)
      | (1ULL << MapleGrammarParser::INTEGER)
      | (1ULL << MapleGrammarParser::ID))) != 0)) {
      setState(329);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(324);
          expr(0);
          setState(325);
          match(MapleGrammarParser::T__33); 
        }
        setState(331);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
      }
      setState(332);
      expr(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeListContext ------------------------------------------------------------------

MapleGrammarParser::TypeListContext::TypeListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> MapleGrammarParser::TypeListContext::TYPE() {
  return getTokens(MapleGrammarParser::TYPE);
}

tree::TerminalNode* MapleGrammarParser::TypeListContext::TYPE(size_t i) {
  return getToken(MapleGrammarParser::TYPE, i);
}

std::vector<tree::TerminalNode *> MapleGrammarParser::TypeListContext::ID() {
  return getTokens(MapleGrammarParser::ID);
}

tree::TerminalNode* MapleGrammarParser::TypeListContext::ID(size_t i) {
  return getToken(MapleGrammarParser::ID, i);
}


size_t MapleGrammarParser::TypeListContext::getRuleIndex() const {
  return MapleGrammarParser::RuleTypeList;
}

antlrcpp::Any MapleGrammarParser::TypeListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitTypeList(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::TypeListContext* MapleGrammarParser::typeList() {
  TypeListContext *_localctx = _tracker.createInstance<TypeListContext>(_ctx, getState());
  enterRule(_localctx, 74, MapleGrammarParser::RuleTypeList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(340);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(335);
        match(MapleGrammarParser::TYPE);
        setState(336);
        match(MapleGrammarParser::ID);
        setState(337);
        match(MapleGrammarParser::T__33); 
      }
      setState(342);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    }
    setState(343);
    match(MapleGrammarParser::TYPE);
    setState(344);
    match(MapleGrammarParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeListWithoutNameContext ------------------------------------------------------------------

MapleGrammarParser::TypeListWithoutNameContext::TypeListWithoutNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> MapleGrammarParser::TypeListWithoutNameContext::TYPE() {
  return getTokens(MapleGrammarParser::TYPE);
}

tree::TerminalNode* MapleGrammarParser::TypeListWithoutNameContext::TYPE(size_t i) {
  return getToken(MapleGrammarParser::TYPE, i);
}

std::vector<tree::TerminalNode *> MapleGrammarParser::TypeListWithoutNameContext::ID() {
  return getTokens(MapleGrammarParser::ID);
}

tree::TerminalNode* MapleGrammarParser::TypeListWithoutNameContext::ID(size_t i) {
  return getToken(MapleGrammarParser::ID, i);
}


size_t MapleGrammarParser::TypeListWithoutNameContext::getRuleIndex() const {
  return MapleGrammarParser::RuleTypeListWithoutName;
}

antlrcpp::Any MapleGrammarParser::TypeListWithoutNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitTypeListWithoutName(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::TypeListWithoutNameContext* MapleGrammarParser::typeListWithoutName() {
  TypeListWithoutNameContext *_localctx = _tracker.createInstance<TypeListWithoutNameContext>(_ctx, getState());
  enterRule(_localctx, 76, MapleGrammarParser::RuleTypeListWithoutName);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(353);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(346);
        match(MapleGrammarParser::TYPE);
        setState(348);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MapleGrammarParser::ID) {
          setState(347);
          match(MapleGrammarParser::ID);
        }
        setState(350);
        match(MapleGrammarParser::T__33); 
      }
      setState(355);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    }
    setState(356);
    match(MapleGrammarParser::TYPE);
    setState(358);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MapleGrammarParser::ID) {
      setState(357);
      match(MapleGrammarParser::ID);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

MapleGrammarParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MapleGrammarParser::InstructionContext *> MapleGrammarParser::BlockContext::instruction() {
  return getRuleContexts<MapleGrammarParser::InstructionContext>();
}

MapleGrammarParser::InstructionContext* MapleGrammarParser::BlockContext::instruction(size_t i) {
  return getRuleContext<MapleGrammarParser::InstructionContext>(i);
}


size_t MapleGrammarParser::BlockContext::getRuleIndex() const {
  return MapleGrammarParser::RuleBlock;
}

antlrcpp::Any MapleGrammarParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::BlockContext* MapleGrammarParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 78, MapleGrammarParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(360);
    match(MapleGrammarParser::T__38);
    setState(364);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MapleGrammarParser::T__0)
      | (1ULL << MapleGrammarParser::T__1)
      | (1ULL << MapleGrammarParser::T__2)
      | (1ULL << MapleGrammarParser::T__3)
      | (1ULL << MapleGrammarParser::T__4)
      | (1ULL << MapleGrammarParser::T__5)
      | (1ULL << MapleGrammarParser::T__34)
      | (1ULL << MapleGrammarParser::T__38)
      | (1ULL << MapleGrammarParser::T__40)
      | (1ULL << MapleGrammarParser::T__42)
      | (1ULL << MapleGrammarParser::T__43)
      | (1ULL << MapleGrammarParser::CHAR)
      | (1ULL << MapleGrammarParser::INTEGER)
      | (1ULL << MapleGrammarParser::ID))) != 0)) {
      setState(361);
      instruction();
      setState(366);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(367);
    match(MapleGrammarParser::T__39);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

MapleGrammarParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MapleGrammarParser::ExprContext* MapleGrammarParser::StatementContext::expr() {
  return getRuleContext<MapleGrammarParser::ExprContext>(0);
}

tree::TerminalNode* MapleGrammarParser::StatementContext::SC() {
  return getToken(MapleGrammarParser::SC, 0);
}


size_t MapleGrammarParser::StatementContext::getRuleIndex() const {
  return MapleGrammarParser::RuleStatement;
}

antlrcpp::Any MapleGrammarParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::StatementContext* MapleGrammarParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 80, MapleGrammarParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(369);
    expr(0);
    setState(370);
    match(MapleGrammarParser::SC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InstructionContext ------------------------------------------------------------------

MapleGrammarParser::InstructionContext::InstructionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MapleGrammarParser::StatementContext* MapleGrammarParser::InstructionContext::statement() {
  return getRuleContext<MapleGrammarParser::StatementContext>(0);
}

MapleGrammarParser::IfStatementContext* MapleGrammarParser::InstructionContext::ifStatement() {
  return getRuleContext<MapleGrammarParser::IfStatementContext>(0);
}

MapleGrammarParser::WhileStatementContext* MapleGrammarParser::InstructionContext::whileStatement() {
  return getRuleContext<MapleGrammarParser::WhileStatementContext>(0);
}

MapleGrammarParser::BlockContext* MapleGrammarParser::InstructionContext::block() {
  return getRuleContext<MapleGrammarParser::BlockContext>(0);
}

MapleGrammarParser::ReturnStatementContext* MapleGrammarParser::InstructionContext::returnStatement() {
  return getRuleContext<MapleGrammarParser::ReturnStatementContext>(0);
}


size_t MapleGrammarParser::InstructionContext::getRuleIndex() const {
  return MapleGrammarParser::RuleInstruction;
}

antlrcpp::Any MapleGrammarParser::InstructionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitInstruction(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::InstructionContext* MapleGrammarParser::instruction() {
  InstructionContext *_localctx = _tracker.createInstance<InstructionContext>(_ctx, getState());
  enterRule(_localctx, 82, MapleGrammarParser::RuleInstruction);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(377);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MapleGrammarParser::T__0:
      case MapleGrammarParser::T__1:
      case MapleGrammarParser::T__2:
      case MapleGrammarParser::T__3:
      case MapleGrammarParser::T__4:
      case MapleGrammarParser::T__5:
      case MapleGrammarParser::T__34:
      case MapleGrammarParser::CHAR:
      case MapleGrammarParser::INTEGER:
      case MapleGrammarParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(372);
        statement();
        break;
      }

      case MapleGrammarParser::T__40: {
        enterOuterAlt(_localctx, 2);
        setState(373);
        ifStatement();
        break;
      }

      case MapleGrammarParser::T__42: {
        enterOuterAlt(_localctx, 3);
        setState(374);
        whileStatement();
        break;
      }

      case MapleGrammarParser::T__38: {
        enterOuterAlt(_localctx, 4);
        setState(375);
        block();
        break;
      }

      case MapleGrammarParser::T__43: {
        enterOuterAlt(_localctx, 5);
        setState(376);
        returnStatement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool MapleGrammarParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 17: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool MapleGrammarParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 12);
    case 1: return precpred(_ctx, 11);
    case 2: return precpred(_ctx, 10);
    case 3: return precpred(_ctx, 9);
    case 4: return precpred(_ctx, 8);
    case 5: return precpred(_ctx, 7);
    case 6: return precpred(_ctx, 6);
    case 7: return precpred(_ctx, 5);
    case 8: return precpred(_ctx, 4);
    case 9: return precpred(_ctx, 3);
    case 10: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> MapleGrammarParser::_decisionToDFA;
atn::PredictionContextCache MapleGrammarParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN MapleGrammarParser::_atn;
std::vector<uint16_t> MapleGrammarParser::_serializedATN;

std::vector<std::string> MapleGrammarParser::_ruleNames = {
  "start", "program", "value", "opIncrement", "opUnaryPrefix", "opMultiplicative", 
  "opAdditive", "opBinaryShift", "opCompareRelational", "opCompareEquality", 
  "opBinaryAnd", "opBinaryXor", "opBinaryOr", "opAnd", "opOr", "opAffectation", 
  "opComma", "expr", "declarationVar", "declarationTab", "declaration", 
  "declarationVarDefinition", "definitionTab", "assignment", "accessorTab", 
  "accessorVar", "accessorFunction", "leftValue", "accessor", "ifStatement", 
  "elseStatement", "whileStatement", "functionDeclaration", "functionDefinition", 
  "returnStatement", "blockFunction", "argumentList", "typeList", "typeListWithoutName", 
  "block", "statement", "instruction"
};

std::vector<std::string> MapleGrammarParser::_literalNames = {
  "", "'++'", "'--'", "'+'", "'-'", "'!'", "'~'", "'*'", "'/'", "'%'", "'<<'", 
  "'>>'", "'<'", "'<='", "'>'", "'>='", "'=='", "'!='", "'&'", "'^'", "'|'", 
  "'&&'", "'||'", "'='", "'+='", "'-='", "'*='", "'/='", "'%='", "'<<='", 
  "'>>='", "'&='", "'^='", "'|='", "','", "'('", "')'", "'['", "']'", "'{'", 
  "'}'", "'if'", "'else'", "'while'", "'return'", "", "", "';'", "", "'void'"
};

std::vector<std::string> MapleGrammarParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "MACRO", "WS", "SC", "TYPE", "TYPE_VOID", 
  "CHAR", "INTEGER", "ID", "COMMENT", "LINE_COMMENT"
};

dfa::Vocabulary MapleGrammarParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> MapleGrammarParser::_tokenNames;

MapleGrammarParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x38, 0x17e, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x3, 
    0x2, 0x6, 0x2, 0x58, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x59, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x5, 0x3, 0x5f, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x5, 0x13, 0x93, 0xa, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x7, 0x13, 0xc1, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 0xc4, 0xb, 
    0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0xca, 0xa, 
    0x14, 0xc, 0x14, 0xe, 0x14, 0xcd, 0xb, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x5, 0x15, 0xd9, 0xa, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 
    0xdd, 0xa, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 
    0xe3, 0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0xe7, 0xa, 0x17, 0x3, 
    0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 0xee, 0xa, 
    0x18, 0xc, 0x18, 0xe, 0x18, 0xf1, 0xb, 0x18, 0x3, 0x18, 0x5, 0x18, 0xf4, 
    0xa, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
    0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 
    0x1d, 0x5, 0x1d, 0x109, 0xa, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 
    0x10d, 0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
    0x3, 0x1f, 0x5, 0x1f, 0x115, 0xa, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 
    0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x125, 
    0xa, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 
    0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x12f, 0xa, 0x23, 0x3, 0x23, 
    0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 
    0x25, 0x3, 0x25, 0x7, 0x25, 0x13a, 0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 
    0x13d, 0xb, 0x25, 0x3, 0x25, 0x7, 0x25, 0x140, 0xa, 0x25, 0xc, 0x25, 
    0xe, 0x25, 0x143, 0xb, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x26, 0x3, 0x26, 
    0x3, 0x26, 0x7, 0x26, 0x14a, 0xa, 0x26, 0xc, 0x26, 0xe, 0x26, 0x14d, 
    0xb, 0x26, 0x3, 0x26, 0x5, 0x26, 0x150, 0xa, 0x26, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x7, 0x27, 0x155, 0xa, 0x27, 0xc, 0x27, 0xe, 0x27, 0x158, 
    0xb, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x28, 0x3, 0x28, 0x5, 
    0x28, 0x15f, 0xa, 0x28, 0x3, 0x28, 0x7, 0x28, 0x162, 0xa, 0x28, 0xc, 
    0x28, 0xe, 0x28, 0x165, 0xb, 0x28, 0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 
    0x169, 0xa, 0x28, 0x3, 0x29, 0x3, 0x29, 0x7, 0x29, 0x16d, 0xa, 0x29, 
    0xc, 0x29, 0xe, 0x29, 0x170, 0xb, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 
    0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 
    0x2b, 0x5, 0x2b, 0x17c, 0xa, 0x2b, 0x3, 0x2b, 0x2, 0x3, 0x24, 0x2c, 
    0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 
    0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 
    0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 
    0x4c, 0x4e, 0x50, 0x52, 0x54, 0x2, 0xc, 0x3, 0x2, 0x34, 0x35, 0x3, 0x2, 
    0x3, 0x4, 0x3, 0x2, 0x5, 0x8, 0x3, 0x2, 0x9, 0xb, 0x3, 0x2, 0x5, 0x6, 
    0x3, 0x2, 0xc, 0xd, 0x3, 0x2, 0xe, 0x11, 0x3, 0x2, 0x12, 0x13, 0x3, 
    0x2, 0x19, 0x23, 0x3, 0x2, 0x32, 0x33, 0x2, 0x182, 0x2, 0x57, 0x3, 0x2, 
    0x2, 0x2, 0x4, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x6, 0x60, 0x3, 0x2, 0x2, 0x2, 
    0x8, 0x62, 0x3, 0x2, 0x2, 0x2, 0xa, 0x64, 0x3, 0x2, 0x2, 0x2, 0xc, 0x66, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x68, 0x3, 0x2, 0x2, 0x2, 0x10, 0x6a, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x14, 0x6e, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0x70, 0x3, 0x2, 0x2, 0x2, 0x18, 0x72, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0x74, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x76, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0x78, 0x3, 0x2, 0x2, 0x2, 0x20, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0x7c, 0x3, 0x2, 0x2, 0x2, 0x24, 0x92, 0x3, 0x2, 0x2, 0x2, 0x26, 0xc5, 
    0x3, 0x2, 0x2, 0x2, 0x28, 0xd1, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xe2, 0x3, 
    0x2, 0x2, 0x2, 0x2c, 0xe4, 0x3, 0x2, 0x2, 0x2, 0x2e, 0xe8, 0x3, 0x2, 
    0x2, 0x2, 0x30, 0xf7, 0x3, 0x2, 0x2, 0x2, 0x32, 0xfa, 0x3, 0x2, 0x2, 
    0x2, 0x34, 0xff, 0x3, 0x2, 0x2, 0x2, 0x36, 0x101, 0x3, 0x2, 0x2, 0x2, 
    0x38, 0x108, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x3c, 
    0x10e, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x116, 0x3, 0x2, 0x2, 0x2, 0x40, 0x119, 
    0x3, 0x2, 0x2, 0x2, 0x42, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x44, 0x129, 0x3, 
    0x2, 0x2, 0x2, 0x46, 0x133, 0x3, 0x2, 0x2, 0x2, 0x48, 0x137, 0x3, 0x2, 
    0x2, 0x2, 0x4a, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x156, 0x3, 0x2, 0x2, 
    0x2, 0x4e, 0x163, 0x3, 0x2, 0x2, 0x2, 0x50, 0x16a, 0x3, 0x2, 0x2, 0x2, 
    0x52, 0x173, 0x3, 0x2, 0x2, 0x2, 0x54, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x56, 
    0x58, 0x5, 0x4, 0x3, 0x2, 0x57, 0x56, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 
    0x3, 0x2, 0x2, 0x2, 0x59, 0x57, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x3, 
    0x2, 0x2, 0x2, 0x5a, 0x3, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5f, 0x5, 0x44, 
    0x23, 0x2, 0x5c, 0x5f, 0x5, 0x42, 0x22, 0x2, 0x5d, 0x5f, 0x5, 0x2a, 
    0x16, 0x2, 0x5e, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5c, 0x3, 0x2, 0x2, 
    0x2, 0x5e, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x5, 0x3, 0x2, 0x2, 0x2, 
    0x60, 0x61, 0x9, 0x2, 0x2, 0x2, 0x61, 0x7, 0x3, 0x2, 0x2, 0x2, 0x62, 
    0x63, 0x9, 0x3, 0x2, 0x2, 0x63, 0x9, 0x3, 0x2, 0x2, 0x2, 0x64, 0x65, 
    0x9, 0x4, 0x2, 0x2, 0x65, 0xb, 0x3, 0x2, 0x2, 0x2, 0x66, 0x67, 0x9, 
    0x5, 0x2, 0x2, 0x67, 0xd, 0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 0x9, 0x6, 
    0x2, 0x2, 0x69, 0xf, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 0x9, 0x7, 0x2, 
    0x2, 0x6b, 0x11, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x9, 0x8, 0x2, 0x2, 
    0x6d, 0x13, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6f, 0x9, 0x9, 0x2, 0x2, 0x6f, 
    0x15, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x7, 0x14, 0x2, 0x2, 0x71, 0x17, 
    0x3, 0x2, 0x2, 0x2, 0x72, 0x73, 0x7, 0x15, 0x2, 0x2, 0x73, 0x19, 0x3, 
    0x2, 0x2, 0x2, 0x74, 0x75, 0x7, 0x16, 0x2, 0x2, 0x75, 0x1b, 0x3, 0x2, 
    0x2, 0x2, 0x76, 0x77, 0x7, 0x17, 0x2, 0x2, 0x77, 0x1d, 0x3, 0x2, 0x2, 
    0x2, 0x78, 0x79, 0x7, 0x18, 0x2, 0x2, 0x79, 0x1f, 0x3, 0x2, 0x2, 0x2, 
    0x7a, 0x7b, 0x9, 0xa, 0x2, 0x2, 0x7b, 0x21, 0x3, 0x2, 0x2, 0x2, 0x7c, 
    0x7d, 0x7, 0x24, 0x2, 0x2, 0x7d, 0x23, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 
    0x8, 0x13, 0x1, 0x2, 0x7f, 0x93, 0x5, 0x3a, 0x1e, 0x2, 0x80, 0x93, 0x5, 
    0x6, 0x4, 0x2, 0x81, 0x82, 0x7, 0x25, 0x2, 0x2, 0x82, 0x83, 0x5, 0x24, 
    0x13, 0x2, 0x83, 0x84, 0x7, 0x26, 0x2, 0x2, 0x84, 0x93, 0x3, 0x2, 0x2, 
    0x2, 0x85, 0x86, 0x5, 0x38, 0x1d, 0x2, 0x86, 0x87, 0x5, 0x8, 0x5, 0x2, 
    0x87, 0x93, 0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0x5, 0x8, 0x5, 0x2, 0x89, 
    0x8a, 0x5, 0x38, 0x1d, 0x2, 0x8a, 0x93, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 
    0x5, 0xa, 0x6, 0x2, 0x8c, 0x8d, 0x5, 0x24, 0x13, 0xf, 0x8d, 0x93, 0x3, 
    0x2, 0x2, 0x2, 0x8e, 0x8f, 0x5, 0x38, 0x1d, 0x2, 0x8f, 0x90, 0x5, 0x20, 
    0x11, 0x2, 0x90, 0x91, 0x5, 0x24, 0x13, 0x4, 0x91, 0x93, 0x3, 0x2, 0x2, 
    0x2, 0x92, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x92, 0x80, 0x3, 0x2, 0x2, 0x2, 
    0x92, 0x81, 0x3, 0x2, 0x2, 0x2, 0x92, 0x85, 0x3, 0x2, 0x2, 0x2, 0x92, 
    0x88, 0x3, 0x2, 0x2, 0x2, 0x92, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x92, 0x8e, 
    0x3, 0x2, 0x2, 0x2, 0x93, 0xc2, 0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 0xc, 
    0xe, 0x2, 0x2, 0x95, 0x96, 0x5, 0xc, 0x7, 0x2, 0x96, 0x97, 0x5, 0x24, 
    0x13, 0xf, 0x97, 0xc1, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 0xc, 0xd, 0x2, 
    0x2, 0x99, 0x9a, 0x5, 0xe, 0x8, 0x2, 0x9a, 0x9b, 0x5, 0x24, 0x13, 0xe, 
    0x9b, 0xc1, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9d, 0xc, 0xc, 0x2, 0x2, 0x9d, 
    0x9e, 0x5, 0x10, 0x9, 0x2, 0x9e, 0x9f, 0x5, 0x24, 0x13, 0xd, 0x9f, 0xc1, 
    0x3, 0x2, 0x2, 0x2, 0xa0, 0xa1, 0xc, 0xb, 0x2, 0x2, 0xa1, 0xa2, 0x5, 
    0x12, 0xa, 0x2, 0xa2, 0xa3, 0x5, 0x24, 0x13, 0xc, 0xa3, 0xc1, 0x3, 0x2, 
    0x2, 0x2, 0xa4, 0xa5, 0xc, 0xa, 0x2, 0x2, 0xa5, 0xa6, 0x5, 0x14, 0xb, 
    0x2, 0xa6, 0xa7, 0x5, 0x24, 0x13, 0xb, 0xa7, 0xc1, 0x3, 0x2, 0x2, 0x2, 
    0xa8, 0xa9, 0xc, 0x9, 0x2, 0x2, 0xa9, 0xaa, 0x5, 0x16, 0xc, 0x2, 0xaa, 
    0xab, 0x5, 0x24, 0x13, 0xa, 0xab, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xac, 0xad, 
    0xc, 0x8, 0x2, 0x2, 0xad, 0xae, 0x5, 0x18, 0xd, 0x2, 0xae, 0xaf, 0x5, 
    0x24, 0x13, 0x9, 0xaf, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb1, 0xc, 0x7, 
    0x2, 0x2, 0xb1, 0xb2, 0x5, 0x1a, 0xe, 0x2, 0xb2, 0xb3, 0x5, 0x24, 0x13, 
    0x8, 0xb3, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb5, 0xc, 0x6, 0x2, 0x2, 
    0xb5, 0xb6, 0x5, 0x1c, 0xf, 0x2, 0xb6, 0xb7, 0x5, 0x24, 0x13, 0x7, 0xb7, 
    0xc1, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb9, 0xc, 0x5, 0x2, 0x2, 0xb9, 0xba, 
    0x5, 0x1e, 0x10, 0x2, 0xba, 0xbb, 0x5, 0x24, 0x13, 0x6, 0xbb, 0xc1, 
    0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0xc, 0x3, 0x2, 0x2, 0xbd, 0xbe, 0x5, 
    0x22, 0x12, 0x2, 0xbe, 0xbf, 0x5, 0x24, 0x13, 0x4, 0xbf, 0xc1, 0x3, 
    0x2, 0x2, 0x2, 0xc0, 0x94, 0x3, 0x2, 0x2, 0x2, 0xc0, 0x98, 0x3, 0x2, 
    0x2, 0x2, 0xc0, 0x9c, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xa0, 0x3, 0x2, 0x2, 
    0x2, 0xc0, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xa8, 0x3, 0x2, 0x2, 0x2, 
    0xc0, 0xac, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xc0, 
    0xb4, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xbc, 
    0x3, 0x2, 0x2, 0x2, 0xc1, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc0, 0x3, 
    0x2, 0x2, 0x2, 0xc2, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc3, 0x25, 0x3, 0x2, 
    0x2, 0x2, 0xc4, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xcb, 0x7, 0x32, 0x2, 
    0x2, 0xc6, 0xc7, 0x5, 0x2c, 0x17, 0x2, 0xc7, 0xc8, 0x7, 0x24, 0x2, 0x2, 
    0xc8, 0xca, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xca, 
    0xcd, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xcc, 
    0x3, 0x2, 0x2, 0x2, 0xcc, 0xce, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xcb, 0x3, 
    0x2, 0x2, 0x2, 0xce, 0xcf, 0x5, 0x2c, 0x17, 0x2, 0xcf, 0xd0, 0x7, 0x31, 
    0x2, 0x2, 0xd0, 0x27, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0x7, 0x32, 0x2, 
    0x2, 0xd2, 0xd3, 0x7, 0x36, 0x2, 0x2, 0xd3, 0xdc, 0x7, 0x27, 0x2, 0x2, 
    0xd4, 0xd5, 0x5, 0x24, 0x13, 0x2, 0xd5, 0xd6, 0x7, 0x28, 0x2, 0x2, 0xd6, 
    0xdd, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd9, 0x5, 0x24, 0x13, 0x2, 0xd8, 0xd7, 
    0x3, 0x2, 0x2, 0x2, 0xd8, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xda, 0x3, 
    0x2, 0x2, 0x2, 0xda, 0xdb, 0x7, 0x28, 0x2, 0x2, 0xdb, 0xdd, 0x5, 0x2e, 
    0x18, 0x2, 0xdc, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xd8, 0x3, 0x2, 0x2, 
    0x2, 0xdd, 0xde, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdf, 0x7, 0x31, 0x2, 0x2, 
    0xdf, 0x29, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe3, 0x5, 0x26, 0x14, 0x2, 0xe1, 
    0xe3, 0x5, 0x28, 0x15, 0x2, 0xe2, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe1, 
    0x3, 0x2, 0x2, 0x2, 0xe3, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe6, 0x7, 
    0x36, 0x2, 0x2, 0xe5, 0xe7, 0x5, 0x30, 0x19, 0x2, 0xe6, 0xe5, 0x3, 0x2, 
    0x2, 0x2, 0xe6, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe7, 0x2d, 0x3, 0x2, 0x2, 
    0x2, 0xe8, 0xe9, 0x7, 0x19, 0x2, 0x2, 0xe9, 0xf3, 0x7, 0x29, 0x2, 0x2, 
    0xea, 0xeb, 0x5, 0x6, 0x4, 0x2, 0xeb, 0xec, 0x7, 0x24, 0x2, 0x2, 0xec, 
    0xee, 0x3, 0x2, 0x2, 0x2, 0xed, 0xea, 0x3, 0x2, 0x2, 0x2, 0xee, 0xf1, 
    0x3, 0x2, 0x2, 0x2, 0xef, 0xed, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf0, 0x3, 
    0x2, 0x2, 0x2, 0xf0, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xef, 0x3, 0x2, 
    0x2, 0x2, 0xf2, 0xf4, 0x5, 0x6, 0x4, 0x2, 0xf3, 0xef, 0x3, 0x2, 0x2, 
    0x2, 0xf3, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf5, 0x3, 0x2, 0x2, 0x2, 
    0xf5, 0xf6, 0x7, 0x2a, 0x2, 0x2, 0xf6, 0x2f, 0x3, 0x2, 0x2, 0x2, 0xf7, 
    0xf8, 0x7, 0x19, 0x2, 0x2, 0xf8, 0xf9, 0x5, 0x24, 0x13, 0x2, 0xf9, 0x31, 
    0x3, 0x2, 0x2, 0x2, 0xfa, 0xfb, 0x7, 0x36, 0x2, 0x2, 0xfb, 0xfc, 0x7, 
    0x27, 0x2, 0x2, 0xfc, 0xfd, 0x5, 0x24, 0x13, 0x2, 0xfd, 0xfe, 0x7, 0x28, 
    0x2, 0x2, 0xfe, 0x33, 0x3, 0x2, 0x2, 0x2, 0xff, 0x100, 0x7, 0x36, 0x2, 
    0x2, 0x100, 0x35, 0x3, 0x2, 0x2, 0x2, 0x101, 0x102, 0x7, 0x36, 0x2, 
    0x2, 0x102, 0x103, 0x7, 0x25, 0x2, 0x2, 0x103, 0x104, 0x5, 0x4a, 0x26, 
    0x2, 0x104, 0x105, 0x7, 0x26, 0x2, 0x2, 0x105, 0x37, 0x3, 0x2, 0x2, 
    0x2, 0x106, 0x109, 0x5, 0x32, 0x1a, 0x2, 0x107, 0x109, 0x5, 0x34, 0x1b, 
    0x2, 0x108, 0x106, 0x3, 0x2, 0x2, 0x2, 0x108, 0x107, 0x3, 0x2, 0x2, 
    0x2, 0x109, 0x39, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10d, 0x5, 0x38, 0x1d, 
    0x2, 0x10b, 0x10d, 0x5, 0x36, 0x1c, 0x2, 0x10c, 0x10a, 0x3, 0x2, 0x2, 
    0x2, 0x10c, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x3b, 0x3, 0x2, 0x2, 0x2, 
    0x10e, 0x10f, 0x7, 0x2b, 0x2, 0x2, 0x10f, 0x110, 0x7, 0x25, 0x2, 0x2, 
    0x110, 0x111, 0x5, 0x24, 0x13, 0x2, 0x111, 0x112, 0x7, 0x26, 0x2, 0x2, 
    0x112, 0x114, 0x5, 0x54, 0x2b, 0x2, 0x113, 0x115, 0x5, 0x3e, 0x20, 0x2, 
    0x114, 0x113, 0x3, 0x2, 0x2, 0x2, 0x114, 0x115, 0x3, 0x2, 0x2, 0x2, 
    0x115, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x116, 0x117, 0x7, 0x2c, 0x2, 0x2, 
    0x117, 0x118, 0x5, 0x54, 0x2b, 0x2, 0x118, 0x3f, 0x3, 0x2, 0x2, 0x2, 
    0x119, 0x11a, 0x7, 0x2d, 0x2, 0x2, 0x11a, 0x11b, 0x7, 0x25, 0x2, 0x2, 
    0x11b, 0x11c, 0x5, 0x24, 0x13, 0x2, 0x11c, 0x11d, 0x7, 0x26, 0x2, 0x2, 
    0x11d, 0x11e, 0x5, 0x54, 0x2b, 0x2, 0x11e, 0x41, 0x3, 0x2, 0x2, 0x2, 
    0x11f, 0x120, 0x9, 0xb, 0x2, 0x2, 0x120, 0x121, 0x7, 0x36, 0x2, 0x2, 
    0x121, 0x124, 0x7, 0x25, 0x2, 0x2, 0x122, 0x125, 0x5, 0x4e, 0x28, 0x2, 
    0x123, 0x125, 0x7, 0x33, 0x2, 0x2, 0x124, 0x122, 0x3, 0x2, 0x2, 0x2, 
    0x124, 0x123, 0x3, 0x2, 0x2, 0x2, 0x124, 0x125, 0x3, 0x2, 0x2, 0x2, 
    0x125, 0x126, 0x3, 0x2, 0x2, 0x2, 0x126, 0x127, 0x7, 0x26, 0x2, 0x2, 
    0x127, 0x128, 0x7, 0x31, 0x2, 0x2, 0x128, 0x43, 0x3, 0x2, 0x2, 0x2, 
    0x129, 0x12a, 0x9, 0xb, 0x2, 0x2, 0x12a, 0x12b, 0x7, 0x36, 0x2, 0x2, 
    0x12b, 0x12e, 0x7, 0x25, 0x2, 0x2, 0x12c, 0x12f, 0x5, 0x4c, 0x27, 0x2, 
    0x12d, 0x12f, 0x7, 0x33, 0x2, 0x2, 0x12e, 0x12c, 0x3, 0x2, 0x2, 0x2, 
    0x12e, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x12f, 0x3, 0x2, 0x2, 0x2, 
    0x12f, 0x130, 0x3, 0x2, 0x2, 0x2, 0x130, 0x131, 0x7, 0x26, 0x2, 0x2, 
    0x131, 0x132, 0x5, 0x48, 0x25, 0x2, 0x132, 0x45, 0x3, 0x2, 0x2, 0x2, 
    0x133, 0x134, 0x7, 0x2e, 0x2, 0x2, 0x134, 0x135, 0x5, 0x24, 0x13, 0x2, 
    0x135, 0x136, 0x7, 0x31, 0x2, 0x2, 0x136, 0x47, 0x3, 0x2, 0x2, 0x2, 
    0x137, 0x13b, 0x7, 0x29, 0x2, 0x2, 0x138, 0x13a, 0x5, 0x2a, 0x16, 0x2, 
    0x139, 0x138, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x13d, 0x3, 0x2, 0x2, 0x2, 
    0x13b, 0x139, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x13c, 0x3, 0x2, 0x2, 0x2, 
    0x13c, 0x141, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13b, 0x3, 0x2, 0x2, 0x2, 
    0x13e, 0x140, 0x5, 0x54, 0x2b, 0x2, 0x13f, 0x13e, 0x3, 0x2, 0x2, 0x2, 
    0x140, 0x143, 0x3, 0x2, 0x2, 0x2, 0x141, 0x13f, 0x3, 0x2, 0x2, 0x2, 
    0x141, 0x142, 0x3, 0x2, 0x2, 0x2, 0x142, 0x144, 0x3, 0x2, 0x2, 0x2, 
    0x143, 0x141, 0x3, 0x2, 0x2, 0x2, 0x144, 0x145, 0x7, 0x2a, 0x2, 0x2, 
    0x145, 0x49, 0x3, 0x2, 0x2, 0x2, 0x146, 0x147, 0x5, 0x24, 0x13, 0x2, 
    0x147, 0x148, 0x7, 0x24, 0x2, 0x2, 0x148, 0x14a, 0x3, 0x2, 0x2, 0x2, 
    0x149, 0x146, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x14d, 0x3, 0x2, 0x2, 0x2, 
    0x14b, 0x149, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x14c, 0x3, 0x2, 0x2, 0x2, 
    0x14c, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14b, 0x3, 0x2, 0x2, 0x2, 
    0x14e, 0x150, 0x5, 0x24, 0x13, 0x2, 0x14f, 0x14b, 0x3, 0x2, 0x2, 0x2, 
    0x14f, 0x150, 0x3, 0x2, 0x2, 0x2, 0x150, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x151, 
    0x152, 0x7, 0x32, 0x2, 0x2, 0x152, 0x153, 0x7, 0x36, 0x2, 0x2, 0x153, 
    0x155, 0x7, 0x24, 0x2, 0x2, 0x154, 0x151, 0x3, 0x2, 0x2, 0x2, 0x155, 
    0x158, 0x3, 0x2, 0x2, 0x2, 0x156, 0x154, 0x3, 0x2, 0x2, 0x2, 0x156, 
    0x157, 0x3, 0x2, 0x2, 0x2, 0x157, 0x159, 0x3, 0x2, 0x2, 0x2, 0x158, 
    0x156, 0x3, 0x2, 0x2, 0x2, 0x159, 0x15a, 0x7, 0x32, 0x2, 0x2, 0x15a, 
    0x15b, 0x7, 0x36, 0x2, 0x2, 0x15b, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x15c, 
    0x15e, 0x7, 0x32, 0x2, 0x2, 0x15d, 0x15f, 0x7, 0x36, 0x2, 0x2, 0x15e, 
    0x15d, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x15f, 
    0x160, 0x3, 0x2, 0x2, 0x2, 0x160, 0x162, 0x7, 0x24, 0x2, 0x2, 0x161, 
    0x15c, 0x3, 0x2, 0x2, 0x2, 0x162, 0x165, 0x3, 0x2, 0x2, 0x2, 0x163, 
    0x161, 0x3, 0x2, 0x2, 0x2, 0x163, 0x164, 0x3, 0x2, 0x2, 0x2, 0x164, 
    0x166, 0x3, 0x2, 0x2, 0x2, 0x165, 0x163, 0x3, 0x2, 0x2, 0x2, 0x166, 
    0x168, 0x7, 0x32, 0x2, 0x2, 0x167, 0x169, 0x7, 0x36, 0x2, 0x2, 0x168, 
    0x167, 0x3, 0x2, 0x2, 0x2, 0x168, 0x169, 0x3, 0x2, 0x2, 0x2, 0x169, 
    0x4f, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x16e, 0x7, 0x29, 0x2, 0x2, 0x16b, 
    0x16d, 0x5, 0x54, 0x2b, 0x2, 0x16c, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x16d, 
    0x170, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x16c, 0x3, 0x2, 0x2, 0x2, 0x16e, 
    0x16f, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x171, 0x3, 0x2, 0x2, 0x2, 0x170, 
    0x16e, 0x3, 0x2, 0x2, 0x2, 0x171, 0x172, 0x7, 0x2a, 0x2, 0x2, 0x172, 
    0x51, 0x3, 0x2, 0x2, 0x2, 0x173, 0x174, 0x5, 0x24, 0x13, 0x2, 0x174, 
    0x175, 0x7, 0x31, 0x2, 0x2, 0x175, 0x53, 0x3, 0x2, 0x2, 0x2, 0x176, 
    0x17c, 0x5, 0x52, 0x2a, 0x2, 0x177, 0x17c, 0x5, 0x3c, 0x1f, 0x2, 0x178, 
    0x17c, 0x5, 0x40, 0x21, 0x2, 0x179, 0x17c, 0x5, 0x50, 0x29, 0x2, 0x17a, 
    0x17c, 0x5, 0x46, 0x24, 0x2, 0x17b, 0x176, 0x3, 0x2, 0x2, 0x2, 0x17b, 
    0x177, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x178, 0x3, 0x2, 0x2, 0x2, 0x17b, 
    0x179, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x17c, 
    0x55, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x59, 0x5e, 0x92, 0xc0, 0xc2, 0xcb, 
    0xd8, 0xdc, 0xe2, 0xe6, 0xef, 0xf3, 0x108, 0x10c, 0x114, 0x124, 0x12e, 
    0x13b, 0x141, 0x14b, 0x14f, 0x156, 0x15e, 0x163, 0x168, 0x16e, 0x17b, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

MapleGrammarParser::Initializer MapleGrammarParser::_init;
