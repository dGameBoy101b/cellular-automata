#pragma once

#include <GL/freeglut.h>

namespace Display
{
	namespace FreeGlut
	{
		class DisplayList
		{
		public:
			/**
			 * @brief Default constructor.
			 */
			DisplayList();
			/**
			 * @brief Destructor.
			 */
			~DisplayList();
			/**
			 * @brief Draw this glut DisplayList.
			 */
			void draw() const;
			/**
			 * @brief Get the id of this DisplayList.
			 * @return The unsigned integer id of this DisplayList in glut.
			 */
			unsigned int getId() const;
		private:
			/**
			 * @brief The id of this DisplayList in glut.
			 */
			unsigned int id = 0;
		};
	}
}