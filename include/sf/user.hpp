#ifndef SHITFEST_USER_HPP
#define SHITFEST_USER_HPP 1

#include "identity.hpp"

#include <boost/date_time.hpp>

#include <string>

namespace sf{
	class User{
		public:
			User(Identity id_, boost::posix_time::ptime created_, std::string name_, std::string email_, std::string pass_) noexcept
				: m_id(std::move(id_))
				, m_created(created_)
				, m_name(std::move(name_))
				, m_email(std::move(email_))
				, m_pass(std::move(pass_))
			{}

			const Identity &identity() const noexcept{ return m_id; }
			boost::posix_time::ptime created() const noexcept{ return m_created; }
			const std::string &name() const noexcept{ return m_name; }
			const std::string &email() const noexcept{ return m_email; }
			const std::string &pass() const noexcept{ return m_pass; }

		private:
			Identity m_id;
			boost::posix_time::ptime m_created;
			std::string m_name, m_email, m_pass;
	};
}

#endif // !SHITFEST_USER_HPP
