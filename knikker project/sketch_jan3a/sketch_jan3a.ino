#include <Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>




#define NOTE_E6 1319
#define NOTE_A5 880
#define NOTE_C6 1047
#define NOTE_C5 523
#define NOTE_E5 659
#define NOTE_G5 784
#define NOTE_REST 0
#define NOTE_G4 392
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0

// Change this to the pin connected to the buzzer
int buzzer = 11;
int buttonPin = 2;
int servoCounter = 0;  // Variable to keep track of the current servo
LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo myservo1;    // Servo on pin 8
Servo myservo2;    // Servo on pin 10
Servo myservo3;    // Servo on pin 9
Servo myservo4;    // Servo on pin 12

//Eens knop [2] r                                                                                                                                                                     
const int buttonPin1 = 2;
//Oneens knop [3]
const int buttonPin2 = 3;
//Reset knop [4]
const int buttonPin3 = 4;
//Start knop [5]
const int buttonPin4 = 5;

int buttonState1 = 0;
int buttonState2 = 0;  
int buttonState3 = 0;
int buttonState4 = 0;

void setup() {
  Serial.begin(9600);

  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);

  lcd.begin();
  lcd.backlight();

  myservo1.attach(8);
  myservo2.attach(10);
  myservo3.attach(9);
  myservo4.attach(12);

  myservo1.write(90);
  myservo2.write(90);
  myservo3.write(90);
  myservo4.write(90);

  pinMode(buttonPin1, INPUT); 
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
}

void loop() {
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);

  // Check of er gegevens beschikbaar zijn op de seriële poort
  if (buttonState1 == HIGH) {
    Serial.println("oneens");
    lcd.clear();
    lcd.print("oneens");

    if (servoCounter == 0) {
      myservo1.write(30);
    } else if (servoCounter == 1) {
      myservo2.write(30);
    } else if (servoCounter == 2) {
      myservo3.write(30);
    }

    delay(500);

    if (servoCounter == 0) {
      myservo1.write(90);
    } else if (servoCounter == 1) {
      myservo2.write(90);
    } else if (servoCounter == 2) {
      myservo3.write(90);
    }

    playFunnySound2();
    lcd.clear();
    servoCounter = (servoCounter + 1) % 3;  // Increment and wrap around to 0
  } else if (buttonState2 == HIGH) {
    Serial.println("eens");
    lcd.clear();
    lcd.print("eens");

    if (servoCounter == 0) {
      myservo1.write(150);
    } else if (servoCounter == 1) {
      myservo2.write(150);
    } else if (servoCounter == 2) {
      myservo3.write(150);
    }

    delay(500);

    if (servoCounter == 0) {
      myservo1.write(90);
    } else if (servoCounter == 1) {
      myservo2.write(90);
    } else if (servoCounter == 2) {
      myservo3.write(90);
    }

    playFunnySound();
    lcd.clear();
    servoCounter = (servoCounter + 1) % 3;  // Increment and wrap around to 0

  } else if (buttonState3 == HIGH) {
    Serial.println("r");
    lcd.clear();
    lcd.print("Resetting");
    playWindowsShutdownSound();
    lcd.clear();
    servoCounter = 0;

  } else if (buttonState4 == HIGH) {
("x");
    lcd.clear();
    lcd.print("Starting");
    myservo4.write(30);
    lcd.setCursor(3, 1);
    lcd.print("Knikkerbaan");
    playTurnOnSound();
    myservo4.write(90);
    lcd.clear();

  } else {
    // ...
  }
}

String LeesStringDeel(int deelIndex, String ontvangenString) {
  // Split de string op basis van komma's
  int vanIndex = 0;
  for (int i = 0; i < deelIndex; ++i) {
    vanIndex = ontvangenString.indexOf(',', vanIndex) + 1;
    if (vanIndex == 0) {
      // Kon de volgende komma niet vinden, retourneer een lege string
      return "";
    }
  }
  int totIndex = ontvangenString.indexOf(',', vanIndex);
  if (totIndex == -1) {
    // Dit is het laatste deel, haal de substring op van vanIndex tot het einde
    totIndex = ontvangenString.length();
  }
  return ontvangenString.substring(vanIndex, totIndex);
}



//Niet belangerijk !!! alleen de muziek noten van de geluids indicatie
void playFunnySound() {
  int melody1[] = {
    NOTE_C5, 8, NOTE_E5, 8, NOTE_G5, 8,
    NOTE_REST, 8,
    NOTE_G5, 8, NOTE_E5, 8, NOTE_C5, 8,
    NOTE_REST, 8
  };

  int notes1 = sizeof(melody1) / sizeof(melody1[0]) / 2;
  int wholenote = 500;

  for (int thisNote = 0; thisNote < notes1 * 2; thisNote = thisNote + 2) {
    int noteDuration = wholenote / melody1[thisNote + 1];

    tone(buzzer, melody1[thisNote], noteDuration * 0.9);
    delay(noteDuration);

    noTone(buzzer);
    delay(50);
  }
}

void playFunnySound2() {
  int melody2[] = {
    NOTE_E5, 8, NOTE_C5, 8, NOTE_G4, 8,
    NOTE_REST, 8,
    NOTE_G4, 8, NOTE_C5, 8, NOTE_E5, 8,
    NOTE_REST, 8
  };

  int notes2 = sizeof(melody2) / sizeof(melody2[0]) / 2;
  int wholenote = 500;

  for (int thisNote = 0; thisNote < notes2 * 2; thisNote = thisNote + 2) {
    int noteDuration = wholenote / melody2[thisNote + 1];

    tone(buzzer, melody2[thisNote], noteDuration * 0.9);
    delay(noteDuration);

    noTone(buzzer);
    delay(50);
  }
}

void reset() {
  int melody3[] = {
  NOTE_E5, 8, NOTE_D5, 8, NOTE_FS4, 4, NOTE_GS4, 4, 
  NOTE_CS5, 8, NOTE_B4, 8, NOTE_D4, 4, NOTE_E4, 4, 
  NOTE_B4, 8, NOTE_A4, 8, NOTE_CS4, 4, NOTE_E4, 4,
  NOTE_A4, 2, 
};

  int notes2 = sizeof(melody3) / sizeof(melody3[0]) / 2;
  int wholenote = 500;

  for (int thisNote = 0; thisNote < notes2 * 2; thisNote = thisNote + 2) {
    int noteDuration = wholenote / melody3[thisNote + 1];

    tone(buzzer, melody3[thisNote], noteDuration * 0.9);
    delay(noteDuration);

    noTone(buzzer);
    delay(50);
  }
}

void playWindowsShutdownSound() {
  int melody[] = {
    NOTE_A5, 8, NOTE_G5, 8, NOTE_E5, 8, NOTE_C5, 8,  // Play A5, G5, E5, C5 sequentially
    NOTE_REST, 8,  // Pause
    NOTE_C6, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_E5, 8,  // Play C6, A5, G5, E5 sequentially
    NOTE_REST, 8  // Pause
  };

  int notes = sizeof(melody) / sizeof(melody[0]) / 2;
  int wholenote = 500;  // Adjust the duration as needed

  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
    int noteDuration = wholenote / melody[thisNote + 1];

    tone(buzzer, melody[thisNote], noteDuration * 0.9);
    delay(noteDuration);

    noTone(buzzer);
    delay(50);  // Small delay between notes
  }
}


void playTurnOnSound() {
  int melody[] = {
    NOTE_E5, 8, NOTE_G5, 8, NOTE_C6, 8, NOTE_E6, 8,  // Play E5, G5, C6, E6 sequentially
    NOTE_REST, 8,  // Pause
    NOTE_E6, 8, NOTE_C6, 8, NOTE_G5, 8, NOTE_E5, 8,  // Play E6, C6, G5, E5 sequentially
    NOTE_REST, 8  // Pause
  };

  int notes = sizeof(melody) / sizeof(melody[0]) / 2;
  int wholenote = 500;  // Adjust the duration as needed

  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
    int noteDuration = wholenote / melody[thisNote + 1];

    tone(buzzer, melody[thisNote], noteDuration * 0.9);
    delay(noteDuration);

    noTone(buzzer);
    delay(50);  // Small delay between notes
  }
}
