![Logo](https://user-images.githubusercontent.com/105953019/211302587-2d25f503-5e47-428c-a74a-32b8e97e9d2a.png)
 # NotSSH V 1.0.01 

**Índice**   
1. [Resumen](#resumen)
2. [Instalacion](#instalacion)


### Resumen<a name="resumen"></a>
Este repositorio contiene una aplicación cliente-servidor llamada "NotSSH" que permite ejecutar comandos a nivel de sistema de forma remota. La aplicación está dividida en dos partes: un cliente y un servidor.

El código del servidor se encarga de crear un socket y asociarlo a un puerto especificado por el usuario. A continuación, el servidor escucha por conexiones entrantes y, cuando recibe una, acepta la conexión y comienza a recibir comandos del cliente. Cuando recibe un comando, el servidor lo ejecuta en el sistema y envía el resultado de vuelta al cliente.

El código del servidor incluye algunas funciones auxiliares para leer archivos, obtener el nombre de usuario y el nombre del host, y asignar memoria dinámicamente. También se usa la función system para ejecutar comandos en el sistema.

Es importante tener en cuenta que esta aplicación no implementa ningún tipo de seguridad, por lo que se recomienda tener precaución al utilizarla. Se recomienda utilizar esta aplicación solo en entornos de prueba o en redes confiables.


## Instalacion <a name="instalacion"></a>  <img src="https://user-images.githubusercontent.com/105953019/211303153-4d2c1e12-5f01-4a17-abc0-f9df24a1583d.png " width="32" height="32" />


<h4> Puedes elejir entre: </h4>

<h5> 1.- Descargar un compilado desde: https://github.com/zYoplyd/notssh/releases </h5>
<h5> 2.- Compilarlo tu mismo (Tutorial abajo).</h5>

<h4>Para descargar y compilar la aplicación "nssh", debes seguir los siguientes pasos: </h4>

- Abre una terminal en tu sistema operativo.

- Asegúrate de tener instalado Git en tu sistema. Si no lo tienes instalado, puedes instalarlo con el siguiente comando:
```shell
 sudo apt-get install git
```
- Usa el comando git clone para descargar el repositorio "nssh" a tu ordenador:
```shell
 git clone https://github.com/zYoplyd/notssh.git
```
	
- Accede al directorio del repositorio descargado:
```shell
 cd notssh
```
- Usa el comando make para compilar el código de la aplicación:
```shell
 make
```
- Si la compilación se ha completado correctamente, encontrarás los archivos ejecutables "notssh-client" y "notssh-server" en el directorio del repositorio.
