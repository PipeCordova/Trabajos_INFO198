# Trabajo 1 Sistemas Operativos INFO198 2023 I

El programa consiste en ingresar un usuario y un vector. Se verifica que el usuario exista en la base de datos BD.txt para asi poder realizar las 4 operaciones disponibles con el vector.
Tambien se comprueba que el usuario tenga los permisos necesarios para realizar las operaciones que quiere. Se imprime en pantalla los resultados. Finalmente se da la opcion de agregar mas lineas a BD.txt y asi llenarla mas.

# Comando para compilar
Escriba 'make' en el directorio correspondiente.

# Comando para ejecutar
Escriba ./prog -u NombreUsuario -v Vector  
Donde:
  - NombreUsuario es su nombre de usuario el cual será verificado si existe en la BD.
  - Vector es un vector de la forma a,b,c,d,... de enteros.

# Explicación de la Base de Datos  
El archivo BD.txt contiene en cada linea los datos del usuario. Cada linea es de la forma: NombreUsuario 1,2,3,4
Donde 1,2,3,4 son los permisos disponibles para las opciones.txt. No necesariamente se tiene todos los permisos.

Al final del programa se da la opcion de agregar mas elementos a la BD y se asume que ingresará de la forma correcta.


