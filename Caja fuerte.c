#include <Servo.h> // Incluye la biblioteca Servo.h para poder controlar el servo motor.

int servoPin = 9; // Define el pin al que está conectado el servo
Servo servo_9; // Crea un objeto de tipo Servo llamado servo_9

int signalPin = 7; // Define el pin al que está conectado el sensor que dara la señal

void setup() {
  Serial.begin(9600); // Inicia la comunicación serial con la PC
  servo_9.attach(servoPin); // Adjunta el servo al pin definido
  pinMode(signalPin, INPUT); // Configura el pin de señal como entrada
}

void loop() {
  int signalValue = digitalRead(signalPin); // Lee el valor del pin de señal (0 o 1).

  if (signalValue == 1) { // Si la señal es alta (1)
    moveServo(0, 3000); // Mueve el servo a la posición 0 grados en 3 segundos.
  } else if (signalValue == 0) { // Si la señal es baja (0)...
    moveServo(100, 3000); // Mueve el servo a la posición 100 grados en 3 segundos.
  }
}

void moveServo(int angle, int duration) {
  int initialAngle = servo_9.read(); // Lee el ángulo inicial del servo.
  int steps = abs(angle - initialAngle); // Calcula la cantidad de pasos necesarios para alcanzar el nuevo ángulo.
  int stepDuration = duration / steps; // Calcula la duración de cada paso.

  for (int i = initialAngle; i != angle; i += (angle > initialAngle) ? 1 : -1) { // Itera sobre cada paso necesario para alcanzar el nuevo ángulo.
    servo_9.write(i); // Envía la señal al servo para moverlo al siguiente ángulo.
    delay(stepDuration); // Espera la duración de un paso.
  }
}
