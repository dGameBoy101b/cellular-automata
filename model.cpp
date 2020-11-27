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

	for (std::vector<Position<float>>::iterator it = this->vertices.begin();
		it != this->vertices.end(); it++)
	{
		it->setX(it->getX() - center.getX());
		it->setY(it->getY() - center.getY());
		it->setZ(it->getZ() - center.getZ());
	}

	const float radius = this->calcRadius();

	for (std::vector<Position<float>>::iterator it = this->vertices.begin();
		it != this->vertices.end(); it++)
	{
		it->setX(it->getX() / radius);
		it->setY(it->getY() / radius);
		it->setZ(it->getZ() / radius);
	}
}

const Data::Position<float> Data::Model::calcCenter() const
{
	Data::Position<float> center = Data::Position<float>();

	for (std::vector<Position<float>>::const_iterator it = this->vertices.begin();
		it != this->vertices.end(); it++)
	{
		center.setX(center.getX() + it->getX());
		center.setY(center.getY() + it->getY());
		center.setZ(center.getZ() + it->getZ());
	}

	center.setX(center.getX() / this->vertices.size());
	center.setY(center.getY() / this->vertices.size());
	center.setZ(center.getZ() / this->vertices.size());
	return center;
}

const float Data::Model::calcRadius() const
{
	const Data::Position<float> center = this->calcCenter();
	float radius = 0;
	float dist = 0;

	for (std::vector<Data::Position<float>>::const_iterator it = this->vertices.begin();
		it != this->vertices.end(); it++)
	{
		dist = sqrt((it->getX() - center.getX()) * (it->getX() - center.getX())
			+ (it->getY() - center.getY()) * (it->getY() - center.getY())
			+ (it->getZ() - center.getZ()) * (it->getZ() - center.getZ()));
		if (dist > radius)
		{
			radius = dist;
		}
	}

	return radius;
}
