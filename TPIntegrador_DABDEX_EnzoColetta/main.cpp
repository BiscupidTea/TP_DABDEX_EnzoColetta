#include <iostream>
#include "mysql.h"

using namespace std;

int main()
{

	MYSQL* baseDeDatos;
	baseDeDatos = mysql_init(0);
	baseDeDatos = mysql_real_connect(baseDeDatos, "localhost", "usr_TP", "12345", "TP_EnzoColetta", 3306, NULL, 0);

	if (baseDeDatos)
	{
		cout << "Base de datos Contectada!" << endl;
	}
	else
	{
		cout << "ERROR al conectar con la Base de datos" << endl;
	}
}