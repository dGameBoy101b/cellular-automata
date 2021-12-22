#include "keyboard_event_tests.hpp"
#include "Testing/assertion.hpp"
#include <ctime>
#include "Source/SDL/Events/keyboard_event.hpp"
#include "Source/SDL/Events/quit_event.hpp"

using namespace CellularAutomata::SDL::Events;

const std::map<std::string, std::function<void()>> Tests::SDL::Events::KEYBOARD_EVENT_TESTS = {
	{
		"SDL::Events::KeyboardEvent Initialiser Constructor",
		[]{
			const SDL_Keycode KEY = SDLK_HOME;
			const bool IS_DOWN = true;
			const uint32_t BEFORE = std::time(nullptr);
			KeyboardEvent test = {KEY, IS_DOWN};
			const uint32_t AFTER = std::time(nullptr);
			TestFramework::assertEqual(test.getType(), IS_DOWN ? SDL_KEYDOWN : SDL_KEYUP);
			TestFramework::assertRange(test.getTimestamp(), BEFORE, AFTER);
			TestFramework::assertEqual(test.getKey(), KEY);
			TestFramework::assertEqual(test.isDown(), IS_DOWN);
			TestFramework::assertEqual(test.getModifiers(), (uint16_t)0);
			TestFramework::assertEqual(test.isRepeat(), false);
		}
	},
	{
		"SDL::Events::KeyboardEvent Wrapper Constructor",
		[]{
			const SDL_Keysym KEYSYM = {
				.scancode = SDL_SCANCODE_SPACE,
				.sym = SDLK_SPACE,
				.mod = KMOD_LSHIFT | KMOD_LCTRL
			};
			SDL_KeyboardEvent EVENT = {
				.type = SDL_KEYUP,
				.timestamp = (uint32_t)std::time(nullptr),
				.windowID = 0,
				.state = SDL_PRESSED,
				.repeat = 0
			};
			EVENT.keysym = KEYSYM;
			KeyboardEvent test = {EVENT};
			TestFramework::assertEqual(test.getType(), (SDL_EventType)EVENT.type);
			TestFramework::assertEqual(test.getTimestamp(), EVENT.timestamp);
			TestFramework::assertEqual(test.getKey(), EVENT.keysym.sym);
			TestFramework::assertEqual(test.getModifiers(), EVENT.keysym.mod);
			TestFramework::assertEqual(test.isRepeat(), EVENT.repeat > 0);
			TestFramework::assertEqual(test.isDown(), EVENT.type == SDL_KEYDOWN);
		}
	},
	{
		"SDL::Events::KeyboardEvent Conversion Constructor",
		[]{
			const KeyboardEvent KEY_EVENT = {SDLK_j, false};
			KeyboardEvent test = {Event(KEY_EVENT)};
			TestFramework::assertEqual(test.getType(), KEY_EVENT.isDown() ? SDL_KEYDOWN : SDL_KEYUP);
			TestFramework::assertEqual(test.getTimestamp(), KEY_EVENT.getTimestamp());
			TestFramework::assertEqual(test.getKey(), KEY_EVENT.getKey());
			TestFramework::assertEqual(test.getModifiers(), KEY_EVENT.getModifiers());
			TestFramework::assertEqual(test.isRepeat(), KEY_EVENT.isRepeat());
			TestFramework::assertEqual(test.isDown(), KEY_EVENT.isDown());
		}
	},
	{
		"SDL::Events::KeyboardEvent Conversion Constructor Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{
				KeyboardEvent(Event(QuitEvent().getEvent()));
			});
		}
	},
	{
		"SDL::Events::KeyboardEvent Equals Comparison",
		[]{
			const SDL_Keycode KEY = SDLK_y;
			const bool IS_DOWN = false;
			const uint16_t MODIFIERS = KMOD_LSHIFT;
			const bool IS_REPEAT = true;
			TestFramework::assertEqual(KeyboardEvent(KEY, IS_DOWN, MODIFIERS, IS_REPEAT), KeyboardEvent(KEY, IS_DOWN, MODIFIERS, IS_REPEAT));
		}
	},
	{
		"SDL::Events::KeyboardEvent Not Equals Comparision",
		[]{
			const SDL_Keycode KEY = SDLK_f;
			const bool IS_DOWN = true;
			const uint16_t MODIFIERS = KMOD_RSHIFT | KMOD_LALT;
			const bool IS_REPEAT = true;
			TestFramework::assertNotEqual(KeyboardEvent(KEY, IS_DOWN, MODIFIERS, IS_REPEAT), KeyboardEvent(KEY, !IS_DOWN, MODIFIERS, IS_REPEAT));
			TestFramework::assertNotEqual(KeyboardEvent(KEY, IS_DOWN, MODIFIERS, IS_REPEAT), KeyboardEvent(KEY, IS_DOWN, MODIFIERS, !IS_REPEAT));
			TestFramework::assertNotEqual(KeyboardEvent(KEY, IS_DOWN, MODIFIERS, IS_REPEAT), KeyboardEvent(KEY, IS_DOWN, 0, IS_REPEAT));
			TestFramework::assertNotEqual(KeyboardEvent(KEY, IS_DOWN, MODIFIERS, IS_REPEAT), KeyboardEvent(SDLK_INSERT, IS_DOWN, MODIFIERS, IS_REPEAT));
		}
	}
};
