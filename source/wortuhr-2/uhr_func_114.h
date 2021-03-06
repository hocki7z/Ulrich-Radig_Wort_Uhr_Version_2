#include <Arduino.h>

#define LED_LAYOUT_NORMAL	1
#define LED_LAYOUT_REVERSE	0

#if LED_LAYOUT_NORMAL

#define LED_MAP(x)			(x)

unsigned int matrix[11][11] = {                               //aus 10  11

  {0,   1,  2,  3,  4,  5,  6,  7,  8,  9, 10},
  {21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11},
  {22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32},
  {43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33},
  {44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54},
  {65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55},
  {66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76},
  {87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77},
  {88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98},
  {109,108,107,106,105,104,103,102,101,100,99}, 
  {110,111,112,113},                                          //ergänzt
  
  };


//------------------------------------------------------------------------------

unsigned int smatrix[114] = {                             //vorher 110


   0,   1,  2,  3,  4,  5,  6,  7,  8,  9, 10,
   11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21,
   22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32,
   33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43,
   44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54,
   55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65,
   66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76,
   77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87,
   88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98,
   99,100,101,102,103,104,105,106,107,108,109,
   110,111,112,113,                                         //ergänzt
};
#endif

//------------------------------------------------------------------------------

#if LED_LAYOUT_REVERSE

//   0 -> 103			10 -> 113
//  11 ->  92			21 -> 102
//  22 ->  81			32 ->  91
// usw.
// 110 ->   0   111 -> 1   112 -> 2   113 -> 3
#define LED_MAP(x)		(x > 109 ? x - 110 : 113 - (((x / 11) * 11) + (10 - (x % 11))))

unsigned int matrix[11][11] = {
  {103,104,105,106,107,108,109,110,111,112,113},
  {102,101,100, 99, 98, 97, 96, 95, 94, 93, 92},
  { 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91},
  { 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70},
  { 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69},
  { 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48},
  { 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47},
  { 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26},
  { 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25},
  { 14, 13, 12, 11, 10,  9,  8,  7,  6,  5,  4},
  {  0,  1,  2,  3 }
  };

unsigned int smatrix[114] = {
   113,112,111,110,109,108,107,106,105,104,103,
   102,101,100, 99, 98, 97, 96, 95, 94, 93, 92,
    91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81,
    80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70,
    69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59,
    58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48,
    47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37,
    36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26,
    25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15,
    14, 13, 12, 11, 10,  9,  8,  7,  6,  5,  4,
     3,  2,  1,  0
};
#endif

//------------------------------------------------------------------------------


unsigned int min_arr[2][4] = {                       //ergänzt aus "Uhr func 169"-datei
  {LED_MAP(110), LED_MAP(111), LED_MAP(112), LED_MAP(113)}, // LED für Minuten Anzeige Zeile
  {LED_MAP(110), LED_MAP(111), LED_MAP(112), LED_MAP(113)}  // LED für Minuten Anzeige Ecken 
};

//------------------------------------------------------------------------------





void es_ist() 
{
  //Es
  led_set(LED_MAP(0));
  led_set(LED_MAP(1));
  
  //Ist
  led_set(LED_MAP(3));
  led_set(LED_MAP(4));
  led_set(LED_MAP(5));
}

//------------------------------------------------------------------------------

void nach()
{  
  led_set(LED_MAP(38));
  led_set(LED_MAP(39));
  led_set(LED_MAP(40));
  led_set(LED_MAP(41));
}

//------------------------------------------------------------------------------

void vor()
{
  led_set(LED_MAP(35));
  led_set(LED_MAP(36));
  led_set(LED_MAP(37));
}
//------------------------------------------------------------------------------

void viertel()
{ 
  led_set(LED_MAP(26));
  led_set(LED_MAP(27));
  led_set(LED_MAP(28));
  led_set(LED_MAP(29));
  led_set(LED_MAP(30));
  led_set(LED_MAP(31));
  led_set(LED_MAP(32));
} 

//------------------------------------------------------------------------------

void fuenf()
{
  led_set(LED_MAP(7));
  led_set(LED_MAP(8));
  led_set(LED_MAP(9));
  led_set(LED_MAP(10));
}

//------------------------------------------------------------------------------

void zehn()
{
  led_set(LED_MAP(18));
  led_set(LED_MAP(19));
  led_set(LED_MAP(20));
  led_set(LED_MAP(21));
}

//------------------------------------------------------------------------------
void zwanzig()
{
  led_set(LED_MAP(11));
  led_set(LED_MAP(12));
  led_set(LED_MAP(13));
  led_set(LED_MAP(14));
  led_set(LED_MAP(15));
  led_set(LED_MAP(16));
  led_set(LED_MAP(17));
}

//------------------------------------------------------------------------------

void halb()
{  
  led_set(LED_MAP(44));
  led_set(LED_MAP(45));
  led_set(LED_MAP(46));
  led_set(LED_MAP(47));
}

//------------------------------------------------------------------------------

void eins()
{
  led_set(LED_MAP(60));
  led_set(LED_MAP(61));
  led_set(LED_MAP(62));
  led_set(LED_MAP(63));
}

//------------------------------------------------------------------------------

void uhr()
{
  led_set(LED_MAP(100));
  led_set(LED_MAP(101));
  led_set(LED_MAP(102));
}

//------------------------------------------------------------------------------

void h_ein()
{
  led_set(LED_MAP(61));
  led_set(LED_MAP(62));
  led_set(LED_MAP(63));
}

//------------------------------------------------------------------------------

void h_zwei()
{  
  led_set(LED_MAP(62));
  led_set(LED_MAP(63));
  led_set(LED_MAP(64));
  led_set(LED_MAP(65));
}

//------------------------------------------------------------------------------

void h_drei()
{  
  led_set(LED_MAP(67));
  led_set(LED_MAP(68));
  led_set(LED_MAP(69));
  led_set(LED_MAP(70));
}

//------------------------------------------------------------------------------

void h_vier()
{ 
  led_set(LED_MAP(77));
  led_set(LED_MAP(78));
  led_set(LED_MAP(79));
  led_set(LED_MAP(80));
}

//------------------------------------------------------------------------------

void h_fuenf()
{  
  led_set(LED_MAP(73));
  led_set(LED_MAP(74));
  led_set(LED_MAP(75));
  led_set(LED_MAP(76));
}

//------------------------------------------------------------------------------

void h_sechs()
{
  led_set(LED_MAP(104));
  led_set(LED_MAP(105));
  led_set(LED_MAP(106));
  led_set(LED_MAP(107));
  led_set(LED_MAP(108));
}

//------------------------------------------------------------------------------

void h_sieben()
{
  led_set(LED_MAP(55));
  led_set(LED_MAP(56));
  led_set(LED_MAP(57));
  led_set(LED_MAP(58));
  led_set(LED_MAP(59));
  led_set(LED_MAP(60));
}

//------------------------------------------------------------------------------

void h_acht()
{
  led_set(LED_MAP(89));
  led_set(LED_MAP(90));
  led_set(LED_MAP(91));
  led_set(LED_MAP(92));
}

//------------------------------------------------------------------------------

void h_neun()
{
  led_set(LED_MAP(81));
  led_set(LED_MAP(82));
  led_set(LED_MAP(83));
  led_set(LED_MAP(84));
}

//------------------------------------------------------------------------------

void h_zehn()
{
  led_set(LED_MAP(93));
  led_set(LED_MAP(94));
  led_set(LED_MAP(95));
  led_set(LED_MAP(96));
}

//------------------------------------------------------------------------------

void h_elf()
{
  led_set(LED_MAP(85));
  led_set(LED_MAP(86));
  led_set(LED_MAP(87));
}

//------------------------------------------------------------------------------

void h_zwoelf()
{ 

  led_set(LED_MAP(49));
  led_set(LED_MAP(50));
  led_set(LED_MAP(51));
  led_set(LED_MAP(52));
  led_set(LED_MAP(53));

}

//------------------------------------------------------------------------------

