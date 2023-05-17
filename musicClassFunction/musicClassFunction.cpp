// Given the following Music class, construct it in main and invoke it's print function

#include <iostream>

class Music {
public:
    Music(std::string track) {
        this->track = track;
    }
    void play() {
        std::cout << this->track << "\n";
    }
    std::string track;
};

int main()
{
    Music legendOfZelda("Song of Time");
    legendOfZelda.play();
    return 0;
}