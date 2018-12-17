#include "Matrix2D.h"
#include "Vector2D.h"
#include <vector>
#include <cmath>

class Shape
{
protected:
	Vector2D position;
	Matrix2D rotation;
	Assignment::AssignmentApp::Colour colour;

public:
	virtual ~Shape();
	virtual void updatePosition(Vector2D newPos) = 0;
	virtual void updatePosition(float x, float y) = 0;
	virtual void rotateShape() = 0;
	virtual void drawShape() = 0;
};

// Square
class Square : public Shape
{
private:
	float dimension;
	Vector2D vertices[4];

public:
	Square(float dim);
	void updatePosition(Vector2D newPos);
	void updatePosition(float x, float y);
	void rotateShape();
	void drawShape();
};

// Triangle
class Triangle : public Shape
{
private:
	float base;
	float height;
	Vector2D vertices[3];

public:
	Triangle(float base, float height);
	void updatePosition(Vector2D newPos);
	void updatePosition(float x, float y);
	void rotateShape();
	void drawShape();
};

// Cirlce
class Circle : public Shape
{
private:
	float radius;
	float roundness;

public:
	Circle(float radius);
	void updatePosition(Vector2D newPos);
	void updatePosition(float x, float y);
	void rotateShape();
	void drawShape();
};