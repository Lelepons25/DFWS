void HomeScreen() {
    tft.fillScreen(BLACK);

    // create buttons
    for (uint8_t row = 0; row < 4; row++) {
        for (uint8_t col = 0; col < 1; col++) {
            buttons[col + row].initButton(&tft, BUTTON_X + col * (BUTTON_W + BUTTON_SPACING_X),
                BUTTON_Y + row * (BUTTON_H + BUTTON_SPACING_Y), // x, y, w, h, outline, fill, text
                BUTTON_W, BUTTON_H, ILI9341_WHITE, buttoncolors[col + row],
                ILI9341_WHITE,
                buttonlabels[col + row], BUTTON_TEXTSIZE);
            buttons[col + row].drawButton();
        }
    }

    // create 'text field'
    tft.drawRect(TEXT_X, TEXT_Y, TEXT_W, TEXT_H, ILI9341_WHITE);
}

void CheckHomeScreen(){



}