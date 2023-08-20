#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "sql_query_builder.h"

int main(int argc, char ** argv) 
{
    // local variables

    std::vector<std::string> cols;
    std::map<std::string, std::string> wher;

    // Preps

    cols.push_back("name");
    cols.push_back("phone");

    wher.insert(std::pair<std::string, std::string>("id", "42"));
    wher.insert(std::pair<std::string, std::string>("name", "John"));

    // Body

    jinx::SqlSelectQueryBuilder query_builder;
    // query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddColumn(cols);
    query_builder.AddFrom("students");
    // query_builder.AddWhere("id", "42").AddWhere("name", "John");
    query_builder.AddWhere(wher);
    
    // Не очень понял как оно тут должно работать и почему строитель запроса должен возвращать тип bool
    // static_assert(query_builder.BuildQuery(), "SELECT name, phone FROM students WHERE id=42 AND name=John;");

    std::cout << "QUERY: " << query_builder.BuildQuery() << '\n';

    // ADD

    jinx::AdvancedSqlSelectQueryBuilder adv_query_builder;
    adv_query_builder.AddColumn(cols);
    adv_query_builder.AddFrom("students");
    adv_query_builder.AddWhere("id", "42", ">"); // Добавляем условие id > 42
    
    // static_assert(query_builder.BuildQuery(), "SELECT name, phone FROM students WHERE id>42;");

    std::cout << "QUERY: " << adv_query_builder.BuildQuery() << '\n';

    std::cout << std::endl;
    std::cout << "PRESS 'ENTER' TO CONTINUE...";
    std::cin.get();
    return EXIT_SUCCESS;
} // !main