#pragma once

#include <string>
#include <GL/freeglut.h>
#include "glut_special_keys.h"
#include "glut_mouse_buttons.h"
#include "glut_button_states.h"
#include "glut_visibility_states.h"
#include "glut_mouse_entry_states.h"
#include "window_already_created.h"
#include "window_already_destroyed.h"
#include "non_positive_size.h"
#include "no_display_callback.h"
#include "invalid_parent_id.h"

namespace Display
{
	namespace FreeGlut
	{
		class Window
		{
		public:
			/**
			 * @brief Default constructor.
			 * 
			 */
			Window();
			/**
			 * @brief Create this Window in glut.
			 * 
			 * @throw WindowAlreadyCreated This Window already exists in glut.
			 * @throw NoDisplayCallback This Window has no display callback set.
			 */
			void createWindow();
			/**
			 * @brief Create this Window in glut as a child of another window.
			 * 
			 * @param parent_id The integer id of the glut window to parent this one to.
			 * @param x The x position of this Window in pixels relative to the parent window.
			 * @param y The y position of this Window in pixels relative to the parent window.
			 * @param width The width of this Window in pixels relative.
			 * @param height The height of this Window in pixels relative.
			 * @throw WindowAlreadyCreated This Window already exists in glut.
			 * @throw NoDisplayCallback This Window has no display callback set.
			 * @throw InvalidParentID The given parent id is invalid.
			 * @note The dimensions set for this Window are ingnored in favour for the given parameters 
			 * but are updated to be the true dimensions after the sub window creatation succeeds.
			 */
			void createSubWindow(int parent_id, int x, int y, int width, int height);
			/**
			 * @brief Destroy this Window in glut.
			 * 
			 * @throw WindowAlreadyDestroyed This Window already does not exist in glut.
			 */
			void destroyWindow();
			/**
			 * @brief Destructor.
			 * 
			 */
			~Window();
			/**
			 * @brief Test if this Window exists.
			 * 
			 * @return True if this Window has been created in glut, false otherwise.
			 */
			bool exists() const;
			/**
			 * @brief Get the id of this Window.
			 * 
			 * @return The integer id of this Window.
			 */
			int getId() const;
			/**
			 * @brief Get the x position of this Window.
			 * 
			 * @return The integer x position of this Window in pixels.
			 */
			int getXPos() const;
			/**
			 * @brief Set the x position of this Window.
			 * 
			 * @param x The new integer x position of this Window in pixels.
			 */
			void setXPos(int x);
			/**
			 * @brief Get the y position of this Window.
			 * 
			 * @return The integer y position of this Window in pixels.
			 */
			int getYPos() const;
			/**
			 * @brief Set the y position of this Window.
			 * 
			 * @param y The new integer y position of this Window in pixels.
			 */
			void setYPos(int y);
			/**
			 * @brief Get the width of this Window.
			 * 
			 * @return The integer width of this Window in pixels.
			 */
			int getWidth() const;
			/**
			 * @brief Set the width of this Window.
			 * 
			 * @param width The new integer width of this Window in pixels.
			 */
			void setWidth(int width);
			/**
			 * @brief Get the height of this Window.
			 * 
			 * @return The integer height of this Window in pixels
			 */
			int getHeight() const;
			/**
			 * @brief Set the height of this Window.
			 * 
			 * @param height The new integer height of this Window in pixels.
			 */
			void setHeight(int height);
			/**
			 * @brief Get the title of this Window.
			 * 
			 * @return The string title of this Window.
			 */
			const std::string getTitle() const;
			/**
			 * @brief Set the title of this Window.
			 * 
			 * @param title The new string title of this Window.
			 */
			void setTitle(const std::string title);
			/**
			 * @brief Get the function used when this Window is closed.
			 * 
			 * @return The function pointer to the close function of this Window.
			 */
			void (*getCloseFunc() const)();
			/**
			 * @brief Set the close function of this Window.
			 * 
			 * @param func The pointer to the new close function of this Window.
			 */
			void setCloseFunc(void(*func)());
			/**
			 * @brief Get the function used when this Window is displayed.
			 * 
			 * @return The function pointer to the display function of this Window.
			 */
			void (*getDisplayFunc() const)();
			/**
			 * @brief Set the display function of this Window.
			 * 
			 * @param func The pointer to the new display function of this Window.
			 * @throw NoDisplayCallback The display function cannot be set to null.
			 * @note The display function is required before creating this Window.
			 */
			void setDisplayFunc(void(*func)());
			/**
			 * @brief Get the function used continuously for this Window.
			 * 
			 * @return The function pointer to the idle function of this Window.
			 */
			void (*getIdleFunc() const)();
			/**
			 * @brief Set the idle function of this Window.
			 * 
			 * @param func The pointer to the new display function of this Window.
			 */
			void setIdleFunc(void(*func)());
			/**
			 * @brief Get the function used when this Window is reshaped.
			 * 
			 * @return The function pointer to the reshape function of this Window.
			 */
			void (*getReshapeFunc() const)(int, int);
			/**
			 * @brief Set the reshape function of this Window.
			 * 
			 * @param func The pointer to the new reshape function for this Window.
			 */
			void setReshapeFunc(void(*func)(int, int));
			/**
			 * @brief Get the function used when a character key is pressed.
			 * 
			 * @return The function pointer to the character keyboard press function of this Window.
			 */
			void (*getCharKeyboardDownFunc() const)(unsigned char, int, int);
			/**
			 * @brief Set the character key press function of this Window.
			 * 
			 * @param func The function pointer to the new character keyboard press function for this Window.
			 */
			void setCharKeyboardDownFunc(void(*func)(unsigned char, int, int));
			/**
			 * @brief Get the function used when a non-character key is pressed.
			 * 
			 * @return The function pointer to the special keyboard press function for this Window.
			 */
			void (*getSpecialKeyboardDownFunc() const)(SpecialKeys, int, int);
			/**
			 * @brief Set the special key press function of this Window.
			 * 
			 * @param func The pointer to the new special key press function for this Window.
			 */
			void setSpecialKeyboardDownFunc(void(*func)(SpecialKeys, int, int));
			/**
			 * @brief Get the function used when a mouse button is used.
			 * 
			 * @return The function pointer to the mouse button function for this Window.
			 */
			void (*getMouseButtonFunc() const)(MouseButton, ButtonState, int, int);
			/**
			 * @brief Set the mouse button function of this Window.
			 * 
			 * @param func The function pointer to the new mouse button function for this Window.
			 */
			void setMouseButtonFunc(void(*func)(MouseButton, ButtonState, int, int));
			/**
			 * @brief Get the function used when the mouse moves while a mouse button is held.
			 * 
			 * @return The function pointer to the mouse button motion function for this Window.
			 */
			void (*getMouseButtonMotionFunc() const)(int, int);
			/**
			 * @brief Set the mouse button motion function for this Window.
			 * 
			 * @param func The function pointer to the mouse button motion function for this Window.
			 */
			void setMouseButtonMotionFunc(void(*func)(int, int));
			/**
			 * @brief Get the function used when the mouse moves.
			 * 
			 * @return The function pointer to the mouse motion function for this Window.
			 */
			void (*getMouseMotionFunc() const)(int, int);
			/**
			 * @brief Set the mouse motion function of this Window.
			 * 
			 * @param func The function pointer to the new mouse motion function for this Window.
			 */
			void setMouseMotionFunc(void(*func)(int, int));
		protected:
			/**
			 * @brief The function called when the window needs to be displayed.
			 * @note This is the only required function.
			 */
			void (*displayFunc)();
			/**
			 * @brief The function called when the window is reshaped.
			 */
			void (*reshapeFunc)(int, int);
			/**
			 * @brief The function called continuously.
			 */
			void (*idleFunc)();
			/**
			 * @brief The function called when the window is closed.
			 */
			void (*closeFunc)();
			/**
			 * @brief The function called when a character keyboard key is pressed..
			 */
			void (*charKeyboardDownFunc)(unsigned char, int, int);
			/**
			 * @brief The function called when a non-character keyboard key is pressed.
			 */
			void (*specialKeyboardDownFunc)(SpecialKeys, int, int);
			/**
			 * @brief The function called when a character keyboard key is released.
			 */
			void (*charKeyboardUpFunc)(unsigned char, int, int);
			/**
			 * @brief The function called when a non-character keyboard key is released.
			 */
			void (*specialKeyboardUpFunc)(SpecialKeys, int, int);
			/**
			 * @brief The function called when a mouse button is pressed or released.
			 */
			void (*mouseButtonFunc)(MouseButton, ButtonState, int, int);
			/**
			 * @brief The function called when the ouse is moved with any mouse buttons held.
			 */
			void (*mouseButtonMotionFunc)(int, int);
			/**
			 * @brief The function called when the mouse is moved without any mouse buttons held.
			 */
			void (*mouseMotionFunc)(int, int);
			/**
			 * @brief The function called when this Window changes visibility.
			 */
			void (*visibilityFunc)(VisibilityState);
			/**
			 * @brief The function called when the mouse enters or leaves the window bounds.
			 */
			void (*mouseEntryFunc)(MouseEntryState);
			/**
			 * @brief The title of this Window.
			 */
			std::string title;
		private:
			/**
			 * @brief The glut identifier of this Window.
			 * @note Zero if this Window is not currently registered.
			 */
			int id;
			/**
			 * @brief The x position of this Window.
			 * @note Negative for any position.
			 */
			int x;
			/**
			 * @brief The y position of this Window.
			 * @note Negative for any position.
			 */
			int y;
			/**
			 * @brief The positive width of this Window.
			 */
			int width;
			/**
			 * @brief The positive height of this Window.
			 */
			int height;
			/**
			 * @brief Set all the glut callback functions to the functions in this Window.
			 */
			void setCallbacks();
			/**
			 * @brief Get the current dimensions of the currently active glut window and store it in this Window.
			 * 
			 */
			void getDimensions();
			/**
			 * @brief Set the initial glut window dimensions to the dimensions of this Window.
			 * 
			 */
			void setDimensions();
		};
	}
}