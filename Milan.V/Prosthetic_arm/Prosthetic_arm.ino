/*
macro definitions of PIR motion sensor pin
Use pin 2 to receive the signal from the module
*/
#define PIR_MOTION_SENSOR 2


void setup()
{
    pinMode(PIR_MOTION_SENSOR, INPUT);
    Serial.begin(9600);  

}

void loop()
{
    // If it detects moving people
    // To know more about why digital numbers are used as boolean, check https://www.techtarget.com/whatis/definition/Boolean#:~:text=The%20Boolean%20data,1%20or%200
    if(digitalRead(PIR_MOTION_SENSOR))
        Serial.println("Hi,people is coming");
    else
        Serial.println("Watching");

 delay(200);
}
