#include "window_tests.hpp"
#include "Testing/assertion.hpp"
#include "Source/SDL/Video/window.hpp"
#include "SDL2/SDL.h"
#include <vector>

using namespace CellularAutomata::SDL::Video;
using namespace CellularAutomata::Data;

const std::map<std::string, std::function<void()>> Tests::SDL::Video::WINDOW_TESTS = {
	{
		"SDL::Video::Window Default Constructor",
		[]{
			Window test = {};
			TestFramework::assertEqual(test.doesExist(), false);
		}
	},
	{
		"SDL::Video::Window Creation",
		[]{
			const Position<int> SIZE = {690, 50};
			const std::string TITLE = "Test Window II";
			const Position<int> POS = {40, 120};
			const std::vector<SDL_WindowFlags> FLAG_LIST = {
				SDL_WINDOW_ALWAYS_ON_TOP,
				SDL_WINDOW_INPUT_FOCUS
			};
			uint32_t FLAGS = 0u;
			for (auto it = FLAG_LIST.cbegin(); it != FLAG_LIST.cend(); ++it)
			{
				FLAGS |= *it;
			}
			Window test;
			SDL_Init(SDL_INIT_VIDEO);
			test.create(SIZE, TITLE, POS, FLAGS);
			TestFramework::assertEqual(test.doesExist(), true);
			TestFramework::assertEqual(test.getSize(), SIZE);
			TestFramework::assertEqual(test.getTitle(), TITLE);
			TestFramework::assertEqual(test.getPosition(), POS);
			SDL_Quit();
		}
	},
	{
		"SDL::Video::Window Creation Constructor",
		[]{
			const Position<int> SIZE = {400, 300};
			const std::string TITLE = "Test Window";
			const Position<int> POS = {SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_CENTERED};
			const uint32_t FLAGS = 0u;
			SDL_Init(SDL_INIT_VIDEO);
			Window test = {SIZE, TITLE, POS, FLAGS};
			TestFramework::assertEqual(test.doesExist(), true);
			TestFramework::assertEqual(test.getSize(), SIZE);
			TestFramework::assertEqual(test.getTitle(), TITLE);
			SDL_Quit();
		}
	},
	{
		"SDL::Video::Window Flash",
		[]{
			SDL_Init(SDL_INIT_VIDEO);
			Window test = {{900, 300}, "Flash Test"};
			test.flashOnce();
			test.startFlashing();
			test.stopFlashing();
			SDL_Quit();
		}
	},
	{
		"SDL::Video::Window Title Setter",
		[]{
			const std::string TITLE = "Title Set Test";
			SDL_Init(SDL_INIT_VIDEO);
			Window test = {{300, 300}};
			test.setTitle(TITLE);
			TestFramework::assertEqual(test.getTitle(), TITLE);
			SDL_Quit();
		}
	},
	{
		"SDL::Video::Window Position Setter",
		[]{
			const Position<int> POS = {340, 23};
			SDL_Init(SDL_INIT_VIDEO);
			Window test = {{890, 340}, "Position Set Test"};
			test.setPosition(POS);
			TestFramework::assertEqual(test.getPosition(), POS);
			SDL_Quit();
		}
	},
	{
		"SDL::Video::Window Size Setter",
		[]{
			const Position<int> SIZE = {420, 169};
			SDL_Init(SDL_INIT_VIDEO);
			Window test = {{0, 0}, "Size Set Test"};
			test.setSize(SIZE);
			TestFramework::assertEqual(test.getSize(), SIZE);
			SDL_Quit();
		}
	},
	{
		"SDL::Video::Window Size Bounds Setter",
		[]{
			const Bounds<Position<int>> BOUNDS = {{200, 100}, {1000, 500}};
			SDL_Init(SDL_INIT_VIDEO);
			Window test = {{0, 0}, "Size Bounds Set Test"};
			test.setSizeBounds(BOUNDS);
			TestFramework::assertEqual(test.getSizeBounds(), BOUNDS);
		}
	},
	{
		"SDL::Video::Window Opacity Setter",
		[]{
			const float OPACITY = .5;
			SDL_Init(SDL_INIT_VIDEO);
			Window test = {{300, 300}, "Opacity Set Test"};
			test.setOpacity(OPACITY);
			TestFramework::assertEqual(test.getOpacity(), OPACITY);
			SDL_Quit();
		}
	},
	{
		"SDL::Video::Window Opacity Setter Invalid",
		[]{
			SDL_Init(SDL_INIT_VIDEO);
			Window test = {{300, 300}, "Opacity Invalid Test"};
			TestFramework::assertError<std::invalid_argument>([&test]{ test.setOpacity(-1); });
			TestFramework::assertError<std::invalid_argument>([&test]{ test.setOpacity(2); });
			SDL_Quit();
		}
	},
	{
		"SDL::Video::Window Display Manipulators",
		[]{
			SDL_Init(SDL_INIT_VIDEO);
			Window test = {{300, 300}, "Manipulate Test"};
			test.hide();
			test.show();
			test.minimise();
			test.maximise();
			test.restore();
			test.raise();
			SDL_Quit();
		}
	},
	{
		"SDL::Video::Window Fullscreen",
		[]{
			SDL_Init(SDL_INIT_VIDEO);
			Window test = {{300, 300}, "Fullscreen Test"};
			test.enterFullscreen(true);
			TestFramework::assertEqual(test.isFullscreen(), true);
			test.exitFullscreen();
			TestFramework::assertEqual(test.isFullscreen(), false);
			test.toggleFullscreen();
			TestFramework::assertEqual(test.isFullscreen(), true);
			test.toggleFullscreen();
			TestFramework::assertEqual(test.isFullscreen(), false);
			SDL_Quit();
		}
	},
	{
		"SDL::Video::Window Input Grabbing",
		[]{
			SDL_Init(SDL_INIT_VIDEO);
			Window test = {{300, 300}, "Input Grab Test"};
			TestFramework::assertEqual(test.hasGrabbedMouse(), false);
			TestFramework::assertEqual(test.hasGrabbedKeyboard(), false);
			test.grabMouse();
			TestFramework::assertEqual(test.hasGrabbedMouse(), true);
			test.releaseMouse();
			TestFramework::assertEqual(test.hasGrabbedMouse(), false);
			test.grabKeyboard();
			TestFramework::assertEqual(test.hasGrabbedKeyboard(), true);
			test.releaseKeyboard();
			TestFramework::assertEqual(test.hasGrabbedKeyboard(), false);
			SDL_Quit();
		}
	},
	{
		"SDL::Video::Window Border Changing",
		[]{
			SDL_Init(SDL_INIT_VIDEO);
			Window test = {{300, 300}, "Border Change Test"};
			TestFramework::assertEqual(test.hasBorder(), true);
			test.removeBorder();
			TestFramework::assertEqual(test.hasBorder(), false);
			test.addBorder();
			TestFramework::assertEqual(test.hasBorder(), true);
			SDL_Quit();
		}
	},
	{
		"SDL::Video::Window Resizing",
		[]{
            SDL_Init(SDL_INIT_VIDEO);
            Window test = {{300, 300}, "Window Resizing Test"};
            TestFramework::assertEqual(test.isResizable(), false);
            test.enableResizing();
            TestFramework::assertEqual(test.isResizable(), true);
            test.disableResizing();
            TestFramework::assertEqual(test.isResizable(), false);
            SDL_Quit();
		}
	}
};
