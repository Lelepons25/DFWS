void Category() {
    tft.fillScreen(ILI9341_DARKGREY);


    //Create Buttons
    for (uint8_t row = 0; row < 6; row++) {
        for (uint8_t col = 0; col < 1; col++) {
            category[col + row].initButton(&tft, CATEG_X + col * (CATEG_W + BUTTON_SPACING_X),
                CATEG_Y + row * (CATEG_H + BUTTON_SPACING_Y), // x, y, w, h, outline, fill, text
                CATEG_W, CATEG_H, ILI9341_WHITE, categorycolors[col + row], ILI9341_WHITE,
                categorylabels[col + row], BUTTON_TEXTSIZE);
            category[col + row].drawButton();
        }
    }

    //Text Food Category
    tft.fillRect(30, 5, 220, 50, ILI9341_DARKGREY);
    tft.drawRect(30, 5, 180, 50, ILI9341_DARKGREY); //Display Weight //create a function here
    tft.setCursor(3, 20);
    tft.setTextColor(ILI9341_GREENYELLOW);
    tft.setTextSize(3);
    tft.print("Food Category");
}


void FoodCategory(TSPoint p) {


    for (uint8_t count = 0; count < 12; count++) // Number of 
    {
        if (fruit[count].contains(p.x, p.y)) {
            fruit[count].press(true);
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
        }
    }
}
