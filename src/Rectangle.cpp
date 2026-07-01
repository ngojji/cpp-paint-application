#include <Rectangle.h>
#include <cmath>
                                                                             
 Rectangle::Rectangle(float _x, float _y, float _width, float _height, Color _color) {
     x = _x; y = _y; width = _width; height = _height; color = _color;
 }                                                                           
                                                                                                               
 void Rectangle::draw() const {       
     glColor3f(color.r, color.g, color.b);                                                                     
     glBegin(GL_POLYGON);                                                                                      
     glVertex2f(x - width/2, y + height/2);
     glVertex2f(x + width/2, y + height/2);                                                                    
     glVertex2f(x + width/2, y - height/2);                                   
     glVertex2f(x - width/2, y - height/2);
     glEnd();                                                                
 }                                                                                                             
                                      
 void Rectangle::drawHighlight() const {                                                                       
     glColor3f(1, 1, 0);                                                                                       
     glBegin(GL_LINE_LOOP);
     glVertex2f(x - width/2 - 0.02f, y + height/2 + 0.02f);                                                    
     glVertex2f(x + width/2 + 0.02f, y + height/2 + 0.02f);                   
     glVertex2f(x + width/2 + 0.02f, y - height/2 - 0.02f);                  
     glEnd();                                                                 
 }                                                                                                             
                                                                              
 bool Rectangle::contains(float px, float py) const {                                                          
     return px >= x - width/2 && px <= x + width/2 &&
            py >= y - height/2 && py <= y + height/2;                                                          
 }                                                                           
                                                                                                               
 void Rectangle::move(float dx, float dy) { x += dx; y += dy; }
                                                                             
 Color Rectangle::getColor() const { return color; }                                                           
 void Rectangle::setColor(Color c) { color = c; }  
 float Rectangle::getX() const { return x; }                                                                   
 float Rectangle::getY() const { return y; }                                                                   
 float Rectangle::getWidth() const { return width; }
 float Rectangle::getHeight() const { return height; }                                                         
 void Rectangle::setX(float _x) { x = _x; }                                   
 void Rectangle::setY(float _y) { y = _y; }
 void Rectangle::setWidth(float w) { width = w; }
 void Rectangle::setHeight(float h) { height = h; }                                                            
                                                                              
 bool Rectangle::nearResizeHandle(float px, float py) const {                                                  
     float hx = x + width/2, hy = y - height/2;                              
     float dx = px - hx, dy = py - hy;                                                                         
     return sqrt(dx*dx + dy*dy) < 0.05f;
 }                                                                                                             
                                                                                                               
 void Rectangle::resize(float dx, float dy) {
     width = std::max(0.02f, width + dx);                                                                      
     height = std::max(0.02f, height - dy);                                                                    
 }                                        
                                                                                                               
 void Rectangle::drawResizeHandle() const {                                   
     float hx = x + width/2, hy = y - height/2;
     float s = 0.025f;                        
     glColor3f(0, 1, 1);                                                                                       
     glBegin(GL_QUADS);                                                      
     glVertex2f(hx - s, hy - s);                                                                               
     glVertex2f(hx + s, hy - s);      
     glVertex2f(hx + s, hy + s);
     glVertex2f(hx - s, hy + s);                                                                               
     glEnd();                                                                 
 }                                                                                                             
                
 Rectangle::~Rectangle() {} 
