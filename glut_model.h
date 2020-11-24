#pragma once

#include <GL/freeglut.h>
#include "model.h"
#include "display_list_already_destroyed.h"
#include "display_list_not_exist.h"
#include "display_list_already_created.h"

namespace Display
{
	namespace FreeGlut
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
			 * @brief Test if the wireframe display list for this Model exists in glut.
			 * 
			 * @return True if the wireframe has been registered in glut, flase otherwise.
			 */
			bool wireframeDisplayListExists() const;
			/**
			 * @brief Test if the solid display list for this Model exists in glut.
			 * 
			 * @return True if the solid has been registered in glut, false otherwise.
			 */
			bool solidDisplayListExists() const;
			/**
			 * @brief Create the wireframe display list for this Model in glut.
			 * 
			 * @throw Exceptions::DisplayListAlreadyCreated The wireframe display list already exists.
			 */
			void createWireframeDisplayList();
			/**
			 * @brief Destroy the wireframe displaylist for this Model in glut.
			 * 
			 * @throw Exceptions::DisplayListAlreadyDestroyed The wireframe display list already does not exist.
			 */
			void destroyWireframeDisplayList();
			/**
			 * @brief Create the solid display list for this Model in glut.
			 * 
			 * @throw Exceptions::DisplayListAlreadyCreated The solid display list already exists.
			 */
			void createSolidDisplayList();
			/**
			 * @brief Destory the solid display list for this Model in glut.
			 * 
			 * @throw Exceptions::DisplayListAlreadyDestroyed The solid display list already does not exist.
			 */
			void destroySolidDisplayList();
			/**
			 * @brief Draw the wireframe display list for this Model.
			 * 
			 * @throw Exceptins::DisplayListNotExist The solid display list does not exist.
			 */
			void drawWireframe() const;
			/**
			 * @brief Draw the solid display list for this Model.
			 * 
			 * @throw Exceptions::DisplayListNotExist The wireframe display list does not exist.
			 */
			void drawSolid() const;
			/**
			 * @brief Destructor.
			 * 
			 */
			~Model();
		private:
			/**
			 * @brief The underlying Data::Model.
			 */
			Data::Model model;
			/**
			 * @brief The wireframe display list id.
			 * @note Zero if no display list exists.
			 */
			int wireframe_id;
			/**
			 * @brief The solid display list id.
			 * @note Zero if no display list exists.
			 */
			int solid_id;
		};
	}
}
