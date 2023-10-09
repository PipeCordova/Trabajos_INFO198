# Trabajos_INFO198

Trabajos de la asignatura INFO198 2023 II.

# Descripción

La aplicación se basa en leer una entrada de 6 inputs ingresada por el usuario, los cuales son los datos que el programa procesa para luego darle una respuesta al usuario de acuerdo a sus necesiades y las opciones disponibles que él dispone, ya que se verifica en la base de datos data/BD.txt que tipo de usuario es, ya sea admin, userGeneral o userRookie.

# Explicacion de cada programa de la carpeta src

  - **main.cpp**: Programa principal que se encarga del control de la aplicación, en este se extraen los parametros de entrada del usuario, para luego hacer unas verificaciones correspondientes. Se crean variables de string para almacenar el valor de las variables de entorno previamente cargadas. Seguido de esto se muestra el menú desplegable y se pide al usuario que ingrese un número con la opción que él desee ejecutar.Se verifica que el usuario tenga permiso para ejecutar esa opción. El programa termina hasta que el usuario ingrese el número 0.  

  - **interaccion.cpp**: Cuando el usuario ingresa una opción, el programa viene hasta este archivo para ejecutar la opción seleccionada. Puede revisar en detalle las opciones disponibles en la base de datos data/menu.txt.

  - **controlArchivos.cpp**: Aquí se manejan las opciones de creación de archivos o agregación de linea en el archivo, lo cual corresponde a la opción 5 y 6. Tambien se creó una función para obtener los permisos desde data/perfilesUsuario.txt, de acuerdo al usuario ingresado.

  - **procesarCuento.cpp**: Se crean funciones para el procesamiento del cuento que esta en la carpeta io, esto es para que funcione la opción 7 del menú. Basicamente se cuentan las palabras, se eliminan simbolos extraños y se ordena de acuerdo a la ocurrencia.

  - **controlEntrada.cpp**: Aquí se crean funciones para la verificación de la entrada, verificar si el usuario existe en la base de datos y para convertir a vector el string vector de la entrada. 

# Cargar variables de entorno

set -o allexport  
source config/.env  
export  


# Ejecucion

./prog -u Clarita -v 3,1,4,5,2,2,3 -f "ft/hola.py" -t "print(':D')" -i "io/cuento.txt" -o "io/salida.txt"

