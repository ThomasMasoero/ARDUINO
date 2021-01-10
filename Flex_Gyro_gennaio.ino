
 /*-------flex sensor part (mouse click)----------
the output is 1 for a left click, 0 for rest position, 2 for right click */
const int flexPin = A0; 
// rest 994  1010 contratto 984 decontratto
const int sogliaDES = 992;    //right button treshold
const int sogliaSIN = 1003;   //left button treshold

/*-------Accelerometer part-----------------------*/

#include <MPU6050_tockn.h>
#include <Wire.h>
MPU6050 mpu6050(Wire);
// declare variables
int x = 0; 
int z = 0;
int x_const = 0;
int z_const = 0;
int coord_x = 0;
int coord_z = 0;
int arr[3]={0, 0, 0};
int flexState=0;

void setup() 
{ 

  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
} 
void loop() 
{ 
  mpu6050.update();
  // calculating the angles values
  x=mpu6050.getAngleX();
  z=mpu6050.getAngleZ();
  //the angles considered from the accelerometers are constrained between -30 and 30
  x_const=constrain(x,-30, 30);  
  z_const=constrain(z,-30, 30);
  // converting them in mouse coordinates thanks to the map function
  coord_x=map(x_const, 30, -30, 767, 0);    
  coord_z=map(z_const, 30, -30, 0,1365 );
  int flexValue;

 flexValue = analogRead(flexPin);
 //Serial.println(flexValue);
  
  if(flexValue>=1010){
    flexState=1;
    Serial.print(1);    //left click
    Serial.print("-");
    Serial.print(coord_x);
    Serial.print("|");
    Serial.print(coord_z);
    Serial.println("/");

  }
  else if(flexValue<=984){
    Serial.print(2);    //right click
    Serial.print("-");
    Serial.print(coord_x);
    Serial.print("|");
    Serial.print(coord_z);
    Serial.println("/");
   
  } 
  else {
    Serial.print(0);    //rest position 
    Serial.print("-");
    Serial.print(coord_x);
    Serial.print("|");
    Serial.print(coord_z);
    Serial.println("/");
    
    }

  
  
 
} 
