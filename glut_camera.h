#pragma once

#include <GL/freeglut.h>
#include "position.h"

namespace Display
{
	namespace FreeGlut
	{
		class Camera
		{
		public:
			/**
			 * @brief The default constructor.
			 */
			Camera();
			/**
			 * @brief Get the position of this Camera.
			 * @return The float Data::Position position of this Camera.
			 */
			const Data::Position<float>& getPos() const;
			/**
			 * @brief Set the position of this Camera.
			 * @param pos The new float Data::Position position of this Camera.
			 */
			void setPos(const Data::Position<float>& pos);
			/**
			 * @brief Get the forward direction of this Camera.
			 * @return The normalised float Data::Position forward vector of this Camera.
			 */
			const Data::Position<float>& getDir() const;
			/**
			 * @brief Set the forward direction of this Camera.
			 * @param dir The new float Data:Position forward vector of this Camera.
			 * @note The given vector is automatically normalised.
			 */
			void setDir(Data::Position<float> dir);
			/**
			 * @brief Get the up direction of this Camera.
			 * @return The float Data::Position up vector of this Camera.
			 */
			const Data::Position<float>& getUp() const;
			/**
			 * @brief Set the up direction of this Camera.
			 * @param up The new float Data::Position up vector of this Camera.
			 * @note the given vector is automatically normalised.
			 */
			void setUp(Data::Position<float> up);
			/**
			 * @brief Apply the camera transformations to the glut matrices.
			 */
			void draw() const;
		private:
			/**
			 * @brief The position of this Camera.
			 */
			Data::Position<float> pos;
			/**
			 * @brief The normalised forward vector of this camera.
			 */
			Data::Position<float> dir;
			/**
			 * @brief The normalised up vector of this Camera.
			 */
			Data::Position<float> up;
		};
	}
}