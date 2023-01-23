#include <CapacitiveSensor.h>
#include "pitches.h"

#define COMMON_PIN      2    // The common 'send' pin for all keys
#define BUZZER_PIN      A5   // The output pin for the piezo buzzer
#define NUM_OF_SAMPLES  10   // Higher number means more delay but more consistent readings
#define CAP_THRESHOLDC   100  // Capactive reading that triggers a note (adjust to fit your needs)
#define Led0              11
#define Led1              12
#define Led2              A0
#define Led3              A1
#define Led4              A2
#define Led5              A3
#define Led6              A4

// This macro creates a capacitance "key" sensor object for each key on the piano keyboard:
#define CS(Y) CapacitiveSensor(2, Y)

// Each key corresponds to a note, which are defined here. Uncomment the scale that you want to use:
int notesC[]={NOTE_C4,NOTE_D4,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_B4}; // C-Major scale
//int notesA[]={NOTE_A4,NOTE_B4,NOTE_C5,NOTE_D5,NOTE_E5,NOTE_F5,NOTE_G5}; // A-Minor scale
//int notes[]={NOTE_C4,NOTE_DS4,NOTE_F4,NOTE_FS4,NOTE_G4,NOTE_AS4,NOTE_C5}; // C Blues scale

// Defines the pins that the keys are connected to:
CapacitiveSensor keys[] = {CS(3), CS(4), CS(5), CS(6), CS(7), CS(8), CS(9)};

void setup() { 
  // Turn off autocalibrate on all channels:
  for(int i=0; i<7; ++i) {
    keys[i].set_CS_AutocaL_Millis(0xFFFFFFFF);
  }
  // Set the buzzer and leds as output:
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(Led0, OUTPUT); 
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT); 
  pinMode(Led3, OUTPUT);
  pinMode(Led4, OUTPUT); 
  pinMode(Led5, OUTPUT);
  pinMode(Led6, OUTPUT); 
  Serial.begin(9600);
}

void loop() {    
  if(keys[0].capacitiveSensor(NUM_OF_SAMPLES) > CAP_THRESHOLDC) {
    Serial.println(keys[0].capacitiveSensor(NUM_OF_SAMPLES));
    tone(BUZZER_PIN, notesC[0]);
    digitalWrite(Led0,HIGH);
    digitalWrite(Led1,LOW);
    digitalWrite(Led2,LOW);
    digitalWrite(Led3,LOW);
    digitalWrite(Led4,LOW);
    digitalWrite(Led5,LOW);
    digitalWrite(Led6,LOW);
  }
  if(keys[1].capacitiveSensor(NUM_OF_SAMPLES) > CAP_THRESHOLDC) {
    tone(BUZZER_PIN, notesC[1]);
    digitalWrite(Led0,LOW);
    digitalWrite(Led1,HIGH);
    digitalWrite(Led2,LOW);
    digitalWrite(Led3,LOW);
    digitalWrite(Led4,LOW);
    digitalWrite(Led5,LOW);
    digitalWrite(Led6,LOW);
  }
  if(keys[2].capacitiveSensor(NUM_OF_SAMPLES) > CAP_THRESHOLDC) {
    tone(BUZZER_PIN, notesC[2]);
    digitalWrite(Led0,LOW);
    digitalWrite(Led1,LOW);
    digitalWrite(Led2,HIGH);
    digitalWrite(Led3,LOW);
    digitalWrite(Led4,LOW);
    digitalWrite(Led5,LOW);
    digitalWrite(Led6,LOW);
  }
  if(keys[3].capacitiveSensor(NUM_OF_SAMPLES) > CAP_THRESHOLDC) {
    tone(BUZZER_PIN, notesC[3]);
    digitalWrite(Led0,LOW);
    digitalWrite(Led1,LOW);
    digitalWrite(Led2,LOW);
    digitalWrite(Led3,HIGH);
    digitalWrite(Led4,LOW);
    digitalWrite(Led5,LOW);
    digitalWrite(Led6,LOW);
  }
  if(keys[4].capacitiveSensor(NUM_OF_SAMPLES) > CAP_THRESHOLDC) {
    tone(BUZZER_PIN, notesC[4]);
    digitalWrite(Led0,LOW);
    digitalWrite(Led1,LOW);
    digitalWrite(Led2,LOW);
    digitalWrite(Led3,LOW);
    digitalWrite(Led4,HIGH);
    digitalWrite(Led5,LOW);
    digitalWrite(Led6,LOW);
  }
  if(keys[5].capacitiveSensor(NUM_OF_SAMPLES) > CAP_THRESHOLDC) {
    tone(BUZZER_PIN, notesC[5]);
    digitalWrite(Led0,LOW);
    digitalWrite(Led1,LOW);
    digitalWrite(Led2,LOW);
    digitalWrite(Led3,LOW);
    digitalWrite(Led4,LOW);
    digitalWrite(Led5,HIGH);
    digitalWrite(Led6,LOW);
  }
  if(keys[6].capacitiveSensor(NUM_OF_SAMPLES) > CAP_THRESHOLDC) {
    tone(BUZZER_PIN, notesC[6]);
    digitalWrite(Led0,LOW);
    digitalWrite(Led1,LOW);
    digitalWrite(Led2,LOW);
    digitalWrite(Led3,LOW);
    digitalWrite(Led4,LOW);
    digitalWrite(Led5,LOW);
    digitalWrite(Led6,HIGH);
  }
  if(keys[0].capacitiveSensor(NUM_OF_SAMPLES) < CAP_THRESHOLDC && 
  keys[1].capacitiveSensor(NUM_OF_SAMPLES) < CAP_THRESHOLDC && 
  keys[2].capacitiveSensor(NUM_OF_SAMPLES) < CAP_THRESHOLDC && 
  keys[3].capacitiveSensor(NUM_OF_SAMPLES) < CAP_THRESHOLDC && 
  keys[4].capacitiveSensor(NUM_OF_SAMPLES) < CAP_THRESHOLDC &&
  keys[5].capacitiveSensor(NUM_OF_SAMPLES) < CAP_THRESHOLDC && 
  keys[6].capacitiveSensor(NUM_OF_SAMPLES) < CAP_THRESHOLDC){
    Serial.println(keys[0].capacitiveSensor(NUM_OF_SAMPLES));
    noTone(BUZZER_PIN);
    digitalWrite(Led0,LOW);
    digitalWrite(Led1,LOW);
    digitalWrite(Led2,LOW);
    digitalWrite(Led3,LOW);
    digitalWrite(Led4,LOW);
    digitalWrite(Led5,LOW);
    digitalWrite(Led6,LOW);
  }
}
