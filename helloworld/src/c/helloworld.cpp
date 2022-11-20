#include <pebble-cpp/pebble.hpp>

using namespace Pebble;

class MainWindow : public AppWindow, public TickTimer
{
protected:
    void OnLoad()
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
    
    void UpdateTime()
    {
        DateTime date = DateTime::Now();    
        // Use 24 hour format
        date.Format(buffer, sizeof("00:00"), "%H:%M");
        textLayer.SetText(buffer);
    }    
    
    void OnTick(tm &tick_time, TimeUnits units_changed)
    {
        UpdateTime();
    }    
    
    void OnClickConfig(const ClickConfig& clickConfig)
    { 
        clickConfig.SingleClick(BUTTON_ID_SELECT, CALLBACK(OnSelectClick));
        clickConfig.SingleClick(BUTTON_ID_UP, CALLBACK(OnUpClick));
        clickConfig.SingleClick(BUTTON_ID_DOWN, CALLBACK(OnDownClick));
    }    
    
    void OnSelectClick(const ClickRecognizer& recognizer)
    {
        textLayer.SetText("Select");
    }    

    void OnDownClick(const ClickRecognizer& recognizer)
    {
        textLayer.SetText("Down");
    }    

    void OnUpClick(const ClickRecognizer& recognizer)
    {
        textLayer.SetText("Up");
    }    

private:
    char buffer[5];
    Pebble::TextLayer textLayer;   
};

extern "C" int main(void) 
{
    MainWindow window;
    window.StackPush(true);
    app_event_loop();
}
