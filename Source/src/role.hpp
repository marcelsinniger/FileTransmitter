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

#ifndef ROLE_HPP_
#define ROLE_HPP_

#include <boost/asio.hpp>
#include <fstream>

#define BUFFER_SIZE 1024 * 1024 // bytes

class role {

private:

protected:
    char buffer[BUFFER_SIZE];
    int length;

public:
    role();
    virtual ~role();
};

#endif /* ROLE_HPP_ */
