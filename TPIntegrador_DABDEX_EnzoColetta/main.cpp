#include <iostream>
#include "mysql.h"

using namespace std;

void InsertData();
void DeleteData();
void UpdateData();
void SelectData(MYSQL* conexion, MYSQL_ROW fila, MYSQL_RES* resultado);


int main()
{
	MYSQL* conexion = 0;
	MYSQL_ROW fila = 0;
	MYSQL_RES* resultado = 0;

	conexion = mysql_init(0);
	conexion = mysql_real_connect(conexion, "localhost", "usr_TP", "12345", "TP_EnzoColetta", 3306, NULL, 0);

	if (conexion)
	{
		cout << "Base de datos Contectada!" << endl;
		system("pause");
		system("cls");

		int userInput;

		do
		{
			system("cls");
			cout << R"(--Seleciona que quieres hacer con la base de datos--

1.Insertar
2.Eliminar 
3.Actualizar
4.Consultar
0.Salir
)" << endl;

			cin >> userInput;
			system("cls");

			switch (userInput)
			{
			case 1:
				InsertData();
				system("pause");
				break;
			case 2:
				DeleteData();
				system("pause");
				break;
			case 3:
				UpdateData();
				system("pause");
				break;
			case 4:
				SelectData(conexion, fila, resultado);
				system("pause");
				break;
			default:
				break;
			}

		} while (userInput != 0);
	}
	else
	{
		cout << "ERROR al conectar con la Base de datos" << endl;
	}
	system("pause");
}

void InsertData()
{

}

void DeleteData()
{

}

void UpdateData()
{

}

void SelectData(MYSQL* conexion, MYSQL_ROW fila, MYSQL_RES* resultado)
{
	int userInput;
	int estado;
	string consulta;
	const char* querry;

	do
	{
		system("cls");
		cout << R"(--Seleciona que quieres consultar--

1.Alumnos
2.Cursos 
3.Materias
4.Curso alumno
5.Curso materia

0.Volver
)" << endl;

		cin >> userInput;
		system("cls");

		switch (userInput)
		{
		case 1:
			consulta = "select * from ALUMNOS";
			querry = consulta.c_str();

			estado = mysql_query(conexion, querry);

			if (!estado)
			{
				resultado = mysql_store_result(conexion);

				while (fila = mysql_fetch_row(resultado))
				{
					cout << "ID: " << fila[0] << endl;
					cout << "Apellido: " << fila[1] << endl;
					cout << "Nombre: " << fila[2] << endl;
					cout << "Fecha de nacimiento: " << fila[3] << endl;
					cout << "DNI: " << fila[4] << endl;
					cout << endl;
				}
			}
			system("pause");
			break;
		case 2:
			consulta = "select * from CURSOS";
			querry = consulta.c_str();

			estado = mysql_query(conexion, querry);

			if (!estado)
			{
				resultado = mysql_store_result(conexion);

				while (fila = mysql_fetch_row(resultado))
				{
					cout << "ID: " << fila[0] << endl;
					cout << "Curso: " << fila[1] << endl;
					cout << "Division: " << fila[2] << endl;
					cout << "Descripcion: " << fila[3] << endl;
					cout << "Nivel: " << fila[4] << endl;
					cout << endl;
				}
			}
			system("pause");
			break;
		case 3:
			consulta = "select * from MATERIAS";
			querry = consulta.c_str();

			estado = mysql_query(conexion, querry);

			if (!estado)
			{
				resultado = mysql_store_result(conexion);

				while (fila = mysql_fetch_row(resultado))
				{
					cout << "ID: " << fila[0] << endl;
					cout << "Nombre: " << fila[1] << endl;
					cout << "Nivel: " << fila[2] << endl;
					cout << endl;
				}
			}
			system("pause");
			break;
		case 4:
			consulta = "select * from CURSOALUMNO";
			querry = consulta.c_str();

			estado = mysql_query(conexion, querry);

			if (!estado)
			{
				resultado = mysql_store_result(conexion);

				while (fila = mysql_fetch_row(resultado))
				{
					cout << "IdCursoAlumno: " << fila[0] << endl;
					cout << "IdCurso: " << fila[1] << endl;
					cout << "IdAlumno: " << fila[2] << endl;
					cout << "anioLectivo: " << fila[3] << endl;
					cout << endl;
				}
			}
			system("pause");
			break;
		case 5:
			consulta = "select * from CURSOMATERIA";
			querry = consulta.c_str();

			estado = mysql_query(conexion, querry);

			if (!estado)
			{
				resultado = mysql_store_result(conexion);

				while (fila = mysql_fetch_row(resultado))
				{
					cout << "IdCursoMateria: " << fila[0] << endl;
					cout << "IdCurso: " << fila[1] << endl;
					cout << "IdMateria: " << fila[2] << endl;
					cout << "anioLectivo: " << fila[3] << endl;
					cout << endl;
				}
			}
			system("pause");
			break;
		default:
			break;
		}

	} while (userInput != 0);
}