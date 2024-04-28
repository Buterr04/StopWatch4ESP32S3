#include <SPI.h>
#include <TFT_eSPI.h>
#define TFT_BACKLIGHT_PIN 45
TFT_eSPI tft = TFT_eSPI();
const int startPin = 0;
const int stopPin = 1;    
int start = 0;
int stop=0;
int h=0;     
int m=0;     
int s=0;     
int ms=0;

void TFT_init(){
  //初始化TFT显示屏
  tft.init();
  tft.setRotation(3);
}

void stopwatch()
{
 
  tft.setCursor(80,100);  //定义数字的位置
  tft.setTextColor(TFT_WHITE,TFT_BLACK); tft.setTextSize(3);
  tft.print("TIME:");   //显示时间
  tft.print(h);         //显示时
  tft.print(":");      
  tft.print(m);        //显示分钟
  tft.print(":"); 
  tft.print(s);        //显示秒
  tft.setCursor(3,1);
 
  ms=ms+10;           
  delay(10); 
   
 if(ms==590)           
  {
   
   ms=0; 
   s=s+1; 
  }
  
  if(s==60)     //如果是分钟计数状态
  { 
  s=0; 
  m=m+1; 
  }

  if(m==60)     //如果状态为小时数
  {  
  m=00; 
  h=h+01;  
  } 
  stop = digitalRead(stopPin);  //读取buton状态
 if(stop == HIGH)    //检查是否按下了按钮
 {
  stopwatch_stop();   //调用stopwatch_stop函数
 }
  else
  {
   stopwatch();   //调用秒表功能
  }
}
void stopwatch_stop()
{
  tft.setCursor(80,100); 
  tft.print("TIME:"); 
  tft.print(h); 
  tft.print(":"); 
  tft.print(m); 
  tft.print(":"); 
  tft.print(s);
  tft.setCursor(3,1);
    
   start = digitalRead(startPin);   //读取button状态
 if(start == HIGH)
 {
  stopwatch();    //调用秒表功能
 } 
 } 

void setup() 
{
  pinMode( TFT_BACKLIGHT_PIN ,OUTPUT);
  digitalWrite( TFT_BACKLIGHT_PIN ,HIGH);
  TFT_init();
  tft.fillScreen(TFT_BLACK);
  pinMode(startPin , INPUT);
}

void loop() 
{
  tft.setCursor(80,70); 
  tft.setTextColor(TFT_WHITE,TFT_BLACK); tft.setTextSize(3);
  tft.print("STOPWATCH");  
  tft.setCursor(80,100);  
  tft.print("TIME:"); 
  tft.print(h); 
  tft.print(":"); 
  tft.print(m); 
  tft.print(":"); 
  tft.print(s);
  start = digitalRead(startPin);//读取button状态
 if(start == LOW) 
 {
  stopwatch();  //调用秒表功能
 }

    
  
}
