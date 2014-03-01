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

#include <string>
#include <cstdlib>
#include "server.hpp"
#include "client.hpp"
#include "relay.hpp"

using namespace std;

const string MODE_SERVER = "server";
const string MODE_CLIENT = "client";
const string MODE_RELAY = "relay";

void usage() {
    cerr << "Usage fileTransmitter server <filename> <src_port>" << endl;
    cerr << "Usage fileTransmitter client <filename> <dest_ip> <dest_port>" << endl;
    cerr << "Usage fileTransmitter relay <src_port> <dest_ip> <dest_port>" << endl;
    exit(EXIT_FAILURE);
}

int main(int argc, char** args) {

    string mode;
    string filename;
    string dest_ip;
    string src_port;
    string dest_port;

    if (argc < 3) {
        usage();
    } else {
        mode = args[1];
    }

    if (mode == MODE_SERVER) {
        if (argc == 4) {
            filename = args[2];
            src_port = args[3];
            server srv;
            srv.bind(src_port);
            printf("Waiting for client/relay...\n");
            srv.accept();
            printf("Connection established\n");
            printf("Receiving file...\n");
            srv.receive(filename);
            printf("Transfer completed\n");
        } else {
            usage();
        }
    } else if (mode == MODE_CLIENT) {
        if (argc == 5) {
            filename = args[2];
            dest_ip = args[3];
            dest_port = args[4];
            client cli;
            cli.connect(dest_ip, dest_port);
            printf("Sending file...\n");
            cli.send(filename);
            printf("Transfer completed\n");
        } else {
            usage();
        }

    } else if (mode == MODE_RELAY) {
        if (argc == 5) {
            src_port = args[2];
            dest_ip = args[3];
            dest_port = args[4];
            relay rel;
            rel.connect(dest_ip, dest_port);
            rel.bind(src_port);
            printf("Waiting for client/relay...\n");
            rel.accept();
            printf("Connection established\n");
            printf("Forwarding file...\n");
            rel.forward();
            printf("Transfer completed\n");
        } else {
            usage();
        }
    } else {
        usage();
    }

    return EXIT_SUCCESS;
}
