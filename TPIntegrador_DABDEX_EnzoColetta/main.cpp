#include <iostream>
#include "mysql.h"

using namespace std;

void InsertData(MYSQL* conexion, MYSQL_ROW fila, MYSQL_RES* resultado);
void DeleteData(MYSQL* conexion, MYSQL_ROW fila, MYSQL_RES* resultado);
void UpdateData(MYSQL* conexion, MYSQL_ROW fila, MYSQL_RES* resultado);
void SelectData(MYSQL* conexion, MYSQL_ROW fila, MYSQL_RES* resultado);

struct alumno
{
	string nombre;
	string apellido;
	string fechaNacimiento;
	string DNI;
};

struct curso
{
	string curso;
	string division;
	string descripcion;
	string nivel;
};

struct materias
{
	string nombre;
	string nivel;
};

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
				InsertData(conexion, fila, resultado);
				system("pause");
				break;
			case 2:
				DeleteData(conexion, fila, resultado);
				system("pause");
				break;
			case 3:
				UpdateData(conexion, fila, resultado);
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

void InsertData(MYSQL* conexion, MYSQL_ROW fila, MYSQL_RES* resultado)
{
	int userInput;
	int estado;
	string insercion;
	const char* query;
	alumno nuevoAlumno;
	curso nuevoCurso;
	materias nuevaMateria;
	string id1;
	string id2;
	string id3;

	do
	{
		system("cls");
		cout << R"(--Seleciona que quieres insertar--

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
		{
			cout << "Ingresa el apellido del alumno" << endl;
			cin >> nuevoAlumno.apellido;
			cout << "Ingresa el nombre " << endl;
			cin >> nuevoAlumno.nombre;
			cout << "Ingresa el anio, mes, dia de la fecha de nacimiento, separa con - " << endl;
			cin >> nuevoAlumno.fechaNacimiento;
			cout << "Ingresa el dni" << endl;
			cin >> nuevoAlumno.DNI;

			insercion = "insert into alumnos (apellido, nombre, fechaNacimiento, dni) values ('" + nuevoAlumno.apellido + "','" + nuevoAlumno.nombre + "','" + nuevoAlumno.fechaNacimiento + "','" + nuevoAlumno.DNI + "')";

			query = insercion.c_str();
			estado = mysql_query(conexion, query);

			if (!estado)
			{
				cout << "Alumno ingresado correctamente!" << endl;
			}
			else
			{
				cout << "ERROR al ingresar alumno" << endl;
			}
		}
		case 2:
		{
			cout << "Ingresa el curso" << endl;
			cin >> nuevoCurso.curso;
			cout << "Ingresa la division " << endl;
			cin >> nuevoCurso.division;
			cout << "Ingresa una pequenia descripcion " << endl;
			cin >> nuevoCurso.descripcion;
			cout << "Ingresa el nivel" << endl;
			cin >> nuevoCurso.nivel;

			insercion = "insert into cursos (curso, division, descripcion, nivel) values ('" + nuevoCurso.curso + "','" + nuevoCurso.division + "','" + nuevoCurso.descripcion + "','" + nuevoCurso.nivel + "')";

			query = insercion.c_str();
			estado = mysql_query(conexion, query);

			if (!estado)
			{
				cout << "Curso ingresado correctamente!" << endl;
			}
			else
			{
				cout << "ERROR al ingresar curso" << endl;
			}
		}
			break;
		case 3:
		{
			cout << "Ingresa la materia" << endl;
			cin >> nuevaMateria.nombre;
			cout << "Ingresa el nivel " << endl;
			cin >> nuevaMateria.nivel;

			insercion = "insert into materias (nombreMateria, nivel) values ('" + nuevaMateria.nombre + "','" + nuevaMateria.nivel + "')";

			query = insercion.c_str();
			estado = mysql_query(conexion, query);

			if (!estado)
			{
				cout << "Materia ingresada correctamente!" << endl;
			}
			else
			{
				cout << "ERROR al ingresar materia" << endl;
			}
		}
			break;
		case 4:
		{
			cout << "Ingresa el id del curso" << endl;
			cin >> id1;
			cout << "Ingresa el id del alumno " << endl;
			cin >> id2;
			cout << "Ingresa el anio lectivo " << endl;
			cin >> id3;

			insercion = "insert into cursoAlumno (idCurso, idAlumno, anio_lectivo) values ('" + id1 + "','" + id2 + "','" + id3 + "')";

			query = insercion.c_str();
			estado = mysql_query(conexion, query);

			if (!estado)
			{
				cout << "Curso alumno ingresado correctamente!" << endl;
			}
			else
			{
				cout << "ERROR al ingresar curso alumno" << endl;
			}
		}
			break;
		case 5:
		{
			cout << "Ingresa el id del curso" << endl;
			cin >> id1;
			cout << "Ingresa el id de la materia " << endl;
			cin >> id2;
			cout << "Ingresa el anio lectivo " << endl;
			cin >> id3;

			insercion = "insert into cursoMateria (idCurso, idMateria, anio_lectivo) values ('" + id1 + "','" + id2 + "','" + id3 + "')";

			query = insercion.c_str();
			estado = mysql_query(conexion, query);

			if (!estado)
			{
				cout << "Curso materia ingresado correctamente!" << endl;
			}
			else
			{
				cout << "ERROR al ingresar curso materia" << endl;
			}
		}
			break;
		default:
			break;
		}
		system("pause");
	} while (userInput != 0);
}

void DeleteData(MYSQL* conexion, MYSQL_ROW fila, MYSQL_RES* resultado)
{

}

void UpdateData(MYSQL* conexion, MYSQL_ROW fila, MYSQL_RES* resultado)
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