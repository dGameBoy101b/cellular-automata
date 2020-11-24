#include "glut_model.h"

Display::FreeGlut::Model::Model()
{
	this->model = Data::Model();
	this->wireframe_id = 0;
	this->solid_id = 0;
}

Display::FreeGlut::Model::Model(const Data::Model& model)
{
	this->model = model;
	this->wireframe_id = 0;
	this->solid_id = 0;
}

const Data::Model& Display::FreeGlut::Model::getModel() const
{
	return this->model;
}

void Display::FreeGlut::Model::setModel(const Data::Model& model)
{
	this->model = model;
}

bool Display::FreeGlut::Model::wireframeDisplayListExists() const
{
	return this->wireframe_id > 0
		&& glIsList(this->wireframe_id);
}

bool Display::FreeGlut::Model::solidDisplayListExists() const
{
	return this->solid_id > 0
		&& glIsList(this->solid_id);
}

void Display::FreeGlut::Model::destroyWireframeDisplayList()
{
	if (!this->wireframeDisplayListExists())
	{
		throw Exceptions::DisplayListAlreadyDestroyed();
	}

	glDeleteLists(this->wireframe_id, 1);
	this->wireframe_id = 0;
}

void Display::FreeGlut::Model::destroySolidDisplayList()
{
	if (!this->solidDisplayListExists())
	{
		throw Exceptions::DisplayListAlreadyDestroyed();
	}

	glDeleteLists(this->solid_id, 1);
	this->solid_id = 0;
}

void Display::FreeGlut::Model::drawWireframe() const
{
	if (!this->wireframeDisplayListExists())
	{
		throw Exceptions::DisplayListNotExist();
	}

	glCallList(this->wireframe_id);
}

void Display::FreeGlut::Model::drawSolid() const
{
	if (!this->solidDisplayListExists())
	{
		throw Exceptions::DisplayListNotExist();
	}

	glCallList(this->solid_id);
}

void Display::FreeGlut::Model::createSolidDisplayList()
{
	Data::Position<float> pos;

	if (this->solidDisplayListExists())
	{
		throw Exceptions::DisplayListAlreadyCreated();
	}

	this->solid_id = glGenLists(1);
	glNewList(this->solid_id, GL_COMPILE);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	for (std::vector<std::vector<std::vector<Data::Position<float>>::size_type>>::const_iterator it = this->model.getFaces().begin();
		it != this->model.getFaces().end(); it++)
	{
		glBegin(GL_TRIANGLE_STRIP);
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

void Display::FreeGlut::Model::createWireframeDisplayList()
{
	Data::Position<float> pos;

	if (this->wireframeDisplayListExists())
	{
		throw Exceptions::DisplayListAlreadyCreated();
	}

	this->wireframe_id = glGenLists(1);
	glNewList(this->wireframe_id, GL_COMPILE);
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

Display::FreeGlut::Model::~Model()
{
	if (this->wireframeDisplayListExists())
	{
		this->destroyWireframeDisplayList();
	}
	if (this->solidDisplayListExists())
	{
		this->destroySolidDisplayList();
	}
}