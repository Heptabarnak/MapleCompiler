
// Generated from F:/Downloads/MapleCompiler/front-end\MapleGrammar.g4 by ANTLR 4.7


#include "MapleGrammarListener.h"
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

void MapleGrammarParser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void MapleGrammarParser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
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
    setState(77); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(76);
      program();
      setState(79); 
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

MapleGrammarParser::DeclarationContext* MapleGrammarParser::ProgramContext::declaration() {
  return getRuleContext<MapleGrammarParser::DeclarationContext>(0);
}


size_t MapleGrammarParser::ProgramContext::getRuleIndex() const {
  return MapleGrammarParser::RuleProgram;
}

void MapleGrammarParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void MapleGrammarParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
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
    setState(83);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(81);
      functionDefinition();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(82);
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

void MapleGrammarParser::ValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue(this);
}

void MapleGrammarParser::ValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue(this);
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
    setState(85);
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

//----------------- Op1Context ------------------------------------------------------------------

MapleGrammarParser::Op1Context::Op1Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MapleGrammarParser::Op1Context::getRuleIndex() const {
  return MapleGrammarParser::RuleOp1;
}

void MapleGrammarParser::Op1Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp1(this);
}

void MapleGrammarParser::Op1Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp1(this);
}


antlrcpp::Any MapleGrammarParser::Op1Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitOp1(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::Op1Context* MapleGrammarParser::op1() {
  Op1Context *_localctx = _tracker.createInstance<Op1Context>(_ctx, getState());
  enterRule(_localctx, 6, MapleGrammarParser::RuleOp1);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(87);
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

//----------------- Op2Context ------------------------------------------------------------------

MapleGrammarParser::Op2Context::Op2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MapleGrammarParser::Op2Context::getRuleIndex() const {
  return MapleGrammarParser::RuleOp2;
}

void MapleGrammarParser::Op2Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp2(this);
}

void MapleGrammarParser::Op2Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp2(this);
}


antlrcpp::Any MapleGrammarParser::Op2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitOp2(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::Op2Context* MapleGrammarParser::op2() {
  Op2Context *_localctx = _tracker.createInstance<Op2Context>(_ctx, getState());
  enterRule(_localctx, 8, MapleGrammarParser::RuleOp2);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(89);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MapleGrammarParser::T__0)
      | (1ULL << MapleGrammarParser::T__1)
      | (1ULL << MapleGrammarParser::T__2)
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

//----------------- Op3Context ------------------------------------------------------------------

MapleGrammarParser::Op3Context::Op3Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MapleGrammarParser::Op3Context::getRuleIndex() const {
  return MapleGrammarParser::RuleOp3;
}

void MapleGrammarParser::Op3Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp3(this);
}

void MapleGrammarParser::Op3Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp3(this);
}


antlrcpp::Any MapleGrammarParser::Op3Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitOp3(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::Op3Context* MapleGrammarParser::op3() {
  Op3Context *_localctx = _tracker.createInstance<Op3Context>(_ctx, getState());
  enterRule(_localctx, 10, MapleGrammarParser::RuleOp3);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(91);
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

//----------------- Op4Context ------------------------------------------------------------------

MapleGrammarParser::Op4Context::Op4Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MapleGrammarParser::Op4Context::getRuleIndex() const {
  return MapleGrammarParser::RuleOp4;
}

void MapleGrammarParser::Op4Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp4(this);
}

void MapleGrammarParser::Op4Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp4(this);
}


antlrcpp::Any MapleGrammarParser::Op4Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitOp4(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::Op4Context* MapleGrammarParser::op4() {
  Op4Context *_localctx = _tracker.createInstance<Op4Context>(_ctx, getState());
  enterRule(_localctx, 12, MapleGrammarParser::RuleOp4);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(93);
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

//----------------- Op5Context ------------------------------------------------------------------

MapleGrammarParser::Op5Context::Op5Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MapleGrammarParser::Op5Context::getRuleIndex() const {
  return MapleGrammarParser::RuleOp5;
}

void MapleGrammarParser::Op5Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp5(this);
}

void MapleGrammarParser::Op5Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp5(this);
}


antlrcpp::Any MapleGrammarParser::Op5Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitOp5(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::Op5Context* MapleGrammarParser::op5() {
  Op5Context *_localctx = _tracker.createInstance<Op5Context>(_ctx, getState());
  enterRule(_localctx, 14, MapleGrammarParser::RuleOp5);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(95);
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

//----------------- Op6Context ------------------------------------------------------------------

MapleGrammarParser::Op6Context::Op6Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MapleGrammarParser::Op6Context::getRuleIndex() const {
  return MapleGrammarParser::RuleOp6;
}

void MapleGrammarParser::Op6Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp6(this);
}

void MapleGrammarParser::Op6Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp6(this);
}


antlrcpp::Any MapleGrammarParser::Op6Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitOp6(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::Op6Context* MapleGrammarParser::op6() {
  Op6Context *_localctx = _tracker.createInstance<Op6Context>(_ctx, getState());
  enterRule(_localctx, 16, MapleGrammarParser::RuleOp6);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(97);
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

//----------------- Op7Context ------------------------------------------------------------------

MapleGrammarParser::Op7Context::Op7Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MapleGrammarParser::Op7Context::getRuleIndex() const {
  return MapleGrammarParser::RuleOp7;
}

void MapleGrammarParser::Op7Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp7(this);
}

void MapleGrammarParser::Op7Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp7(this);
}


antlrcpp::Any MapleGrammarParser::Op7Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitOp7(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::Op7Context* MapleGrammarParser::op7() {
  Op7Context *_localctx = _tracker.createInstance<Op7Context>(_ctx, getState());
  enterRule(_localctx, 18, MapleGrammarParser::RuleOp7);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(99);
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

//----------------- Op8Context ------------------------------------------------------------------

MapleGrammarParser::Op8Context::Op8Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MapleGrammarParser::Op8Context::getRuleIndex() const {
  return MapleGrammarParser::RuleOp8;
}

void MapleGrammarParser::Op8Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp8(this);
}

void MapleGrammarParser::Op8Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp8(this);
}


antlrcpp::Any MapleGrammarParser::Op8Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitOp8(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::Op8Context* MapleGrammarParser::op8() {
  Op8Context *_localctx = _tracker.createInstance<Op8Context>(_ctx, getState());
  enterRule(_localctx, 20, MapleGrammarParser::RuleOp8);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(101);
    match(MapleGrammarParser::T__17);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op9Context ------------------------------------------------------------------

MapleGrammarParser::Op9Context::Op9Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MapleGrammarParser::Op9Context::getRuleIndex() const {
  return MapleGrammarParser::RuleOp9;
}

void MapleGrammarParser::Op9Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp9(this);
}

void MapleGrammarParser::Op9Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp9(this);
}


antlrcpp::Any MapleGrammarParser::Op9Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitOp9(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::Op9Context* MapleGrammarParser::op9() {
  Op9Context *_localctx = _tracker.createInstance<Op9Context>(_ctx, getState());
  enterRule(_localctx, 22, MapleGrammarParser::RuleOp9);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(103);
    match(MapleGrammarParser::T__18);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op10Context ------------------------------------------------------------------

MapleGrammarParser::Op10Context::Op10Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MapleGrammarParser::Op10Context::getRuleIndex() const {
  return MapleGrammarParser::RuleOp10;
}

void MapleGrammarParser::Op10Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp10(this);
}

void MapleGrammarParser::Op10Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp10(this);
}


antlrcpp::Any MapleGrammarParser::Op10Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitOp10(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::Op10Context* MapleGrammarParser::op10() {
  Op10Context *_localctx = _tracker.createInstance<Op10Context>(_ctx, getState());
  enterRule(_localctx, 24, MapleGrammarParser::RuleOp10);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(105);
    match(MapleGrammarParser::T__19);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op11Context ------------------------------------------------------------------

MapleGrammarParser::Op11Context::Op11Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MapleGrammarParser::Op11Context::getRuleIndex() const {
  return MapleGrammarParser::RuleOp11;
}

void MapleGrammarParser::Op11Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp11(this);
}

void MapleGrammarParser::Op11Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp11(this);
}


antlrcpp::Any MapleGrammarParser::Op11Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitOp11(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::Op11Context* MapleGrammarParser::op11() {
  Op11Context *_localctx = _tracker.createInstance<Op11Context>(_ctx, getState());
  enterRule(_localctx, 26, MapleGrammarParser::RuleOp11);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(107);
    match(MapleGrammarParser::T__20);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op12Context ------------------------------------------------------------------

MapleGrammarParser::Op12Context::Op12Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MapleGrammarParser::Op12Context::getRuleIndex() const {
  return MapleGrammarParser::RuleOp12;
}

void MapleGrammarParser::Op12Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp12(this);
}

void MapleGrammarParser::Op12Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp12(this);
}


antlrcpp::Any MapleGrammarParser::Op12Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitOp12(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::Op12Context* MapleGrammarParser::op12() {
  Op12Context *_localctx = _tracker.createInstance<Op12Context>(_ctx, getState());
  enterRule(_localctx, 28, MapleGrammarParser::RuleOp12);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(109);
    match(MapleGrammarParser::T__21);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Op13Context ------------------------------------------------------------------

MapleGrammarParser::Op13Context::Op13Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MapleGrammarParser::Op13Context::getRuleIndex() const {
  return MapleGrammarParser::RuleOp13;
}

void MapleGrammarParser::Op13Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp13(this);
}

void MapleGrammarParser::Op13Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp13(this);
}


antlrcpp::Any MapleGrammarParser::Op13Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitOp13(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::Op13Context* MapleGrammarParser::op13() {
  Op13Context *_localctx = _tracker.createInstance<Op13Context>(_ctx, getState());
  enterRule(_localctx, 30, MapleGrammarParser::RuleOp13);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(111);
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

//----------------- ExprContext ------------------------------------------------------------------

MapleGrammarParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MapleGrammarParser::AccessorContext* MapleGrammarParser::ExprContext::accessor() {
  return getRuleContext<MapleGrammarParser::AccessorContext>(0);
}

MapleGrammarParser::ValueContext* MapleGrammarParser::ExprContext::value() {
  return getRuleContext<MapleGrammarParser::ValueContext>(0);
}

std::vector<MapleGrammarParser::ExprContext *> MapleGrammarParser::ExprContext::expr() {
  return getRuleContexts<MapleGrammarParser::ExprContext>();
}

MapleGrammarParser::ExprContext* MapleGrammarParser::ExprContext::expr(size_t i) {
  return getRuleContext<MapleGrammarParser::ExprContext>(i);
}

MapleGrammarParser::Op2Context* MapleGrammarParser::ExprContext::op2() {
  return getRuleContext<MapleGrammarParser::Op2Context>(0);
}

MapleGrammarParser::LeftValueContext* MapleGrammarParser::ExprContext::leftValue() {
  return getRuleContext<MapleGrammarParser::LeftValueContext>(0);
}

MapleGrammarParser::Op13Context* MapleGrammarParser::ExprContext::op13() {
  return getRuleContext<MapleGrammarParser::Op13Context>(0);
}

MapleGrammarParser::Op3Context* MapleGrammarParser::ExprContext::op3() {
  return getRuleContext<MapleGrammarParser::Op3Context>(0);
}

MapleGrammarParser::Op4Context* MapleGrammarParser::ExprContext::op4() {
  return getRuleContext<MapleGrammarParser::Op4Context>(0);
}

MapleGrammarParser::Op5Context* MapleGrammarParser::ExprContext::op5() {
  return getRuleContext<MapleGrammarParser::Op5Context>(0);
}

MapleGrammarParser::Op6Context* MapleGrammarParser::ExprContext::op6() {
  return getRuleContext<MapleGrammarParser::Op6Context>(0);
}

MapleGrammarParser::Op7Context* MapleGrammarParser::ExprContext::op7() {
  return getRuleContext<MapleGrammarParser::Op7Context>(0);
}

MapleGrammarParser::Op8Context* MapleGrammarParser::ExprContext::op8() {
  return getRuleContext<MapleGrammarParser::Op8Context>(0);
}

MapleGrammarParser::Op9Context* MapleGrammarParser::ExprContext::op9() {
  return getRuleContext<MapleGrammarParser::Op9Context>(0);
}

MapleGrammarParser::Op10Context* MapleGrammarParser::ExprContext::op10() {
  return getRuleContext<MapleGrammarParser::Op10Context>(0);
}

MapleGrammarParser::Op11Context* MapleGrammarParser::ExprContext::op11() {
  return getRuleContext<MapleGrammarParser::Op11Context>(0);
}

MapleGrammarParser::Op12Context* MapleGrammarParser::ExprContext::op12() {
  return getRuleContext<MapleGrammarParser::Op12Context>(0);
}

MapleGrammarParser::Op1Context* MapleGrammarParser::ExprContext::op1() {
  return getRuleContext<MapleGrammarParser::Op1Context>(0);
}


size_t MapleGrammarParser::ExprContext::getRuleIndex() const {
  return MapleGrammarParser::RuleExpr;
}

void MapleGrammarParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void MapleGrammarParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


antlrcpp::Any MapleGrammarParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
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
  size_t startState = 32;
  enterRecursionRule(_localctx, 32, MapleGrammarParser::RuleExpr, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(127);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      setState(114);
      accessor();
      break;
    }

    case 2: {
      setState(115);
      value();
      break;
    }

    case 3: {
      setState(116);
      match(MapleGrammarParser::T__33);
      setState(117);
      expr(0);
      setState(118);
      match(MapleGrammarParser::T__34);
      break;
    }

    case 4: {
      setState(120);
      op2();
      setState(121);
      expr(12);
      break;
    }

    case 5: {
      setState(123);
      leftValue();
      setState(124);
      op13();
      setState(125);
      expr(1);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(173);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(171);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(129);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(130);
          op3();
          setState(131);
          expr(12);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(133);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(134);
          op4();
          setState(135);
          expr(11);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(137);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(138);
          op5();
          setState(139);
          expr(10);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(141);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(142);
          op6();
          setState(143);
          expr(9);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(145);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(146);
          op7();
          setState(147);
          expr(8);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(149);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(150);
          op8();
          setState(151);
          expr(7);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(153);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(154);
          op9();
          setState(155);
          expr(6);
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(157);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(158);
          op10();
          setState(159);
          expr(5);
          break;
        }

        case 9: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(161);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(162);
          op11();
          setState(163);
          expr(4);
          break;
        }

        case 10: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(165);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(166);
          op12();
          setState(167);
          expr(3);
          break;
        }

        case 11: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(169);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(170);
          op1();
          break;
        }

        } 
      }
      setState(175);
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

tree::TerminalNode* MapleGrammarParser::DeclarationVarContext::ID() {
  return getToken(MapleGrammarParser::ID, 0);
}

tree::TerminalNode* MapleGrammarParser::DeclarationVarContext::SC() {
  return getToken(MapleGrammarParser::SC, 0);
}

MapleGrammarParser::AssignmentContext* MapleGrammarParser::DeclarationVarContext::assignment() {
  return getRuleContext<MapleGrammarParser::AssignmentContext>(0);
}


size_t MapleGrammarParser::DeclarationVarContext::getRuleIndex() const {
  return MapleGrammarParser::RuleDeclarationVar;
}

void MapleGrammarParser::DeclarationVarContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarationVar(this);
}

void MapleGrammarParser::DeclarationVarContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarationVar(this);
}


antlrcpp::Any MapleGrammarParser::DeclarationVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitDeclarationVar(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::DeclarationVarContext* MapleGrammarParser::declarationVar() {
  DeclarationVarContext *_localctx = _tracker.createInstance<DeclarationVarContext>(_ctx, getState());
  enterRule(_localctx, 34, MapleGrammarParser::RuleDeclarationVar);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(176);
    match(MapleGrammarParser::TYPE);
    setState(177);
    match(MapleGrammarParser::ID);
    setState(179);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MapleGrammarParser::T__22) {
      setState(178);
      assignment();
    }
    setState(181);
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

MapleGrammarParser::ExprContext* MapleGrammarParser::DeclarationTabContext::expr() {
  return getRuleContext<MapleGrammarParser::ExprContext>(0);
}

tree::TerminalNode* MapleGrammarParser::DeclarationTabContext::ID() {
  return getToken(MapleGrammarParser::ID, 0);
}

tree::TerminalNode* MapleGrammarParser::DeclarationTabContext::SC() {
  return getToken(MapleGrammarParser::SC, 0);
}

MapleGrammarParser::DefinitionTabContext* MapleGrammarParser::DeclarationTabContext::definitionTab() {
  return getRuleContext<MapleGrammarParser::DefinitionTabContext>(0);
}


size_t MapleGrammarParser::DeclarationTabContext::getRuleIndex() const {
  return MapleGrammarParser::RuleDeclarationTab;
}

void MapleGrammarParser::DeclarationTabContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarationTab(this);
}

void MapleGrammarParser::DeclarationTabContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarationTab(this);
}


antlrcpp::Any MapleGrammarParser::DeclarationTabContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitDeclarationTab(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::DeclarationTabContext* MapleGrammarParser::declarationTab() {
  DeclarationTabContext *_localctx = _tracker.createInstance<DeclarationTabContext>(_ctx, getState());
  enterRule(_localctx, 36, MapleGrammarParser::RuleDeclarationTab);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(183);
    match(MapleGrammarParser::TYPE);
    setState(184);
    match(MapleGrammarParser::T__35);
    setState(185);
    expr(0);
    setState(186);
    match(MapleGrammarParser::T__36);
    setState(187);
    match(MapleGrammarParser::ID);
    setState(189);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MapleGrammarParser::T__22) {
      setState(188);
      definitionTab();
    }
    setState(191);
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

void MapleGrammarParser::DeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration(this);
}

void MapleGrammarParser::DeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration(this);
}


antlrcpp::Any MapleGrammarParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::DeclarationContext* MapleGrammarParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 38, MapleGrammarParser::RuleDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(195);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(193);
      declarationVar();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(194);
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

void MapleGrammarParser::DefinitionTabContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefinitionTab(this);
}

void MapleGrammarParser::DefinitionTabContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefinitionTab(this);
}


antlrcpp::Any MapleGrammarParser::DefinitionTabContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitDefinitionTab(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::DefinitionTabContext* MapleGrammarParser::definitionTab() {
  DefinitionTabContext *_localctx = _tracker.createInstance<DefinitionTabContext>(_ctx, getState());
  enterRule(_localctx, 40, MapleGrammarParser::RuleDefinitionTab);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(197);
    match(MapleGrammarParser::T__22);
    setState(198);
    match(MapleGrammarParser::T__37);
    setState(208);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MapleGrammarParser::CHAR

    || _la == MapleGrammarParser::INTEGER) {
      setState(204);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(199);
          value();
          setState(200);
          match(MapleGrammarParser::T__38); 
        }
        setState(206);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
      }
      setState(207);
      value();
    }
    setState(210);
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

void MapleGrammarParser::AssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment(this);
}

void MapleGrammarParser::AssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment(this);
}


antlrcpp::Any MapleGrammarParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::AssignmentContext* MapleGrammarParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 42, MapleGrammarParser::RuleAssignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(212);
    match(MapleGrammarParser::T__22);
    setState(213);
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

void MapleGrammarParser::AccessorTabContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAccessorTab(this);
}

void MapleGrammarParser::AccessorTabContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAccessorTab(this);
}


antlrcpp::Any MapleGrammarParser::AccessorTabContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitAccessorTab(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::AccessorTabContext* MapleGrammarParser::accessorTab() {
  AccessorTabContext *_localctx = _tracker.createInstance<AccessorTabContext>(_ctx, getState());
  enterRule(_localctx, 44, MapleGrammarParser::RuleAccessorTab);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(215);
    match(MapleGrammarParser::ID);
    setState(216);
    match(MapleGrammarParser::T__35);
    setState(217);
    expr(0);
    setState(218);
    match(MapleGrammarParser::T__36);
   
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

void MapleGrammarParser::AccessorVarContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAccessorVar(this);
}

void MapleGrammarParser::AccessorVarContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAccessorVar(this);
}


antlrcpp::Any MapleGrammarParser::AccessorVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitAccessorVar(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::AccessorVarContext* MapleGrammarParser::accessorVar() {
  AccessorVarContext *_localctx = _tracker.createInstance<AccessorVarContext>(_ctx, getState());
  enterRule(_localctx, 46, MapleGrammarParser::RuleAccessorVar);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(220);
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

void MapleGrammarParser::AccessorFunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAccessorFunction(this);
}

void MapleGrammarParser::AccessorFunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAccessorFunction(this);
}


antlrcpp::Any MapleGrammarParser::AccessorFunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitAccessorFunction(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::AccessorFunctionContext* MapleGrammarParser::accessorFunction() {
  AccessorFunctionContext *_localctx = _tracker.createInstance<AccessorFunctionContext>(_ctx, getState());
  enterRule(_localctx, 48, MapleGrammarParser::RuleAccessorFunction);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(222);
    match(MapleGrammarParser::ID);
    setState(223);
    match(MapleGrammarParser::T__33);
    setState(224);
    argumentList();
    setState(225);
    match(MapleGrammarParser::T__34);
   
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

void MapleGrammarParser::LeftValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLeftValue(this);
}

void MapleGrammarParser::LeftValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLeftValue(this);
}


antlrcpp::Any MapleGrammarParser::LeftValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitLeftValue(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::LeftValueContext* MapleGrammarParser::leftValue() {
  LeftValueContext *_localctx = _tracker.createInstance<LeftValueContext>(_ctx, getState());
  enterRule(_localctx, 50, MapleGrammarParser::RuleLeftValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(229);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(227);
      accessorTab();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(228);
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

void MapleGrammarParser::AccessorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAccessor(this);
}

void MapleGrammarParser::AccessorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAccessor(this);
}


antlrcpp::Any MapleGrammarParser::AccessorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitAccessor(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::AccessorContext* MapleGrammarParser::accessor() {
  AccessorContext *_localctx = _tracker.createInstance<AccessorContext>(_ctx, getState());
  enterRule(_localctx, 52, MapleGrammarParser::RuleAccessor);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(233);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(231);
      leftValue();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(232);
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

//----------------- IfContext ------------------------------------------------------------------

MapleGrammarParser::IfContext::IfContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MapleGrammarParser::ExprContext* MapleGrammarParser::IfContext::expr() {
  return getRuleContext<MapleGrammarParser::ExprContext>(0);
}

MapleGrammarParser::InstructionContext* MapleGrammarParser::IfContext::instruction() {
  return getRuleContext<MapleGrammarParser::InstructionContext>(0);
}

MapleGrammarParser::ElseContext* MapleGrammarParser::IfContext::else() {
  return getRuleContext<MapleGrammarParser::ElseContext>(0);
}


size_t MapleGrammarParser::IfContext::getRuleIndex() const {
  return MapleGrammarParser::RuleIf;
}

void MapleGrammarParser::IfContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf(this);
}

void MapleGrammarParser::IfContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf(this);
}


antlrcpp::Any MapleGrammarParser::IfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitIf(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::IfContext* MapleGrammarParser::if() {
  IfContext *_localctx = _tracker.createInstance<IfContext>(_ctx, getState());
  enterRule(_localctx, 54, MapleGrammarParser::RuleIf);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(235);
    match(MapleGrammarParser::T__40);
    setState(236);
    match(MapleGrammarParser::T__33);
    setState(237);
    expr(0);
    setState(238);
    match(MapleGrammarParser::T__34);
    setState(239);
    instruction();
    setState(241);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      setState(240);
      else();
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

//----------------- ElseContext ------------------------------------------------------------------

MapleGrammarParser::ElseContext::ElseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MapleGrammarParser::InstructionContext* MapleGrammarParser::ElseContext::instruction() {
  return getRuleContext<MapleGrammarParser::InstructionContext>(0);
}


size_t MapleGrammarParser::ElseContext::getRuleIndex() const {
  return MapleGrammarParser::RuleElse;
}

void MapleGrammarParser::ElseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElse(this);
}

void MapleGrammarParser::ElseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElse(this);
}


antlrcpp::Any MapleGrammarParser::ElseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitElse(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::ElseContext* MapleGrammarParser::else() {
  ElseContext *_localctx = _tracker.createInstance<ElseContext>(_ctx, getState());
  enterRule(_localctx, 56, MapleGrammarParser::RuleElse);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(243);
    match(MapleGrammarParser::T__41);
    setState(244);
    instruction();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileContext ------------------------------------------------------------------

MapleGrammarParser::WhileContext::WhileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MapleGrammarParser::ExprContext* MapleGrammarParser::WhileContext::expr() {
  return getRuleContext<MapleGrammarParser::ExprContext>(0);
}

MapleGrammarParser::InstructionContext* MapleGrammarParser::WhileContext::instruction() {
  return getRuleContext<MapleGrammarParser::InstructionContext>(0);
}


size_t MapleGrammarParser::WhileContext::getRuleIndex() const {
  return MapleGrammarParser::RuleWhile;
}

void MapleGrammarParser::WhileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhile(this);
}

void MapleGrammarParser::WhileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhile(this);
}


antlrcpp::Any MapleGrammarParser::WhileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitWhile(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::WhileContext* MapleGrammarParser::while() {
  WhileContext *_localctx = _tracker.createInstance<WhileContext>(_ctx, getState());
  enterRule(_localctx, 58, MapleGrammarParser::RuleWhile);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(246);
    match(MapleGrammarParser::T__42);
    setState(247);
    match(MapleGrammarParser::T__33);
    setState(248);
    expr(0);
    setState(249);
    match(MapleGrammarParser::T__34);
    setState(250);
    instruction();
   
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

void MapleGrammarParser::FunctionDefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDefinition(this);
}

void MapleGrammarParser::FunctionDefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDefinition(this);
}


antlrcpp::Any MapleGrammarParser::FunctionDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitFunctionDefinition(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::FunctionDefinitionContext* MapleGrammarParser::functionDefinition() {
  FunctionDefinitionContext *_localctx = _tracker.createInstance<FunctionDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 60, MapleGrammarParser::RuleFunctionDefinition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(252);
    _la = _input->LA(1);
    if (!(_la == MapleGrammarParser::TYPE

    || _la == MapleGrammarParser::TYPE_VOID)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(253);
    match(MapleGrammarParser::ID);
    setState(254);
    match(MapleGrammarParser::T__33);
    setState(257);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MapleGrammarParser::TYPE: {
        setState(255);
        typeList();
        break;
      }

      case MapleGrammarParser::TYPE_VOID: {
        setState(256);
        match(MapleGrammarParser::TYPE_VOID);
        break;
      }

      case MapleGrammarParser::T__34: {
        break;
      }

    default:
      break;
    }
    setState(259);
    match(MapleGrammarParser::T__34);
    setState(260);
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

void MapleGrammarParser::ReturnStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStatement(this);
}

void MapleGrammarParser::ReturnStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStatement(this);
}


antlrcpp::Any MapleGrammarParser::ReturnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitReturnStatement(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::ReturnStatementContext* MapleGrammarParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 62, MapleGrammarParser::RuleReturnStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(262);
    match(MapleGrammarParser::T__43);
    setState(263);
    expr(0);
    setState(264);
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

void MapleGrammarParser::BlockFunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockFunction(this);
}

void MapleGrammarParser::BlockFunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockFunction(this);
}


antlrcpp::Any MapleGrammarParser::BlockFunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitBlockFunction(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::BlockFunctionContext* MapleGrammarParser::blockFunction() {
  BlockFunctionContext *_localctx = _tracker.createInstance<BlockFunctionContext>(_ctx, getState());
  enterRule(_localctx, 64, MapleGrammarParser::RuleBlockFunction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(266);
    match(MapleGrammarParser::T__37);
    setState(270);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MapleGrammarParser::TYPE) {
      setState(267);
      declaration();
      setState(272);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(276);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MapleGrammarParser::T__0)
      | (1ULL << MapleGrammarParser::T__1)
      | (1ULL << MapleGrammarParser::T__2)
      | (1ULL << MapleGrammarParser::T__3)
      | (1ULL << MapleGrammarParser::T__4)
      | (1ULL << MapleGrammarParser::T__5)
      | (1ULL << MapleGrammarParser::T__33)
      | (1ULL << MapleGrammarParser::T__37)
      | (1ULL << MapleGrammarParser::T__40)
      | (1ULL << MapleGrammarParser::T__42)
      | (1ULL << MapleGrammarParser::T__43)
      | (1ULL << MapleGrammarParser::CHAR)
      | (1ULL << MapleGrammarParser::INTEGER)
      | (1ULL << MapleGrammarParser::ID))) != 0)) {
      setState(273);
      instruction();
      setState(278);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(279);
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

void MapleGrammarParser::ArgumentListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgumentList(this);
}

void MapleGrammarParser::ArgumentListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgumentList(this);
}


antlrcpp::Any MapleGrammarParser::ArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitArgumentList(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::ArgumentListContext* MapleGrammarParser::argumentList() {
  ArgumentListContext *_localctx = _tracker.createInstance<ArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 66, MapleGrammarParser::RuleArgumentList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(290);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MapleGrammarParser::T__0)
      | (1ULL << MapleGrammarParser::T__1)
      | (1ULL << MapleGrammarParser::T__2)
      | (1ULL << MapleGrammarParser::T__3)
      | (1ULL << MapleGrammarParser::T__4)
      | (1ULL << MapleGrammarParser::T__5)
      | (1ULL << MapleGrammarParser::T__33)
      | (1ULL << MapleGrammarParser::CHAR)
      | (1ULL << MapleGrammarParser::INTEGER)
      | (1ULL << MapleGrammarParser::ID))) != 0)) {
      setState(286);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(281);
          expr(0);
          setState(282);
          match(MapleGrammarParser::T__38); 
        }
        setState(288);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
      }
      setState(289);
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

void MapleGrammarParser::TypeListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeList(this);
}

void MapleGrammarParser::TypeListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeList(this);
}


antlrcpp::Any MapleGrammarParser::TypeListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitTypeList(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::TypeListContext* MapleGrammarParser::typeList() {
  TypeListContext *_localctx = _tracker.createInstance<TypeListContext>(_ctx, getState());
  enterRule(_localctx, 68, MapleGrammarParser::RuleTypeList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(297);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(292);
        match(MapleGrammarParser::TYPE);
        setState(293);
        match(MapleGrammarParser::ID);
        setState(294);
        match(MapleGrammarParser::T__38); 
      }
      setState(299);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    }
    setState(300);
    match(MapleGrammarParser::TYPE);
    setState(301);
    match(MapleGrammarParser::ID);
   
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

void MapleGrammarParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void MapleGrammarParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


antlrcpp::Any MapleGrammarParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::BlockContext* MapleGrammarParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 70, MapleGrammarParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(303);
    match(MapleGrammarParser::T__37);
    setState(307);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MapleGrammarParser::T__0)
      | (1ULL << MapleGrammarParser::T__1)
      | (1ULL << MapleGrammarParser::T__2)
      | (1ULL << MapleGrammarParser::T__3)
      | (1ULL << MapleGrammarParser::T__4)
      | (1ULL << MapleGrammarParser::T__5)
      | (1ULL << MapleGrammarParser::T__33)
      | (1ULL << MapleGrammarParser::T__37)
      | (1ULL << MapleGrammarParser::T__40)
      | (1ULL << MapleGrammarParser::T__42)
      | (1ULL << MapleGrammarParser::T__43)
      | (1ULL << MapleGrammarParser::CHAR)
      | (1ULL << MapleGrammarParser::INTEGER)
      | (1ULL << MapleGrammarParser::ID))) != 0)) {
      setState(304);
      instruction();
      setState(309);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(310);
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

void MapleGrammarParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void MapleGrammarParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


antlrcpp::Any MapleGrammarParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::StatementContext* MapleGrammarParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 72, MapleGrammarParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(312);
    expr(0);
    setState(313);
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

MapleGrammarParser::IfContext* MapleGrammarParser::InstructionContext::if() {
  return getRuleContext<MapleGrammarParser::IfContext>(0);
}

MapleGrammarParser::WhileContext* MapleGrammarParser::InstructionContext::while() {
  return getRuleContext<MapleGrammarParser::WhileContext>(0);
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

void MapleGrammarParser::InstructionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInstruction(this);
}

void MapleGrammarParser::InstructionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MapleGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInstruction(this);
}


antlrcpp::Any MapleGrammarParser::InstructionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MapleGrammarVisitor*>(visitor))
    return parserVisitor->visitInstruction(this);
  else
    return visitor->visitChildren(this);
}

MapleGrammarParser::InstructionContext* MapleGrammarParser::instruction() {
  InstructionContext *_localctx = _tracker.createInstance<InstructionContext>(_ctx, getState());
  enterRule(_localctx, 74, MapleGrammarParser::RuleInstruction);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(320);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MapleGrammarParser::T__0:
      case MapleGrammarParser::T__1:
      case MapleGrammarParser::T__2:
      case MapleGrammarParser::T__3:
      case MapleGrammarParser::T__4:
      case MapleGrammarParser::T__5:
      case MapleGrammarParser::T__33:
      case MapleGrammarParser::CHAR:
      case MapleGrammarParser::INTEGER:
      case MapleGrammarParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(315);
        statement();
        break;
      }

      case MapleGrammarParser::T__40: {
        enterOuterAlt(_localctx, 2);
        setState(316);
        if();
        break;
      }

      case MapleGrammarParser::T__42: {
        enterOuterAlt(_localctx, 3);
        setState(317);
        while();
        break;
      }

      case MapleGrammarParser::T__37: {
        enterOuterAlt(_localctx, 4);
        setState(318);
        block();
        break;
      }

      case MapleGrammarParser::T__43: {
        enterOuterAlt(_localctx, 5);
        setState(319);
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
    case 16: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool MapleGrammarParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 11);
    case 1: return precpred(_ctx, 10);
    case 2: return precpred(_ctx, 9);
    case 3: return precpred(_ctx, 8);
    case 4: return precpred(_ctx, 7);
    case 5: return precpred(_ctx, 6);
    case 6: return precpred(_ctx, 5);
    case 7: return precpred(_ctx, 4);
    case 8: return precpred(_ctx, 3);
    case 9: return precpred(_ctx, 2);
    case 10: return precpred(_ctx, 13);

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
  "start", "program", "value", "op1", "op2", "op3", "op4", "op5", "op6", 
  "op7", "op8", "op9", "op10", "op11", "op12", "op13", "expr", "declarationVar", 
  "declarationTab", "declaration", "definitionTab", "assignment", "accessorTab", 
  "accessorVar", "accessorFunction", "leftValue", "accessor", "if", "else", 
  "while", "functionDefinition", "returnStatement", "blockFunction", "argumentList", 
  "typeList", "block", "statement", "instruction"
};

std::vector<std::string> MapleGrammarParser::_literalNames = {
  "", "'++'", "'--'", "'+'", "'-'", "'!'", "'~'", "'*'", "'/'", "'%'", "'<<'", 
  "'>>'", "'<'", "'<='", "'>'", "'>='", "'=='", "'!='", "'&'", "'^'", "'|'", 
  "'&&'", "'||'", "'='", "'+='", "'-='", "'*='", "'/='", "'%='", "'<<='", 
  "'>>='", "'&='", "'^='", "'|='", "'('", "')'", "'['", "']'", "'{'", "','", 
  "'}'", "'if'", "'else'", "'while'", "'return'", "", "", "';'", "", "'void'"
};

std::vector<std::string> MapleGrammarParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "MACRO", "WS", "SC", "TYPE", "TYPE_VOID", 
  "CHAR", "INTEGER", "ID"
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
    0x3, 0x36, 0x145, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x3, 0x2, 0x6, 0x2, 
    0x50, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x51, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 
    0x56, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x82, 0xa, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x7, 0x12, 0xae, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0xb1, 
    0xb, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0xb6, 0xa, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x5, 0x14, 0xc0, 0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x15, 0x3, 0x15, 0x5, 0x15, 0xc6, 0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x3, 0x16, 0x3, 0x16, 0x7, 0x16, 0xcd, 0xa, 0x16, 0xc, 0x16, 0xe, 
    0x16, 0xd0, 0xb, 0x16, 0x3, 0x16, 0x5, 0x16, 0xd3, 0xa, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 
    0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0xe8, 
    0xa, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0xec, 0xa, 0x1c, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0xf4, 
    0xa, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 
    0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x104, 0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 
    0x22, 0x7, 0x22, 0x10f, 0xa, 0x22, 0xc, 0x22, 0xe, 0x22, 0x112, 0xb, 
    0x22, 0x3, 0x22, 0x7, 0x22, 0x115, 0xa, 0x22, 0xc, 0x22, 0xe, 0x22, 
    0x118, 0xb, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 
    0x7, 0x23, 0x11f, 0xa, 0x23, 0xc, 0x23, 0xe, 0x23, 0x122, 0xb, 0x23, 
    0x3, 0x23, 0x5, 0x23, 0x125, 0xa, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x7, 0x24, 0x12a, 0xa, 0x24, 0xc, 0x24, 0xe, 0x24, 0x12d, 0xb, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 0x3, 0x25, 0x7, 0x25, 0x134, 
    0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 0x137, 0xb, 0x25, 0x3, 0x25, 0x3, 0x25, 
    0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 
    0x27, 0x3, 0x27, 0x5, 0x27, 0x143, 0xa, 0x27, 0x3, 0x27, 0x2, 0x3, 0x22, 
    0x28, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 
    0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 
    0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 
    0x4a, 0x4c, 0x2, 0xc, 0x3, 0x2, 0x34, 0x35, 0x3, 0x2, 0x3, 0x4, 0x3, 
    0x2, 0x3, 0x8, 0x3, 0x2, 0x9, 0xb, 0x3, 0x2, 0x5, 0x6, 0x3, 0x2, 0xc, 
    0xd, 0x3, 0x2, 0xe, 0x11, 0x3, 0x2, 0x12, 0x13, 0x3, 0x2, 0x19, 0x23, 
    0x3, 0x2, 0x32, 0x33, 0x2, 0x143, 0x2, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4, 
    0x55, 0x3, 0x2, 0x2, 0x2, 0x6, 0x57, 0x3, 0x2, 0x2, 0x2, 0x8, 0x59, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x5b, 0x3, 0x2, 0x2, 0x2, 0xc, 0x5d, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x10, 0x61, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0x63, 0x3, 0x2, 0x2, 0x2, 0x14, 0x65, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0x67, 0x3, 0x2, 0x2, 0x2, 0x18, 0x69, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0x6b, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x6f, 
    0x3, 0x2, 0x2, 0x2, 0x20, 0x71, 0x3, 0x2, 0x2, 0x2, 0x22, 0x81, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0xb2, 0x3, 0x2, 0x2, 0x2, 0x26, 0xb9, 0x3, 0x2, 
    0x2, 0x2, 0x28, 0xc5, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xc7, 0x3, 0x2, 0x2, 
    0x2, 0x2c, 0xd6, 0x3, 0x2, 0x2, 0x2, 0x2e, 0xd9, 0x3, 0x2, 0x2, 0x2, 
    0x30, 0xde, 0x3, 0x2, 0x2, 0x2, 0x32, 0xe0, 0x3, 0x2, 0x2, 0x2, 0x34, 
    0xe7, 0x3, 0x2, 0x2, 0x2, 0x36, 0xeb, 0x3, 0x2, 0x2, 0x2, 0x38, 0xed, 
    0x3, 0x2, 0x2, 0x2, 0x3a, 0xf5, 0x3, 0x2, 0x2, 0x2, 0x3c, 0xf8, 0x3, 
    0x2, 0x2, 0x2, 0x3e, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x40, 0x108, 0x3, 0x2, 
    0x2, 0x2, 0x42, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x44, 0x124, 0x3, 0x2, 0x2, 
    0x2, 0x46, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x48, 0x131, 0x3, 0x2, 0x2, 0x2, 
    0x4a, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x142, 0x3, 0x2, 0x2, 0x2, 0x4e, 
    0x50, 0x5, 0x4, 0x3, 0x2, 0x4f, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x50, 0x51, 
    0x3, 0x2, 0x2, 0x2, 0x51, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x3, 
    0x2, 0x2, 0x2, 0x52, 0x3, 0x3, 0x2, 0x2, 0x2, 0x53, 0x56, 0x5, 0x3e, 
    0x20, 0x2, 0x54, 0x56, 0x5, 0x28, 0x15, 0x2, 0x55, 0x53, 0x3, 0x2, 0x2, 
    0x2, 0x55, 0x54, 0x3, 0x2, 0x2, 0x2, 0x56, 0x5, 0x3, 0x2, 0x2, 0x2, 
    0x57, 0x58, 0x9, 0x2, 0x2, 0x2, 0x58, 0x7, 0x3, 0x2, 0x2, 0x2, 0x59, 
    0x5a, 0x9, 0x3, 0x2, 0x2, 0x5a, 0x9, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 
    0x9, 0x4, 0x2, 0x2, 0x5c, 0xb, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5e, 0x9, 
    0x5, 0x2, 0x2, 0x5e, 0xd, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x9, 0x6, 
    0x2, 0x2, 0x60, 0xf, 0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 0x9, 0x7, 0x2, 
    0x2, 0x62, 0x11, 0x3, 0x2, 0x2, 0x2, 0x63, 0x64, 0x9, 0x8, 0x2, 0x2, 
    0x64, 0x13, 0x3, 0x2, 0x2, 0x2, 0x65, 0x66, 0x9, 0x9, 0x2, 0x2, 0x66, 
    0x15, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x7, 0x14, 0x2, 0x2, 0x68, 0x17, 
    0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x7, 0x15, 0x2, 0x2, 0x6a, 0x19, 0x3, 
    0x2, 0x2, 0x2, 0x6b, 0x6c, 0x7, 0x16, 0x2, 0x2, 0x6c, 0x1b, 0x3, 0x2, 
    0x2, 0x2, 0x6d, 0x6e, 0x7, 0x17, 0x2, 0x2, 0x6e, 0x1d, 0x3, 0x2, 0x2, 
    0x2, 0x6f, 0x70, 0x7, 0x18, 0x2, 0x2, 0x70, 0x1f, 0x3, 0x2, 0x2, 0x2, 
    0x71, 0x72, 0x9, 0xa, 0x2, 0x2, 0x72, 0x21, 0x3, 0x2, 0x2, 0x2, 0x73, 
    0x74, 0x8, 0x12, 0x1, 0x2, 0x74, 0x82, 0x5, 0x36, 0x1c, 0x2, 0x75, 0x82, 
    0x5, 0x6, 0x4, 0x2, 0x76, 0x77, 0x7, 0x24, 0x2, 0x2, 0x77, 0x78, 0x5, 
    0x22, 0x12, 0x2, 0x78, 0x79, 0x7, 0x25, 0x2, 0x2, 0x79, 0x82, 0x3, 0x2, 
    0x2, 0x2, 0x7a, 0x7b, 0x5, 0xa, 0x6, 0x2, 0x7b, 0x7c, 0x5, 0x22, 0x12, 
    0xe, 0x7c, 0x82, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7e, 0x5, 0x34, 0x1b, 0x2, 
    0x7e, 0x7f, 0x5, 0x20, 0x11, 0x2, 0x7f, 0x80, 0x5, 0x22, 0x12, 0x3, 
    0x80, 0x82, 0x3, 0x2, 0x2, 0x2, 0x81, 0x73, 0x3, 0x2, 0x2, 0x2, 0x81, 
    0x75, 0x3, 0x2, 0x2, 0x2, 0x81, 0x76, 0x3, 0x2, 0x2, 0x2, 0x81, 0x7a, 
    0x3, 0x2, 0x2, 0x2, 0x81, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x82, 0xaf, 0x3, 
    0x2, 0x2, 0x2, 0x83, 0x84, 0xc, 0xd, 0x2, 0x2, 0x84, 0x85, 0x5, 0xc, 
    0x7, 0x2, 0x85, 0x86, 0x5, 0x22, 0x12, 0xe, 0x86, 0xae, 0x3, 0x2, 0x2, 
    0x2, 0x87, 0x88, 0xc, 0xc, 0x2, 0x2, 0x88, 0x89, 0x5, 0xe, 0x8, 0x2, 
    0x89, 0x8a, 0x5, 0x22, 0x12, 0xd, 0x8a, 0xae, 0x3, 0x2, 0x2, 0x2, 0x8b, 
    0x8c, 0xc, 0xb, 0x2, 0x2, 0x8c, 0x8d, 0x5, 0x10, 0x9, 0x2, 0x8d, 0x8e, 
    0x5, 0x22, 0x12, 0xc, 0x8e, 0xae, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 0xc, 
    0xa, 0x2, 0x2, 0x90, 0x91, 0x5, 0x12, 0xa, 0x2, 0x91, 0x92, 0x5, 0x22, 
    0x12, 0xb, 0x92, 0xae, 0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0xc, 0x9, 0x2, 
    0x2, 0x94, 0x95, 0x5, 0x14, 0xb, 0x2, 0x95, 0x96, 0x5, 0x22, 0x12, 0xa, 
    0x96, 0xae, 0x3, 0x2, 0x2, 0x2, 0x97, 0x98, 0xc, 0x8, 0x2, 0x2, 0x98, 
    0x99, 0x5, 0x16, 0xc, 0x2, 0x99, 0x9a, 0x5, 0x22, 0x12, 0x9, 0x9a, 0xae, 
    0x3, 0x2, 0x2, 0x2, 0x9b, 0x9c, 0xc, 0x7, 0x2, 0x2, 0x9c, 0x9d, 0x5, 
    0x18, 0xd, 0x2, 0x9d, 0x9e, 0x5, 0x22, 0x12, 0x8, 0x9e, 0xae, 0x3, 0x2, 
    0x2, 0x2, 0x9f, 0xa0, 0xc, 0x6, 0x2, 0x2, 0xa0, 0xa1, 0x5, 0x1a, 0xe, 
    0x2, 0xa1, 0xa2, 0x5, 0x22, 0x12, 0x7, 0xa2, 0xae, 0x3, 0x2, 0x2, 0x2, 
    0xa3, 0xa4, 0xc, 0x5, 0x2, 0x2, 0xa4, 0xa5, 0x5, 0x1c, 0xf, 0x2, 0xa5, 
    0xa6, 0x5, 0x22, 0x12, 0x6, 0xa6, 0xae, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa8, 
    0xc, 0x4, 0x2, 0x2, 0xa8, 0xa9, 0x5, 0x1e, 0x10, 0x2, 0xa9, 0xaa, 0x5, 
    0x22, 0x12, 0x5, 0xaa, 0xae, 0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 0xc, 0xf, 
    0x2, 0x2, 0xac, 0xae, 0x5, 0x8, 0x5, 0x2, 0xad, 0x83, 0x3, 0x2, 0x2, 
    0x2, 0xad, 0x87, 0x3, 0x2, 0x2, 0x2, 0xad, 0x8b, 0x3, 0x2, 0x2, 0x2, 
    0xad, 0x8f, 0x3, 0x2, 0x2, 0x2, 0xad, 0x93, 0x3, 0x2, 0x2, 0x2, 0xad, 
    0x97, 0x3, 0x2, 0x2, 0x2, 0xad, 0x9b, 0x3, 0x2, 0x2, 0x2, 0xad, 0x9f, 
    0x3, 0x2, 0x2, 0x2, 0xad, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xad, 0xa7, 0x3, 
    0x2, 0x2, 0x2, 0xad, 0xab, 0x3, 0x2, 0x2, 0x2, 0xae, 0xb1, 0x3, 0x2, 
    0x2, 0x2, 0xaf, 0xad, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb0, 0x3, 0x2, 0x2, 
    0x2, 0xb0, 0x23, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xaf, 0x3, 0x2, 0x2, 0x2, 
    0xb2, 0xb3, 0x7, 0x32, 0x2, 0x2, 0xb3, 0xb5, 0x7, 0x36, 0x2, 0x2, 0xb4, 
    0xb6, 0x5, 0x2c, 0x17, 0x2, 0xb5, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 
    0x3, 0x2, 0x2, 0x2, 0xb6, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 0x7, 
    0x31, 0x2, 0x2, 0xb8, 0x25, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xba, 0x7, 0x32, 
    0x2, 0x2, 0xba, 0xbb, 0x7, 0x26, 0x2, 0x2, 0xbb, 0xbc, 0x5, 0x22, 0x12, 
    0x2, 0xbc, 0xbd, 0x7, 0x27, 0x2, 0x2, 0xbd, 0xbf, 0x7, 0x36, 0x2, 0x2, 
    0xbe, 0xc0, 0x5, 0x2a, 0x16, 0x2, 0xbf, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xbf, 
    0xc0, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 
    0x7, 0x31, 0x2, 0x2, 0xc2, 0x27, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc6, 0x5, 
    0x24, 0x13, 0x2, 0xc4, 0xc6, 0x5, 0x26, 0x14, 0x2, 0xc5, 0xc3, 0x3, 
    0x2, 0x2, 0x2, 0xc5, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc6, 0x29, 0x3, 0x2, 
    0x2, 0x2, 0xc7, 0xc8, 0x7, 0x19, 0x2, 0x2, 0xc8, 0xd2, 0x7, 0x28, 0x2, 
    0x2, 0xc9, 0xca, 0x5, 0x6, 0x4, 0x2, 0xca, 0xcb, 0x7, 0x29, 0x2, 0x2, 
    0xcb, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xcd, 
    0xd0, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcf, 
    0x3, 0x2, 0x2, 0x2, 0xcf, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xce, 0x3, 
    0x2, 0x2, 0x2, 0xd1, 0xd3, 0x5, 0x6, 0x4, 0x2, 0xd2, 0xce, 0x3, 0x2, 
    0x2, 0x2, 0xd2, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x3, 0x2, 0x2, 
    0x2, 0xd4, 0xd5, 0x7, 0x2a, 0x2, 0x2, 0xd5, 0x2b, 0x3, 0x2, 0x2, 0x2, 
    0xd6, 0xd7, 0x7, 0x19, 0x2, 0x2, 0xd7, 0xd8, 0x5, 0x22, 0x12, 0x2, 0xd8, 
    0x2d, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xda, 0x7, 0x36, 0x2, 0x2, 0xda, 0xdb, 
    0x7, 0x26, 0x2, 0x2, 0xdb, 0xdc, 0x5, 0x22, 0x12, 0x2, 0xdc, 0xdd, 0x7, 
    0x27, 0x2, 0x2, 0xdd, 0x2f, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdf, 0x7, 0x36, 
    0x2, 0x2, 0xdf, 0x31, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 0x7, 0x36, 0x2, 
    0x2, 0xe1, 0xe2, 0x7, 0x24, 0x2, 0x2, 0xe2, 0xe3, 0x5, 0x44, 0x23, 0x2, 
    0xe3, 0xe4, 0x7, 0x25, 0x2, 0x2, 0xe4, 0x33, 0x3, 0x2, 0x2, 0x2, 0xe5, 
    0xe8, 0x5, 0x2e, 0x18, 0x2, 0xe6, 0xe8, 0x5, 0x30, 0x19, 0x2, 0xe7, 
    0xe5, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe8, 0x35, 
    0x3, 0x2, 0x2, 0x2, 0xe9, 0xec, 0x5, 0x34, 0x1b, 0x2, 0xea, 0xec, 0x5, 
    0x32, 0x1a, 0x2, 0xeb, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xea, 0x3, 0x2, 
    0x2, 0x2, 0xec, 0x37, 0x3, 0x2, 0x2, 0x2, 0xed, 0xee, 0x7, 0x2b, 0x2, 
    0x2, 0xee, 0xef, 0x7, 0x24, 0x2, 0x2, 0xef, 0xf0, 0x5, 0x22, 0x12, 0x2, 
    0xf0, 0xf1, 0x7, 0x25, 0x2, 0x2, 0xf1, 0xf3, 0x5, 0x4c, 0x27, 0x2, 0xf2, 
    0xf4, 0x5, 0x3a, 0x1e, 0x2, 0xf3, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf4, 
    0x3, 0x2, 0x2, 0x2, 0xf4, 0x39, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf6, 0x7, 
    0x2c, 0x2, 0x2, 0xf6, 0xf7, 0x5, 0x4c, 0x27, 0x2, 0xf7, 0x3b, 0x3, 0x2, 
    0x2, 0x2, 0xf8, 0xf9, 0x7, 0x2d, 0x2, 0x2, 0xf9, 0xfa, 0x7, 0x24, 0x2, 
    0x2, 0xfa, 0xfb, 0x5, 0x22, 0x12, 0x2, 0xfb, 0xfc, 0x7, 0x25, 0x2, 0x2, 
    0xfc, 0xfd, 0x5, 0x4c, 0x27, 0x2, 0xfd, 0x3d, 0x3, 0x2, 0x2, 0x2, 0xfe, 
    0xff, 0x9, 0xb, 0x2, 0x2, 0xff, 0x100, 0x7, 0x36, 0x2, 0x2, 0x100, 0x103, 
    0x7, 0x24, 0x2, 0x2, 0x101, 0x104, 0x5, 0x46, 0x24, 0x2, 0x102, 0x104, 
    0x7, 0x33, 0x2, 0x2, 0x103, 0x101, 0x3, 0x2, 0x2, 0x2, 0x103, 0x102, 
    0x3, 0x2, 0x2, 0x2, 0x103, 0x104, 0x3, 0x2, 0x2, 0x2, 0x104, 0x105, 
    0x3, 0x2, 0x2, 0x2, 0x105, 0x106, 0x7, 0x25, 0x2, 0x2, 0x106, 0x107, 
    0x5, 0x42, 0x22, 0x2, 0x107, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x108, 0x109, 
    0x7, 0x2e, 0x2, 0x2, 0x109, 0x10a, 0x5, 0x22, 0x12, 0x2, 0x10a, 0x10b, 
    0x7, 0x31, 0x2, 0x2, 0x10b, 0x41, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x110, 
    0x7, 0x28, 0x2, 0x2, 0x10d, 0x10f, 0x5, 0x28, 0x15, 0x2, 0x10e, 0x10d, 
    0x3, 0x2, 0x2, 0x2, 0x10f, 0x112, 0x3, 0x2, 0x2, 0x2, 0x110, 0x10e, 
    0x3, 0x2, 0x2, 0x2, 0x110, 0x111, 0x3, 0x2, 0x2, 0x2, 0x111, 0x116, 
    0x3, 0x2, 0x2, 0x2, 0x112, 0x110, 0x3, 0x2, 0x2, 0x2, 0x113, 0x115, 
    0x5, 0x4c, 0x27, 0x2, 0x114, 0x113, 0x3, 0x2, 0x2, 0x2, 0x115, 0x118, 
    0x3, 0x2, 0x2, 0x2, 0x116, 0x114, 0x3, 0x2, 0x2, 0x2, 0x116, 0x117, 
    0x3, 0x2, 0x2, 0x2, 0x117, 0x119, 0x3, 0x2, 0x2, 0x2, 0x118, 0x116, 
    0x3, 0x2, 0x2, 0x2, 0x119, 0x11a, 0x7, 0x2a, 0x2, 0x2, 0x11a, 0x43, 
    0x3, 0x2, 0x2, 0x2, 0x11b, 0x11c, 0x5, 0x22, 0x12, 0x2, 0x11c, 0x11d, 
    0x7, 0x29, 0x2, 0x2, 0x11d, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x11b, 
    0x3, 0x2, 0x2, 0x2, 0x11f, 0x122, 0x3, 0x2, 0x2, 0x2, 0x120, 0x11e, 
    0x3, 0x2, 0x2, 0x2, 0x120, 0x121, 0x3, 0x2, 0x2, 0x2, 0x121, 0x123, 
    0x3, 0x2, 0x2, 0x2, 0x122, 0x120, 0x3, 0x2, 0x2, 0x2, 0x123, 0x125, 
    0x5, 0x22, 0x12, 0x2, 0x124, 0x120, 0x3, 0x2, 0x2, 0x2, 0x124, 0x125, 
    0x3, 0x2, 0x2, 0x2, 0x125, 0x45, 0x3, 0x2, 0x2, 0x2, 0x126, 0x127, 0x7, 
    0x32, 0x2, 0x2, 0x127, 0x128, 0x7, 0x36, 0x2, 0x2, 0x128, 0x12a, 0x7, 
    0x29, 0x2, 0x2, 0x129, 0x126, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12d, 0x3, 
    0x2, 0x2, 0x2, 0x12b, 0x129, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12c, 0x3, 
    0x2, 0x2, 0x2, 0x12c, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12b, 0x3, 
    0x2, 0x2, 0x2, 0x12e, 0x12f, 0x7, 0x32, 0x2, 0x2, 0x12f, 0x130, 0x7, 
    0x36, 0x2, 0x2, 0x130, 0x47, 0x3, 0x2, 0x2, 0x2, 0x131, 0x135, 0x7, 
    0x28, 0x2, 0x2, 0x132, 0x134, 0x5, 0x4c, 0x27, 0x2, 0x133, 0x132, 0x3, 
    0x2, 0x2, 0x2, 0x134, 0x137, 0x3, 0x2, 0x2, 0x2, 0x135, 0x133, 0x3, 
    0x2, 0x2, 0x2, 0x135, 0x136, 0x3, 0x2, 0x2, 0x2, 0x136, 0x138, 0x3, 
    0x2, 0x2, 0x2, 0x137, 0x135, 0x3, 0x2, 0x2, 0x2, 0x138, 0x139, 0x7, 
    0x2a, 0x2, 0x2, 0x139, 0x49, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x13b, 0x5, 
    0x22, 0x12, 0x2, 0x13b, 0x13c, 0x7, 0x31, 0x2, 0x2, 0x13c, 0x4b, 0x3, 
    0x2, 0x2, 0x2, 0x13d, 0x143, 0x5, 0x4a, 0x26, 0x2, 0x13e, 0x143, 0x5, 
    0x38, 0x1d, 0x2, 0x13f, 0x143, 0x5, 0x3c, 0x1f, 0x2, 0x140, 0x143, 0x5, 
    0x48, 0x25, 0x2, 0x141, 0x143, 0x5, 0x40, 0x21, 0x2, 0x142, 0x13d, 0x3, 
    0x2, 0x2, 0x2, 0x142, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x142, 0x13f, 0x3, 
    0x2, 0x2, 0x2, 0x142, 0x140, 0x3, 0x2, 0x2, 0x2, 0x142, 0x141, 0x3, 
    0x2, 0x2, 0x2, 0x143, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x17, 0x51, 0x55, 0x81, 
    0xad, 0xaf, 0xb5, 0xbf, 0xc5, 0xce, 0xd2, 0xe7, 0xeb, 0xf3, 0x103, 0x110, 
    0x116, 0x120, 0x124, 0x12b, 0x135, 0x142, 
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
