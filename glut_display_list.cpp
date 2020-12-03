#include "glut_display_list.h"

Display::FreeGlut::DisplayList::DisplayList()
{
	this->id = glGenLists(1);
}

Display::FreeGlut::DisplayList::~DisplayList()
{
	glDeleteLists(this->id, 1);
}

void Display::FreeGlut::DisplayList::draw() const
{
	glCallList(this->id);
}

unsigned int Display::FreeGlut::DisplayList::getId() const
{
	return this->id;
}
