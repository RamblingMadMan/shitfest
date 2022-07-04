#ifndef SHITFEST_IDENTITY_HPP
#define SHITFEST_IDENTITY_HPP 1

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_hash.hpp>

#include <string>
#include <utility>

namespace sf{
	class Identity{
		public:
			Identity(boost::uuids::uuid id_, std::string name_) noexcept
				: m_id(id_)
				, m_name(std::move(name_)){}

			bool operator==(const Identity &other) const noexcept{
				return m_id == other.m_id;
			}

			bool operator!=(const Identity &other) const noexcept{
				return m_id != other.m_id;
			}

			bool operator<(const Identity &other) const noexcept{
				return m_id < other.m_id;
			}

			boost::uuids::uuid id() const noexcept{ return m_id; }
			const std::string &name() const noexcept{ return m_name; }

			std::size_t hash() const noexcept{ return boost::uuids::hash_value(m_id); }

			void setId(boost::uuids::uuid newId) noexcept{ m_id = newId; }
			void setName(std::string newName) noexcept{ m_name = std::move(newName); }

		private:
			boost::uuids::uuid m_id;
			std::string m_name;
	};
}

template<>
struct std::hash<sf::Identity>{
	public:
		std::size_t operator()(const sf::Identity &id){ return id.hash(); }
};

#endif // !SHITFEST_IDENTITY_HPP
