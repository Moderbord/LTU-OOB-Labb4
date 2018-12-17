//------------------------------------------------------------------------------
// assignmentapp.cc
// (C) 2015-2017 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "config.h"
#include "assignmentapp.h"

namespace Assignment
{

//------------------------------------------------------------------------------
/**
*/
AssignmentApp::AssignmentApp()
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
AssignmentApp::~AssignmentApp()
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
void 
AssignmentApp::Setup()
{

	Shape* square = new Square(0.5f);
	renderQueue.push_back(square);
}

//------------------------------------------------------------------------------
/**
*/
void
AssignmentApp::Update()
{
	renderQueue[0]->updatePosition(0.001f, 0.001f);

	for (auto s : renderQueue)
	{
		s->drawShape();
	}
}

} // namespace Assignment




// Shape
Shape::~Shape() {
	delete this;
}

// Square
Square::Square(float dim) : Shape(), dimension(dim)
{
	colour.r = 1.0f; // Sqaure is magenta

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

void Square::rotate(float x)
{

};

void Square::drawShape()
{
	float posX = position.getX();
	float posY = position.getY();

	Assignment::AssignmentApp::LineData line;
	line.x1 = -dimension + posX;
	line.y1 = -dimension + posY;
	line.x2 = dimension + posX;
	line.y2 = -dimension + posY;
	Assignment::AssignmentApp::DrawLine(line);

	line.x1 = dimension + posX;
	line.y1 = -dimension + posY;
	line.x2 = dimension + posX;
	line.y2 = dimension + posY;
	Assignment::AssignmentApp::DrawLine(line);

	line.x1 = dimension + posX;
	line.y1 = dimension + posY;
	line.x2 = -dimension + posX;
	line.y2 = dimension + posY;
	Assignment::AssignmentApp::DrawLine(line);

	line.x1 = -dimension + posX;
	line.y1 = dimension + posY;
	line.x2 = -dimension + posX;
	line.y2 = -dimension + posY;
	Assignment::AssignmentApp::DrawLine(line);
};