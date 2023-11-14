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

// var for joystick
int joyStickX = A1;
int joyStickY = A2;
int joyStickPinNum = 4;
int mouseMoveLowerBound = 550;
int mouseMoveUpperBound = 450;

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


  // Mouse Control - mouse move

  int mouseXVal = analogRead(joyStickX);
  int mouseYVal = analogRead(joyStickY);
  int mouseZVal = digitalRead(joyStickPinNum);

  if(mouseMoveLowerBound < mouseXVal)
    Mouse.move(0, 1);
  else if(mouseXVal < mouseMoveUpperBound)
    Mouse.move(0, -1);
  
  if(mouseMoveLowerBound < mouseYVal)
    Mouse.move(-1, 0);
  else if(mouseYVal < mouseMoveUpperBound)
    Mouse.move(1, 0);

  // Mouse Control - click button
  if(mouseZVal == 0)
    Mouse.press(MOUSE_LEFT);
  if(mouseZVal == 1)
    Mouse.release(MOUSE_LEFT);
}

