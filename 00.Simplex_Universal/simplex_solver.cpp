#include "simplex_solver.h"




	simplex_solver::simplex_solver(simplex_data *sd)
	{

		//Inicializando modelo cplex
		_sd = sd;
		_model = IloModel(_env);
		_cplex = IloCplex(_model);
		_x = IloNumVarArray(_env);

		//Agregando variables de decisión
		for (int i = 0; i < sd->get_nVar(); i++)
		{
			_x.add(IloNumVar(_env, 0, IloInfinity, ILOFLOAT));
		}
		// Agregando función objetivo
		if (sd->get_max())
		{
			_obj = IloAdd(_model, IloMaximize(_env, 0));
		}
		else
		{
			_obj = IloAdd(_model, IloMinimize(_env, 0));
		}

		for (int i = 0; i < sd->get_nVar(); i++)
		{
			_obj.setLinearCoef(_x[i], sd->get_FunObj(i));
		}


		// RESTRICCIONES 

		// restricciones menor igual
		if (sd->get_nRestMenor() > 0)
		{
			for (int i = 0; i < sd->get_nRestMenor(); i++)
			{
				IloExpr exp(_env); // crear expresion
				for (int j = 0; j < sd->get_nVar(); j++)
				{
					exp.setLinearCoef(_x[j], sd->get_weigthMenor(i, j));
				}// fin for j
				exp -= sd->get_bMenor(i);
				_model.add(IloRange(_env, -IloInfinity, exp, 0));
				exp.end();
			}// fin for i
		}//fin if

			// restricciones mayor igual
		if (sd->get_nRestMayor() > 0)
		{
			for (int i = 0; i < sd->get_nRestMayor(); i++)
			{
				IloExpr exp(_env); // crear expresion
				for (int j = 0;j< sd->get_nVar(); j++)
				{
					exp.setLinearCoef(_x[j], sd->get_weigthMayor(i, j));
				}// fin for j
				exp -= sd->get_bMayor(i);
				_model.add(IloRange(_env, 0, exp, IloInfinity));
				exp.end();
			}// fin for i

		}// fin if

				// restricciones igualdad
		if (sd->get_nRestIgual() > 0)
		{
			for (int i = 0; i < sd->get_nRestIgual(); i++)
			{
				IloExpr exp(_env); // crear expresion
				for (int j = 0; j < sd->get_nVar(); j++)
				{
					exp.setLinearCoef(_x[j], sd->get_weigthIgual(i, j));
				}// fin for j
				exp -= sd->get_bIgual(i);
				_model.add(IloRange(_env, 0, exp, 0));
				exp.end();
			}// fin for i

		}// fin if



	}

	simplex_solver::~simplex_solver()
{
	_model.end();
	_cplex.end();
}

void simplex_solver::solve()
{
	_cplex.solve();

	cout << endl << "************ Resultados ************ " << endl;
	cout << "Valor función objetivo: " << _cplex.getObjValue() << endl;
	for(int i=0;i< _sd->get_nVar();i++)
	{
		cout << "X" << (i + 1) << ": " << _cplex.getValue(_x[i]) << endl;
	}

	report_results();
}

void simplex_solver::report_results()
{
	
	string name_results = _sd->get_name() + "_resultados.dat";
	ofstream results;
	results.open(name_results);
	
	if (results.fail()) {
		cout << "Error en archivo: " << name_results << endl;
		system("pause");
		exit(0);
	}
	else 
	{
		results << "************************** PROBLEMA **************************" << endl;
		results << _sd->tipo_problema() <<" ";
		for(int i=0;i<_sd->get_nVar();i++)// imprimir funcion objetivo
		{
		
			if(i>0)// imprimir signo adecuado
			{
			
				if(_sd->get_FunObj(i)>0)
				{
					results << " + ";
				}else
				{
					results << " - ";
				}
			}
			results << _sd->get_FunObj(i);
			results << "X" << (i + 1);
		}

		results << endl << endl << "S.A." << endl<<endl;

		/// IMPRIMIR RESTRICCIONES

		if(_sd->get_nRestMenor()>0)  // Imprimir restricciones menor-igual
		{
			for(int i=0;i< _sd->get_nRestMenor();i++)
			{
				results << "\t";
				for (int j = 0; j < _sd->get_nVar(); j++)
				{
				//ecuacion
					if (j > 0)// imprimir signo adecuado
					{

						if (_sd->get_weigthMenor(i, j) > 0)
						{
							results << " + ";
						}
						else
						{
							results << " - ";
						}
					}
					results << _sd->get_weigthMenor(i, j)<<"X"<<(j+1);
				}// fin j
				results << "<=" << _sd->get_bMenor(i) << endl;
				

			}// fin for i

		
		}//Restricciones menor igual


		if (_sd->get_nRestMayor() > 0)  // Imprimir restricciones mayor-igual
		{
			for (int i = 0; i < _sd->get_nRestMayor(); i++)
			{
				results << "\t";
				for (int j = 0; j < _sd->get_nVar(); j++)
				{
					//ecuacion
					if (j > 0)// imprimir signo adecuado
					{

						if (_sd->get_weigthMayor(i, j) > 0)
						{
							results << " + ";
						}
						else
						{
							results << " - ";
						}
					}
					results << _sd->get_weigthMayor(i, j) << "X" << (j + 1);
				}// fin j
				results << ">=" << _sd->get_bMayor(i) << endl;


			}// fin for i


		}//Restricciones mayor igual




		if (_sd->get_nRestIgual() > 0)  // Imprimir restricciones igualdad
		{
			for (int i = 0; i < _sd->get_nRestIgual(); i++)
			{
				results << "\t";
				for (int j = 0; j < _sd->get_nVar(); j++)
				{
					//ecuacion
					if (j > 0)// imprimir signo adecuado
					{

						if (_sd->get_weigthIgual(i, j) > 0)
						{
							results << " + ";
						}
						else
						{
							results << " - ";
						}
					}
					results << _sd->get_weigthIgual(i, j) << "X" << (j + 1);
				}// fin j
				results << "=" << _sd->get_bIgual(i) << endl;


			}// fin for i


		}//Restricciones igualdad


		results << endl;
		results << "************************** SOLUCION **************************" << endl;

		results <<endl<< "Valor funcion objetivo: " << _cplex.getObjValue() << endl;
		for (int i = 0; i < _sd->get_nVar(); i++)
		{
			results << "X" << (i + 1) << ": " << _cplex.getValue(_x[i]) << endl;
		}



	}
	
    
}
