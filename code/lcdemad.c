
char x[16] ;
////////////////////////////////////// ÊÚÑíÝ ÇáÔÇÔå
sbit LCD_RS at RB4_bit;
sbit LCD_EN at RB5_bit;
sbit LCD_D4 at RB0_bit;
sbit LCD_D5 at RB1_bit;
sbit LCD_D6 at RB2_bit;
sbit LCD_D7 at RB3_bit;

sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_D4_Direction at TRISB0_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB3_bit;
////////////////////////////////
void main()
{
float tem;
char temstr[16];

 ADC_Init();
Lcd_Init();
Lcd_Cmd(_LCD_CURSOR_OFF );
Lcd_Cmd(_LCD_CLEAR );
Lcd_Cmd(_LCD_FIRST_ROW);
TRISC.F0=0;
PORTC.F0=0;// led
TRISC.F2=0;// ÇááãÇÊæÑ
PORTC.F2=0;
//Ýí ÍÇáå ÏÑÌå ÇáÍÑÇÑå ÚáíÊ ÚäÏ ÊÔÛíá ÇáÚÑÈíå
////////////////////////////////////////////////
tem=ADC_Read(0);//
tem=tem*0.4838710458;// ÚáÔÇäÇáÊÍæíá
if(tem>70){
goto loop;
}
/////////////////////////////////////////////ÇáÈÏÇíå ÇáÈÑäÇãÌ
Lcd_Out(1,6,"WELCOME" );
Lcd_Out(2,2,"TO PROGRM TEMP");
Delay_ms(9000);
 Lcd_Cmd(_LCD_CLEAR );
 Lcd_Out(1,1,"Eng/Emad Masri" );
  Lcd_Out(2,2," M:01276611519" );
Delay_ms(12500);
 Lcd_Cmd(_LCD_CLEAR );
 /////////////////////////////////
 loop:
while(1){
tem=ADC_Read(0);// æåäÇ ÇäÇ ÈÚÑÝ ÑÞã Çá ÑÎá Úáí Çá ic
tem=tem*0.4838710458;// ÚáÔÇäÇáÊÍæíá
  if(tem>70){
 portc.f2=1;
 Lcd_Out(2,2,"Warning" );}
 else if(tem<=70)
{portc.f2=0;
Lcd_Out(2,2,"safety"); }

 inttostr(tem,temstr);// ÇáÊÍæíá Çá ÚáÔÇä ÇÚÑÝ ÇÚÑÖåÇ Úáí ÇáÔÇÔå float
 Lcd_Out (1,1," tem= ");
 Lcd_Out (1,8, temstr);
 if(tem>50){
 portc.f0=1;
 Delay_ms(500);
  portc.f0=0;
  Delay_ms(250);
}
 else if(tem<50){
 portc.f0=0;}
Lcd_Out(2,11,"EMAD");

 }



}