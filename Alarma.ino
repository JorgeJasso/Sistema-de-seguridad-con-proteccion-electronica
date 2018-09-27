#include <Keypad.h> //Se incluye la libreria Keypad para poder uilizar el teclado matricial.
#include "LowPower.h" // Se incluye la libreria que permite manipular el consumo de energia.

const byte LEDROJO = 2; //Almacena el valor "2" para utilizarlo en el pin que esta conectado al led rojo dentro de la casa.
const byte LEDAZUL = 4; //Almacena el valor "4" para utilizarlo en el pin que esta conectado al led azul dentro de la casa.
const byte REDSWITCH = 3; //Se guarda el valor del pin que tendra el red switch.
const byte BOCINA = 5; //Indica el valor del pin que tendra la bocina.
const byte NUMFILAS = 4; //Determina el numero de filas con las que trabajara nuestro teclado matrial.
const byte NUMCOLUMNAS = 4; //Determina el numero de columnas con las que trabajara nuestro teclado matrial.
const String CLAVE =  "271115"; //Guarda la clave que se utilizara para verificar el ingreso a la propiedad.

boolean estadoAlarma = HIGH; //Determina si la alarma esta encendida (sonara la bocina en caso de que se abra la puerta) o apagada (se podra abrir la puerta y no sonara la bocina).
boolean despierto = HIGH; //Se utiliza para conocer si el arduino esta en modo de consumo o no.
byte pinsFilas[NUMFILAS] = {13,12,11,10}; //Se declara un arreglo que determinara los pines que utiliza el teclado matricial para las filas.
byte pinsColumnas[NUMCOLUMNAS] = {9,8,7,6}; //Se declara un arreglo que determinara los pines que utiliza el teclado matricial para las columnas.
char tecla; //Almacena el valor de la tecla presionada
char tecladoMatricial[NUMFILAS][NUMCOLUMNAS]=
{
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'},
}; //Arreglo que especifica los caracteres del teclado matrial.
String claveIngresada; //Variable utilizada para ir almacenando los caracteres que ingrese el usuario.

Keypad teclado = Keypad(makeKeymap(tecladoMatricial),pinsFilas,pinsColumnas,NUMFILAS,NUMCOLUMNAS); //Declara una instancia de Keypad indicando los parametros (tecladoMatricial, pinsFilas, pinsColumnas, NUMFILAS, NUMCOLUMNAS).

void setup() {
  pinMode(LEDROJO,OUTPUT); //Asigna el pin 2 al led rojo dentro de la casa.
  pinMode(LEDAZUL,OUTPUT); //Asigna el pin 3 al led azul dentro de la casa.
  pinMode(REDSWITCH,INPUT); //Asigna el pin 4 al red switch pero con un valor INPUT.
  pinMode(BOCINA,OUTPUT); //Asigna el pin 5 a la bocina.
  attachInterrupt(digitalPinToInterrupt(REDSWITCH), despertar, LOW); //Asignamos la interrupcion a la entrada del red switch.
  Serial.begin(9600); 
}

void loop() {
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);  // Pone al Arduino en modo de bajo consumo, dormido hasta que se ejecute una interrupcion
  if(despierto==LOW){ //Verifica si el consumo esta en bajo no hace nada y si es alto hace las siguientes lineas de codigo.
    eventosDeTeclado(); //Verifica si se ha ingresado un caracter, y de ser asi verifica si el caracter es * para compararlo con CLAVE.
    if(digitalRead(REDSWITCH)==HIGH){ //Comprueba si el iman se ha alejado del red switch.
      estadosDeLaAlarma(); //Verifica y ejecuta las acciones dependiendo del estado que tenga la alarma.
    }else{
      noTone(BOCINA); //Si el iman esta cerca del red switch entonces debe dejar de sonar la alarma.
    }
  }
}

void despertar(){  // Este metodo hace que le arduino despierte del modo de bajo consumo
  despierto = LOW; // Indica que ahora debe despertar para sonar la alarma.
}    

void eventosDeTeclado(){ //Verifica si se ha ingresado un caracter, y de ser asi verifica si el caracter es * para compararlo con CLAVE.
  tecla=teclado.getKey(); //Obtiene el caracter del teclado.
  if(tecla!=NO_KEY){ //Si se presiono una tecla del teclado matricial entra en esta parte de codigo.
    if(tecla=='*'){ //El asterisco sirve para ingresar todos los caracteres presionados antes de él.
      if(claveIngresada==CLAVE){ //Entra cuando claveIngresada es igual a CLAVE (271115). 
        Serial.println("Bienvenido");
        estadoAlarma=LOW; //Desactiva la alarma para poder ingresar a la casa.
      }else{
        Serial.println("Clave incorrecta");
      }
      claveIngresada=""; //Limpia cualquier valor que haya estado contenido en CLAVEINGRESADA.
    }else{
      claveIngresada=claveIngresada+tecla; //Si aun no se ha precionado asterisco ingresa el caracter a claveIngresada.
    } 
  }
}

void estadosDeLaAlarma(){ //Verifica y ejecuta las acciones dependiendo del estado que tenga la alarma.
  if(estadoAlarma==HIGH){ //Si se alejo y la alarma estaba activada entonces tiene que sonar encendiendo los led rojo y azul.
    do{ //Ejecuta el ciclo al menos una vez hasta que el iman se vuelva a colocar cerca del reed switch.
      tone(BOCINA,55,00); //Le agrega una frecuencia de 55
      digitalWrite (LEDROJO, HIGH);//Enciende el LED rojo
      delay(500);
      digitalWrite (LEDROJO, LOW);//Apaga el LED rojo
      noTone(BOCINA);
      tone(BOCINA,73,42); //Le agrega una frecuencia de 73
      digitalWrite (LEDAZUL, HIGH);//Enciende el LED azul
      delay(500);
      digitalWrite (LEDAZUL, LOW);//Paga el LED azul
      noTone(BOCINA);
    }while(digitalRead(REDSWITCH)==HIGH);
  }else{
    delay(5000);
    if(digitalRead(REDSWITCH)==LOW){ //Vuelve a comprobar, si el iman ya esta cerca del red switch.
      estadoAlarma=HIGH; //Si fue asi entonces la alarma se vuelve a activar.
    }
  }
}
