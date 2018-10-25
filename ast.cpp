#include "ast.hpp"
#include <iostream>

StmtAST::~StmtAST() {

}

fdata BlockStmtAST::statistics(fdata data) const {
	for (auto e : _stmts)
		data = e->statistics(data);

	return data;
}

fdata LoopStmtAST::statistics(fdata data) const {
	data.numLoops++;
	data = _body->statistics(data);

	return data;
}

fdata CallStmtAST::statistics(fdata data) const {
	if(_name.compare(data.name) == 0)
		data.recursive = true;
	return data;
}
 
fdata AssignStmtAST::statistics(fdata data) const {
	return data;
}

fdata IfElseStmtAST::statistics(fdata data) const {
	data.numBranches++;
	data = _then->statistics(data);
	if(_else != nullptr)
		data = _else->statistics(data);

	return data;
}

fdata SwitchStmtAST::statistics(fdata data) const {
	data.numBranches++;
	for (auto e : _stmts)
		data = e->statistics(data);

	return data;	
}

fdata DeclarationStmtAST::statistics(fdata data) const {
	data.numVars += _numOfDecls;
	return data;
}

/* return-break-continue */
fdata RBCStmtAST::statistics(fdata data) const {
	return data;
}