void Category() {
    tft.fillScreen(ILI9341_DARKGREY);

    //Text Food Category
    tft.fillRect(30, 5, 220, 50, ILI9341_DARKGREY);
    tft.drawRect(30, 5, 180, 50, ILI9341_DARKGREY); //Display Weight //create a function here
    tft.setCursor(3, 20);
    tft.setTextColor(ILI9341_GREENYELLOW);
    tft.setTextSize(3);
    tft.print("Food Category");

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
}

void DrawFruits()
{
    tft.fillScreen(ILI9341_DARKGREY);


    //Fruits
    tft.fillRect(30, 5, 220, 50, ILI9341_DARKGREY);
    tft.drawRect(30, 5, 180, 50, ILI9341_DARKGREY); //Display Weight //create a function here
    tft.setCursor(3, 20);
    tft.setTextColor(ILI9341_GREENYELLOW);
    tft.setTextSize(3);
    tft.print("FRUITS");

    //Create Buttons
    for (uint8_t row = 0; row < 6; row++) {
        for (uint8_t col = 0; col < 2; col++) {
            fruit[col + row * 2].initButton(&tft, FRUIT_X + col * (FRUIT_W + FRUIT_SPACING_X),
                FRUIT_Y + row * (FRUIT_H + FRUIT_SPACING_Y), // x, y, w, h, outline, fill, text
                FRUIT_W, FRUIT_H, ILI9341_WHITE, fruitcolors, ILI9341_WHITE,
                fruitlabels[col + row * 2], FRUIT_TEXTSIZE);
            fruit[col + row * 2].drawButton();
        }
    }
    //  // Back Button
    //     FruitBack[1].initButton(&tft, FRUIT_X_back, FRUIT_Y_back,
    //     FRUIT_W_back, FRUIT_H,back, ILI9341_GREEN, ILI9341_GREEN, ILI9341_WHITE,
    //     "Back", BUTTON_TEXTSIZE_input );
    //     FruitBack[1].drawButton();
    //   // Next Button
    //     FruitNext[1].initButton(&tft, FRUIT_X_next, FRUIT_Y_next,
    //     FRUIT_W_next, FRUIT_H,next, ILI9341_GREEN, ILI9341_GREEN, ILI9341_WHITE,
    //     "Next", BUTTON_TEXTSIZE_input);
    //     FruitNext[1].drawButton();

}