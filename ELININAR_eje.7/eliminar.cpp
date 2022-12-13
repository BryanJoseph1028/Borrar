#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;
const char * nombre_ejercicio7 = "datos7.dat";
char coma;

struct empleados{
	int bonif;
	int sueldob;
	int sueldo;
	int id;
	int estatus;
	char apellido[50];
    char nombre[50];
    char puesto[50];
    string datos;
};
	

void eli()
{
FILE *datos7;
    datos7=fopen(nombre_ejercicio7,"r+b");
    if (datos7==NULL)
        exit(1);	
    printf("Ingrese el codigo dato que desea eliminar:");
    int id;
    scanf("%i", &id);
    struct empleados modificar;
    int existe=0;
    fread(&modificar, sizeof(struct empleados), 1, datos7);
    while(!feof(datos7))
    {
        if (id==modificar.id)
        {
        	cout<<"estatus actual: ";
           printf("%i\n", modificar.estatus);
           printf("Ingrese 1 para mostrar o activar: \n");
           printf("Ingrese 0 para eliminar: \n \n");
           scanf("%i",&modificar.estatus);
           int pos=ftell(datos7)-sizeof(struct empleados);
           fseek(datos7,pos,SEEK_SET);
           fwrite(&modificar, sizeof(struct empleados), 1, datos7);
           printf("Se ah modificado los datos de manera exitosa.\n \n \n");
           existe=1;
           break;
        }
        fread(&modificar, sizeof(struct empleados), 1, datos7);
    }
    if (existe==0)
        printf("No se ha encontrado un registro con el numero de id solicitado\n");
    fclose(datos7);
    system ("PAUSE");

}

	
void abrir_empleados(){

empleados empleado;

FILE* datos7 = fopen(nombre_ejercicio7,"rb");
if (!datos7){
	datos7 = fopen(nombre_ejercicio7,"w+b");
}		


fread(&empleado,sizeof(struct empleados),1,datos7);
while(!feof(datos7)){
	if(empleado.estatus == 1){
	cout<<empleado.id<<coma<<empleado.apellido<<"-"<<empleado.nombre<<coma<<empleado.puesto<<coma<<empleado.sueldob<<coma<<empleado.bonif<<coma<<empleado.sueldo<<endl;
	}
	fread(&empleado,sizeof(struct empleados),1,datos7);
}
fclose(datos7);
}	



void ingresar_datos(){
		
		ofstream archivo;
	string datos;
	string nombre;
	string apellido;
	string puesto;
	int sueldo;
	int bonificacion;
	int sueldo_total;
	archivo.open("archivo.txt",ios::out);
	
	
	if (archivo.fail()){
	cout<<"No se pudo abrir o crear el archivo";
	exit(1);
	}
	else{
	cout << "cual es tu nombre: ";
	getline(cin,nombre);
	archivo <<nombre<<endl;
	cout << "cual es tu apellido: ";
	getline(cin,apellido);
	archivo <<apellido<<endl;
	cout << "cual es tu puesto: ";
	getline(cin,puesto);
	archivo <<puesto<<endl;
	cout << "cual es su sueldo: ";
	cin >>sueldo;
	archivo <<sueldo<<endl;
	cout << "cual es su bonificacion: ";
	cin>>bonificacion;
	archivo <<bonificacion<<endl;
	sueldo_total = sueldo + bonificacion;
	cout << "los resultados son: " << nombre << " , " << apellido << " , " << puesto << " , " << sueldo << " , " << bonificacion << " , " << sueldo_total << " , " << endl;
	}
			
	cout<<"desea agregar otro valor s/n"<<endl;
	cin>>datos;
	cout<<" "<<endl<<endl;		
	}
	
main(){
int menu;
char regresar;

do{
system("cls");		
cout<<"***************MENU************"<<endl<<endl;
cout<<"1.__leer datos"<<endl;
cout<<"2.__ingresar datos"<<endl;
cout<<"3.__eliminar registro"<<endl;
cin>>menu;
switch(menu){
	case 1:
	system("cls");
	abrir_empleados();
	break;
	case 2:
	system("cls");	
	ingresar_datos();	
	break;
	case 3:
	system("cls");
	eli();
	break;
	default:
	system("cls");
	cout<<"no valido"<<endl;
	break;	
	

}
	
cout<<"desea continuar s/n"<<endl;
cin>>regresar;	
}while((regresar=='s')||(regresar=='S'));
}

