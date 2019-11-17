#include "simplex_data.h"
#include "simplex_solver.h"


int main()
{
	simplex_data *ejemplo;
	ejemplo = new simplex_data("min5x14x2.dat");

	simplex_solver *solucion;
	solucion = new simplex_solver(ejemplo);
	solucion->solve();

	delete ejemplo;
	delete solucion;
	system("pause");
	return 0;
}