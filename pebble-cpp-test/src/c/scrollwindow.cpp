#include "scrollwindow.hpp"


// Lorum ipsum to have something to scroll
static char scroll_text[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nam quam tellus, fermentu  m quis vulputate quis, vestibulum interdum sapien. Vestibulum lobortis pellentesque pretium. Quisque ultricies purus e  u orci convallis lacinia. Cras a urna mi. Donec convallis ante id dui dapibus nec ullamcorper erat egestas. Aenean a m  auris a sapien commodo lacinia. Sed posuere mi vel risus congue ornare. Curabitur leo nisi, euismod ut pellentesque se  d, suscipit sit amet lorem. Aliquam eget sem vitae sem aliquam ornare. In sem sapien, imperdiet eget pharetra a, lacin  ia ac justo. Suspendisse at ante nec felis facilisis eleifend.";

static const int vert_scroll_text_padding = 4;


void ScrollWindow::OnLoad()
{
    scrollLayer.SetClickConfigOntoWindow(*this);
    textLayer.SetText(scroll_text);
    textLayer.SetFont(FONT_KEY_GOTHIC_24_BOLD);
    Pebble::GSize max_size = textLayer.GetContentSize();
    textLayer.SetSize(max_size);
    scrollLayer.SetContentSize(GetBounds().size.w, max_size.h + vert_scroll_text_padding);
    scrollLayer.AddChild(textLayer);
    scrollLayer.SetCallbacks(*this, CALLBACK(OnClickConfig));       
    AddChild(scrollLayer);
}
    
void ScrollWindow::OnClickConfig(const ClickConfig& clickConfig) 
{ 
    clickConfig.SingleClick(BUTTON_ID_SELECT, CALLBACK(OnSelectClick));
} 
    
void ScrollWindow::OnSelectClick(const ClickRecognizer& recognizer)
{
    if (!mainWindow) mainWindow.reset(new MainWindow());
    mainWindow->StackPush(true);
} 

