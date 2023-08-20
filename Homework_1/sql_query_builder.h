#pragma once

#include <string>

namespace jinx
{
    class SqlSelectQueryBuilder final
    {
        public:  

            SqlSelectQueryBuilder & AddColumn(std::string) noexcept;
            SqlSelectQueryBuilder & AddFrom(std::string) noexcept;
            SqlSelectQueryBuilder & AddWhere(std::string, std::string) noexcept;

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