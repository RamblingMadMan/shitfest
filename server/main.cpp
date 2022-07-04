#include "sf/cluster.hpp"
#include "sf/identity.hpp"
#include "sf/user.hpp"

#include <boost/asio.hpp>
#include <boost/asio/bind_executor.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/read_until.hpp>
#include <boost/asio/steady_timer.hpp>
#include <boost/asio/streambuf.hpp>
#include <boost/optional/optional.hpp>
#include <boost/thread.hpp>
#include <boost/bind/bind.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/optional.hpp>

#include "fmt/printf.h"

#include "robin_hood.h"

#include <string_view>

namespace asio = boost::asio;
namespace ip = boost::asio::ip;

class Directory{
	public:
		robin_hood::unordered_map<sf::Identity, sf::User> users;
		robin_hood::unordered_map<sf::Identity, sf::Cluster> clusters;
};

class Connection{
	public:
		Connection(ip::tcp::socket sock_)
			: m_sock(std::move(sock_)){}

		auto remoteEndpoint() const noexcept{ return m_sock.remote_endpoint(); }
		auto localEndpoint() const noexcept{ return m_sock.local_endpoint(); }

		std::string read(){
			asio::streambuf buf;
			asio::read_until(m_sock, buf, "\n");
			return asio::buffer_cast<const char*>(buf.data());
		}

		void send(std::string_view msg){
			const std::string output = fmt::format("{}\n", msg);
			asio::write(m_sock, asio::buffer(output));
		}

	private:
		ip::tcp::socket m_sock;
};

class Listener{
	public:
		Listener(asio::io_context &io, std::uint16_t port)
			: m_acceptor(io, ip::tcp::endpoint(ip::tcp::v4(), port)){}

		std::uint16_t port() const noexcept{ return m_acceptor.local_endpoint().port(); }

		boost::optional<Connection> waitForConnection(asio::io_context &io){
			ip::tcp::socket socket(io);
			m_acceptor.accept(socket);
			return Connection(std::move(socket));
		}

	private:
		ip::tcp::acceptor m_acceptor;
};

class Dispatcher{};

int main(int argc, char *argv[]){
	fmt::print("-- Shitfest Server v0.0.1\n");
	asio::io_context io;
	Directory dir;
	Listener listener(io, 6969);
	io.run();
	return 0;
}
