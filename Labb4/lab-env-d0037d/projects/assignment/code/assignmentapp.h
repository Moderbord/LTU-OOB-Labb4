//------------------------------------------------------------------------------
/**
	Application class used for Assignment applications.
	Based on 2D app
	
	(C) 2015-2017 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "core/app.h"
#include "render/window.h"
#include "2d/2dapp.h"
#include "Matrix2D.h"
#include "Vector2D.h"
#include <vector>

class cColour
{
public:
	float r, g, b;
	cColour() : r(0.0f), g(0.0f), b(1.0f){};
};

class Shape
{
protected:
	Vector2D position;
	Matrix2D rotation;
	cColour colour;
public:
	virtual ~Shape();
	virtual void updatePosition(Vector2D newPos) = 0;
	virtual void updatePosition(float x, float y) = 0;
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
	void drawShape();
};


namespace Assignment
{
class AssignmentApp : public App2D::BaseApp
{
public:

	std::vector<Shape*> renderQueue;

	static AssignmentApp& GetInstance()
	{
		static AssignmentApp instance;
		return instance;
	}

	/// destructor
	~AssignmentApp();

	/// initialize, create shapes etc
	void Setup();

	/// update app, draw lines etc
	void Update();

	/// line drawing function
	static void DrawLine(const LineData & line);

private:
	/// constructor hidden because it is a singleton
	AssignmentApp();
	/// also hidden because of the singleton
	AssignmentApp(AssignmentApp const &);
	/// also hidden because of the singleton
	void operator=(AssignmentApp const &);

};

//------------------------------------------------------------------------------
/**
*/
inline void 
AssignmentApp::DrawLine( const LineData & line )
{
	AssignmentApp::GetInstance().AddLine(line);
}
} // namespace Assignment