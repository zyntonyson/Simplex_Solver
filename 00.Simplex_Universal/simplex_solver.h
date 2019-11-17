#pragma once
#include "simplex_data.h"
#include <ilconcert/iloenv.h>
#include <ilcplex/ilocplex.h>




class simplex_solver
{
private:
	simplex_data *_sd;
	IloEnv _env;
	IloCplex _cplex;
	IloModel _model;
	IloObjective _obj;
	IloRange _cap;
	IloNumVarArray _x;

public:
	simplex_solver(simplex_data *sd);
	~simplex_solver();
	void solve();
	void report_results();
};

