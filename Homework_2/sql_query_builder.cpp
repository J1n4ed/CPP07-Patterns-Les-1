#include "sql_query_builder.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>

jinx::SqlSelectQueryBuilder & jinx::SqlSelectQueryBuilder::AddColumn(std::string value) noexcept
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

jinx::SqlSelectQueryBuilder & jinx::SqlSelectQueryBuilder::AddColumn(const std::vector<std::string> & columns) noexcept
{
    if (!columnCalledOnce)
    {
        for (auto i = columns.begin(); i != columns.end(); ++i)
        {
            if (i == columns.begin())
            {                
                QColumn = *i;
            } 
            else
            {
                QColumn += ", " + *i;
            }
        }
    }
    else
    {
        for (auto i = columns.begin(); i != columns.end(); ++i)
        {            
            QColumn += ", " + *i;
        }
    }    

    columnCalledOnce = true;

    return *this;
} // !AddColumt with vector

jinx::SqlSelectQueryBuilder & jinx::SqlSelectQueryBuilder::AddFrom(std::string value) noexcept
{
    QFrom = value;
    fromCalledOnce = true;

    return *this;
} // !AddFrom

jinx::SqlSelectQueryBuilder & jinx::SqlSelectQueryBuilder::AddWhere(std::string lval, std::string rval) noexcept
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

 jinx::SqlSelectQueryBuilder & jinx::SqlSelectQueryBuilder::AddWhere(const std::map<std::string, std::string> & kv) noexcept
 {
    if (!whereCalledOnce)
    {
        for (auto i = kv.begin(); i != kv.end(); ++i)
        {
            if (i == kv.begin())
            {
                QWhere = i->first + "=" + i->second;

            }
            else
            {
                QWhere += " AND " + i->first + "=" + i->second;
            }
        }
    }
    else
    {
        for (auto i = kv.begin(); i != kv.end(); ++i)
        {
            QWhere += " AND " + i->first + "=" + i->second;
        }
    }

    whereCalledOnce = true;

    return *this;
 } // !Where map

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