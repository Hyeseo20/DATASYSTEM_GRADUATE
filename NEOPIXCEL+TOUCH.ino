#include <Adafruit_NeoPixel.h>
#include <SoftwareSerial.h>

#define PIN            6    //연결핀 번호
#define NUMPIXELS      8    //네오픽셀 갯수
//네오픽셀 라이브러리를 설정할때 신호를 보내는데 사용할 픽셀수와 핀수를 알려줍니다.

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);  
int delayval = 20;    //일정 시간(20mS) 동안 지연 됩니다.
SoftwareSerial bluetooth(2,3);  //블루투스 통신 속도

int R = 11;                // Connect LED on pin 13, or use the onboard one
int KEY = 4;                 // Connect Touch sensor on Digital Pin 2


void setup() {
  pinMode(R, OUTPUT);      // Set ledPin to output mode
  pinMode(KEY, INPUT);       //Set touch sensor pin to input mode

  pixels.begin();  //네오픽셀 라이브러리가 초기화 됩니다. 
  bluetooth.begin(9600);    //블루투스 통신속도
 
}

byte r = 0, g = 0, b = 0;   // RGB 변수 선언
void loop() {

  if(digitalRead(KEY)==HIGH)       //Read Touch sensor signal
        {
          digitalWrite(R, HIGH);   // if Touch sensor is HIGH, then turn on
      }
    else
     {
         digitalWrite(R, LOW);    // if Touch sensor is LOW, then turn off the led
   }


  if(bluetooth.available()>2){    //수신받는 블루투스 테이터가 2개 초과일때  
    r = bluetooth.read();  //첫번째 데이터를 r에 저장    
    g = bluetooth.read();   //두번째 데이터를 g에 저장   
    b = bluetooth.read();     //세번째 데이터를 b에 저장   
    bluetooth.flush();    //통신내용 초기화(블루투스통신)
    
    for(int i=NUMPIXELS;i>=0;i--){
          pixels.setPixelColor(i, pixels.Color(0,0,0)); //지정된 색깔이 없음
          pixels.show(); //업데이트 된 픽셀 색상을 하드웨어로 보냅니다....
          delay(delayval); //일정 시간(20mS) 동안 지연됩니다.
        }
        delay(delayval);
    for(int i=0;i<NUMPIXELS;i++){
          pixels.setPixelColor(i, pixels.Color(r,g,b)); //지정된 색깔
          pixels.show(); 
          delay(delayval); 
        }

  }
          

}