#include "model.h"
#include "glut_model.h"

Data::Model::Model()
{
	this->vertices = std::vector<Position<float>>();
	this->faces = std::vector<std::vector<std::vector<Position<float>>::size_type>>();
}

const std::vector<Data::Position<float>>& Data::Model::getVerticies() const
{
	return this->vertices;
}

void Data::Model::addVertex(const Position<float>& vert)
{
	this->vertices.push_back(vert);
}

const std::vector<std::vector<std::vector<Data::Position<float>>::size_type>>& Data::Model::getFaces() const
{
	return this->faces;
}

void Data::Model::addFace(const std::vector<std::vector<Position<float>>::size_type>& face)
{
	if (face.size() < 3)
	{
		throw Exceptions::TooFewVerticesInFace();
	}
	for (std::vector<std::vector<Position<float>>::size_type>::const_iterator it = face.begin(); 
		it != face.end(); it++)
	{
		if (*it > this->vertices.size()
			|| *it < 0)
		{
			throw Exceptions::VertexIndexOutOfRange();
		}
	}

	this->faces.push_back(face);
}

std::vector<Data::Position<float>>::size_type Data::Model::getNumVertices() const
{
	return this->vertices.size();
}

std::vector<std::vector<std::vector<Data::Position<float>>::size_type>>::size_type Data::Model::getNumFaces() const
{
	return this->faces.size();
}

void Data::Model::normalise()
{
	const Position<float> center = this->calcCenter();
	float radius;
	float rad;

	for (std::vector<Position<float>>::iterator it = this->vertices.begin();
		it != this->vertices.end(); it++)
	{
		*it -= center;
	}

	radius = this->calcXRadius();
	rad = this->calcYRadius();
	if (rad > radius)
	{
		radius = rad;
	}
	rad = this->calcZRadius();
	if (rad > radius)
	{
		radius = rad;
	}

	for (std::vector<Position<float>>::iterator it = this->vertices.begin();
		it != this->vertices.end(); it++)
	{
		*it /= radius;
	}
}

const Data::Position<float> Data::Model::calcCenter() const
{
	Data::Position<float> center = Data::Position<float>();

	for (std::vector<Position<float>>::const_iterator it = this->vertices.begin();
		it != this->vertices.end(); it++)
	{
		center += *it;
	}

	return center / (float)this->vertices.size();
}

const float Data::Model::calcXRadius() const
{
	const Data::Position<float> center = this->calcCenter();
	float radius = 0;
	float dist = 0;

	for (std::vector<Data::Position<float>>::const_iterator it = this->vertices.begin();
		it != this->vertices.end(); it++)
	{
		dist = abs(it->getX() - center.getX());
		if (dist > radius)
		{
			radius = dist;
		}
	}

	return radius;
}

const float Data::Model::calcYRadius() const
{
	const Data::Position<float> center = this->calcCenter();
	float radius = 0;
	float dist = 0;

	for (std::vector<Data::Position<float>>::const_iterator it = this->vertices.begin();
		it != this->vertices.end(); it++)
	{
		dist = abs(it->getY() - center.getY());
		if (dist > radius)
		{
			radius = dist;
		}
	}

	return radius;
}

const float Data::Model::calcZRadius() const
{
	const Data::Position<float> center = this->calcCenter();
	float radius = 0;
	float dist = 0;

	for (std::vector<Data::Position<float>>::const_iterator it = this->vertices.begin();
		it != this->vertices.end(); it++)
	{
		dist = abs(it->getZ() - center.getZ());
		if (dist > radius)
		{
			radius = dist;
		}
	}

	return radius;
}