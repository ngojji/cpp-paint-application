#ifndef CANVAS_H                                                                                              
 #define CANVAS_H
                                                                                                               
 #include <bobcat_ui/canvas.h>
 #include <FL/Fl.H>                                                                                            
 #include <Enums.h>                         
 #include <Shape.h>                     
 #include <Scribble.h>
 #include <Circle.h>                                                                                           
 #include <Triangle.h>
 #include <Rectangle.h>                                                                                        
 #include <Line.h>
 #include <Pentagon.h>
 #include <vector>                          
                                        
 class Canvas : public bobcat::Canvas_ {
     std::vector<Shape*> shapes;                                                                               
     std::vector<Shape*> redoStack;
     int selectedIndex;                                                                                        
     bool isResizing;
     Scribble* currentScribble;
     float lastDragX, lastDragY;            
     TOOL currentTool;                  
     Color currentColor;
                                                                                                               
     float getGLX() const;
     float getGLY() const;                                                                                     
                
 public:
     Canvas(int x, int y, int w, int h);
                                            
     int handle(int event) override;    
     void render() override;
                                                                                                               
     void setTool(TOOL t);
     void setColor(Color c);                                                                                   
     void setSelectedColor(Color c);


     void addCircle(float x, float y, float radius, Color color);
     void addTriangle(float x, float y, float base, float height, Color color);
     void addRectangle(float x, float y, float width, float height, Color color);
     void addLine(float x1, float y1, float x2, float y2, Color color);                                        
     void addPentagon(float x, float y, float radius, Color color);
                                                                                                               
     void beginScribble(Color color);
     void addToScribble(float x, float y);                                                                     
                                            
     void selectAt(float x, float y);                                                                          
     void startDrag(float x, float y);
     void moveSelected(float x, float y);                                                                      
 
     void bringToFront();                                                                                      
     void sendToBack();
     void undo();
     void redo();
     void clear();                          
                                        
     ~Canvas();
 };                                                                                                            
 
 #endif 

