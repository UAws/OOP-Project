// Authors: Akide Liu ; Andrew Wang ; Chi Wang
// Date : 25/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

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