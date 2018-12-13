//------------------------------------------------------------------------------
// assignmentapp.cc
// (C) 2015-2017 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "config.h"
#include "../../vstudio/Shape.h"

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
	// create your own objects 

}

//------------------------------------------------------------------------------
/**
*/
void
AssignmentApp::Update()
{
	Triangle triangle(3, 4);
	triangle.updatePosition(-0.3f, -0.3f);
	triangle.drawShape();

	Square square(0.3f);
	square.updatePosition(0.3f, 0.5f);
	square.drawShape();

	Circle circle(0.1f);
	circle.updatePosition(-0.4f, 0.7f);
	circle.drawShape();


	
	// demo line drawing code
	/*
	LineData line;
	line.x1 = -0.3f;
	line.y1 = -0.3f;
	line.x2 = 0.0f;
	line.y2 = 0.5f;
	line.c1.r = 1.0f;
	AssignmentApp::DrawLine(line);	
	line.x1 = 0.0f;
	line.y1 = 0.5f;
	line.x2 = 0.3f;
	line.y2 = -0.3f;	
	AssignmentApp::DrawLine(line);	
	line.x1 = 0.3f;
	line.y1 = -0.3f;
	line.x2 = -0.3f;
	line.y2 = -0.3f;
	AssignmentApp::DrawLine(line);	
	AssignmentApp::PrintText("triangle", 0.5f, 0.5f);
	*/
}

} // namespace Assignment
