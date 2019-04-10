// Benennung der Pins für einfachere Lesbarkeit und bessere Wartbarkeit des Codes. 
#define trigger 18
#define echo 19
#define LED_R 5
#define LED_G 6
#define LED_B 3

// Deklaration und Initialisierung der Arbeitsvariablen
float time = 0, distance = 0;

// setup() wird einmal beim Start des Programms ausgeführt um alles "vorzubereiten", Input/Output wird deklariert
void setup() 
{
 pinMode(trigger,OUTPUT);
 pinMode(echo,INPUT);
 pinMode(LED_R,OUTPUT);
 pinMode(LED_G,OUTPUT);
 pinMode(LED_B,OUTPUT);
}

// loop() wird für immer wiederholt
void loop() {
 digitalWrite(trigger,LOW);  // Trigger wird ausgeschaltet
 delayMicroseconds(2);       // Delay aus Datenblatt
 
 digitalWrite(trigger,HIGH); // Trigger wird eingeschaltet
 delayMicroseconds(10);      // Delay aus Datenblatt
 
 digitalWrite(trigger,LOW);  // Trigger wird ausgeschaltet
 delayMicroseconds(2);       // Delay aus Datenblatt
 
 time=pulseIn(echo,HIGH);    
 distance=time*340/20000;    // Berechnung der Distanz auf Basis der Zeit zwischen Senden und Empfangen des Ultraschall-Signals, Berechnung mit konstanten aus Datenblatt
 
//Steuerung der RGB-LED auf Basis der errechneten Distanz
 if (distance <= 5) {        // Distanz <= 5 cm
   analogWrite(LED_R, 0);
   analogWrite(LED_G, 255);  // LED Grün
   analogWrite(LED_B, 0);
 } 
 else if(distance <= 10) {   // Distanz 5-10 cm
   analogWrite(LED_R, 255);  
   analogWrite(LED_G, 63);   // LED Gelb
   analogWrite(LED_B, 0);
 }
 else {                      // Distanz > 10 cm
   analogWrite(LED_R, 255);
   analogWrite(LED_G, 0);    // LED Rot
   analogWrite(LED_B, 0);
 }
}
