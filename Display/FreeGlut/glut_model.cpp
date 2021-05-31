#include "glut_model.h"

Display::FreeGlut::Model::Model()
{
	this->model = Data::Model();
	this->wireframe_displaylist = nullptr;
	this->solid_displaylist = nullptr;
}

Display::FreeGlut::Model::Model(const Data::Model& model)
{
	this->model = model;
	this->wireframe_displaylist = nullptr;
	this->solid_displaylist = nullptr;
}

const Data::Model& Display::FreeGlut::Model::getModel() const
{
	return this->model;
}

void Display::FreeGlut::Model::setModel(const Data::Model& model)
{
	this->model = model;
}

const Display::FreeGlut::DisplayList* const Display::FreeGlut::Model::getWireframeDisplayList() const
{
	return this->wireframe_displaylist;
}

const Display::FreeGlut::DisplayList* const Display::FreeGlut::Model::getSolidDisplayList() const
{
	return this->solid_displaylist;
}

void Display::FreeGlut::Model::createSolidDisplayList()
{
	Data::Position<float> pos;

	*(this->solid_displaylist) = DisplayList();
	glNewList(this->solid_displaylist->getId(), GL_COMPILE);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	for (std::vector<std::vector<std::vector<Data::Position<float>>::size_type>>::const_iterator it = this->model.getFaces().begin();
		it != this->model.getFaces().end(); it++)
	{
		glBegin(GL_POLYGON);
		for (std::vector<std::vector<Data::Position<float>>::size_type>::const_iterator v_it = it->begin();
			v_it != it->end(); v_it++)
		{
			pos = this->model.getVerticies().at(*v_it);
			glVertex3f(pos.getX(), pos.getY(), pos.getZ());
		}
		glEnd();
	}

	glPopMatrix();
	glEndList();
}

void Display::FreeGlut::Model::destoryWireFrameDisplayList()
{
	if (this->wireframe_displaylist != nullptr)
	{
		this->wireframe_displaylist->~DisplayList();
		this->wireframe_displaylist = nullptr;
	}
}

void Display::FreeGlut::Model::destorySolidDisplayList()
{
	if (this->solid_displaylist != nullptr)
	{
		this->solid_displaylist->~DisplayList();
		this->solid_displaylist = nullptr;
	}
}

void Display::FreeGlut::Model::createWireframeDisplayList()
{
	Data::Position<float> pos;

	*(this->wireframe_displaylist) = DisplayList();
	glNewList(this->wireframe_displaylist->getId(), GL_COMPILE);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	for (std::vector<std::vector<std::vector<Data::Position<float>>::size_type>>::const_iterator it = this->model.getFaces().begin();
		it != this->model.getFaces().end(); it++)
	{
		glBegin(GL_LINE_LOOP);
		for (std::vector<std::vector<Data::Position<float>>::size_type>::const_iterator v_it = it->begin();
			v_it != it->end(); v_it++)
		{
			pos = this->model.getVerticies().at(*v_it);
			glVertex3f(pos.getX(), pos.getY(), pos.getZ());
		}
		glEnd();
	}

	glPopMatrix();
	glEndList();
}
