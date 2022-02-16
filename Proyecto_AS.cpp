#include<iostream>
#include<locale.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
using namespace std;

//	CLASES
class Usuario{
	protected:
		string Cuenta;
		string Contrasenia;
		int TipoCuenta;
	public:
		string getCuenta();
		string getContrasenia();
		int getTipoCuenta();
};

class Cita{
	private:
		string Cita_Codigo;
		string Nombres;
		string Horario_Codigo;
		string Fecha_Cita;
		string Asunto;
		string Estado;
		//Horario horario;
	public:
		Cita(string,string,string,string,string,string);
		//~Cita();
		string getCodigo();
		string getHora();
		string getFecha();
		string getAsunto();
		string getEstado();
		void setCodigo();
		void setNombres();
		void setHora();
		void setFecha();
		void setAsunto();
		void setEstado();
		void Ct_Programar(Cita*);
		void Ct_Actualizar(Cita*);
		void Ct_Anular();
		void Ct_Mostrar();
};

class Ficha{
	private:
		string codigo;
		string fecha;
		string Diagnostico;
		string Tratamiento;
	public:
		Ficha(string,string,string,string);
		void Ficha_Vizualizar();
};

class HC{
	private:
		string Hc_Codigo;
		string Nombres;
		string Fecha_Cita;
		//Ficha fichas[50];
	public:
		HC(string,string,string);
		void setHc_Codigo();
		void setNombres();
		void setFecha_Cita();
		string getHc_Codigo();
		string getNombres();
		string getFecha_Cita();
		void HC_Actualizar();
		void Ficha_Actualizar();
		void Ficha_Aniadir();
		void Ficha_Ordenar();
		void Ficha_Buscar(string);
};

class Asistente : public Usuario{
	public:
		Asistente(string,string,int);
		void Acceder_Interfaz_HC(HC *);
		void Acceder_Interfaz_GC(HC*, Cita *,Asistente);
};

class Odontologo : public Usuario{
	public:
		Odontologo(string,string,int);
		void Acceder_Interfaz_HC(HC *);
};

class Paciente{
	protected:
		string Nombres;
		string Apellidos;
		string Genero;
		int DNI;
		int Edad;
		string Direccion;
		string Correo;
		int Celular;
		string HcTipoSangre;
		string HcAntecedentesPersonal;
		string HcDentistaAnterior;
		//HC HistoriaClinica;
	public:
		Paciente(string,string,string,int,int,string,string,int,string,string,string);
		void Paciente_Visualizar();
		void Paciente_Actualizar();
};

class Horario{	
	protected:
		string Codigo;
		string Hora_Inicio;
		string Hora_Final;
		string Turno;	
	public:
		Horario(string,string,string,string);
		void HorariodeAtencion();
		void Horario_Visualizar();
		void Horario_Actualizar();
};


//	CONSTRUCTORES
Odontologo::Odontologo(string _Cuenta, string _Contrasenia, int _TipoCuenta){
	Cuenta = _Cuenta;
	Contrasenia = _Contrasenia;
	TipoCuenta = _TipoCuenta;
}

Asistente::Asistente(string _Cuenta, string _Contrasenia, int _TipoCuenta){
	Cuenta = _Cuenta;
	Contrasenia = _Contrasenia;
	TipoCuenta = _TipoCuenta;
}

Paciente::Paciente(string _Nombres, string _Apellidos, string _Genero, int _DNI, int _Edad, string _Direccion, string _Correo, int _Celular, string _HcTipoSangre, string _HcAntecedentesPersonal, string _HcDentistaAnterior){
	Nombres = _Nombres;
	Apellidos = _Apellidos;
	Genero = _Genero;
	DNI = _DNI;
	Edad = _Edad;
	Direccion = _Direccion;
	Correo = _Correo;
	Celular = _Celular;
	HcTipoSangre = _HcTipoSangre;
	HcAntecedentesPersonal = _HcAntecedentesPersonal;
	HcDentistaAnterior = _HcDentistaAnterior;
}

Ficha::Ficha(string _codigo, string _fecha, string _Diagnostico, string _Tratamiento){
	codigo = _codigo;
	fecha = _fecha;
	Diagnostico = _Diagnostico;
	Tratamiento = _Tratamiento;
}

HC::HC(string _Hc_Codigo,string _Nombres,string _Fecha_Cita){
	Hc_Codigo = _Hc_Codigo;
	Nombres = _Nombres;
	Fecha_Cita = _Fecha_Cita;
}

Cita::Cita(string _Cita_Codigo, string _Nombres, string _Horario_Codigo, string _Fecha_Cita, string _Asunto, string _Estado){
	Cita_Codigo = _Cita_Codigo;
	Nombres = _Nombres;
	Horario_Codigo = _Horario_Codigo;
	Fecha_Cita = _Fecha_Cita;
	Asunto = _Asunto;
	Estado = _Estado;
}

Horario::Horario(string _Codigo, string _Hora_Inicio, string _Hora_Final, string _Turno){
	Codigo = _Codigo;
	Hora_Inicio = _Hora_Inicio;
	Hora_Final = _Hora_Final;
	Turno = _Turno;
}

//	PROTOTIPOS DE FUNCIONES
void IniciarSesion();
void Menu_Interfaz(HC *, Cita *,Asistente);
void Plantilla_Interfaz_GC(HC*, Cita *,Asistente);
void Interfaz_HC();
void Interfaz_Citas();
void Buscar_Cita(Cita *,int,int);
void Ordenar_Cita(Cita *,int,int);
void Aniadir_HC(HC*);
void Ordenar_HC(HC*,int,int);
void Buscar_HC(HC*,int,int);

void proceso();
void PlantillasCitas(int);
void Plantilla_Menu_Interfaz();
void Plantilla_GC();
void gotoxy(int,int);

//	VARIABLES GLOBALES
int num_pacientes = 4;
int num_citas = 2;
int num_hc = num_pacientes;

//	FUNCI�N MAIN
int main()
{
	setlocale(LC_CTYPE,"Spanish");
	IniciarSesion();
}

// M�TODOS	- GETERS
string Usuario::getCuenta(){
	return Cuenta;
}

string Usuario::getContrasenia(){
	return Contrasenia;
}

int Usuario::getTipoCuenta(){
	return TipoCuenta;
}

string Cita::getCodigo(){
	return Cita_Codigo;
}

string Cita::getHora(){
	return Horario_Codigo;
}

string Cita::getFecha(){
	return Fecha_Cita;
}

string Cita::getAsunto(){
	return Asunto;
}

string Cita::getEstado(){
	return Estado;
}

string HC::getHc_Codigo(){
	return Hc_Codigo;
}

string HC::getNombres(){
	return Nombres;
}

string HC::getFecha_Cita(){
	return Fecha_Cita;
}
		
//	M�TODOS	- SETERS
void Cita::setCodigo(){
	cin.ignore();
	cout<<"\tCodigo	: "; getline(cin,Cita_Codigo);
}

void Cita::setNombres(){
	cin.ignore();
	cout<<"\tNombres	: "; getline(cin,Nombres);
}

void Cita::setHora(){
	cin.ignore();
	cout<<"\tHora	: "; getline(cin,Horario_Codigo);
}

void Cita::setFecha(){
	cin.ignore();
	cout<<"\tFecha	: "; getline(cin,Fecha_Cita);
}

void Cita::setAsunto(){
	cin.ignore();
	cout<<"\tAsunto	: "; getline(cin,Asunto);
}

void Cita::setEstado(){
	cin.ignore();
	cout<<"\tEstado	: "; getline(cin,Estado);
}

void HC::setHc_Codigo(){
	cin.ignore();
	cout<<"\tCodigo	: "; getline(cin,Hc_Codigo);
}

void HC::setNombres(){
	cin.ignore();
	cout<<"\tNombres	: "; getline(cin,Nombres);
}

void HC::setFecha_Cita(){
	cin.ignore();
	cout<<"\tFecha	: "; getline(cin,Fecha_Cita);
}

//	M�TODOS	- VOID
void Asistente::Acceder_Interfaz_GC(HC *c, Cita *y, Asistente x){
	Plantilla_Interfaz_GC(c,y,x);
}

void Odontologo::Acceder_Interfaz_HC(HC *x){
	int opcion1, opcion2, opcion3;
	do{
		system("cls");
		cout<<"\n\tMENU HISTORIAS CL�NICAS--------";
		cout<<"\n\t[1] Aniadir HC"<<endl;
		cout<<"\t[2] Ordenar HC"<<endl;
		cout<<"\t[3] Buscar HC"<<endl;
		cout<<"\t[4] Volver"<<endl;
		cout<<"\n\tEscoja una opcion: "; cin>>opcion1;
		switch(opcion1){
			case 1: Aniadir_HC(x); break;
			case 2: Ordenar_HC(x,num_hc,opcion2); break;
			case 3: Buscar_HC(x,num_hc,opcion3); break;
			case 4: IniciarSesion(); break;
			default: cout<<"\n\t\t.:Opci�n invalida."; break;
		}
	}while(opcion1 != 4);
}

void Asistente::Acceder_Interfaz_HC(HC *x){
	
}

void Cita::Ct_Programar(Cita *x){
	x[num_citas].setCodigo();
	x[num_citas].setNombres();
	x[num_citas].setFecha();
	x[num_citas].setAsunto();
	x[num_citas].setEstado();
}

void Cita::Ct_Actualizar(Cita *x){
	x[num_citas].setCodigo();
	x[num_citas].setNombres();
	x[num_citas].setFecha();
	x[num_citas].setAsunto();
	x[num_citas].setEstado();
}

void Cita::Ct_Anular(){
	
}

void Cita::Ct_Mostrar(){
	system("cls");
	cout<<"\n\tCodigo	: "<<Cita_Codigo<<endl;
	cout<<"\tNombres	: "<<Nombres<<endl;
	cout<<"\tHora	: "<<Horario_Codigo<<endl;
	cout<<"\tFecha	: "<<Fecha_Cita<<endl;
	cout<<"\tAsunto	: "<<Asunto<<endl;
	cout<<"\tEstado	: "<<Estado<<endl;
}


//	FUNCIONES
void IniciarSesion(){
	HC *HistoriasClinicas[100];
	Cita *Citas[100];
	Odontologo usuario01("GutierrezJavier","221702",1);
	Asistente usuario02("OliverosAngie","561422",2);
	HistoriasClinicas[0] = new HC("0001","Nayeli Valderrama Copa","02/08/2019");
	HistoriasClinicas[1] = new HC("0002","Pedro Aquino Loza","10/10/2019");
	HistoriasClinicas[2] = new HC("0003","Diego Villanueva Noa","11/10/2019");
	HistoriasClinicas[3] = new HC("0004","Carla Lozano Leyva","25/11/2019");
	Citas[0] = new Cita("0012","Maria Pizarro Rojas","10:00 AM","15/02/2022","Consulta","Sin confirmar");
	Citas[1] = new Cita("0013","Miguel Limachi Achata","11:00 AM","16/02/2022","Endodoncia","Confirmar");
	
	int band = 1;
	string usuario, pass;
	do{
		system("cls");
		cout<<"\n\t     INICIO DE SESI�N     "<<endl;
		cout<<"\t=========================="<<endl;
		cout<<"\n\tUsuario		: "<<endl;
		cout<<"\tContrase�a	: "<<endl;
		gotoxy(26,4);
		getline(cin,usuario);
		gotoxy(26,5);
		getline(cin,pass);
		if(usuario == usuario01.getCuenta() && pass == usuario01.getContrasenia()){
			proceso();
			band = 0;
			usuario01.Acceder_Interfaz_HC(*HistoriasClinicas);
		}
		if(usuario == usuario02.getCuenta() && pass == usuario02.getContrasenia()){
			proceso();
			band = 0;
			Menu_Interfaz(*HistoriasClinicas, *Citas,usuario02);
		}
		if(band == 1){
			cout<<"\n\t.:Datos equivocados, vuelva a ingresar."<<endl;
			Sleep(2000);
		}
	}while(band == 1);
}

void Menu_Interfaz(HC *y,Cita *x, Asistente c){
	int opcion;
	Plantilla_Menu_Interfaz();
	gotoxy(16,26);
	cout<<"Ingrese una opci�n: "; cin>>opcion;
	switch(opcion){
		case 1: c.Acceder_Interfaz_HC(y); break;
		case 2: c.Acceder_Interfaz_GC(y, x,c); break;
		case 3: cout<<"\n\t\t.:Volviendo al Login de Usuario."; IniciarSesion(); break;
		default: cout<<"\n\t\t.:Opci�n invalida."; break;
	}
	getch();
}

void Plantilla_Interfaz_GC(HC *y, Cita *x,Asistente c){
	system("cls");
	int opcion1, opcion2, opcion3;
	string palabra;
	Plantilla_GC();
	gotoxy(21,15);
	cout<<"Opci�n: "; cin>>opcion1;
	switch(opcion1){
		case 1: system("cls"); gotoxy(50,15); cout<<".:Volviendo al menu."; Menu_Interfaz(y,x,c); break;
		case 2: do{
					system("cls");
					cout<<"\n\tBUSQUEDAS---------"<<endl;
					cout<<"\n\t[1] C�digo"<<endl;
					cout<<"\t[2] Hora"<<endl;
					cout<<"\t[3] Fecha"<<endl;
					cout<<"\t[4] Asunto"<<endl;
					cout<<"\t[5] Estado"<<endl;
					cout<<"\n\tBuscar por: "; cin>>opcion2;
					if(opcion2 > 6 || opcion2 < 1){
						cout<<"\n\t.: Dato invalido, vuelva a ingresar"<<endl;
					}
					else{
						Buscar_Cita(x,num_citas,opcion2);
					}
				}while(opcion2 >6 || opcion2 < 1);
		break;
		case 3: x[num_citas].Ct_Programar(x); Plantilla_Interfaz_GC(y,x,c); num_citas++; break;
		case 4: system("cls"); gotoxy(50,15); cout<<".:Volviendo al Login de Usuario."; IniciarSesion(); break;
		case 5: PlantillasCitas(5); getch(); Plantilla_Interfaz_GC(y,x,c); break;
		case 6: PlantillasCitas(6); getch(); Plantilla_Interfaz_GC(y,x,c); break;
		case 7: x[num_citas-1].Ct_Anular(); Plantilla_Interfaz_GC(y,x,c); break;
		case 8: x[num_citas-1].Ct_Mostrar(); getch(); Plantilla_Interfaz_GC(y,x,c); break;
		case 9: do{
					system("cls");
					cout<<"\n\tORDENAMIENTO---------"<<endl;
					cout<<"\n\t[1] C�digo"<<endl;
					cout<<"\t[2] Hora"<<endl;
					cout<<"\t[3] Fecha"<<endl;
					cout<<"\t[4] Asunto"<<endl;
					cout<<"\t[5] Estado"<<endl;
					cout<<"\n\tBuscar por: "; cin>>opcion3;
					if(opcion3 > 6 || opcion3 < 1){
						cout<<"\n\t.: Dato invalido, vuelva a ingresar"<<endl;
					}
					else{
						Ordenar_Cita(x,num_citas,opcion3);
					}
				}while(opcion2 >6 || opcion2 < 1);
				Plantilla_Interfaz_GC(y,x,c);
				break;
	}
}

void Buscar_Cita(Cita *x,int n, int criterio){
	int i=0, cent = 0;
	string palabra;
	cin.ignore();
	switch(criterio){
		case 1: cout<<"\n\tIngrese el c�digo de la cita que busca: "; 
				getline(cin,palabra);
				while((i<=n) && (cent == 0)){
					if(x[i].getCodigo() == palabra){
						cent = 1;
					}
					else{
						i++;
					}
					if(cent == 1){
						cout<<"\n\tSe encontr� la cita en la posicion #"<<i+1<<endl;
						x[i].Ct_Mostrar();
					}
					else{
						cout<<"\n\tLa cita no se encuentra"<<endl;
					}
				}
				getch();
				break;
		case 2: cout<<"\n\tIngrese la hora de la cita que busca: "; getline(cin,palabra);
				while((i<=n) && (cent == 0)){
					if(x[i].getHora() == palabra){
						cent = 1;
					}
					else{
						i++;
					}
					if(cent == 1){
						cout<<"\n\tSe encontr� la cita en la posicion #"<<i+1<<endl;
						x[i].Ct_Mostrar();
					}
					else{
						cout<<"\n\tLa cita no se encuentra"<<endl;
					}
				}
				getch();
				break;
		case 3: cout<<"\n\tIngrese la fecha de la cita que busca: "; getline(cin,palabra);
				while((i<=n) && (cent == 0)){
					if(x[i].getFecha() == palabra){
						cent = 1;
					}
					else{
						i++;
					}
					if(cent == 1){
						cout<<"\n\tSe encontr� la cita en la posicion #"<<i+1<<endl;
						x[i].Ct_Mostrar();
					}
					else{
						cout<<"\n\tLa cita no se encuentra"<<endl;
					}
				}
				getch();
				break;
		case 4: cout<<"\n\tIngrese el asunto de la cita que busca: "; getline(cin,palabra);
				while((i<=n) && (cent == 0)){
					if(x[i].getAsunto() == palabra){
						cent = 1;
					}
					else{
						i++;
					}
					if(cent == 1){
						cout<<"\n\tSe encontr� la cita en la posicion #"<<i+1<<endl;
						x[i].Ct_Mostrar();
					}
					else{
						cout<<"\n\tLa cita no se encuentra"<<endl;
					}
				}
				getch();
				break;
		case 5: cout<<"\n\tIngrese el estado de la cita que busca: "; getline(cin,palabra);
				while((i<=n) && (cent == 0)){
					if(x[i].getEstado() == palabra){
						cent = 1;
					}
					else{
						i++;
					}
					if(cent == 1){
						cout<<"\n\tSe encontr� la cita en la posicion #"<<i+1<<endl;
						x[i].Ct_Mostrar();					}
					else{
						cout<<"\n\tLa cita no se encuentra"<<endl;
					}
				}
				getch();
				break;
	}
}

void Ordenar_Cita(Cita *x,int n,int criterio){
	Cita aux("","","","","","");
	string palabra;
	cin.ignore();
	switch(criterio){
		case 1: 
				for(int i=1;i<n;i++){
					for(int j=n-1;j>=i;j--){
						if(x[j-1].getCodigo() > x[j].getCodigo()){
							aux = x[j-1];
							x[j-1] = x[j];
							x[j] = aux;
						}
					}
				}
				break;
		case 2: 
				for(int i=1;i<n;i++){
					for(int j=n-1;j>=i;j--){
						if(x[j-1].getHora() > x[j].getHora()){
							aux = x[j-1];
							x[j-1] = x[j];
							x[j] = aux;
						}
					}
				}
				break;
		case 3: 
				for(int i=1;i<n;i++){
					for(int j=n-1;j>=i;j--){
						if(x[j-1].getFecha() > x[j].getFecha()){
							aux = x[j-1];
							x[j-1] = x[j];
							x[j] = aux;
						}
					}
				}
				break;
		case 4: 
				for(int i=1;i<n;i++){
					for(int j=n-1;j>=i;j--){
						if(x[j-1].getAsunto() > x[j].getAsunto()){
							aux = x[j-1];
							x[j-1] = x[j];
							x[j] = aux;
						}
					}
				}
				break;
		case 5: 
				for(int i=1;i<n;i++){
					for(int j=n-1;j>=i;j--){
						if(x[j-1].getEstado() > x[j].getEstado()){
							aux = x[j-1];
							x[j-1] = x[j];
							x[j] = aux;
						}
					}
				}
				break;
	}
}

void Aniadir_HC(HC *x){
	x[num_hc].setHc_Codigo();
	x[num_hc].setNombres();
	x[num_hc].setFecha_Cita();
}
void Ordenar_HC(HC *x,int n, int criterio){
	
}

void Buscar_HC(HC *x, int n, int criterio){
	/*HC aux();
	string palabra;
	cin.ignore();
	switch(criterio){
		case 1: 
				for(int i=1;i<n;i++){
					for(int j=n-1;j>=i;j--){
						if(x[j-1].getHc_Codigo() > x[j].getHc_Codigo()){
							aux = x[j-1];
							x[j-1] = x[j];
							x[j] = aux;
						}
					}
				}
				break;
		case 2: 
				for(int i=1;i<n;i++){
					for(int j=n-1;j>=i;j--){
						if(x[j-1].getNombres() > x[j].getNombres()){
							aux = x[j-1];
							x[j-1] = x[j];
							x[j] = aux;
						}
					}
				}
				break;
		case 3: 
				for(int i=1;i<n;i++){
					for(int j=n-1;j>=i;j--){
						if(x[j-1].getFecha_Cita() > x[j].getFecha_Cita()){
							aux = x[j-1];
							x[j-1] = x[j];
							x[j] = aux;
						}
					}
				}
				break;*/
}

//	PLANTILLAS Y OTROS
void gotoxy(int x,int y){  
	HANDLE hcon;  
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
	COORD dwPos;  
	dwPos.X = x;  
	dwPos.Y= y;  
	SetConsoleCursorPosition(hcon,dwPos);  
}

void proceso(){
	system("cls");
	gotoxy(50,15);
	cout<<"Ingresando."; Sleep(750);
	gotoxy(50,15);
	cout<<"Ingresando.."; Sleep(750);
	gotoxy(50,15);
	cout<<"Ingresando..."; Sleep(750);
}

void PlantillasCitas(int x){
	switch(x){
		case 5: 
			//Cita 1 -> consulta
		for(int i=0;i<3;i++){
			gotoxy(51,5+i);
			cout<<"|";
			gotoxy(61,5+i);
			cout<<"|";
		}
		for(int i=0;i<9;i++){
			gotoxy(52+i,4);
			cout<<"_";
			gotoxy(52+i,7);
			cout<<"_";
		}
		gotoxy(53,6);
		cout<<"00012";
		gotoxy(80,6);
		cout<<"CONSULTA";
		for(int i=0;i<3;i++){
			gotoxy(111,5+i);
			cout<<"o";
		}
		//Foto cita
		for(int i=0;i<14;i++){
			gotoxy(53,10+i);
			cout<<"|";
			gotoxy(84,10+i);
			cout<<"|";
		}
		for(int i=0;i<30;i++){
			gotoxy(54+i,9);
			cout<<"_";
			gotoxy(54+i,23);
			cout<<"_";
		}
		//cuadros de cita x 4
		for(int i=0;i<4;i++){
			gotoxy(87,10+i);
			cout<<"|";
			gotoxy(114,10+i);
			cout<<"|";
		}
		for(int i=0;i<26;i++){
			gotoxy(88+i,9);
			cout<<"_";
			gotoxy(88+i,13);
			cout<<"_";
		}
		gotoxy(92,11);
		cout<<">      SIN";
		gotoxy(94,12);
		cout<<"  CONFIRMAR";
		for(int i=0;i<3;i++){
			gotoxy(87,15+i);
			cout<<"|";
			gotoxy(114,15+i);
			cout<<"|";
		}
		for(int i=0;i<26;i++){
			gotoxy(88+i,14);
			cout<<"_";
			gotoxy(88+i,17);
			cout<<"_";
		}
		gotoxy(92,16);
		cout<<">   08/ 02 / 2022";
		for(int i=0;i<4;i++){
			gotoxy(87,19+i);
			cout<<"|";
			gotoxy(114,19+i);
			cout<<"|";
		}
		for(int i=0;i<26;i++){
			gotoxy(88+i,18);
			cout<<"_";
			gotoxy(88+i,22);
			cout<<"_";
		}
		gotoxy(90,20);
		cout<<"  >    4:00 - 5:00";
		gotoxy(90,21);
		cout<<"            PM";
		for(int i=0;i<4;i++){
			gotoxy(87,24+i);
			cout<<"|";
			gotoxy(114,24+i);
			cout<<"|";
		}
		for(int i=0;i<26;i++){
			gotoxy(88+i,23);
			cout<<"_";
			gotoxy(88+i,27);
			cout<<"_";
		}
		gotoxy(90,25);
		cout<<"  >      MA�ANA";
		for(int i=0;i<3;i++){
			gotoxy(53,25+i);
			cout<<"|";
			gotoxy(84,25+i);
			cout<<"|";
		}
		for(int i=0;i<30;i++){
			gotoxy(54+i,24);
			cout<<"_";
			gotoxy(54+i,27);
			cout<<"_";
		}
		gotoxy(55,26);
		cout<<"     MAR�A PIZARRO ROJAS";
		break;
		
		case 6:
			//Cita 1 -> consulta
		for(int i=0;i<3;i++){
			gotoxy(51,5+i);
			cout<<"|";
			gotoxy(61,5+i);
			cout<<"|";
		}
		for(int i=0;i<9;i++){
			gotoxy(52+i,4);
			cout<<"_";
			gotoxy(52+i,7);
			cout<<"_";
		}
		gotoxy(53,6);
		cout<<"00013";
		gotoxy(80,6);
		cout<<"ENDODONCIA";
		for(int i=0;i<3;i++){
			gotoxy(111,5+i);
			cout<<"o";
		}
		
		//Foto cita
		for(int i=0;i<14;i++){
			gotoxy(53,10+i);
			cout<<"|";
			gotoxy(84,10+i);
			cout<<"|";
		}
		for(int i=0;i<30;i++){
			gotoxy(54+i,9);
			cout<<"_";
			gotoxy(54+i,23);
			cout<<"_";
		}
		
		//cuadros de cita x 4
		for(int i=0;i<4;i++){
			gotoxy(87,10+i);
			cout<<"|";
			gotoxy(114,10+i);
			cout<<"|";
		}
		for(int i=0;i<26;i++){
			gotoxy(88+i,9);
			cout<<"_";
			gotoxy(88+i,13);
			cout<<"_";
		}
		gotoxy(92,11);
		cout<<"> CONFIRMADO";
		for(int i=0;i<3;i++){
			gotoxy(87,15+i);
			cout<<"|";
			gotoxy(114,15+i);
			cout<<"|";
		}
		for(int i=0;i<26;i++){
			gotoxy(88+i,14);
			cout<<"_";
			gotoxy(88+i,17);
			cout<<"_";
		}
		gotoxy(92,16);
		cout<<">   08/ 02 / 2022";
		for(int i=0;i<4;i++){
			gotoxy(87,19+i);
			cout<<"|";
			gotoxy(114,19+i);
			cout<<"|";
		}
		for(int i=0;i<26;i++){
			gotoxy(88+i,18);
			cout<<"_";
			gotoxy(88+i,22);
			cout<<"_";
		}
		gotoxy(90,20);
		cout<<"  >   10:00 - 11:00";
		gotoxy(90,21);
		cout<<"            AM";
		for(int i=0;i<4;i++){
			gotoxy(87,24+i);
			cout<<"|";
			gotoxy(114,24+i);
			cout<<"|";
		}
		for(int i=0;i<26;i++){
			gotoxy(88+i,23);
			cout<<"_";
			gotoxy(88+i,27);
			cout<<"_";
		}
		gotoxy(90,25);
		cout<<"  >      MA�ANA";
		for(int i=0;i<3;i++){
			gotoxy(53,25+i);
			cout<<"|";
			gotoxy(84,25+i);
			cout<<"|";
		}
		for(int i=0;i<30;i++){
			gotoxy(54+i,24);
			cout<<"_";
			gotoxy(54+i,27);
			cout<<"_";
		}
		gotoxy(55,26);
		cout<<"     MIGUEL LIMACHI ACHATA";
		break;
			
	}
}

void Plantilla_GC(){
	for(int i=0;i<30;i++){
		gotoxy(6,i);
		cout<<"|";
	}
	for(int i=0;i<27;i++){
		gotoxy(15,3+i);
		cout<<"|";
		gotoxy(47,3+i);
		cout<<"|";
	}
	for(int i=0;i<113;i++){
		gotoxy(7+i,2);
		cout<<"_";
	}
	for(int i=0;i<3;i++){
		gotoxy(43,i);
		cout<<"|";
		gotoxy(81,i);
		cout<<"|";
	}
	gotoxy(26,1);
	cout<<"HOY";
	gotoxy(62,1);
	cout<<"SEMANA";
	gotoxy(102,1);
	cout<<"MES";
	gotoxy(8,4);
	cout<<"Martes";
	gotoxy(8,5);
	cout<<"  8  ";
	gotoxy(1,27);
	cout<<"|";
	gotoxy(4,27);
	cout<<"|";
	for(int i=0;i<2;i++){
		gotoxy(2+i,26);
		cout<<"_";
		gotoxy(2+i,28);
		cout<<"�";
	}
	gotoxy(2,27);
	cout<<"<-";
	gotoxy(1,1);
	cout<<"|";
	gotoxy(4,1);
	cout<<"|";
	for(int i=0;i<2;i++){
		gotoxy(2+i,0);
		cout<<"_";
		gotoxy(2+i,2);
		cout<<"�";
	}
	gotoxy(2,1);
	cout<<"HM";
	gotoxy(1,4);
	cout<<"|";
	gotoxy(4,4);
	cout<<"|";
	for(int i=0;i<2;i++){
		gotoxy(2+i,3);
		cout<<"_";
		gotoxy(2+i,5);
		cout<<"�";
	}
	gotoxy(2,4);
	cout<<"O-";
	gotoxy(1,7);
	cout<<"|";
	gotoxy(4,7);
	cout<<"|";
	for(int i=0;i<2;i++){
		gotoxy(2+i,6);
		cout<<"_";
		gotoxy(2+i,8);
		cout<<"�";
	}
	gotoxy(2,7);
	cout<<"++";
	//	Rectangulo
	for(int i=0;i<25;i++){
		gotoxy(49,4+i);
		cout<<"|";
		gotoxy(116,4+i);
		cout<<"|";
	}
	for(int i=0;i<66;i++){
		gotoxy(50+i,3);
		cout<<"_";
		gotoxy(50+i,8);
		cout<<"_";
		gotoxy(50+i,28);
		cout<<"_";
	}
	// Citas (2)
	for(int i=0;i<4;i++){
		gotoxy(18,4+i);
		cout<<"|";
		gotoxy(44,4+i);
		cout<<"|";
	}
	for(int i=0;i<25;i++){
		gotoxy(19+i,3);
		cout<<"_";
		gotoxy(19+i,7);
		cout<<"_";
	}
	for(int i=0;i<4;i++){
		gotoxy(18,9+i);
		cout<<"|";
		gotoxy(44,9+i);
		cout<<"|";
	}
	for(int i=0;i<25;i++){
		gotoxy(19+i,8);
		cout<<"_";
		gotoxy(19+i,12);
		cout<<"_";
	}
	
	for(int i=0;i<2;i++){
		gotoxy(42,5+i);
		cout<<"o";
	}
	for(int i=0;i<2;i++){
		gotoxy(42,10+i);
		cout<<"o";
	}
	
	gotoxy(24,4);
	cout<<"CONSULTA";
	gotoxy(22,5);
	cout<<"> 10:00 - 11:00 AM";
	gotoxy(22,6);
	cout<<"> 927 557405";
	gotoxy(24,9);
	cout<<"ENDODONCIA";
	gotoxy(22,10);
	cout<<"> 10:00 - 11:00 AM";
	gotoxy(22,11);
	cout<<"> 927 557405";
}

void Plantilla_Menu_Interfaz(){
	system("cls");
	for(int i=0;i<30;i++){
		gotoxy(55,i);
		cout<<"|";
	}
	for(int i=0;i<60;i++){
		gotoxy(56+i,14);
		cout<<"-";
	}
	gotoxy(72,8);
	cout<<"GESTI�N DE HISTORIAS CL�NICAS 1";
	gotoxy(77,20);
	cout<<"GESTI�N DE CITAS 2";
	for(int i=6;i<12;i++){
		gotoxy(22,i);
		cout<<"|";
		gotoxy(32,i);
		cout<<"|";
	}
	gotoxy(21,3);
	cout<<"DENTAL TACNA ";
	for(int i=0;i<9;i++){
		gotoxy(23+i,5);
		cout<<"_";
		gotoxy(23+i,11);
		cout<<"_";
	}
	gotoxy(18,14);
	cout<<"OLIVEROS ANGIE PINTO";
	gotoxy(2,27);
	cout<<"|";
	gotoxy(8,27);
	cout<<"|";
	for(int i=0;i<5;i++){
		gotoxy(3+i,26);
		cout<<"_";
		gotoxy(3+i,28);
		cout<<"�";
	}
	gotoxy(4,27);
	cout<<"<--";
	gotoxy(9,27);
	cout<<"3";
	gotoxy(9,18);
	cout<<"� Implantes Dental Tacna";
	gotoxy(9,22);
	cout<<"� ImplantDental";
	gotoxy(35,18);
	cout<<"� +51821524431";
	gotoxy(35,22);
	cout<<"� 052-632629";
}
