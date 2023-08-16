# Trabajo 1 Sistemas Operativos INFO198 2023 II

El programa consiste en ingresar un usuario u y un vector v. Se verifica que el usuario exista en la Base de Datos BD.txt para asi poder realizar las 4 operaciones disponibles en opciones.txt con el vector y tambien se comprueba que el usuario tenga los permisos necesarios para realizar las operaciones que quiere. Se imprime en pantalla los resultados correspondiente y finalmente se da la opción de agregar mas datos a BD.txt.

# Comando para compilar
Escriba 'make' en el directorio correspondiente.

# Comando para ejecutar
Escriba ./prog -u NombreUsuario -v Vector  
Donde:
  - NombreUsuario es su nombre de usuario el cual será verificado si existe en la BD.
  - Vector es un vector de la forma a,b,c,d,... de enteros.

# Explicación de la Base de Datos  
El archivo BD.txt contiene en cada linea los datos del usuario. Cada linea es de la forma: NombreUsuario 1,2,3,4
donde 1,2,3,4 son los permisos disponibles para las opciones disponibles. No necesariamente cada usuario tiene todos los permisos.

Al final se asume que el usuario ingresa lineas válidas a la Base de Datos.


