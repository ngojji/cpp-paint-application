

#ifndef TRIANGLE_H
 #define TRIANGLE_H                                                                                            
                  
 #include <Shape.h>                                                                                            
 #include <GL/freeglut.h>
                        
 class Triangle : public Shape {                                             
     float x, y, base, height;                                                
     Color color;                     
                
 public:                                                                                                       
     Triangle(float x, float y, float base, float height, Color color);
     void draw() const;                                                                                        
     void drawHighlight() const;
     bool contains(float px, float py) const;                                
     void move(float dx, float dy);                                           
     Color getColor() const;          
     void setColor(Color c);
     float getX() const;                                                                                       
     float getY() const;
     float getBase() const;                                                                                    
     float getHeight() const;                                                 
     void setX(float x);              
     void setY(float y);
     void setBase(float b);                                                                                    
     void setHeight(float h);
                                                                                                               
     bool nearResizeHandle(float px, float py) const;                         
     void resize(float dx, float dy);               
     void drawResizeHandle() const; 
                                                                                                               
     ~Triangle();
 };                                                                                                            
                
 #endif

