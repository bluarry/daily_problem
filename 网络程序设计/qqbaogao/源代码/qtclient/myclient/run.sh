#!/bin/sh
sudo apt-get update

sudo sudo apt-get install build-essential qt4-dev-tools qt4-doc qt4-qtconfig qt4-demos qt4-designer qtcreator libsqlite3-dev

qmake ./myclient.pro -r -spec linux-g++-64 CONFIG+=debug CONFIG+=declarative_debug CONFIG+=qml_debug

make

cd ../../servers

gcc -o server server.c -lsqlite3