#include "mouse_wheel_event_tests.hpp"
#include "Testing/assertion.hpp"
#include <ctime>
#include "Source/SDL/Events/mouse_wheel_event.hpp"
#include "Source/SDL/Events/quit_event.hpp"

using namespace CellularAutomata::Data;
using namespace CellularAutomata::SDL::Events;

const std::map<std::string, std::function<void()>> Tests::SDL::Events::MOUSE_WHEEL_EVENT_TESTS = {
	{
		"SDL::Events::MouseWheelEvent Initialiser Constructor",
		[]{
			const Position<int32_t> VELOCITY = {-394, 4992};
			const bool IS_TOUCH = false;
			const bool IS_FLIPPED = true;
			const uint32_t BEFORE = std::time(nullptr);
			MouseWheelEvent test = {VELOCITY, IS_TOUCH, IS_FLIPPED};
			const uint32_t AFTER = std::time(nullptr);
			TestFramework::assertEqual(test.getType(), SDL_MOUSEWHEEL);
			TestFramework::assertRange(test.getTimestamp(), BEFORE, AFTER);
			TestFramework::assertEqual(test.getVelocity(), VELOCITY * (IS_FLIPPED ? -1 : 1));
			TestFramework::assertEqual(test.isTouch(), IS_TOUCH);
			TestFramework::assertEqual(test.isFlipped(), IS_FLIPPED);
		}
	},
	{
		"SDL::Events::MouseWheelEvent Wrapper Constructor",
		[]{
			const SDL_MouseWheelEvent EVENT = {
				.type = SDL_MOUSEWHEEL,
				.timestamp = (uint32_t)std::time(nullptr),
				.windowID = 0,
				.which = SDL_TOUCH_MOUSEID,
				.x = 4891,
				.y = -3892,
				.direction = SDL_MOUSEWHEEL_NORMAL
			};
			MouseWheelEvent test = {EVENT};
			TestFramework::assertEqual(test.getType(), (SDL_EventType)EVENT.type);
			TestFramework::assertEqual(test.getTimestamp(), EVENT.timestamp);
			TestFramework::assertEqual(test.getVelocity(), Position<int32_t>(EVENT.x, EVENT.y));
			TestFramework::assertEqual(test.isTouch(), EVENT.which  == SDL_TOUCH_MOUSEID);
			TestFramework::assertEqual(test.isFlipped(), EVENT.direction == SDL_MOUSEWHEEL_FLIPPED);
		}
	},
	{
		"SDL::Events::MouseWheelEvent Conversion Constructor",
		[]{
			const MouseWheelEvent EVENT = {Position<int32_t>(3782, -3892)};
			MouseWheelEvent test = {Event(EVENT)};
			TestFramework::assertEqual(test.getType(), EVENT.getType());
			TestFramework::assertEqual(test.getTimestamp(), EVENT.getTimestamp());
			TestFramework::assertEqual(test.getVelocity(), EVENT.getVelocity());
			TestFramework::assertEqual(test.isTouch(), EVENT.isTouch());
			TestFramework::assertEqual(test.isFlipped(), EVENT.isFlipped());
		}
	},
	{
		"SDL::Events::MouseWheelEvent Conversion Constructor Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{
				MouseWheelEvent(Event(QuitEvent().getEvent()));
			});
		}
	},
	{
		"SDL::Events::MouseWheelEvent Equals Comparison",
		[]{
			const Position<int32_t> VELOCITY = {49803, -3903};
			TestFramework::assertEqual(MouseWheelEvent(VELOCITY), MouseWheelEvent(VELOCITY));
			TestFramework::assertEqual(MouseWheelEvent(VELOCITY), MouseWheelEvent(-VELOCITY, false, true));
		}
	},
	{
		"SDL::Events::MouseWheelEvent Not Equals Comparison",
		[]{
			const Position<int32_t> VELOCITY = {49803, -3903};
			TestFramework::assertNotEqual(MouseWheelEvent(VELOCITY), MouseWheelEvent(Position<int32_t>()));
			TestFramework::assertNotEqual(MouseWheelEvent(VELOCITY), MouseWheelEvent(VELOCITY, false, true));
		}
	}
};
