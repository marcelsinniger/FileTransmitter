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

#ifndef SERVER_H_
#define SERVER_H_

#include "role.hpp"

class server : virtual public role{

protected:
    boost::asio::io_service io_service;
    boost::asio::ip::tcp::socket socket;
    boost::asio::ip::tcp::endpoint *endpoint;
    boost::asio::ip::tcp::acceptor *acceptor;

public:
    server();
    void bind(std::string src_port);
    void accept();
    void receive(std::string filename);
    void close();
    virtual ~server();
};

#endif /* SERVER_H_ */
