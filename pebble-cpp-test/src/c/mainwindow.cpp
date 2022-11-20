#include "mainwindow.hpp"

void MainWindow::OnLoad()
{
    SetClickConfigProvider(CALLBACK(OnClickConfig));
    textLayer.SetFrame(0, 55, 144, 50);
    textLayer.SetBackgroundColor(GColorClear);
    textLayer.SetTextColor(GColorBlack);
    textLayer.SetFont(FONT_KEY_BITHAM_42_BOLD);
    textLayer.SetTextAlignment(GTextAlignmentCenter);
    AddChild(textLayer);
    TickTimerStart(MINUTE_UNIT);
    UpdateTime();
}
    
void MainWindow::UpdateTime()
{
    DateTime date = DateTime::Now();    
    if (clock_is_24h_style()) {
        // Use 24 hour format
        date.Format(buffer, sizeof("00:00"), "%H:%M");
    } else {
        // Use 12 hour format
        date.Format(buffer, sizeof("00:00"), "%I:%M");
    }        
    textLayer.SetText(buffer);
}

void MainWindow::OnTick(tm &tick_time, TimeUnits units_changed)
{
    UpdateTime();
}

void MainWindow::OnClickConfig(const ClickConfig& clickConfig) 
{ 
    clickConfig.SingleClick(BUTTON_ID_SELECT, CALLBACK(OnSelectClick));
    clickConfig.SingleClick(BUTTON_ID_UP, CALLBACK(OnUpClick));
    clickConfig.SingleClick(BUTTON_ID_DOWN, CALLBACK(OnDownClick));
}

void MainWindow::OnSelectClick(const ClickRecognizer& recognizer)
{
    textLayer.SetText("Select");
}

void MainWindow::OnDownClick(const ClickRecognizer& recognizer)
{
    textLayer.SetText("Down");
}

void MainWindow::OnUpClick(const ClickRecognizer& recognizer)
{
    textLayer.SetText("Up");
}


