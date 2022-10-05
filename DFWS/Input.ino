void InputScreen() {
    tft.fillScreen(ILI9341_DARKGREY);

    for (uint8_t row = 0; row < 4; row++) {
        for (uint8_t col = 0; col < 3; col++) {
            i_buttons[col + row * 3].initButton(&tft, BUTTON_X_input + col * (BUTTON_W_input + BUTTON_SPACING_Xinput),
                BUTTON_Y_input + row * (BUTTON_H_input + BUTTON_SPACING_Yinput), // x, y, w, h, outline, fill, text
                BUTTON_W_input, BUTTON_H_input, ILI9341_WHITE, i_buttoncolors[col + row * 3],
                ILI9341_WHITE,
                i_buttonlabels[col + row * 3], BUTTON_TEXTSIZE_input);
            i_buttons[col + row * 3].drawButton();
        }
    }

    // create 'text field'
    tft.drawRect(TEXT_X_input, TEXT_Y_input, TEXT_W_input, TEXT_H_input, ILI9341_WHITE);
    tft.fillRect(STATUS_X, STATUS_Y, 240, 8, ILI9341_DARKGREY);
    tft.setCursor(STATUS_X, STATUS_Y);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);
    tft.print("Enter Target Goal");

    //Save Button
    SaveButton[1].initButton(&tft, BUTTON_X_save, BUTTON_Y_save, // x, y, w, h, outline, fill, text
        BUTTON_W_save, BUTTON_H_save, ILI9341_GREEN, ILI9341_GREEN, ILI9341_WHITE,
        "Save", BUTTON_TEXTSIZE_input);
    SaveButton[1].drawButton();

}
