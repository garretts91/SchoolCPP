// Why isn't this code working and how can we fix it?
// Note the namespace being used.

#include <iostream>

namespace bar {
    struct Log { };
}

namespace foo
{
    namespace bar
    {
        struct Log { };
    }
}

using namespace foo;

int main()
{
    std::cout << "Can we fix it? " << std::endl;
    foo::bar::Log bob = {};
    std::cout << "Yes we can!" << std::endl;
    return 0;
}