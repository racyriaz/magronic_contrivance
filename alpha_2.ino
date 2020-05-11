int svalue = 0,tvalue = 0,i,j;

void setup()
{
 pinMode(7,OUTPUT); //motor
 pinMode(8,OUTPUT); //heater
}



void loop()
{ 
  //*closing of valve* dpdt relay add program*//
  //delay("based upon dpdt valve");
  digitalWrite(8,LOW);          //mixing stage
  digitalWrite(7,HIGH);
  delay(300000);  //5 mins
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);            //sedimentation state
  delay(10000);                   //10 seconds
  digitalWrite(7,HIGH);           // motor is on 
  for(i=1200;i>0;i--)           //based on minutes    (20hours)
    {
      for(j=60;j>0;j--)         //based on seconds     (1 minute)
        {
          delay(560);
          temp();
        }
    }
                for(i=14; i>0 ;i--)             //(5 hours)
                 {
                    digitalWrite(7,HIGH);
                    delay(120000);              //(2 mins)
                    digitalWrite(7,LOW);
                    delay(1200000);             //20 mins     20+2=22 mins   5hrs=300mins  300/22= 14 = 5hrs
                  }
       for(i=600; i>0; i--)           //10 mins   10 x 60
       {
        temp();
        digitalWrite(7,HIGH);
        delay(580);
       }
  
  //*ADD THE DPDT RELAY LINE PROGRAM*//
  //delay("based upon dpdt valve");
  digitalWrite(7,HIGH);
  //delay("based upon dpdt valve");

       for(;;)
       { }
}

void temp()
{  
  svalue = analogRead(A2);
  delay(400);
  tvalue = ((5.0 * svalue * 100)/1024);
  if(tvalue < 40)
  {
    digitalWrite(8,HIGH);
  }
  else
      digitalWrite(8,LOW); 
}

