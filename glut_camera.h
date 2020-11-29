#pragma once

#include <GL/freeglut.h>
#include "position.h"
#include "non_positive_zoom_factor.h"

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
			const Data::Position<float>& getForward() const;
			/**
			 * @brief Set the forward direction of this Camera.
			 * @param dir The new float Data:Position forward vector of this Camera.
			 * @note The given vector is automatically normalised.
			 */
			void setForward(Data::Position<float> dir);
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
			/**
			 * @brief Calculate the normalised right vector of this Camera.
			 * @return The float Data::Position normalised right vector of this Camera.
			 */
			const Data::Position<float> calcRight() const;
			/**
			 * @brief Move this Camera rightward by the given distance.
			 * @param dist The float distance to move this Camera rightward.
			 */
			void dollyRight(float dist);
			/**
			 * @brief Move this Camera forward by the given distance.
			 * @param dist The float distance to move this Camera forward.
			 */
			void truckForward(float dist);
			/**
			 * @brief Move this Camera upward by the given distance.
			 * @param dist The float distance to move this Camera upward.
			 */
			void boomUp(float dist);
			/**
			 * @brief Rotate this Camera around its up vector by the given angle.
			 * @param angle The float angle to rotate this Camera by in radians.
			 */
			void panRight(float angle);
			/**
			 * @brief Rotate this Camera around its right vector by the given angle.
			 * @param angle The float angle to rotate this Camera by in radians.
			 */
			void tiltUp(float angle);
			/**
			 * @brief Rotate this Camera around its forward vector by the given angle.
			 * @param angle The float angle to rotate this Camera by in radians.
			 */
			void rollCCW(float angle);
			/**
			 * @brief Multiply the zoom factor of this Camera.
			 * @param factor
			 */
			void zoomIn(float factor);
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
			/**
			 * @brief The factor by which this Camera is zoomed.
			 */
			float zoom;
		};
	}
}