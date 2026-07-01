#ifndef TOOLBAR_H                                                                                                                                                                                                                              
 #define TOOLBAR_H                                                                                                                                                                                                                              
                                                                                                                                                                                                                                                
 #include <bobcat_ui/all.h>                                                                                                                                                                                                                     
 #include <Enums.h>       
                                                                                                                                                                                                                                                
 class Toolbar : public bobcat::Group {
     bobcat::Image* pencilButton;     
     bobcat::Image* eraserButton;
     bobcat::Image* mouseButton;                                                                                                                                                                                                                
     bobcat::Image* circleButton;
     bobcat::Image* triangleButton;                                                                                                                                                                                                             
     bobcat::Image* rectangleButton;
     bobcat::Image* undoButton;                                                                                                                                                                                                                 
     bobcat::Image* clearButton;
     bobcat::Image* bringToFrontButton;                                                                                                                                                                                                        
     bobcat::Image* sendToBackButton; 
     bobcat::Image* redoButton;                                                                                                                                                                                                                
     bobcat::Image* lineButton;
     bobcat::Image* pentagonButton;                                                                                                                                                                                                            
                                   
     TOOL selectedTool;
     ACTION action;                                                                                                                                                                                                                             
                  
     void onClick(bobcat::Widget* sender);                                                                                                                                                                                                      
     void visualizeSelectedTool() const; 
     void deselectAllTools() const;    
                                                                                                                                                                                                                                                
 public:
     Toolbar(int x, int y, int w, int h);                                                                                                                                                                                                       
                                        
     TOOL getSelectedTool() const;
     ACTION getAction() const;                                                                                                                                                                                                                  
 
     ~Toolbar();                                                                                                                                                                                                                                
 };             


 #endif
