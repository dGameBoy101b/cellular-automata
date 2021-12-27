#pragma once
#include <string>
#include "SDL2/SDL_video.h"
#include "../../Data/position.hpp"
#include "../../Data/bounds_position.hpp"

namespace CellularAutomata
{
	namespace SDL
	{
		namespace Video
		{
			class Window
			{
			public:
				/** Wrapper constructor
				\param window The window to wrap
				*/
				Window(SDL_Window* window = nullptr);
				/** Lookup constructor
				\param id The window id to lookup
				\throw std::invalid_argument A window with the given id does not exist
				*/
				Window(uint32_t id);
				/** Calls SDL_CreateWindow to construct a window
				\param size The requested window width and height
				\param title The title of the new window (defaults to empty)
				\param position The requested window position (defaults to SDL_WINDOWPOS_UNDEFINED)
				\param flags The flags to use for this window (defaults to 0)
				*/
				Window(const CellularAutomata::Data::Position<int>& size, const std::string& title = "", const CellularAutomata::Data::Position<int>& position = {SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED}, const uint32_t& flags = 0u);
				/** Calls SDL_DestroyWindow if necessary */
				~Window();
				/** Calls SDL_CreateWindow to create a window
				\param size The requested window width and height
				\param title The title of the new window (defaults to empty)
				\param position The requested window position (defaults to SDL_WINDOWPOS_UNDEFINED)
				\param flags The flags to use for this window (defaults to 0)
				\throw std::domain_error The window already exists
				\throw std::runtime_error Failed to create the window
				*/
				void create(const CellularAutomata::Data::Position<int>& size, const std::string& title = "", const CellularAutomata::Data::Position<int>& position = {SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED}, const uint32_t& flags = 0u);
				/** Destroy this window
				\throw std::domain_error The window does not exist
				*/
				void destroy();
				/** Wrapped window getter
				\return Pointer to the window this wraps
				\note Provided only for compatability purposes; best to use other methods
				*/
				SDL_Window* getWindow() const;
				/** Check if the window exists
				\return True when the window does exist
				\return False when the window does not exist
				*/
				bool doesExist() const;
				/** Check if the window has the given flag set
				\return True when the given flag is set for the window
				\return False when the given flag is not set for the window
				\throw std::domain_error The window does not exist
				*/
				bool hasFlag(const SDL_WindowFlags& flag) const;
				/** ID getter
				\return The id of this window
				\throw std::domain_error The window does not exist
				\throw std::runtime_error Failed to fetch window id
				*/
				uint32_t getID() const;
				/** Flash the window once to get the user's attention
				\throw std::domain_error The window does not exist
				\throw std::runtime_error The flash operation could not be done
				*/
				void flashOnce();
				/** Keep flashing the window to get the user's attention until it gains focus or Window::stopFlashing() is called
				\throw std::domain_error The window does not exist
				\throw std::runtime_error The flash operation could not be done
				*/
				void startFlashing();
				/** Stop flashing window after Window::startFlashing() had been called
				\throw std::domain_error The window does not exist
				\throw std::runtime_error The flash operation could not be done
				*/
				void stopFlashing();
				/** Title getter
				\return The title of this window
				\throw std::domain_error The window does not exist
				*/
				std::string getTitle() const;
				/** Title setter
				\param title The new title
				\throw std::domain_error The window does not exist
				*/
				void setTitle(const std::string& title);
				/** Position getter
				\return The x and y position of the window in screen coordinates
				\throw std::domain_error The window does not exist
				*/
				CellularAutomata::Data::Position<int> getPosition() const;
				/** Position setter
				\param position The new position
				\throw std::domain_error The window does not exist
				*/
				void setPosition(const CellularAutomata::Data::Position<int>& position);
				/** Size getter
				\return the width and height of the window in screen coordinates
				\throw std::domain_error The window does not exist
				*/
				CellularAutomata::Data::Position<int> getSize() const;
				/** Size setter
				\param size The new size
				\throw std::domain_error The window does not exist
				*/
				void setSize(const CellularAutomata::Data::Position<int>& size);
				/** Size bounds getter
				\return The bounds for the size of this window in pixels
				\throw std::domain_error The window does not exist
				*/
				CellularAutomata::Data::Bounds<CellularAutomata::Data::Position<int>> getSizeBounds() const;
				/** Size bounds setter
				\param bounds The new size bounds
				\throw std::runtiem_error The window does not exist
				*/
				void setSizeBounds(const CellularAutomata::Data::Bounds<CellularAutomata::Data::Position<int>>& bounds);
				/** Opacity getter
				\return The opacity of the window
				\throw std::domain_error The window does not exist
				\throw std::runtime_error Failed to fetch the window opacity
				*/
				float getOpacity() const;
				/** Opacity setter
				\param opacity The new opacity between 0 (transparent) and 1 (opaque)
				\throw std::domain_error The window does not exist
				\throw std::invalid_argument The given opacity is not within range
				\throw std::runtime_error Failed to set the window opacity
				*/
				void setOpacity(const float& opacity);
				/** Hide the window
				\throw std::domain_error The window does not exist
				*/
				void hide();
				/** Show the window
				\throw std::domain_error The window does not exist
				*/
				void show();
				/** Raise the window above others and take focus
				\throw std::domain_error The window does not exist
				*/
				void raise();
				/** Make the window as large as possible
				\throw std::domain_error The window does not exist
				*/
				void maximise();
				/** Minimise the window into icon form
				\throw std::domain_error The window does not exist
				*/
				void minimise();
				/** Restore the size and position of the window after calling Window::maximise() or Window::minimise()
				\throw std::domain_error The window does not exist
				*/
				void restore();
				/** Check if the window is fullscreen
				\return True when the window is fullscreen
				\return False when the window is not fullscreen
				\throw std::domain_error The window does not exist
				*/
				bool isFullscreen() const;
				/** Enter fullscreen mode
				\param use_true Whether true fullscreen should be used (defaults to false)
				\throw std::domain_error The window does not exist
				\throw std::runtime_error Failed to set fullscreen mode
				*/
				void enterFullscreen(const bool use_true = false);
				/** Exit fullscreen mode
				\throw std::domain_error The window does not exist
				\throw std::runtime_error Failed to set fullscreen mode
				*/
				void exitFullscreen();
				/** Toggle fullscreen mode
				\throw std::domain_error The window does not exist
				\throw std::runtime_error Failed to set fullscreen mode
				*/
				void toggleFullscreen();
				/** Check if the window has grabbed the mouse
				\return True when the mouse is constrained to the window
				\return False when the mouse is not constrained to the window
				\throw std::domain_error The window does not exist
				*/
				bool hasGrabbedMouse() const;
				/** Grab the mouse and constrain it to this window
				\throw std::domain_error The window does not exist
				*/
				void grabMouse();
				/** Release the mouse from the constraints of this window
				\throw std::domain_error The window does not exist
				*/
				void releaseMouse();
				/** Check if the window has grabbed the keyboard
				\return True when the keyboard is constrained to the window
				\return False when the keyboard is not constrained to the window
				\throw std::domain_error The window does not exist
				*/
				bool hasGrabbedKeyboard() const;
				/** Grab the keyboard and constrain it to this window
				\throw std::domain_error The window does not exist
				*/
				void grabKeyboard();
				/** Release the keyboard from the constraints of this window
				\throw std::domain_error The window does not exist
				*/
				void releaseKeyboard();
				/** Check if the window has a border decoration around it
				\return True when the window has a border
				\return False when the window is borderless
				\throw std::domain_error The window does not exist
				*/
				bool hasBorder() const;
				/** Add the border decoration to the window
				\throw std::domain_error The window does not exist
				*/
				void addBorder();
				/** Remove the border decoration from the window
				\throw std::domain_error The window does not exist
				*/
				void removeBorder();
				/** Check if the window can be resized
				\return True when the window can be resized
				\return False when the window cannot be resized
				\throw std::domain_error The window does not exist
				*/
				bool isResizable() const;
				/** Allow the window to be resized
				\throw std::domain_error The window does not exist
				*/
				void enableResizing();
				/** Stop allowing the window to be resized
				\throw std::domain_error The window does not exist
				*/
				void disableResizing();
				/** Equals comparison
				\param other The other window to compare with
				\return True when the given window refers to the same window
				\return False when the given window refers to a different window
				*/
				bool operator==(const Window& other) const;
				/** Not equals comparison
				\param other The other window to compare with
				\return True when the given window refers to a different window
				\return False when the given window refers to the same window
				*/
				bool operator!=(const Window& other) const;
			private:
				/** The SDL window this wraps */
				SDL_Window* window;
				/** Throw an error if the window does not exist
				\throw std::domain_error The window does not exist
				*/
				inline void existCheck() const;
			};
		}
	}
}
/** Window stream insertion
\param output The output stream to insert into
\param window The window to insert
\return The given output stream
*/
std::ostream& operator<<(std::ostream& output, const CellularAutomata::SDL::Video::Window& window);
