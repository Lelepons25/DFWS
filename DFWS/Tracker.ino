void Tracker() {
    tft.fillScreen(BLACK);
    // create 'Title' for Tracker
    tft.drawRect(6, 7, 225, 50, CYAN);
    tft.fillRect(TRACKER_X, TRACKER_Y, 240, 8, BLACK);
    tft.setCursor(TRACKER_X, TRACKER_Y);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(3);
    tft.print("Tracker");

    //GOAL
    tft.fillRect(GOAL_X, GOAL_Y, 240, 8, BLACK);
    tft.setCursor(GOAL_X, GOAL_Y);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);
    tft.print("Goal");

    tft.setCursor(24, 85);
    tft.setTextColor(BLUE, BLACK);
    tft.setTextSize(TEXT_TSIZE);
    tft.print("900");

    //Intake
    tft.fillRect(In_X, In_Y, 240, 8, BLACK);
    tft.setCursor(In_X, In_Y);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);
    tft.print("Intake");

    tft.setCursor(145, 85);
    tft.setTextColor(RED, BLACK);
    tft.setTextSize(TEXT_TSIZE);
    tft.print("500");

    //Remaining Calories
    tft.fillRect(rCal_X, rCal_Y, 240, 8, BLACK);
    tft.setCursor(rCal_X, rCal_Y);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);
    tft.print("Remaining Calories");

    tft.setCursor(95, 200);
    tft.setTextColor(GREEN, BLACK);
    tft.setTextSize(4);
    //int goal1 = targetGoal(goal);
    tft.print("400");

    //Back Button
    BackButton[1].initButton(&tft, 55, 290, // x, y, w, h, outline, fill, text
        80, 30, ILI9341_CYAN, ILI9341_CYAN, ILI9341_BLACK,
        "Back", 1.5);
    BackButton[1].drawButton();

}
