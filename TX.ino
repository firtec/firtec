/**********************************************************************
** Descripción  : Envía el valor de un contador por un enlace ZigBee            
**                usando el controlador MRF24J40MA a 2.4 Ghz
**                
**  Target       : Arduino UNO
**  ToolChain    : Arduino IDE 1.8.9 bajo Linux Debian
**  www.firtec.com.ar 
**********************************************************************/
#include <SPI.h>
#include <mrf24j.h>

#define pin_reset 6
#define pin_cs 10   // Pin CS por defecto para ATmega 328
#define pin_irq  2  // IRQ para ATmega 328
byte contador = 0;

Mrf24j mrf(pin_reset, pin_cs, pin_irq);

long tiempo_anterior;
long temporizador = 2000;

void setup() {
  Serial.begin(9600); 
  mrf.reset();  // Inicia el reset del modulo ZegBee
  mrf.init();   // Configuración inicial del modulo
  mrf.set_pan(0x40F3);  // ID de la red ZigBee
  mrf.address16_write(0x4201); // Dirección de este nodo
  attachInterrupt(0, Rutina_ISR, CHANGE); // interrupt 0 equivale al pin 2(INT0) en ATmega 328
  tiempo_anterior = millis(); // Temporizador configurado
  interrupts();   // Interrupciónes activas
}

void Rutina_ISR() {
    mrf.interrupt_handler(); // Vector de iterrupción de la placa ZegBee
}

void loop() {
  char buffer[5]=" ";
    mrf.check_flags(&ISR_RX, &ISR_TX);
    unsigned long tiempo_actual = millis();
    if (tiempo_actual - tiempo_anterior > temporizador) {
        tiempo_anterior = tiempo_actual;
        dtostrf(contador,1,0,buffer);
        mrf.send16(0x4202, buffer);  // Envía buffer al nodo destino (0x4202)
        contador++;
        if(contador > 9)
            contador = 0;
    }
}

void ISR_RX() {
    // Vector no usado en el ejemplo
}

void ISR_TX() {
    if (mrf.get_txinfo()->tx_ok) {
        Serial.print(F("Enviando: "));
        Serial.println(contador);
        
    } else {
        Serial.print(F("Fallo en tranmisión "));
    }
}
