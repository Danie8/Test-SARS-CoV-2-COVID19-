#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct
{
	char Nombre[50];
	char Apellido1[50];
	char Apellido2[50];
	char Sexo[50];
	int Edad;
	char Mail[50];
	char Telefono[50];
	char Direccion[50];	
} Ciudadano;

void Excepcion_Respuesta(char *Respuesta){
	
	while(*Respuesta!='S'&&*Respuesta!='N')
	{
		scanf("%s",&(*Respuesta));
		if(*Respuesta=='S'||*Respuesta=='N'){
			printf("----------------------------------------------------------------------------------------------\n");
			break;				
		} 
		else printf("\tRespuesta invalida. Responda S o N: ");
	}
	return;
}

void Test(Ciudadano *C,char *Respuestas){
	system("cls");
	
	printf("   Este formulario proporcionara un primer panorama para el diagnostico del sospechoso \n   de contagio. Favor de llenar todo lo que se pide a continuacion.\n");
	printf("\n\t\t\t||Datos del ciudadano||\n\n");
	printf("   Estos datos son recabados con la unica finalidad de dar seguimiento\n   al resultado que usted obtenga con base en las preguntas del test");
	
	printf("\n\n  Nombre: ");
	scanf("%s",&C->Nombre);
	printf("  Primer apellido: ");
	scanf("%s",&C->Apellido1);
	printf("  Segundo apellido: ");
	scanf("%s",&C->Apellido2);
	printf("  Sexo(M/F): ");
	scanf("%s",&C->Sexo);
	printf("  Edad: ");
	scanf("%d",&C->Edad);
	printf("  Mail: ");
	scanf("%s",&C->Mail);
	printf("  Telefono: ");
	scanf("%s",&C->Telefono);
	printf("  Direccion: ");
	scanf("%s",&C->Direccion);
	
	printf("\n   Gracias. A continuacion responda las siguientes preguntas \n   con S o N segun sea el caso, donde S es si y N es no.\n\n");
	
	system("PAUSE");
	//system("cls");
	
	printf("\n\t\t\t||Cuestionario de tamizaje para COVID-19||\n\n");
	printf("----------------------------------------------------------------------------------------------\n");
	printf("1. Has estado con alguna persona que tenga COVID-19 (Coronavirus)?\n\n\t(S/N): ");
	Excepcion_Respuesta(Respuestas);
	printf("2.Tienes fiebre? (Temperatura igual o mayor a 38 grados)\n\n\t(S/N): ");
	Excepcion_Respuesta(Respuestas+1);
	printf("3.Tienes dolor de cabeza?\n\n\t(S/N): ");
	Excepcion_Respuesta(Respuestas+2);
	printf("4.Tienes tos?\n\n\t(S/N): ");
	Excepcion_Respuesta(Respuestas+3);
	printf("5.Tienes dolor en el pecho?\n\n\t(S/N): ");
	Excepcion_Respuesta(Respuestas+4);
	printf("6.Tienes dolor de garganta?\n\n\t(S/N): ");
	Excepcion_Respuesta(Respuestas+5);
	printf("7.Tienes dificultad para respirar?\n\n\t(S/N): ");
	Excepcion_Respuesta(Respuestas+6);
	printf("8.Tienes escurrimiento nasal?\n\n\t(S/N): ");
	Excepcion_Respuesta(Respuestas+7);
	printf("9.Tienes dolor en el cuerpo?\n\n\t(S/N): ");
	Excepcion_Respuesta(Respuestas+8);
	printf("10.Tienes conjuntivitis?\n\n\t(S/N): ");
	Excepcion_Respuesta(Respuestas+9);
	printf("11.Tienes alguna de las siguientes condiciones? (diabetes, hipertension, obesidad,\n   problemas cardiacos, asma, EPOC, VIH, Cancer)\n\n\t(S/N): ");
	Excepcion_Respuesta(Respuestas+10);
	printf("12.Sientes dolor al respirar?\n\n\t(S/N): ");
	Excepcion_Respuesta(Respuestas+11);
	printf("13.Sientes falta de aire al hablar o caminar algunos pasos?\n\n\t(S/N): ");
	Excepcion_Respuesta(Respuestas+12);
	printf("14.Tienes coloracion azul o morada en labios, dedos o unas?\n\n\t(S/N): ");
	Excepcion_Respuesta(Respuestas+13);
	printf("15.Tienes diarrea o vomito?\n\n\t(S/N): ");
	Excepcion_Respuesta(Respuestas+14);
	printf("16.Has perdido el olfato o el gusto?\n\n\t(S/N): ");
	Excepcion_Respuesta(Respuestas+15); 		
	return;	
}

void Evaluacion(char *Respuestas,Ciudadano C,int *Puntuacion){
	
	int Puntos=0;
		
	if(C.Edad<=65&&C.Edad>=0)
	Puntos+=2;
	else if (C.Edad>65&&C.Edad<=84)
	Puntos+=3;
	else if(C.Edad>84)
	Puntos+=4;
	
	if(*(Respuestas)=='S')
	Puntos+=3;
	if(*(Respuestas+1)=='S')
	Puntos+=3;
	if(*(Respuestas+2)=='S')
	Puntos+=3;
	if(*(Respuestas+3)=='S')
	Puntos+=3;
	if(*(Respuestas+4)=='S')
	Puntos+=4;
	if(*(Respuestas+5)=='S')
	Puntos+=3;
	if(*(Respuestas+6)=='S')
	Puntos+=4;
	if(*(Respuestas+7)=='S')
	Puntos+=2;
	if(*(Respuestas+8)=='S')
	Puntos+=2;
	if(*(Respuestas+9)=='S')
	Puntos+=2;
	if(*(Respuestas+10)=='S')
	Puntos+=3;
	if(*(Respuestas+11)=='S')
	Puntos+=4;
	if(*(Respuestas+12)=='S')
	Puntos+=4;
	if(*(Respuestas+13)=='S')
	Puntos+=4;
	if(*(Respuestas+14)=='S')
	Puntos+=2;
	if(*(Respuestas+15)=='S')
	Puntos+=2;
	
	*Puntuacion=Puntos;
	
	/*if(Puntos<6&&*(Respuestas)=='S'){
		printf("El ciudadano tiene una baja probabilidad de contagio");
	}
	else if(Puntos<7&&*(Respuestas+1)=='S'){
		printf("El ciudadano tiene una probabilidad de contagio media");
	}
	else if(Puntos>11&&*(Respuestas)=='S'&&*(Respuestas+10)=='S'){
		printf("El ciudadano tiene una alta probabilidad de contagio");
	}*/
	
	system("cls");
	if(Puntos<=10){
		printf("\n\n\t\t%s tiene una probabilidad baja de padecer coronavirus. \n\n\t\t Quedate en casa y atiendes las indicaciones.\n\n",C.Nombre);
	}	
	else if(Puntos<=22&&Puntos>10){
		printf("\n\n\t\t%s tiene una probabilidad media de padecer coronavirus.\n\n\t\t Es importante que estés al pendiente de tu salud por unos dias.\n\n",C.Nombre);
	}
	else if(Puntos<=36&&Puntos>22){
		printf("\n\n\t\t%s tiene una probabilidad alta de padecer coronavirus. \n\n\t\tNo es necesario que acudas al hospital. si tus sintomas cambian vuelve a hacer la prueba\n\n",C.Nombre);
	}
	else if(Puntos>36){
		printf("\n\n\t\t%s tiene una probabilidad muy alta de padecer coronavirus. \n\n\t\tEs muy importante que te pongas en contacto con las autoridades y acudas de inmediato a un hospital.\n\n",C.Nombre);
	}
	return;
}

void Reporte(Ciudadano C,int Puntos,char Respuestas[]){
	
	FILE *f = fopen("reporte.txt","w");
	if(f == NULL)
	printf("\n\tEl fichero no se ha podido abrir, no existe.");
	
	fprintf(f,"Nombre: ");
	fputs(C.Nombre,f);
	fprintf(f,"\nApellidos: ");
	fputs(C.Apellido1,f);
	fprintf(f," ");
	fputs(C.Apellido2,f);
	fprintf(f,"\nSexo: ");
	fputs(C.Sexo,f);
	fprintf(f,"\nEdad: %d\n",C.Edad);
	fprintf(f,"Mail: ");
	fputs(C.Mail,f);
	fprintf(f,"\nTelefono: ");
	fputs(C.Telefono,f);
	fprintf(f,"\nDireccion: ");
	fputs(C.Direccion,f);
	fprintf(f,"\nPuntuacion: %d\n",Puntos);
	//fprintf(f,"1. %s\n",Respuestas[0]);
		
	if(Puntos<=10){
		fprintf(f,"Probabilidad baja");
	}	
	else if(Puntos<=22&&Puntos>10){
		fprintf(f,"Probabilidad media");
	}
	else if(Puntos<=36&&Puntos>22){
		fprintf(f,"Probabilidad alta");
	}
	else if(Puntos>36){
		fprintf(f,"Probabilidad muy alta");
	}
		
	fclose(f);

return;	
}

int main(){
	
	Ciudadano C; //Arreglo de estructuras ciudadanos
	char Respuestas[16];//Registro de las respuestas del cuestionario
	int Puntuacion=0;
		
			Test(&C,Respuestas); 
			Evaluacion(Respuestas,C,&Puntuacion);
			Reporte(C,Puntuacion,Respuestas);	
			system("PAUSE");
			system("PAUSE");			
	
	return 0;
}
