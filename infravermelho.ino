#include <IRremote.h>
int RECV_PIN = 12;                          // Defina a porta que vai receber
IRrecv irrecv(RECV_PIN);                    // criando a instância
decode_results results;

bool Port1 = true;
bool Port2 = true;

void setup() {
  Serial.begin(9600);                       // Monitor velocidade 9600 bps
  irrecv.enableIRIn();
  //Definindo portas digitais
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    //Definindo variável que irá receber o código do infra vermelho

    uint32_t code = results.value;

    //Imprimindo o código
    Serial.println(code);


    if (code == 16753245) {
      Port1 = !Port1;

    }
    if (code == 16736925) {
      Port2 = !Port2;
    }

    if (Port1 == true) {
      digitalWrite(7, LOW);
    } else {
      digitalWrite(7, HIGH);
    }

    if (Port2 == true) {
      digitalWrite(6, LOW);
    } else {
      digitalWrite(6, HIGH);
    }

    irrecv.resume(); // Resetando o sensor
  }
}
