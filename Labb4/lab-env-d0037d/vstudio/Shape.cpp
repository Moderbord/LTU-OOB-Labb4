#include "config.h"
#include "../../projects/assignment/code/assignmentapp.h"
#include "Shape.h"

const float aspectRatio = (3.0f/4.0f);

// Shape
Shape::~Shape() {
	delete this;
}

// Square
Square::Square(float dim) : Shape(), dimension(dim)
{
	colour.r = 1.0f; // Sqaure is magenta

	rotation = Matrix2D::rotationMatrix(0);

	vertices[0] = Vector2D(-dim, -dim);
	vertices[1] = Vector2D(dim, -dim);
	vertices[2] = Vector2D(dim, dim);
	vertices[3] = Vector2D(-dim, dim);
};

void Square::updatePosition(Vector2D newPos)
{
	position = position + newPos;
};

void Square::updatePosition(float x, float y)
{
	position = position + Vector2D(x, y);
};

void Square::rotateShape()
{
	position = rotation * position;
}

void Square::drawShape()
{
	float posX = position.getX();
	float posY = position.getY();

	Assignment::AssignmentApp::LineData line;
	line.c1 = colour;
	line.c2 = colour;

	for (int i = 0; i < 4; i++)
	{
		line.x1 = (vertices[i].getX() + posX) * aspectRatio;
		line.y1 = vertices[i].getY() + posY;
		line.x2 = (vertices[i + 1].getX() + posX) * aspectRatio;
		line.y2 = vertices[i + 1].getY() + posY;

		if (i == 3)
		{
			line.x2 = (vertices[0].getX() + posX) * aspectRatio;
			line.y2 = vertices[0].getY() + posY;
		}

		Assignment::AssignmentApp::DrawLine(line);
	}
};

// Triangle
Triangle::Triangle(float b, float h) : Shape(), base(b), height(h)
{
	colour.g = 1.0f; // Triangle is cyan

	rotation = Matrix2D::rotationMatrix(1);

	vertices[0] = Vector2D(-base / 2, -height / 2);
	vertices[1] = Vector2D(base / 2, -height / 2);
	vertices[2] = Vector2D(0, height / 2);
};

void Triangle::updatePosition(Vector2D newPos)
{
	position = position + newPos;
};

void Triangle::updatePosition(float x, float y)
{
	position = position + Vector2D(x, y);
}

void Triangle::rotateShape()
{
	//Vector2D rot;
	//for (Vector2D &v : vertices)
	//{
	//	rot = Vector2D(v.getX(), v.getY());
	//	v = rotation * rot;
	//}
};

void Triangle::drawShape()
{
	float posX = position.getX();
	float posY = position.getY();

	Assignment::AssignmentApp::LineData line;
	line.c1 = colour;
	line.c2 = colour;

	for (int i = 0; i < 3; i++)
	{
		line.x1 = (vertices[i].getX() + posX) * aspectRatio;
		line.y1 = vertices[i].getY() + posY;
		line.x2 = (vertices[i + 1].getX() + posX) * aspectRatio;
		line.y2 = vertices[i + 1].getY() + posY;

		if (i == 2)
		{
			line.x2 = (vertices[0].getX() + posX) * aspectRatio;
			line.y2 = vertices[0].getY() + posY;
		}

		Assignment::AssignmentApp::DrawLine(line);
	}
}

// Circle
Circle::Circle(float rad) : Shape(), radius(rad)
{
	colour.r = 1.0f; // circle is yellow
	colour.g = 1.0f;
	colour.b = 0.0f;

	rotation = Matrix2D::rotationMatrix(0);

	roundness = 1000;
};

void Circle::updatePosition(Vector2D newPos)
{
	position = position + newPos;
};

void Circle::updatePosition(float x, float y)
{
	position = position + Vector2D(x, y);
}

void Circle::rotateShape()
{
	position = rotation * position;
};

void Circle::drawShape()
{
	float posX = position.getX();
	float posY = position.getY();

	Assignment::AssignmentApp::LineData line;
	line.c1 = colour;
	line.c2 = colour;

	for (int i = 0; i < roundness; i++)
	{
		line.x1 = (radius * cosf(i * 2 * M_PI / roundness) + posX) * aspectRatio;
		line.y1 = radius * sinf(i * 2 * M_PI / roundness) + posY;

		line.x2 = (radius * cosf((i + 1) * 2 * M_PI / roundness) + posX) * aspectRatio;
		line.y2 = radius * sinf((i + 1) * 2 * M_PI / roundness) + posY;

		Assignment::AssignmentApp::DrawLine(line);
	}
}