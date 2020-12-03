#pragma once

#include <GL/freeglut.h>
#include "model.h"
#include "glut_display_list.h"

namespace Display
{
	namespace FreeGlut
	{
		class Model
		{
		public:
			/**
			 * @brief Default constructor.
			 */
			Model();
			/**
			 * @brief Model initialise constructor.
			 * 
			 * @param model The underlying Data::Model of this Model.
			 */
			Model(const Data::Model& model);
			/**
			 * @brief Get the underlying Data::Model of this Model.
			 * 
			 * @return The underlying Data::Model of this Model.
			 */
			const Data::Model& getModel() const;
			/**
			 * @brief Set the underlying Data::Model of this Model.
			 * 
			 * @param model The new underlying Data::Model of this Model.
			 */
			void setModel(const Data::Model& model);
			/**
			 * @brief Get the wireframe DisplayList of this Model.
			 * @return The DisplayList for the wireframe of this Model.
			 */
			const DisplayList* const getWireframeDisplayList() const;
			/**
			 * @brief Get the solid DisplayList of this Model.
			 * @return The DisplayList for the solid of this Model.
			 */
			const DisplayList* const getSolidDisplayList() const;
			/**
			 * @brief Create the wireframe display list for this Model in glut.
			 */
			void createWireframeDisplayList();
			/**
			 * @brief Create the solid display list for this Model in glut.
			 */
			void createSolidDisplayList();
			/**
			 * @brief Destroy the wireframe DisplayList of this Model.
			 */
			void destoryWireFrameDisplayList();
			/**
			 * @brief Destroy the solid DisplayList of this Model.
			 */
			void destorySolidDisplayList();
		private:
			/**
			 * @brief The underlying Data::Model.
			 */
			Data::Model model;
			/**
			 * @brief The wireframe DisplayList.
			 */
			Display::FreeGlut::DisplayList* wireframe_displaylist;
			/**
			 * @brief The solid DisplayList.
			 */
			Display::FreeGlut::DisplayList* solid_displaylist;
		};
	}
}
