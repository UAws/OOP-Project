/*

Authors: Akide Liu ; Andrew Wang ; Chi Wang
Date : 24/9/20

OOP-Project
Copyright (C) <2020>  Akide Liu ; Andrew Wang ; Chi Wang

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

Description :

*/

#include "database_connection.h"

mysql::connection database_connection::getConnection() {

        auto config = std::make_shared<mysql::connection_config>();
        config->host = "172.16.0.78";
        config->password = "LJi8kLPc2KaGjEJF";
        config->user = "oop";
        config->database = "oop";
        config->debug = false;

        mysql::connection db(config);

        return db;
}