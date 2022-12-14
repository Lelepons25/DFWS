void HomeScreen() {

    currentPage = '0';
    tft.fillScreen(ILI9341_BLACK);

    tft.drawRect(TEXT_X, TEXT_Y, TEXT_W, TEXT_H, ILI9341_WHITE);
   
    for (uint8_t row = 0; row < 5; row++) {
        for (uint8_t col = 0; col < 1; col++) {
            category[col + row].initButton(&tft, CATEG_X + col * (CATEG_W + CATEG_SPACING_X),
                CATEG_Y + row * (CATEG_H + CATEG_SPACING_Y), // x, y, w, h, outline, fill, text
                CATEG_W, CATEG_H, ILI9341_WHITE, categorycolors[col + row],
                ILI9341_WHITE,
                categorylabels[col + row], CATEG_TEXTSIZE);
            category[col + row].drawButton();
        }
    }



    inputButton[0].initButton(&tft, 200, 20, 75, 20, ILI9341_WHITE, ILI9341_BLUE,
        ILI9341_WHITE,
        "INPUT", SIDE_TEXTSIZE);
    inputButton[0].drawButton();

    tareButton[0].initButton(&tft, 200, 50, 75, 20, ILI9341_WHITE, ILI9341_BLUE,
        ILI9341_WHITE,
        "TARE", SIDE_TEXTSIZE);
    tareButton[0].drawButton();

    trackButton[0].initButton(&tft, 200, 80, 75, 20, ILI9341_WHITE, ILI9341_BLUE,
        ILI9341_WHITE,
        "TRACK", SIDE_TEXTSIZE);
    trackButton[0].drawButton();

    /*FruitButton[0].initButton(&tft, 120, 120, 220, 30, ILI9341_WHITE, ILI9341_LIGHTGREY,
        ILI9341_WHITE,
        "Fruits", CATEG_TEXTSIZE);
    FruitButton[0].drawButton();

    VegButton[0].initButton(&tft, 120, 155, 220, 30, ILI9341_WHITE, ILI9341_RED,
        ILI9341_WHITE,
        "Vegetables", CATEG_TEXTSIZE);
    VegButton[0].drawButton();

    GrainsButton[0].initButton(&tft, 120, 190, 220, 30, ILI9341_WHITE, ILI9341_esti,
        ILI9341_WHITE,
        "Grains", CATEG_TEXTSIZE);
    GrainsButton[0].drawButton();

    ProteinButton[0].initButton(&tft, 120, 225, 220, 30, ILI9341_WHITE, ILI9341_CYAN,
        ILI9341_WHITE,
        "Proteins", CATEG_TEXTSIZE);
    ProteinButton[0].drawButton();

    DairyButton[0].initButton(&tft, 120, 260, 220, 30, ILI9341_WHITE, ILI9341_MAGENTA,
        ILI9341_WHITE,
        "Dairy", CATEG_TEXTSIZE);
    DairyButton[0].drawButton();*/

}

void DrawButtons() {

    BackButton[1].initButton(&tft, 40, 295, // x, y, w, h, outline, fill, text
        60, 30, ILI9341_ORANGE, ILI9341_ORANGE, ILI9341_BLACK,
        "Back", 1.5);
    BackButton[1].drawButton();

    NextButton[1].initButton(&tft, 200, 295, // x, y, w, h, outline, fill, text
        60, 30, ILI9341_RED, ILI9341_RED, ILI9341_BLACK,
        "Next", 1.5);
    NextButton[1].drawButton();

    CancelButton[0].initButton(&tft, 200, 20, 75, 20, ILI9341_WHITE, ILI9341_BLUE,
        ILI9341_WHITE,
        "CANCEL", SIDE_TEXTSIZE);
    CancelButton[0].drawButton();

    SaveButton[0].initButton(&tft, 200, 60, 75, 40, ILI9341_WHITE, ILI9341_BLUE,
        ILI9341_WHITE,
        "SAVE", SIDE_TEXTSIZE);
    SaveButton[0].drawButton();
}

void DrawFruits() {
    tft.fillScreen(ILI9341_DARKGREY);

    tft.drawRect(TEXT_X, TEXT_Y, TEXT_W, 70, ILI9341_WHITE);

    //Create Buttons
    for (uint8_t row = 0; row < 5; row++) {
        for (uint8_t col = 0; col < 1; col++) {
            fruit[col + row].initButton(&tft, FRUIT_X + col * (FRUIT_W + FRUIT_SPACING_X),
                FRUIT_Y + row * (FRUIT_H + FRUIT_SPACING_Y), // x, y, w, h, outline, fill, text
                FRUIT_W, FRUIT_H, ILI9341_WHITE, colors, ILI9341_WHITE,
                fruitlabels[col + row], FRUIT_TEXTSIZE);
            fruit[col + row].drawButton();
        }
    }

    DrawButtons();
}

void DrawVeg() {
    tft.fillScreen(ILI9341_DARKGREY);

    tft.drawRect(TEXT_X, TEXT_Y, TEXT_W, 70, ILI9341_WHITE);

    //Create Buttons
    for (uint8_t row = 0; row < 5; row++) {
        for (uint8_t col = 0; col < 1; col++) {
            veg[col + row].initButton(&tft, FRUIT_X + col * (FRUIT_W + FRUIT_SPACING_X),
                FRUIT_Y + row * (FRUIT_H + FRUIT_SPACING_Y), // x, y, w, h, outline, fill, text
                FRUIT_W, FRUIT_H, ILI9341_WHITE, colors, ILI9341_WHITE,
                veglabels[col + row], FRUIT_TEXTSIZE);
            veg[col + row].drawButton();
        }
    }

    DrawButtons();
}

void DrawGrains() {
    tft.fillScreen(ILI9341_DARKGREY);

    tft.drawRect(TEXT_X, TEXT_Y, TEXT_W, 70, ILI9341_WHITE);

    //Create Buttons
    for (uint8_t row = 0; row < 5; row++) {
        for (uint8_t col = 0; col < 1; col++) {
            grains[col + row].initButton(&tft, FRUIT_X + col * (FRUIT_W + FRUIT_SPACING_X),
                FRUIT_Y + row * (FRUIT_H + FRUIT_SPACING_Y), // x, y, w, h, outline, fill, text
                FRUIT_W, FRUIT_H, ILI9341_WHITE, colors, ILI9341_WHITE,
                grainslabels[col + row], FRUIT_TEXTSIZE);
            grains[col + row].drawButton();
        }
    }

    DrawButtons();
}

void DrawProtein() {

    tft.fillScreen(ILI9341_DARKGREY);

    tft.drawRect(TEXT_X, TEXT_Y, TEXT_W, 70, ILI9341_WHITE);

    //Create Buttons
    for (uint8_t row = 0; row < 5; row++) {
        for (uint8_t col = 0; col < 1; col++) {
            protein[col + row].initButton(&tft, FRUIT_X + col * (FRUIT_W + FRUIT_SPACING_X),
                FRUIT_Y + row * (FRUIT_H + FRUIT_SPACING_Y), // x, y, w, h, outline, fill, text
                FRUIT_W, FRUIT_H, ILI9341_WHITE, colors, ILI9341_WHITE,
                proteinlabels[col + row], FRUIT_TEXTSIZE);
            protein[col + row].drawButton();
        }
    }

    DrawButtons();
}

void DrawDairy() {
    tft.fillScreen(ILI9341_DARKGREY);

    tft.drawRect(TEXT_X, TEXT_Y, TEXT_W, 70, ILI9341_WHITE);

    //Create Buttons
    for (uint8_t row = 0; row < 5; row++) {
        for (uint8_t col = 0; col < 1; col++) {
            dairy[col + row].initButton(&tft, FRUIT_X + col * (FRUIT_W + FRUIT_SPACING_X),
                FRUIT_Y + row * (FRUIT_H + FRUIT_SPACING_Y), // x, y, w, h, outline, fill, text
                FRUIT_W, FRUIT_H, ILI9341_WHITE, colors, ILI9341_WHITE,
                dairylabels[col + row], FRUIT_TEXTSIZE);
            dairy[col + row].drawButton();
        }
    }

    DrawButtons();
}

void DrawInput() {
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

void DrawTare() {
    tft.fillScreen(ILI9341_CYAN);
}

void DrawTrack() {
    tft.fillScreen(ILI9341_BLACK);
    // create 'Title' for Tracker
    tft.drawRect(6, 7, 225, 50, ILI9341_CYAN);
    tft.fillRect(TRACKER_X, TRACKER_Y, 240, 8, ILI9341_BLACK);
    tft.setCursor(TRACKER_X, TRACKER_Y);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(3);
    tft.print("Tracker");

    //GOAL
    tft.fillRect(GOAL_X, GOAL_Y, 240, 8, ILI9341_BLACK);
    tft.setCursor(GOAL_X, GOAL_Y);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);
    tft.print("Goal");

    tft.setCursor(24, 85);
    tft.setTextColor(ILI9341_BLUE, ILI9341_BLACK);
    tft.setTextSize(TEXT_TSIZE);
    tft.print("900");

    //Intake
    tft.fillRect(In_X, In_Y, 240, 8, ILI9341_BLACK);
    tft.setCursor(In_X, In_Y);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);
    tft.print("Intake");

    tft.setCursor(145, 85);
    tft.setTextColor(ILI9341_RED, ILI9341_BLACK);
    tft.setTextSize(TEXT_TSIZE);
    tft.print("500");

    //Remaining Calories
    tft.fillRect(rCal_X, rCal_Y, 240, 8, ILI9341_BLACK);
    tft.setCursor(rCal_X, rCal_Y);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);
    tft.print("Remaining Calories");

    tft.setCursor(95, 200);
    tft.setTextColor(ILI9341_GREEN, ILI9341_BLACK);
    tft.setTextSize(4);
    //int goal1 = targetGoal(goal);
    tft.print("400");

    //Back Button
    BackButton[1].initButton(&tft, 55, 290, // x, y, w, h, outline, fill, text
        80, 30, ILI9341_CYAN, ILI9341_CYAN, ILI9341_BLACK,
        "Back", 1.5);
    BackButton[1].drawButton();
}

void displayErrorGoal() {
    tft.fillRect(20, 120, 200, 100, ILI9341_WHITE);
    tft.setCursor(35, 140);
    tft.setTextColor(ILI9341_BLACK);
    tft.setTextSize(2);
    tft.println("Invalid Input");
    tft.println("Calorie intake \n minimum and maximum is \n between 1,200 and 2,000 \n calories per day.");
}

void displayCalorie(int b, int categ) {

    int calorie = 0;

    //Check which category

    if (categ == 1) {
        calorie = fruitcalories[b];
    }
    else if (categ == 2) {
        calorie = vegcalories[b];
    }
    else if (categ == 3) {
        calorie = grainscalories[b];
    }
    else if (categ == 4) {
        calorie = proteincalories[b];
    }
    else if (categ == 5){
        calorie = dairycalories[b];
    }

    tft.setCursor(TEXT_X + 10, TEXT_Y + 10);
    tft.setTextColor(ILI9341_BLACK);
    tft.setTextSize(2);
    tft.println("Calories:");
    tft.setCursor((TEXT_X + 15), (TEXT_Y + 30));
    tft.setTextSize(3);
    tft.print(calorie);

    //delay(3000);

}

void clearInput() {
    tft.fillRect(TEXT_X, TEXT_Y, TEXT_W, 70, ILI9341_DARKGREY);
    tft.drawRect(TEXT_X, TEXT_Y, TEXT_W, 70, ILI9341_WHITE);
}

void displayTargetGoal(int goal) {
    //tft.fillScreen(ILI9341_WHITE);
    tft.fillRect(20, 120, 200, 100, ILI9341_WHITE);
    tft.setCursor(35, 140);
    tft.setTextColor(ILI9341_BLACK);
    tft.setTextSize(2);
    tft.println("Target Goal is:");
    tft.setCursor(90, 180);
    tft.setTextSize(3);
    tft.println(goal);

    delay(4000);
    //InputScreen();
}
