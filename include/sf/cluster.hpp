#ifndef SHITFEST_CLUSTER_HPP
#define SHITFEST_CLUSTER_HPP 1

#include "identity.hpp"

#include "robin_hood.h"

namespace sf{
	class ClusterPermissions{
		public:
			ClusterPermissions() noexcept
				: admin(false)
				, moderate(false)
				, read(true)
				, write(true)
				, voip(true)
				, vid(true)
			{}

			bool admin: 1;
			bool moderate: 1;
			bool read: 1;
			bool write: 1;
			bool voip: 1;
			bool vid: 1;
	};

	class ClusterRole{
		public:
			ClusterRole(Identity id_): m_id(std::move(id_)){}

			const Identity &id() const noexcept{ return m_id; }

		private:
			Identity m_id;
	};

	class ClusterGroup{
		public:

		private:
			robin_hood::unordered_map<Identity, ClusterPermissions> m_perms;
			robin_hood::unordered_set<Identity> m_users;
	};

	class Cluster{
		public:
			Cluster(Identity id_)
				: m_id(std::move(id_)){}

		private:
			Identity m_id;
			robin_hood::unordered_map<Identity, ClusterRole> m_roles;
			robin_hood::unordered_set<Identity> m_joined;
	};
}

#endif // !SHITFEST_CLUSTER_HPP
