/*
 FileTransmitter is a program which allows to transfer files between computers over the network
 Version 0.2
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

#include <string>

using namespace std;

string help =
        "\n"
                "FileTransmitter  Copyright (C) 2014  Marcel Sinniger\n"
                "(marcel.sinniger@gmail.com, http://durchnull.ch)\n"
                "This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'."
                "\n"
                "This is free software, and you are welcome to redistribute it"
                "\n"
                "under certain conditions; type `show c' for details."
                "\n"
                "Usage:\n"
                "    FileTransmitter dest <filename> <src_port>\n"
                "    FileTransmitter src <filename> <dest_ip> <dest_port>"
                "\n"
                "    FileTransmitter relay <src_port> <dest_ip> <dest_port>"
                "\n";
