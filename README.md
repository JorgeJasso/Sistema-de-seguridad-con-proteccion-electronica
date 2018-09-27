# <font color="#841312" face="fantasy">Sistema de seguridad con protección electrónica</font>

## Introducción
> Se sabe que la inseguridad constituye uno de los grandes problemas de México ya que según datos de las procuradurías de Justicia de los estados, 2017 cerró con un total de 99,659 denuncias de robo a casa habitación sin violencia y 13,782 despojos con uso de violencia en todo el país, hecho que hace darnos cuenta de la gran utilidad que tienen las alarmas en nuestra vida diaria.

> Para poder aportar seguridad a nuestras viviendas el presente trabajo muestra la realización de una alarma utilizando Arduino, que permite o deniega (enciende la alarma al igual que los LED dentro de la casa) el acceso a la vivienda dependiendo de si la clave ingresada por el usuario es correcta o no.

## Materiales
-	1 Arduino.
-	1 Protoboard.
-	1 Teclado matricial.
-	1 Reed Switch.
-	1 Bocina.
-	1 Resistencia de 1 k.
-	2 Resistencias de 330 ohms.
-	2 LEDs.
-	Jumpers Macho Macho.
-	Cable eléctrico.

## Montaje
### Paso 1
> 1.-Conecte un jumper en la tierra del Arduino al negativo del Protoboard y otro jumper del voltaje al positivo.

> 2.-Con el cable eléctrico debe puntear el negativo para que pase al otro lado del Protoboard.

### Paso 2
> 1.-Agregue la bocina al Protoboard y a su vez en el pin 5 conecte un jumper que servirá para la entrada digital de la misma.

> 2.- Conecte a tierra el lado negativo de la bocina.

### Paso 3
> 1.-Conecte el Reed Switch al protoboard

> 2.- En el pin 4 conecte la entrada para el Reed Switch.

> 3.- En la misma fila donde conecto el Reed switch conecte la resistencia de 1 K y que esta vaya al voltaje suministrado por el Arduino.

> 4.- Conecte el Reed Switch a tierra.

### Paso 4
> 1.- Conecte dos jumpers a los pines 2 y 3 que servirán para los LED.

> 2.- Agregue las resistencias de 330 ohm.

> 3.-Coloque ambos LED en cada resistencia.

> 4.- Conéctelos a tierra.

### Paso 5
> 1.- Conecte un jumper a cada entrada del teclado matricial.

> 2.- Empezando por la izquierda del teclado matricial, conecte desde el pin número 13 hasta el pin número 5. 

### Imágenes del montaje
> Protoboard

<img src="https://github.com/JorgeJasso/Sistema-de-seguridad-con-proteccion-electronica/blob/master/Imagenes/protoboardFrente.jpg" width="500" height="400">

<img src="https://github.com/JorgeJasso/Sistema-de-seguridad-con-proteccion-electronica/blob/master/Imagenes/protoboardEspalda.jpg" width="500" height="400">

<img src="https://github.com/JorgeJasso/Sistema-de-seguridad-con-proteccion-electronica/blob/master/Imagenes/protoboardSuperior.jpg" width="500" height="400">

> Arduino

<img src="https://github.com/JorgeJasso/Sistema-de-seguridad-con-proteccion-electronica/blob/master/Imagenes/arduinoFrente.jpg" width="500" height="400">

<img src="https://github.com/JorgeJasso/Sistema-de-seguridad-con-proteccion-electronica/blob/master/Imagenes/arduinoEspalda.jpg" width="500" height="400">

<img src="https://github.com/JorgeJasso/Sistema-de-seguridad-con-proteccion-electronica/blob/master/Imagenes/arduinoSuperior.jpg" width="500" height="400">

## Codificación
 
<img src="https://github.com/JorgeJasso/Sistema-de-seguridad-con-proteccion-electronica/blob/master/Imagenes/diagramaDeFlujo.jpg">


## Instalación
 
1.- Monta circuito mencionado en este documento. 

2.- Descarga Arduino IDE del siguiente link https://www.arduino.cc/en/Main/Software

3.- Elige la arquitectura de tu computadora.

4.- Ejecuta el archivo descargado.

5.- Descarga la libreria <Keypad.h> y posterirormente pega toda la carpeta en las librerias de arduino.

6.- Descarga la libreria "LowPower.h" y posterirormente pega toda la carpeta en las librerias de arduino.

7.- Abre Arduino IDE y copia el código Alarma.ino

8.- Conecta tu Arduino y carga el programa.

9.- Verifica que el programa funcione correctamente.

