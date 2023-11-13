#include <SoftwareSerial.h>
#include <HID-Project.h>

// var for volume controller
int volumNum = A0;
int vol_tmp = 0;
int volumeChangeDiff = 5;
int keyboardMute = 9;

void setup() {
  Serial.begin(9600);

  // keyboard 초기화
  pinMode(keyboardMute, INPUT_PULLUP);
}

void loop() {
  // Volume Control

  int volumeVal = analogRead(volumNum);
  if(volumeVal < vol_tmp - volumeChangeDiff) {
    // volume down
    Consumer.write(MEDIA_VOLUME_UP);
    vol_tmp = volumeVal;
  }
  else if(volumeVal > vol_tmp + 5) {
    // volume up
    Consumer.write(MEDIA_VOLUME_DOWN);
    vol_tmp = volumeVal;
  }

  // Mute button -> This will be integrated to Volume Controller
  
  if(digitalRead(keyBoardMute) == LOW)
    Keyboard.press('m');
  else
    Keyboard.release('m');
}

