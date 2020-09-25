// Authors: Akide Liu ; Andrew Wang ; Chi Wang
// Date : 25/9/20
// License and copyright notice: GNU General Public License v3.0 
// https://www.gnu.org/licenses/gpl-3.0.en.html
// Description : 

//

#ifndef OOP_PROJECT_DATABASE_CONNECTION_H
#define OOP_PROJECT_DATABASE_CONNECTION_H
#include <sqlpp11/mysql/mysql.h>

namespace mysql = sqlpp::mysql;

using namespace std;

class database_connection {
public:
    static mysql::connection getConnection();

private:
    static string data_host;
    static string data_password;
    static string data_user;
    static string data_database;
    static string data_debug;

    static bool readXML();
};


#endif //OOP_PROJECT_DATABASE_CONNECTION_H
