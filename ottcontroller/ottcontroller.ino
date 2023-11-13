#include <SoftwareSerial.h>
#include <HID-Project.h>

// var for volume controller
int volumNum = A0;
int vol_tmp = 0;
int volumeChangeDiff = 5;
int keyboardMute = 9;

// var for video controller
int videoNum = A3;
int video_tmp = 0;
int videoChangeDiff = 20;
// int keyBoardStopResume = ; // stop/resume key

// var for LED
int led = 12;

void setup() {
  Serial.begin(9600);

  // keyboard 초기화
  pinMode(keyboardMute, INPUT_PULLUP);
  pinMode(keyBoardStopResume, INPUT_PULLUP);

  // LED
  pinMode(led, OUTPUT);

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

  // Video Control
  int videoVal = analogRead(videoNum);

  if(videoVal < video_tmp - videoChangeDiff) {
    // video forward
    Keyboard.press(KEY_LEFT_ARROW);
    Keyboard.release(KEY_LEFT_ARROW);
    video_tmp = videoVal;
  }else if(videoVal > video_tmp + videoChangeDiff) {
    // video backward
    Keyboard.press(KEY_RIGHT_ARROW);
    Keyboard.release(KEY_RIGHT_ARROW);
    video_tmp = videoVal;
  }

  // Video stop/resume button -> This will be integrated to Video Controller
  if(digitalRead(keyBoardMute) == LOW)
    Keyboard.press(' ');
  else
    Keyboard.release(' ');

  // LED
  digitalWrite(led, HIGH);
}

