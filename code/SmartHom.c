void chek()
{
TRISD=0XFF;
PORTD=0;
UART1_Init(9600);
UART1_Write(0);
if(portd.f0==1){ UART1_Write_Text ("Hall=ON ");UART1_Write(10);UART1_Write(13);}
else { UART1_Write_Text ("Hall=OFF");UART1_Write(10);UART1_Write(13);}

if(portd.f1==1){ UART1_Write_Text ("BedRoom1=ON ");UART1_Write(10);UART1_Write(13);}
else { UART1_Write_Text ("BedRoom1=OFF");UART1_Write(10);UART1_Write(13);}
 
 if(portd.f2==1){ UART1_Write_Text ("BedRoom2=ON ");UART1_Write(10);UART1_Write(13);}
else { UART1_Write_Text ("BedRoom2=OFF");UART1_Write(10);UART1_Write(13);}

if(portd.f3==1){ UART1_Write_Text ("Recpition=ON ");UART1_Write(10);UART1_Write(13);}
else { UART1_Write_Text ("Recpition=OFF");UART1_Write(10);UART1_Write(13);}

if(portd.f7==1){ UART1_Write_Text("Kitechen=ON");UART1_Write(10);UART1_Write(13);}
else {UART1_Write_Text("Kit=OFF");UART1_Write(10);UART1_Write(13);}

if(portd.f5==1){ UART1_Write_Text ("WC=ON ");UART1_Write(10);UART1_Write(13);}
else { UART1_Write_Text ("Wc=OFF");UART1_Write(10);UART1_Write(13);}

if(portd.f6==1){ UART1_Write_Text ("passage=ON ");UART1_Write(10);UART1_Write(13);}
else { UART1_Write_Text ("Passage=OFF");UART1_Write(10);UART1_Write(13);}
}
char read;
void main()
{
float tem;
 ADC_Init();
TRISA.F0=1;
TRISD=0XFF;
PORTD=0;
TRISB=0;
PORTB=0;
UART1_Init(9600);
while(1)
{
if(UART1_Data_Ready() ==1)
{
read= UART1_Read();
read = UART1_Read();
switch (read)
  {
case 'c':
chek();

break;
///////////////////////
 case '1':// Ïå ÇáÒÑÇÑ ÇáÎÇÕ Èí Çá Hall
 portb.f0= ~portb.f0;// ÈÓÊÎÏãå áÊÛíÑ ÇáÍÇáå Çá áãÈå
 read=0; // áÌÚá ÇáãÓÌá íÓÇæí ÕÝÑ
  break;
  //////////////////////
  case '2' : // Bed room1
    portb.f1= ~portb.f1;// ÈÓÊÎÏãå áÊÛíÑ ÇáÍÇáå Çá áãÈå
 read=0; // áÌÚá ÇáãÓÌá íÓÇæí ÕÝÑ
  break;
  ///////////
  case '3' : // Bed room2
    portb.f2= ~portb.f2;// ÈÓÊÎÏãå áÊÛíÑ ÇáÍÇáå Çá áãÈå
 read=0; // áÌÚá ÇáãÓÌá íÓÇæí ÕÝÑ
  break;
  ////////////------------------------///
  case '4' : // Recption
    portb.f3= ~portb.f3;// ÈÓÊÎÏãå áÊÛíÑ ÇáÍÇáå Çá áãÈå
 read=0; // áÌÚá ÇáãÓÌá íÓÇæí ÕÝÑ
  break;
  //-*********************************
  case '5' : // Kitchen
    portb.f4= ~portb.f4;// ÈÓÊÎÏãå áÊÛíÑ ÇáÍÇáå Çá áãÈå
 read=0; // áÌÚá ÇáãÓÌá íÓÇæí ÕÝÑ
  break;
   ///*******************
  case '6' : // WC
    portb.f5= ~portb.f5;// ÈÓÊÎÏãå áÊÛíÑ ÇáÍÇáå Çá áãÈå
 read=0; // áÌÚá ÇáãÓÌá íÓÇæí ÕÝÑ
  break;
  //****************************
  case '7' : // Passage
    portb.f6= ~portb.f6;// ÈÓÊÎÏãå áÊÛíÑ ÇáÍÇáå Çá áãÈå
 read=0; // áÌÚá ÇáãÓÌá íÓÇæí ÕÝÑ
  break;
   }
    }
   ///*****áÞíÇÓ ÏÑÌå ÇáÍÑÇÑå *****////
tem=ADC_Read(0);// ÇáÊÍÏíÏ ÑÞã ÇáÑÌá
tem=tem*0.4838710458;// ÚáÔÇäÇáÊÍæíá
if(tem>75)
{portb.f7=1;}
else {portb.f7=0;}

      }
          }