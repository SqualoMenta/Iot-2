#define TRIG_PIN 9
#define ECHO_PIN 10

void setup()
{
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    Serial.begin(9600); // Per stampare i dati sulla console seriale
}

void loop()
{
    long duration;
    float distance;

    // Invio dell'impulso ultrasonico
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // Lettura del segnale di ritorno
    duration = pulseIn(ECHO_PIN, HIGH);

    // Calcolo della distanza
    distance = (duration * 0.034) / 2; // 0.034 cm/µs è la velocità del suono

    // Stampa della distanza calcolata
    Serial.print("Distanza: ");
    Serial.print(distance);
    Serial.println(" cm");

    delay(500); // Pausa per evitare letture troppo ravvicinate
}