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


//revisa si el id ya esta utilizado para evitar repeticiones y eventuales errores
int IDEnUso(List *prioridadBaja , List* prioridadMedia , List* prioridadAlta , size_t ID){
  List *listasPrioridades[] = {prioridadAlta , prioridadMedia , prioridadBaja};

  for(int i = 0;i < 3 ; i++){
    ticket *ticketActual  = list_first(listasPrioridades[i]) ; 
    while(ticketActual  != NULL){
      if(ticketActual ->id==ID){
        return 1;
      }
      ticketActual = list_next(listasPrioridades[i]) ;
    }
  }
  return 0 ; 
}

//registro de los tickets
void registrarTicket(List *prioridadBaja , List* prioridadMedia , List* prioridadAlta) {
  printf("Registrar nuevo ticket\n");

  ticket *Nticket = crearTicket() ; 

  printf("ingrese la descripcion del problema : \n") ;

  scanf(" %[^\n]s" , Nticket->descripcion);

  strcpy(Nticket->prioridad , "Bajo") ; 
  printf("ingrese la hora de creacion del ticket : \n") ;
  
  scanf(" %[^\n]s" , Nticket->hora);

  do{
    printf("ingrese el ID : \n") ; 
    scanf("%zd" , &Nticket->id) ;

    if(IDEnUso(prioridadAlta, prioridadMedia, prioridadBaja, Nticket->id)) {
      printf("ID en uso , favor de ingresar uno diferente \n") ; 
    }
    else break;

  }while(1) ; 


  list_pushBack(prioridadBaja , Nticket) ; 

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


  List *listasPrioridades[] = {prioridadBaja , prioridadMedia , prioridadAlta}; 

  for(int i = 0 ; i < 3 ;i++){
  ticket* ticketActual = (ticket*) list_first(listasPrioridades[i]) ;

    while(ticketActual != NULL) {

      if(ticketActual->id == ticketID){
        printf("se encontro el ID , seleccione la nueva prioridad (1.- Alto , 2.- Medio , 3.- Bajo ):\n") ;
        int nuevaPrioridad ;
        scanf("%d" , &nuevaPrioridad) ;

        list_popCurrent(listasPrioridades[i]) ; 

        switch (nuevaPrioridad) {
        case 1 :
          strcpy(ticketActual->prioridad , "Alto") ;
          list_pushBack(prioridadAlta , ticketActual) ; 
          break;

        case 2:
          strcpy(ticketActual->prioridad , "Medio") ;
          list_pushBack(prioridadMedia , ticketActual) ; 
          break;
        
        case 3:
          strcpy(ticketActual->prioridad , "Bajo") ;
          list_pushBack(prioridadBaja , ticketActual) ; 
          break;

        default:
          printf("ingrese una prioridad valida : \n") ; 
          break;
        }
        printf("cambio realizado con exito :) \n") ; 
        return;
      }

      ticketActual = list_next(listasPrioridades[i]) ;
    }
  }
  printf("ticket no encontrado \n");
}

//funcion que sirve para mostrar los tickets por prioridad y odern de llegada
void mostrarTickets(List *prioridadAlta , List* prioridadMedia , List* prioridadBaja) {
  if(list_first(prioridadBaja) == NULL && list_first(prioridadMedia) == NULL && list_first(prioridadAlta) == NULL){
    printf("Actualemete no hay tickets creados \n") ;
    return ;
  }

  List *listasPrioridades[] = {prioridadAlta , prioridadMedia , prioridadBaja};
  const char *prioridades[] = {"Alta" , "Media" , "Baja" } ;

  for(int i = 0 ; i < 3 ; i++){
    
    ticket *ticketActual = (ticket*)list_first(listasPrioridades[i]) ;
    if(ticketActual == NULL) {
      printf("no existen tickets con la prioridad actual \n") ; 
    }

    printf("\nTickets con prioridad %s en orden de llegada \n" , prioridades[i]) ;

    while(ticketActual != NULL) {
      printf("ID: %zu\n", ticketActual->id);
      printf("Descripcion: %s\n", ticketActual->descripcion);
      printf("Prioridad: %s\n", ticketActual->prioridad);
      printf("Hora de creacion: %s\n\n", ticketActual->hora);      

      ticketActual = (ticket*)list_next(listasPrioridades[i]) ;
    }

  }

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
      registrarTicket(listaPrioridadBaja, listaPrioridadMedia , listaPrioridadAlta); 
      break;
    case '2':
      asignarPrioridad(listaPrioridadBaja , listaPrioridadMedia , listaPrioridadAlta) ; 
      break;
    case '3':
      mostrarTickets(listaPrioridadAlta , listaPrioridadMedia , listaPrioridadBaja);
      break;
    case '4':
      procesarSiguenteTicket(listaPrioridadAlta , listaPrioridadMedia , listaPrioridadBaja); //por crear
      break;
    case '5':
      buscarTicketPorID(listaPrioridadAlta , listaPrioridadMedia , listaPrioridadBaja); //por crear
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
