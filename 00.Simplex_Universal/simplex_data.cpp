#include "simplex_data.h"

// Referencias: https://www.youtube.com/watch?v=AUnokGBRca8


simplex_data::simplex_data(string File)
{
	//  Cargar archivo de datos
	_file = File;
	ifstream ifile(File.c_str(), ios::in);
	if (ifile.fail()) {
		cout << "Error en archivo: " << File << endl;
		system("pause");
		exit(0);
	}
	// Maximizar o minimizar
	ifile >> _max;
	if(_max==0)
	{
		_tipo_problem = "Minimizar";
	}
	else
	{
		_tipo_problem = "Maximizar";
	}


	// Guardar datos
	ifile>> _nVar;  // Numero de variables de decision

	// Guardar función objetivo
	_FunObj = new float[_nVar];

	for(int i=0;i<_nVar;i++)
	{
		ifile >> _FunObj[i];
	}

	//******************** Guardar restricciones de tipo menor igual**********************
	ifile >> _nRestMenor;
	if(_nRestMenor>0)
	{
		
		// Guardando restricciones
		
		_weigthMenor = new float*[_nRestMenor];
		for (int i=0;i<_nRestMenor;i++)
		{
			_weigthMenor[i] = new float[_nVar];
			for(int j=0;j<_nVar;j++)
			{
			ifile >> _weigthMenor[i][j];
			}
		}

		// Guardar lados derechos

		_bMenor = new float[_nRestMenor];


		for(int i=0;i<_nRestMenor;i++)
		{
			ifile >> _bMenor[i];
		}

	}// fin de if de Restriccion


	
	// ***********Guardar restricciones de tipo mayor igual***************

	ifile >> _nRestMayor;

	if (_nRestMayor > 0)
	{
		// Guardando restricciones
		 _weigthMayor = new float*[_nRestMayor];
		for (int i = 0; i < _nRestMayor; i++)
		{
			_weigthMayor[i] = new float[_nVar];
			for (int j = 0; j < _nVar; j++)
			{

				ifile >> _weigthMayor[i][j];

			}
		}

		// Guardar lados derechos

		_bMayor = new float[_nRestMayor];


		for (int i = 0; i < _nRestMayor; i++)
		{
			ifile >> _bMayor[i];
		}

	}// fin de if de Restriccion



	// ************Guardar restricciones de tipo  igualdad**************


	ifile >> _nRestIgual;

	if (_nRestIgual > 0)
	{
		// Guardando restricciones
		_weigthIgual = new float*[_nRestIgual];
		for (int i = 0; i < _nRestMayor; i++)
		{
			_weigthIgual[i] = new float[_nVar];
			for (int j = 0; j < _nVar; j++)
			{

				ifile >> _weigthIgual[i][j];
			}
		}
		// Guardar lados derechos

		_bIgual = new float[_nRestIgual];

		for (int i = 0; i < _nRestIgual; i++)
		{
			ifile >> _bIgual[i];
		}

	}// fin de if de Restriccion


	// Cerrar archivo
	ifile.close();
	summary_data();
}


simplex_data::~simplex_data()
{

	if(_nRestMenor>0)
	{
	
		for (int i = 0; i < _nVar; i++)
		{
			delete[] _weigthMenor[i];
		}
	}

	delete  _weigthMenor;
	delete  _bMenor;

	if (_nRestMayor>0)
	{
		for (int i = 0; i < _nVar; i++)
		{
			delete[] _weigthMayor[i];
		}
	}
	
	delete  _weigthMayor;
	delete  _bMayor;

	if (_nRestIgual>0)
	{
		for (int i = 0; i < _nVar; i++)
		{
			delete[] _weigthIgual[i];
		}
	
	}
	delete  _weigthIgual;
	delete  _bIgual;
}

void simplex_data::summary_data()
{

	cout << "*********************DATOS********************" << endl;

if (_max==0)
{
	cout << "Problema de MINIMIZACION"<<endl;
}
else
{
	cout << "Problema de MAXIMIZACION" << endl;
}

cout << "Numero de variables de decision: " << _nVar << endl;
cout << "Numero de restricciones de menor-igual: " << _nRestMenor << endl;
cout << "Numero de restricciones de mayor-igual: " << _nRestMayor << endl;
cout << "Numero de restricciones de igualdad: " << _nRestIgual << endl;


}
