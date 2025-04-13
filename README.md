# tarea 1 estuctura de datos

El objetivo del proyecto es crear una aplicacion para el mejor manejo de tickets de soporte tecnico , calificandolos por prioridad , con una iterfaz amigable para el usuario y facil de comprender y utilizar 

## Caracteristicas de la aplicacion

- [x] Registrar tickets (ID , prioridad)
- [x] Asignar diversas prioridades (Alta , Media y Baja)
- [x] Mostar los tickets pendientes por nivel de prioridad
- [x] Procesa los tickets de manera inteligente (prioridad e tiempo de atiguedad)
- [x] Busqueda de tickets por ID
- [x] Mostrar los detalles de un ticket especifico (si no existe se indicara)


## Tecnologías utilizadas
- C
- Git
- GNU Compiler Collection (GCC)


## Instalación

1. Clona el repositorio en tu maquina local (git clone https://github.com/Knox2904/tareas-estructura-datos.git)
2. Accede a la carpeta del proyecto. Usa el comando cd seguido de la ruta , puedes usar el comando dir para listar las carpetas y confirmar tu ubicación
3. Compila el código con el siguiente comando (gcc tarea1.c tdas/*.c -o programa.exe)
4. Ejecuta el programa (.\programa.exe)

Notas: 
- si gcc no esta instalado tendra que instalarlo
- asegurese de estar en la misma carpeta de donde estan los archivos tarea1.c y la carpeta tdas de lo contrario no compliara

## Uso

Ejecute el programa siguiendo las instrucciones previamente dadas. Una vez en ejecución, se mostrará un menú con varias opciones para gestionar los tickets: agregar, modificar o eliminarlos.

Seleccione la opción deseada y siga las instrucciones en pantalla.
En caso de seleccionar una opción que requiera al menos un ticket, y que este no haya sido creado correctamente, el programa le avisará del error.

Para evitar problemas:
* No cree un ticket con una descripción mayor a 100 caracteres
* Utilice únicamente las prioridades "Baja", "Media" o "Alta"
* Al ingresar la hora, siga el formato "00:00" (hora:minutos). Aunque el programa acepta otros formatos mientras no superen 7 caracteres, esto podría causar confusión visual para otros usuarios
* Evite utilizar números decimales al asignar el ID de un ticket.

Importante:
* El programa no guarda los datos al cerrarse; todos los tickets se perderán si reinicia el programa
* Todos los nuevos tickets se crean inicialmente con prioridad "Baja". Puede cambiar la prioridad seleccionando la opción correspondiente en el menú
* El sistema maneja los tickets siguiendo la siguiente jerarquía: Prioridad > Antigüedad > Hora (Es decir, los tickets de mayor prioridad y más antiguos se procesarán primero.)

## Contribuciones 

basicamente todo el trabajo yo Gabriel lopez , creditos tambien a Felipe Castro , Luis Guzman y Juan Araya por ayudar con el mapa mental durante clases sobre el trabajo para asi poder tener una idea mas o menos clara de por donde empezar.

## Errores conocidos

* ~~El código no compilaba correctamente~~ → Solucionado: ahora el programa compila sin errores
* ~~La mayoría de las funciones no estaban creadas~~ → Solucionado: todas las funciones están implementadas y funcionan correctamente
* La descripción de un ticket no debe superar los 100 caracteres, de lo contrario el programa puede fallar
* La prioridad de un ticket no debe superar los 20 caracteres, para evitar errores
* El campo de la hora no debe superar los 7 caracteres, ya que puede causar errores de formato
* ~~La función registrarTicket generaba un error en el bucle~~ → Solucionado: ahora la función registrarTicket funciona correctamente y verifica que no se repitan los IDs

Notas: 
* Si el programa se reinicia, los datos no se guardan (no hay persistencia en disco)
* evitar ingresar IDs decimales (por ejemplo, 1.5) ya que solo se aceptan números enteros

