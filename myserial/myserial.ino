int  PIN_led = 13;
#define FeedingVoltagePin A0
#define InputPinMeasurement A1
#define OutputPinMeasurement A2


void setup() {
  Serial.begin(115200);                     
  pinMode(FeedingVoltagePin,OUTPUT);                
  pinMode(InputPinMeasurement,INPUT);
  pinMode(OutputPinMeasurement,INPUT);                
}

void loop() {
  DecodeDataChain();
 }


void DecodeDataChain() {

  #define ArraySize 4
  String parameters[ArraySize],DataChain, element;
  #define SeparatorCharacter ","
  int SubstringInitialPosition, SubstringLastPosition, ArrayIndex;

  if(Serial.available()){    
    DataChain = Serial.readString();                                                  //if true, save the string in a variable
    Serial.println(DataChain);                                                        //print the string in serial monitor
    SubstringInitialPosition=0;                                                                //first character's position of the first substring
    SubstringLastPosition = DataChain.indexOf(SeparatorCharacter,SubstringInitialPosition);    //last character's position of the first substring
      
    ArrayIndex = 0;                                                                   
    while (SubstringLastPosition!=-1) {
      Serial.print(ArrayIndex);
      element = DataChain.substring(SubstringInitialPosition,  SubstringLastPosition); 
      parameters[ArrayIndex]= element;
    
      SubstringInitialPosition = SubstringLastPosition+1;
      SubstringLastPosition = DataChain.indexOf(SeparatorCharacter, SubstringInitialPosition);
      ArrayIndex =ArrayIndex+1;
    }
    Serial.println(ArrayIndex);
    Serial.println(" ");
    element = DataChain.substring(SubstringInitialPosition, DataChain.length());
    parameters[ArraySize-1] = element;

    //###At this point the array is already created and stores Strings
    unsigned float MeasuremenTime = parameters[0].toFloat()*1000000;    //Time in seconds conveerted in microseconds
    unsigned float SamplingTime = parameters[1].toFloat()*1000000;      //Time in seconds converted in microseconds
    String SignalType = parameters[2];
    unsigned long 

    //###A PWM signal will be used, so the voltaje must converted into a duty cycle valid integer number (0-255) 
    unsigned float InputVoltage = round((255/5)*parameters[3].toFloat());

    Serial.println(MeasuremenTime);
    Serial.println(SamplingTime);
    Serial.println(SignalType);
    Serial.println(InputVoltage);


    
  }
} 

 
