# NSSH
**Índice**   
1. [Resumen](#id1)
2. [Instalacion](#id2)


### Resumen<a name="id1"></a>
Este repositorio contiene una aplicación cliente-servidor llamada "nssh" que permite ejecutar comandos a nivel de sistema de forma remota. La aplicación está dividida en dos partes: un cliente y un servidor.

El código del servidor se encarga de crear un socket y asociarlo a un puerto especificado por el usuario. A continuación, el servidor escucha por conexiones entrantes y, cuando recibe una, acepta la conexión y comienza a recibir comandos del cliente. Cuando recibe un comando, el servidor lo ejecuta en el sistema y envía el resultado de vuelta al cliente.

El código del servidor incluye algunas funciones auxiliares para leer archivos, obtener el nombre de usuario y el nombre del host, y asignar memoria dinámicamente. También se usa la función system para ejecutar comandos en el sistema.

Es importante tener en cuenta que esta aplicación no implementa ningún tipo de seguridad, por lo que se recomienda tener precaución al utilizarla. Se recomienda utilizar esta aplicación solo en entornos de prueba o en redes confiables.



## Instalacion <a name="id2"></a>
##### Para descargar y compilar la aplicación "nssh", debes seguir los siguientes pasos:

###### Abre una terminal en tu sistema operativo.

###### Asegúrate de tener instalado Git en tu sistema. Si no lo tienes instalado, puedes instalarlo con el siguiente comando:
```shell
 sudo apt-get install git
```
###### Usa el comando git clone para descargar el repositorio "nssh" a tu ordenador:
```shell
 git clone https://github.com/user/nssh.git
```
	
###### Accede al directorio del repositorio descargado:
```shell
 cd nssh
```
###### Usa el comando make para compilar el código de la aplicación:
```shell
 make
```
###### Si la compilación se ha completado correctamente, encontrarás los archivos ejecutables "nssh-client" y "nssh-server" en el directorio del repositorio.
[1]: http://https://github.com/zYoplyd/nssh/ "Resumen"
