#include "sql_query_builder.h"
#include <string>

jinx::SqlSelectQueryBuilder & jinx::SqlSelectQueryBuilder::AddColumn(std::string value)
{
    if (!columnCalledOnce)
    {
        QColumn = value;
    } 
    else
    {
        QColumn = QColumn + ", " + value;
    }

    columnCalledOnce = true;

    return *this;
} // !AddColumn

jinx::SqlSelectQueryBuilder & jinx::SqlSelectQueryBuilder::AddFrom(std::string value)
{
    QFrom = value;
    fromCalledOnce = true;

    return *this;
} // !AddFrom

jinx::SqlSelectQueryBuilder & jinx::SqlSelectQueryBuilder::AddWhere(std::string lval, std::string rval)
{
    if (!whereCalledOnce)
    {
        QWhere = lval + "=" + rval;
    }
    else
    {
        QWhere = QWhere + " AND " + lval + "=" + rval;
    }

    whereCalledOnce = true;

    return *this;
} // !AddWhere

std::string jinx::SqlSelectQueryBuilder::BuildQuery()
{ 
    // SELECT name, phone FROM students WHERE id=42 AND name=John;

    std::string query;

    query += "SELECT ";

    if (!columnCalledOnce)
    {
        query += "*";
    }
    else
    {
        query += QColumn;
    }

    query += " FROM ";

    if (!fromCalledOnce)
    {
        query += "*";
    }
    else
    {
        query += QFrom;
    }

    query += " WHERE ";

    if (!whereCalledOnce)
    {
        query += "*";
    }
    else
    {
        query += QWhere;
    }

    query += ";";

    return query;
} // !BuildQuery