/*
 FileTransmitter is a program which allows to transfer files between computers over the network
 Version 0.1
 Copyright 2014 Marcel Sinniger

 This file is part of FileTransmitter.

 FileTransmitter is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 FileTransmitter is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with FileTransmitter.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "client.hpp"
#include <boost/lexical_cast.hpp>

using namespace boost::asio::ip;

client::client() :
        resolver(io_service), socket(io_service) {
}

void client::connect(std::string dest_ip, std::string dest_port) {
    boost::asio::ip::tcp::resolver::query query(dest_ip, dest_port);
    boost::asio::ip::tcp::resolver::iterator endpoint_interator =
            resolver.resolve(query);
    boost::asio::connect(socket, endpoint_interator);
}
void client::send(std::string filename) {

    std::ifstream file(filename);
    while (true) {
        try {
            file.read((buffer + sizeof(int)), BUFFER_SIZE - sizeof(int));
            length = file.gcount();
            memcpy(buffer, &length, sizeof(int)); // send the length
            boost::asio::write(socket,
                    boost::asio::buffer(buffer, BUFFER_SIZE));
            if (file.eof()) {
                if (length != 0) {
                    length = 0;
                    std::cout << length << std::endl;
                    memcpy(buffer, &length, sizeof(int)); // send the length
                    boost::asio::write(socket,
                            boost::asio::buffer(buffer, BUFFER_SIZE));
                }
                break;
            }
        } catch (boost::system::system_error &e) {
            std::cerr << e.what() << std::endl;
            std::exit(EXIT_FAILURE);
        }
    }
}
void client::close() {
    socket.close();
}

client::~client() {
}

