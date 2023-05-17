// Which namespace does Pigeon p need to be in in order to sqwuack?

#include <iostream>

namespace a {
    namespace c {
        class Bird {
        public:
            void sqwauck() { std::cout << "Blurt\n"; }
        };
    }
    namespace b {
        class Duck {
        public:
            void sqwauck() { std::cout << "Blart\n"; }
        };
    }
    class Pigeon {
    public:
        void sqwauck() { std::cout << "Blargle\n"; }
    };
}

int main()
{
    using namespace a;
    Pigeon p;
    p.sqwauck();
}