#include "tdas/list.h"
#include "tdas/extra.h"
#include <stdio.h>
#include <stdlib.h>

//estructura para guardar los datos de los tickets
typedef struct {

  size_t id ; 
  char* descripcion ;
  char* prioridad ; 
  char* hora ; 

} ticket ; 



// Menú principal
void mostrarMenuPrincipal() {
  limpiarPantalla();
  puts("=============================================================");
  puts("     Sistema de Gestion de Tickets de soporte tecnico        ");
  puts("=============================================================");

  puts("1) Registrar ticket");
  puts("2) Asignar prioridad a paciente");
  puts("3) Mostrar lista de espera");
  puts("4) Atender al siguiente paciente");
  puts("5) Mostrar pacientes por prioridad");
  puts("6) Salir");
}

//Inicio de los tickets y asignacion de memoria
ticket *crearTicket(){
  ticket *t = (ticket*)malloc(sizeof(ticket)) ; 
  if(t == NULL) exit(EXIT_FAILURE) ;
  t->descripcion = (char*)malloc(100 * sizeof(char));  
  t->prioridad = (char*)malloc(20 * sizeof(char));  
  t->hora = (char*)malloc(7 * sizeof(char));  
  return t ; 

}

//registro de los tickets
void registrarTicket(List *prioBaja ) {
  printf("Registrar nuevo ticket\n");

  ticket *Nticket = crearTicket() ; 

  printf("ingrese el ID : \n") ; 
  scanf("%zd" , Nticket->id) ;
  printf("ingrese la descripcion del problema : \n") ; 
  scanf("%[^\n]s" , Nticket->descripcion) ;
  strcpy(Nticket->prioridad , "Bajo") ; 
  printf("ingrese la hora de creacion del ticket : \n") ; 
  scanf("%[^\n]s" , Nticket->hora) ;

  list_pushFront(prioBaja , Nticket) ; 

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
      registrarTicket(listaPrioridadBaja);
      break;
    case '2':
      // Lógica para asignar prioridad
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
