int count = 0,flag=0,old_count=0,i,j;

void setup() {

  Serial.begin(9600);
  for(i=2;i<=5;i++)
  {
    pinMode(i,INPUT);   //4 ir sensors at 2,3,4,5
  }
  pinMode(6,OUTPUT); //led indicator for walking in
  pinMode(7,OUTPUT); // led indicator for walking out
  // put your setup code here, to run once: sure

}

void loop() {
  int state[4];
  for(i=2;i<=5;i++)
  {
    state[i-2]=digitalRead(i);
  }
  for(i=0;i<=3;i++)
  {
    if (state[i]==0)
    {
      for(j=i+1;j<=3;j++)
      {
        if(state[j]==0) //if ir reciever reads low for any two sensors in ascending order
        {
          count++; 
          flag=1;
          digitalWrite(6,HIGH);
          delay(1000);
          digitalWrite(6,LOW);
          break;
            
        }
      }  
    }
    if(flag=1)
    {
      break;
    }
  }
  flag=0;
  for(i=3;i>=0;i--)
  {
    if (state[i]==0)
    {
      for(j=i-1;j>=0;j--)
      {
        if(state[j]==0)  //if ir reciever reads low for any two sensors in descending order
        {
          count--;
          flag=1;
          digitalWrite(6,HIGH);
          delay(1000);
          digitalWrite(6,LOW);
          break;
            
        }
      }  
    }
    if(flag=1)
    {
      break;
    }
  }
  flag=0;
  if(count!=old_count)
  {
    Serial.print(count);
    old_count=count;
  }
  
  // put your main code here, to run repeatedly: yea yea sure

}
