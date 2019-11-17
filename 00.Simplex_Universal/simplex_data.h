#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>

using namespace std;

class simplex_data
{
private:
	int _max;
	int _nVar;
	int _nRestMenor;
	int _nRestMayor;
	int _nRestIgual;
	float **_weigthMenor;
	float **_weigthMayor;
	float **_weigthIgual;
	float *_bMenor;
	float *_bMayor;
	float *_bIgual;
	float *_FunObj;
	string _file;
	string _tipo_problem;

public:
	simplex_data(string File);
	~simplex_data();
	int get_max() { return _max; };
	int get_nVar() { return _nVar; };
	int get_nRestMenor() { return _nRestMenor; };
	int get_nRestMayor() { return _nRestMayor; };
	int get_nRestIgual() { return _nRestIgual; };
	float get_weigthMenor(int i,int j) { return _weigthMenor[i][j]; };
	float get_weigthMayor(int i, int j) { return _weigthMayor[i][j]; };
	float get_weigthIgual(int i, int j) { return _weigthIgual[i][j]; };
	float get_bMenor(int k) { return _bMenor[k]; };
	float get_bMayor(int k) { return _bMayor[k]; };
	float get_bIgual(int k) { return _bIgual[k]; };
	float get_FunObj(int k) { return _FunObj[k]; };
	string get_name() { return _file; }
	string tipo_problema() { return _tipo_problem; }
	void summary_data();
};

