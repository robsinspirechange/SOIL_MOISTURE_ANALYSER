int sensor_temp = A0; //lm35
int value_temp;
int sensor_moisture = A1;//moisture
int value_moisture;
float c;


void setup() 
{
   Serial.begin(9600);  

  pinMode(10,OUTPUT);
  pinMode(4,OUTPUT);  
  pinMode(5,OUTPUT); 
  pinMode(3,OUTPUT);
  pinMode(13,OUTPUT);
  
  digitalWrite(4, LOW);
  digitalWrite(5,LOW);
  digitalWrite( 3,LOW);
  delay(10000);
  digitalWrite( 13,HIGH);
  digitalWrite( 10,HIGH);
}

void loop() {
  value_moisture = analogRead(sensor_moisture);
  c = analogRead(sensor_temp);
  value_temp = (5.0 * c * 100.0) / 1024;
    Serial.print(" ATMOSPHERIC TEMPERATURE in Celcius is ");
  Serial.println(value_temp);
  Serial.print("MOISTURE value of the SOIL according to sensor is ");
  Serial.println(value_moisture);  
  Serial.println("     ");
  
  
  String data="@"+String(value_temp)+"&"+String(value_moisture);
  
  Serial.print(data);
  
  if(value_temp>=35)
{
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);

}
  
  else if(value_temp > 25 && value_temp<35)//High Temperature Turn on the Motor
  {
    digitalWrite(5, HIGH);
    digitalWrite(4,LOW);
  } 
  
  else if (value_moisture >=1000 && value_temp<=25)//Sensor is Outside Motor is Off
  {
    digitalWrite(5, LOW);
     digitalWrite(4,LOW);
  }

 else if (value_moisture <1000 && value_moisture >600 && value_temp<25)//Dry Soil Turn on the Motor  
  {    
     digitalWrite(5, HIGH);
     digitalWrite(4,LOW); 
  }
  
  else if(value_moisture <=600 && value_moisture>400 && value_temp<25) //Humid Soil Turn off the motor
  {
     digitalWrite(5, LOW);
     digitalWrite(4,LOW);
  }
  
  else if (value_moisture < 400 && value_temp<25)//Sensor is in the water Turn off the Motor
  {
    digitalWrite(5, LOW);
     digitalWrite(4,LOW);
  }
  delay(5000); 
}











