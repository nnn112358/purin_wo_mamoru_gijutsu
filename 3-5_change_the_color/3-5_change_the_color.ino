#include <M5Stack.h>
TFT_eSprite *Spr;
uint32_t front_col = TFT_BLACK;
uint32_t back_col = TFT_YELLOW;

/* 24Bit color->16bit color変換する関数 */
uint16_t getColor(uint8_t red, uint8_t green, uint8_t blue){
  return ((red>>3)<<11) | ((green>>2)<<5) | (blue>>3);
}
void draw_face(float open);//顔の表示を行う関数

void setup() {
  M5.begin();
  back_col=getColor(255,0,0);	//お顔を真っ赤にする①
  back_col=0xF800;		//お顔を真っ赤にする②
  back_col=TFT_RED;		//お顔を真っ赤にする③
}
void loop() {
  M5.update();
  draw_face(0);	//顔表示を呼び出し
  delay(50);
}

/*　顔の表示を行う関数　*/
void draw_face(float open){  //openはお口の開き具合
  Spr = new TFT_eSprite(&M5.Lcd);    
  Spr->setColorDepth(8); 
  Spr->createSprite(320,240);
  Spr->setBitmapColor(front_col, back_col);
    Spr->fillSprite(back_col);  //背景を塗る。
    Spr->fillTriangle(190, 70, 190, 50,
      280 + random(10), 25 + random(15), front_col); //左眉
    Spr->fillTriangle(130, 70, 130, 50,
       50 + random(10), 25 + random(15), front_col); //右眉
    Spr->fillCircle(90 + random(5), 93 + random(5),
       25 , front_col );//左目
    Spr->fillCircle(230 + random(5), 93 + random(5),
       25 , front_col );//右目
    Spr->fillTriangle(133, 188 - open / 2, 133 + 60, 188 - open / 2,
       133 + 60, 188 + open / 2, front_col); //口
    Spr->fillTriangle(133, 188 - open / 2, 133, 188 + open / 2,
       133 + 60, 188 + open / 2, front_col); //口
    Spr->pushSprite(0, 0);     //スプライトを表示する
}
