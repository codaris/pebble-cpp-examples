#include <pebble-cpp/pebble.hpp>
#include "mainwindow.hpp"

using namespace Pebble;

class ScrollWindow : public AppWindow
{
    Pebble::ScrollLayer scrollLayer = Pebble::ScrollLayer(GetBounds());
    Pebble::TextLayer textLayer = Pebble::TextLayer(Pebble::GRect(0, 0, GetBounds().size.w, 2000));
    std::unique_ptr<MainWindow> mainWindow;

    void OnLoad();
    
    void OnClickConfig(const ClickConfig& clickConfig); 
    
    void OnSelectClick(const ClickRecognizer& recognizer);
};

