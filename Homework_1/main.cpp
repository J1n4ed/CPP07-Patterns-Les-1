#include <iostream>
#include <string>
#include "sql_query_builder.h"

int main_2(int argc, char ** argv) 
{
    jinx::SqlSelectQueryBuilder query_builder;
    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddFrom("students");
    query_builder.AddWhere("id", "42").AddWhere("name", "John");
    
    // Не очень понял как оно тут должно работать и почему строитель запроса должен возвращать тип bool
    // static_assert(query_builder.BuildQuery(), "SELECT name, phone FROM students WHERE id=42 AND name=John;");

    std::cout << "QUERY: " << query_builder.BuildQuery() << '\n';

    std::cout << std::endl;
    std::cout << "PRESS 'ENTER' TO CONTINUE...";
    std::cin.get();
    return EXIT_SUCCESS;
} // !main