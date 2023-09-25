// Given the following classes, what function is being overridden?

class Epsilon {
protected:
    void a(int i) { }
    void b() { }
    int c() { return 0; }
};
class Alpha : public Epsilon {
public:
    void a() { }
};
class Delta : public Epsilon {
    void b() { }
};
class Gamma : public Delta {
    int c(int i) { return i; }
};

int main()
{
    return 0;
}