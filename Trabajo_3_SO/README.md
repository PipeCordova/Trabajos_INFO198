
# Trabajo 3 Sistemas Operativos
Este README tiene como objetivo proporcionar instrucciones detalladas para reconstruir y ejecutar "Mi Aplicación". Incluso si pierdes el código y las Base de Datos, estas instrucciones te permitirán volver a poner en marcha el sistema.  

# Descripción  
El programa consiste en ingresar un usuario u; un vector v; un path/nombre de un archivo a crear f; un texto t; un input path/nombre i y un output path/nombre o. Se verifica que el usuario u exista en la Base de Datos BD.txt y se vé que tipo de usuario es, este puede ser: admin, userGeneral o userRookie. Independiente cual sea su permiso, el programa lee la Base de Datos perfilesUsuarios.txt y extrae los permisos correspondientes al tipo de usuario mencionado. Se imprime en pantalla los resultados correspondientes hasta que el usuario ingresa el entero 0, el cual significa que termina la interacción con las operaciones. Finalmente se da la opción de agregar mas datos a BD.txt. **Se asume que ingresará nuevos usuarios y permisos de la forma correcta**. Por ejemplo: nombreUsuario admin

# Estructura de Archivos
El programa esta estructurado en la carpeta **archivosCPP** de forma modular de la siguiente manera:  
  - **procEntrada.cpp**: Código que se encarga de validar que el usuario u exista en la Base de Datos BD.txt y extrae el tipo de usuario.
  - **operarVector.cpp**: Código el cual esta implementada la funcion que retorna la moda del vector v ingresado, es decir, se invoca cuando se selecciona la opción 3) de la Base de Datos menu.txt. Notar que las demás operaciones disponibles con el vector se hicieron utilizando funciones de las bibliotecas disponibles que ofrece C++.
  - **operarArchivo.cpp**: Código el cual se realizan las operaciones 5) y 6) de la Base de Datos menu.txt. Ademas permite agregar mas usuarios a la Base de datos BD.txt si es que el usuario lo desea.
  - **loopConUsuario.cpp**: Código el cual contiene la interacción con el usuario y realiza las operaciones que selecciona.
  - **vectorPermisos.cpp**: Se encarga de retornar un vector con los permisos respectivos al usuario ingresado. Esto lo extrae desde la Base de Datos menu.txt.
  - **procesarCuento.cpp**: Código que se encarga de realizar la operación 7), osea de contar la cantidad de veces que repite cada palabra en el texto de entrada -i.  
  -   **metodos.h**: Un archivo de tipo .h el cual contiene la declaración de todos los metodos utilizados en esta aplicación.

Estas implementaciones se encuentran fuera de la carpeta **archivosCPP**, para una mejor compresión del trabajo.  

  - **main.cpp**: Programa principal que se encarga del flujo total del programa.  
  
  -   **PATHS.env**: Este archivo contiene las variables de las rutas completas (path + archivo) de las diferentes bases de datos del sistema. Este tipo de variables NO estan en duro en el código fuente.
  -   **Makefile**: Un Makefile disponible para automatizar y gestionar el proceso de compilación.

# Base de Datos 
La aplicación contiene 3 archivos **.txt** los cuales cumplen la función de ser la Base de Datos. A continuación una breve descripción:
  - **BD.txt**: Archivo el cual contiene el nombre de usuario u y su tipo de usuario. Notar que esta Base de Datos da salto de linea con cada usuario distinto.
La forma de este archivo es: nombreUsuario admin
  - **menu.txt**: Archivo el cual contiene el menú desplegable que se muestra en pantalla, es la información que el usuario necesita para elegir una operación a realizar. No olvidar que antes de realizar la operación se verifica que el usuario tenga los permisos para poder realizarla. Este menú desplegable se limpia de la consola automaticamente luego de 5 segundos de mostrar el resultado de la operación, lo cual es mas amigable para el usuario que lo esta ejecutando.
  - **perfilesUsuario.txt**: Este archivo contiene los permisos a los cuales corresponde cada tipo de usuario. Por ejemplo un admin tienen todos los permisos, osea 0,1,2,3,4,5,6,7

# Requisitos Previos
De preferencia:
  - Sistema Operativo: Ubuntu/Linux
  - Editor: Visual Studio Code https://code.visualstudio.com/

# Pasos para compilar
  - Abrir la consola en el editor.
  - Para clonar este repositorio escribir en la consola: https://github.com/PipeCordova/Trabajos_INFO198_2023_II.git
  - Dirigirse a la carpeta de nombre **Trabajo_3_SO**, allí se encuentra lo necesario para ejecutar la aplicación.
  - Haga click derecho encima de la carpeta mencionada y seleccione la opción: **Open in Integrated terminal**, esto abrirá una consola con la ubicación de la carpeta.
  - Escriba el comando: **make**

Note que se habrá creado un ejecutable **prog** en la carpeta, esto quiere decir que esta listo para ejecutar.

# Pasos para ejecutar
Considere ahora la forma de la entrada es: **./prog -u nombreUsuario -v vector -f "path/nombre" -t "Texto" -i "path/nombre2" -o "path/nombre3"**, donde:
  - **nombreUsuario** Es su nombre de usuario, el cual sera verificado si existe en la Base de Datos BD.txt. **Note que su nombre se usuario debe ir sin espacios.**
  - **vector** Es un vector de la forma **a,b,c,...,z** donde cada elemento es de tipo entero. **Note que debe ingresar cada entero separado por una coma.**
  - **path/nombre** Es la ruta exacta donde se creará el archivo correspondiente si lo selecciona. Siendo **path** la ruta y **nombre** el nombre del archivo con su respectiva extensión.  
    Por ejemplo: /home/nombreEquipo/Escritorio/Carpeta Favorita/holaMundo.txt
    En este ejemplo:
      - path sería **/home/nombreEquipo/Escritorio/Carpeta Favorita**, ya que es la ruta donde queremos que se guarde el archivo.
      - nombre sería **holaMundo.txt**, ya que es el nombre del archivo que queremos con su extensión, ya sea .txt, .csc, .py, etc.  
Una vez con la entrada clara, ejecute de la forma mencionada.
  - **Texto** Es el texto que se agregará en el archivo creado en la ruta ingresada. **Note que si el archivo existe, no crea otro archivo, solo agregará el texto en la última linea de ese archivo ya existente. En caso de no existir, creará el archivo y agregará el texto.**
  - **path/nombre2** Es la ruta exacta donde se encuentra el archivo de texto de entrada (input), el cual debe ser al menos de 1MB. En este caso el cuento se prueba se encuentra en la carpeta input_output.
  - **path/nombre3** Es la ruta exacta donde quiere que se guarde el archivo de salida (output) al seleccionar la opcion 7 de la aplicación, osea, contar la cantidad de veces que se repite una palabra. 


**Un ejemplo de ejecución sería:** ./prog -u Pipe -v 1,2,3,4,5 -f "/home/felipe/Escritorio/Sistemas Operativos/probando archivos/jajajaj.txt" -t "holaMundo" -i "/home/felipe/Escritorio/Sistemas Operativos/Semana 3/Trabajo_3_SO/input_output/cuento" -o "/home/felipe/Escritorio/Sistemas Operativos/Semana 3/Trabajo_3_SO/input_output/salida"

  
