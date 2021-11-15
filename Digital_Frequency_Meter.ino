#include <LiquidCrystal.h>

LiquidCrystal lcd(3,4,5,6,7,8);
#define pulse_ip 9
float frequency,period;
int ontime,offtime,duty;

   
void setup()
{
  pinMode(pulse_ip,INPUT);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Frequency:");
  lcd.setCursor(0,1); 
  lcd.print("Duty:");  
}
void loop()
{
   ontime = pulseIn(pulse_ip,HIGH);
   offtime = pulseIn(pulse_ip,LOW);
   period = ontime+offtime;
   frequency = 1000000.0/period;
   duty = (ontime/period)*100; 
   if(period==0){ 
    frequency=0;
    
    }
   lcd.setCursor(5,0);
   lcd.print("           ");
   lcd.setCursor(5,0);
   if(frequency<1000){ 
   lcd.print(frequency);
   lcd.print("Hz");
   }else if(frequency>999|frequency<1000000){ 
   lcd.print(frequency/1000);
   lcd.print("KHz");
   }else if(frequency>999999|frequency<1000000000){ 
   lcd.print(frequency/1000000);
   lcd.print("MHz");
   }
   lcd.setCursor(6,1);
   lcd.print("           ");
   lcd.setCursor(6,1);
   lcd.print(duty); 
   lcd.print('%'); 
   delay(1000);
}
