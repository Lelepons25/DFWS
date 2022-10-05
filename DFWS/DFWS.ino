/*
 Name:		DFWS.ino
 Created:	10/5/2022 6:05:21 PM
 Author:	CABELIN
*/
//////////////////////////////////////////////////////////////// Everything important before the void setup

#include <Adafruit_GFX.h> // Core graphics library
#include <Adafruit_TFTLCD.h> // Hardware-specific library
#include <TouchScreen.h>


#define LCD_CS A3 
#define LCD_CD A2 
#define LCD_WR A1 
#define LCD_RD A0 
#define LCD_RESET A4 

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define GREY    0xCCCCCC

// Color definitions
#define ILI9341_BLACK 0000 /* 0, 0, 0 */
#define ILI9341_NAVY 0x000F /* 0, 0, 128 */
#define ILI9341_DARKGREEN 0x03E0 /* 0, 128, 0 */
#define ILI9341_DARKCYAN 0x03EF /* 0, 128, 128 */
#define ILI9341_MAROON 0x7800 /* 128, 0, 0 */
#define ILI9341_PURPLE 0x780F /* 128, 0, 128 */
#define ILI9341_OLIVE 0x7BE0 /* 128, 128, 0 */
#define ILI9341_LIGHTGREY 0xC618 /* 192, 192, 192 */
#define ILI9341_DARKGREY 0x7BEF /* 128, 128, 128 */
#define ILI9341_BLUE 0x001F /* 0, 0, 255 */
#define ILI9341_GREEN 0x07E0 /* 0, 255, 0 */
#define ILI9341_CYAN 0x07FF /* 0, 255, 255 */
#define ILI9341_RED 0xF800 /* 255, 0, 0 */
#define ILI9341_MAGENTA 0xF81F /* 255, 0, 255 */
#define ILI9341_YELLOW 0xFFE0 /* 255, 255, 0 */
#define ILI9341_WHITE 0xFFFF /* 255, 255, 255 */
#define ILI9341_ORANGE 0xFD20 /* 255, 165, 0 */
#define ILI9341_GREENYELLOW 0xAFE5 /* 173, 255, 47 */
#define ILI9341_PINK 0xF81F
#define ILI9341_esti 0x794379
#define ILI9341_esti2 0x86923B
/******************* UI details */
#define BUTTON_X 120
#define BUTTON_Y 140
#define BUTTON_W 220
#define BUTTON_H 40
#define BUTTON_SPACING_X 10
#define BUTTON_SPACING_Y 10
#define BUTTON_TEXTSIZE 2

// text box where numbers go
#define TEXT_X 10
#define TEXT_Y 10
#define TEXT_W 220
#define TEXT_H 100
#define TEXT_TSIZE 3
#define TEXT_TCOLOR ILI9341_MAGENTA
// the data (phone #) we store in the textfield
#define TEXT_LEN 4
char textfield[TEXT_LEN + 1] = "";
uint8_t textfield_i = 0;
#define YP A3 // must be an analog pin, use "An" notation!
#define XM A2 // must be an analog pin, use "An" notation!
#define YM 9 // can be a digital pin
#define XP 8 // can be a digital pin
#define TS_MINX 100
#define TS_MAXX 920
#define TS_MINY 70
#define TS_MAXY 900
// We have a status line for like, is FONA working
#define STATUS_X 10
#define STATUS_Y 65

#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;
//Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
int a = 0;

//int goal;

//button details for InputScreen
#define BUTTON_X_input 50
#define BUTTON_Y_input 120
#define BUTTON_W_input 60
#define BUTTON_H_input 30
#define BUTTON_SPACING_Xinput 10
#define BUTTON_SPACING_Yinput 10
#define BUTTON_TEXTSIZE_input 2
//Textbox Details for InputScreen
#define TEXT_X_input 10
#define TEXT_Y_input 10
#define TEXT_W_input 220
#define TEXT_H_input 50
#define TEXT_TSIZE_input 3
#define TEXT_TCOLOR_input ILI9341_MAGENTA
//SaveButton
#define BUTTON_X_save 120
#define BUTTON_Y_save 280
#define BUTTON_W_save 200
#define BUTTON_H_save 35
#define BUTTON_SPACING_Xsave 10
#define BUTTON_SPACING_Ysave 10

// Button Details Food Category
#define CATEG_X 120
#define CATEG_Y 80
#define CATEG_W 220
#define CATEG_H 30
#define CATEG_I 5

// Button Details Fruit Category
#define FRUIT_X 60 //Left border
#define FRUIT_Y 60 //Top
#define FRUIT_W 105
#define FRUIT_H 25 //lower
#define FRUIT_I 10
#define FRUIT_SPACING_X 15
#define FRUIT_SPACING_Y 15
#define FRUIT_TEXTSIZE 1.6

//NextButton
#define FRUIT_X_next 120
#define FRUIT_Y_next 280
#define FRUIT_W_next 200
#define FRUIT_H_next 35
#define BUTTON_SPACING_X 10
#define BUTTON_SPACING_Y 10

//TRACKER
#define TRACKER_X 50
#define TRACKER_Y 20

//GOAL
#define GOAL_X 25
#define GOAL_Y 120

//INTAKE
#define In_X 140
#define In_Y 120

//REMAINING CALORIES
#define rCal_X 10
#define rCal_Y 250


bool buttonEnabled = true;
char currentPage, unit;
//int targetGoal;

Adafruit_GFX_Button buttons[4];
/* create 15 buttons, in classic candybar phone style */
char buttonlabels[4][10] = { "Input", "Tare", "Category", "Tracker" };
uint16_t buttoncolors[4] = { ILI9341_DARKGREY, ILI9341_RED, ILI9341_esti2, ILI9341_esti };

Adafruit_GFX_Button i_buttons[12];
/* create 15 buttons, in classic candybar phone style */
char i_buttonlabels[12][5] = { "0", "1", "2", "3", "4", "5", "6", "7", "8",
"Back", "9", "Clr" };
uint16_t i_buttoncolors[12] = { ILI9341_BLUE, ILI9341_BLUE, ILI9341_BLUE,
ILI9341_BLUE, ILI9341_BLUE, ILI9341_BLUE, ILI9341_BLUE, ILI9341_BLUE,
ILI9341_BLUE, ILI9341_LIGHTGREY, ILI9341_BLUE, ILI9341_RED };

Adafruit_GFX_Button SaveButton[1];

Adafruit_GFX_Button BackButton[1];

//Category Buttons
Adafruit_GFX_Button category[6];
char categorylabels[6][24] = { "Fruits","Vegetables","Grains", "Protein", "Dairy", "Back" };
uint16_t categorycolors[6] = { ILI9341_DARKGREY, ILI9341_RED, ILI9341_esti2, ILI9341_esti, ILI9341_PINK, ILI9341_ORANGE };

//Fruit Category Buttons
Adafruit_GFX_Button fruit[12];
char fruitlabels[12][24] = { "Apple","Avocado","Banana", "Durian", "Grape", "Guava", "Jackfruit", "Lemon","Lime","Mango", "Back", "Next" };
uint16_t fruitcolors = ILI9341_esti2;


void setup() {

    Serial.begin(9600);
    tft.reset();
    tft.begin(0x9341);
    tft.setRotation(0);


    //Serial.println("HomeScreen Display");
    HomeScreen();
    currentPage = '0';

}

#define MINPRESSURE 10
#define MAXPRESSURE 1000

void loop() {

    digitalWrite(13, HIGH);
    TSPoint p = ts.getPoint();
    digitalWrite(13, LOW);
    // if sharing pins, you'll need to fix the directions of the touchscreen pins
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);

    if (p.z > MINPRESSURE && p.z < MAXPRESSURE) {
        // scale from 0->1023 to tft.width
        p.x = map(p.x, TS_MINX, TS_MAXX, tft.width(), 0);
        p.y = (tft.height() - map(p.y, TS_MINY, TS_MAXY, tft.height(), 0));
    }

    //Home Screen
    if (currentPage == '0') {
        for (uint8_t b = 0; b < 4; b++) {
            if (buttons[b].contains(p.x, p.y)) {
                //Serial.print("Pressing: "); Serial.println(b);
                buttons[b].press(true); // tell the button it is pressed
            }
            else {
                buttons[b].press(false); // tell the button it is NOT pressed
            }
        }

        for (uint8_t b = 0; b < 4; b++) {
            if (buttons[b].justReleased()) {
                // Serial.print("Released: "); Serial.println(b);
                //buttons[b].drawButton(); // draw normal
            }

            if (buttons[b].justPressed()) {
                buttons[b].drawButton(true); // draw invert! 

                if (b == 0) {
                    currentPage = '1';
                    //textfield[textfield_i] = ' ';
                    tft.setRotation(0);
                    InputScreen();

                }

                // if (b == 1){
                //   currentPage = '2';
                //   tft.setRotation(0);
                //   TareScreen(400);
                //   HomeScreen();
                // }
                if (b == 2) {
                    currentPage = '3';
                    tft.setRotation(0);
                    Category();
                }

                if (b == 3) {
                    currentPage = '4';
                    tft.setRotation(0);
                    Tracker();
                }
            }
        }
    }
    //Input Screen
    if (currentPage == '1') {

        // go thru all the buttons, checking if they were pressed
        for (uint8_t b = 0; b < 12; b++) {
            if (i_buttons[b].contains(p.x, p.y)) {
                i_buttons[b].press(true); // tell the button it is pressed
            }
            else {
                i_buttons[b].press(false); // tell the button it is NOT pressed
            }
        }
        // now we can ask the buttons if their state has changed
        for (uint8_t b = 0; b < 12; b++) {
            if (i_buttons[b].justReleased()) {
                i_buttons[b].drawButton(); // draw normal
            }

            if (i_buttons[b].justPressed()) {
                i_buttons[b].drawButton(true); // draw invert!

                // if a numberpad button, append the relevant # to the textfield
                if (b >= 0 && b != 9 && b != 11) {
                    if (textfield_i < TEXT_LEN) {
                        textfield[textfield_i] = i_buttonlabels[b][0];
                        textfield_i++;
                        textfield[textfield_i] = 0; // zero terminate
                    }
                }

                // clr button
                if (b == 11) {
                    textfield[textfield_i] = 0;
                    if (textfield > 0) {
                        textfield_i--;
                        textfield[textfield_i] = ' ';
                    }
                }

                // update the current text field
                Serial.println(textfield);
                tft.setCursor(TEXT_X + 2, TEXT_Y + 10);
                tft.setTextColor(TEXT_TCOLOR, ILI9341_DARKGREY);
                tft.setTextSize(TEXT_TSIZE);
                tft.print(textfield);

                //Back Button
                if (b == 9) {
                    currentPage = '0';
                    void fillscreen();
                    HomeScreen();
                }

                //delay(100); // UI debouncing
            }
        }


        if (SaveButton[1].justReleased()) {
            SaveButton[1].drawButton(); // draw normal
        }

        if (SaveButton[1].justPressed()) {
            SaveButton[1].drawButton(true);
            Serial.println("SAVE BUTTON PRESSED");
            targetGoal((int)textfield);
        }
    }

    if (currentPage == '3') { //Food Category

        // go thru all the buttons, checking if they were pressed
        for (uint8_t b = 0; b < 6; b++) {
            if (category[b].contains(p.x, p.y)) {
                category[b].press(true); // tell the button it is pressed
            }
            else {
                category[b].press(false); // tell the button it is NOT pressed
            }
        }
        // now we can ask the buttons if their state has changed
        for (uint8_t b = 0; b < 6; b++) {
            if (category[b].justReleased()) {
                // category[b].drawButton(); // draw normal
            }

            if (category[b].justPressed()) {
                // category[b].drawButton(true); // draw invert!

                if (b >= 0 && b <= 4) {
                    //void fillscreen();
                    //Create button for database
                    if (b == 0) { // Fruit

                        DrawFruits(); // Draw 
                        // if (p.z > MINPRESSURE && p.z < MAXPRESSURE) {
                        //   // scale from 0->1023 to tft.width
                        //   p.x = map(p.x, TS_MINX, TS_MAXX, tft.width(), 0);
                        //   p.y = (tft.height()-map(p.y, TS_MINY, TS_MAXY, tft.height(), 0));
                        // }
                        //Read button
                        for (uint8_t count = 0; count < 12; count++) // Number of 
                        {
                            if (fruit[count].contains(p.x, p.y)) {
                                fruit[count].press(true);
                                // Serial.println(count);
                                 // Serial.println(p.x);
                            }
                            else {
                                fruit[count].press(false);
                            }
                        }

                        for (uint8_t count = 0; count < 12; count++) {

                            if (fruit[count].justReleased()) {
                                fruit[count].drawButton();

                            }

                            else if (fruit[count].justPressed()) {
                                fruit[count].drawButton(true);
                                //Serial.println(b);

                                if (count == 10) {// Back
                                    currentPage = '0';
                                    Serial.println("korik");
                                    void fillscreen();
                                    HomeScreen();
                                }
                                else {
                                    Serial.println("Sayop");
                                }
                            }
                        }
                    }
                    else {
                        Serial.println("Dli Fruits");
                    }
                }
                if (b == 5) {
                    currentPage = '0';
                    void fillscreen();
                    Serial.println("korik5");
                    HomeScreen();
                }

            }
        }
    }

    if (currentPage == '4') {
        if (BackButton[1].contains(p.x, p.y)) {
            BackButton[1].press(true); // tell the button it is pressed
        }
        else {
            BackButton[1].press(false); // tell the button it is NOT pressed
        }
        //Serial.println("Page 4");
        if (BackButton[1].justReleased()) {
            BackButton[1].drawButton(); // draw normal
        }

        if (BackButton[1].justPressed()) {
            BackButton[1].drawButton(true);
            //if (BackButton[1].isPressed()){
            currentPage = '0';
            void fillscreen();
            HomeScreen();

        }
    }

}



void DisplayWeight(int weight) {
    tft.fillRect(TEXT_X, TEXT_Y, TEXT_W, TEXT_H, ILI9341_DARKGREY);
    tft.drawRect(TEXT_X, TEXT_Y, TEXT_W, TEXT_H, ILI9341_DARKGREY); //Display Weight //create a function here
    tft.setCursor(20, 20);
    tft.setTextColor(ILI9341_MAGENTA);
    tft.setTextSize(6);
    tft.print(weight);
}

void TareScreen(int container) {
    container = 0;
    DisplayWeight(container);
}



int targetGoal(int goal) {
    int goal1 = goal;
    return goal1;
}

