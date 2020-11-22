#pragma once

#include <vector>
#include <stdexcept>
#include <cmath>
#include "too_few_vertices_in_face.h"
#include "position.h"

namespace Data
{
	class Model
	{
	public:
		/**
		 * @brief Default constructor.
		 * 
		 */
		Model();
		/**
		 * @brief Get the list of verticies.
		 * 
		 * @return The vector list of Positions of the vertices of this Model.
		 */
		const std::vector<Position<float>>& getVerticies() const;
		/**
		 * @brief Add a vertex to this Model.
		 * 
		 * @param vert The Position of the new vertex to add to this Model.
		 */
		void addVertex(const Position<float>& vert);
		/**
		 * @brief Get the list of faces of this Model.
		 * 
		 * @return The list of faces of this Model which contain indicies for the verticies of this Model.
		 */
		const std::vector<std::vector<std::vector<Position<float>>::size_type>>& getFaces() const;
		/**
		 * @brief Add a face to this Model.
		 * 
		 * @param face The list of vertex indicies that comprise the additional face.
		 */
		void addFace(const std::vector<std::vector<Position<float>>::size_type>& face);
		/**
		 * @brief Get the number of vertices in this Model.
		 * 
		 * @return The number of vertices in this Model.
		 */
		const std::vector<Position<float>>::size_type& getNumVertices() const;
		/**
		 * @brief Get the number of faces in this Model.
		 * 
		 * @return The number of faces in this Model.
		 */
		const std::vector<std::vector<std::vector<Position<float>>::size_type>>::size_type& getNumFaces() const;
		/**
		 * @brief Normalise this Model to center on the origin and fit within a 2 unit cube.
		 * 
		 */
		void normalise();
	private:
		/**
		 * @brief The list of vertices.
		 */
		std::vector<Position<float>> vertices;
		/**
		 * @brief The list of faces, which are a list of vertex indices included in the face.
		 */
		std::vector<std::vector<std::vector<Position<float>>::size_type>> faces;
		/**
		 * @brief Calculate the center point of this Model.
		 * 
		 * @return The float Position of the center point of this Model.
		 */
		const Position<float> calcCenter() const;
		/**
		 * @brief Calculate the radius of this Model.
		 * 
		 * @return The float radius of this Model.
		 */
		const float calcRadius() const;
	};
}