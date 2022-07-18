#include <LiquidCrystal.h> 
LiquidCrystal lcd(7, 6, 5, 4, 3, 2); 
int hrs = 12; 
int mins = 0; 
int sec = 0; 
int TIME = 0; 
const int bhrs = A4; 
const int bmins = A5; 
int state1 = 0;
int state2 = 0; 
void setup()
{
  lcd.begin(16, 2);  
  pinMode(bhrs, INPUT_PULLUP);
  pinMode(bmins, INPUT_PULLUP);
}
void loop()
{
  lcd.setCursor(0, 0);
  sec = sec + 1;
  lcd.print("TIME:" );
  lcd.print(hrs);
  lcd.print(":");
  lcd.print(mins);
  lcd.print(":");
  lcd.print(sec);

  if (TIME ==12) {
    lcd.print(" PM");
  }
  if (TIME == 24) TIME = 0;
  delay(800);
  lcd.clear();
  if (sec == 60) 
  {
    sec = 0;
    mins = mins + 1;
  }
  if (mins == 60)
  {
    mins = 0;
    hrs = hrs + 1;
    TIME = TIME + 1;
  }
  if (hrs == 13)
  {
    hrs = 1;
  }
lcd.setCursor(0, 1);
   lcd.print("Simple Clock ");
  state1 = digitalRead(bhrs);
  if (state1 == 0)
  {
    hrs = hrs + 1;
    TIME = TIME + 1;
    if (TIME==12){
      lcd.print(" PM");
    }
    if (TIME == 24) TIME = 0;
    if (hrs == 13)
     hrs = 1;
  }
  state2 = digitalRead(bmins);
  if (state2 == 0)
  {
    sec = 0;
    mins = mins + 1;
  }
}
