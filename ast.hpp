#ifndef __AST_HPP__
#define __AST_HPP__ 1

#include <string>
#include <vector>
using namespace std;

typedef struct fdata {
	string name;
	int numVars = 0;
	int numLoops = 0;
	int numBranches = 0;
	// int typesDefined = 0;
	// int calls = 0;
	bool recursive = false;
} fdata;

 /* Hierarchy */
class StmtAST {
public:
	virtual ~StmtAST();
	virtual fdata statistics(fdata data) const = 0;
};

class BlockStmtAST : public StmtAST {
public:
	BlockStmtAST(vector<StmtAST*> stmts)
		: _stmts(stmts)
	{ }
	fdata statistics(fdata data) const;

protected:
	vector<StmtAST*> _stmts;
};

class AssignStmtAST : public StmtAST {
public:
	fdata statistics(fdata data) const;
};

class CallStmtAST : public StmtAST{
public:
	CallStmtAST(string n) : _name(n) {}
	fdata statistics(fdata data) const;
private:
	string _name;
};

class ExprAST {
public:
};

class ConstValExprAST : public ExprAST {
public:
	ConstValExprAST(string v) : _v(v) {}
private:
	string _v;	// const value
};

class VariableExprAST : public ExprAST {
public:
	VariableExprAST(string n) : _n(n) {}
private:
	string _n; // variable name
};

class CallExprAST : public ExprAST {
public:
	CallExprAST(string n) : _name(n) {}
private:
	string _name;
};

class UnaryExprAST : public ExprAST {

};

class BinaryExprAST : public ExprAST {

};

class TernaryExprAST : public ExprAST {

};

class DeclarationStmtAST : public StmtAST {
public:
	DeclarationStmtAST(int numOfDecls) : _numOfDecls(numOfDecls) {}
	fdata statistics(fdata data) const;
private:
	int _numOfDecls;
};

/* return-break-continue */
class RBCStmtAST : public StmtAST {
public:
	RBCStmtAST(ExprAST* rvalue) : _rvalue(rvalue) {}
	fdata statistics(fdata data) const;

private:
	ExprAST* _rvalue;
};

class LoopStmtAST : public StmtAST {
public:
	LoopStmtAST(ExprAST* init, ExprAST* cond, ExprAST* incr, StmtAST* body)
		:_init(init),_cond(cond),_incr(incr),_body(body) {}
	fdata statistics(fdata data) const;

private:
	ExprAST* _init;
	ExprAST* _cond;
	ExprAST* _incr;
	StmtAST* _body;
};


class IfElseStmtAST : public StmtAST {
public:
	IfElseStmtAST(ExprAST* cond, StmtAST* bodyThen, StmtAST* bodyElse)
		:_cond(cond),_then(bodyThen),_else(bodyElse) {}
	fdata statistics(fdata data) const;

private:
	ExprAST* _cond;
	StmtAST* _then;
	StmtAST* _else;
};


class SwitchStmtAST : public StmtAST {
public:
	SwitchStmtAST(ExprAST* expr, vector<ConstValExprAST*> cases, vector<StmtAST*> stmts)
		:_expr(expr),_cases(cases),_stmts(stmts) {}
	fdata statistics(fdata data) const;

private:
	ExprAST* _expr;
	vector<ConstValExprAST*> _cases;
	vector<StmtAST*> _stmts;
};

class PrototypeAST {
public:
	PrototypeAST(string n, vector<string> args)
		:_n(n), _args(args)
	{}
	string getName() const {
		return _n;
	}

private:
	string _n;
	vector<string> _args;
};

class FunctionAST {
public:
	FunctionAST(const PrototypeAST &p, StmtAST *s)
		:_proto(p), _body(s)
	{}
	~FunctionAST();
	
private:
	FunctionAST(const FunctionAST&);
	FunctionAST& operator=(const FunctionAST&);
	PrototypeAST _proto;
	StmtAST *_body;
};

#endif