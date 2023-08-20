#pragma once

#include <string>
#include <map>
#include <vector>

namespace jinx
{
    class SqlSelectQueryBuilder 
    {
        public:  

            SqlSelectQueryBuilder & AddColumn(std::string) noexcept;
            SqlSelectQueryBuilder & AddColumn(const std::vector<std::string> & columns) noexcept;
            SqlSelectQueryBuilder & AddFrom(std::string) noexcept;
            SqlSelectQueryBuilder & AddWhere(std::string, std::string) noexcept;
            SqlSelectQueryBuilder & AddWhere(const std::map<std::string, std::string> & kv) noexcept;

            std::string BuildQuery();

            SqlSelectQueryBuilder() = default;

        protected:

        std::string QColumn;
        std::string QFrom;        
        std::string QWhere;

        bool columnCalledOnce = false;
        bool whereCalledOnce = false;
        bool fromCalledOnce = false;        

    }; // !SqlSelectQueryBuilder

    class AdvancedSqlSelectQueryBuilder : public SqlSelectQueryBuilder
    {
    public:

        AdvancedSqlSelectQueryBuilder & AddWhere(std::string, std::string, std::string) noexcept;    

    }; // !AdvancedSqlSelectQueryBuilder

} // !jinx