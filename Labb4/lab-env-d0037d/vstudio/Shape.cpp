//#include "../../projects/assignment/code/assignmentapp.h"
//
//
//
//Square::Square(float dim) : Shape(), dimension(dim)
//{
//	colour.r = 1.0f; // Sqaure is magenta
//};
//
//void Square::updatePosition(Vector2D newPos)
//{
//	position = newPos;
//};
//
//void Square::updatePosition(float x, float y)
//{
//	position = Vector2D(x, y);
//};
//
//void Square::drawShape()
//{
//	float posX = position.getX();
//	float posY = position.getY();
//
//	Assignment::AssignmentApp::LineData line;
//	line.x1 = -dimension + posX;
//	line.y1 = -dimension + posY;
//	line.x2 = dimension + posX;
//	line.y2 = -dimension + posY;
//	Assignment::AssignmentApp::DrawLine(line);
//
//	line.x1 = dimension + posX;
//	line.y1 = -dimension + posY;
//	line.x2 = dimension + posX;
//	line.y2 = dimension + posY;
//	Assignment::AssignmentApp::DrawLine(line);
//
//	line.x1 = dimension + posX;
//	line.y1 = dimension + posY;
//	line.x2 = -dimension + posX;
//	line.y2 = dimension + posY;
//	Assignment::AssignmentApp::DrawLine(line);
//
//	line.x1 = -dimension + posX;
//	line.y1 = dimension + posY;
//	line.x2 = -dimension + posX;
//	line.y2 = -dimension + posY;
//	Assignment::AssignmentApp::DrawLine(line);
//};