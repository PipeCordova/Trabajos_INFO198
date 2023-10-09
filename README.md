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


# Cargar variables de entorno antes de compilar

Escriba en la consola en la carpeta **proyecto en progreso** los siguientes comandos:  
  `set -o allexport`        
  `source config/.env`      
  `export`      

Gracias a estos comandos se cargaran las variables de entorno, definidas en config/.env. Estas variables de entorno tienen la ruta exactas donde se encuentran las bases de datos, y lo necesario para ejecutar la opcioón 8  y 9, es decir, el tipo de extensión, el numero de threads, carpeta de entrada y salida, y la ruta con el archivo de indices invertidos.  

# Comando para compilar

Escriba en consola el comando `make`    
Gracias al Makefile proporcionado, la compilación se simplifica.  

# Comando para ejecutar

La ejecución es de la forma: ./prog -u `userName` -v `a,b,c,...z` -f `"path/nombre"` - t `"texto"` -i `"path/textoEntrada"` -o `"path/textoSalida"`  

A continuación se explica en detalle cada argumento ingresado:  
  - `userName` es su nombre de usuario. Se validará si este nombre existe en la base de datos data/DB.txt.
  - `a,b,c,...,z` es el vector de entrada. Ingrese números enteros separados por comas.
  - `path/nombre` path es la ubicación donde deseas que se guarde un archivo y el nombre del archivo que deseas crear. Notar que se ingresa entre comillas!
  - `texto`es el texto que quiere agregar al archivo creado cuando se selecciona la opción correspondiente.
  - `path/textoEntrada` es la ubicacion exacta donde se encuentra el cuento para que se gatille la opción de contar las palabras.
  - `path/textoSalida` es el archivo que se crea con el resultado una vez ejecutada la opción de contar palabras, es de la forma: palabra1, cantidad

 Un ejemplo simple de ejecución sería: ./prog -u Clarita -v 3,1,4,5,2,2,3 -f "ft/hola.py" -t "print(':D')" -i "io/cuento.txt" -o "io/salida.txt"


 # Explicación Base de Datos

 Se encuentran en la carpeta data, hay 3 archivos txt. A continuación una explicación breve.  
  - `BD.txt`es el archivo donde estan los usuarios registrados en el sistema y su perfil. Es de la forma: `userName perfil`, perfil puede ser: admin, userGeneral o userRookie.
  - `menu.txt`es el archivo con el menú desplegable que se muestra cuando se ejecuta el código.
  - `perfilesUsuarios.txt` es el archivo en el cual estan los permisos de usuario, de acuerdo si es admin, userGeneral o userRookie. Estos son los permisos para los cuales puede acceder o no el usuario cuando se muestra el menú desplegable. Es de la forma: `perfil = 0,1,...,9`















