#include "tdas/list.h"
#include "tdas/extra.h"
#include <stdio.h>
#include <stdlib.h>

//estructura para guardar los datos de los tickets
typedef struct {

  size_t id ; 
  char descripcion[100] ;
  char prioridad[20] ; 
  char hora[6] ; 

} ticket ; 



// Menú principal
void mostrarMenuPrincipal() {
  limpiarPantalla();
  puts("=============================================================");
  puts("     Sistema de Gestion de Tickets de soporte tecnico        ");
  puts("=============================================================");

  puts("1) Registrar ticket");
  puts("2) Asignar prioridad al ticket");
  puts("3) Mostrar lista de tickets pendientes");
  puts("4) Procesar siguente ticket");
  puts("5) Buscar ticket por ID y detalles");
  puts("6) Salir");
}

//Inicio de los tickets y asignacion de memoria
ticket *crearTicket(){
  ticket *t = (ticket*)malloc(sizeof(ticket)) ; 
  if(t == NULL) exit(EXIT_FAILURE) ; 
  return t ; 

}

//registro de los tickets
void registrarTicket(List *prioBaja ) {
  printf("Registrar nuevo ticket\n");

  ticket *Nticket = crearTicket() ; 

  printf("ingrese el ID : \n") ; 
  scanf("%zd" , Nticket->id) ;
  printf("ingrese la descripcion del problema : \n") ;

  scanf(" %[^\n]s" , Nticket->descripcion);

  strcpy(Nticket->prioridad , "Bajo") ; 
  printf("ingrese la hora de creacion del ticket : \n") ;
  
  scanf(" %[^\n]s" , Nticket->hora);

  list_pushFront(prioBaja , Nticket) ; 

}

//funcion para cambiar prioridades
void asignarPrioridad(List *prioridadBaja , List* prioridadMedia , List* prioridadAlta){
  if(list_first(prioridadBaja) == NULL && list_first(prioridadMedia) == NULL && list_first(prioridadAlta) == NULL){
    printf("Actualemete no hay tickets creados \n") ;
    return ;
  }

  size_t ticketID ;
  printf("ingrese el ID del ticket al que se le desa cambiar la prioridad: \n") ;
  scanf("%zd" , &ticketID) ;

  ticket* ticketActual = (ticket*) list_first(prioridadBaja) ;

  while(ticketActual != NULL) {
    if(ticketActual->id == ticketID){
      printf("se encontro el ID , seleccione la nueva prioridad (1.- Alto , 2.- Medio , 3.- Bajo ):\n") ;
      int nuevaPrioridad ;
      scanf("%d" , &nuevaPrioridad) ;

      switch (nuevaPrioridad) {
      case 1 :
        strcpy(ticketActual->prioridad , "Alto") ; 
        break;

      case 2:
        strcpy(ticketActual->prioridad , "Medio") ; 
        break;
        
      case 3:
        strcpy(ticketActual->prioridad , "Bajo") ; 
        break;

      default:
        break;
      }
    }

    ticketActual = list_next(prioridadBaja) ;
  }

}


void mostrar_lista_pacientes(List *pacientes) {
  // Mostrar pacientes en la cola de espera
  printf("Pacientes en espera: \n");
  // Aquí implementarías la lógica para recorrer y mostrar los pacientes
}

int main() {
  char opcion;
  List *listaPrioridadBaja = list_create() ; //lista que se va a usar para guardar a los pacientes de prioridad baja
  List *listaPrioridadMedia = list_create() ; //lista que se va a usar para guardar a los pacientes de prioridad media
  List *listaPrioridadAlta = list_create() ; //lista que se va a usar para guardar a los pacientes de prioridad alta


  do {
    mostrarMenuPrincipal();
    printf("Ingrese su opcion: ");
    scanf(" %c", &opcion); // Nota el espacio antes de %c para consumir el
                           // newline anterior

    switch (opcion) {
    case '1':
      registrarTicket(listaPrioridadBaja); //problema de iteracion revisar
      break;
    case '2':
      asignarPrioridad(listaPrioridadBaja , listaPrioridadMedia , listaPrioridadAlta) ; 
      break;
    case '3':
      
      break;
    case '4':
      // Lógica para atender al siguiente paciente
      break;
    case '5':
      // Lógica para mostrar pacientes por prioridad
      break;
    case '6':
      puts("Saliendo del sistema de gestion de tickets...");
      break;
    default:
      puts("Opcion no válida. Por favor, intente de nuevo.");
    }
    presioneTeclaParaContinuar();

  } while (opcion != '6');

  // Liberar recursos, si es necesario
  //list_clean();
  free(listaPrioridadBaja) ;
  free(listaPrioridadMedia) ;
  free(listaPrioridadAlta) ;

  return 0;
}
