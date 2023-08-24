# Trabajo 2 Sistemas Operativos

Este README tiene como objetivo proporcionar instrucciones detalladas para reconstruir y ejecutar "Mi Aplicación". Incluso si pierdes el código y los datos, estas instrucciones te permitirán volver a poner en marcha el sistema.  

# Descripción  
El programa consiste en ingresar un usuario u; un vector v; un path/nombre de un archivo a crear f y un texto t. Se verifica que el usuario exista en la Base de Datos BD.txt y se guardan sus permisos correspondientes para asi poder realizar las operaciones las cuales tiene disponible. Se imprime en pantalla los resultados y finalmente se da la opción de agregar mas datos a BD.txt. **Se asume que ingresará nuevos usuarios y permisos de la forma correcta**.

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


    

    













