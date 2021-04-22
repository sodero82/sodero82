#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <iomanip>
#include <fstream>

using namespace std;
#define TOPEP 31
#define TOPET 21
#define TOPEPROM 10
#define TOPETEL 10
#define TOPEDIAS 31
#define TOPETOT 1

void l0( ){
		system("pause");
		system("cls");
}
void l1( ){
		system("cls");
}
// Estructura generica para ventas
struct tyventas{
	char nombv[TOPEP];
	char descv[TOPET];
	int cantv;
	int diav;
};
//Estructura generica para promotores
struct typromotores{
	char nombre[TOPEP];
	float comi;
};
//Estructura generica para celulares
struct tycelulares{
	char dcel[TOPET];
	float pcel;
};
void valida_promotor (tyventas vta, typromotores dato[],int tope2, int &pos_prom){	
	pos_prom=0;	
		while (pos_prom<tope2 && strcmp(dato[pos_prom].nombre,vta.nombv)!=0){		
			pos_prom++;				
		}
		if ( pos_prom==tope2){
				pos_prom=-1;
			}		
			//cout<<pos_prom<<endl;
	}	
void valida_celular (tyventas vta, tycelulares dato[],int tope2, int &pos_cel){
	pos_cel=0;
		while (pos_cel<tope2 && strcmp(dato[pos_cel].dcel,vta.descv)!=0){		
			pos_cel++;			
		}
		if ( pos_cel==tope2){
				pos_cel=-1;
			}	
	//cout<<pos_cel<<endl;	
}
void prepara_vector_dias (int dias[],int tdias){
		
		for (int c=0;c<tdias;c++){
			dias[c]=0;

		}
		
}
void prepara_matriz_comi_total (float mat[][TOPETOT],int tprom,int tcel,typromotores vec_pro[],int tope1,tycelulares vec_cel[],int tope2){
	int y;
	int x;
	for (y=0;y<tprom;y++){
		for (x=0;x<tcel;x++){
			mat[y][x]=0;
		}
	}	
}
void prepara_prom_cel (int mat[][TOPETEL],int tprom,int tcel,typromotores vec_pro[],int tope1,tycelulares vec_cel[],int tope2){
	int y;
	int x;
	for (y=0;y<tprom;y++){
		for (x=0;x<tcel;x++){
			mat[y][x]=0;
		}
	}	
}

void agrega_matriz_comi_total (float mat[][TOPETOT],int tprom,int tcel,tyventas vta, typromotores vec_pro[],int tope1,tycelulares vec_cel[],int tope2){
	int y;
	int x;
	int pos_prom=0;
	int pos_cel=0;
	valida_promotor(vta,vec_pro,TOPEPROM,pos_prom);
	valida_celular(vta,vec_cel,TOPETEL,pos_cel);
	
	for (y=0;y<tprom;y++){
		for (x=0;x<tcel;x++){
			
			mat[pos_prom][0]+=(((vta.cantv*vec_cel[pos_cel].pcel)*vec_pro[pos_prom].comi)/100)/10;
		}
			
	}
	
}
void agrega_prom_cel (int mat[][TOPETEL],int tprom,int tcel,tyventas vta, typromotores vec_pro[],int tope1,tycelulares vec_cel[],int tope2){
	int y=0;
	int x=0;
	int pos_prom=0;
	int pos_cel=0;
	valida_promotor(vta,vec_pro,TOPEPROM,pos_prom);
	valida_celular(vta,vec_cel,TOPETEL,pos_cel);

while (y<tprom){
		while (x<tcel){
			mat[pos_prom][pos_cel]+=vta.cantv;
			break;
			x++;		
		}
		y++;
		x=0;
	}	
}
	void muestra_matriz_comi_total (float mat[][TOPETOT],int tprom,int tcel,tyventas vta,typromotores vec_pro[],int tope1,tycelulares vec_cel[],int tope2){
	int y=0;
	int x=0;
	float num=0;

	cout<<"\n"<<setw(63)<<"COMISIONES DEL MES\n"<<endl;
	
	while (y<tprom){
		cout<<"La comision de "<<setw(9)<<vec_pro[y].nombre<<" es :";
		while (x<tcel){
			cout<<"\033[1;32m $"<<fixed<<setprecision(3)<<setw(10)<<mat[y][x]<<"\033[0m";
			x++;		
		}	
		cout<<"\n";	
		y++;
		x=0;		
	}
	l0();	
}

void muestra_mv_pp (int mat[][TOPETEL],int tprom,int tcel,tyventas vta,typromotores vec_pro[],int tope1,tycelulares vec_cel[],int tope2){
	int y=0;
	int x=0;
	int mayor=0;
	int pos_prom=0;
	int pos_cel=0;
	int mat_aux[TOPEPROM][TOPETOT];
	cout<<"\n"<<setw(63)<<"TELEFONO MAS VENDIDO POR PROMOTOR\n"<<endl;

	while (y<tprom){		
		while (x<1){
			mat_aux[y][x]=0;				
			x++;		
		}	
		y++;
		x=0;
	}
	
	y=0;
	x=0;
	while (y<tprom){
		pos_prom=0;
		mayor=0;
		while (x<tcel){
			if (mat[y][x]>mayor){			
				mayor=mat[y][x];			
				pos_prom=y;
				pos_cel=x;
				mat_aux[pos_prom][0]=mayor/10;
				cout<<"El celular mas vendido de \033[1;32m "<<vec_pro[pos_prom].nombre<<"\033[0m fue el \033[1;32m "<<vec_cel[pos_cel].dcel<<"\033[0m con \033[1;32m "<<mayor/10<<"\033[0m ventas"<<endl;				
			
			}
			x++;		
		}	
		cout<<"\n";	
		y++;
		x=0;
	}

	l0();
}
void muestra_mas_vend (int mat[][TOPETEL],int tprom,int tcel,tyventas vta,tycelulares vec_cel[],int tope2){
	int y=0;
	int x=0;
	int suma=0;
	int mayor=0;
	int pos_cel=0;
	float vec_aux[TOPETEL];
	
	while (x<tcel){
		vec_aux[x]=0;
		x++;		
	}
	x=0;
	while (y<tprom){
		suma=0;
		x=0;
		while(x<tcel){
			suma+=mat[x][y]/10;
			vec_aux[y]=suma;		
			x++;
		}
		y++;
	}
	y=0;
	x=0;
	cout<<"\n"<<setw(63)<<"TELEFONO MAS VENDIDO DE TODOS\n"<<endl;
		
	while (x<tcel){			
		if (vec_aux[x]>mayor){				
			mayor=vec_aux[x];
			pos_cel=x;
		}	
		x++;
	}
	cout<<"El telefono mas vendido del mes fue el \033[1;32m"<<vec_cel[pos_cel].dcel<<" \033[0m con \033[1;32m"<<mayor<<" \033[0mventas"<<endl;
	l0();
}
void muestra_sin_vender (int mat[][TOPETEL],int tprom,int tcel,tyventas vta,typromotores vec_pro[],int tope1,tycelulares vec_cel[],int tope2){
	int y=0;
	int x=0;
	int mayor=0;
	int pos_prom=0;
	int pos_cel=0;
	cout<<"\n"<<setw(63)<<"PROMOTORES SIN VENDER X CADA CELULAR\n"<<endl;

	while (y<tprom){
		pos_prom=0;
		cout<<"El telefono \033[2;32m"<<vec_cel[y].dcel<<"\033[0m no fue vendido por |";
		while (x<tcel){
			if (mat[x][y]==0){		
				pos_prom=x;
				pos_cel=y;
				cout<<"\033[1;31m"<<vec_pro[pos_prom].nombre<<"\033[0m ";

			}
			pos_cel=0;
			x++;	
		}

	cout<<endl;	
	y++;
	x=0;
	}
	l0();
}

void busca_mayor_venta(int vec[], int tope, int &posmax){
	int i=0;	
		while(i<tope){			
			if(vec[i]>vec[posmax]){
				posmax=i;				
			}		
			i++;			
		}
}
void muestra_vector_dias (int dias[],int tdias,tyventas vta,typromotores vec_pro[],int tope1,tycelulares vec_cel[],int tope2){
	int x=0;
	int y=0;
	int posmax=0;
	int mayor=0;
	
	cout<<"\n"<<setw(50)<<"MAYOR VENTA DEL MES\n"<<endl;
	while (y<tdias){
		cout<<setw(2)<<y+1<<"|";
		y++;
	}
	cout<<endl;
	while (x<tdias){
		cout<<setw(2)<<dias[x]<<"|";
		x++;
	}	
	busca_mayor_venta(dias,tdias,posmax);
	mayor=dias[posmax];
	y=0;
	while(y<tdias){
		if (dias[y]==mayor){	
			cout<<"\nEl dia con mas ventas fue el \033[1;32m"<<y+1<<"\033[0m con \033[1;32m"<<mayor<<"\033[0m ventas"<<endl;
		}
		y++;
	}

}

	
void mostrar_promotores (typromotores dato[], int tope1){
	system("color 0F");
	int i;
	cout<<"\033[1;42m                            PROMOTORES HABILITADOS                            \033[0m"<<endl;
	for (i=0; i<tope1;i++){
		cout<<"\033[1;32m"<<dato[i].nombre<<"\033[0m  ";
	
	}
	cout<<"\n"<<endl;
}

void mostrar_celulares (tycelulares dato[], int tope2){
	int i;
	cout<<"\033[1;42m                           TELEFONOS EN STOCK                           \033[0m"<<endl;
	for (i=0; i<tope2;i++){
		cout<<"\033[1;32m"<<dato[i].dcel<<"\033[0m ";
	
	}
	cout<<"\n"<<endl;
}
//copia promotores.dat a vec_prom[]
void copiar_promotores (typromotores vdato[],int tope){	
	typromotores dato;		
	int i=0;
	ifstream archivo;
	int lp=sizeof(dato);
	archivo.open("promotores.dat", ios::in | ios::out | ios::binary);
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}

		while (i<tope && !archivo.eof()){
			archivo.read(reinterpret_cast<char*>(&dato),lp);
				strcpy(vdato[i].nombre, dato.nombre);				
				vdato[i].comi=dato.comi;
				//cout<<"Nombre: "<<vdato[i].nombre<<endl;
				//cout<<"Comision: "<<vdato[i].comi<<endl;	
			i++;
		}
		
	archivo.close();
}
//copia telefonos.dat a vec_cel[]
void copiar_celulares (tycelulares vdato[], int tope2){
	tycelulares dato;
	int i=0;
	ifstream archivo;
	int lp=sizeof(dato);
	archivo.open("telefonos.dat", ios::in | ios::out | ios::binary);
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
		while (i<tope2 && !archivo.eof()){
			archivo.read(reinterpret_cast<char*>(&dato),lp);
				strcpy(vdato[i].dcel, dato.dcel);				
				vdato[i].pcel=dato.pcel;
				
			i++;
		}
		
	archivo.close();
}

void ingreso_ventas (tyventas & vta, typromotores dato[], int tope1, tycelulares vdato[], int tope2, int &pos_prom, int &pos_cel){	
	int i=0;
	pos_prom=0;
	pos_cel=0;
	char fin[TOPEP]="cerrar";
	char nombre[TOPEP];
	char modelo[TOPET];
	int cantidad=0;
	int dia=0;
	bool noestan=true;
	
	mostrar_promotores (dato,tope1);
	
	cout<<"Ingrese nombre del promotor (\033[1;34mcerrar\033[0m para salir): "<<endl;	
	cin>>vta.nombv;	
	fflush(stdin);
	while (strlen(vta.nombv)>31){
		cout<<"Ingrese nombre no superior a 30 caracteres.... (cerrar para salir): "<<endl;	
		cin>>vta.nombv;
	}
	l1();	
	if (strcmp(vta.nombv,fin)!=0){	
		mostrar_celulares (vdato,tope2);
		
		cout<<"Ingrese modelo: \n"<<endl;
		cin>>vta.descv;
		fflush(stdin);
		while (strlen(vta.descv)>21){
			cout<<"Ingrese modelo no superior a 20 caracteres....: "<<endl;	
			cin>>vta.descv;
		}
		l1();
		cout<<"Ingrese cantidad (>0): "<<endl;
		cin>>vta.cantv;
		while (vta.cantv<=0){
			system("color 4F");
			cout<<"Ingrese cantidad (>0): "<<endl;
			cin>>vta.cantv;		
		}	
		l1();
		cout<<"Ingrese dia de la venta (1 a 31): "<<endl;		
		cin>>vta.diav;					
		while (vta.diav <=0 || vta.diav >=32){		
			system("color 4F");
			cout<<"Ingrese dia de la venta (1 a 31): "<<endl;
			cin>>vta.diav;			
		}
		l1();
		valida_promotor (vta,dato,TOPEPROM,pos_prom);
		valida_celular (vta,vdato,TOPETEL,pos_cel);
		
		if (pos_prom !=-1 && pos_cel !=-1){
			
			cout<<"\033[1;32mVENTA CORRECTA\033[0m"<<endl;
		
			noestan=false;
			
		}
		if (noestan){
			
			strcpy(vta.nombv, "No existe");
			strcpy(vta.descv, "No existe");				
			vta.cantv=0;
			vta.diav=0;	

			cout<<"\033[0;31m VENTA ERRONEA ....INGRESE LOS DATOS NUEVAMENTE....\033[0m"<<endl;

		}
		
	}	
}
void informe_venta (tyventas & vta, typromotores dato[], int tope1, tycelulares vdato[], int tope2, int pos_prom, int pos_cel){	
	cout<<" ________________________________________________"<<endl;	
	cout<<"|                INFORME DE VENTA                |"<<endl;
	cout<<"|________________________________________________|"<<endl;	

	
	cout<<"|"<<setw(28)<<"Nombre: "<<setw(20)<<vta.nombv<<"|"<<endl;
	cout<<"|"<<setw(28)<<"Descripcion del telefono: "<<setw(20)<<vta.descv<<"|"<<endl;
	cout<<"|"<<setw(28)<<"Cantidad vendida: "<<setw(20)<<vta.cantv<<"|"<<endl;
	cout<<"|"<<setw(28)<<"Dia de la venta: "<<setw(20)<<vta.diav<<"|"<<endl;
	cout<<"|________________________________________________|"<<endl;	

	
	l0();
}
void suma_venta_por_dia (int dias[],int tdias,tyventas  vta,int pos_prom,int pos_cel){
	
	dias[vta.diav-1]+=1;
	
}
int main(){
	float mat_comi_total [TOPEPROM][TOPETOT];
	int mat_prom_cel [TOPEPROM][TOPETEL];
	int dias[TOPEDIAS];	
	int pos_prom=0;
	int pos_cel=0;
	char fin[TOPEP]="cerrar";
	typromotores vec_prom[TOPEPROM];	
	tycelulares vec_cel[TOPETEL];
	tyventas venta;	
	
	copiar_promotores (vec_prom,TOPEPROM);  //copia promotores.dat a typromotores vec_prom[]
	copiar_celulares (vec_cel,TOPETEL);              //copia telefonos.dat a  tycelulares vec_cel[]
	prepara_vector_dias (dias,TOPEDIAS);		
	prepara_matriz_comi_total(mat_comi_total,TOPEPROM,TOPETOT,vec_prom,TOPEPROM,vec_cel,TOPETEL);
	prepara_prom_cel (mat_prom_cel,TOPEPROM,TOPETEL,vec_prom,TOPEPROM,vec_cel,TOPETEL);	
	ingreso_ventas (venta,vec_prom,TOPEPROM,vec_cel,TOPETEL,pos_prom,pos_cel);//Ingreso venta
	
	while (strcmp(venta.nombv,fin)!=0){
		informe_venta (venta,vec_prom,TOPEPROM,vec_cel,TOPETEL,pos_prom,pos_cel);
		agrega_matriz_comi_total(mat_comi_total,TOPEPROM,TOPETOT,venta,vec_prom,TOPEPROM,vec_cel,TOPETEL);		
		agrega_prom_cel (mat_prom_cel,TOPEPROM,TOPETEL,venta,vec_prom,TOPEPROM,vec_cel,TOPETEL);
		suma_venta_por_dia (dias,TOPEDIAS,venta,pos_prom,pos_cel); 				             //Contar ventas por dia y separar validas de erroneas		

		ingreso_ventas (venta,vec_prom,TOPEPROM,vec_cel,TOPETEL,pos_prom,pos_cel);            //Ingreso venta
	}
	
		cout<<"\nPunto A"<<endl;
		muestra_matriz_comi_total (mat_comi_total,TOPEPROM,TOPETOT,venta,vec_prom,TOPEPROM,vec_cel,TOPETEL);
		cout<<"\nPunto B"<<endl;
		muestra_mv_pp (mat_prom_cel,TOPEPROM,TOPETEL,venta,vec_prom,TOPEPROM,vec_cel,TOPETEL);
		cout<<"\nPunto C"<<endl;
		muestra_mas_vend (mat_prom_cel,TOPEPROM,TOPETEL,venta,vec_cel,TOPETEL);
		cout<<"\nPunto D"<<endl;
		muestra_sin_vender (mat_prom_cel,TOPEPROM,TOPETEL,venta,vec_prom,TOPEPROM,vec_cel,TOPETEL);
		cout<<"\nPunto E"<<endl;	
		muestra_vector_dias (dias,TOPEDIAS,venta,vec_prom,TOPEPROM,vec_cel,TOPETEL);
	return 0;

}
