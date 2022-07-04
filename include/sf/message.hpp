#ifndef SHITFEST_MESSAGE_HPP
#define SHITFEST_MESSAGE_HPP 1

#include "identity.hpp"

#include <string>

namespace sf{
	class Message{
		public:
			Message(
				Identity from_, Identity to_,
				std::string text_
			) noexcept
				: m_from(std::move(from_))
				, m_to(std::move(to_))
				, m_text(std::move(text_))
			{}

			const Identity &from() const noexcept{ return m_from; }
			const Identity &to() const noexcept{ return m_to; }
			const std::string &text() const noexcept{ return m_text; }

			void setText(std::string newText) noexcept{ m_text = std::move(newText); }

		private:
			Identity m_from, m_to;
			std::string m_text;
	};
}

#endif // !SHITFEST_MESSAGE_HPP
