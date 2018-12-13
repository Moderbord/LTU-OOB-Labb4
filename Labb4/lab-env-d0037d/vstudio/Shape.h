#pragma once
#include "../../projects/assignment/code/assignmentapp.h"
#include "Matrix2D.h"
#include "Vector2D.h"

namespace {
	using Assignment::AssignmentApp;
}

class Shape
{
protected:
	Vector2D position;
	Matrix2D rotation;
	AssignmentApp::Colour colour;
	virtual void updatePosition(Vector2D newPos) = 0;
	virtual void drawShape() = 0;
};

// Square
class Square : public Shape 
{
private:
	float dimension;

public:
	Square(float dim) : Shape(), dimension(dim)
	{
		colour.r = 1.0f; // Sqaure is magenta
	};
	void updatePosition(Vector2D newPos)
	{
		position = newPos;
	};
	void updatePosition(float x, float y)
	{
		position = Vector2D(x, y);
	};
	void drawShape()
	{
		float posX = position.getX();
		float posY = position.getY();

		AssignmentApp::LineData line;
		line.x1 = -dimension + posX;
		line.y1 = -dimension + posY;
		line.x2 = dimension + posX;
		line.y2 = -dimension + posY;
		line.c1 = colour;
		AssignmentApp::DrawLine(line);

		line.x1 = dimension + posX;
		line.y1 = -dimension + posY;
		line.x2 = dimension + posX;
		line.y2 = dimension + posY;
		AssignmentApp::DrawLine(line);

		line.x1 = dimension + posX;
		line.y1 = dimension + posY;
		line.x2 = -dimension + posX;
		line.y2 = dimension + posY;
		AssignmentApp::DrawLine(line);

		line.x1 = -dimension + posX;
		line.y1 = dimension + posY;
		line.x2 = -dimension + posX;
		line.y2 = -dimension + posY;
		AssignmentApp::DrawLine(line);
	};
};

// Triangle
class Triangle : public Shape
{
private:
	float base;
	float height;

public:
	Triangle(float x, float y) : Shape(), base(x), height(y)
	{
		colour.g = 1.0f; // triangle is cyan
		rotation = Matrix2D::identityMatrix();
	};
	void updatePosition(Vector2D newPos)
	{
		position = newPos;
	};
	void updatePosition(float x, float y)
	{
		position = Vector2D(x, y);
	};
	void setRotation(float degrees)
	{
		rotation = Matrix2D::rotationMatrix(degrees, degrees, degrees, degrees);
	};
	void drawShape()
	{
		float posX = position.getX();
		float posY = position.getY();

		Vector2D normalized = Vector2D(base, height).normalized();
		float normX = normalized.getX() / 2;
		float normY = normalized.getY() / 2;

		//Vector2D v1(-normX, -normY);
		//Vector2D v2(normX, -normY);
		//Vector2D v3(0, normY);

		//v1 = rotation * v1;
		//v2 = rotation * v2;
		//v3 = rotation * v3;

		AssignmentApp::LineData line;
		line.x1 = -normX + posX;
		line.y1 = -normY + posY;
		line.x2 = normX + posX;
		line.y2 = -normY + posY;
		line.c1 = colour;
		AssignmentApp::DrawLine(line);

		line.x1 = normX + posX;
		line.y1 = -normY + posY;
		line.x2 = posX;
		line.y2 = normY + posY;
		AssignmentApp::DrawLine(line);

		line.x1 = posX;
		line.y1 = normY + posY;
		line.x2 = -normX + posX;
		line.y2 = -normY + posY;
		AssignmentApp::DrawLine(line);
	};
};

// Circle 
class Circle : public Shape
{
private:
	float radius;

public:
	Circle(float r) : Shape(), radius(r)
	{
		colour.r = 1.0f; // Circle is yellow-ish
		colour.g = 1.0f;
		colour.b = 0.0f;
	};
	void updatePosition(Vector2D newPos)
	{
		position = newPos;
	};
	void updatePosition(float x, float y)
	{
		position = Vector2D(x, y);
	};
	void drawShape() 
	{
		float posX = position.getX();
		float posY = position.getY();

		AssignmentApp::LineData line;
		line.x1 = 0 + posX;
		line.y1 = -radius + posY;
		line.x2 = radius/2.25f + posX;
		line.y2 = -2.5f * radius / 3 + posY;
		line.c1 = colour;
		AssignmentApp::DrawLine(line);

		line.x1 = radius / 2.25f + posX;
		line.y1 = -2.5f * radius / 3 + posY;
		line.x2 = 2.5f * radius / 3 + posX;
		line.y2 = -radius / 2.25f + posY;
		AssignmentApp::DrawLine(line);

		line.x1 = 2.5f * radius / 3 + posX;
		line.y1 = -radius / 2.25f + posY;
		line.x2 = radius + posX;
		line.y2 = 0 + posY;
		AssignmentApp::DrawLine(line);

		line.x1 = radius + posX;
		line.y1 = 0 + posY;
		line.x2 = 2.5f * radius / 3 + posX;
		line.y2 = radius / 2.25f + posY;
		AssignmentApp::DrawLine(line);

		line.x1 = 2.5f * radius / 3 + posX;
		line.y1 = radius / 2.25f + posY;
		line.x2 = radius / 2.25f + posX;
		line.y2 = 2.5f * radius / 3 + posY;
		AssignmentApp::DrawLine(line);

		line.x1 = radius / 2.25f + posX;
		line.y1 = 2.5f * radius / 3 + posY;
		line.x2 = 0 + posX;
		line.y2 = radius + posY;
		AssignmentApp::DrawLine(line);

		line.x1 = 0 + posX;
		line.y1 = radius + posY;
		line.x2 = -radius / 2.25f + posX;
		line.y2 = 2.5f * radius / 3 + posY;
		AssignmentApp::DrawLine(line);

		line.x1 = -radius / 2.25f + posX;
		line.y1 = 2.5f * radius / 3 + posY;
		line.x2 = -2.5f * radius / 3 + posX;
		line.y2 = radius / 2.25f + posY;
		AssignmentApp::DrawLine(line);

		line.x1 = -2.5f * radius / 3 + posX;
		line.y1 = radius / 2.25f + posY;
		line.x2 = -radius + posX;
		line.y2 = 0 + posY;
		AssignmentApp::DrawLine(line);

		line.x1 = -radius + posX;
		line.y1 = 0 + posY;
		line.x2 = -2.5f * radius / 3 + posX;
		line.y2 = -radius / 2.25f + posY;
		AssignmentApp::DrawLine(line);

		line.x1 = -2.5f * radius / 3 + posX;
		line.y1 = -radius / 2.25f + posY;
		line.x2 = -radius / 2.25f + posX;
		line.y2 = -2.5f * radius / 3 + posY;
		AssignmentApp::DrawLine(line);

		line.x1 = -radius / 2.25f + posX;
		line.y1 = -2.5f * radius / 3 + posY;
		line.x2 = 0 + posX;
		line.y2 = -radius + posY;
		AssignmentApp::DrawLine(line);


	};
};
