#include <pebble-cpp/pebble.hpp>

using namespace Pebble;

class MainWindow : public AppWindow, public TickTimer
{
protected:
    virtual void OnLoad();
    
    void UpdateTime();
    
    void OnTick(tm &tick_time, TimeUnits units_changed);
    
    void OnClickConfig(const ClickConfig& clickConfig);
    
    void OnSelectClick(const ClickRecognizer& recognizer);

    void OnDownClick(const ClickRecognizer& recognizer);

    void OnUpClick(const ClickRecognizer& recognizer);

private:
    char buffer[5];
    Pebble::TextLayer textLayer;   
};


