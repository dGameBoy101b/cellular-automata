#include "mouse_motion_event_tests.hpp"
#include "Testing/assertion.hpp"
#include "Source/SDL/Events/mouse_motion_event.hpp"
#include "Source/Data/position.hpp"
#include <ctime>
#include "Source/SDL/Events/quit_event.hpp"

using namespace CellularAutomata::SDL::Events;
using namespace CellularAutomata::Data;

const std::map<std::string, std::function<void()>> Tests::SDL::Events::MOUSE_MOTION_EVENT_TESTS = {
	{
		"SDL::Events::MouseMotionEvent Initialiser Constructor",
		[]{
			const Position<int32_t> POS = {493, -347};
			const Position<int32_t> VEL = {-4, 87};
			const bool IS_TOUCH = false;
			const uint32_t BEFORE = std::time(nullptr);
			MouseMotionEvent test = {POS, VEL, IS_TOUCH};
			const uint32_t AFTER = std::time(nullptr);
			TestFramework::assertEqual(test.getType(), SDL_MOUSEMOTION);
			TestFramework::assertRange(test.getTimestamp(), BEFORE, AFTER);
			TestFramework::assertEqual(test.getPosition(), POS);
			TestFramework::assertEqual(test.getVelocity(), VEL);
			TestFramework::assertEqual(test.isTouch(), IS_TOUCH);
		}
	},
	{
		"SDL::Events::MouseMotionEvent Wrapper Constructor",
		[]{
			const SDL_MouseMotionEvent EVENT = {
				.type = SDL_MOUSEMOTION,
				.timestamp = (uint32_t) std::time(nullptr),
				.windowID = SDL_GetWindowID(SDL_GetMouseFocus()),
				.which = !SDL_TOUCH_MOUSEID,
				.state = SDL_PRESSED,
				.x = 239,
				.y = -42,
				.xrel = -23,
				.yrel = 99
			};
			MouseMotionEvent test = {EVENT};
			TestFramework::assertEqual(test.getType(), (SDL_EventType)EVENT.type);
			TestFramework::assertEqual(test.getTimestamp(), EVENT.timestamp);
			TestFramework::assertEqual(test.getPosition(), Position<int32_t>(EVENT.x, EVENT.y));
			TestFramework::assertEqual(test.getVelocity(), Position<int32_t>(EVENT.xrel, EVENT.yrel));
			TestFramework::assertEqual(test.isTouch(), EVENT.which == SDL_TOUCH_MOUSEID);
		}
	},
	{
		"SDL::Events::MouseMotionEvent Conversion Constructor",
		[]{
			const MouseMotionEvent EVENT = {{4893, 49}, {-45, -8}};
			MouseMotionEvent test = Event(EVENT.getEvent());
			TestFramework::assertEqual(test.getType(), (SDL_EventType)EVENT.getType());
			TestFramework::assertEqual(test.getTimestamp(), EVENT.getTimestamp());
			TestFramework::assertEqual(test.getPosition(), EVENT.getPosition());
			TestFramework::assertEqual(test.getVelocity(), EVENT.getVelocity());
			TestFramework::assertEqual(test.isTouch(), EVENT.isTouch());
		}
	},
	{
		"SDL::Events::MouseMotionEvent Conversion Constructor Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{
				MouseMotionEvent(Event(QuitEvent().getEvent()));
			});
		}
	},
	{
		"SDL::Events::MouseMotionEvent Equals Comparison",
		[]{
			const Position<int32_t> POS = {299, -43};
			const Position<int32_t> VEL = {72, 9};
			TestFramework::assertEqual(MouseMotionEvent(POS, VEL), MouseMotionEvent(POS, VEL));
			TestFramework::assertEqual(MouseMotionEvent(POS, VEL, true), MouseMotionEvent(POS, VEL, false));
		}
	},
	{
		"SDL::Events::MouseMotionEvent Not Equals Comparison",
		[]{
			const Position<int32_t> POS = {-8433, 45};
			const Position<int32_t> VEL = {0, -45};
			TestFramework::assertNotEqual(MouseMotionEvent(POS, VEL), MouseMotionEvent(POS + Position<int32_t>(1), VEL));
			TestFramework::assertNotEqual(MouseMotionEvent(POS, VEL), MouseMotionEvent(POS, VEL + Position<int32_t>(1)));
		}
	}
};
