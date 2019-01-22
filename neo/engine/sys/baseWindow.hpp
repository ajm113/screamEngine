#ifndef BASE_WINDOW_HPP
#define BASE_WINDOW_HPP

/*
	baseWindow.hpp
	Use this class as a foundation for any external GUI APIs. e.g: Win32, QT, GTK4, etc you wish to use. This permits Scream engine to run on different platforms with very little refactoring. yayy OOP!
*/

#include <string>
#include <map>

#define KEYS_MAP_SIZE 256
#define MOUSE_MAP_SIZE 5

namespace scream {

	// Holds anything todo w/ our window context.
	struct ButtonState {
		bool m_clickDown = false;
		bool m_clickUp = false;
		bool m_held = false;
	};
	

	enum KeyCode {
		A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
		K0, K1, K2, K3, K4, K5, K6, K7, K8, K9,
		F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
		UP, DOWN, LEFT, RIGHT,
		SPACE, TAB, SHIFT, CTRL, INS, DEL, HOME, END, PGUP, PGDN,
		BACK, ESCAPE, RETURN, ENTER, PAUSE, SCROLL,
		NP0, NP1, NP2, NP3, NP4, NP5, NP6, NP7, NP8, NP9,
		NP_MUL, NP_DIV, NP_ADD, NP_SUB, NP_DECIMAL
	};

	class BaseWindow {
		public:
		virtual ~BaseWindow() {}
		// Window specific creation.
		virtual bool Create(const std::string &, const uint32_t, const uint32_t, const bool) { return false; }
		virtual bool Destroy() { return false; }
		virtual void HandleEvents() {}

		// Window specific API calls.
		virtual ButtonState GetMouse(uint32_t) { ButtonState s; return s; }
		virtual int32_t GetMouseX() { return 0; }
		virtual int32_t GetMouseY() { return 0; }
		virtual ButtonState GetKey(KeyCode) { ButtonState s; return s; }

		bool isFocused() { return m_focused; }

		protected:
		bool m_focused;

		// Hardware specific state.
		bool m_keyNewState[KEYS_MAP_SIZE]{ false };
		bool m_keyOldState[KEYS_MAP_SIZE]{ false };
		ButtonState m_keyboardState[KEYS_MAP_SIZE];

		std::map<uint16_t, uint8_t> m_mapKeys;

		bool m_mouseNewState[MOUSE_MAP_SIZE]{ false };
		bool m_mouseOldState[MOUSE_MAP_SIZE]{ false };
		ButtonState m_mouseState[MOUSE_MAP_SIZE];
	};
};


#endif
