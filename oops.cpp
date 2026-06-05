/*
	
	Topics covered:
	1. Class and Object
	2. Encapsulation and Data Hiding
	3. Constructors, Destructor, Copy Constructor
	4. Static data members and static member functions
	5. this pointer
	6. Friend function
	7. Operator Overloading
	8. Inheritance (single, multilevel, multiple)
	9. Function Overloading
	10. Method Overriding and Virtual Functions
	11. Abstract Class and Pure Virtual Function
	12. Composition
*/

#include <iostream>
#include <string>
using namespace std;

class Student {
private:
	string name;
	int age;

public:
	static int studentCount;

	Student() : name("Unknown"), age(0) { studentCount++; }
	Student(string n, int a) : name(n), age(a) { studentCount++; }
	Student(const Student& other) : name(other.name), age(other.age) { studentCount++; }
	~Student() {}

	void setName(string n) { name = n; }
	void setAge(int a) { age = a; }
	string getName() const { return name; }
	int getAge() const { return age; }

	Student& setDetails(string name, int age) {
		this->name = name;
		this->age = age;
		return *this;
	}

	void display() const {
		cout << "Student Name: " << name << ", Age: " << age << endl;
	}

	static int getStudentCount() { return studentCount; }
};

int Student::studentCount = 0;

class Box {
private:
	double length;

public:
	Box(double l = 0) : length(l) {}
	friend double getLength(const Box& b);
};

double getLength(const Box& b) { return b.length; }

class Complex {
private:
	int real;
	int imag;

public:
	Complex(int r = 0, int i = 0) : real(r), imag(i) {}
	Complex operator+(const Complex& other) const {
		return Complex(real + other.real, imag + other.imag);
	}
	void display() const { cout << real << " + " << imag << "i" << endl; }
};

class Calculator {
public:
	int add(int a, int b) { return a + b; }
	int add(int a, int b, int c) { return a + b + c; }
	double add(double a, double b) { return a + b; }
};

class Animal {
protected:
	string type;

public:
	Animal(string t = "Animal") : type(t) {}
	virtual void sound() const { cout << type << " makes a sound." << endl; }
	virtual ~Animal() = default;
};

class Dog : public Animal {
public:
	Dog() : Animal("Dog") {}
	void sound() const override { cout << "Dog barks." << endl; }
};

class Puppy : public Dog {
public:
	void sound() const override { cout << "Puppy makes a soft bark." << endl; }
};

class Flyer {
public:
	void fly() const { cout << "Flying..." << endl; }
};

class Swimmer {
public:
	void swim() const { cout << "Swimming..." << endl; }
};

class Duck : public Flyer, public Swimmer {
public:
	void quack() const { cout << "Duck says quack." << endl; }
};

class Shape {
public:
	virtual double area() const = 0;
	virtual void info() const { cout << "This is a shape." << endl; }
	virtual ~Shape() = default;
};

class Rectangle : public Shape {
private:
	double length;
	double width;

public:
	Rectangle(double l, double w) : length(l), width(w) {}
	double area() const override { return length * width; }
};

class Engine {
public:
	void start() const { cout << "Engine started." << endl; }
};

class Car {
private:
	Engine engine;

public:
	void startCar() const {
		engine.start();
		cout << "Car is ready." << endl;
	}
};

int main() {
	cout << "===== OOPs in C++ Demonstration =====\n\n";

	Student s1;
	Student s2("Alice", 20);
	Student s3 = s2;
	s1.setDetails("Bob", 21);

	cout << "-- Student Objects --" << endl;
	s1.display();
	s2.display();
	s3.display();
	cout << "Total Student objects created: " << Student::getStudentCount() << "\n\n";

	Box box(15.5);
	cout << "-- Friend Function --" << endl;
	cout << "Box length: " << getLength(box) << "\n\n";

	cout << "-- Operator Overloading --" << endl;
	Complex c1(3, 4), c2(5, 6), c3Result;
	c3Result = c1 + c2;
	c1.display();
	c2.display();
	c3Result.display();
	cout << endl;

	cout << "-- Function Overloading --" << endl;
	Calculator calc;
	cout << calc.add(2, 3) << endl;
	cout << calc.add(2, 3, 4) << endl;
	cout << calc.add(2.5, 3.5) << "\n\n";

	cout << "-- Inheritance and Polymorphism --" << endl;
	Animal* a;
	Dog d;
	Puppy p;
	a = &d;
	a->sound();
	a = &p;
	a->sound();
	cout << endl;

	cout << "-- Multiple Inheritance --" << endl;
	Duck duck;
	duck.quack();
	duck.fly();
	duck.swim();
	cout << endl;

	cout << "-- Abstract Class --" << endl;
	Rectangle rect(10, 5);
	Shape* shape = &rect;
	shape->info();
	cout << "Rectangle area = " << shape->area() << "\n\n";

	cout << "-- Composition --" << endl;
	Car car;
	car.startCar();

	return 0;
}

/*
Quick topic summary (expanded):

Class:
	- A user-defined type that groups data (attributes) and functions
		(methods) which operate on that data. Acts as a blueprint for objects.

Object:
	- A concrete instance of a class. It has its own set of attribute values
		and can call the class methods.

Encapsulation and Data Hiding:
	- Bundling of data and methods in a class and restricting direct access to
		some of an object's components (using private/protected). This enforces
		controlled access through public methods (getters/setters).

Constructor:
	- A special member function called when an object is created. It initializes
		the object's state. Constructors can be overloaded and may provide default
		values.

Destructor:
	- A special member function called when an object goes out of scope or is
		deleted. It is used to release resources such as memory or file handles.

Copy Constructor:
	- A constructor that builds a new object as a copy of an existing object.
		Useful to define how member-wise copying should behave, especially with
		dynamically allocated resources.

Static Members:
	- Data members or functions declared static belong to the class rather than
		any particular object instance. They are shared across all instances.

this Pointer:
	- An implicit pointer available inside non-static member functions that
		points to the object for which the member function was invoked. Useful
		for disambiguating members (e.g., parameter names) and returning *this.

Friend Function:
	- A non-member function or another class declared with the friend keyword
		to grant it access to private and protected members of the class.

Operator Overloading:
	- Defining or customizing how operators (such as +, -, <<) behave for user-
		defined types to make code more intuitive and expressive.

Function Overloading:
	- Defining multiple functions with the same name but different parameter
		lists (type or number) so the appropriate one is chosen based on arguments.

Inheritance:
	- Mechanism where a class (derived) acquires the properties and behaviors of
		another class (base). Supports code reuse and polymorphic behavior.

Polymorphism:
	- The ability to treat objects of different derived types uniformly through
		a common base type. Two forms: compile-time (overloading, templates) and
		runtime (virtual functions).

Virtual Function:
	- A member function declared with the virtual keyword in a base class that
		allows derived classes to provide their own implementation. Enables
		runtime method dispatch when accessed through base pointers/references.

Abstract Class and Pure Virtual Function:
	- An abstract class contains at least one pure virtual function (declared
		with = 0). It cannot be instantiated and serves as an interface or base
		contract for derived classes to implement.

Composition (Has-a relationship):
	- A design where a class contains objects of other classes as members to
		build complex types from simpler ones. Indicates ownership or strong
		relationship between components.

*/
