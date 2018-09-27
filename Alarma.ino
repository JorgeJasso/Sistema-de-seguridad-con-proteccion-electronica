/*
 Se sabe que la inseguridad constituye uno de los grandes problemas de México ya que según datos de las procuradurías de Justicia
 de los estados, 2017 cerró con un total de 99,659 denuncias de robo a casa habitación sin violencia y 13,782 despojos con uso de
 violencia en todo el país, hecho que hace darnos cuenta de la gran utilidad que tienen las alarmas en nuestra vida diaria.
 Para poder aportar seguridad a nuestras viviendas el presente trabajo muestra la realización de una alarma utilizando Arduino,
 que permite o deniega (enciende la alarma al igual que los LED dentro de la casa) el acceso a la vivienda dependiendo de si la clave
 ingresada por el usuario es correcta o no.
 
 Desarrollado por: Jasso Torres Jorge Alberto
 Contacto: Jassojorgealberto@gmail.com
*/

#include "LowPower.h" // Se incluye la libreria que permite manipular el consumo de energia.

const byte LEDROJO = 2; //Almacena el valor "2" para utilizarlo en el pin que esta conectado al led rojo dentro de la casa.
const byte LEDAZUL = 4; //Almacena el valor "4" para utilizarlo en el pin que esta conectado al led azul dentro de la casa.
const byte REDSWITCH = 3; //Se guarda el valor del pin que tendra el red switch.
const byte BOCINA = 5; //Indica el valor del pin que tendra la bocina.

boolean estadoAlarma = HIGH; //Determina si la alarma esta encendida (sonara la bocina en caso de que se abra la puerta) o apagada (se podra abrir la puerta y no sonara la bocina).
boolean despierto = HIGH; //Se utiliza para conocer si el arduino esta en modo de consumo o no.

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
