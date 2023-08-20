#pragma once

#include <string>
#include <map>
#include <vector>

namespace jinx
{
    class SqlSelectQueryBuilder final
    {
        public:  

            SqlSelectQueryBuilder & AddColumn(std::string) noexcept;
            SqlSelectQueryBuilder & AddColumn(const std::vector<std::string> & columns) noexcept;
            SqlSelectQueryBuilder & AddFrom(std::string) noexcept;
            SqlSelectQueryBuilder & AddWhere(std::string, std::string) noexcept;
            SqlSelectQueryBuilder & AddWhere(const std::map<std::string, std::string> & kv) noexcept;

            std::string BuildQuery();

            SqlSelectQueryBuilder() = default;

        private:

        std::string QColumn;
        std::string QFrom;        
        std::string QWhere;

        bool columnCalledOnce = false;
        bool whereCalledOnce = false;
        bool fromCalledOnce = false;        

    }; // !SqlSelectQueryBuilder

} // !jinx