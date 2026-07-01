#include <Toolbar.h>
                                                                                                                                                                                                                                                
 using namespace bobcat;


 Toolbar::Toolbar(int x, int y, int w, int h) : Group(x, y, w, h) {                                                                                                                                                                             
     pencilButton    = new Image(x, y,50, 50, "./assets/pencil.png");
     eraserButton    = new Image(x, y + 50,  50, 50, "./assets/eraser.png");                                                                                                                                                                    
     mouseButton     = new Image(x, y + 100, 50, 50, "./assets/mouse.png");                                                                                                                                                                     
     circleButton    = new Image(x, y + 150, 50, 50, "./assets/circle.png");                                                                                                                                                                    
     triangleButton  = new Image(x, y + 200, 50, 50, "./assets/triangle.png");                                                                                                                                                                  
     rectangleButton = new Image(x, y + 250, 50, 50, "./assets/rectangle.png");
     undoButton      = new Image(x, y + 300, 50, 50, "./assets/undo.png");                                                                                                                                                                      
     clearButton     = new Image(x, y + 350, 50, 50, "./assets/clear.png");
     bringToFrontButton = new Image(x, y + 400, 50, 50, "./assets/bringToFront.png");                                                                                                                                                                              
     sendToBackButton   = new Image(x, y + 450, 50, 50, "./assets/sendToBack.png");
     redoButton         = new Image(x, y + 500, 50, 50, "./assets/redo.png");                                                                                                                                                                               
     lineButton         = new Image(x, y + 550, 50, 50, "./assets/line.png");                                                                                                                                                                               
     pentagonButton     = new Image(x, y + 600, 50, 50, "./assets/pentagon.png");                                                                                                                                                                               
                                                                                                                                                                                                                                                
     pencilButton->box(FL_BORDER_BOX);
     eraserButton->box(FL_BORDER_BOX);                                                                                                                                                                                                          
     mouseButton->box(FL_BORDER_BOX);
     circleButton->box(FL_BORDER_BOX);                                                                                                                                                                                                          
     triangleButton->box(FL_BORDER_BOX);
     rectangleButton->box(FL_BORDER_BOX);                                                                                                                                                                                                       
     undoButton->box(FL_BORDER_BOX);                                                                                                                                                                                                            
     clearButton->box(FL_BORDER_BOX);
     bringToFrontButton->box(FL_BORDER_BOX);
     sendToBackButton->box(FL_BORDER_BOX);
     redoButton->box(FL_BORDER_BOX);
     lineButton->box(FL_BORDER_BOX);
     pentagonButton->box(FL_BORDER_BOX);
                                                                                                                                                                                                                                                
     ON_CLICK(pencilButton,      Toolbar::onClick);                                                                                                                                                                                             
     ON_CLICK(eraserButton,      Toolbar::onClick);
     ON_CLICK(mouseButton,       Toolbar::onClick);                                                                                                                                                                                             
     ON_CLICK(circleButton,      Toolbar::onClick);
     ON_CLICK(triangleButton,    Toolbar::onClick);                                                                                                                                                                                             
     ON_CLICK(rectangleButton,   Toolbar::onClick);
     ON_CLICK(undoButton,        Toolbar::onClick);                                                                                                                                                                                             
     ON_CLICK(clearButton,       Toolbar::onClick);                                                                                                                                                                                             
     ON_CLICK(bringToFrontButton,Toolbar::onClick);
     ON_CLICK(sendToBackButton,  Toolbar::onClick);                                                                                                                                                                                             
     ON_CLICK(redoButton,        Toolbar::onClick);                                                                                                                                                                                             
     ON_CLICK(lineButton,        Toolbar::onClick);
     ON_CLICK(pentagonButton,    Toolbar::onClick);                                                                                                                                                                                             
     selectedTool = PENCIL;                                                                                                                                                                                                                     
     action = NONE;       
     visualizeSelectedTool();                                                                                                                                                                                                                   
 }                          
 
 TOOL Toolbar::getSelectedTool() const { return selectedTool; }
 ACTION Toolbar::getAction() const { return action; }                                                                                                                                                                                           
                                                    
 void Toolbar::onClick(bobcat::Widget* sender) {                                                                                                                                                                                                
     deselectAllTools();                       
     action = NONE;    
                  
     if (sender == pencilButton)            selectedTool = PENCIL;
     else if (sender == eraserButton)       selectedTool = ERASER;                                                                                                                                                                              
     else if (sender == mouseButton)        selectedTool = MOUSE;
     else if (sender == circleButton)       selectedTool = CIRCLE;                                                                                                                                                                              
     else if (sender == triangleButton)     selectedTool = TRIANGLE;
     else if (sender == rectangleButton)    selectedTool = RECTANGLE;                                                                                                                                                                           
     else if (sender == lineButton)         selectedTool = LINE;    
     else if (sender == pentagonButton)     selectedTool = PENTAGON;                                                                                                                                                                            
     else if (sender == undoButton)         action = UNDO;         
     else if (sender == clearButton)        action = CLEAR;                                                                                                                                                                                     
     else if (sender == redoButton)         action = REDO;
     else if (sender == bringToFrontButton) action = BRING_TO_FRONT;                                                                                                                                                                            
     else if (sender == sendToBackButton)   action = SEND_TO_BACK; 
                                                                                                                                                                                                                                                
     if (onChangeCb) onChangeCb(this);
     visualizeSelectedTool();                                                                                                                                                                                                                   
     redraw();              
 }           
                                                                                                                                                                                                                                                
 void Toolbar::visualizeSelectedTool() const {
     if (selectedTool == PENCIL)         pencilButton->color(FL_WHITE);                                                                                                                                                                         
     else if (selectedTool == ERASER)    eraserButton->color(FL_WHITE);
     else if (selectedTool == MOUSE)     mouseButton->color(FL_WHITE);
     else if (selectedTool == CIRCLE)    circleButton->color(FL_WHITE);                                                                                                                                                                         
     else if (selectedTool == TRIANGLE)  triangleButton->color(FL_WHITE);
     else if (selectedTool == RECTANGLE) rectangleButton->color(FL_WHITE);                                                                                                                                                                      
     else if (selectedTool == LINE)      lineButton->color(FL_WHITE);    
     else if (selectedTool == PENTAGON)  pentagonButton->color(FL_WHITE);                                                                                                                                                                       
 }                                                                                                                                                                                                                                              
 
 void Toolbar::deselectAllTools() const {                                                                                                                                                                                                       
     pencilButton->color(FL_BACKGROUND_COLOR);
     eraserButton->color(FL_BACKGROUND_COLOR);
     mouseButton->color(FL_BACKGROUND_COLOR);                                                                                                                                                                                                   
     circleButton->color(FL_BACKGROUND_COLOR);
     triangleButton->color(FL_BACKGROUND_COLOR);                                                                                                                                                                                                
     rectangleButton->color(FL_BACKGROUND_COLOR);
     lineButton->color(FL_BACKGROUND_COLOR);                                                                                                                                                                                                    
     pentagonButton->color(FL_BACKGROUND_COLOR);
 }                                                                                                                                                                                                                                              
                
 Toolbar::~Toolbar() {                                                                                                                                                                                                                          
     delete pencilButton;
     delete eraserButton;                                                                                                                                                                                                                       
     delete mouseButton;
     delete circleButton;
     delete triangleButton;
     delete rectangleButton;
     delete undoButton;    
     delete clearButton;
     delete bringToFrontButton;                                                                                                                                                                                                                 
     delete sendToBackButton; 
     delete redoButton;                                                                                                                                                                                                                         
     delete lineButton;
     delete pentagonButton;
 }           

