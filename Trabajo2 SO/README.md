# Trabajo 2 Sistemas Operativos

El programa consiste en ingresar un usuario **u**, un vector **v**, un nombre de archivo **f** y un texto **t** para agregar al archivo. Se verifica que el usuario exista en la Base de Datos **BD.txt** y que el nombre de archivo ingresado no exista en la carpeta **Trabajo2 SO**. Una vez validada la entrada, se muestra en pantalla las opciones disponibles leídas desde **menu.txt** y se muestra en pantalla los resultados correspondientes. El programa termina dando la opción de agregar mas usuario a la Base de datos.  

# Comando para compilar
- Diríjase a su editor favorito y clone este repositorio con el comando: git clone <link>
- Abra la carpeta **Trabajo2 SO** y vaya a su terminal correspondiente.
- Una vez en la terminal, escriba: make

# Comando para ejecutar
Escriba ./prog -u NombreUsuario -v Vector -f NombreArchivo -t "TextoAgregar"
Donde:
  - NombreUsuario es su nombre de usuario el cual será verificado si existe en la BD.
  - Vector es un vector de la forma a,b,c,d,...,z de enteros.
  - NombreArchivo es el nombre que desea que se llame su nuevo archivo a crear dentro del programa.
  - "TextoAgregar" es el texto que desea agregar al archivo creado. **Notar que debe ir entre comillas el texto.**

# Explicación de la Base de Datos  
El archivo **menu.txt** contiene las opciones disponibles para esta ocación. Respecto al **Trabajo1 SO**, se agregó:
  - Opción **0**: Permite terminar la ejecución si el usuario lo desea.
  - Opción **5**: Permite crear un archivo **.txt** con el nombre ingresado en el parametro **-f**.
  - Opción **6**: Permite agregar texto al archivo creado. Se da la opción de agregar más lineas iterativamente.
  - Opción **7**: Opción no creada hasta este momento. Si ingresa un número fuera de las opciones disponibles mostrará esta opción.


Si desea agregar más usuario a la Base de Datos **BD.txt**, se asume que ingresará de forma correcta.



