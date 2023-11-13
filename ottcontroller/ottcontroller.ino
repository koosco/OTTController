#include <SoftwareSerial.h>
#include <HID-Project.h>

// var for volume controller
int volumNum = A0;
int vol_tmp = 0;
int volumeChangeDiff = 5;

void setup() {
  Serial.begin(9600);
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
}

