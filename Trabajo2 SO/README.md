# Trabajo 2 Sistemas Operativos
Este README tiene como objetivo proporcionar instrucciones detalladas para reconstruir y ejecutar "Mi Aplicación". Incluso si pierdes el código y las Base de Datos, estas instrucciones te permitirán volver a poner en marcha el sistema.  

# Descripción  
El programa consiste en ingresar un usuario u; un vector v; un path/nombre de un archivo a crear f y un texto t. Se verifica que el usuario exista en la Base de Datos BD.txt y se guardan sus permisos correspondientes para asi poder realizar las operaciones las cuales tiene disponible. Se imprime en pantalla los resultados hasta que el usuario ingresa el entero 0, el cual significa que termina la interacción. Finalmente se da la opción de agregar mas datos a BD.txt. **Se asume que ingresará nuevos usuarios y permisos de la forma correcta**.

# Estructura de Archivos
Esta aplicación ha sido desarrollada de manera modular para facilitar la flexibilidad y la personalización. El programa esta estructurado de la siguiente manera:
  - **main.cpp**: Código principal el cual se encarga del flujo total de la aplicación.
  - **procEntrada.cpp**: Código que se encarga de validar que el usuario u exista en la Base de Datos BD.txt y extrae todos sus permisos.
  -   **operarVector.cpp**: Código el cual esta implementada la funcion que retorna la moda del vector v ingresado, es decir, se invoca cuando se selecciona la opción 3) de la Base de Datos menu.txt. Notar que las demas operaciones disponibles con el vector se hicieron utilizando funciones de las bibliotecas disponibles que ofrece C++.
  -   **operarArchivo.cpp**: Código el cual se realizan las operaciones 5) y 6) de la Base de Datos menu.txt. Ademas permite agregar mas usuarios a la Base de datos BD.txt.
  -   **loopConUsuario.cpp**: Código el cual contiene la interacción con el usuario y realiza las operaciones que selecciona.
  -   **metodos.h**: Un archivo de tipo .h el cual contiene la declaración de todos los metodos utilizados en esta aplicación.
  -   **Makefile**: Un Makefile disponible para automatizar y gestionar el proceso de compilación.

# Base de Datos 
La aplicación contiene 2 archivos **.txt** los cuales cumplen la función de ser la Base de datos. A continuación una breve descripción:
  - **BD.txt**: Archivo el cual contiene el nombre de usuario u y sus permisos correspondientes, los cuales son su disponibilidad para realizar cada operación. Notar que esta Base de Datos da salto de linea cada vez que se tiene lo requerido.
  - **menu.txt**: Archivo el cual contiene el menú desplegable que se muestra en pantalla, es la información que el usuario necesita para elegir una operación a realizar. No olvidar que antes de realizar la operación se verifica que el usuario tenga los permisos para poder realizarla. Este menú desplegable se limpia de la consola automaticamente luego de 10 segundos de mostrar el resultado de la operación, lo cual es mas amigable para el usuario que lo esta ejecutando.

# Requisitos Previos
De preferencia:
  - Sistema: Operativo Ubuntu/Linux
  - Editor: Visual Studio Code https://code.visualstudio.com/

# Pasos para compilar
  - Abrir la consola en el editor.
  - Para clonar este repositorio escribir en la consola: https://github.com/PipeCordova/Trabajos_INFO198_2023_II.git
  - Dirigirse a la carpeta de nombre **Trabajo 2 SO**, allí se encuentra lo necesario para ejecutar la aplicación.
  - Haga click derecho encima de la carpeta mencionada y seleccione la opción: **Open in Integrated terminal**, esto abrirá una consola con la ubicación de la carpeta.
  - Escriba el comando: **make**

Note que se habrá creado un ejecutable **prog** en la carpeta, esto quiere decir que esta listo para ejecutar.

# Pasos para ejecutar
Considere ahora la forma de la entrada es: **./prog -u nombreUsuario -v vector -f "path/nombre" -t "Texto"**, donde:
  - **nombreUsuario** Es su nombre de usuario, el cual sera verificado si existe en la Base de Datos BD.txt. **Note que su nombre se usuario debe ir sin espacios.**
  - **vector** Es un vector de la forma **a,b,c,...,z** donde cada elemento es de tipo entero. **Note que debe ingresar cada entero separado por una coma.**
  - **path/nombre** Es la ruta exacta donde se creará el archivo correspondiente si lo selecciona. Siendo **path** la ruta y **nombre** el nombre del archivo con su respectiva extensión.  
    Por ejemplo: /home/nombreEquipo/Escritorio/Carpeta Favorita/holaMundo.txt
    En este ejemplo:
      - path sería **/home/nombreEquipo/Escritorio/Carpeta Favorita**, ya que es la ruta donde queremos que se guarde el archivo.
      - nombre sería **holaMundo.txt**, ya que es el nombre del archivo que queremos con su extensión, ya sea .txt, .csc, .py, etc.  
Una vez con la entrada clara, ejecute de la forma mencionada.


    

    













