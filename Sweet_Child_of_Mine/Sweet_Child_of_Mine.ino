// Written for Freetronics LeoStick
// by Craige McWhirter

int speakerPin = 11;

char notes[] = "DdAGgAFDdAGgAFAEdAgAFAEdAGgAFAFAEdAGgAFA DdAGgAFDdAGgAFAEdAgAFAEdAGgAFAFAEdAGgAFA";

//              d d a g g a F d d a g g a f a e d a g a f a e d a g g a f a f a e d a g g a f a
int beats[] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int tempo = 255;

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = {'d','g','D', 'E', 'F', 'G', 'A'};
  int tones[] = {1175, 1568, 587, 659, 698, 784, 880};

// play the tone corresponding to the note name
  for (int i = 0; i < sizeof(tones); i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

void setup() {
  pinMode(speakerPin, OUTPUT);
}
void loop() {
  for (int i = 0; i < sizeof(notes); i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * tempo); // rest
    } else {
      playNote(notes[i], beats[i] * tempo);
    }
    // pause between notes
    delay(tempo / 255);
    if (i == sizeof(notes)-1){
      delay(100000);
    }
  }
}
