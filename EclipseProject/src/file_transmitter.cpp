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
#include <cstdlib>
#include <iostream>
#include "destination.hpp"
#include "source.hpp"
#include "relay.hpp"
#include "license.hpp"
#include "help.hpp"

using namespace std;

const string MODE_SERVER = "dest";
const string MODE_CLIENT = "src";
const string MODE_RELAY = "relay";

int main(int argc, char** argv) {

    cout << argc << endl;

    string mode;
    string filename;
    string dest_ip;
    string src_port;
    string dest_port;

    // show license
    if (argc == 3 && argv[1] == string("show")
            && ((argv[2]) == string("w") || (argv[2]) == string("c"))) {
        cout << gnu_license;
        exit(EXIT_SUCCESS);
    }

    // start component
    if (argc >= 2)
        mode = argv[1];
    else
        mode = "error";

    if (mode == MODE_SERVER) {
        if (argc == 4) {
            filename = argv[2];
            src_port = argv[3];
            destination dest;
            dest.bind(src_port);
            printf("Waiting for client/relay...\n");
            dest.accept();
            printf("Connection established\n");
            printf("Receiving file...\n");
            dest.receive(filename);
            printf("Transfer completed\n");
        } else {
            cout << help;
            exit(EXIT_FAILURE);
        }
    } else if (mode == MODE_CLIENT) {
        if (argc == 5) {
            filename = argv[2];
            dest_ip = argv[3];
            dest_port = argv[4];
            source src;
            src.connect(dest_ip, dest_port);
            printf("Sending file...\n");
            src.send(filename);
            printf("Transfer completed\n");
        } else {
            cout << help;
            exit(EXIT_FAILURE);
        }

    } else if (mode == MODE_RELAY) {
        if (argc == 5) {
            src_port = argv[2];
            dest_ip = argv[3];
            dest_port = argv[4];
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
            cout << help;
            exit(EXIT_FAILURE);
        }
    } else {
        cout << help;
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}
