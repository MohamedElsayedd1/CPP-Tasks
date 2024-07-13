#include <iostream> // For input and output operations
#include <vector>   // For using vectors
using namespace std;

// Abstract base class Shape
class Shape {
public:
    // Pure virtual functions to be overridden by derived classes
    virtual void draw() = 0;    // Draw the shape (pure virtual)
    virtual void rotate() = 0;  // Rotate the shape (pure virtual)
};

// Abstract class representing open shapes (inherits Shape)
class Open_shape : public Shape {
public:
    // Pure virtual functions to be overridden by derived classes
    virtual void draw() = 0;    // Draw the open shape (pure virtual)
    virtual void rotate() = 0;  // Rotate the open shape (pure virtual)
};

// Abstract class representing closed shapes (inherits Shape)
class Closed_shape : public Shape {
public:
    // Pure virtual functions to be overridden by derived classes
    virtual void draw() = 0;    // Draw the closed shape (pure virtual)
    virtual void rotate() = 0;  // Rotate the closed shape (pure virtual)
};

// Concrete class representing a Line (inherits Open_shape)
class Line : public Open_shape {
public:
    void draw() override {
        cout << "Draw line.\n";   // Implementation of draw for Line
    }
    void rotate() override {
        cout << "Rotate line.\n"; // Implementation of rotate for Line
    }
};

// Concrete class representing a Circle (inherits Closed_shape)
class Circle : public Closed_shape {
public:
    void draw() override {
        cout << "Draw Circle.\n"; // Implementation of draw for Circle
    }
    void rotate() override {
        cout << "Rotate Circle.\n";   // Implementation of rotate for Circle
    }
};

// Concrete class representing a Square (inherits Closed_shape)
class Square : public Closed_shape {
public:
    void draw() override {
        cout << "Draw Square.\n"; // Implementation of draw for Square
    }
    void rotate() override {
        cout << "Rotate Square.\n";   // Implementation of rotate for Square
    }
};

// Function to draw shapes stored in a vector of Shape pointers
void do_draw(vector<Shape *> &shapes) {
    for(const auto x : shapes) {
        x->draw();  // Call draw() polymorphically for each shape
    }
}

// Main function where program execution begins
int main() {
    // Example usage of classes and polymorphism
    
    // Static binding example
    Circle c;
    c.draw();   // Directly calls Circle's draw() function
    
    // Dynamic binding example using base class pointer
    Shape *s = new Square();
    s->draw();  // Calls Square's draw() function through base class pointer
    
    cout << "==============================\n";
    
    // Creating instances of different shapes
    Circle cc;
    Line ll;
    Square ss;
    
    // Creating a vector of Shape pointers
    vector<Shape *> shapes{&cc, &ll, &ss};
    
    // Draw all shapes in the vector
    do_draw(shapes);
    
    cout << "==============================\n";
    
    // Adding another shape to the vector
    Shape *dd = new Circle();   // dd points to a Circle object
    shapes.push_back(dd);
    
    // Draw all shapes in the updated vector
    do_draw(shapes);
    
    // Clean up dynamically allocated memory
    delete s;   // Delete the Square object
    delete dd;  // Delete the Circle object
    
    return 0;   // Indicates successful program execution
}
